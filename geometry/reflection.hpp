#pragma once

#include "geometry/line.hpp"
#include "geometry/point.hpp"
#include "projection.hpp"

// reflection
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
Point reflection(const Line &l, const Point &p) { return p + (projection(l, p) - p) * Double(2.0); }