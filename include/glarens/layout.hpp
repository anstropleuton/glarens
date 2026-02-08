// Glarens - GUI Framework.
//
// Layout nodes.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#pragma once

#include "glarens/node.hpp"
#include "glarens/property.hpp"
#include <memory>
#include <stdexcept>

enum Align {
    ALIGN_BEGIN,  /// Align to the beginning of the axis
    ALIGN_CENTER, /// Align to the center of the axis
    ALIGN_END,    /// Align to the end of the axis

    // Applicable for multi-child configs only; treated as ALIGN_CENTER for single-child alignment

    ALIGN_SPACE_BETWEEN, /// Align with equal space between each items
    ALIGN_SPACE_EQUALLY, /// Align with equal space between each items and edges
    ALIGN_SPACE_AROUND   /// Align with equal space between each sides of each items
};

enum Direction {
    DIRECTION_UP,   /// y- direction
    DIRECTION_DOWN, /// y+ direction
    DIRECTION_LEFT, /// x- direction
    DIRECTION_RIGHT /// x+ direction
};

// Note: hildren without the corresponding Item context are treated as if the context exists with default values

/// Arranges items linearly
class FlexLayout : public Node {
    Param<Direction> dir_     = DIRECTION_RIGHT;
    Param<Direction> wrapDir_ = DIRECTION_DOWN;

    Param<Align> align_     = ALIGN_BEGIN;
    Param<Align> wrapAlign_ = ALIGN_BEGIN;

    Param<bool> doWrapping_  = true;
    Param<bool> altWrapping_ = false;

    void update_layout_();

  protected:
    FlexLayout() = default;

  public:
    MEM_PROP_EXP(FlexLayout, dir, Direction, self.dir_.get(), self.dir_.set(value); self.update_layout_());             /// Direction to flow
    MEM_PROP_EXP(FlexLayout, wrapDir, Direction, self.wrapDir_.get(), self.wrapDir_.set(value); self.update_layout_()); /// Direction to wrap

    MEM_PROP_EXP(FlexLayout, align, Align, self.align_.get(), self.align_.set(value); self.update_layout_());             /// Align in the flow
    MEM_PROP_EXP(FlexLayout, wrapAlign, Align, self.wrapAlign_.get(), self.wrapAlign_.set(value); self.update_layout_()); /// Align in the wrap

    MEM_PROP_EXP(FlexLayout, doWrapping, bool, self.doWrapping_.get(), self.doWrapping_.set(value); self.update_layout_());    /// Enable wrapping
    MEM_PROP_EXP(FlexLayout, altWrapping, bool, self.altWrapping_.get(), self.altWrapping_.set(value); self.update_layout_()); /// Wrap in alternative direction

    static std::shared_ptr<FlexLayout> create() {
        return std::shared_ptr<FlexLayout>(new FlexLayout);
    }

    std::shared_ptr<Node> recreate() const override {
        return std::shared_ptr<FlexLayout>(new FlexLayout);
    }

    void sync(const std::shared_ptr<Node> &proto) override {
        auto layout = std::dynamic_pointer_cast<FlexLayout>(proto);
        if (!layout) {
            throw std::runtime_error("Prototype of a different type cannot be used to synchronize parameters");
        }

        Node::sync(proto);

        dir_.set_proto(layout->dir_.get());
        wrapDir_.set_proto(layout->wrapDir_.get());
        align_.set_proto(layout->align_.get());
        wrapAlign_.set_proto(layout->wrapAlign_.get());
        doWrapping_.set_proto(layout->doWrapping_.get());
        altWrapping_.set_proto(layout->altWrapping_.get());
    }

    void on_model() override;
};

class FlexItem : public Context {
    Param<float> weight_     = 1.0f;
    Param<float> wrapWeight_ = 1.0f;

    void update_layout_();

  protected:
    FlexItem() = default;

  public:
    MEM_PROP_EXP(FlexItem, weight, float, self.weight_.get(), self.weight_.set(value); self.update_layout_());             /// Weighted alignment in flow axis
    MEM_PROP_EXP(FlexItem, wrapWeight, float, self.wrapWeight_.get(), self.wrapWeight_.set(value); self.update_layout_()); /// Weighted alignment in wrap axis (averaged for all items in main axis)

