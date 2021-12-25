#include "rendering/ray.h"

using namespace mq;

namespace tkr
{
    Ray::Ray(const vec3& from, const vec3& to)
    : mOrigin(from)
    , mDirection(to - from)
    {}
    
    vec3 Ray::at(float t) const
    {
        return mOrigin + t * mDirection;
    }
} // namespace tkr