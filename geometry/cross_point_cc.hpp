#pragma once

#include "geometry/is_intersect_cc.hpp"

// cross point (circle and circle)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
template <typename T> std::vector<Point<T>> cross_point_cc(const Circle<T> &c1, const Circle<T> &c2) {
    if (!is_intersect_cc(c1, c2)) return {};
    T d = abs(c1.o - c2.o);
    T a = std::acos((c1.r * c1.r - c2.r * c2.r + d * d) / (T(2) * c1.r * d));
    T t = arg(c2.o - c1.o);
    Point<T> p = c1.o + polar(c1.r, t + a);
    Point<T> q = c1.o + polar(c1.r, t - a);
    if (equal(p.x, q.x) and equal(p.y, q.y)) return {p};
    return {p, q};
}