    static std::shared_ptr<FlexItem> create() {
        return std::shared_ptr<FlexItem>(new FlexItem);
    }

    std::shared_ptr<Context> clone() override {
        auto clone = create();
        clone->sync(shared_from_this());
        return clone;
    }

    void sync(const std::shared_ptr<Context> &proto) override {
        auto context = std::dynamic_pointer_cast<FlexItem>(proto);
        if (!context) {
            throw std::runtime_error("Prototype of a different type cannot be used to synchronize parameters");
        }

        weight_.set_proto(context->weight_.get());
        wrapWeight_.set_proto(context->wrapWeight_.get());
    }
};

/// Arranges items in a grid
class GridLayout : public Node {
    Param<Direction> dir_     = DIRECTION_RIGHT;
    Param<Direction> wrapDir_ = DIRECTION_DOWN;

    Param<Align> align_     = ALIGN_BEGIN;
    Param<Align> wrapAlign_ = ALIGN_BEGIN;

    Param<int>  slots_   = 1;
    Param<bool> masonry_ = false;

    void update_layout_();

  protected:
    GridLayout() = default;

  public:
    MEM_PROP_EXP(GridLayout, dir, Direction, self.dir_.get(), self.dir_.set(value); self.update_layout_());             /// Direction to flow in slots
    MEM_PROP_EXP(GridLayout, wrapDir, Direction, self.wrapDir_.get(), self.wrapDir_.set(value); self.update_layout_()); /// Direction to wrap in slots

    MEM_PROP_EXP(GridLayout, align, Align, self.align_.get(), self.align_.set(value); self.update_layout_());             /// Align in the flow
    MEM_PROP_EXP(GridLayout, wrapAlign, Align, self.wrapAlign_.get(), self.wrapAlign_.set(value); self.update_layout_()); /// Align in the wrap

    MEM_PROP_EXP(GridLayout, slots, int, self.slots_.get(), self.slots_.set(value); self.update_layout_());        /// Number of slots in flow axis
    MEM_PROP_EXP(GridLayout, masonry, bool, self.masonry_.get(), self.masonry_.set(value); self.update_layout_()); /// Whether to arrange next items in main slot in masonry style

    static std::shared_ptr<GridLayout> create() {
        return std::shared_ptr<GridLayout>(new GridLayout);
    }

    std::shared_ptr<Node> recreate() const override {
        return std::shared_ptr<GridLayout>(new GridLayout);
    }

    void sync(const std::shared_ptr<Node> &proto) override {
        auto layout = std::dynamic_pointer_cast<GridLayout>(proto);
        if (!layout) {
            throw std::runtime_error("Prototype of a different type cannot be used to synchronize parameters");
        }

        Node::sync(proto);

        dir_.set_proto(layout->dir_.get());
        wrapDir_.set_proto(layout->wrapDir_.get());
        align_.set_proto(layout->align_.get());
        wrapAlign_.set_proto(layout->wrapAlign_.get());
        slots_.set_proto(layout->slots_.get());
        masonry_.set_proto(layout->masonry_.get());
    }

    void on_model() override;
};

class GridItem : public Context {
    Param<int>   xSpan_   = 1;
    Param<int>   ySpan_   = 1;
    Param<float> xWeight_ = 1.0f;
    Param<float> yWeight_ = 1.0f;

    void update_layout_();

  protected:
    GridItem() = default;

  public:
    MEM_PROP_EXP(GridItem, xSpan, int, self.xSpan_.get(), self.xSpan_.set(value); self.update_layout_());         /// Number of slots to occupy in x-axis
    MEM_PROP_EXP(GridItem, ySpan, int, self.ySpan_.get(), self.ySpan_.set(value); self.update_layout_());         /// Number of slots to occupy in y-axis
    MEM_PROP_EXP(GridItem, xWeight, float, self.xWeight_.get(), self.xWeight_.set(value); self.update_layout_()); /// Weighted alignment in x-axis (averaged for all items in the slot)
    MEM_PROP_EXP(GridItem, yWeight, float, self.yWeight_.get(), self.yWeight_.set(value); self.update_layout_()); /// Weighted alignment in y-axis (averaged for all items in the slot)

