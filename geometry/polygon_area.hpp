#pragma once

#include "geometry/polygon.hpp"

// area of polygon
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
// return area * 2
template <typename T> T polygon_area2(const Polygon<T> &p) {
    int n = (int)p.size();
    assert(n >= 2);
    T ret = T(0);
    for (int i = 0; i < n - 1; i++) {
        ret += cross(p[i], p[i + 1]);
    }
    ret += cross(p[n - 1], p[0]);
    // counter clockwise: ret > 0
    // clockwise: ret < 0
    return std::abs(ret);
}
template <typename T> T polygon_area(const Polygon<T> &p) { return polygon_area2(p) / T(2); }