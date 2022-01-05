#pragma once

#define _USE_MATH_DEFINES
#include <math.h> // Must be a first include in the file which is disagreeable.

#include <memory>

#include "geometry/rect.h"
#include "rendering/ray.h"
#include "rendering/viewport.h"
#include "vec3.h"

namespace tkr {
    class Frustrum {
    public:
        Frustrum(float fov, float near, float far);

    private:
        Rect mNearPlane;
        Rect mFarPlane;
    };

    class PerspectiveCamera {
    public:
        PerspectiveCamera(std::shared_ptr<Viewport> viewport, 
            const mq::vec3& origin, const mq::vec3& lookAt,
            float fov = M_PI / 4, float near = 1, float far = 1024, 
            const mq::vec3& up = mq::vec3(0.0f, 1.0f, 0.0f));

        Ray rayThroughPixel(int row, int column) const;

        mq::vec3 origin() const { return mOrigin; }
        mq::vec3 lookAt() const { return mLookAt; }

        void setOrigin(const mq::vec3& origin) { mOrigin = origin; }
        void setLookAt(const mq::vec3& lookAt) { mLookAt = lookAt; }

        std::shared_ptr<Viewport> viewport() const { return mViewport; }

    private:
        std::shared_ptr<Viewport> mViewport;
        mq::vec3 mOrigin;
        mq::vec3 mLookAt;
        float mFov;
        float mNear;
        float mFar;
        mq::vec3 mUp;
    }; // class Camera

} // namespace tkr