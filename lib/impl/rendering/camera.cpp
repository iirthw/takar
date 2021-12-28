#include "rendering/camera.h"

#include "vec3.h"

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

    Ray rayThroughPixel(int row, int column) const
    {
        return Ray(vec3::zero(), vec3{1.f, 0.f, 0.f});
    }
    
} // namespace tkr