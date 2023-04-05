#pragma once

#include "geometry/point.hpp"
#include "geometry/segment.hpp"
#include "geometry/projection.hpp"
#include "geometry/is_intersect_sp.hpp"

// distance (segment and point)
template <typename T> T distance_sp(const Segment<T> &s, const Point<T> &p) {
    Point<T> r = projection(s, p);
    if (is_intersect_sp(s, r)) {
        return abs(r - p);
    }
    return std::min(abs(s.a - p), abs(s.b - p));
}