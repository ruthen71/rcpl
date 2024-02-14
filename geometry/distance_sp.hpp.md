---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_sp.hpp
    title: geometry/is_intersect_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_ss.hpp
    title: geometry/distance_ss.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
    title: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/distance_sp.hpp\"\n\n#line 2 \"geometry/point.hpp\"\
    \n\n// point\ntemplate <typename T> struct Point {\n    static T EPS;\n    static\
    \ constexpr T PI = 3.1415926535'8979323846'2643383279L;\n    static void set_eps(const\
    \ T &e) { EPS = e; }\n    T x, y;\n    Point(const T x = T(0), const T y = T(0))\
    \ : x(x), y(y) {}\n    Point &operator+=(const Point &p) {\n        x += p.x;\n\
    \        y += p.y;\n        return *this;\n    }\n    Point &operator-=(const\
    \ Point &p) {\n        x -= p.x;\n        y -= p.y;\n        return *this;\n \
    \   }\n    Point &operator*=(const Point &p) { return *this = Point(x * p.x -\
    \ y * p.y, x * p.y + y * p.x); }\n    Point &operator*=(const T &k) {\n      \
    \  x *= k;\n        y *= k;\n        return *this;\n    }\n    Point &operator/=(const\
    \ Point &p) { return *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / (p.x\
    \ * p.x + p.y * p.y); }\n    Point &operator/=(const T &k) {\n        x /= k;\n\
    \        y /= k;\n        return *this;\n    }\n\n    Point operator+() const\
    \ { return *this; }\n    Point operator-() const { return Point(-x, -y); }\n\n\
    \    friend Point operator+(const Point &a, const Point &b) { return Point(a)\
    \ += b; }\n    friend Point operator-(const Point &a, const Point &b) { return\
    \ Point(a) -= b; }\n    friend Point operator*(const Point &a, const Point &b)\
    \ { return Point(a) *= b; }\n    friend Point operator*(const Point &p, const\
    \ T &k) { return Point(p) *= k; }\n    friend Point operator/(const Point &a,\
    \ const Point &b) { return Point(a) /= b; }\n    friend Point operator/(const\
    \ Point &p, const T &k) { return Point(p) /= k; }\n    // for std::set, std::map,\
    \ compare_arg, ...\n    friend bool operator<(const Point &a, const Point &b)\
    \ { return a.x == b.x ? a.y < b.y : a.x < b.x; }\n    friend bool operator>(const\
    \ Point &a, const Point &b) { return a.x == b.x ? a.y > b.y : a.x > b.x; }\n \
    \   // I/O\n    friend std::istream &operator>>(std::istream &is, Point &p) {\
    \ return is >> p.x >> p.y; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Point &p) { return os << '(' << p.x << ' ' << p.y << ')'; }\n};\n\
    \n// template\ntemplate <typename T> inline int sign(const T &x) { return x <\
    \ -Point<T>::EPS ? -1 : (x > Point<T>::EPS ? 1 : 0); }\ntemplate <typename T>\
    \ inline bool equal(const T &a, const T &b) { return sign(a - b) == 0; }\ntemplate\
    \ <typename T> inline T radian_to_degree(const T &r) { return r * 180.0 / Point<T>::PI;\
    \ }\ntemplate <typename T> inline T degree_to_radian(const T &d) { return d *\
    \ Point<T>::PI / 180.0; }\n\n// contain enum\nconstexpr int IN = 2;\nconstexpr\
    \ int ON = 1;\nconstexpr int OUT = 0;\n\n// equal (point and point)\ntemplate\
    \ <typename T> inline bool equal(const Point<T> &a, const Point<T> &b) { return\
    \ equal(a.x, b.x) and equal(a.y, b.y); }\n// inner product\ntemplate <typename\
    \ T> inline T dot(const Point<T> &a, const Point<T> &b) { return a.x * b.x + a.y\
    \ * b.y; }\n// outer product\ntemplate <typename T> inline T cross(const Point<T>\
    \ &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }\n// rotate Point p\
    \ counterclockwise by theta radian\ntemplate <typename T> inline Point<T> rotate(const\
    \ Point<T> &p, const T &theta) { return p * Point<T>(std::cos(theta), std::sin(theta));\
    \ }\n// compare (x, y)\ntemplate <typename T> inline bool compare_x(const Point<T>\
    \ &a, const Point<T> &b) { return equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x\
    \ - b.x) < 0; }\n// compare (y, x)\ntemplate <typename T> inline bool compare_y(const\
    \ Point<T> &a, const Point<T> &b) { return equal(a.y, b.y) ? sign(a.x - b.x) <\
    \ 0 : sign(a.y - b.y) < 0; }\n// compare by (arg(p), norm(p)) [0, 360)\ntemplate\
    \ <typename T> inline bool compare_arg(const Point<T> &a, const Point<T> &b) {\n\
    \    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n    assert(!equal(a,\
    \ Point<T>(0, 0)));\n    assert(!equal(b, Point<T>(0, 0)));\n    if ((Point<T>(0,\
    \ 0) < Point<T>(a.y, a.x)) == (Point<T>(0, 0) < Point<T>(b.y, b.x))) {\n     \
    \   return (a.x * b.y == a.y * b.x) ? norm(a) < norm(b) : a.x * b.y > a.y * b.x;\n\
    \    } else {\n        return Point<T>(a.y, a.x) > Point<T>(b.y, b.x);\n    }\n\
    }\n// |p| ^ 2\ntemplate <typename T> inline T norm(const Point<T> &p) { return\
    \ p.x * p.x + p.y * p.y; }\n// |p|\ntemplate <typename T> inline T abs(const Point<T>\
    \ &p) { return std::sqrt(norm(p)); }\n// arg\ntemplate <typename T> inline T arg(const\
    \ Point<T> &p) { return std::atan2(p.y, p.x); }\n// polar\ntemplate <typename\
    \ T> inline Point<T> polar(const T &rho, const T &theta = T(0)) { return rotate(Point<T>(rho,\
    \ 0), theta); }\n// EPS\ntemplate <> double Point<double>::EPS = 1e-9;\ntemplate\
    \ <> long double Point<long double>::EPS = 1e-12;\ntemplate <> long long Point<long\
    \ long>::EPS = 0;\ntemplate <> __int128_t Point<__int128_t>::EPS = 0;\n// change\
    \ EPS\n// using Double = double;\n// using Pt = Point<Double>;\n// Point<Double>::set_eps(new_eps);\n\
    #line 2 \"geometry/segment.hpp\"\n\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"\
    geometry/line.hpp\"\n\n// line\ntemplate <typename T> struct Line {\n    Point<T>\
    \ a, b;\n\n    Line() = default;\n\n    Line(const Point<T> &a, const Point<T>\
    \ &b) : a(a), b(b) {}\n\n    // Ax + By = C\n    Line(const T &A, const T &B,\
    \ const T &C) {\n        assert(equal(A, 0) and equal(B, 0));\n        if (equal(A,\
    \ 0)) {\n            a = Point<T>(0, C / B), b = Point<T>(1, C / B);\n       \
    \ } else if (equal(B, 0)) {\n            a = Point<T>(C / A, 0), b = Point<T>(C\
    \ / A, 1);\n        } else if (equal(C, 0)) {\n            a = Point<T>(0, 0),\
    \ b = Point<T>(1, B / A);\n        } else {\n            a = Point<T>(0, C / B),\
    \ b = Point<T>(C / A, 0);\n        }\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Line &p) { return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 4 \"geometry/segment.hpp\"\
    \n\n// segment\ntemplate <typename T> struct Segment : Line<T> {\n    Segment()\
    \ = default;\n\n    Segment(const Point<T> &a, const Point<T> &b) : Line<T>(a,\
    \ b) {}\n};\n#line 2 \"geometry/projection.hpp\"\n\n#line 5 \"geometry/projection.hpp\"\
    \n\n// projection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    template <typename T> Point<T> projection(const Line<T> &l, const Point<T> &p)\
    \ {\n    T t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);\n    return l.a + t\
    \ * (l.b - l.a);\n}\n#line 2 \"geometry/is_intersect_sp.hpp\"\n\n#line 2 \"geometry/ccw.hpp\"\
    \n\n#line 4 \"geometry/ccw.hpp\"\n\n// counter clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int\
    \ CLOCKWISE = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2; \
    \       // c-a-b line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr\
    \ int ON_SEGMENT = 0;         // a-c-b line\ntemplate <typename T> int ccw(const\
    \ Point<T> &a, Point<T> b, Point<T> c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b,\
    \ c)) == 1) return COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return\
    \ CLOCKWISE;\n    if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (norm(b)\
    \ < norm(c)) return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n#line 5 \"geometry/is_intersect_sp.hpp\"\
    \n\n// intersection (segment and point)\n// ccw(a, b, c) == ON_SEGMENT -> a -\
    \ c - b\ntemplate <typename T> inline bool is_intersect_sp(const Segment<T> &s,\
    \ const Point<T> &p) { return ccw(s.a, s.b, p) == ON_SEGMENT or sign(norm(s.a\
    \ - p)) == 0 or sign(norm(s.b - p)) == 0; }\n#line 7 \"geometry/distance_sp.hpp\"\
    \n\n// distance (segment and point)\ntemplate <typename T> T distance_sp(const\
    \ Segment<T> &s, const Point<T> &p) {\n    Point<T> r = projection(s, p);\n  \
    \  if (is_intersect_sp(s, r)) {\n        return abs(r - p);\n    }\n    return\
    \ std::min(abs(s.a - p), abs(s.b - p));\n}\n"
  code: "#pragma once\n\n#include \"geometry/point.hpp\"\n#include \"geometry/segment.hpp\"\
    \n#include \"geometry/projection.hpp\"\n#include \"geometry/is_intersect_sp.hpp\"\
    \n\n// distance (segment and point)\ntemplate <typename T> T distance_sp(const\
    \ Segment<T> &s, const Point<T> &p) {\n    Point<T> r = projection(s, p);\n  \
    \  if (is_intersect_sp(s, r)) {\n        return abs(r - p);\n    }\n    return\
    \ std::min(abs(s.a - p), abs(s.b - p));\n}"
  dependsOn:
  - geometry/point.hpp
  - geometry/segment.hpp
  - geometry/line.hpp
  - geometry/projection.hpp
  - geometry/is_intersect_sp.hpp
  - geometry/ccw.hpp
  isVerificationFile: false
  path: geometry/distance_sp.hpp
  requiredBy:
  - geometry/all.hpp
  - geometry/distance_ss.hpp
  timestamp: '2023-06-01 23:47:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_2_d.test.cpp
documentation_of: geometry/distance_sp.hpp
layout: document
redirect_from:
- /library/geometry/distance_sp.hpp
- /library/geometry/distance_sp.hpp.html
title: geometry/distance_sp.hpp
---
