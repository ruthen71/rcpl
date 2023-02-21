#pragma once

#include "geometry/segment.hpp"
#include "geometry/ccw.hpp"

// intersection (segment and point)
// ccw(a, b, c) == ON_SEGMENT -> a - c - b
inline bool is_intersect_sp(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == ON_SEGMENT or sign(std::abs(s.a - p)) == 0 or sign(std::abs(s.b - p)) == 0; }