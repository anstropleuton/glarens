// Glarens - GUI Framework.
//
// GUI Node Graph implementation.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#include "glarens/node.hpp"
#include "internal/app-data.hpp"
#include <SDL3/SDL_video.h>

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

    if (model.useMin) {
        BoxMetric minMetric       = model_dim(model.min, parentMetric);
        metric.bounds.topLeft     = max(Vec2(metric.bounds.topLeft), Vec2(minMetric.bounds.topLeft));
        metric.bounds.bottomRight = min(Vec2(metric.bounds.bottomRight), Vec2(minMetric.bounds.bottomRight));
    }

    if (model.useMax) {
        BoxMetric maxMetric       = model_dim(model.max, parentMetric);
        metric.bounds.topLeft     = min(Vec2(metric.bounds.topLeft), Vec2(maxMetric.bounds.topLeft));
        metric.bounds.bottomRight = max(Vec2(metric.bounds.bottomRight), Vec2(maxMetric.bounds.bottomRight));
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
