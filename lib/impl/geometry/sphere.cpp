#include "geometry/sphere.h"

namespace tkr {
    Sphere::Sphere(const mq::vec3& center, float radius)
    : mCenter(center)
    , mRadius(radius)
    {}

    bool Sphere::rayIntersect(const Ray& ray) const
    {
        // TODO: 
    }
} // namespace tkr