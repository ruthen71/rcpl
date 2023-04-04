#pragma once

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/projection.hpp"

// distance (line and point) (Double = double or long)
Double distance_lp(const Line &l, const Point &p) { return abs(p - projection(l, p)); }
Double distance2_lp(const Line &l, const Point &p) { return norm(p - projection(l, p)); }