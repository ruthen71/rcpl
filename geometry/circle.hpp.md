---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  - icon: ':x:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':x:'
    path: geometry/cross_point_cl.hpp
    title: geometry/cross_point_cl.hpp
  - icon: ':x:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
  - icon: ':x:'
    path: geometry/is_intersect_cl.hpp
    title: geometry/is_intersect_cl.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_cp.hpp
    title: geometry/is_intersect_cp.hpp
  - icon: ':question:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
  - icon: ':x:'
    path: verify/aoj_cgl/aoj_cgl_7_d.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_d.test.cpp
  - icon: ':x:'
    path: verify/aoj_cgl/aoj_cgl_7_e.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
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
    #line 4 \"geometry/circle.hpp\"\n\n// circle\nstruct Circle {\n    Point o;\n\
    \    Double r;\n\n    Circle() = default;\n\n    Circle(Point o, Double r) : o(o),\
    \ r(r) {}\n\n    friend std::ostream &operator<<(std::ostream &os, const Circle\
    \ &c) { return os << c.o << ' ' << c.r; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Circle &c) { return is >> c.o >> c.r; }  // format : x y r\n};\n"
  code: "#pragma once\n\n#include \"geometry/point.hpp\"\n\n// circle\nstruct Circle\
    \ {\n    Point o;\n    Double r;\n\n    Circle() = default;\n\n    Circle(Point\
    \ o, Double r) : o(o), r(r) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Circle &c) { return is >> c.o >> c.r; }  // format\
    \ : x y r\n};"
  dependsOn:
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: false
  path: geometry/circle.hpp
  requiredBy:
  - geometry/cross_point_cc.hpp
  - geometry/is_intersect_cc.hpp
  - geometry/tangent_number_cc.hpp
  - geometry/is_intersect_cl.hpp
  - geometry/cross_point_cl.hpp
  - geometry/is_intersect_cp.hpp
  - geometry/all.hpp
  timestamp: '2023-02-12 02:42:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_7_e.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_d.test.cpp
documentation_of: geometry/circle.hpp
layout: document
redirect_from:
- /library/geometry/circle.hpp
- /library/geometry/circle.hpp.html
title: geometry/circle.hpp
---
