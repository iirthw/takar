#include "rendering/sphere.h"

namespace tkr {
    Sphere::Sphere(const mq::vec3& center, float radius)
    : mCenter(center)
    , mRadius(radius)
    {}
} // namespace tkr