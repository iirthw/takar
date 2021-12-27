#include "rendering/viewport.h"

#include <cassert>
#include <cmath>

#include "mq.h"

using namespace mq;

namespace tkr {

    Viewport::Viewport(float aspect, int height)
    : mAspect(aspect)
    , mWidth(static_cast<int>(std::floor(aspect * height)))
    , mHeight(height)
    {
        assert(!isZero(mAspect));
    }

    void Viewport::setWidth(int width)
    {
        assert(!isZero(mAspect));
        mWidth = width;
        mHeight = static_cast<int>(std::floor(mWidth / mAspect));
    }

    void Viewport::setHeight(int height)
    {
        mHeight = height;
        mWidth = static_cast<int>(std::floor(mAspect * mHeight));
    }

} // namespace tkr