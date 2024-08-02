#pragma once

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/circle.hpp"
#include "geometry/cross_point.hpp"

// 三角形の外接円
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C
// https://drken1215.hatenablog.com/entry/2020/10/16/074400
template <class T> Circle<T> circumscribed_circle(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    static_assert(is_geometry_floating_point<T>::value == true);
    Line<T> l1((a + b) / 2, (a + b) / 2 + rotate(b - a, Constants<T>::PI / 2));
    Line<T> l2((b + c) / 2, (b + c) / 2 + rotate(c - b, Constants<T>::PI / 2));
    auto o = cross_point(l1, l2);
    auto r = abs(o - a);
    return Circle(o, r);
}