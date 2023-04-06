#pragma once

// point
template <typename T> struct Point {
    static T EPS;
    static constexpr T PI = std::acos(T(-1));
    static void set_eps(const T &e) { EPS = e; }
    T x, y;
    Point(const T x = T(0), const T y = T(0)) : x(x), y(y) {}
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
    Point &operator*=(const T &k) {
        x *= k;
        y *= k;
        return *this;
    }
    Point &operator/=(const Point &p) { return *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / (p.x * p.x + p.y * p.y); }
    Point &operator/=(const T &k) {
        x /= k;
        y /= k;
        return *this;
    }

    Point operator+() const { return *this; }
    Point operator-() const { return Point(-x, -y); }

    friend Point operator+(const Point &a, const Point &b) { return Point(a) += b; }
    friend Point operator-(const Point &a, const Point &b) { return Point(a) -= b; }
    friend Point operator*(const Point &a, const Point &b) { return Point(a) *= b; }
    friend Point operator*(const Point &p, const T &k) { return Point(p) *= k; }
    friend Point operator/(const Point &a, const Point &b) { return Point(a) /= b; }
    friend Point operator/(const Point &p, const T &k) { return Point(p) /= k; }
    // for std::set, std::map, compare_arg, ...
    friend bool operator<(const Point &a, const Point &b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
    // I/O
    friend std::istream &operator>>(std::istream &is, Point &p) { return is >> p.x >> p.y; }
    friend std::ostream &operator<<(std::ostream &os, const Point &p) { return os << '(' << p.x << ' ' << p.y << ')'; }
};

// template
template <typename T> inline int sign(const T &x) { return x < -Point<T>::EPS ? -1 : (x > Point<T>::EPS ? 1 : 0); }
template <typename T> inline bool equal(const T &a, const T &b) { return sign(a - b) == 0; }
template <typename T> inline T radian_to_degree(const T &r) { return r * 180.0 / Point<T>::PI; }
template <typename T> inline T degree_to_radian(const T &d) { return d * Point<T>::PI / 180.0; }

// contain enum
constexpr int IN = 2;
constexpr int ON = 1;
constexpr int OUT = 0;

// equal (point and point)
template <typename T> inline bool equal(const Point<T> &a, const Point<T> &b) { return equal(a.x, b.x) and equal(a.y, b.y); }
// inner product
template <typename T> inline T dot(const Point<T> &a, const Point<T> &b) { return a.x * b.x + a.y * b.y; }
// outer product
template <typename T> inline T cross(const Point<T> &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }
// rotate Point p counterclockwise by theta radian
template <typename T> inline Point<T> rotate(const Point<T> &p, const T &theta) { return p * Point<T>(std::cos(theta), std::sin(theta)); }
// compare (x, y)
template <typename T> inline bool compare_x(const Point<T> &a, const Point<T> &b) { return equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x - b.x) < 0; }
// compare (y, x)
template <typename T> inline bool compare_y(const Point<T> &a, const Point<T> &b) { return equal(a.y, b.y) ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }
// compare by arg (start from 90.0000000001~)
template <typename T> inline bool compare_arg(const Point<T> &a, const Point<T> &b) {
    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103
    return (Point<T>(0, 0) < a) == (Point<T>(0, 0) < b) ? a.x * b.y > a.y * b.x : a < b;
}
// |p| ^ 2
template <typename T> inline T norm(const Point<T> &p) { return p.x * p.x + p.y * p.y; }
// |p|
template <typename T> inline T abs(const Point<T> &p) { return std::sqrt(norm(p)); }
// arg
template <typename T> inline T arg(const Point<T> &p) { return std::atan2(p.y, p.x); }
// polar
template <typename T> inline Point<T> polar(const T &rho, const T &theta = T(0)) { return rotate(Point<T>(rho, 0), theta); }
// EPS
template <> double Point<double>::EPS = 1e-9;
template <> long double Point<long double>::EPS = 1e-12;
template <> long long Point<long long>::EPS = 0;
template <> __int128_t Point<__int128_t>::EPS = 0;
// change EPS
// using Double = double;
// using Pt = Point<Double>;
// Point<Double>::set_eps(new_eps);