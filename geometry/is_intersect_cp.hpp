#pragma once

#include "geometry/point.hpp"
#include "geometry/circle.hpp"
// intersection (circle and point)
bool is_intersect_cp(const Circle &c, const Point &p) { return equal(std::abs(p - c.o), c.r); }