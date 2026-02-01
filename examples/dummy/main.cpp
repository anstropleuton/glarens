// Glarens - GUI Framework.
//
// Dummy example file.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#define SDL_MAIN_USE_CALLBACKS

#include "SDL3/SDL.h" // IWYU pragma: export
#include "SDL3/SDL_main.h"
#include "dummy.hpp"
#include "glarens/glarens.hpp" // IWYU pragma: export
#include <SDL3/SDL_init.h>
#include <iostream>

SDL_Window    *window   = nullptr;
SDL_Renderer  *renderer = nullptr;
SDL_GPUDevice *device   = nullptr;

int posx = 0;
int posy = 0;

SDL_AppResult SDL_AppInit(void **, int argc, char *argv[]) {
    SDL_SetAppMetadata("Dummy Application", "0.0.1", "user.anstropleuton.dummy_application");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    if (!(device = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_DXIL | SDL_GPU_SHADERFORMAT_MSL, true, nullptr))) {
        std::cout << "Failed to create SDL GPU" << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("Dummy Application", 1024, 768, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        std::cout << "Failed to create window and renderer: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    if (!SDL_ClaimWindowForGPUDevice(device, window)) {
        std::cout << "Failed to \"claim window for GPU device\"" << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *, SDL_Event *event) {
    switch (event->type) {
    case SDL_EVENT_QUIT: return SDL_APP_SUCCESS;
    case SDL_EVENT_KEY_DOWN:
        switch (event->key.key) {
        case SDLK_W: posy--;
        case SDLK_S: posy++;
        case SDLK_A: posx--;
        case SDLK_D: posx++;
        }
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *) {
    SDL_SetRenderDrawColor(renderer, 34, 34, 38, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderLine(renderer, 0, 0, posx, posy);

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *, SDL_AppResult result) {
    SDL_ReleaseWindowFromGPUDevice(device, window);
    SDL_DestroyWindow(window);
    SDL_DestroyGPUDevice(device);
}