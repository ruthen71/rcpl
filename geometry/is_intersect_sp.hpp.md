---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/contain.hpp
    title: geometry/contain.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_ss.hpp
    title: geometry/cross_point_ss.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_sp.hpp
    title: geometry/distance_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_ss.hpp
    title: geometry/distance_ss.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_2_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_2_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
    title: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_3_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_3_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/is_intersect_sp.hpp\"\n\n#line 2 \"geometry/segment.hpp\"\
    \n\n#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n#line 2\
    \ \"geometry/geometry_template.hpp\"\n\n// template\nusing Double = double;\n\
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
    #line 4 \"geometry/line.hpp\"\n\n// line\nstruct Line {\n    Point a, b;\n\n \
    \   Line() = default;\n\n    Line(Point a, Point b) : a(a), b(b) {}\n\n    //\
    \ Ax + By = C\n    Line(Double A, Double B, Double C) {\n        assert(equal(A,\
    \ 0) and equal(B, 0));\n        if (equal(A, 0)) {\n            a = Point(0, C\
    \ / B), b = Point(1, C / B);\n        } else if (equal(B, 0)) {\n            a\
    \ = Point(C / A, 0), b = Point(C / A, 1);\n        } else if (equal(C, 0)) {\n\
    \            a = Point(0, 0), b = Point(1, B / A);\n        } else {\n       \
    \     a = Point(0, C / B), b = Point(C / A, 0);\n        }\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, Line &p) { return is >> p.a >> p.b;\
    \ }\n    friend std::ostream &operator<<(std::ostream &os, const Line &p) { return\
    \ os << p.a << \"->\" << p.b; }\n};\n#line 4 \"geometry/segment.hpp\"\n\n// segment\n\
    struct Segment : Line {\n    Segment() = default;\n\n    Segment(Point a, Point\
    \ b) : Line(a, b) {}\n};\n#line 2 \"geometry/ccw.hpp\"\n\n#line 4 \"geometry/ccw.hpp\"\
    \n\n// counter clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int\
    \ CLOCKWISE = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2; \
    \       // c-a-b line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr\
    \ int ON_SEGMENT = 0;         // a-c-b line\nint ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b, c)) == 1) return\
    \ COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return CLOCKWISE;\n   \
    \ if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (std::norm(b) < std::norm(c))\
    \ return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n#line 5 \"geometry/is_intersect_sp.hpp\"\
    \n\n// intersection (segment and point)\n// ccw(a, b, c) == ON_SEGMENT -> a -\
    \ c - b\nbool is_intersect_sp(const Segment &s, const Point &p) { return ccw(s.a,\
    \ s.b, p) == ON_SEGMENT or sign(std::abs(s.a - p)) == 0 or sign(std::abs(s.b -\
    \ p)) == 0; }\n"
  code: '#pragma once


    #include "geometry/segment.hpp"

    #include "geometry/ccw.hpp"


    // intersection (segment and point)

    // ccw(a, b, c) == ON_SEGMENT -> a - c - b

    bool is_intersect_sp(const Segment &s, const Point &p) { return ccw(s.a, s.b,
    p) == ON_SEGMENT or sign(std::abs(s.a - p)) == 0 or sign(std::abs(s.b - p)) ==
    0; }'
  dependsOn:
  - geometry/segment.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/ccw.hpp
  isVerificationFile: false
  path: geometry/is_intersect_sp.hpp
  requiredBy:
  - geometry/distance_sp.hpp
  - geometry/distance_ss.hpp
  - geometry/contain.hpp
  - geometry/cross_point_ss.hpp
  - geometry/all.hpp
  timestamp: '2023-02-18 13:26:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_3_c.test.cpp
  - verify/aoj_cgl/aoj_cgl_2_c.test.cpp
  - verify/aoj_cgl/aoj_cgl_2_d.test.cpp
documentation_of: geometry/is_intersect_sp.hpp
layout: document
redirect_from:
- /library/geometry/is_intersect_sp.hpp
- /library/geometry/is_intersect_sp.hpp.html
title: geometry/is_intersect_sp.hpp
---
