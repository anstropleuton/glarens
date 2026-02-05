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

BoxMetric ModelDim(BoxDim dim, BoxMetric parentMetric) {
    int width, height;
    SDL_GetWindowSize(appData.window, &width, &height);

    Vec2 screen  = Vec2(width, height);
    Vec2 refPos  = dim.positioningRefMode == Absolute ? screen / 2.0f : parentMetric.bounds.center;
    Vec2 refSize = dim.sizingRefMode == Absolute ? screen : parentMetric.bounds.extent;

    Vec2 finalSize = dim.size + dim.scale * refSize;
    Vec2 finalPos  = dim.pos + refPos + dim.anchor * refSize + dim.floating * finalSize;

    return BoxMetric{
        .bounds   = Rect(finalPos, finalSize),
        .rotation = 0.0f
    };
}

BoxMetric ModelBox(BoxModel model, BoxMetric parentMetric) {
    BoxMetric metric = ModelDim(model, parentMetric);

    if (model.useMin) {
        BoxMetric minMetric       = ModelDim(model.min, parentMetric);
        metric.bounds.topLeft     = max(Vec2(metric.bounds.topLeft), Vec2(minMetric.bounds.topLeft));
        metric.bounds.bottomRight = min(Vec2(metric.bounds.bottomRight), Vec2(minMetric.bounds.bottomRight));
    }

    if (model.useMax) {
        BoxMetric maxMetric       = ModelDim(model.max, parentMetric);
        metric.bounds.topLeft     = min(Vec2(metric.bounds.topLeft), Vec2(maxMetric.bounds.topLeft));
        metric.bounds.bottomRight = max(Vec2(metric.bounds.bottomRight), Vec2(maxMetric.bounds.bottomRight));
    }

    return metric;
}

BoxMetric TransformBox(BoxMetric metric, Transformation t, BoxMetric parentMetric) {
    int width, height;
    SDL_GetWindowSize(appData.window, &width, &height);

    Vec2 screen  = Vec2(width, height);
    Vec2 refPos  = t.originRefMode == Absolute ? screen / 2.0f : parentMetric.bounds.center;
    Vec2 refSize = t.originRefMode == Absolute ? screen : parentMetric.bounds.extent;

    Vec2 origin = refPos + t.originPos + t.originAnchor * refSize + t.originFloating * metric.bounds.extent;

    Vec2 v = metric.bounds.center - origin;
    v *= t.scale;

    metric.bounds.extent *= abs(t.scale);

    v = rotate(v, t.rotate);
    metric.rotation += t.rotate;

    metric.bounds.center = origin + v + t.offset;

    return metric;
}

BoxMetric TransformBox(BoxMetric metric, const TStack &tStack, BoxMetric parentMetric) {
    for (const Transformation &t : tStack) {
        metric = TransformBox(metric, t, parentMetric);
    }

    return metric;
}

void Node::UpdateModeled_() {
    int width, height;
    SDL_GetWindowSize(appData.window, &width, &height);

    BoxMetric parentMetric = BoxMetric(Rect::from_xywh(0.0f, 0.0f, width, height));
    if (auto pLock = parent.lock()) {
        parentMetric = pLock->modeledMetric_;
    }

    modeledMetric_ = ModelBox(boxModel_, parentMetric);
    for (auto &child : children) {
        child->UpdateModeled_();
    }
}

void Node::UpdateTransformed_() {
    int width, height;
    SDL_GetWindowSize(appData.window, &width, &height);

    BoxMetric parentMetric = BoxMetric(Rect::from_xywh(0.0f, 0.0f, width, height));
    if (auto pLock = parent.lock()) {
        parentMetric = pLock->modeledMetric_;
    }

    transformedMetric_ = TransformBox(modeledMetric_, tStack_, parentMetric);
    for (auto &child : children) {
        child->UpdateTransformed_();
    }
}

Node::Node() {
}

bool Node::HitTest(Vec2 position) const {
    return false;
}
