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
  - icon: ':heavy_check_mark:'
    path: geometry/area.hpp
    title: geometry/area.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/contain.hpp
    title: geometry/contain.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_convex.hpp
    title: geometry/is_convex.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_3_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_3_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_3_b.test.cpp
    title: verify/aoj_cgl/aoj_cgl_3_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_3_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_3_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/polygon.hpp\"\n\n#line 2 \"geometry/point.hpp\"\
    \n\n#line 2 \"geometry/geometry_template.hpp\"\n\n// template\nusing Double =\
    \ double;\nconst Double EPS = 1e-8;\nconst Double PI = std::acos(-1);\ninline\
    \ int sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }\n\
    inline bool equal(const Double &a, const Double &b) { return sign(a - b) == 0;\
    \ }\nDouble radian_to_degree(const Double &r) { return r * 180.0 / PI; }\nDouble\
    \ degree_to_radian(const Double &d) { return d * PI / 180.0; }\n#line 4 \"geometry/point.hpp\"\
    \n\n// point\nusing Point = std::complex<Double>;\nstd::istream &operator>>(std::istream\
    \ &is, Point &p) {\n    Double x, y;\n    is >> x >> y;\n    p = Point(x, y);\n\
    \    return is;\n}\nstd::ostream &operator<<(std::ostream &os, Point &p) {\n \
    \   os << std::fixed << std::setprecision(15);\n    return os << p.real() << '\
    \ ' << p.imag();\n}\n\nnamespace std {\nbool operator<(const Point &a, const Point\
    \ &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();\
    \ }\n}  // namespace std\n\n// inner product\nDouble dot(const Point &a, const\
    \ Point &b) { return a.real() * b.real() + a.imag() * b.imag(); }\n// outer product\n\
    Double cross(const Point &a, const Point &b) { return a.real() * b.imag() - a.imag()\
    \ * b.real(); }\n// rotate Point p counterclockwise by theta radian\nPoint rotate(const\
    \ Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }\n\
    #line 4 \"geometry/polygon.hpp\"\n// polygon\nusing Polygon = std::vector<Point>;\n\
    std::istream &operator>>(std::istream &is, Polygon &p) {\n    for (auto &&pi :\
    \ p) is >> pi;\n    return is;\n}\nstd::ostream &operator<<(std::ostream &os,\
    \ Polygon &p) {\n    for (auto &&pi : p) os << pi << \" -> \";\n    return os;\n\
    }\n"
  code: "#pragma once\n\n#include \"geometry/point.hpp\"\n// polygon\nusing Polygon\
    \ = std::vector<Point>;\nstd::istream &operator>>(std::istream &is, Polygon &p)\
    \ {\n    for (auto &&pi : p) is >> pi;\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
    \ &os, Polygon &p) {\n    for (auto &&pi : p) os << pi << \" -> \";\n    return\
    \ os;\n}"
  dependsOn:
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: false
  path: geometry/polygon.hpp
  requiredBy:
  - geometry/area.hpp
  - geometry/is_convex.hpp
  - geometry/contain.hpp
  - geometry/all.hpp
  timestamp: '2023-02-17 13:25:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_3_b.test.cpp
  - verify/aoj_cgl/aoj_cgl_3_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_3_c.test.cpp
documentation_of: geometry/polygon.hpp
layout: document
redirect_from:
- /library/geometry/polygon.hpp
- /library/geometry/polygon.hpp.html
title: geometry/polygon.hpp
---
