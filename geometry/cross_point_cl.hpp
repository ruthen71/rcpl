#pragma once

#include "geometry/is_intersect_cl.hpp"
#include "geometry/projection.hpp"

// cross point (circle and line)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
std::vector<Point> cross_point_cl(const Circle &c, const Line &l) {
    assert(is_intersect_cl(c, l));
    auto pr = projection(l, c.o);
    if (equal(std::abs(pr - c.o), c.r)) return {pr};
    Point e = (l.b - l.a) / abs(l.b - l.a);
    auto k = sqrt(std::norm(c.r) - std::norm(pr - c.o));
    return {pr - e * k, pr + e * k};
}