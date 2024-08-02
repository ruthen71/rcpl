#pragma once

#include "geometry/point.hpp"
#include "geometry/circle.hpp"
#include "geometry/line.hpp"
#include "geometry/cross_point.hpp"
#include "geometry/distance.hpp"

// 三角形の内接円
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B
// https://drken1215.hatenablog.com/entry/2020/10/16/073700
template <class T> Circle<T> incircle(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    static_assert(is_geometry_floating_point<T>::value == true);
    T A = arg((c - a) / (b - a)), B = arg((a - b) / (c - b));
    Line l1(a, a + rotate(b - a, A / 2)), l2(b, b + rotate(c - b, B / 2));
    auto o = cross_point(l1, l2);
    auto r = distance(Line(a, b), o);
    return Circle(o, r);
}
