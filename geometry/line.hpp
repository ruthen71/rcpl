#pragma once

#include "geometry/point.hpp"

// line
template <typename T> struct Line {
    Point<T> a, b;

    Line() = default;

    Line(const Point<T> &a, const Point<T> &b) : a(a), b(b) {}

    // Ax + By = C
    Line(const T &A, const T &B, const T &C) {
        assert(equal(A, 0) and equal(B, 0));
        if (equal(A, 0)) {
            a = Point<T>(0, C / B), b = Point<T>(1, C / B);
        } else if (equal(B, 0)) {
            a = Point<T>(C / A, 0), b = Point<T>(C / A, 1);
        } else if (equal(C, 0)) {
            a = Point<T>(0, 0), b = Point<T>(1, B / A);
        } else {
            a = Point<T>(0, C / B), b = Point<T>(C / A, 0);
        }
    }

    friend std::istream &operator>>(std::istream &is, Line &p) { return is >> p.a >> p.b; }
    friend std::ostream &operator<<(std::ostream &os, const Line &p) { return os << p.a << "->" << p.b; }
};