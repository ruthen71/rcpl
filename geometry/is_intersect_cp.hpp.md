---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/is_intersect_cp.hpp\"\n\n#line 2 \"geometry/point.hpp\"\
    \n\n#line 2 \"geometry/geometry_template.hpp\"\n\n// template\nusing Double =\
    \ double;    // double or long double\nconst Double EPS = 1e-8;  // change the\
    \ value depending on the problem\nconst Double PI = std::acos(Double(-1));\ninline\
    \ int sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }\n\
    inline bool equal(const Double &a, const Double &b) { return sign(a - b) == 0;\
    \ }\ninline Double radian_to_degree(const Double &r) { return r * 180.0 / PI;\
    \ }\ninline Double degree_to_radian(const Double &d) { return d * PI / 180.0;\
    \ }\n#line 4 \"geometry/point.hpp\"\n\n// point\nusing Point = std::complex<Double>;\n\
    std::istream &operator>>(std::istream &is, Point &p) {\n    Double x, y;\n   \
    \ is >> x >> y;\n    p = Point(x, y);\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
    \ &os, const Point &p) {\n    os << std::fixed << std::setprecision(15);\n   \
    \ return os << p.real() << ' ' << p.imag();\n}\n\n// for std::set, std::map, ...\n\
    namespace std {\ninline bool operator<(const Point &a, const Point &b) { return\
    \ a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }\n}  // namespace\
    \ std\n\ninline Point operator*(const Point &p, const Double &k) { return Point(p.real()\
    \ * k, p.imag() * k); }\ninline Point operator/(const Point &p, const Double &k)\
    \ { return Point(p.real() / k, p.imag() / k); }\n// equal (point and point)\n\
    inline bool equal(const Point &a, const Point &b) { return equal(a.real(), b.real())\
    \ and equal(a.imag(), b.imag()); }\n// inner product\ninline Double dot(const\
    \ Point &a, const Point &b) { return a.real() * b.real() + a.imag() * b.imag();\
    \ }\n// outer product\ninline Double cross(const Point &a, const Point &b) { return\
    \ a.real() * b.imag() - a.imag() * b.real(); }\n// rotate Point p counterclockwise\
    \ by theta radian\ninline Point rotate(const Point &p, const Double &theta) {\
    \ return p * Point(cos(theta), sin(theta)); }\n// compare (x, y)\ninline bool\
    \ compare_x(const Point &a, const Point &b) { return equal(a.real(), b.real())\
    \ ? sign(a.imag() - b.imag()) < 0 : sign(a.real() - b.real()) < 0; }\n// compare\
    \ (y, x)\ninline bool compare_y(const Point &a, const Point &b) { return equal(a.imag(),\
    \ b.imag()) ? sign(a.real() - b.real()) < 0 : sign(a.imag() - b.imag()) < 0; }\n\
    #line 2 \"geometry/circle.hpp\"\n\n#line 4 \"geometry/circle.hpp\"\n\n// circle\n\
    struct Circle {\n    Point o;\n    Double r;\n\n    Circle() = default;\n\n  \
    \  Circle(const Point &o, const Double &r) : o(o), r(r) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Circle &c) { return os << c.o << ' ' <<\
    \ c.r; }\n    friend std::istream &operator>>(std::istream &is, Circle &c) { return\
    \ is >> c.o >> c.r; }  // format : x y r\n};\n#line 5 \"geometry/is_intersect_cp.hpp\"\
    \n// intersection (circle and point)\ninline bool is_intersect_cp(const Circle\
    \ &c, const Point &p) { return equal(std::abs(p - c.o), c.r); }\n"
  code: '#pragma once


    #include "geometry/point.hpp"

    #include "geometry/circle.hpp"

    // intersection (circle and point)

    inline bool is_intersect_cp(const Circle &c, const Point &p) { return equal(std::abs(p
    - c.o), c.r); }'
  dependsOn:
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/circle.hpp
  isVerificationFile: false
  path: geometry/is_intersect_cp.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2023-03-12 06:40:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/is_intersect_cp.hpp
layout: document
redirect_from:
- /library/geometry/is_intersect_cp.hpp
- /library/geometry/is_intersect_cp.hpp.html
title: geometry/is_intersect_cp.hpp
---
