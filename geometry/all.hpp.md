---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':warning:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':warning:'
    path: geometry/cross_point_ll.hpp
    title: geometry/cross_point_ll.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_ss.hpp
    title: geometry/cross_point_ss.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_cp.hpp
    title: geometry/is_intersect_cp.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_ll.hpp
    title: geometry/is_intersect_ll.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_lp.hpp
    title: geometry/is_intersect_lp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_sp.hpp
    title: geometry/is_intersect_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_ss.hpp
    title: geometry/is_intersect_ss.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_orthogonal.hpp
    title: geometry/is_orthogonal.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_parallel.hpp
    title: geometry/is_parallel.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: geometry/reflection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  - icon: ':warning:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/geometry_template.hpp\"\n\n// template\nusing Double\
    \ = double;\nconst Double EPS = 1e-8;\nconst Double PI = std::acos(-1);\ninline\
    \ int sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }\n\
    inline bool equal(const Double &a, const Double &b) { return sign(a - b) == 0;\
    \ }\nDouble radian_to_degree(const Double &r) { return r * 180.0 / PI; }\nDouble\
    \ degree_to_radian(const Double &d) { return d * PI / 180.0; }\n#line 3 \"geometry/all.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#line 4 \"geometry/point.hpp\"\n\n// point\n\
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
    #line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\n\n// line\nstruct\
    \ Line {\n    Point a, b;\n\n    Line() = default;\n\n    Line(Point a, Point\
    \ b) : a(a), b(b) {}\n\n    // Ax + By = C\n    Line(Double A, Double B, Double\
    \ C) {\n        assert(equal(A, 0) and equal(B, 0));\n        if (equal(A, 0))\
    \ {\n            a = Point(0, C / B), b = Point(1, C / B);\n        } else if\
    \ (equal(B, 0)) {\n            a = Point(C / A, 0), b = Point(C / A, 1);\n   \
    \     } else if (equal(C, 0)) {\n            a = Point(0, 0), b = Point(1, B /\
    \ A);\n        } else {\n            a = Point(0, C / B), b = Point(C / A, 0);\n\
    \        }\n    }\n\n    friend std::istream &operator>>(std::istream &is, Line\
    \ &p) { return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 2 \"geometry/segment.hpp\"\
    \n\n#line 4 \"geometry/segment.hpp\"\n\n// segment\nstruct Segment : Line {\n\
    \    Segment() = default;\n\n    Segment(Point a, Point b) : Line(a, b) {}\n};\n\
    #line 2 \"geometry/circle.hpp\"\n\n#line 4 \"geometry/circle.hpp\"\n\n// circle\n\
    struct Circle {\n    Point o;\n    Double r;\n\n    Circle() = default;\n\n  \
    \  Circle(Point o, Double r) : o(o), r(r) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Circle &c) { return is >> c.o >> c.r; }  // format\
    \ : x y r\n};\n#line 8 \"geometry/all.hpp\"\n\n#line 2 \"geometry/projection.hpp\"\
    \n\n#line 5 \"geometry/projection.hpp\"\n\n// projection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    Point projection(const Line &l, const Point &p) {\n    Double t = dot(p - l.a,\
    \ l.b - l.a) / std::norm(l.b - l.a);\n    return l.a + t * (l.b - l.a);\n}\n#line\
    \ 2 \"geometry/reflection.hpp\"\n\n#line 6 \"geometry/reflection.hpp\"\n\n// reflection\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\nPoint reflection(const\
    \ Line &l, const Point &p) { return p + (projection(l, p) - p) * Double(2.0);\
    \ }\n#line 2 \"geometry/ccw.hpp\"\n\n#line 4 \"geometry/ccw.hpp\"\n\n// counter\
    \ clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int\
    \ CLOCKWISE = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2; \
    \       // c-a-b line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr\
    \ int ON_SEGMENT = 0;         // a-c-b line\nint ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b, c)) == 1) return\
    \ COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return CLOCKWISE;\n   \
    \ if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (std::norm(b) < std::norm(c))\
    \ return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n#line 2 \"geometry/is_orthogonal.hpp\"\
    \n\n#line 4 \"geometry/is_orthogonal.hpp\"\n\n// orthogonal\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    bool is_orthogonal(const Line &l1, const Line &l2) { return sign(dot(l1.b - l1.a,\
    \ l2.b - l2.a)) == 0; }\n#line 2 \"geometry/is_parallel.hpp\"\n\n#line 4 \"geometry/is_parallel.hpp\"\
    \n\n// parallel\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    bool is_parallel(const Line &l1, const Line &l2) { return sign(cross(l1.b - l1.a,\
    \ l2.b - l2.a)) == 0; }\n#line 14 \"geometry/all.hpp\"\n\n#line 2 \"geometry/is_intersect_ll.hpp\"\
    \n\n#line 4 \"geometry/is_intersect_ll.hpp\"\n\n// intersection (line and line)\n\
    bool is_intersect_ll(const Line &l1, const Line &l2) {\n    Point base = l1.b\
    \ - l1.a;\n    Double d12 = cross(base, l2.b - l2.a);\n    Double d1 = cross(base,\
    \ l1.b - l2.a);\n    if (sign(d12) == 0) {\n        // parallel\n        if (sign(d1)\
    \ == 0) {\n            // cross\n            return true;\n        } else {\n\
    \            // not cross\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n#line 2 \"geometry/is_intersect_lp.hpp\"\n\n#line 5 \"geometry/is_intersect_lp.hpp\"\
    \n\n// intersection (line and point)\n// ccw(a, b, c) == ON_SEGMENT or ONLINE_BACK\
    \ or ONLINE_FRONT\nbool is_intersect_lp(const Line &l, const Point &p) {\n   \
    \ int res = ccw(l.a, l.b, p);\n    return (res == ONLINE_BACK or res == ONLINE_FRONT\
    \ or res == ON_SEGMENT);\n}\n#line 2 \"geometry/is_intersect_ss.hpp\"\n\n#line\
    \ 5 \"geometry/is_intersect_ss.hpp\"\n\n// intersection (segment and segment)\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B\nbool is_intersect_ss(const\
    \ Segment &s1, const Segment &s2) { return (ccw(s1.a, s1.b, s2.a) * ccw(s1.a,\
    \ s1.b, s2.b) <= 0 and ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0); }\n\
    #line 2 \"geometry/is_intersect_sp.hpp\"\n\n#line 5 \"geometry/is_intersect_sp.hpp\"\
    \n\n// intersection (segment and point)\n// ccw(a, b, c) == ON_SEGMENT -> a -\
    \ c - b\nbool is_intersect_sp(const Segment &s, const Point &p) { return ccw(s.a,\
    \ s.b, p) == ON_SEGMENT; }\n#line 3 \"geometry/tangent_number_cc.hpp\"\n// return\
    \ the number of tangent\nint tangent_number_cc(Circle c1, Circle c2) {\n    if\
    \ (c1.r < c2.r) std::swap(c1, c2);\n    Double d = std::abs(c1.o - c2.o);\n  \
    \  if (c1.r + c2.r < d) return 4;\n    if (equal(c1.r + c2.r, d)) return 3;\n\
    \    if (c1.r - c2.r < d) return 2;\n    if (equal(c1.r - c2.r, d)) return 1;\n\
    \    return 0;\n}\n#line 2 \"geometry/is_intersect_cc.hpp\"\n\n#line 5 \"geometry/is_intersect_cc.hpp\"\
    \n// intersection (circle and circle)\n// intersect = number of tangent is 1,\
    \ 2, 3\nbool is_intersect_cc(const Circle &c1, const Circle &c2) {\n    int num\
    \ = tangent_number_cc(c1, c2);\n    return 1 <= num and num <= 3;\n}\n#line 2\
    \ \"geometry/is_intersect_cp.hpp\"\n\n#line 5 \"geometry/is_intersect_cp.hpp\"\
    \n// intersection (circle and point)\nbool is_intersect_cp(const Circle &c, const\
    \ Point &p) { return equal(std::abs(p - c.o), c.r); }\n#line 22 \"geometry/all.hpp\"\
    \n\n#line 2 \"geometry/cross_point_ll.hpp\"\n\n#line 4 \"geometry/cross_point_ll.hpp\"\
    \n\n// cross point (line and line)\nPoint cross_point_ll(const Line &l1, const\
    \ Line &l2) {\n    Point base = l1.b - l1.a;\n    Double d12 = cross(base, l2.b\
    \ - l2.a);\n    Double d1 = cross(base, l1.b - l2.a);\n    if (sign(d12) == 0)\
    \ {\n        // parallel\n        if (sign(d1) == 0) {\n            // cross\n\
    \            return l2.a;\n        } else {\n            // not cross\n      \
    \      assert(false);\n        }\n    }\n    return l2.a + (l2.b - l2.a) * (d1\
    \ / d12);\n}\n#line 2 \"geometry/cross_point_ss.hpp\"\n\n#line 6 \"geometry/cross_point_ss.hpp\"\
    \n\n// cross point (segment and segment)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\n\
    Point cross_point_ss(const Segment &s1, const Segment &s2) {\n    // check intersection\
    \ s1 and s2\n    assert(is_intersect_ss(s1, s2));\n    Point base = s1.b - s1.a;\n\
    \    Double d12 = cross(base, s2.b - s2.a);\n    Double d1 = cross(base, s1.b\
    \ - s2.a);\n    if (sign(d12) == 0) {\n        // parallel\n        if (sign(d1)\
    \ == 0) {\n            // equal\n            if (is_intersect_sp(s1, s2.a)) return\
    \ s2.a;\n            if (is_intersect_sp(s1, s2.b)) return s2.b;\n           \
    \ if (is_intersect_sp(s2, s1.a)) return s1.a;\n            assert(is_intersect_sp(s2,\
    \ s1.b));\n            return s1.b;\n        } else {\n            // excepted\
    \ by is_intersect_ss(s1, s2)\n            assert(0);\n        }\n    }\n    return\
    \ s2.a + (s2.b - s2.a) * (d1 / d12);\n}\n#line 25 \"geometry/all.hpp\"\n"
  code: '#pragma once

    #include "geometry/geometry_template.hpp"


    #include "geometry/point.hpp"

    #include "geometry/line.hpp"

    #include "geometry/segment.hpp"

    #include "geometry/circle.hpp"


    #include "geometry/projection.hpp"

    #include "geometry/reflection.hpp"

    #include "geometry/ccw.hpp"

    #include "geometry/is_orthogonal.hpp"

    #include "geometry/is_parallel.hpp"


    #include "geometry/is_intersect_ll.hpp"

    #include "geometry/is_intersect_lp.hpp"

    #include "geometry/is_intersect_ss.hpp"

    #include "geometry/is_intersect_sp.hpp"

    #include "geometry/tangent_number_cc.hpp"

    #include "geometry/is_intersect_cc.hpp"

    #include "geometry/is_intersect_cp.hpp"


    #include "geometry/cross_point_ll.hpp"

    #include "geometry/cross_point_ss.hpp"

    '
  dependsOn:
  - geometry/geometry_template.hpp
  - geometry/point.hpp
  - geometry/line.hpp
  - geometry/segment.hpp
  - geometry/circle.hpp
  - geometry/projection.hpp
  - geometry/reflection.hpp
  - geometry/ccw.hpp
  - geometry/is_orthogonal.hpp
  - geometry/is_parallel.hpp
  - geometry/is_intersect_ll.hpp
  - geometry/is_intersect_lp.hpp
  - geometry/is_intersect_ss.hpp
  - geometry/is_intersect_sp.hpp
  - geometry/tangent_number_cc.hpp
  - geometry/is_intersect_cc.hpp
  - geometry/is_intersect_cp.hpp
  - geometry/cross_point_ll.hpp
  - geometry/cross_point_ss.hpp
  isVerificationFile: false
  path: geometry/all.hpp
  requiredBy: []
  timestamp: '2023-02-17 12:54:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/all.hpp
layout: document
redirect_from:
- /library/geometry/all.hpp
- /library/geometry/all.hpp.html
title: geometry/all.hpp
---
