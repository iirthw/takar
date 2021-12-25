#pragma once

#include <memory>

#include "image.h"
#include "scene.h"

namespace tkr {
    class PathTracer {
    public:
        PathTracer(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera);

        Image renderToImage() const;

    private:
        std::shared_ptr<Scene> mScene;
        std::shared_ptr<Camera> mCamera;
    }; // class PathTracer

} // namespace tkr