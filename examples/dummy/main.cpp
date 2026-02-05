// Glarens - GUI Framework.
//
// Dummy example file.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#define SDL_MAIN_USE_CALLBACKS

#include "dummy.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <fstream>
#include <iostream>
#include <iterator>

SDL_Window    *window   = nullptr;
SDL_Renderer  *renderer = nullptr;
SDL_GPUDevice *device   = nullptr;

SDL_GPUShader *vertShader = nullptr;
SDL_GPUShader *fragShader = nullptr;

SDL_GPUGraphicsPipeline *pipeline = nullptr;

SDL_AppResult SDL_AppInit(void **, int argc, char *argv[]) {
    SDL_setenv_unsafe("SDL_VIDEO_DRIVER", "wayland", 1);
    SDL_SetAppMetadata("Dummy Application", "0.0.1", "user.anstropleuton.dummy_application");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    if (!(device = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_DXIL | SDL_GPU_SHADERFORMAT_MSL, true, nullptr))) {
        std::cout << "Failed to create SDL GPU: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("Dummy Application", 1024, 768, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        std::cout << "Failed to create window and renderer: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    if (!SDL_ClaimWindowForGPUDevice(device, window)) {
        std::cout << "Failed to \"claim window for GPU device\": " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    std::cout << "SDL video driver: " << SDL_GetCurrentVideoDriver() << std::endl;
    std::cout << "SDL GPU driver: " << SDL_GetGPUDeviceDriver(device) << std::endl;

    SDL_GPUShaderFormat shaderFormat;
    std::string         formatExt;
    std::string         formatEntry;
    if (SDL_GetGPUShaderFormats(device) & SDL_GPU_SHADERFORMAT_SPIRV) {
        shaderFormat = SDL_GPU_SHADERFORMAT_SPIRV;
        formatExt    = ".spv";
        formatEntry  = "main";
    } else if (SDL_GetGPUShaderFormats(device) & SDL_GPU_SHADERFORMAT_MSL) {
        shaderFormat = SDL_GPU_SHADERFORMAT_MSL;
        formatExt    = ".msl";
        formatEntry  = "main0"; // Of course only apple could fuck this up and do this kind of shit
    } else if (SDL_GetGPUShaderFormats(device) & SDL_GPU_SHADERFORMAT_DXIL) {
        shaderFormat = SDL_GPU_SHADERFORMAT_DXIL;
        formatExt    = ".dxil";
        formatEntry  = "main";
    } else {
        std::cout << "Unsupported shader format" << std::endl;
        return SDL_APP_FAILURE;
    }

    std::ifstream vertFile("assets/shaders/shader.vert" + formatExt, std::ios::binary);

    if (!vertFile) {
        std::cout << "Failed to open vertex shader file" << std::endl;
        return SDL_APP_FAILURE;
    }

    std::ifstream fragFile("assets/shaders/shader.frag" + formatExt, std::ios::binary);

    if (!fragFile) {
        std::cout << "Failed to open fragment shader file" << std::endl;
        return SDL_APP_FAILURE;
    }

    std::string vertContent{std::istreambuf_iterator<char>(vertFile), std::istreambuf_iterator<char>()};
    std::string fragContent{std::istreambuf_iterator<char>(fragFile), std::istreambuf_iterator<char>()};

    SDL_GPUShaderCreateInfo vertCreateInfo = {
        .code_size  = vertContent.size(),
        .code       = (const Uint8 *)vertContent.c_str(),
        .entrypoint = formatEntry.c_str(),
        .format     = shaderFormat,
        .stage      = SDL_GPU_SHADERSTAGE_VERTEX,
    };

    SDL_GPUShaderCreateInfo fragCreateInfo = {
        .code_size  = fragContent.size(),
        .code       = (const Uint8 *)fragContent.c_str(),
        .entrypoint = formatEntry.c_str(),
        .format     = shaderFormat,
        .stage      = SDL_GPU_SHADERSTAGE_FRAGMENT,
    };

    if (!(vertShader = SDL_CreateGPUShader(device, &vertCreateInfo))) {
        std::cout << "Failed to create vertex shader: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }
    if (!(fragShader = SDL_CreateGPUShader(device, &fragCreateInfo))) {
        std::cout << "Failed to create fragment shader: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    SDL_GPUColorTargetDescription colorTargetDesc = {
        .format = SDL_GetGPUSwapchainTextureFormat(device, window)
    };

    SDL_GPUGraphicsPipelineTargetInfo pipelineTargetInfo = {
        .color_target_descriptions = &colorTargetDesc,
        .num_color_targets         = 1
    };

    SDL_GPUGraphicsPipelineCreateInfo pipelineCreateInfo = {
        .vertex_shader    = vertShader,
        .fragment_shader  = fragShader,
        .primitive_type   = SDL_GPU_PRIMITIVETYPE_TRIANGLELIST,
        .rasterizer_state = {
            .fill_mode = SDL_GPU_FILLMODE_FILL
        },
        .target_info = pipelineTargetInfo
    };

    if (!(pipeline = SDL_CreateGPUGraphicsPipeline(device, &pipelineCreateInfo))) {
        std::cout << "Failed to create graphics pipeline: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *, SDL_Event *event) {
    switch (event->type) {
    case SDL_EVENT_QUIT: return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *) {
    SDL_GPUCommandBuffer *cmd = SDL_AcquireGPUCommandBuffer(device);
    if (!cmd) {
        std::cout << "Failed to acquire command buffer: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    SDL_GPUTexture *texture = nullptr;
    if (!SDL_AcquireGPUSwapchainTexture(cmd, window, &texture, nullptr, nullptr)) {
        std::cout << "Failed to acquire \"swapchain texture\": " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    if (!texture) {
        SDL_SubmitGPUCommandBuffer(cmd);
        return SDL_APP_CONTINUE;
    }

    SDL_GPUColorTargetInfo colorTargetInfo = {
        .texture  = texture,
        .load_op  = SDL_GPU_LOADOP_CLEAR,
        .store_op = SDL_GPU_STOREOP_STORE
    };

    SDL_GPURenderPass *pass = SDL_BeginGPURenderPass(cmd, &colorTargetInfo, 1, nullptr);
    SDL_BindGPUGraphicsPipeline(pass, pipeline);
    SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0);
    SDL_EndGPURenderPass(pass);
    SDL_SubmitGPUCommandBuffer(cmd);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *, SDL_AppResult result) {
    SDL_ReleaseGPUShader(device, vertShader);
    SDL_ReleaseGPUShader(device, fragShader);
    SDL_ReleaseGPUGraphicsPipeline(device, pipeline);
    SDL_ReleaseWindowFromGPUDevice(device, window);
    SDL_DestroyWindow(window);
    SDL_DestroyGPUDevice(device);
}
