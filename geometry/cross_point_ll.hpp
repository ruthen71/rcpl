#pragma once

#include "geometry/line.hpp"

// cross point (line and line)
template <typename T> Point<T> cross_point_ll(const Line<T> &l1, const Line<T> &l2) {
    Point<T> base = l1.b - l1.a;
    T d12 = cross(base, l2.b - l2.a);
    T d1 = cross(base, l1.b - l2.a);
    if (sign(d12) == 0) {
        // parallel
        if (sign(d1) == 0) {
            // cross
            return l2.a;
        } else {
            // not cross
            assert(false);
        }
    }
    return l2.a + (l2.b - l2.a) * (d1 / d12);
}