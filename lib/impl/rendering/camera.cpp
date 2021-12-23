#include "rendering/camera.h"

using namespace mq;

namespace tkr {
    Camera::Camera(std::shared_ptr<Viewport> viewport, const vec3& origin,
        const vec3& lookAt, const vec3& up)
    : mViewport(viewport)
    , mOrigin(origin)
    , mLookAt(lookAt)
    , mUp(up)
    {}
    
} // namespace tkr