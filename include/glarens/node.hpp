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
    REF_MODE_RELATIVE, /// Uses parent metric for modeling reference (parent node, screen otherwise).
    REF_MODE_ABSOLUTE  /// Uses screen metric for modeling reference (0, 0, GetScreenWidth(), GetScreenHeight()).
};

struct BoxDim {
    Vec2 pos;      /// Offset from reference position.
    Vec2 anchor;   /// Additional offset from reference size.
    Vec2 floating; /// Additional offset from current size.
    Vec2 size;     /// Absolute extent.
    Vec2 scale;    /// Additional extent from reference size.

    ReferenceMode positioningRefMode = REF_MODE_RELATIVE;
    ReferenceMode sizingRefMode      = REF_MODE_RELATIVE;
};

struct BoxModel : BoxDim {
    bool   useMin = false; /// Clamp at min
    BoxDim min;            /// Minimum dimension (not just size)

    bool   useMax = false; /// Clamp at max
    BoxDim max;            /// Maximum dimension (not just size)

    BoxModel() noexcept = default;
    BoxModel(Vec2 position, Vec2 anchor, Vec2 floating, Vec2 size, Vec2 scale) noexcept : BoxDim(position, anchor, floating, size, scale) {}
    BoxModel(Vec2 position, Vec2 anchor, Vec2 floating, Vec2 size, Vec2 scale, ReferenceMode positioningRefMode, ReferenceMode sizingRefMode) noexcept : BoxDim(position, anchor, floating, size, scale, positioningRefMode, sizingRefMode) {}
};

struct BoxMetric {
    Rect  bounds;          /// Bounding box
    float rotation = 0.0f; /// Rotation from center

    static BoxMetric screen_metric();
};

struct Transformation {
    ReferenceMode originRefMode = REF_MODE_RELATIVE; /// Reference mode for positioning the origin point of transformation

    Vec2 originPos;      /// Offset from reference origin position
    Vec2 originAnchor;   /// Additional offset from reference origin size
    Vec2 originFloating; /// Additional offset from current size

    Vec2  offset;                    /// Position offset
    float rotate = 0.0f;             /// Rotation offset
    Vec2  scale  = Vec2(1.0f, 1.0f); /// Scaling (origin-dependent)
};

using TStack = std::vector<Transformation>;

// Provide screen metric in case of no parent

[[nodiscard]] BoxMetric model_dim(BoxDim dim, BoxMetric parentMetric) noexcept;
[[nodiscard]] BoxMetric model_box(BoxModel model, BoxMetric parentMetric) noexcept;
[[nodiscard]] BoxMetric transform_box(BoxMetric metric, Transformation t, BoxMetric parentMetric) noexcept;
[[nodiscard]] BoxMetric transform_box(BoxMetric metric, const TStack &tStack, BoxMetric parentMetric) noexcept;

template <typename T>
class Param {
    T                proto = T(); /// Prototype value
    std::optional<T> local;       /// Local override

  public:
    Param()                              = default;
    Param(const Param &param)            = default;
    Param(Param &&param)                 = default;
    Param &operator=(const Param &param) = default;
    Param &operator=(Param &&param)      = default;

    Param(const T &value) { set(value); }
    Param(T &&value) { set(std::move(value)); }

    Param &operator=(const T &value) { set(value); }
    Param &operator=(T &&value) { set(std::move(value)); }

    [[nodiscard]] const T &get() const {
        if (local.has_value()) return *local;
        return proto;
    }

    void set(const T &value) { local = value; }
    void set(T &&value) { local = std::move(value); }

    void set_proto(const T &value) { proto = value; }
    void set_proto(T &&value) { proto = std::move(value); }

    void clear() noexcept { local.reset(); }

    [[nodiscard]] bool has_override() const noexcept {
        return local.has_value();
    }
};

class Context : public std::enable_shared_from_this<Context> {
  protected:
    Context();

