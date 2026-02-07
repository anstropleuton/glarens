// Glarens - GUI Framework.
//
// GUI Node Graph.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#pragma once

#include "glarens/math.hpp"
#include "glarens/property.hpp"
#include <algorithm>
#include <memory>
#include <optional>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
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

BoxMetric model_dim(BoxDim dim, BoxMetric parentMetric);
BoxMetric model_box(BoxModel model, BoxMetric parentMetric);
BoxMetric tramsform_box(BoxMetric metric, Transformation t, BoxMetric parentMetric);
BoxMetric transform_box(BoxMetric metric, const TStack &tStack, BoxMetric parentMetric);

template <typename T>
class Param {
    T                base = T();
    std::optional<T> override;

  public:
    const T &get() const {
        if (override.has_value()) return *override;
        return base;
    }

    void set(T value) {
        override = std::move(value);
    }

    void clear() {
        override.reset();
    }

    void set_base(T value) {
        base = std::move(value);
    }

    bool has_override() const {
        return override.has_value();
    }
};

class Context : public std::enable_shared_from_this<Context> {
    int id = 0; // Unique identifier

  public:
    Context();
};

class Node : public std::enable_shared_from_this<Node> {
    int id = 0; // Unique identifier

    Param<BoxModel> model_;
    Param<TStack>   tStack_;

    BoxMetric modeledMetric_;
    BoxMetric tMetric_;

    std::weak_ptr<Node>                parent_;
    std::vector<std::shared_ptr<Node>> children_;

    std::weak_ptr<Node>              proto_;
    std::vector<std::weak_ptr<Node>> clones_;

    std::unordered_map<std::type_index, std::shared_ptr<Context>> contexts_;

    static void dupe_values(const std::shared_ptr<Node> &proto, const std::shared_ptr<Node> &clone) {
        clone->model_.set_base(proto->model_.get());
        clone->tStack_.set_base(proto->tStack_.get());
    }

    void gen_id();

  public:
    Node();
    virtual ~Node() = default;

    MEM_PROP_EXP(Node, model, BoxModel, self.model_.get(), self.model_.set(value));
    MEM_PROP_EXP(Node, tStack, TStack, self.tStack_.get(), self.tStack_.set(value));

    MEM_PROP_RO_EXP(Node, modeledMetric, BoxMetric, self.modeledMetric_);
    MEM_PROP_RO_EXP(Node, tMetric, BoxMetric, self.tMetric_);

    MEM_PROP_RO_EXP(Node, parent, const std::weak_ptr<Node> &, self.parent_);
    MEM_PROP_RO_EXP(Node, children, const std::vector<std::shared_ptr<Node>> &, self.children_);

    // Derived must provide their own factory
    static std::shared_ptr<Node> create_node() {
        return std::make_shared<Node>();
    }

    // Derived must provide their own clone function
    virtual std::shared_ptr<Node> clone_node() {
        auto clone = std::make_shared<Node>();

        dupe_values(shared_from_this(), clone);

        clones_.push_back(clone);
        clone->proto_ = shared_from_this();

        for (const auto &child : children_) {
            clone->add_child(child->clone_node());
        }

        return clone;
    }

    // Derived must provide their own sync function
    virtual void sync_clones() {
        clones_.erase(std::remove_if(clones_.begin(), clones_.end(), [](const std::weak_ptr<Node> &clone) { return clone.expired(); }), clones_.end());
        for (const auto &clone_ : clones_) {
            if (auto clone = clone_.lock()) {
                dupe_values(shared_from_this(), clone);
            }
        }
    }

    // Note: node tree graph management does not enforce anything

    void add_child(std::shared_ptr<Node> child) {
        children_.push_back(child);
        child->parent_ = shared_from_this();
    }

    void remove_child(int id) {
        auto it = std::find_if(children_.begin(), children_.end(), [id](const std::shared_ptr<Node> &child) { return child->id == id; });
        if (it == children_.end()) {
            return;
        }
        (*it)->parent_.reset();
        children_.erase(it);
    }

    bool has_child(int id) const {
        return std::find_if(children_.begin(), children_.end(), [id](const std::shared_ptr<Node> &child) { return child->id == id; }) != children_.end();
    }

    std::shared_ptr<Node> get_child(int id) const {
        auto it = std::find_if(children_.begin(), children_.end(), [id](const std::shared_ptr<Node> &child) { return child->id == id; });
        if (it == children_.end()) {
            return nullptr;
        }
        return *it;
    }

    template <typename T>
        requires std::is_base_of_v<Context, T>
    void set_context(std::shared_ptr<T> context) {
        std::type_index type = typeid(T);
        contexts_[type]      = context;
    }

    template <typename T>
        requires std::is_base_of_v<Context, T>
    void reset_context() {
        std::type_index type = typeid(T);
        contexts_.erase(type);
    }

    template <typename T>
        requires std::is_base_of_v<Context, T>
    bool has_context() const {
        std::type_index type = typeid(T);
        return contexts_.contains(type);
    }

    template <typename T>
        requires std::is_base_of_v<Context, T>
    std::shared_ptr<T> get_context() const {
        if (!has_context<T>()) {
            return nullptr;
        }

        std::type_index type = typeid(T);
        return std::static_pointer_cast<T>(contexts_.at(type));
    }
};
