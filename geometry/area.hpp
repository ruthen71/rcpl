#pragma once

#include "geometry/polygon.hpp"
// area of polygon
Double area(const Polygon &p) {
    int n = (int)p.size();
    assert(n >= 3);
    Double ret = Double(0);
    for (int i = 0; i < n - 1; i++) {
        ret += cross(p[i], p[i + 1]);
    }
    ret += cross(p[n - 1], p[0]);
    // 点が反時計回りに並んでいた場合はret>0で、時計回りに並んでいた場合はret<0
    return std::abs(ret) / 2;
}