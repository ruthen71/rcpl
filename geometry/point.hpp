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
std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << std::fixed << std::setprecision(15);
    return os << p.real() << ' ' << p.imag();
}

namespace std {
bool operator<(const Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }
}  // namespace std

Point operator*(const Point &p, const Double &k) { return Point(p.real() * k, p.imag() * k); }
Point operator/(const Point &p, const Double &k) { return Point(p.real() / k, p.imag() / k); }
// equal (point and point)
inline bool equal(const Point &a, const Point &b) { return equal(a.real(), b.real()) and equal(a.imag(), b.imag()); }
// inner product
inline Double dot(const Point &a, const Point &b) { return a.real() * b.real() + a.imag() * b.imag(); }
// outer product
inline Double cross(const Point &a, const Point &b) { return a.real() * b.imag() - a.imag() * b.real(); }
// rotate Point p counterclockwise by theta radian
inline Point rotate(const Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }
// compare (x, y)
inline bool compare_x(const Point &a, const Point &b) { return equal(a.real(), b.real()) ? sign(a.imag() - b.imag()) < 0 : sign(a.real() - b.real()) < 0; }
// compare (y, x)
inline bool compare_y(const Point &a, const Point &b) { return equal(a.imag(), b.imag()) ? sign(a.real() - b.real()) < 0 : sign(a.imag() - b.imag()) < 0; }