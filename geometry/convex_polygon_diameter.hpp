#pragma once

#include "geometry/polygon.hpp"
#include "geometry/polygon_is_convex.hpp"

// convex polygon diameter
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
// return {index1, index2, diameter}
// using the method of rotating calipers (https://en.wikipedia.org/wiki/Rotating_calipers)
// complexity: O(n)
std::tuple<int, int, Double> convex_polygon_diameter(const Polygon &p) {
    assert(polygon_is_convex(p));
    int n = (int)p.size();
    assert(n >= 2);
    if (n == 2) {
        return {0, 1, std::abs(p[0] - p[1])};
    }
    auto [it_min, it_max] = std::minmax_element(p.begin(), p.end(), compare_x);
    int idx_min = it_min - p.begin();
    int idx_max = it_max - p.begin();

    Double maxdis = std::norm(p[idx_max] - p[idx_min]);
    int maxi = idx_min, i = idx_min, maxj = idx_max, j = idx_max;
    do {
        int ni = (i + 1 == n ? 0 : i + 1), nj = (j + 1 == n ? 0 : j + 1);
        if (sign(cross(p[ni] - p[i], p[nj] - p[j])) < 0) {
            i = ni;
        } else {
            j = nj;
        }
        if (std::norm(p[i] - p[j]) > maxdis) {
            maxdis = std::norm(p[i] - p[j]);
            maxi = i;
            maxj = j;
        }
    } while (i != idx_min || j != idx_max);
    return {maxi, maxj, std::abs(p[maxi] - p[maxj])};
}