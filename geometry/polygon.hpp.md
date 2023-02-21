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
    path: geometry/convex_polygon_cut.hpp
    title: geometry/convex_polygon_cut.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_diameter.hpp
    title: geometry/convex_polygon_diameter.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/monotone_chain.hpp
    title: geometry/monotone_chain.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon_area.hpp
    title: geometry/polygon_area.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon_contain.hpp
    title: geometry/polygon_contain.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon_is_convex.hpp
    title: geometry/polygon_is_convex.hpp
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
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_4_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_4_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_4_b.test.cpp
    title: verify/aoj_cgl/aoj_cgl_4_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
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
    \ }\n}  // namespace std\n\nPoint operator*(const Point &p, const Double &k) {\
    \ return Point(p.real() * k, p.imag() * k); }\nPoint operator/(const Point &p,\
    \ const Double &k) { return Point(p.real() / k, p.imag() / k); }\n// equal (point\
    \ and point)\ninline bool equal(const Point &a, const Point &b) { return equal(a.real(),\
    \ b.real()) and equal(a.imag(), b.imag()); }\n// inner product\ninline Double\
    \ dot(const Point &a, const Point &b) { return a.real() * b.real() + a.imag()\
    \ * b.imag(); }\n// outer product\ninline Double cross(const Point &a, const Point\
    \ &b) { return a.real() * b.imag() - a.imag() * b.real(); }\n// rotate Point p\
    \ counterclockwise by theta radian\ninline Point rotate(const Point &p, const\
    \ Double &theta) { return p * Point(cos(theta), sin(theta)); }\n// compare (x,\
    \ y)\ninline bool compare_x(const Point &a, const Point &b) { return equal(a.real(),\
    \ b.real()) ? sign(a.imag() - b.imag()) < 0 : sign(a.real() - b.real()) < 0; }\n\
    // compare (y, x)\ninline bool compare_y(const Point &a, const Point &b) { return\
    \ equal(a.imag(), b.imag()) ? sign(a.real() - b.real()) < 0 : sign(a.imag() -\
    \ b.imag()) < 0; }\n#line 4 \"geometry/polygon.hpp\"\n\n// polygon\nusing Polygon\
    \ = std::vector<Point>;\nstd::istream &operator>>(std::istream &is, Polygon &p)\
    \ {\n    for (auto &&pi : p) is >> pi;\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
    \ &os, Polygon &p) {\n    for (auto &&pi : p) os << pi << \" -> \";\n    return\
    \ os;\n}\n"
  code: "#pragma once\n\n#include \"geometry/point.hpp\"\n\n// polygon\nusing Polygon\
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
  - geometry/convex_polygon_diameter.hpp
  - geometry/polygon_contain.hpp
  - geometry/convex_polygon_cut.hpp
  - geometry/polygon_is_convex.hpp
  - geometry/polygon_area.hpp
  - geometry/monotone_chain.hpp
  - geometry/all.hpp
  timestamp: '2023-02-21 21:25:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_4_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_3_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_3_b.test.cpp
  - verify/aoj_cgl/aoj_cgl_4_c.test.cpp
  - verify/aoj_cgl/aoj_cgl_4_b.test.cpp
  - verify/aoj_cgl/aoj_cgl_3_c.test.cpp
documentation_of: geometry/polygon.hpp
layout: document
redirect_from:
- /library/geometry/polygon.hpp
- /library/geometry/polygon.hpp.html
title: geometry/polygon.hpp
---
