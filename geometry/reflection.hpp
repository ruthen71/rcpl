#pragma once

#include "geometry/line.hpp"
#include "geometry/point.hpp"
#include "projection.hpp"

// reflection
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
template <typename T> Point<T> reflection(const Line<T> &l, const Point<T> &p) { return p + (projection(l, p) - p) * T(2); }