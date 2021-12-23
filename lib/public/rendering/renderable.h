#pragma once

#include "rendering/ray.h"

namespace tkr
{
    class Renderable
    {
    public:
        virtual bool rayIntersect(const Ray& ray) const = 0;
    }; // class Renderable
} // namespace tkr