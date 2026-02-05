// Glarens - GUI Framework.
//
// GUI Node Graph.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#pragma once

#include "glarens/math.hpp"
#include <memory>
#include <vector>

enum ReferenceMode {
    Relative, /// Uses parent metric for modeling reference (parent node, screen otherwise).
    Absolute  /// Uses screen metric for modeling reference (0, 0, GetScreenWidth(), GetScreenHeight()).
};

struct BoxDim {
    Vec2 pos;      /// Offset from reference position.
    Vec2 anchor;   /// Additional offset from reference size.
    Vec2 floating; /// Additional offset from current size.
    Vec2 size;     /// Absolute extent.
    Vec2 scale;    /// Additional extent from reference size.

    ReferenceMode positioningRefMode = Relative;
    ReferenceMode sizingRefMode      = Relative;
};

struct BoxModel : BoxDim {
    bool   useMin = false; /// Clamp at min
    BoxDim min;            /// Minimum dimension (not just size)

    bool   useMax = false; /// Clamp at max
    BoxDim max;            /// Maximum dimension (not just size)

    BoxModel() = default;
    BoxModel(Vec2 position, Vec2 anchor, Vec2 floating, Vec2 size, Vec2 scale) : BoxDim(position, anchor, floating, size, scale) {}
    BoxModel(Vec2 position, Vec2 anchor, Vec2 floating, Vec2 size, Vec2 scale, ReferenceMode positioningRefMode, ReferenceMode sizingRefMode) : BoxDim(position, anchor, floating, size, scale, positioningRefMode, sizingRefMode) {}
};

struct BoxMetric {
    Rect  bounds;          /// Bounding box
    float rotation = 0.0f; /// Rotation from center
};

struct Transformation {
    ReferenceMode originRefMode = Relative; /// Reference mode for positioning the origin point of transformation

    Vec2 originPos;      /// Offset from reference origin position
    Vec2 originAnchor;   /// Additional offset from reference origin size
    Vec2 originFloating; /// Additional offset from current size

    Vec2  offset;                    /// Position offset
    float rotate = 0.0f;             /// Rotation offset
    Vec2  scale  = Vec2(1.0f, 1.0f); /// Scaling (origin-dependent)
};

using TStack = std::vector<Transformation>;

BoxMetric ModelDim(BoxDim dim, BoxMetric parentMetric);
BoxMetric ModelBox(BoxModel model, BoxMetric parentMetric);
BoxMetric TransformBox(BoxMetric metric, Transformation t, BoxMetric parentMetric);
BoxMetric TransformBox(BoxMetric metric, const TStack &tStack, BoxMetric parentMetric);

struct Context {
    virtual ~Context() = default;
};

struct Node {
  private:
    BoxModel boxModel_;
    TStack   tStack_;

    mutable BoxMetric modeledMetric_;
    mutable BoxMetric transformedMetric_;

    void UpdateModeled_();
    void UpdateTransformed_();

    std::vector<std::shared_ptr<Context>> contexts_;

    mutable std::vector<std::weak_ptr<void>> contextAncestors_;
    mutable std::vector<std::weak_ptr<void>> contextDescendents_;

  public:
    Node();

    virtual ~Node() = default;

    int                      id = 0;
    std::string              name;
    std::vector<std::string> tags;
    bool                     noupdate = false;
    bool                     nodraw   = false;

    MemPropExp(Node, boxModel, BoxModel, self.boxModel_, self.UpdateModeled_(); self.boxModel_ = value);
    MemPropExp(Node, tStack, TStack, self.tStack_, self.UpdateTransformed_(); self.tStack_ = value);
    MemPropROExp(Node, modeledMetric, BoxMetric, self.modeledMetric_);
    MemPropROExp(Node, transformedMetric, BoxMetric, self.transformedMetric_);

    std::weak_ptr<Node>                parent;
    std::vector<std::shared_ptr<Node>> children;

    template <typename T = Node>
    static std::shared_ptr<T> New(const BoxModel &boxModel = {}, const TStack &tStack = {}, const std::string &name = "", const std::vector<std::string> &tags = {}) {
        auto node      = std::make_shared<T>();
        node->boxModel = boxModel;
        node->tStack   = tStack;
        node->name     = name;
        node->tags     = tags;
        return node;
    }

    template <typename T = Node>
    std::shared_ptr<T> Insert(std::size_t index = -1, const BoxModel &boxModel = {}, const TStack &tStack = {}, const std::string &name = "", const std::vector<std::string> &tags = {}) {
        auto node = New(boxModel, tStack, name, tags);
        if (index == -1) {
            children.emplace_back(node);
        } else {
            children.insert(children.begin() + index, node);
        }
        return node;
    }

    template <typename T = Node>
    void Insert(std::shared_ptr<T> node, std::size_t index = -1) {
        if (index == -1) {
            children.emplace_back(node);
        } else {
            children.insert(children.begin() + index, node);
        }
    }

    template <typename T = Node>
    void Remove(std::shared_ptr<T> node) {
        for (std::size_t i = 0; i < children.size(); i++) {
            if (node == children[i]) {
                children.erase(children.begin() + i);
                return;
            }
        }
    }

    void Remove(std::size_t index) {
        children.erase(children.begin() + index);
    }

    template <typename T>
    void AttachContext(const T &context) {
        if (HasContext<T>()) {
            return;
        }
        contexts_.emplace_back(context);
    }

    template <typename T>
    void DetachContext() {
        if (!HasContext<T>()) {
            return;
        }
        for (std::size_t i = 0; i < contexts_.size(); i++) {
            if (std::dynamic_pointer_cast<T>(contexts_[i])) {
                contexts_.erase(contexts_.begin() + i);
                return;
            }
        }
    }

    template <typename T>
    bool HasContext() {
        return GetContext<T>() != nullptr;
    }

    template <typename T>
    std::weak_ptr<T> GetContext() const {
        for (std::size_t i = 0; i < contexts_.size(); i++) {
            if (auto casted = std::dynamic_pointer_cast<T>(contexts_[i])) {
                return casted;
            }
        }

        return nullptr;
    }

    template <typename T>
    std::weak_ptr<T> GetContextInAncestor() const {
        std::weak_ptr<T> context = GetContext<T>();
        if (context) {
            return context;
        }

        if (auto casted = parent.lock()) {
            return casted->GetContextInAncestor<T>();
        }

        return nullptr;
    }

    template <typename T>
    std::weak_ptr<T> GetContextInDescendent() const {
        std::weak_ptr<T> context = GetContext<T>();
        if (context) {
            return context;
        }

        for (auto &child : children) {
            context = child->GetContextInDescendent<T>();
            if (context) {
                return context;
            }
        }

        return nullptr;
    }

    virtual bool HitTest(Vec2 position) const;

    virtual void OnModel() {}

    virtual void PreUpdate() {}

    virtual void PostUpdate() {}

    virtual void Update() {
        if (!noupdate) {
            PreUpdate();

            for (auto &child : children) {
                child->Update();
            }

            PostUpdate();
        }
    }

    virtual void PreDraw() const {}

    virtual void PostDraw() const {}

    virtual void Draw() const {
        if (!nodraw) {
            PreDraw();

            for (auto &child : children) {
                child->Draw();
            }

            PostDraw();
        }
    }
};
