// Glarens - GUI Framework.
//
// GUI Node Graph implementation.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#include "glarens/node.hpp"
#include "glarens/math.hpp"
#include "internal/app-data.hpp"
#include "internal/utils.hpp"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <cstddef>
#include <format>
#include <functional>
#include <unordered_map>

static int idCounter = 0;

static std::unordered_map<std::size_t, float> hues;

BoxMetric BoxMetric::screen_metric() {
    int width, height;
    SDL_GetWindowSize(appData.window, &width, &height);
    return BoxMetric{
        .bounds   = Rect::from_xywh(0.0f, 0.0f, width, height),
        .rotation = 0.0f
    };
}

BoxMetric model_dim(BoxDim dim, BoxMetric parentMetric) noexcept {
    int width, height;
    SDL_GetWindowSize(appData.window, &width, &height);

    Vec2 screen  = Vec2(width, height);
    Vec2 refPos  = dim.positioningRefMode == REF_MODE_ABSOLUTE ? screen / 2.0f : parentMetric.bounds.center;
    Vec2 refSize = dim.sizingRefMode == REF_MODE_ABSOLUTE ? screen : parentMetric.bounds.extent;

    Vec2 finalSize = dim.size + dim.scale * refSize;
    Vec2 finalPos  = dim.pos + refPos + dim.anchor * refSize + dim.floating * finalSize;

    return BoxMetric{
        .bounds   = Rect(finalPos, finalSize),
        .rotation = 0.0f
    };
}

BoxMetric model_box(BoxModel model, BoxMetric parentMetric) noexcept {
    BoxMetric metric = model_dim(model, parentMetric);

    if (model.min.has_value()) {
        BoxMetric minMetric = model_dim(*model.min, parentMetric);
        metric.bounds       = unionsection(metric.bounds, minMetric.bounds);
    }

    if (model.min.has_value()) {
        BoxMetric maxMetric = model_dim(*model.max, parentMetric);
        metric.bounds       = intersection(metric.bounds, maxMetric.bounds);
    }

    return metric;
}

BoxMetric transform_box(BoxMetric metric, Transformation t, BoxMetric parentMetric) noexcept {
    int width, height;
    SDL_GetWindowSize(appData.window, &width, &height);

    Vec2 screen  = Vec2(width, height);
    Vec2 refPos  = t.originRefMode == REF_MODE_ABSOLUTE ? screen / 2.0f : parentMetric.bounds.center;
    Vec2 refSize = t.originRefMode == REF_MODE_ABSOLUTE ? screen : parentMetric.bounds.extent;

    Vec2 origin = refPos + t.originPos + t.originAnchor * refSize + t.originFloating * metric.bounds.extent;

    Vec2 v = metric.bounds.center - origin;
    v *= t.scale;

    metric.bounds.extent *= abs(t.scale);

    v = rotate(v, t.rotate);
    metric.rotation += t.rotate;

    metric.bounds.center = origin + v + t.offset;

    return metric;
}

BoxMetric transform_box(BoxMetric metric, const TStack &tStack, BoxMetric parentMetric) noexcept {
    for (const Transformation &t : tStack) {
        metric = transform_box(metric, t, parentMetric);
    }

    return metric;
}

Context::Context() {
}

void Node::update_m_metric_() const {
    BoxMetric parentMetric = BoxMetric::screen_metric();
    if (auto parent = parent_.lock()) {
        parentMetric = parent->tMetric_;
    }

    mMetric_ = model_box(model_.get(), parentMetric);
    update_t_metric_();
}

void Node::update_t_metric_() const {
    BoxMetric parentMetric = BoxMetric::screen_metric();
    if (auto parent = parent_.lock()) {
        parentMetric = parent->tMetric_;
    }

    tMetric_ = transform_box(mMetric_, tStack_.get(), parentMetric);
    for (const auto &child : children_) {
        child->update_m_metric_();
    }
}

Node::Node() {
    refresh_metric();
}

void Node::debug() const {
    std::size_t this_ptr = std::size_t(this);
    float       hue      = ((this_ptr >> 16) ^ (this_ptr) * 12987391ULL) % 36 / 36.0f;
    Color       color    = Color::from_hsl(hue, 0.5f, 0.9f);

    SDL_FRect rect = to_sdl_rect(tMetric_.bounds);
    SDL_SetRenderDrawColor(appData.renderer, color.r, color.g, color.b, 255);
    SDL_RenderRect(appData.renderer, &rect);
    SDL_SetRenderDrawColor(appData.renderer, color.r, color.g, color.b, 63);
    SDL_RenderFillRect(appData.renderer, &rect);

    for (const auto &child : children_) {
        child->debug();
    }
}
