#pragma once

#include "geometry/line.hpp"

// orthogonal
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
template <typename T> inline bool is_orthogonal(const Line<T> &l1, const Line<T> &l2) { return sign(dot(l1.b - l1.a, l2.b - l2.a)) == 0; }