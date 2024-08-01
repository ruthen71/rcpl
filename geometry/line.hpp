#pragma once

#include "geometry/point.hpp"

// line
template <class T> struct Line {
    Point<T> a, b;

    Line() = default;
    Line(const Point<T>& a, const Point<T>& b) : a(a), b(b) {}

    // Ax + By = C
    Line(const T A, const T B, const T C) {
        static_assert(is_geometry_floating_point<T>::value == true);
        assert(!(equal(A, T(0)) and equal(B, T(0))));
        if (equal(A, T(0))) {
            a = Point<T>(T(0), C / B), b = Point<T>(T(1), C / B);
        } else if (equal(B, T(0))) {
            a = Point<T>(C / A, T(0)), b = Point<T>(C / A, T(1));
        } else if (equal(C, T(0))) {
            a = Point<T>(T(0), T(0)), b = Point<T>(T(1), -A / B);
        } else {
            a = Point<T>(T(0), C / B), b = Point<T>(C / A, T(0));
        }
    }

    friend std::istream& operator>>(std::istream& is, Line& p) { return is >> p.a >> p.b; }
    friend std::ostream& operator<<(std::ostream& os, const Line& p) { return os << p.a << "->" << p.b; }
};

// segment
template <class T> struct Segment : Line<T> {
    Segment() = default;

    Segment(const Point<T>& a, const Point<T>& b) : Line<T>(a, b) {}
};

// 点 p から直線 l に下ろした垂線と直線 l の交点
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
template <class T> Point<T> projection(const Line<T>& l, const Point<T>& p) {
    static_assert(is_geometry_floating_point<T>::value == true);
    T t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    return l.a + (l.b - l.a) * t;
}

// 直線 l に関して点 p と対象な位置にある点
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
template <class T> Point<T> reflection(const Line<T>& l, const Point<T>& p) {
    static_assert(is_geometry_floating_point<T>::value == true);
    return p + (projection(l, p) - p) * T(2);
}

// 直線 l1, l2 の垂直判定
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
template <class T> inline bool is_orthogonal(const Line<T>& l1, const Line<T>& l2) { return sign(dot(l1.b - l1.a, l2.b - l2.a)) == 0; }

// 直線 l1, l2 の平行判定
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
template <class T> inline bool is_parallel(const Line<T>& l1, const Line<T>& l2) { return sign(cross(l1.b - l1.a, l2.b - l2.a)) == 0; }