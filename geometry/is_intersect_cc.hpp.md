---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_point_cp.hpp
    title: geometry/tangent_point_cp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_e.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_f.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/is_intersect_cc.hpp\"\n\n#line 2 \"geometry/circle.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n// point\ntemplate <typename T> struct Point\
    \ {\n    static T EPS;\n    static constexpr T PI = std::acos(T(-1));\n    static\
    \ void set_eps(const T &e) { EPS = e; }\n    T x, y;\n    Point(const T x = T(0),\
    \ const T y = T(0)) : x(x), y(y) {}\n    Point &operator+=(const Point &p) {\n\
    \        x += p.x;\n        y += p.y;\n        return *this;\n    }\n    Point\
    \ &operator-=(const Point &p) {\n        x -= p.x;\n        y -= p.y;\n      \
    \  return *this;\n    }\n    Point &operator*=(const Point &p) { return *this\
    \ = Point(x * p.x - y * p.y, x * p.y + y * p.x); }\n    Point &operator*=(const\
    \ T &k) {\n        x *= k;\n        y *= k;\n        return *this;\n    }\n  \
    \  Point &operator/=(const Point &p) { return *this = Point(x * p.x + y * p.y,\
    \ -x * p.y + y * p.x) / (p.x * p.x + p.y * p.y); }\n    Point &operator/=(const\
    \ T &k) {\n        x /= k;\n        y /= k;\n        return *this;\n    }\n\n\
    \    Point operator+() const { return *this; }\n    Point operator-() const {\
    \ return Point(-x, -y); }\n\n    friend Point operator+(const Point &a, const\
    \ Point &b) { return Point(a) += b; }\n    friend Point operator-(const Point\
    \ &a, const Point &b) { return Point(a) -= b; }\n    friend Point operator*(const\
    \ Point &a, const Point &b) { return Point(a) *= b; }\n    friend Point operator*(const\
    \ Point &p, const T &k) { return Point(p) *= k; }\n    friend Point operator/(const\
    \ Point &a, const Point &b) { return Point(a) /= b; }\n    friend Point operator/(const\
    \ Point &p, const T &k) { return Point(p) /= k; }\n    // for std::set, std::map,\
    \ compare_arg, ...\n    friend bool operator<(const Point &a, const Point &b)\
    \ { return a.x == b.x ? a.y < b.y : a.x < b.x; }\n    // I/O\n    friend std::istream\
    \ &operator>>(std::istream &is, Point &p) { return is >> p.x >> p.y; }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Point &p) { return os << '('\
    \ << p.x << ' ' << p.y << ')'; }\n};\n\n// template\ntemplate <typename T> inline\
    \ int sign(const T &x) { return x < -Point<T>::EPS ? -1 : (x > Point<T>::EPS ?\
    \ 1 : 0); }\ntemplate <typename T> inline bool equal(const T &a, const T &b) {\
    \ return sign(a - b) == 0; }\ntemplate <typename T> inline T radian_to_degree(const\
    \ T &r) { return r * 180.0 / Point<T>::PI; }\ntemplate <typename T> inline T degree_to_radian(const\
    \ T &d) { return d * Point<T>::PI / 180.0; }\n\n// contain enum\nconstexpr int\
    \ IN = 2;\nconstexpr int ON = 1;\nconstexpr int OUT = 0;\n\n// equal (point and\
    \ point)\ntemplate <typename T> inline bool equal(const Point<T> &a, const Point<T>\
    \ &b) { return equal(a.x, b.x) and equal(a.y, b.y); }\n// inner product\ntemplate\
    \ <typename T> inline T dot(const Point<T> &a, const Point<T> &b) { return a.x\
    \ * b.x + a.y * b.y; }\n// outer product\ntemplate <typename T> inline T cross(const\
    \ Point<T> &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }\n// rotate\
    \ Point p counterclockwise by theta radian\ntemplate <typename T> inline Point<T>\
    \ rotate(const Point<T> &p, const T &theta) { return p * Point<T>(std::cos(theta),\
    \ std::sin(theta)); }\n// compare (x, y)\ntemplate <typename T> inline bool compare_x(const\
    \ Point<T> &a, const Point<T> &b) { return equal(a.x, b.x) ? sign(a.y - b.y) <\
    \ 0 : sign(a.x - b.x) < 0; }\n// compare (y, x)\ntemplate <typename T> inline\
    \ bool compare_y(const Point<T> &a, const Point<T> &b) { return equal(a.y, b.y)\
    \ ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }\n// compare by arg (start from\
    \ 90.0000000001~)\ntemplate <typename T> inline bool compare_arg(const Point<T>\
    \ &a, const Point<T> &b) {\n    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n\
    \    return (Point<T>(0, 0) < a) == (Point<T>(0, 0) < b) ? a.x * b.y > a.y * b.x\
    \ : a < b;\n}\n// |p| ^ 2\ntemplate <typename T> inline T norm(const Point<T>\
    \ &p) { return p.x * p.x + p.y * p.y; }\n// |p|\ntemplate <typename T> inline\
    \ T abs(const Point<T> &p) { return std::sqrt(norm(p)); }\n// arg\ntemplate <typename\
    \ T> inline T arg(const Point<T> &p) { return std::atan2(p.y, p.x); }\n// polar\n\
    template <typename T> inline Point<T> polar(const T &rho, const T &theta = T(0))\
    \ { return rotate(Point<T>(rho, 0), theta); }\n// EPS\ntemplate <> double Point<double>::EPS\
    \ = 1e-9;\ntemplate <> long double Point<long double>::EPS = 1e-12;\ntemplate\
    \ <> long long Point<long long>::EPS = 0;\ntemplate <> __int128_t Point<__int128_t>::EPS\
    \ = 0;\n// change EPS\n// using Double = double;\n// using Pt = Point<Double>;\n\
    // Point<Double>::set_eps(new_eps);\n#line 4 \"geometry/circle.hpp\"\n\n// circle\n\
    template <typename T> struct Circle {\n    Point<T> o;\n    T r;\n\n    Circle()\
    \ = default;\n\n    Circle(const Point<T> &o, const T &r) : o(o), r(r) {}\n\n\
    \    friend std::istream &operator>>(std::istream &is, Circle &c) { return is\
    \ >> c.o >> c.r; }  // format : x y r\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n};\n#line 3 \"geometry/tangent_number_cc.hpp\"\
    \n\n// return the number of tangent\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\n\
    template <typename T> int tangent_number_cc(Circle<T> c1, Circle<T> c2) {\n  \
    \  if (c1.r < c2.r) std::swap(c1, c2);\n    const T d2 = norm(c1.o - c2.o);\n\
    \    if (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 1) return 4;  // d > c1.r\
    \ + c2.r and c1.r + c2.r >= 0 <=> d * d > (c1.r + c2.r) * (c1.r + c2.r)\n    if\
    \ (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 0) return 3;  // d = c1.r + c2.r\
    \ and c1.r + c2.r >= 0 <=> d * d = (c1.r + c2.r) * (c1.r + c2.r)\n    if (sign(d2\
    \ - (c1.r - c2.r) * (c1.r - c2.r)) == 1) return 2;  // d > c1.r - c2.r and c1.r\
    \ - c2.r >= 0 <=> d * d > (c1.r - c2.r) * (c1.r - c2.r)\n    if (sign(d2 - (c1.r\
    \ - c2.r) * (c1.r - c2.r)) == 0) return 1;  // d = c1.r - c2.r and c1.r - c2.r\
    \ >= 0 <=> d * d = (c1.r - c2.r) * (c1.r - c2.r)\n    return 0;\n}\n#line 5 \"\
    geometry/is_intersect_cc.hpp\"\n\n// intersection (circle and circle)\n// intersect\
    \ = number of tangent is 1, 2, 3\ntemplate <typename T> inline bool is_intersect_cc(const\
    \ Circle<T> &c1, const Circle<T> &c2) {\n    int num = tangent_number_cc(c1, c2);\n\
    \    return 1 <= num and num <= 3;\n}\n"
  code: "#pragma once\n\n#include \"geometry/circle.hpp\"\n#include \"geometry/tangent_number_cc.hpp\"\
    \n\n// intersection (circle and circle)\n// intersect = number of tangent is 1,\
    \ 2, 3\ntemplate <typename T> inline bool is_intersect_cc(const Circle<T> &c1,\
    \ const Circle<T> &c2) {\n    int num = tangent_number_cc(c1, c2);\n    return\
    \ 1 <= num and num <= 3;\n}"
  dependsOn:
  - geometry/circle.hpp
  - geometry/point.hpp
  - geometry/tangent_number_cc.hpp
  isVerificationFile: false
  path: geometry/is_intersect_cc.hpp
  requiredBy:
  - geometry/tangent_point_cp.hpp
  - geometry/all.hpp
  - geometry/cross_point_cc.hpp
  timestamp: '2023-04-05 19:46:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_7_e.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_f.test.cpp
documentation_of: geometry/is_intersect_cc.hpp
layout: document
redirect_from:
- /library/geometry/is_intersect_cc.hpp
- /library/geometry/is_intersect_cc.hpp.html
title: geometry/is_intersect_cc.hpp
---
