---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_ll.hpp
    title: geometry/cross_point_ll.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_lp.hpp
    title: geometry/distance_lp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/incircle.hpp
    title: geometry/incircle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_7_b.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B\"\n#define ERROR\
    \ 0.000001\n\n#include <bits/stdc++.h>\n\n#line 2 \"geometry/incircle.hpp\"\n\n\
    #line 2 \"geometry/cross_point_ll.hpp\"\n\n#line 2 \"geometry/line.hpp\"\n\n#line\
    \ 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\n\n//\
    \ template\nusing Double = double;\nconst Double EPS = 1e-8;\nconst Double PI\
    \ = std::acos(-1);\ninline int sign(const Double &x) { return x <= -EPS ? -1 :\
    \ (x >= EPS ? 1 : 0); }\ninline bool equal(const Double &a, const Double &b) {\
    \ return sign(a - b) == 0; }\nDouble radian_to_degree(const Double &r) { return\
    \ r * 180.0 / PI; }\nDouble degree_to_radian(const Double &d) { return d * PI\
    \ / 180.0; }\n#line 4 \"geometry/point.hpp\"\n\n// point\nusing Point = std::complex<Double>;\n\
    std::istream &operator>>(std::istream &is, Point &p) {\n    Double x, y;\n   \
    \ is >> x >> y;\n    p = Point(x, y);\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
    \ &os, Point &p) {\n    os << std::fixed << std::setprecision(15);\n    return\
    \ os << p.real() << ' ' << p.imag();\n}\n\nnamespace std {\nbool operator<(const\
    \ Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real()\
    \ : a.imag() < b.imag(); }\n}  // namespace std\n\n// equal (point and point)\n\
    inline bool equal(const Point &a, const Point &b) { return equal(a.real(), b.real())\
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
    \   Line() = default;\n\n    Line(Point a, Point b) : a(a), b(b) {}\n\n    //\
    \ Ax + By = C\n    Line(Double A, Double B, Double C) {\n        assert(equal(A,\
    \ 0) and equal(B, 0));\n        if (equal(A, 0)) {\n            a = Point(0, C\
    \ / B), b = Point(1, C / B);\n        } else if (equal(B, 0)) {\n            a\
    \ = Point(C / A, 0), b = Point(C / A, 1);\n        } else if (equal(C, 0)) {\n\
    \            a = Point(0, 0), b = Point(1, B / A);\n        } else {\n       \
    \     a = Point(0, C / B), b = Point(C / A, 0);\n        }\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, Line &p) { return is >> p.a >> p.b;\
    \ }\n    friend std::ostream &operator<<(std::ostream &os, const Line &p) { return\
    \ os << p.a << \"->\" << p.b; }\n};\n#line 4 \"geometry/cross_point_ll.hpp\"\n\
    \n// cross point (line and line)\nPoint cross_point_ll(const Line &l1, const Line\
    \ &l2) {\n    Point base = l1.b - l1.a;\n    Double d12 = cross(base, l2.b - l2.a);\n\
    \    Double d1 = cross(base, l1.b - l2.a);\n    if (sign(d12) == 0) {\n      \
    \  // parallel\n        if (sign(d1) == 0) {\n            // cross\n         \
    \   return l2.a;\n        } else {\n            // not cross\n            assert(false);\n\
    \        }\n    }\n    return l2.a + (l2.b - l2.a) * (d1 / d12);\n}\n#line 2 \"\
    geometry/distance_lp.hpp\"\n\n#line 2 \"geometry/projection.hpp\"\n\n#line 5 \"\
    geometry/projection.hpp\"\n\n// projection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    Point projection(const Line &l, const Point &p) {\n    Double t = dot(p - l.a,\
    \ l.b - l.a) / std::norm(l.b - l.a);\n    return l.a + t * (l.b - l.a);\n}\n#line\
    \ 6 \"geometry/distance_lp.hpp\"\n\n// distance (line and point)\nDouble distance_lp(const\
    \ Line &l, const Point &p) { return std::abs(p - projection(l, p)); }\n#line 5\
    \ \"geometry/incircle.hpp\"\n\n// incircle of a triangle\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B\n\
    // https://drken1215.hatenablog.com/entry/2020/10/16/073700\nstd::pair<Point,\
    \ Double> incircle(const Point &a, const Point &b, const Point &c) {\n    Double\
    \ A = std::arg((c - a) / (b - a)), B = std::arg((a - b) / (c - b));\n    Line\
    \ l1(a, a + rotate(b - a, A / 2)), l2(b, b + rotate(c - b, B / 2));\n    auto\
    \ o = cross_point_ll(l1, l2);\n    auto r = distance_lp(Line(a, b), o);\n    return\
    \ {o, r};\n}\n#line 7 \"verify/aoj_cgl/aoj_cgl_7_b.test.cpp\"\n\nint main() {\n\
    \    Point a, b, c;\n    std::cin >> a >> b >> c;\n    auto [p, r] = incircle(a,\
    \ b, c);\n    std::cout << p << ' ' << r << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B\"\
    \n#define ERROR 0.000001\n\n#include <bits/stdc++.h>\n\n#include \"geometry/incircle.hpp\"\
    \n\nint main() {\n    Point a, b, c;\n    std::cin >> a >> b >> c;\n    auto [p,\
    \ r] = incircle(a, b, c);\n    std::cout << p << ' ' << r << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - geometry/incircle.hpp
  - geometry/cross_point_ll.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/distance_lp.hpp
  - geometry/projection.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_7_b.test.cpp
  requiredBy: []
  timestamp: '2023-02-21 18:42:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_7_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_7_b.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_7_b.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_7_b.test.cpp
---
