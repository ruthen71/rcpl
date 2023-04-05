#pragma once

#include "geometry/line.hpp"

// intersection (line and line)
template <typename T> bool is_intersect_ll(const Line<T> &l1, const Line<T> &l2) {
    Point<T> base = l1.b - l1.a;
    T d12 = cross(base, l2.b - l2.a);
    T d1 = cross(base, l1.b - l2.a);
    if (sign(d12) == 0) {
        // parallel
        if (sign(d1) == 0) {
            // cross
            return true;
        } else {
            // not cross
            return false;
        }
    }
    return true;
}