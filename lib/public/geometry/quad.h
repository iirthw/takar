#pragma once

namespace tkr {
    template<typename T>
    class Quad {
    public:
        Quad(const T& p0, const T& p1, const T& p2, T p3);

    private:
        T mPoints[4];
    };
} // namespace tkr