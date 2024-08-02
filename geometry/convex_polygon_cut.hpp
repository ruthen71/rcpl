#pragma once

#include "geometry/line.hpp"
#include "geometry/polygon.hpp"
#include "geometry/cross_point.hpp"

#include <utility>

// 凸多角形 p を 直線 l で切断
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
// return {left polygon, right polygon}
template <class T> std::pair<Polygon<T>, Polygon<T>> convex_polygon_cut(const Polygon<T>& p, const Line<T>& l) {
    static_assert(is_geometry_floating_point<T>::value == true);
    const int n = (int)(p.size());
    assert(n >= 3);
    Polygon<T> pl, pr;
    for (int i = 0; i < n; i++) {
        int ni = i + 1 == n ? 0 : i + 1;
        const int s1 = sign(cross(l.a - p[i], l.b - p[i]));
        const int s2 = sign(cross(l.a - p[ni], l.b - p[ni]));
        if (s1 >= 0) {
            pl.push_back(p[i]);
        }
        if (s1 <= 0) {
            pr.push_back(p[i]);
        }
        if (s1 * s2 < 0) {
            auto pc = cross_point(Line(p[i], p[ni]), l);
            pl.push_back(pc);
            pr.push_back(pc);
        }
    }
    return {pl, pr};
}