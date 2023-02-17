#pragma once

#include "geometry/polygon.hpp"
// area of polygon
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
Double area(const Polygon &p) {
    int n = (int)p.size();
    assert(n >= 2);
    Double ret = Double(0);
    for (int i = 0; i < n - 1; i++) {
        ret += cross(p[i], p[i + 1]);
    }
    ret += cross(p[n - 1], p[0]);
    // counter clockwise: ret > 0
    // clockwise: ret < 0
    return std::abs(ret) / 2;
}