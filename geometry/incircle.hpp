#pragma once

#include "geometry/cross_point_ll.hpp"
#include "geometry/distance_lp.hpp"
#include "geometry/circle.hpp"

// incircle of a triangle
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B
// https://drken1215.hatenablog.com/entry/2020/10/16/073700
template <typename T> Circle<T> incircle(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    T A = arg((c - a) / (b - a)), B = arg((a - b) / (c - b));
    Line l1(a, a + rotate(b - a, A / 2)), l2(b, b + rotate(c - b, B / 2));
    auto o = cross_point_ll(l1, l2);
    auto r = distance_lp(Line(a, b), o);
    return Circle(o, r);
}