#pragma once

#include <memory>

#include "image.h"
#include "rendering/camera.h"
#include "rendering/scene.h"

namespace tkr {
    class PathTracer {
    public:
        PathTracer(std::shared_ptr<Scene> scene, std::shared_ptr<PerspectiveCamera> camera);

        Image renderToImage() const;

    private:
        std::shared_ptr<Scene> mScene;
        std::shared_ptr<PerspectiveCamera> mCamera;
    }; // class PathTracer

} // namespace tkr