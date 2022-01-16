#include "rendering/camera.h"

#include <cmath>
#include "vec3.h"

using namespace mq;

namespace tkr {
    // =========================================================================

    Frustum::Frustum(float fovy, float aspect, float near, float far)
    : mFovy(fovy)
    , mAspect(aspect)
    , mNear(near)
    , mFar(far)
    {
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
        const float scaleX = 1 / tan(fovy * 0.5f * aspect);
        const float scaleY = 1 / tan(fovy * 0.5f);
        mq::mat4 P;
        P[0][0] = scaleX;
        P[1][1] = scaleY;
        const float temp = -far / (far - near);
        P[2][2] = temp; // remap x to [0, 1]
        P[3][2] = near * temp; // remap x to [0, 1]
        P[2][3] = -1;

        return P;
    }

    // =========================================================================

    PerspectiveCamera::PerspectiveCamera(std::shared_ptr<Viewport> viewport,
        const vec3& origin, const vec3& lookAt, Frustum frustum, const vec3& up)
    : mViewport(viewport)
    , mOrigin(origin)
    , mLookAt(normalize(lookAt))
    , mRight(normalize(cross(mLookAt, up)))
    , mUp(normalize(cross(mLookAt, mRight)))
    , mFrustum(frustum)
    // r = normalize(r)
    // l = - tan(mFrustum->fovx() / 2) * len(mLookAt) * normalize(mRight)
    // u = - tan(mFrustum->fovy() / 2) * len(mLookAt) * normalize(mUp)
    , mNearPlane(computeNearPlane(mFrustum.fovx(), mFrustum.fovy(), mLookAt, mRight, mUp))
    {}

    Ray PerspectiveCamera::rayThroughPixel(int row, int column) const
    {
        return Ray(vec3::getZero(), vec3{1.f, 0.f, 0.f}); 
    }

    Rect PerspectiveCamera::computeNearPlane(float fovx, float fovy, mq::vec3 lookAt,
                                             mq::vec3 right, mq::vec3 up)
    {
        const auto xtan = tan(fovx / 2);
        const auto ytan = tan(fovy / 2);
        
        return Rect(-xtan * length(lookAt) * normalize(right),
                    );
    }
    
} // namespace tkr
