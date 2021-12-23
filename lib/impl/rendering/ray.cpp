#include "ray.h"

using namespace mq3;

namespace tkr
{
    Ray::Ray(const vec3& origin, const vec3& direction)
    : mOrigin(origin)
    , mDirection(direction)
    {}
    
    vec3 Ray::at(double t)
    {
        return mOrigin + t * mDirection;
    }
} // namespace tkr