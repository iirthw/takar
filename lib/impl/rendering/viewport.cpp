#include "rendering/viewport.h"

#include <cassert>

#include "mq.h"

using namespace mq;

namespace tkr {

    Viewport::Viewport(float aspect, float height)
    : mAspect(aspect)
    , mWidth(aspect * height)
    , mHeight(height)
    {
        assert(!isZero(mAspect));
    }

    void Viewport::setWidth(float width)
    {
        assert(!isZero(mAspect));
        mWidth = width;
        mHeight = mWidth / mAspect;
    }

    void Viewport::setHeight(float height)
    {
        mHeight = height;
        mWidth = mAspect * mHeight;
    }

} // namespace tkr