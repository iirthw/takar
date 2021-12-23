#include "rendering/ray.h"

using namespace mq;

namespace tkr
{
    Ray::Ray(const vec3& origin, const vec3& direction)
    : mOrigin(origin)
    , mDirection(direction)
    {}
    
    vec3 Ray::at(float t) const
    {
        return mOrigin + t * mDirection;
    }
} // namespace tkr