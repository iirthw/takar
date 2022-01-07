#include "rendering/camera.h"

#include <cmath>
#include "vec3.h"

using namespace mq;

namespace tkr {
    Frustum::Frustum(float fov, float near, float far)
    :  mNearPlane() {

    }

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

    Ray PerspectiveCamera::rayThroughPixel(int row, int column) const
    {
        return Ray(vec3::getZero(), vec3{1.f, 0.f, 0.f}); 
    }
    
} // namespace tkr