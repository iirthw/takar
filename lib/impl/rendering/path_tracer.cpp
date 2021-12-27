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
    Image img(viewport->width(), viewport->height());

    // auto node = mScene->node();
    // const auto renderables = node->renderables();
    // for (auto renderable : renderables) {
    // 
    //     renderable->rayIntersect
    // }

    return img;
}