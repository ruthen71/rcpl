#pragma once

#include "geometry/point.hpp"

// line
struct Line {
    Point a, b;

    Line() = default;

    Line(Point a, Point b) : a(a), b(b) {}

    // Ax + By = C
    Line(Double A, Double B, Double C) {
        assert(equal(A, 0) and equal(B, 0));
        if (equal(A, 0)) {
            a = Point(0, C / B), b = Point(1, C / B);
        } else if (equal(B, 0)) {
            a = Point(C / A, 0), b = Point(C / A, 1);
        } else if (equal(C, 0)) {
            a = Point(0, 0), b = Point(1, B / A);
        } else {
            a = Point(0, C / B), b = Point(C / A, 0);
        }
    }

    friend std::istream &operator>>(std::istream &is, Line &p) { return is >> p.a >> p.b; }
    friend std::ostream &operator<<(std::ostream &os, const Line &p) { return os << p.a << "->" << p.b; }
};