    static std::shared_ptr<GridItem> create() {
        return std::shared_ptr<GridItem>(new GridItem);
    }

    std::shared_ptr<Context> clone() override {
        auto clone = create();
        clone->sync(shared_from_this());
        return clone;
    }

    void sync(const std::shared_ptr<Context> &proto) override {
        auto context = std::dynamic_pointer_cast<GridItem>(proto);
        if (!context) {
            throw std::runtime_error("Prototype of a different type cannot be used to synchronize parameters");
        }

        xSpan_.set_proto(context->xSpan_.get());
        ySpan_.set_proto(context->ySpan_.get());
        xWeight_.set_proto(context->xWeight_.get());
        yWeight_.set_proto(context->yWeight_.get());
    }
};

/// Arranges items in a fixed grid
class MatrixLayout : public Node {
    Param<int> xSlots_ = 1;
    Param<int> ySlots_ = 1;

    Param<Direction> dir_     = DIRECTION_RIGHT;
    Param<Direction> wrapDir_ = DIRECTION_DOWN;

    Param<Align> align_     = ALIGN_BEGIN;
    Param<Align> wrapAlign_ = ALIGN_BEGIN;

    void update_layout_();

  protected:
    MatrixLayout() = default;

  public:
    MEM_PROP_EXP(MatrixLayout, xSlots, int, self.xSlots_.get(), self.xSlots_.set(value); self.update_layout_()); /// Number of slots in x-axis
    MEM_PROP_EXP(MatrixLayout, ySlots, int, self.ySlots_.get(), self.ySlots_.set(value); self.update_layout_()); /// Number of slots in y-axis

    MEM_PROP_EXP(MatrixLayout, dir, Direction, self.dir_.get(), self.dir_.set(value); self.update_layout_());             /// Direction to flow in slots
    MEM_PROP_EXP(MatrixLayout, wrapDir, Direction, self.wrapDir_.get(), self.wrapDir_.set(value); self.update_layout_()); /// Direction to wrap in slots

    MEM_PROP_EXP(MatrixLayout, align, Align, self.align_.get(), self.align_.set(value); self.update_layout_());             /// Align in the flow
    MEM_PROP_EXP(MatrixLayout, wrapAlign, Align, self.wrapAlign_.get(), self.wrapAlign_.set(value); self.update_layout_()); /// Align in the wrap

    static std::shared_ptr<MatrixLayout> create() {
        return std::shared_ptr<MatrixLayout>(new MatrixLayout);
    }

    std::shared_ptr<Node> recreate() const override {
        return std::shared_ptr<MatrixLayout>(new MatrixLayout);
    }

    void sync(const std::shared_ptr<Node> &proto) override {
        auto layout = std::dynamic_pointer_cast<MatrixLayout>(proto);
        if (!layout) {
            throw std::runtime_error("Prototype of a different type cannot be used to synchronize parameters");
        }

        Node::sync(proto);

        xSlots_.set_proto(layout->xSlots_.get());
        ySlots_.set_proto(layout->ySlots_.get());
        dir_.set_proto(layout->dir_.get());
        wrapDir_.set_proto(layout->wrapDir_.get());
        align_.set_proto(layout->align_.get());
        wrapAlign_.set_proto(layout->wrapAlign_.get());
    }

    void on_model() override;
};

class MatrixItem : public Context {
    Param<int>   xSpan_   = 1;
    Param<int>   ySpan_   = 1;
    Param<float> xWeight_ = 1.0f;
    Param<float> yWeight_ = 1.0f;

    void update_layout_();

  protected:
    MatrixItem() = default;

