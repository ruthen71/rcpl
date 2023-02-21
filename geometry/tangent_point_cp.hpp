#pragma once

#include "geometry/cross_point_cc.hpp"

// tangent point (circle and point)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
std::pair<Point, Point> tangent_point_cp(const Circle &c, const Point &p) {
    assert(sign(std::abs(c.o - p) - c.r) == 1);
    auto res = cross_point_cc(c, Circle(p, sqrt(std::norm(c.o - p) - std::norm(c.r))));
    return {res[0], res[1]};
}