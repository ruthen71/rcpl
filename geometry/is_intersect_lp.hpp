#pragma once

#include "geometry/line.hpp"
#include "geometry/ccw.hpp"

// intersection (line and point)
// ccw(a, b, c) == ON_SEGMENT or ONLINE_BACK or ONLINE_FRONT
bool is_intersect_lp(const Line &l, const Point &p) {
    int res = ccw(l.a, l.b, p);
    return (res == ONLINE_BACK or res == ONLINE_FRONT or res == ON_SEGMENT);
}