  public:
    MEM_PROP_EXP(MatrixItem, xSpan, int, self.xSpan_.get(), self.xSpan_.set(value); self.update_layout_());         /// Number of slots to occupy in x-axis
    MEM_PROP_EXP(MatrixItem, ySpan, int, self.ySpan_.get(), self.ySpan_.set(value); self.update_layout_());         /// Number of slots to occupy in y-axis
    MEM_PROP_EXP(MatrixItem, xWeight, float, self.xWeight_.get(), self.xWeight_.set(value); self.update_layout_()); /// Weighted alignment in x-axis (averaged for all items in the slot)
    MEM_PROP_EXP(MatrixItem, yWeight, float, self.yWeight_.get(), self.yWeight_.set(value); self.update_layout_()); /// Weighted alignment in y-axis (averaged for all items in the slot)

    static std::shared_ptr<MatrixItem> create() {
        return std::shared_ptr<MatrixItem>(new MatrixItem);
    }

    std::shared_ptr<Context> clone() override {
        auto clone = create();
        clone->sync(shared_from_this());
        return clone;
    }

    void sync(const std::shared_ptr<Context> &proto) override {
        auto context = std::dynamic_pointer_cast<MatrixItem>(proto);
        if (!context) {
            throw std::runtime_error("Prototype of a different type cannot be used to synchronize parameters");
        }

        xSpan_.set_proto(context->xSpan_.get());
        ySpan_.set_proto(context->ySpan_.get());
        xWeight_.set_proto(context->xWeight_.get());
        yWeight_.set_proto(context->yWeight_.get());
    }
};

/// Arranges items by splitting view recursively based on aspect ratio
/// Note: does not traverse the children. It only arranges the immediate children in abstract split space
class SplitLayout : public Node {
    Param<std::vector<float>> splitWeights_ = std::vector{1.0f, 1.0f};
    Param<Direction>          splitDir_     = DIRECTION_RIGHT;
    Param<Direction>          wrapDir_      = DIRECTION_DOWN;
    Param<int>                minDepth_     = 0;

    void update_layout_();

  protected:
    SplitLayout() = default;

  public:
    MEM_PROP_EXP(SplitLayout, splitWeights, std::vector<float>, self.splitWeights_.get(), self.splitWeights_.set(value); self.update_layout_()); /// Number of splits and weight of each split
    MEM_PROP_EXP(SplitLayout, splitDir, Direction, self.splitDir_.get(), self.splitDir_.set(value); self.update_layout_());                      /// Direction to split primarily
    MEM_PROP_EXP(SplitLayout, wrapDir, Direction, self.wrapDir_.get(), self.wrapDir_.set(value); self.update_layout_());                         /// Direction to split alternatively
    MEM_PROP_EXP(SplitLayout, minDepth, int, self.minDepth_.get(), self.minDepth_.set(value); self.update_layout_());                            /// Minimum split depth initially

    static std::shared_ptr<SplitLayout> create() {
        return std::shared_ptr<SplitLayout>(new SplitLayout);
    }

    std::shared_ptr<Node> recreate() const override {
        return std::shared_ptr<SplitLayout>(new SplitLayout);
    }

    void sync(const std::shared_ptr<Node> &proto) override {
        auto layout = std::dynamic_pointer_cast<SplitLayout>(proto);
        if (!layout) {
            throw std::runtime_error("Prototype of a different type cannot be used to synchronize parameters");
        }

        Node::sync(proto);

        splitWeights_.set_proto(layout->splitWeights_.get());
        splitDir_.set_proto(layout->splitDir_.get());
        wrapDir_.set_proto(layout->wrapDir_.get());
        minDepth_.set_proto(layout->minDepth_.get());
    }

    void on_model() override;
};

class SplitItem : public Context {
    void update_layout_();

  protected:
    SplitItem() = default;

  public:
    static std::shared_ptr<SplitItem> create() {
        return std::shared_ptr<SplitItem>(new SplitItem);
    }

    std::shared_ptr<Context> clone() override {
        auto clone = create();
        clone->sync(shared_from_this());
        return clone;
    }

    void sync(const std::shared_ptr<Context> &proto) override {
        auto context = std::dynamic_pointer_cast<SplitItem>(proto);
        if (!context) {
            throw std::runtime_error("Prototype of a different type cannot be used to synchronize parameters");
        }
    }
};
