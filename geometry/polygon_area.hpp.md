---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_3_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_3_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
  bundledCode: "#line 2 \"geometry/polygon_area.hpp\"\n\n#line 2 \"geometry/polygon.hpp\"\
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
    \ : sign(a.imag() - b.imag()) < 0; }\n#line 4 \"geometry/polygon.hpp\"\n\n// polygon\n\
    using Polygon = std::vector<Point>;\nstd::istream &operator>>(std::istream &is,\
    \ Polygon &p) {\n    for (auto &&pi : p) is >> pi;\n    return is;\n}\nstd::ostream\
    \ &operator<<(std::ostream &os, Polygon &p) {\n    for (auto &&pi : p) os << pi\
    \ << \" -> \";\n    return os;\n}\n#line 4 \"geometry/polygon_area.hpp\"\n// area\
    \ of polygon\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    Double polygon_area(const Polygon &p) {\n    int n = (int)p.size();\n    assert(n\
    \ >= 2);\n    Double ret = Double(0);\n    for (int i = 0; i < n - 1; i++) {\n\
    \        ret += cross(p[i], p[i + 1]);\n    }\n    ret += cross(p[n - 1], p[0]);\n\
    \    // counter clockwise: ret > 0\n    // clockwise: ret < 0\n    return std::abs(ret)\
    \ / 2;\n}\n"
  code: "#pragma once\n\n#include \"geometry/polygon.hpp\"\n// area of polygon\n//\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\nDouble polygon_area(const\
    \ Polygon &p) {\n    int n = (int)p.size();\n    assert(n >= 2);\n    Double ret\
    \ = Double(0);\n    for (int i = 0; i < n - 1; i++) {\n        ret += cross(p[i],\
    \ p[i + 1]);\n    }\n    ret += cross(p[n - 1], p[0]);\n    // counter clockwise:\
    \ ret > 0\n    // clockwise: ret < 0\n    return std::abs(ret) / 2;\n}"
  dependsOn:
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: false
  path: geometry/polygon_area.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2023-02-18 17:31:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_3_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_4_c.test.cpp
documentation_of: geometry/polygon_area.hpp
layout: document
redirect_from:
- /library/geometry/polygon_area.hpp
- /library/geometry/polygon_area.hpp.html
title: geometry/polygon_area.hpp
---
