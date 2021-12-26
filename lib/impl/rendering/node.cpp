#include "rendering/node.h"

namespace tkr {
    Node::Node(std::shared_ptr<Renderable> renderable)
    : mRenderables(std::vector<std::shared_ptr<Renderable>>{renderable})
    {}
} // namespace tkr