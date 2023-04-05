#pragma once

#include "geometry/point.hpp"
#include "geometry/circle.hpp"
// intersection (circle and point)
template <typename T> inline bool is_intersect_cp(const Circle<T> &c, const Point<T> &p) { return equal(norm(p - c.o), c.r * c.r); }