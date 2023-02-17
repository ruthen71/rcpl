#pragma once
#include "geometry/circle.hpp"
// return the number of tangent
int tangent_number_cc(Circle c1, Circle c2) {
    if (c1.r < c2.r) std::swap(c1, c2);
    Double d = std::abs(c1.o - c2.o);
    if (c1.r + c2.r < d) return 4;
    if (equal(c1.r + c2.r, d)) return 3;
    if (c1.r - c2.r < d) return 2;
    if (equal(c1.r - c2.r, d)) return 1;
    return 0;
}