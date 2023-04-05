#pragma once

#include "geometry/segment.hpp"
#include "geometry/is_intersect_ss.hpp"
#include "geometry/distance_sp.hpp"

// distance (segment and segment)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
template <typename T> T distance_ss(const Segment<T> &s1, const Segment<T> &s2) {
    if (is_intersect_ss(s1, s2)) return T(0);
    return std::min({distance_sp(s1, s2.a), distance_sp(s1, s2.b), distance_sp(s2, s1.a), distance_sp(s2, s1.b)});
}