#pragma once

#include "geometry/cross_point_cc.hpp"

// tangent point (circle and point)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
template <typename T> std::pair<Point<T>, Point<T>> tangent_point_cp(const Circle<T> &c, const Point<T> &p) {
    assert(sign(abs(c.o - p) - c.r) == 1);
    auto res = cross_point_cc(c, Circle(p, sqrt(norm(c.o - p) - c.r * c.r)));
    return {res[0], res[1]};
}