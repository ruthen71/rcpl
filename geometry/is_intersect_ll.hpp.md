---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_parallel.hpp
    title: geometry/is_parallel.hpp
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/is_intersect_ll.hpp\"\n\n#line 2 \"geometry/line.hpp\"\
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
    \ sin(theta)); }\n#line 4 \"geometry/line.hpp\"\n\n// line\nstruct Line {\n  \
    \  Point a, b;\n\n    Line() = default;\n\n    Line(Point a, Point b) : a(a),\
    \ b(b) {}\n\n    // Ax + By = C\n    Line(Double A, Double B, Double C) {\n  \
    \      assert(equal(A, 0) and equal(B, 0));\n        if (equal(A, 0)) {\n    \
    \        a = Point(0, C / B), b = Point(1, C / B);\n        } else if (equal(B,\
    \ 0)) {\n            a = Point(C / A, 0), b = Point(C / A, 1);\n        } else\
    \ if (equal(C, 0)) {\n            a = Point(0, 0), b = Point(1, B / A);\n    \
    \    } else {\n            a = Point(0, C / B), b = Point(C / A, 0);\n       \
    \ }\n    }\n\n    friend std::istream &operator>>(std::istream &is, Line &p) {\
    \ return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 2 \"geometry/is_parallel.hpp\"\
    \n\n#line 4 \"geometry/is_parallel.hpp\"\n\n// parallel\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    bool is_parallel(const Line &l1, const Line &l2) { return sign(cross(l1.b - l1.a,\
    \ l2.b - l2.a)) == 0; }\n#line 5 \"geometry/is_intersect_ll.hpp\"\n\n// intersection\
    \ (line and line)\nbool is_intersect_ll(const Line &l1, const Line &l2) {\n  \
    \  Point base = l1.b - l1.a;\n    Double d12 = cross(base, l2.b - l2.a);\n   \
    \ Double d1 = cross(base, l1.b - l2.a);\n    if (sign(d12) == 0) {\n        //\
    \ parallel\n        if (sign(d1) == 0) {\n            // cross\n            return\
    \ true;\n        } else {\n            // not cross\n            return false;\n\
    \        }\n    }\n    return true;\n}\n"
  code: "#pragma once\n\n#include \"geometry/line.hpp\"\n#include \"geometry/is_parallel.hpp\"\
    \n\n// intersection (line and line)\nbool is_intersect_ll(const Line &l1, const\
    \ Line &l2) {\n    Point base = l1.b - l1.a;\n    Double d12 = cross(base, l2.b\
    \ - l2.a);\n    Double d1 = cross(base, l1.b - l2.a);\n    if (sign(d12) == 0)\
    \ {\n        // parallel\n        if (sign(d1) == 0) {\n            // cross\n\
    \            return true;\n        } else {\n            // not cross\n      \
    \      return false;\n        }\n    }\n    return true;\n}"
  dependsOn:
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/is_parallel.hpp
  isVerificationFile: false
  path: geometry/is_intersect_ll.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2023-02-17 09:50:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/is_intersect_ll.hpp
layout: document
redirect_from:
- /library/geometry/is_intersect_ll.hpp
- /library/geometry/is_intersect_ll.hpp.html
title: geometry/is_intersect_ll.hpp
---
