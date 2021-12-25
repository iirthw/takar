#include "rendering/path_tracer.h"

using namespace tkr;

PathTracer::PathTracer(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera)
: mScene(scene)
, mCamera(camera)
{}

Image PathTracer::renderToImage() const
{
    // TODO: provide impl
    Image img(1, 1);
    return img;
}