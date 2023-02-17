#pragma once

#include "geometry/line.hpp"
#include "geometry/is_parallel.hpp"

// intersection (line and line)
bool is_intersect_ll(const Line &l1, const Line &l2) {
    Point base = l1.b - l1.a;
    Double d12 = cross(base, l2.b - l2.a);
    Double d1 = cross(base, l1.b - l2.a);
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