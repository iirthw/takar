#pragma once

#include <memory>

#include "vec3.h"

namespace tkr {
    class Camera {
    public:
        Camera(std::shared_ptr<Viewport> viewport, const mq::vec3& origin, 
            const mq::vec3& lookAt, const mq::vec3& up = vec3(0.0f, 1.0f, 0.0f));

        mq::vec3 origin() const { return mOrigin; }
        mq::vec3 lookAt() const { return mLookAt; }

        void setOrigin(const mq::vec3& origin) { mOrigin = origin; }
        void setLookAt(const mq::vec3& lookAt) { mLookAt = lookAt; }

    private:
        std::shared_ptr<Viewport> mViewport;
        mq::vec3 mOrigin;
        mq::vec3 mLookAt;
        mq::vec3 mUp;
    }; // class Camera

} // namespace tkr