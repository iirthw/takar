#include "geometry/rect.h"

#include "mq.h"

using namespace mq;

namespace tkr
{
    Rect::Rect() : mX(0.0f), mY(0.0f), mWidth(0.0f), mHeight(0.0f) {}

    Rect::Rect(float x, float y, float width, float height)
    : mX(x)
    , mY(y)
    , mWidth(width)
    , mHeight(height)
    {}

    Rect::Rect(const vec2& origin, float width, float height)
    : Rect(origin.x, origin.y, width, height)
    {}

    bool Rect::degenerate() const
    {
        return isZero(area());
    }

    float Rect::area() const
    {
        return mWidth * mHeight;
    }
} // namespace tkr