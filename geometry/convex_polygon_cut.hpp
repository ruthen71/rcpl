#pragma once

#include "geometry/polygon.hpp"
#include "geometry/cross_point_ll.hpp"

// cut convex polygon p by line l
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
// return {left polygon, right polygon}
// whether each point is included is determined by the sign of the outer product of the two vectors to the endpoints of the line
std::pair<Polygon, Polygon> convex_polygon_cut(const Polygon &p, const Line &l) {
    int n = (int)p.size();
    assert(n >= 3);
    Polygon pl, pr;
    for (int i = 0; i < n - 1; i++) {
        int s1 = sign(cross(l.a - p[i], l.b - p[i]));
        int s2 = sign(cross(l.a - p[i + 1], l.b - p[i + 1]));
        if (s1 >= 0) {
            pl.push_back(p[i]);
        }
        if (s1 <= 0) {
            pr.push_back(p[i]);
        }
        if (s1 * s2 < 0) {
            // don't use "<=", use "<" to exclude endpoints
            auto pc = cross_point_ll(Line(p[i], p[i + 1]), l);
            pl.push_back(pc);
            pr.push_back(pc);
        }
    }
    {
        int s1 = sign(cross(l.a - p[n - 1], l.b - p[n - 1]));
        int s2 = sign(cross(l.a - p[0], l.b - p[0]));
        if (s1 >= 0) {
            pl.push_back(p[n - 1]);
        }
        if (s1 <= 0) {
            pr.push_back(p[n - 1]);
        }
        if (s1 * s2 < 0) {
            // don't use "<=", use "<" to exclude endpoints
            auto pc = cross_point_ll(Line(p[n - 1], p[0]), l);
            pl.push_back(pc);
            pr.push_back(pc);
        }
    }
    return {pl, pr};
}