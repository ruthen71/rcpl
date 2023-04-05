#pragma once

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/projection.hpp"

// distance (line and point) (Double = double or long)
template <typename T> T distance_lp(const Line<T> &l, const Point<T> &p) { return abs(p - projection(l, p)); }
template <typename T> T distance2_lp(const Line<T> &l, const Point<T> &p) { return norm(p - projection(l, p)); }