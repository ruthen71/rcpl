#pragma once

#include "geometry/geometry_template.hpp"

// point
using Point = std::complex<Double>;
std::istream &operator>>(std::istream &is, Point &p) {
    Double x, y;
    is >> x >> y;
    p = Point(x, y);
    return is;
}
std::ostream &operator<<(std::ostream &os, Point &p) {
    os << std::fixed << std::setprecision(15);
    return os << p.real() << ' ' << p.imag();
}

namespace std {
bool operator<(const Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }
}  // namespace std

// inner product
Double dot(const Point &a, const Point &b) { return a.real() * b.real() + a.imag() * b.imag(); }
// outer product
Double cross(const Point &a, const Point &b) { return a.real() * b.imag() - a.imag() * b.real(); }
// rotate Point p counterclockwise by theta radian
Point rotate(const Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }