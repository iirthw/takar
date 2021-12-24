#pragma once

#include "vec3.h"

namespace tkr {
    class Sphere {
    public:
        Sphere(const mq::vec3& center, float radius);

        mq::vec3 center() const { return mCenter; }
        float radius() const { return mRadius; }

    private:
        mq::vec3 mCenter;
        float mRadius;
    }; // class Sphere
} // namespace tkr