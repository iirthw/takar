#pragma once

#include "vec2.h"

namespace tkr {

    class Rect {
    public:
        Rect();
        Rect(float x, float y, float width, float height);
        Rect(const mq::vec2& origin, float width, float height);

        bool degenerate() const;
        float area() const;

    private:

        float mX;
        float mY;
        float mWidth;
        float mHeight;
    }; // class Rect

} // namespace tkr