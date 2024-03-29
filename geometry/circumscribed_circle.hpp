#pragma once

#include "geometry/cross_point_ll.hpp"
#include "geometry/circle.hpp"

// circumscribed circle of a triangle
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C
// https://drken1215.hatenablog.com/entry/2020/10/16/074400
template <typename T> Circle<T> circumscribed_circle(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    Line l1((a + b) / 2, (a + b) / 2 + rotate(b - a, Point<T>::PI / 2)), l2((b + c) / 2, (b + c) / 2 + rotate(c - b, Point<T>::PI / 2));
    auto o = cross_point_ll(l1, l2);
    auto r = abs(o - a);
    return Circle(o, r);
}