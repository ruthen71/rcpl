#pragma once

#include "geometry/geometry_template.hpp"

#include <cmath>

// point
template <class T> struct Point {
    T x, y;

    Point() = default;
    Point(const T x, const T y) : x(x), y(y) {}

    Point& operator+=(const Point& p) {
        x += p.x, y += p.y;
        return *this;
    }
    Point& operator-=(const Point& p) {
        x -= p.x, y -= p.y;
        return *this;
    }
    Point& operator*=(const Point& p) {
        static_assert(is_geometry_floating_point<T>::value == true);
        return *this = Point(x * p.x - y * p.y, x * p.y + y * p.x);
    }
    Point& operator/=(const Point& p) {
        static_assert(is_geometry_floating_point<T>::value == true);
        return *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / (p.x * p.x + p.y * p.y);
    }
    Point& operator*=(const T k) {
        x *= k, y *= k;
        return *this;
    }
    Point& operator/=(const T k) {
        static_assert(is_geometry_floating_point<T>::value == true);
        x /= k, y /= k;
        return *this;
    }

    Point operator+() const { return *this; }
    Point operator-() const { return Point(-x, -y); }

    friend Point operator+(const Point& a, const Point& b) { return Point(a) += b; }
    friend Point operator-(const Point& a, const Point& b) { return Point(a) -= b; }
    friend Point operator*(const Point& a, const Point& b) { return Point(a) *= b; }
    friend Point operator/(const Point& a, const Point& b) { return Point(a) /= b; }
    friend Point operator*(const Point& p, const T k) { return Point(p) *= k; }
    friend Point operator/(const Point& p, const T k) { return Point(p) /= k; }

    // 辞書式順序
    friend bool operator<(const Point& a, const Point& b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
    friend bool operator>(const Point& a, const Point& b) { return a.x == b.x ? a.y > b.y : a.x > b.x; }

    // I/O
    friend std::istream& operator>>(std::istream& is, Point& p) { return is >> p.x >> p.y; }
    friend std::ostream& operator<<(std::ostream& os, const Point& p) { return os << '(' << p.x << ' ' << p.y << ')'; }
};

// point base functions
// 点の一致判定
template <class T> inline bool equal(const Point<T>& a, const Point<T>& b) { return equal(a.x, b.x) and equal(a.y, b.y); }
// 内積
template <class T> inline T dot(const Point<T>& a, const Point<T>& b) { return a.x * b.x + a.y * b.y; }
// 外積
template <class T> inline T cross(const Point<T>& a, const Point<T>& b) { return a.x * b.y - a.y * b.x; }
// rad ラジアンだけ反時計回りに回転
template <class T> inline Point<T> rotate(const Point<T>& p, const T theta) {
    static_assert(is_geometry_floating_point<T>::value == true);
    return p * Point<T>(std::cos(theta), std::sin(theta));
}
// x, y の順で比較
template <class T> inline bool compare_x(const Point<T>& a, const Point<T>& b) { return equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x - b.x) < 0; }
// y, x の順で比較
template <class T> inline bool compare_y(const Point<T>& a, const Point<T>& b) { return equal(a.y, b.y) ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }
// arg(p), norm(p) の順で比較, arg(p) は [0, 2 * PI) で並ぶ
// 整数の範囲で比較可能
template <class T> inline bool compare_arg(const Point<T>& a, const Point<T>& b) {
    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103
    assert(!equal(a, Point<T>(0, 0)));
    assert(!equal(b, Point<T>(0, 0)));
    if ((Point<T>(0, 0) < Point<T>(a.y, a.x)) == (Point<T>(0, 0) < Point<T>(b.y, b.x))) {
        return (a.x * b.y == a.y * b.x) ? norm(a) < norm(b) : a.x * b.y > a.y * b.x;
    } else {
        return Point<T>(a.y, a.x) > Point<T>(b.y, b.x);
    }
}
// 絶対値の 2 乗
template <class T> inline T norm(const Point<T>& p) { return p.x * p.x + p.y * p.y; }
// 絶対値
template <class T> inline T abs(const Point<T>& p) {
    static_assert(is_geometry_floating_point<T>::value == true);
    return std::sqrt(norm(p));
}
// 偏角
template <class T> inline T arg(const Point<T>& p) {
    static_assert(is_geometry_floating_point<T>::value == true);
    return std::atan2(p.y, p.x);
}
// 共役複素数 (x 軸について対象な点)
template <class T> inline Point<T> conj(const Point<T>& p) { return Point(p.x, -p.y); }
// 極座標系 -> 直交座標系 (絶対値が rho で偏角が theta ラジアン)
template <class T> inline Point<T> polar(const T rho, const T theta = T(0)) {
    static_assert(is_geometry_floating_point<T>::value == true);
    assert(sign(rho) >= 0);
    return Point<T>(std::cos(theta), std::sin(theta)) * rho;
}

// ccw の戻り値
enum class Ccw {
    COUNTER_CLOCKWISE = 1,  // a->b->c 反時計回り
    CLOCKWISE = -1,         // a->b->c 時計回り
    ONLINE_BACK = 2,        // c->a->b 直線
    ONLINE_FRONT = -2,      // a->b->c 直線
    ON_SEGMENT = 0          // a->c->b 直線
};
// 点 a, b, c の位置関係
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
template <class T> Ccw ccw(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    Point<T> ab = b - a;
    Point<T> ac = c - a;
    if (sign(cross(ab, ac)) == 1) return Ccw::COUNTER_CLOCKWISE;
    if (sign(cross(ab, ac)) == -1) return Ccw::CLOCKWISE;
    if (sign(dot(ab, ac)) == -1) return Ccw::ONLINE_BACK;
    if (sign(norm(ab) - norm(ac)) == -1) return Ccw::ONLINE_FRONT;
    return Ccw::ON_SEGMENT;
}