---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':warning:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
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
    \ sin(theta)); }\n#line 4 \"geometry/circle.hpp\"\n\n// circle\nstruct Circle\
    \ {\n    Point o;\n    Double r;\n\n    Circle() = default;\n\n    Circle(Point\
    \ o, Double r) : o(o), r(r) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Circle &c) { return is >> c.o >> c.r; }  // format\
    \ : x y r\n};\n#line 3 \"geometry/tangent_number_cc.hpp\"\n// return the number\
    \ of tangent\nint tangent_number_cc(Circle c1, Circle c2) {\n    if (c1.r < c2.r)\
    \ std::swap(c1, c2);\n    Double d = std::abs(c1.o - c2.o);\n    if (c1.r + c2.r\
    \ < d) return 4;\n    if (equal(c1.r + c2.r, d)) return 3;\n    if (c1.r - c2.r\
    \ < d) return 2;\n    if (equal(c1.r - c2.r, d)) return 1;\n    return 0;\n}\n\
    #line 5 \"geometry/is_intersect_cc.hpp\"\n// intersection (circle and circle)\n\
    // intersect = number of tangent is 1, 2, 3\nbool is_intersect_cc(const Circle\
    \ &c1, const Circle &c2) {\n    int num = tangent_number_cc(c1, c2);\n    return\
    \ 1 <= num and num <= 3;\n}\n"
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
  - geometry/all.hpp
  timestamp: '2023-02-17 12:54:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/is_intersect_cc.hpp
layout: document
redirect_from:
- /library/geometry/is_intersect_cc.hpp
- /library/geometry/is_intersect_cc.hpp.html
title: geometry/is_intersect_cc.hpp
---