  public:
    virtual ~Context();

    virtual std::shared_ptr<Context> clone()                                     = 0;
    virtual void                     sync(const std::shared_ptr<Context> &proto) = 0;
};

class Node : public std::enable_shared_from_this<Node> {
    int id_ = 0; /// Unique identifier

    Param<BoxModel> model_;
    Param<TStack>   tStack_;

    mutable BoxMetric mMetric_;
    mutable BoxMetric tMetric_;

    // Note: propagates updates down to children

    void update_m_metric_();
    void update_t_metric_();

    std::weak_ptr<Node>                parent_;
    std::vector<std::shared_ptr<Node>> children_;

    std::weak_ptr<Node>              proto_;
    std::vector<std::weak_ptr<Node>> clones_;

    std::unordered_map<std::type_index, std::shared_ptr<Context>> contexts_;

    void gen_id_();

  protected:
    Node();

  public:
    bool enableUpdate         = true; /// Enable updates
    bool enableChildrenUpdate = true; /// Enable updates for children
    bool enableRender         = true; /// Enable renders
    bool enableChildrenRender = true; /// Enable renders for children

    virtual ~Node() = default;

    MEM_PROP_EXP(Node, model, BoxModel, self.model_.get(), self.model_.set(value); self.update_m_metric_());
    MEM_PROP_EXP(Node, tStack, TStack, self.tStack_.get(), self.tStack_.set(value); self.update_t_metric_());

    MEM_PROP_RO_EXP(Node, mMetric, BoxMetric, self.mMetric_); /// Modeled metric from box model
    MEM_PROP_RO_EXP(Node, tMetric, BoxMetric, self.tMetric_); /// Transformed modeled metric from tStack

    MEM_PROP_RO_EXP(Node, parent, const std::weak_ptr<Node> &, self.parent_);
    MEM_PROP_RO_EXP(Node, children, const std::vector<std::shared_ptr<Node>> &, self.children_);

    /// Derived must provide their own independent factory
    [[nodiscard]] static std::shared_ptr<Node> create() {
        return std::shared_ptr<Node>(new Node());
    }

    /// Derived must provide their own polymorphic factory
    [[nodiscard]] virtual std::shared_ptr<Node> recreate() const {
        return std::shared_ptr<Node>(new Node());
    }

    /// Derived must provide their own sync function
    virtual void sync(const std::shared_ptr<Node> &proto) {
        model_.set_proto(proto->model_.get());
        tStack_.set_proto(proto->tStack_.get());
    }

    [[nodiscard]] std::shared_ptr<Node> clone() {
        auto clone = recreate();

        clone->sync(shared_from_this());

        clones_.push_back(clone);
        clone->proto_ = shared_from_this();

        for (const auto &[type, context] : contexts_) {
            clone->contexts_[type] = context->clone();
        }

        for (const auto &child : children_) {
            clone->add_child(child->clone());
        }

        return clone;
    }

    [[nodiscard]] std::shared_ptr<Node> clone_single() {
        auto clone = recreate();

        clone->sync(shared_from_this());

        clones_.push_back(clone);
        clone->proto_ = shared_from_this();

        for (const auto &[type, context] : contexts_) {
            clone->contexts_[type] = context->clone();
        }

        return clone;
    }

    void sync_clones() {
        clones_.erase(std::remove_if(clones_.begin(), clones_.end(), [](const std::weak_ptr<Node> &clone) { return clone.expired(); }), clones_.end());
        for (const auto &clone_ : clones_) {
            if (auto clone = clone_.lock()) {
                clone->sync(shared_from_this());

                for (const auto &[type, context] : contexts_) {
                    if (auto it = clone->contexts_.find(type); it != clone->contexts_.end()) {
                        it->second->sync(context);
                    }
                }
            }
        }

        for (auto child : children_) {
            child->sync_clones();
        }
    }

    // Note: node tree graph management does not enforce anything

