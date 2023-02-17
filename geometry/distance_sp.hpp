#pragma once

#include "geometry/point.hpp"
#include "geometry/segment.hpp"
#include "geometry/projection.hpp"
#include "geometry/is_intersect_sp.hpp"
// distance (segment and point)
Double distance_sp(const Segment &s, const Point &p) {
    Point r = projection(s, p);
    if (is_intersect_sp(s, r)) {
        return std::abs(r - p);
    }
    return std::min(std::abs(s.a - p), std::abs(s.b - p));
}