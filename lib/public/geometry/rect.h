#pragma once

#include "vec2.h"

namespace tkr
{
    class Rect
    {
    public:
        Rect(float x, float y, float width, float height);
        Rect(const mq::vec2& origin, float width, float height);

    private:
        float mX;
        float mY;
        float mWidth;
        float mHeight;
    };
} // namespace tkr