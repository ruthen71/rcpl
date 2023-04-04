#pragma once

#include "geometry/is_intersect_cc.hpp"

// cross point (circle and circle)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
std::vector<Point> cross_point_cc(const Circle &c1, const Circle &c2) {
    if (!is_intersect_cc(c1, c2)) return {};
    Double d = abs(c1.o - c2.o);
    Double a = std::acos((norm(c1.r) - norm(c2.r) + norm(d)) / (Double(2) * c1.r * d));
    Double t = arg(c2.o - c1.o);
    Point p = c1.o + polar(c1.r, t + a);
    Point q = c1.o + polar(c1.r, t - a);
    if (equal(p.x, q.x) and equal(p.y, q.y)) return {p};
    return {p, q};
}