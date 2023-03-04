---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':question:'
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
  - icon: ':x:'
    path: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
  bundledCode: "#line 2 \"geometry/polygon_area.hpp\"\n\n#line 2 \"geometry/polygon.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\
    \n\n// template\nusing Double = double;\nconst Double EPS = 1e-10;\nconst Double\
    \ PI = std::acos(Double(-1));\ninline int sign(const Double &x) { return x <=\
    \ -EPS ? -1 : (x >= EPS ? 1 : 0); }\ninline bool equal(const Double &a, const\
    \ Double &b) { return sign(a - b) == 0; }\ninline Double radian_to_degree(const\
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
    #line 4 \"geometry/polygon.hpp\"\n\n// polygon\nusing Polygon = std::vector<Point>;\n\
    std::istream &operator>>(std::istream &is, Polygon &p) {\n    for (auto &&pi :\
    \ p) is >> pi;\n    return is;\n}\nstd::ostream &operator<<(std::ostream &os,\
    \ const Polygon &p) {\n    for (auto &&pi : p) os << pi << \" -> \";\n    return\
    \ os;\n}\n#line 4 \"geometry/polygon_area.hpp\"\n\n// area of polygon\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    Double polygon_area(const Polygon &p) {\n    int n = (int)p.size();\n    assert(n\
    \ >= 2);\n    Double ret = Double(0);\n    for (int i = 0; i < n - 1; i++) {\n\
    \        ret += cross(p[i], p[i + 1]);\n    }\n    ret += cross(p[n - 1], p[0]);\n\
    \    // counter clockwise: ret > 0\n    // clockwise: ret < 0\n    return std::abs(ret)\
    \ / 2;\n}\n"
  code: "#pragma once\n\n#include \"geometry/polygon.hpp\"\n\n// area of polygon\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\nDouble polygon_area(const\
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
  timestamp: '2023-03-05 00:14:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
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