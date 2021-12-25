#pragma once

#include "rendering/ray.h"
#include "rendering/renderable.h"
#include "vec3.h"

namespace tkr {
    class Sphere : Renderable {
    public:
        Sphere(const mq::vec3& center, float radius);

        virtual bool rayIntersect(const Ray& ray) const;

        mq::vec3 center() const { return mCenter; }
        float radius() const { return mRadius; }

    private:
        mq::vec3 mCenter;
        float mRadius;
    }; // class Sphere
} // namespace tkr