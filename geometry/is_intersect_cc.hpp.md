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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_e.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/is_intersect_cc.hpp\"\n\n#line 2 \"geometry/circle.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\
    \n\n// template\nusing Double = double;\nconst Double EPS = 1e-8;\nconst Double\
    \ PI = std::acos(-1);\ninline int sign(const Double &x) { return x <= -EPS ? -1\
    \ : (x >= EPS ? 1 : 0); }\ninline bool equal(const Double &a, const Double &b)\
    \ { return sign(a - b) == 0; }\nDouble radian_to_degree(const Double &r) { return\
    \ r * 180.0 / PI; }\nDouble degree_to_radian(const Double &d) { return d * PI\
    \ / 180.0; }\n#line 4 \"geometry/point.hpp\"\n\n// point\nusing Point = std::complex<Double>;\n\
    std::istream &operator>>(std::istream &is, Point &p) {\n    Double x, y;\n   \
    \ is >> x >> y;\n    p = Point(x, y);\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
    \ &os, Point &p) {\n    os << std::fixed << std::setprecision(15);\n    return\
    \ os << p.real() << ' ' << p.imag();\n}\n\nnamespace std {\nbool operator<(const\
    \ Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real()\
    \ : a.imag() < b.imag(); }\n}  // namespace std\n\n// inner product\nDouble dot(const\
    \ Point &a, const Point &b) { return a.real() * b.real() + a.imag() * b.imag();\
    \ }\n// outer product\nDouble cross(const Point &a, const Point &b) { return a.real()\
    \ * b.imag() - a.imag() * b.real(); }\n// rotate Point p counterclockwise by theta\
    \ radian\nPoint rotate(const Point &p, const Double &theta) { return p * Point(cos(theta),\
    \ sin(theta)); }\n// compare (x, y)\nbool compare_x(const Point &a, const Point\
    \ &b) { return equal(a.real(), b.real()) ? sign(a.imag() - b.imag()) < 0 : sign(a.real()\
    \ - b.real()) < 0; }\n// compare (y, x)\nbool compare_y(const Point &a, const\
    \ Point &b) { return equal(a.imag(), b.imag()) ? sign(a.real() - b.real()) < 0\
    \ : sign(a.imag() - b.imag()) < 0; }\n#line 4 \"geometry/circle.hpp\"\n\n// circle\n\
    struct Circle {\n    Point o;\n    Double r;\n\n    Circle() = default;\n\n  \
    \  Circle(Point o, Double r) : o(o), r(r) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Circle &c) { return is >> c.o >> c.r; }  // format\
    \ : x y r\n};\n#line 3 \"geometry/tangent_number_cc.hpp\"\n// return the number\
    \ of tangent\nint tangent_number_cc(Circle c1, Circle c2) {\n    if (c1.r < c2.r)\
    \ std::swap(c1, c2);\n    Double d = std::abs(c1.o - c2.o);\n    if (sign(d -\
    \ c1.r - c2.r) == 1) return 4;  // d > c1.r + c2.r\n    if (sign(d - c1.r - c2.r)\
    \ == 0) return 3;  // d = c1.r + c2.r\n    if (sign(d - c1.r + c2.r) == 1) return\
    \ 2;  // d > c1.r - c2.r\n    if (sign(d - c1.r + c2.r) == 0) return 1;  // d\
    \ = c1.r - c2.r\n    return 0;\n}\n#line 5 \"geometry/is_intersect_cc.hpp\"\n\
    // intersection (circle and circle)\n// intersect = number of tangent is 1, 2,\
    \ 3\nbool is_intersect_cc(const Circle &c1, const Circle &c2) {\n    int num =\
    \ tangent_number_cc(c1, c2);\n    return 1 <= num and num <= 3;\n}\n"
  code: "#pragma once\n\n#include \"geometry/circle.hpp\"\n#include \"geometry/tangent_number_cc.hpp\"\
    \n// intersection (circle and circle)\n// intersect = number of tangent is 1,\
    \ 2, 3\nbool is_intersect_cc(const Circle &c1, const Circle &c2) {\n    int num\
    \ = tangent_number_cc(c1, c2);\n    return 1 <= num and num <= 3;\n}"
  dependsOn:
  - geometry/circle.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/tangent_number_cc.hpp
  isVerificationFile: false
  path: geometry/is_intersect_cc.hpp
  requiredBy:
  - geometry/cross_point_cc.hpp
  - geometry/all.hpp
  timestamp: '2023-02-18 13:26:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_7_e.test.cpp
documentation_of: geometry/is_intersect_cc.hpp
layout: document
redirect_from:
- /library/geometry/is_intersect_cc.hpp
- /library/geometry/is_intersect_cc.hpp.html
title: geometry/is_intersect_cc.hpp
---
