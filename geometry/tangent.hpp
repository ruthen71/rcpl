#pragma once

#include "geometry/point.hpp"
#include "geometry/circle.hpp"
#include "geometry/cross_point.hpp"

#include <vector>

// 円 c の点 p に対する接線
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
template <class T> std::vector<Line<T>> tangent(const Circle<T>& c, const Point<T>& p) {
    static_assert(is_geometry_floating_point<T>::value == true);
    assert(sign(norm(c.o - p) - c.r * c.r) == 1);
    auto tangent_points = cross_point(c, Circle(p, std::sqrt(norm(c.o - p) - c.r * c.r)));
    std::vector<Line<T>> res;
    for (auto&& tp : tangent_points) {
        res.emplace_back(p, tp);
    }
    return res;
}

// 円 c1, c2 の共通接線
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G
template <class T> std::vector<Line<T>> tangent(Circle<T> c1, Circle<T> c2) {
    assert(!(equal(c1.r, c2.r) and equal(c1.o, c2.o)));  // 2 つの円は同一なので接線が無数にある
    std::vector<Line<T>> res;
    if (c1.r < c2.r) std::swap(c1, c2);
    // c1.r >= c2.r
    T g2 = norm(c1.o - c2.o);
    T g = abs(c1.o - c2.o);
    if (equal(g2, T(0))) return res;               // 中心は一致しているが半径が異なる
    Point<T> u = (c2.o - c1.o) / g;                // c1.o から c2.o への単位ベクトル
    Point<T> v = rotate(u, Constants<T>::PI / 2);  // u と直行する単位ベクトル
    for (int s : {-1, 1}) {
        T h = (c1.r + s * c2.r) / g;
        if (equal(1 - h * h, T(0))) {
            res.emplace_back(c1.o + u * c1.r, c1.o + (u + v) * c1.r);
        } else if (sign(1 - h * h) == 1) {
            Point<T> uu = u * h, vv = v * std::sqrt(1 - h * h);
            res.emplace_back(c1.o + (uu + vv) * c1.r, c2.o - (uu + vv) * c2.r * s);
            res.emplace_back(c1.o + (uu - vv) * c1.r, c2.o - (uu - vv) * c2.r * s);
        }
    }
    return res;
}