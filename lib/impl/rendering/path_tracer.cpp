#include "rendering/path_tracer.h"

using namespace tkr;

PathTracer::PathTracer(std::shared_ptr<Scene> scene, std::shared_ptr<PerspectiveCamera> camera)
: mScene(scene)
, mCamera(camera)
{}

Image PathTracer::renderToImage() const
{
    // TODO: provide impl
    auto viewport = mCamera->viewport();
    const auto width = viewport->width();
    const auto height = viewport->height();
    Image img(width, height);

    for (int yi = 0; yi < height; ++yi) {
        for (int xj = 0; xj < width; ++xj) {
            const auto ray = mCamera->rayThroughPixel(yi, xj);

            const auto pixelValue = static_cast<char>(255 * static_cast<int>(std::floor(yi / height)));
            img.setPixel(yi, xj, pixelValue);
        }
    }

    // auto node = mScene->node();
    // const auto renderables = node->renderables();
    // for (auto renderable : renderables) {
    // 
    //     renderable->rayIntersect
    // }

    return img;
}