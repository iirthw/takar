#pragma once

#include <memory>

#include "vec3.h"

namespace tkr {
    class Camera {
    public:
        Camera(const mq::vec3& origin, const mq::vec3& lookAt, float fov,
         float near = 1, float far = 1024, const mq::vec3& up = mq::vec3(0.0f, 1.0f, 0.0f));

        mq::vec3 origin() const { return mOrigin; }
        mq::vec3 lookAt() const { return mLookAt; }

        void setOrigin(const mq::vec3& origin) { mOrigin = origin; }
        void setLookAt(const mq::vec3& lookAt) { mLookAt = lookAt; }

    private:
        mq::vec3 mOrigin;
        mq::vec3 mLookAt;
        float mFov;
        float mNear;
        float mFar;
        mq::vec3 mUp;
    }; // class Camera

} // namespace tkr