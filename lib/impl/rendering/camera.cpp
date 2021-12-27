#include "rendering/camera.h"

using namespace mq;

namespace tkr {
    PerspectiveCamera::PerspectiveCamera(std::shared_ptr<Viewport> viewport,
        const vec3& origin, const vec3& lookAt, float fov,
        float near, float far, const vec3& up)
    : mViewport(viewport)
    , mOrigin(origin)
    , mLookAt(lookAt)
    , mFov(fov)
    , mNear(near)
    , mFar(far)
    , mUp(up)
    {}
    
} // namespace tkr