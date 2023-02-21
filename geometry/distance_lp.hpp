#pragma once

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/projection.hpp"

// distance (line and point)
Double distance_lp(const Line &l, const Point &p) { return std::abs(p - projection(l, p)); }