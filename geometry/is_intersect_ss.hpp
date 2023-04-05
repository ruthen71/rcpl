#pragma once

#include "geometry/segment.hpp"
#include "geometry/ccw.hpp"

// intersection (segment and segment)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
template <typename T> inline bool is_intersect_ss(const Segment<T> &s1, const Segment<T> &s2) { return (ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 and ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0); }