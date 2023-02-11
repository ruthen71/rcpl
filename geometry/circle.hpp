#pragma once

#include "geometry/point.hpp"

// circle
struct Circle {
    Point o;
    Double r;

    Circle() = default;

    Circle(Point o, Double r) : o(o), r(r) {}

    friend std::ostream &operator<<(std::ostream &os, const Circle &c) { return os << c.o << ' ' << c.r; }
    friend std::istream &operator>>(std::istream &is, Circle &c) { return is >> c.o >> c.r; }  // format : x y r
};