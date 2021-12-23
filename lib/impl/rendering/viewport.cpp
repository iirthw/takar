#include "viewport.h"

#include <cassert>

using namespace mq;

namespace tkr {

    Viewport::Viewport(float aspect, float height)
    : mAspect(apsect)
    , mWidth(aspect * height)
    , mHeight(height)
    {
        assert(!isZero(mAspect));
    }

    Viewport::Viewport(float apect, float width)
    : mAspect(aspect)
    , mWidth(width)
    , mHeight(!isZero(mAspect) ? mWidth / aspect : 0.0f)
    {
        assert(!isZero(mAspect));
    }

    Viewport::Viewport(float width, float height)
    : mAspect(!isZero(height) ? width / height : 0.0f)
    , mWidth(width)
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