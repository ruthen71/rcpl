#pragma once

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/is_intersect.hpp"

// 距離 (直線, 線分, 点)
// 点 p1, p2 の距離
template <class T> T distance(const Point<T>& p1, const Point<T>& p2) { return abs(p1 - p2); }

// 直線 l, 点 p の距離
template <class T> T distance(const Line<T>& l, const Point<T>& p) {
    static_assert(is_geometry_floating_point<T>::value == true);
    return abs(p - projection(l, p));
}
template <class T> T distance(const Point<T>& p, const Line<T>& l) { return distance(l, p); }

// 線分 s, 点 p の距離
template <class T> T distance(const Segment<T>& s, const Point<T>& p) {
    static_assert(is_geometry_floating_point<T>::value == true);
    Point<T> r = projection(s, p);
    if (is_intersect(s, r)) return abs(r - p);
    return std::min(abs(s.a - p), abs(s.b - p));
}
template <class T> T distance(const Point<T>& p, const Segment<T>& s) { return distance(s, p); }

// 直線 l1, l2 の距離
template <class T> T distance(const Line<T>& l1, const Line<T>& l2) {
    static_assert(is_geometry_floating_point<T>::value == true);
    if (is_intersect(l1, l2)) return 0;
    return distance(l1, l2.a);
}

#include <algorithm>

// 直線 l, 線分 s の距離
template <class T> T distance(const Line<T>& l, const Segment<T>& s) {
    static_assert(is_geometry_floating_point<T>::value == true);
    if (is_intersect(l, s)) return 0;
    return std::min(distance(l, s.a), distance(l, s.b));
}
template <class T> T distance(const Segment<T>& s, const Line<T>& l) { return distance(l, s); }

// 線分 s1, s2 の距離
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
template <class T> T distance(const Segment<T>& s1, const Segment<T>& s2) {
    static_assert(is_geometry_floating_point<T>::value == true);
    if (is_intersect(s1, s2)) return 0;
    return std::min({distance(s1, s2.a), distance(s1, s2.b), distance(s2, s1.a), distance(s2, s1.b)});
}