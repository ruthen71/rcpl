#pragma once

#include "geometry/point.hpp"

// circle
template <typename T> struct Circle {
    Point<T> o;
    T r;

    Circle() = default;

    Circle(const Point<T> &o, const T &r) : o(o), r(r) {}

    friend std::istream &operator>>(std::istream &is, Circle &c) { return is >> c.o >> c.r; }  // format : x y r
    friend std::ostream &operator<<(std::ostream &os, const Circle &c) { return os << c.o << ' ' << c.r; }
};