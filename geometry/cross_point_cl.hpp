#pragma once

#include "geometry/is_intersect_cl.hpp"
#include "geometry/projection.hpp"

// cross point (circle and line)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
template <typename T> std::vector<Point<T>> cross_point_cl(const Circle<T> &c, const Line<T> &l) {
    assert(is_intersect_cl(c, l));
    auto pr = projection(l, c.o);
    if (equal(norm(pr - c.o), c.r * c.r)) return {pr};
    Point<T> e = (l.b - l.a) * (T(1) / abs(l.b - l.a));
    auto k = sqrt(norm(c.r) - norm(pr - c.o));
    return {pr - e * k, pr + e * k};
}