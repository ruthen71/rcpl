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
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_point_cp.hpp
    title: geometry/tangent_point_cp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
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
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
  bundledCode: "#line 2 \"geometry/circle.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\
    \n#line 2 \"geometry/geometry_template.hpp\"\n\n// template\nusing Double = double;\n\
    const Double EPS = 1e-8;\nconst Double PI = std::acos(-1);\ninline int sign(const\
    \ Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }\ninline bool equal(const\
    \ Double &a, const Double &b) { return sign(a - b) == 0; }\nDouble radian_to_degree(const\
    \ Double &r) { return r * 180.0 / PI; }\nDouble degree_to_radian(const Double\
    \ &d) { return d * PI / 180.0; }\n#line 4 \"geometry/point.hpp\"\n\n// point\n\
    using Point = std::complex<Double>;\nstd::istream &operator>>(std::istream &is,\
    \ Point &p) {\n    Double x, y;\n    is >> x >> y;\n    p = Point(x, y);\n   \
    \ return is;\n}\nstd::ostream &operator<<(std::ostream &os, Point &p) {\n    os\
    \ << std::fixed << std::setprecision(15);\n    return os << p.real() << ' ' <<\
    \ p.imag();\n}\n\nnamespace std {\nbool operator<(const Point &a, const Point\
    \ &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();\
    \ }\n}  // namespace std\n\n// inner product\nDouble dot(const Point &a, const\
    \ Point &b) { return a.real() * b.real() + a.imag() * b.imag(); }\n// outer product\n\
    Double cross(const Point &a, const Point &b) { return a.real() * b.imag() - a.imag()\
    \ * b.real(); }\n// rotate Point p counterclockwise by theta radian\nPoint rotate(const\
    \ Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }\n\
    // compare (x, y)\nbool compare_x(const Point &a, const Point &b) { return equal(a.real(),\
    \ b.real()) ? sign(a.imag() - b.imag()) < 0 : sign(a.real() - b.real()) < 0; }\n\
    // compare (y, x)\nbool compare_y(const Point &a, const Point &b) { return equal(a.imag(),\
    \ b.imag()) ? sign(a.real() - b.real()) < 0 : sign(a.imag() - b.imag()) < 0; }\n\
    #line 4 \"geometry/circle.hpp\"\n\n// circle\nstruct Circle {\n    Point o;\n\
    \    Double r;\n\n    Circle() = default;\n\n    Circle(Point o, Double r) : o(o),\
    \ r(r) {}\n\n    friend std::ostream &operator<<(std::ostream &os, const Circle\
    \ &c) { return os << c.o << ' ' << c.r; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Circle &c) { return is >> c.o >> c.r; }  // format : x y r\n};\n#line 3\
    \ \"geometry/tangent_number_cc.hpp\"\n\n// return the number of tangent\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\n\
    int tangent_number_cc(Circle c1, Circle c2) {\n    if (c1.r < c2.r) std::swap(c1,\
    \ c2);\n    Double d = std::abs(c1.o - c2.o);\n    if (sign(d - c1.r - c2.r) ==\
    \ 1) return 4;  // d > c1.r + c2.r\n    if (sign(d - c1.r - c2.r) == 0) return\
    \ 3;  // d = c1.r + c2.r\n    if (sign(d - c1.r + c2.r) == 1) return 2;  // d\
    \ > c1.r - c2.r\n    if (sign(d - c1.r + c2.r) == 0) return 1;  // d = c1.r -\
    \ c2.r\n    return 0;\n}\n"
  code: "#pragma once\n#include \"geometry/circle.hpp\"\n\n// return the number of\
    \ tangent\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\n\
    int tangent_number_cc(Circle c1, Circle c2) {\n    if (c1.r < c2.r) std::swap(c1,\
    \ c2);\n    Double d = std::abs(c1.o - c2.o);\n    if (sign(d - c1.r - c2.r) ==\
    \ 1) return 4;  // d > c1.r + c2.r\n    if (sign(d - c1.r - c2.r) == 0) return\
    \ 3;  // d = c1.r + c2.r\n    if (sign(d - c1.r + c2.r) == 1) return 2;  // d\
    \ > c1.r - c2.r\n    if (sign(d - c1.r + c2.r) == 0) return 1;  // d = c1.r -\
    \ c2.r\n    return 0;\n}"
  dependsOn:
  - geometry/circle.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: false
  path: geometry/tangent_number_cc.hpp
  requiredBy:
  - geometry/tangent_point_cp.hpp
  - geometry/cross_point_cc.hpp
  - geometry/is_intersect_cc.hpp
  - geometry/all.hpp
  timestamp: '2023-02-21 09:00:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_7_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_f.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_e.test.cpp
documentation_of: geometry/tangent_number_cc.hpp
layout: document
redirect_from:
- /library/geometry/tangent_number_cc.hpp
- /library/geometry/tangent_number_cc.hpp.html
title: geometry/tangent_number_cc.hpp
---
