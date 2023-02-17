---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
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
  - icon: ':warning:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ &is, Circle &c) { return is >> c.o >> c.r; }  // format : x y r\n};\n#line 3\
    \ \"geometry/tangent_number_cc.hpp\"\n// return the number of tangent\nint tangent_number_cc(Circle\
    \ c1, Circle c2) {\n    if (c1.r < c2.r) std::swap(c1, c2);\n    Double d = std::abs(c1.o\
    \ - c2.o);\n    if (c1.r + c2.r < d) return 4;\n    if (equal(c1.r + c2.r, d))\
    \ return 3;\n    if (c1.r - c2.r < d) return 2;\n    if (equal(c1.r - c2.r, d))\
    \ return 1;\n    return 0;\n}\n"
  code: "#pragma once\n#include \"geometry/circle.hpp\"\n// return the number of tangent\n\
    int tangent_number_cc(Circle c1, Circle c2) {\n    if (c1.r < c2.r) std::swap(c1,\
    \ c2);\n    Double d = std::abs(c1.o - c2.o);\n    if (c1.r + c2.r < d) return\
    \ 4;\n    if (equal(c1.r + c2.r, d)) return 3;\n    if (c1.r - c2.r < d) return\
    \ 2;\n    if (equal(c1.r - c2.r, d)) return 1;\n    return 0;\n}"
  dependsOn:
  - geometry/circle.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: false
  path: geometry/tangent_number_cc.hpp
  requiredBy:
  - geometry/is_intersect_cc.hpp
  - geometry/all.hpp
  timestamp: '2023-02-17 09:43:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/tangent_number_cc.hpp
layout: document
redirect_from:
- /library/geometry/tangent_number_cc.hpp
- /library/geometry/tangent_number_cc.hpp.html
title: geometry/tangent_number_cc.hpp
---
