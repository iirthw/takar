#pragma once

#include "geometry/rect.h"

namespace tkr {

    class Viewport {
    public:
        Viewport(float aspect, float height);

        float aspect() const { return mAspect; }
        float width() const { return mWidth; }
        float height() const { return mHeight; }
        
        void setWidth(float width);
        void setHeight(float height);

    private:
        float mAspect;
        float mWidth;
        float mHeight;
    }; // class Viewport    

} // namespace tkr