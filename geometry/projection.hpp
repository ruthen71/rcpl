#pragma once

#include "geometry/line.hpp"
#include "geometry/point.hpp"

// projection
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
Point projection(const Line &l, const Point &p) {
    Double t = dot(p - l.a, l.b - l.a) / std::norm(l.b - l.a);
    return l.a + t * (l.b - l.a);
}