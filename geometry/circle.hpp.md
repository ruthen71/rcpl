---
data:
  _extendedDependsOn:
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
  - icon: ':heavy_check_mark:'
    path: geometry/circumscribed_circle.hpp
    title: geometry/circumscribed_circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cl.hpp
    title: geometry/cross_point_cl.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/incircle.hpp
    title: geometry/incircle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cl.hpp
    title: geometry/is_intersect_cl.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_cp.hpp
    title: geometry/is_intersect_cp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_point_cp.hpp
    title: geometry/tangent_point_cp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_b.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_d.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_d.test.cpp
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
  bundledCode: "#line 2 \"geometry/circle.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\
    \n#line 2 \"geometry/geometry_template.hpp\"\n\n// template\nusing Double = double;\
    \    // double or long double\nconst Double EPS = 1e-8;  // change the value depending\
    \ on the problem\nconst Double PI = std::acos(Double(-1));\ninline int sign(const\
    \ Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }\ninline bool equal(const\
    \ Double &a, const Double &b) { return sign(a - b) == 0; }\ninline Double radian_to_degree(const\
    \ Double &r) { return r * 180.0 / PI; }\ninline Double degree_to_radian(const\
    \ Double &d) { return d * PI / 180.0; }\n#line 4 \"geometry/point.hpp\"\n\n//\
    \ point\nusing Point = std::complex<Double>;\nstd::istream &operator>>(std::istream\
    \ &is, Point &p) {\n    Double x, y;\n    is >> x >> y;\n    p = Point(x, y);\n\
    \    return is;\n}\nstd::ostream &operator<<(std::ostream &os, const Point &p)\
    \ {\n    os << std::fixed << std::setprecision(15);\n    return os << p.real()\
    \ << ' ' << p.imag();\n}\n\n// for std::set, std::map, ...\nnamespace std {\n\
    inline bool operator<(const Point &a, const Point &b) { return a.real() != b.real()\
    \ ? a.real() < b.real() : a.imag() < b.imag(); }\n}  // namespace std\n\ninline\
    \ Point operator*(const Point &p, const Double &k) { return Point(p.real() * k,\
    \ p.imag() * k); }\ninline Point operator/(const Point &p, const Double &k) {\
    \ return Point(p.real() / k, p.imag() / k); }\n// equal (point and point)\ninline\
    \ bool equal(const Point &a, const Point &b) { return equal(a.real(), b.real())\
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
    #line 4 \"geometry/circle.hpp\"\n\n// circle\nstruct Circle {\n    Point o;\n\
    \    Double r;\n\n    Circle() = default;\n\n    Circle(const Point &o, const\
    \ Double &r) : o(o), r(r) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Circle &c) { return is >> c.o >> c.r; }  // format\
    \ : x y r\n};\n"
  code: "#pragma once\n\n#include \"geometry/point.hpp\"\n\n// circle\nstruct Circle\
    \ {\n    Point o;\n    Double r;\n\n    Circle() = default;\n\n    Circle(const\
    \ Point &o, const Double &r) : o(o), r(r) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Circle &c) { return is >> c.o >> c.r; }  // format\
    \ : x y r\n};"
  dependsOn:
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: false
  path: geometry/circle.hpp
  requiredBy:
  - geometry/circumscribed_circle.hpp
  - geometry/is_intersect_cc.hpp
  - geometry/tangent_number_cc.hpp
  - geometry/tangent_point_cp.hpp
  - geometry/all.hpp
  - geometry/is_intersect_cp.hpp
  - geometry/is_intersect_cl.hpp
  - geometry/incircle.hpp
  - geometry/cross_point_cc.hpp
  - geometry/cross_point_cl.hpp
  timestamp: '2023-03-12 06:40:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_7_b.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_e.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_f.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_c.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_d.test.cpp
documentation_of: geometry/circle.hpp
layout: document
redirect_from:
- /library/geometry/circle.hpp
- /library/geometry/circle.hpp.html
title: geometry/circle.hpp
---
