#pragma once

namespace tkr {
    template<typename T>
    class Quad {
    public:
        Quad(T p0, T p1, T p2, T p3);

    private:
        T mPoints[4];
    };
} // namespace tkr