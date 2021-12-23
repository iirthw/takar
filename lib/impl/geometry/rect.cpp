#include "rect.h"

namespace tkr
{
    Rect::Rect(float x, float y, float width, float height)
    : mX(x)
    , mY(y)
    , mWidth(width)
    , mHeight(height)
    {}

    Rect::Rect(const mq::vec2& origin, float width, float height)
    : Rect(origin.x, origin.y, width, height)
    {}
} // namespace tkr