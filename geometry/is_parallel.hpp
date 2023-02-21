#pragma once

#include "geometry/line.hpp"

// parallel
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
inline bool is_parallel(const Line &l1, const Line &l2) { return sign(cross(l1.b - l1.a, l2.b - l2.a)) == 0; }