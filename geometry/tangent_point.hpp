#pragma once

#include "geometry/point.hpp"
#include "geometry/circle.hpp"

#include <vector>

// 円の接点 (円の外側の点に対する円の接線の円との交点)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
template <class T> std::vector<Point<T>> tangent_point(const Circle<T>& c, const Point<T>& p) {
    static_assert(is_geometry_floating_point<T>::value == true);
    assert(sign(abs(c.o - p) - c.r) == 1);
    return cross_point(c, Circle(p, sqrtl(norm(c.o - p) - c.r * c.r)));
}