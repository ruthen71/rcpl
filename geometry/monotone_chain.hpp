#pragma once

#include "geometry/polygon.hpp"
#include "geometry/ccw.hpp"

// convex hull (Andrew's monotone chain convex hull algorithm)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
// sort (x, y) by lexicographical order, use stack, calculate upper convex hull and lower convex hull
// counter clockwise order
// assume the return value of ccw is not ONLINE_BACK or ONLINE_FRONT (lexicographical order)
// strict is true : points on the edges of the convex hull are not included (the number of points is minimized)
// complexity: O(n \log n) (n: the number of points)
Polygon monotone_chain(Polygon &p, bool strict = true) {
    int n = (int)p.size();
    if (n <= 2) return p;
    std::sort(p.begin(), p.end(), compare_x);
    Polygon r;
    r.reserve(n * 2);
    if (strict) {
        for (int i = 0; i < n; i++) {
            while (r.size() >= 2 and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) != CLOCKWISE) {
                r.pop_back();
            }
            r.push_back(p[i]);
        }
        int t = r.size() + 1;
        for (int i = n - 2; i >= 0; i--) {
            while (r.size() >= t and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) != CLOCKWISE) {
                r.pop_back();
            }
            r.push_back(p[i]);
        }
    } else {
        for (int i = 0; i < n; i++) {
            while (r.size() >= 2 and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) == COUNTER_CLOCKWISE) {
                r.pop_back();
            }
            r.push_back(p[i]);
        }
        int t = r.size() + 1;
        for (int i = n - 2; i >= 0; i--) {
            while (r.size() >= t and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) == COUNTER_CLOCKWISE) {
                r.pop_back();
            }
            r.push_back(p[i]);
        }
    }
    r.pop_back();
    std::reverse(r.begin(), r.end());
    return r;
}