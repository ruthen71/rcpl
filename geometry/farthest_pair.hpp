#pragma once

#include "geometry/monotone_chain.hpp"
#include "geometry/convex_polygon_diameter.hpp"

// farthest pair
// return {index1, index2, distance}
// using monotone chain (convex hull) and convex polygon diameter
// complexity: O(n \log n) (n: the number of points)
template <typename T> std::tuple<int, int, T> farthest_pair(const std::vector<Point<T>> &p) {
    int n = int(p.size());
    assert(n >= 2);
    if (n == 2) {
        return {0, 1, abs(p[0] - p[1])};
    }
    auto q = p;
    auto ch = monotone_chain(q);                   // O(n \log n)
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