#include "rendering/camera.h"

#include <cmath>
#include "vec3.h"

using namespace mq;

namespace tkr {
    // =========================================================================

    Frustum::Frustum(float fov, float near, float far)
    :  mNearPlane() {

    }

    // =========================================================================

    mq::mat4 Projection::perspective(float fovy, float aspect, float near, float far)
    {
        /*
        | scale 0       0                           0  |
        | 0     scale   0                           0  |
        | 0     0       -far / (far - near)         -1 |
        | 0     0       -far * near / (far - near)  0  |
        */
        const float scale = 1 / tan(fovy * 0.5f);
        mq::mat4 P;
        P[0][0] = scale; // scale x-coord of projected point
        P[1][1] = scale; // scale y-corod of projected point
        const float temp = -far / (far - near);
        P[2][2] = temp; // remap x to [0, 1]
        P[3][2] = near * temp; // remap x to [0, 1]
        P[2][3] = -1;

        return P;
    }

    // =========================================================================

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