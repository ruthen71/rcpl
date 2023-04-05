#pragma once

#include "geometry/distance_lp.hpp"
#include "geometry/circle.hpp"

// intersection (circle and line)
template <typename T> inline bool is_intersect_cl(const Circle<T> &c, const Line<T> &l) { return sign(c.r * c.r - distance2_lp(l, c.o)) >= 0; }