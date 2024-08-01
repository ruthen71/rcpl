#pragma once

#include "geometry/polygon.hpp"
#include "geometry/line.hpp"
#include "geometry/is_intersect.hpp"

enum class Contain { IN, ON, OUT };

// 多角形が点を包含するか判定
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
template <class T> Contain polygon_contain(const Polygon<T>& q, const Point<T>& p) {
    bool x = false;
    const int n = (int)(q.size());
    for (int i = 0; i < n; i++) {
        if (is_intersect(Segment(q[i], q[i + 1 == n ? 0 : i + 1]), p)) return Contain::ON;
        Point a = q[i] - p, b = q[i + 1] - p;
        if (a.y > b.y) std::swap(a, b);
        // a.y < b.y
        // check each point's y is 0 at most 1 times
        if (sign(a.y) <= 0 and sign(b.y) > 0 and sign(cross(a, b)) > 0) x = !x;
    }
    return (x ? Contain::IN : Contain::OUT);
}