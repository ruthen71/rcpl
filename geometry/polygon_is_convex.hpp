#pragma once

#include "geometry/polygon.hpp"
#include "geometry/ccw.hpp"

// check polygon is convex (not strictly, 0 <= angle <= 180 degrees)
// angle = 180 degrees -> ON_SEGMENT
// angle = 0 degrees -> ONLINE_FRONT or ONLINE_BACK
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
template <typename T> bool polygon_is_convex(const Polygon<T> &p) {
    int n = (int)p.size();
    assert(n >= 3);
    bool okccw = true, okcw = true;
    for (int i = 0; i < n - 2; i++) {
        int res = ccw(p[i], p[i + 1], p[i + 2]);
        if (res == CLOCKWISE) okccw = false;
        if (res == COUNTER_CLOCKWISE) okcw = false;
        if (!okccw and !okcw) return false;
    }
    {
        int res = ccw(p[n - 2], p[n - 1], p[0]);
        if (res == CLOCKWISE) okccw = false;
        if (res == COUNTER_CLOCKWISE) okcw = false;
        if (!okccw and !okcw) return false;
    }
    {
        int res = ccw(p[n - 1], p[0], p[1]);
        if (res == CLOCKWISE) okccw = false;
        if (res == COUNTER_CLOCKWISE) okcw = false;
        if (!okccw and !okcw) return false;
    }
    return true;
}