    void add_child(std::shared_ptr<Node> child) {
        child->parent_ = shared_from_this();
        children_.push_back(std::move(child));
    }

    bool remove_child(int id) {
        auto it = std::find_if(children_.begin(), children_.end(), [id](const std::shared_ptr<Node> &child) { return child->id_ == id; });
        if (it == children_.end()) {
            return false;
        }
        (*it)->parent_.reset();
        children_.erase(it);
        return true;
    }

    [[nodiscard]] bool has_child(int id) const noexcept {
        return std::find_if(children_.begin(), children_.end(), [id](const std::shared_ptr<Node> &child) { return child->id_ == id; }) != children_.end();
    }

    [[nodiscard]] std::shared_ptr<Node> get_child(int id) const {
        auto it = std::find_if(children_.begin(), children_.end(), [id](const std::shared_ptr<Node> &child) { return child->id_ == id; });
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
    [[nodiscard]] bool has_context() const noexcept {
        std::type_index type = typeid(T);
        return contexts_.contains(type);
    }

    template <typename T>
        requires std::is_base_of_v<Context, T>
    [[nodiscard]] std::shared_ptr<T> get_context() const {
        if (!has_context<T>()) {
            return nullptr;
        }

        std::type_index type = typeid(T);
        return std::static_pointer_cast<T>(contexts_.at(type));
    }

    /// Checks for context in parent recursively (excluding itself)
    template <typename T>
        requires std::is_base_of_v<Context, T>
    [[nodiscard]] bool has_context_in_ancestor() const noexcept {
        if (auto parent = parent_.lock()) {
            if (parent->has_context<T>()) {
                return true;
            }

            return parent->has_context_in_ancestor<T>();
        }

        return false;
    }

    /// Checks for context in children recursively (excluding itself)
    template <typename T>
        requires std::is_base_of_v<Context, T>
    [[nodiscard]] bool has_context_in_descendant() const noexcept {
        for (auto child : children_) {
            if (child->has_context<T>()) {
                return true;
            }

            if (child->has_context_in_descendant<T>()) {
                return true;
            }
        }

        return false;
    }

    /// Obtains context in parent recursively (excluding itself)
    template <typename T>
        requires std::is_base_of_v<Context, T>
    [[nodiscard]] std::shared_ptr<T> get_context_in_ancestor() const {
        if (auto parent = parent_.lock()) {
            if (auto context = parent->get_context<T>()) {
                return context;
            }

            return parent->get_context_in_ancestor<T>();
        }

        return nullptr;
    }

    /// Obtains context in children recursively (excluding itself)
    template <typename T>
        requires std::is_base_of_v<Context, T>
    [[nodiscard]] std::shared_ptr<T> get_context_in_descendant() const {
        for (auto child : children_) {
            if (auto context = child->get_context<T>()) {
                return context;
            }

            if (auto context = child->get_context_in_descendant<T>()) {
                return context;
            }
        }

        return nullptr;
    }

    /// Override this for custom hit testing
    virtual bool hit_test(Vec2 position) const {
        return contains(tMetric_.bounds, rotate_around(position, tMetric_.bounds.center, -tMetric_.rotation));
    }

    /// Override this for custom modeling after this class has been modeled
    virtual void on_model() {}

    /// Override this for updating before children
    virtual void pre_update() {}

    /// Override this for updating after children
    virtual void post_update() {}

    void update() {
        if (!enableUpdate) {
            return;
        }

        pre_update();

        if (enableChildrenUpdate) {
            for (auto child : children_) {
                child->update();
            }
        }

        post_update();
    }

    /// Override this for rendering before children
    virtual void pre_render() const {}

    /// Override this for rendering after children
    virtual void post_render() const {}

    void render() {
        if (!enableRender) {
            return;
        }

        pre_render();

        if (enableChildrenRender) {
            for (auto child : children_) {
                child->render();
            }
        }

        post_render();
    }
};
