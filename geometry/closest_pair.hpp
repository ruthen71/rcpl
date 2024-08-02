#pragma once

#include "point.hpp"

#include <tuple>
#include <limits>
#include <algorithm>
#include <numeric>

// 最近点対 (分割統治法)
// O(n log n)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
// return {index1, index2, distance}
template <class T> std::tuple<int, int, T> closest_pair(const std::vector<Point<T>>& p) {
    const int n = (int)(p.size());

    assert(n >= 2);
    if (n == 2) {
        return {0, 1, abs(p[0] - p[1])};
    }
    // may not be efficient due to indirect references ...
    std::vector<int> ind(n);
    std::iota(ind.begin(), ind.end(), 0);
    std::sort(ind.begin(), ind.end(), [&](int i, int j) { return compare_x(p[i], p[j]); });
    auto dfs = [&](auto f, int l, int r) -> std::tuple<int, int, T> {
        if (r - l <= 1) return {-1, -1, std::numeric_limits<T>::max()};
        const int md = (l + r) / 2;
        T x = p[ind[md]].x;
        // 分割統治法
        auto [i1l, i2l, dl] = f(f, l, md);
        auto [i1r, i2r, dr] = f(f, md, r);
        int i1 = i1r, i2 = i2r;
        T d = dr;
        if (dl < dr) {
            d = dl, i1 = i1l, i2 = i2l;
        }
        std::inplace_merge(ind.begin() + l, ind.begin() + md, ind.begin() + r, [&](int i, int j) { return compare_y(p[i], p[j]); });
        // ind は y でソートされる
        std::vector<int> near_x;  // 直線 x からの距離が d 未満の頂点のインデックス
        for (int i = l; i < r; i++) {
            if (sign(std::abs(p[ind[i]].x - x) - d) >= 0) continue;  // |p[ind[i]].x - x| >= d
            const int sz = (int)(near_x.size());
            // y座標との距離が d 以上になるまで繰り返す
            for (int j = sz - 1; j >= 0; j--) {
                Point cp = p[ind[i]] - p[near_x[j]];
                if (sign(cp.y - d) >= 0) break;  // cp.y >= d
                T cd = abs(cp);
                if (cd < d) {
                    d = cd, i1 = ind[i], i2 = near_x[j];
                }
            }
            near_x.push_back(ind[i]);
        }
        return {i1, i2, d};
    };
    return dfs(dfs, 0, n);
}