#pragma once

#include "geometry/distance_lp.hpp"
#include "geometry/circle.hpp"

// intersection (circle and line)
inline bool is_intersect_cl(const Circle &c, const Line &l) { return sign(c.r - distance_lp(l, c.o)) >= 0; }