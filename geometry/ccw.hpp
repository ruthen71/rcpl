#pragma once

#include "geometry/point.hpp"

// counter clockwise
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise
constexpr int CLOCKWISE = -1;         // a-b-c clockwise
constexpr int ONLINE_BACK = 2;        // c-a-b line
constexpr int ONLINE_FRONT = -2;      // a-b-c line
constexpr int ON_SEGMENT = 0;         // a-c-b line
int ccw(const Point &a, Point b, Point c) {
    b = b - a, c = c - a;
    if (sign(cross(b, c)) == 1) return COUNTER_CLOCKWISE;
    if (sign(cross(b, c)) == -1) return CLOCKWISE;
    if (sign(dot(b, c)) == -1) return ONLINE_BACK;
    if (std::norm(b) < std::norm(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
}