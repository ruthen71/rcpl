#pragma once

#include "geometry/point.hpp"

// circle
template <class T> struct Circle {
    Point<T> o;
    T r;

    Circle() = default;
    Circle(const Point<T>& o, const T r) : o(o), r(r) {}

    friend std::istream& operator>>(std::istream& is, Circle& c) { return is >> c.o >> c.r; }
    friend std::ostream& operator<<(std::ostream& os, const Circle& c) { return os << c.o << ", " << c.r; }
};

// 共通接線の本数
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
template <class T> int tangent_number(Circle<T> c1, Circle<T> c2) {
    if (c1.r < c2.r) std::swap(c1, c2);
    const T d2 = norm(c1.o - c2.o);
    if (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 1) return 4;  // d > c1.r + c2.r and c1.r + c2.r >= 0 <=> d ^ 2 > (c1.r + c2.r) ^ 2
    if (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 0) return 3;  // d = c1.r + c2.r and c1.r + c2.r >= 0 <=> d ^ 2 = (c1.r + c2.r) ^ 2
    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r)) == 1) return 2;  // d > c1.r - c2.r and c1.r - c2.r >= 0 <=> d ^ 2 > (c1.r - c2.r) ^ 2
    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r)) == 0) return 1;  // d = c1.r - c2.r and c1.r - c2.r >= 0 <=> d ^ 2 = (c1.r - c2.r) ^ 2
    return 0;
}