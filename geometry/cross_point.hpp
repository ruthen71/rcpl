#pragma once

#include <cassert>
#include <vector>

#include "../geometry/circle.hpp"
#include "../geometry/is_intersect.hpp"
#include "../geometry/line.hpp"
#include "../geometry/point.hpp"

// 交点 (直線, 線分, 円)
// 交点を持たない場合の挙動は未定義
// 直線 l1, l2 の交点 1 つ
template <class T> Point<T> cross_point(const Line<T>& l1, const Line<T>& l2) {
    static_assert(is_geometry_floating_point<T>::value == true);
    Point<T> base = l1.b - l1.a;
    T d12 = cross(base, l2.b - l2.a);
    T d1 = cross(base, l1.b - l2.a);
    if (sign(d12) == 0) {
        assert(sign(d1) == 0);  // 平行かつ一致しない
        return l2.a;
    }
    return l2.a + (l2.b - l2.a) * (d1 / d12);
}

// 線分 s1, s2 の交点 1 つ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
template <class T>
Point<T> cross_point(const Segment<T>& s1, const Segment<T>& s2) {
    static_assert(is_geometry_floating_point<T>::value == true);
    Point<T> base = s1.b - s1.a;
    T d12 = cross(base, s2.b - s2.a);
    T d1 = cross(base, s1.b - s2.a);
    if (sign(d12) == 0) {
        assert(sign(d1) == 0);  // 平行かつ一致しない
        // 端点のどれかを返す
        if (is_intersect(s1, s2.a)) return s2.a;
        if (is_intersect(s1, s2.b)) return s2.b;
        if (is_intersect(s2, s1.a)) return s1.a;
        assert(is_intersect(s2, s1.b));
        return s1.b;
    }
    return s2.a + (s2.b - s2.a) * (d1 / d12);
}

// 直線 l, 線分 s の交点 1 つ
template <class T> Point<T> cross_point(const Line<T>& l, const Segment<T>& s) {
    // cross_point(l1, l2) は重なるとき l2.a を返すので OK
    return cross_point(l, Line<T>(s.a, s.b));
}
template <class T> Point<T> cross_point(const Segment<T>& s, const Line<T>& l) {
    return cross_point(l, s);
}

// 円 c, 直線 l の交点 1 or 2 つ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
template <class T>
std::vector<Point<T>> cross_point(const Circle<T>& c, const Line<T>& l) {
    static_assert(is_geometry_floating_point<T>::value == true);
    auto pr = projection(l, c.o);
    if (equal(norm(pr - c.o), c.r * c.r)) return {pr};
    Point<T> e = (l.b - l.a) / abs(l.b - l.a);
    auto k = sqrtl(c.r * c.r - norm(pr - c.o));
    return {pr - e * k, pr + e * k};
}
template <class T>
std::vector<Point<T>> cross_point(const Line<T>& l, const Circle<T>& c) {
    return cross_point(c, l);
}

// 円 c, 線分 s の交点 1 or 2 つ
template <class T>
std::vector<Point<T>> cross_point(const Circle<T>& c, const Segment<T>& s) {
    assert(is_intersect(c, s));
    auto ps = cross_point(c, Line<T>(s.a, s.b));
    std::vector<Point<T>> res;
    for (auto&& p : ps)
        if (ccw(s.a, s.b, p) == Ccw::ON_SEGMENT) res.emplace_back(p);
    return res;
}
template <class T>
std::vector<Point<T>> cross_point(const Segment<T>& s, const Circle<T>& c) {
    return cross_point(c, s);
}

// 円 c1, c2 の交点 1 or 2 つ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
template <class T>
std::vector<Point<T>> cross_point(const Circle<T>& c1, const Circle<T>& c2) {
    static_assert(is_geometry_floating_point<T>::value == true);
    assert(is_intersect(c1, c2));
    T d = abs(c1.o - c2.o);
    T a = std::acos((c1.r * c1.r - c2.r * c2.r + d * d) / (T(2) * c1.r * d));
    T t = arg(c2.o - c1.o);
    Point<T> p = c1.o + polar(c1.r, t + a);
    Point<T> q = c1.o + polar(c1.r, t - a);
    if (equal(p, q)) return {p};
    return {p, q};
}
