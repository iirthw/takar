#include "rendering/scene.h"

namespace tkr {
    Scene::Scene(std::shared_ptr<Node> node)
    : mNode(node)
    {}
} // namespace tkr