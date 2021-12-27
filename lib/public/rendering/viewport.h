#pragma once

#include "geometry/rect.h"

namespace tkr {

    class Viewport {
    public:
        Viewport(float aspect, int height);

        float aspect() const { return mAspect; }
        int width() const { return mWidth; }
        int height() const { return mHeight; }
        
        void setWidth(int width);
        void setHeight(int height);

    private:
        float mAspect;
        int mWidth;
        int mHeight;
    }; // class Viewport    

} // namespace tkr