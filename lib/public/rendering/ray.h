#pragma once

#include "vec3.h"

namespace tkr {

    class Ray {
    public:
        Ray(const mq::vec3& origin, const mq::vec3& direction);

        mq::vec3 at(float t) const;
        inline mq::vec3 origin() const { return mOrigin; }
        inline mq::vec3 direction() const { return mDirection; }

    private:

        mq::vec3 mOrigin;
        mq::vec3 mDirection;
    }; // class Ray

} // namespace tkr