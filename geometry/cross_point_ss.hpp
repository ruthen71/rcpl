#pragma once

#include "geometry/segment.hpp"
#include "geometry/is_intersect_ss.hpp"
#include "geometry/is_intersect_sp.hpp"

// cross point (segment and segment)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
Point cross_point_ss(const Segment &s1, const Segment &s2) {
    // check intersection s1 and s2
    assert(is_intersect_ss(s1, s2));
    Point base = s1.b - s1.a;
    Double d12 = cross(base, s2.b - s2.a);
    Double d1 = cross(base, s1.b - s2.a);
    if (sign(d12) == 0) {
        // parallel
        if (sign(d1) == 0) {
            // equal
            if (is_intersect_sp(s1, s2.a)) return s2.a;
            if (is_intersect_sp(s1, s2.b)) return s2.b;
            if (is_intersect_sp(s2, s1.a)) return s1.a;
            assert(is_intersect_sp(s2, s1.b));
            return s1.b;
        } else {
            // excepted by is_intersect_ss(s1, s2)
            assert(0);
        }
    }
    return s2.a + (s2.b - s2.a) * (d1 / d12);
}