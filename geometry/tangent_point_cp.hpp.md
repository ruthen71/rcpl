---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_f.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
  bundledCode: "#line 2 \"geometry/tangent_point_cp.hpp\"\n\n#line 2 \"geometry/cross_point_cc.hpp\"\
    \n\n#line 2 \"geometry/is_intersect_cc.hpp\"\n\n#line 2 \"geometry/circle.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\
    \n\n// template\nusing Double = double;    // double or long double\nconst Double\
    \ EPS = 1e-8;  // change the value depending on the problem\nconst Double PI =\
    \ std::acos(Double(-1));\ninline int sign(const Double &x) { return x <= -EPS\
    \ ? -1 : (x >= EPS ? 1 : 0); }\ninline bool equal(const Double &a, const Double\
    \ &b) { return sign(a - b) == 0; }\ninline Double radian_to_degree(const Double\
    \ &r) { return r * 180.0 / PI; }\ninline Double degree_to_radian(const Double\
    \ &d) { return d * PI / 180.0; }\nconstexpr int IN = 2;\nconstexpr int ON = 1;\n\
    constexpr int OUT = 0;\n#line 4 \"geometry/point.hpp\"\n\n// point\nusing Point\
    \ = std::complex<Double>;\nstd::istream &operator>>(std::istream &is, Point &p)\
    \ {\n    Double x, y;\n    is >> x >> y;\n    p = Point(x, y);\n    return is;\n\
    }\nstd::ostream &operator<<(std::ostream &os, const Point &p) {\n    os << std::fixed\
    \ << std::setprecision(15);\n    return os << p.real() << ' ' << p.imag();\n}\n\
    \n// for std::set, std::map, ...\nnamespace std {\ninline bool operator<(const\
    \ Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real()\
    \ : a.imag() < b.imag(); }\n}  // namespace std\n\ninline Point operator*(const\
    \ Point &p, const Double &k) { return Point(p.real() * k, p.imag() * k); }\ninline\
    \ Point operator/(const Point &p, const Double &k) { return Point(p.real() / k,\
    \ p.imag() / k); }\n// equal (point and point)\ninline bool equal(const Point\
    \ &a, const Point &b) { return equal(a.real(), b.real()) and equal(a.imag(), b.imag());\
    \ }\n// inner product\ninline Double dot(const Point &a, const Point &b) { return\
    \ a.real() * b.real() + a.imag() * b.imag(); }\n// outer product\ninline Double\
    \ cross(const Point &a, const Point &b) { return a.real() * b.imag() - a.imag()\
    \ * b.real(); }\n// rotate Point p counterclockwise by theta radian\ninline Point\
    \ rotate(const Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta));\
    \ }\n// compare (x, y)\ninline bool compare_x(const Point &a, const Point &b)\
    \ { return equal(a.real(), b.real()) ? sign(a.imag() - b.imag()) < 0 : sign(a.real()\
    \ - b.real()) < 0; }\n// compare (y, x)\ninline bool compare_y(const Point &a,\
    \ const Point &b) { return equal(a.imag(), b.imag()) ? sign(a.real() - b.real())\
    \ < 0 : sign(a.imag() - b.imag()) < 0; }\n// compare by arg\ninline bool compare_arg(const\
    \ Point &a, const Point &b) {\n    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n\
    \    return (Point(0, 0) < a) == (Point(0, 0) < b) ? a.real() * b.imag() > a.imag()\
    \ * b.real() : a < b;\n}\n#line 4 \"geometry/circle.hpp\"\n\n// circle\nstruct\
    \ Circle {\n    Point o;\n    Double r;\n\n    Circle() = default;\n\n    Circle(const\
    \ Point &o, const Double &r) : o(o), r(r) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Circle &c) { return is >> c.o >> c.r; }  // format\
    \ : x y r\n};\n#line 3 \"geometry/tangent_number_cc.hpp\"\n\n// return the number\
    \ of tangent\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\n\
    int tangent_number_cc(Circle c1, Circle c2) {\n    if (c1.r < c2.r) std::swap(c1,\
    \ c2);\n    const Double d = std::abs(c1.o - c2.o);\n    if (sign(d - c1.r - c2.r)\
    \ == 1) return 4;  // d > c1.r + c2.r\n    if (sign(d - c1.r - c2.r) == 0) return\
    \ 3;  // d = c1.r + c2.r\n    if (sign(d - c1.r + c2.r) == 1) return 2;  // d\
    \ > c1.r - c2.r\n    if (sign(d - c1.r + c2.r) == 0) return 1;  // d = c1.r -\
    \ c2.r\n    return 0;\n}\n#line 5 \"geometry/is_intersect_cc.hpp\"\n\n// intersection\
    \ (circle and circle)\n// intersect = number of tangent is 1, 2, 3\ninline bool\
    \ is_intersect_cc(const Circle &c1, const Circle &c2) {\n    int num = tangent_number_cc(c1,\
    \ c2);\n    return 1 <= num and num <= 3;\n}\n#line 4 \"geometry/cross_point_cc.hpp\"\
    \n\n// cross point (circle and circle)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E\n\
    std::vector<Point> cross_point_cc(const Circle &c1, const Circle &c2) {\n    if\
    \ (!is_intersect_cc(c1, c2)) return {};\n    Double d = std::abs(c1.o - c2.o);\n\
    \    Double a = std::acos((std::norm(c1.r) - std::norm(c2.r) + std::norm(d)) /\
    \ (2 * c1.r * d));\n    Double t = std::arg(c2.o - c1.o);\n    Point p = c1.o\
    \ + std::polar(c1.r, t + a);\n    Point q = c1.o + std::polar(c1.r, t - a);\n\
    \    if (equal(p.real(), q.real()) and equal(p.imag(), q.imag())) return {p};\n\
    \    return {p, q};\n}\n#line 4 \"geometry/tangent_point_cp.hpp\"\n\n// tangent\
    \ point (circle and point)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\n\
    std::pair<Point, Point> tangent_point_cp(const Circle &c, const Point &p) {\n\
    \    assert(sign(std::abs(c.o - p) - c.r) == 1);\n    auto res = cross_point_cc(c,\
    \ Circle(p, sqrt(std::norm(c.o - p) - std::norm(c.r))));\n    return {res[0],\
    \ res[1]};\n}\n"
  code: "#pragma once\n\n#include \"geometry/cross_point_cc.hpp\"\n\n// tangent point\
    \ (circle and point)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\n\
    std::pair<Point, Point> tangent_point_cp(const Circle &c, const Point &p) {\n\
    \    assert(sign(std::abs(c.o - p) - c.r) == 1);\n    auto res = cross_point_cc(c,\
    \ Circle(p, sqrt(std::norm(c.o - p) - std::norm(c.r))));\n    return {res[0],\
    \ res[1]};\n}"
  dependsOn:
  - geometry/cross_point_cc.hpp
  - geometry/is_intersect_cc.hpp
  - geometry/circle.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/tangent_number_cc.hpp
  isVerificationFile: false
  path: geometry/tangent_point_cp.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2023-04-04 15:57:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_7_f.test.cpp
documentation_of: geometry/tangent_point_cp.hpp
layout: document
redirect_from:
- /library/geometry/tangent_point_cp.hpp
- /library/geometry/tangent_point_cp.hpp.html
title: geometry/tangent_point_cp.hpp
---
