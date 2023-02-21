#pragma once

#include "geometry/line.hpp"

// segment
struct Segment : Line {
    Segment() = default;

    Segment(const Point &a, const Point &b) : Line(a, b) {}
};