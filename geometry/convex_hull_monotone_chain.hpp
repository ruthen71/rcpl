#pragma once

#include "geometry/polygon.hpp"

#include <algorithm>

// 凸包 (Andrew's Monotone Chain algorithm)
// O(n log n)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
// (x, y) を辞書式順序でソートし, スタックを使って上側凸包と下側凸包を求める
// 反時計回り
// strict を true にすると凸包の辺上に並ぶ頂点は含めない (頂点数が最小になる)
template <class T> Polygon<T> convex_hull_monotone_chain(std::vector<Point<T>>& p, bool strict = true) {
    if (is_geometry_integer<T>::value) {
        std::sort(p.begin(), p.end());
    } else {
        assert(is_geometry_floating_point<T>::value);
        std::sort(p.begin(), p.end(), compare_x<T>);
    }
    p.erase(std::unique(p.begin(), p.end()), p.end());
    const int n = (int)(p.size());
    if (n <= 2) return p;
    Polygon<T> r;
    r.reserve(n * 2);
    auto f = [&strict](Ccw ccwres) -> bool { return strict ? ccwres != Ccw::CLOCKWISE : ccwres == Ccw::COUNTER_CLOCKWISE; };
    for (int i = 0; i < n; i++) {
        while (r.size() >= 2 and f(ccw(r[r.size() - 2], r[r.size() - 1], p[i]))) {
            r.pop_back();
        }
        r.push_back(p[i]);
    }
    int t = r.size() + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (r.size() >= t and f(ccw(r[r.size() - 2], r[r.size() - 1], p[i]))) {
            r.pop_back();
        }
        r.push_back(p[i]);
    }
    r.pop_back();
    std::reverse(r.begin(), r.end());
    return r;
}