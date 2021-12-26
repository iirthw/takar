#pragma once

#include <memory>

#include "rendering/node.h"

namespace tkr {
    class Scene {
    public:
        Scene() = default;
        Scene(std::shared_ptr<Node> node);

        std::shared_ptr<Node> node() const { return mNode; }

    private:

        std::shared_ptr<Node> mNode; // currently single node, instead of a tree
    }; // class Scene
} // namespace tkr