#pragma once

#include "geometry/circle.hpp"
#include "geometry/tangent_number_cc.hpp"

// intersection (circle and circle)
// intersect = number of tangent is 1, 2, 3
template <typename T> inline bool is_intersect_cc(const Circle<T> &c1, const Circle<T> &c2) {
    int num = tangent_number_cc(c1, c2);
    return 1 <= num and num <= 3;
}