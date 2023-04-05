#pragma once

#include "geometry/line.hpp"

// segment
template <typename T> struct Segment : Line<T> {
    Segment() = default;

    Segment(const Point<T> &a, const Point<T> &b) : Line<T>(a, b) {}
};