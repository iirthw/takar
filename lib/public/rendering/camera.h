#pragma once

#define _USE_MATH_DEFINES
#include <math.h> // Must be a first include in the file which is disagreeable.

#include <memory>

#include "geometry/rect.h"
#include "geometry/quad.h"
#include "rendering/ray.h"
#include "rendering/viewport.h"
#include "mat.h"
#include "vec3.h"

namespace tkr {
    struct Frustum {
    public:
        Frustum(float fovy, float aspect, float near, float far);

        float fovx() const { return mFovy * mAspect; }
        float fovy() const { return mFovy; }

    private:
        float mFovy;
        float mAspect;
        float mNear;
        float mFar;
    }; // struct Frustrum

    class Projection {
        static mq::mat4 perspective(float fovy, float aspect, float near, float far);
    }; // class Projection

    class PerspectiveCamera {
    public:
        PerspectiveCamera(std::shared_ptr<Viewport> viewport, 
            const mq::vec3& origin, const mq::vec3& lookAt,
            Frustum frustum, const mq::vec3& up = mq::vec3(0.0f, 1.0f, 0.0f));

        Ray rayThroughPixel(int row, int column) const;

        mq::vec3 origin() const { return mOrigin; }
        mq::vec3 lookAt() const { return mLookAt; }

        void setOrigin(const mq::vec3& origin) { mOrigin = origin; }
        void setLookAt(const mq::vec3& lookAt) { mLookAt = lookAt; }

        std::shared_ptr<Viewport> viewport() const { return mViewport; }

    private:
        
        static Rect computeNearPlane(float fovx, float fovy, mq::vec3 lookAt, mq::vec3 right, mq::vec3 up);
        
        std::shared_ptr<Viewport> mViewport;
        mq::vec3 mOrigin;
        mq::vec3 mLookAt;        
        mq::vec3 mRight;
        mq::vec3 mUp;
        Frustum mFrustum;
        Quad<mq::vec3> mNearPlane;
    }; // class PerspectiveCamera

} // namespace tkr
