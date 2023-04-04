#pragma once
#include "geometry/circle.hpp"

// return the number of tangent
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
int tangent_number_cc(Circle c1, Circle c2) {
    if (c1.r < c2.r) std::swap(c1, c2);
    const Double d2 = norm(c1.o - c2.o);
    if (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 1) return 4;  // d > c1.r + c2.r and c1.r + c2.r >= 0 <=> d * d > (c1.r + c2.r) * (c1.r + c2.r)
    if (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 0) return 3;  // d = c1.r + c2.r and c1.r + c2.r >= 0 <=> d * d = (c1.r + c2.r) * (c1.r + c2.r)
    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r)) == 1) return 2;  // d > c1.r - c2.r and c1.r - c2.r >= 0 <=> d * d > (c1.r - c2.r) * (c1.r - c2.r)
    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r)) == 0) return 1;  // d = c1.r - c2.r and c1.r - c2.r >= 0 <=> d * d = (c1.r - c2.r) * (c1.r - c2.r)
    return 0;
}