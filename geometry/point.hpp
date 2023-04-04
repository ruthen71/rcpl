#pragma once

#include "geometry/geometry_template.hpp"

// point
struct Point {
    Double x, y;
    Point(const Double x = Double(0), const Double y = Double(0)) : x(x), y(y) {}
    Point &operator+=(const Point &p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point &operator*=(const Point &p) { return *this = Point(x * p.x - y * p.y, x * p.y + y * p.x); }
    Point &operator*=(const Double &k) {
        x *= k;
        y *= k;
        return *this;
    }
    Point &operator/=(const Point &p) { return *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / (p.x * p.x + p.y * p.y); }
    Point &operator/=(const Double &k) {
        x /= k;
        y /= k;
        return *this;
    }

    Point operator+() const { return *this; }
    Point operator-() const { return Point(-x, -y); }

    friend Point operator+(const Point &a, const Point &b) { return Point(a) += b; }
    friend Point operator-(const Point &a, const Point &b) { return Point(a) -= b; }
    friend Point operator*(const Point &a, const Point &b) { return Point(a) *= b; }
    friend Point operator*(const Point &p, const Double &k) { return Point(p) *= k; }
    friend Point operator/(const Point &a, const Point &b) { return Point(a) /= b; }
    friend Point operator/(const Point &p, const Double &k) { return Point(p) /= k; }
    // for std::set, std::map, compare_arg, ...
    friend bool operator<(const Point &a, const Point &b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
};

// using Point = std::complex<Double>;
std::istream &operator>>(std::istream &is, Point &p) { return is >> p.x >> p.y; }
std::ostream &operator<<(std::ostream &os, const Point &p) { return os << std::fixed << std::setprecision(15) << p.x << ' ' << p.y; }

// equal (point and point)
inline bool equal(const Point &a, const Point &b) { return equal(a.x, b.x) and equal(a.y, b.y); }
// inner product
inline Double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
// outer product
inline Double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
// rotate Point p counterclockwise by theta radian
inline Point rotate(const Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }
// compare (x, y)
inline bool compare_x(const Point &a, const Point &b) { return equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x - b.x) < 0; }
// compare (y, x)
inline bool compare_y(const Point &a, const Point &b) { return equal(a.y, b.y) ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }
// compare by arg (start from 90.0000000001~)
inline bool compare_arg(const Point &a, const Point &b) {
    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103
    return (Point(0, 0) < a) == (Point(0, 0) < b) ? a.x * b.y > a.y * b.x : a < b;
}
// |p| ^ 2
inline Double norm(const Point &p) { return p.x * p.x + p.y * p.y; }
// |p|
inline Double abs(const Point &p) { return sqrt(norm(p)); }
// arg
inline Double arg(const Point &p) { return std::atan2(p.y, p.x); }
// polar
inline Point polar(const Double &rho, const Double &theta = Double(0)) { return rotate(Point(rho, 0), theta); }