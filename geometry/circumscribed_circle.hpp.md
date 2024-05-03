---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_ll.hpp
    title: geometry/cross_point_ll.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C
    - https://drken1215.hatenablog.com/entry/2020/10/16/074400
  bundledCode: "#line 2 \"geometry/circumscribed_circle.hpp\"\n\n#line 2 \"geometry/cross_point_ll.hpp\"\
    \n\n#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n// point\n\
    template <typename T> struct Point {\n    static T EPS;\n    static constexpr\
    \ T PI = 3.1415926535'8979323846'2643383279L;\n    static void set_eps(const T\
    \ &e) { EPS = e; }\n    T x, y;\n    Point(const T x = T(0), const T y = T(0))\
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
    #line 4 \"geometry/line.hpp\"\n\n// line\ntemplate <typename T> struct Line {\n\
    \    Point<T> a, b;\n\n    Line() = default;\n\n    Line(const Point<T> &a, const\
    \ Point<T> &b) : a(a), b(b) {}\n\n    // Ax + By = C\n    Line(const T &A, const\
    \ T &B, const T &C) {\n        assert(!(equal(A, T(0)) and equal(B, T(0))));\n\
    \        if (equal(A, T(0))) {\n            a = Point<T>(T(0), C / B), b = Point<T>(T(1),\
    \ C / B);\n        } else if (equal(B, T(0))) {\n            a = Point<T>(C /\
    \ A, T(0)), b = Point<T>(C / A, T(1));\n        } else if (equal(C, T(0))) {\n\
    \            a = Point<T>(T(0), T(0)), b = Point<T>(T(1), B / A);\n        } else\
    \ {\n            a = Point<T>(T(0), C / B), b = Point<T>(C / A, T(0));\n     \
    \   }\n    }\n\n    friend std::istream &operator>>(std::istream &is, Line &p)\
    \ { return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 4 \"geometry/cross_point_ll.hpp\"\
    \n\n// cross point (line and line)\ntemplate <typename T> Point<T> cross_point_ll(const\
    \ Line<T> &l1, const Line<T> &l2) {\n    Point<T> base = l1.b - l1.a;\n    T d12\
    \ = cross(base, l2.b - l2.a);\n    T d1 = cross(base, l1.b - l2.a);\n    if (sign(d12)\
    \ == 0) {\n        // parallel\n        if (sign(d1) == 0) {\n            // cross\n\
    \            return l2.a;\n        } else {\n            // not cross\n      \
    \      assert(false);\n        }\n    }\n    return l2.a + (l2.b - l2.a) * (d1\
    \ / d12);\n}\n#line 2 \"geometry/circle.hpp\"\n\n#line 4 \"geometry/circle.hpp\"\
    \n\n// circle\ntemplate <typename T> struct Circle {\n    Point<T> o;\n    T r;\n\
    \n    Circle() = default;\n\n    Circle(const Point<T> &o, const T &r) : o(o),\
    \ r(r) {}\n\n    friend std::istream &operator>>(std::istream &is, Circle &c)\
    \ { return is >> c.o >> c.r; }  // format : x y r\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n};\n#line 5 \"geometry/circumscribed_circle.hpp\"\
    \n\n// circumscribed circle of a triangle\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C\n\
    // https://drken1215.hatenablog.com/entry/2020/10/16/074400\ntemplate <typename\
    \ T> Circle<T> circumscribed_circle(const Point<T> &a, const Point<T> &b, const\
    \ Point<T> &c) {\n    Line l1((a + b) / 2, (a + b) / 2 + rotate(b - a, Point<T>::PI\
    \ / 2)), l2((b + c) / 2, (b + c) / 2 + rotate(c - b, Point<T>::PI / 2));\n   \
    \ auto o = cross_point_ll(l1, l2);\n    auto r = abs(o - a);\n    return Circle(o,\
    \ r);\n}\n"
  code: "#pragma once\n\n#include \"geometry/cross_point_ll.hpp\"\n#include \"geometry/circle.hpp\"\
    \n\n// circumscribed circle of a triangle\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C\n\
    // https://drken1215.hatenablog.com/entry/2020/10/16/074400\ntemplate <typename\
    \ T> Circle<T> circumscribed_circle(const Point<T> &a, const Point<T> &b, const\
    \ Point<T> &c) {\n    Line l1((a + b) / 2, (a + b) / 2 + rotate(b - a, Point<T>::PI\
    \ / 2)), l2((b + c) / 2, (b + c) / 2 + rotate(c - b, Point<T>::PI / 2));\n   \
    \ auto o = cross_point_ll(l1, l2);\n    auto r = abs(o - a);\n    return Circle(o,\
    \ r);\n}"
  dependsOn:
  - geometry/cross_point_ll.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/circle.hpp
  isVerificationFile: false
  path: geometry/circumscribed_circle.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2024-03-24 14:28:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_7_c.test.cpp
documentation_of: geometry/circumscribed_circle.hpp
layout: document
redirect_from:
- /library/geometry/circumscribed_circle.hpp
- /library/geometry/circumscribed_circle.hpp.html
title: geometry/circumscribed_circle.hpp
---