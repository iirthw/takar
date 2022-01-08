#pragma once

#include "geometry/bounding_box.h"
#include "rendering/ray.h"

namespace tkr
{
    class Renderable
    {
    public:
        virtual bool rayIntersect(const Ray& ray) const = 0;

        virtual BoundingBox boundingBox() const;
    }; // class Renderable
} // namespace tkr