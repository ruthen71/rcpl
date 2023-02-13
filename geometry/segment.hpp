#pragma once

#include "geometry/line.hpp"

// segment
struct Segment : Line {
    Segment() = default;

    Segment(Point a, Point b) : Line(a, b) {}
};