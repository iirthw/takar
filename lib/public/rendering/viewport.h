#pragma once

#include "rect.h"

namespace tkr {

    class Viewport {
    public:
        Viewport(float aspectRatio, float height);
        Viewport(float aspectRatio, float width);
        Viewport(float width, float height);

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