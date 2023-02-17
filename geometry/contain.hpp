#pragma once

#include "geometry/polygon.hpp"
#include "geometry/is_intersect_sp.hpp"

constexpr int IN = 2;
constexpr int ON = 1;
constexpr int OUT = 0;
// polygon contain point -> 2 (IN)
// polygon cross point -> 1 (ON)
// otherwise -> 0 (OUT)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
int contain(const Polygon &q, const Point &p) {
    bool x = false;
    int n = (int)q.size();
    for (int i = 0; i < n - 1; i++) {
        if (is_intersect_sp(Segment(q[i], q[i + 1]), p)) return ON;
        Point a = q[i] - p, b = q[i + 1] - p;
        if (a.imag() > b.imag()) std::swap(a, b);
        // a.y < b.y
        // check each point's y is 0 at most 1 times
        if (sign(a.imag()) <= 0 and sign(b.imag()) > 0 and sign(cross(a, b)) > 0) x = !x;
    }
    {
        if (is_intersect_sp(Segment(q[n - 1], q[0]), p)) return ON;
        Point a = q[n - 1] - p, b = q[0] - p;
        if (a.imag() > b.imag()) std::swap(a, b);
        if (sign(a.imag()) <= 0 and sign(b.imag()) > 0 and sign(cross(a, b)) > 0) x = !x;
    }
    return (x ? IN : OUT);
}