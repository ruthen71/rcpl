#pragma once

#include "geometry/point.hpp"
#include "geometry/circle.hpp"
// intersection (circle and point)
inline bool is_intersect_cp(const Circle &c, const Point &p) { return equal(norm(p - c.o), c.r * c.r); }