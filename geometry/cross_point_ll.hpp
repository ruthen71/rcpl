#pragma once

#include "geometry/line.hpp"

// cross point (line and line)
Point cross_point_ll(const Line &l1, const Line &l2) {
    Point base = l1.b - l1.a;
    Double d12 = cross(base, l2.b - l2.a);
    Double d1 = cross(base, l1.b - l2.a);
    // 一致(sign(d12) == 0 は is_parallelと本質的に同じ, sign(d1) == 0は重なっているか)
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