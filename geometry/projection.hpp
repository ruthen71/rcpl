#pragma once

#include "geometry/line.hpp"
#include "geometry/point.hpp"

// projection
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
template <typename T> Point<T> projection(const Line<T> &l, const Point<T> &p) {
    T t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    return l.a + t * (l.b - l.a);
}