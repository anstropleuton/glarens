// Glarens - GUI Framework.
//
// Internal application state data.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#pragma once

#include "SDL3/SDL_rect.h"
#include "glarens/math.hpp"

[[nodiscard]] inline Rect from_sdl_rect(SDL_FRect rect) noexcept {
    return Rect::from_xywh(rect.x, rect.y, rect.w, rect.h);
}

[[nodiscard]] inline Rect from_sdl_rect(SDL_Rect rect) noexcept {
    return Rect::from_xywh(rect.x, rect.y, rect.w, rect.h);
}

[[nodiscard]] inline SDL_FRect to_sdl_rect(Rect rect) noexcept {
    Vec4 v = rect.to_xywh();
    return SDL_FRect{
        .x = v.x,
        .y = v.y,
        .w = v.z,
        .h = v.w
    };
}
