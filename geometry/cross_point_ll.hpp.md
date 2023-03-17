---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
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
  - icon: ':heavy_check_mark:'
    path: geometry/circumscribed_circle.hpp
    title: geometry/circumscribed_circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_cut.hpp
    title: geometry/convex_polygon_cut.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/incircle.hpp
    title: geometry/incircle.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_b.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/cross_point_ll.hpp\"\n\n#line 2 \"geometry/line.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\
    \n\n// template\nusing Double = double;    // double or long double\nconst Double\
    \ EPS = 1e-8;  // change the value depending on the problem\nconst Double PI =\
    \ std::acos(Double(-1));\ninline int sign(const Double &x) { return x <= -EPS\
    \ ? -1 : (x >= EPS ? 1 : 0); }\ninline bool equal(const Double &a, const Double\
    \ &b) { return sign(a - b) == 0; }\ninline Double radian_to_degree(const Double\
    \ &r) { return r * 180.0 / PI; }\ninline Double degree_to_radian(const Double\
    \ &d) { return d * PI / 180.0; }\n#line 4 \"geometry/point.hpp\"\n\n// point\n\
    using Point = std::complex<Double>;\nstd::istream &operator>>(std::istream &is,\
    \ Point &p) {\n    Double x, y;\n    is >> x >> y;\n    p = Point(x, y);\n   \
    \ return is;\n}\nstd::ostream &operator<<(std::ostream &os, const Point &p) {\n\
    \    os << std::fixed << std::setprecision(15);\n    return os << p.real() <<\
    \ ' ' << p.imag();\n}\n\n// for std::set, std::map, ...\nnamespace std {\ninline\
    \ bool operator<(const Point &a, const Point &b) { return a.real() != b.real()\
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
    #line 4 \"geometry/line.hpp\"\n\n// line\nstruct Line {\n    Point a, b;\n\n \
    \   Line() = default;\n\n    Line(const Point &a, const Point &b) : a(a), b(b)\
    \ {}\n\n    // Ax + By = C\n    Line(const Double &A, const Double &B, const Double\
    \ &C) {\n        assert(equal(A, 0) and equal(B, 0));\n        if (equal(A, 0))\
    \ {\n            a = Point(0, C / B), b = Point(1, C / B);\n        } else if\
    \ (equal(B, 0)) {\n            a = Point(C / A, 0), b = Point(C / A, 1);\n   \
    \     } else if (equal(C, 0)) {\n            a = Point(0, 0), b = Point(1, B /\
    \ A);\n        } else {\n            a = Point(0, C / B), b = Point(C / A, 0);\n\
    \        }\n    }\n\n    friend std::istream &operator>>(std::istream &is, Line\
    \ &p) { return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 4 \"geometry/cross_point_ll.hpp\"\
    \n\n// cross point (line and line)\nPoint cross_point_ll(const Line &l1, const\
    \ Line &l2) {\n    Point base = l1.b - l1.a;\n    Double d12 = cross(base, l2.b\
    \ - l2.a);\n    Double d1 = cross(base, l1.b - l2.a);\n    if (sign(d12) == 0)\
    \ {\n        // parallel\n        if (sign(d1) == 0) {\n            // cross\n\
    \            return l2.a;\n        } else {\n            // not cross\n      \
    \      assert(false);\n        }\n    }\n    return l2.a + (l2.b - l2.a) * d1\
    \ / d12;\n}\n"
  code: "#pragma once\n\n#include \"geometry/line.hpp\"\n\n// cross point (line and\
    \ line)\nPoint cross_point_ll(const Line &l1, const Line &l2) {\n    Point base\
    \ = l1.b - l1.a;\n    Double d12 = cross(base, l2.b - l2.a);\n    Double d1 =\
    \ cross(base, l1.b - l2.a);\n    if (sign(d12) == 0) {\n        // parallel\n\
    \        if (sign(d1) == 0) {\n            // cross\n            return l2.a;\n\
    \        } else {\n            // not cross\n            assert(false);\n    \
    \    }\n    }\n    return l2.a + (l2.b - l2.a) * d1 / d12;\n}"
  dependsOn:
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: false
  path: geometry/cross_point_ll.hpp
  requiredBy:
  - geometry/circumscribed_circle.hpp
  - geometry/convex_polygon_cut.hpp
  - geometry/all.hpp
  - geometry/incircle.hpp
  timestamp: '2023-03-12 06:40:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_7_b.test.cpp
  - verify/aoj_cgl/aoj_cgl_4_c.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_c.test.cpp
documentation_of: geometry/cross_point_ll.hpp
layout: document
redirect_from:
- /library/geometry/cross_point_ll.hpp
- /library/geometry/cross_point_ll.hpp.html
title: geometry/cross_point_ll.hpp
---
