#pragma once

#include "geometry/point.hpp"

// closest pair
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
// return {index1, index2, distance}
// using divide-and-conquer algorithm
// complexity: O(n \log n) (n: the number of points)
template <typename T> std::tuple<int, int, T> closest_pair(const std::vector<Point<T>> &p) {
    int n = int(p.size());
    assert(n >= 2);
    if (n == 2) {
        return {0, 1, abs(p[0] - p[1])};
    }
    // may not be efficient due to indirect references ...
    std::vector<int> ind(n);
    std::iota(ind.begin(), ind.end(), 0);
    std::sort(ind.begin(), ind.end(), [&](int i, int j) { return compare_x(p[i], p[j]); });
    auto divide_and_conquer = [&](auto f, int l, int r) -> std::tuple<int, int, T> {
        if (r - l <= 1) return {-1, -1, std::numeric_limits<T>::max()};
        int md = (l + r) / 2;
        T x = p[ind[md]].x;
        // divide and conquer
        auto [i1l, i2l, dl] = f(f, l, md);
        auto [i1r, i2r, dr] = f(f, md, r);
        int i1, i2;
        T d;
        if (dl < dr) {
            d = dl, i1 = i1l, i2 = i2l;
        } else {
            d = dr, i1 = i1r, i2 = i2r;
        }
        std::inplace_merge(ind.begin() + l, ind.begin() + md, ind.begin() + r, [&](int i, int j) { return compare_y(p[i], p[j]); });
        // ind are sorted by y
        std::vector<int> near_x;  // index of vertices whose distance from the line x is less than d
        for (int i = l; i < r; i++) {
            if (sign(std::abs(p[ind[i]].x - x) - d) >= 0) continue;  // std::abs(p[ind[i]].x - x) >= d
            int sz = int(near_x.size());
            // iterate from the end until the distance in y-coordinates is greater than or equal to d
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
    return divide_and_conquer(divide_and_conquer, 0, n);
}