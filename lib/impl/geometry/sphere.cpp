#include "geometry/sphere.h"

#include "mq.h"

using namespace mq;

namespace tkr {
    Sphere::Sphere(const mq::vec3& center, float radius)
    : mCenter(center)
    , mRadius(radius)
    {}

    bool Sphere::rayIntersect(const Ray& ray) const
    {
        const auto& p0 = ray.origin();
        const auto& p1 = ray.direction();
        // Ray-Sphere intersection could be straightworwardly computed by
        // writing out sphere parametruc equation and substituting parameter
        // point coordinates with the ray parametric equation. That yields a 
        // simple quadratic equation:
        // a * t^2 + b * t + c.
        const auto a = dot(p1, p1);
        const auto b = 2 * dot(p0 - mCenter, p1);
        const auto c = dot(p0 - mCenter, p0 - mCenter) - mRadius * mRadius;

        return discriminant_squared<float>(a, b, c) >= 0;
    }
} // namespace tkr