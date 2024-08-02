#pragma once

#include "geometry/convex_hull_monotone_chain.hpp"
#include "geometry/convex_polygon_diameter.hpp"

#include <tuple>

// 最遠点対
// return {index1, index2, distance}
// 凸包を求めてから凸多角形の直径を求めている
// O(n log n)
template <class T> std::tuple<int, int, T> farthest_pair(const std::vector<Point<T>>& p) {
    const int n = (int)(p.size());
    assert(n >= 2);
    if (n == 2) {
        return {0, 1, abs(p[0] - p[1])};
    }
    auto q = p;
    auto ch = convex_hull_monotone_chain(q);       // O(n log n)
    auto [i, j, d] = convex_polygon_diameter(ch);  // O(|ch|)
    int resi, resj;
    for (int k = 0; k < n; k++) {
        if (p[k] == ch[i]) {
            resi = k;
        }
        if (p[k] == ch[j]) {
            resj = k;
        }
    }
    return {resi, resj, d};
}