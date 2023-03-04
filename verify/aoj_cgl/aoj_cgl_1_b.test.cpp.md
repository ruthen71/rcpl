---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':question:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: geometry/reflection.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_1_b.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\"\n#define ERROR\
    \ 0.00000001\n\n#include <bits/stdc++.h>\n\n#line 2 \"geometry/reflection.hpp\"\
    \n\n#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n#line 2\
    \ \"geometry/geometry_template.hpp\"\n\n// template\nusing Double = double;\n\
    const Double EPS = 1e-10;\nconst Double PI = std::acos(Double(-1));\ninline int\
    \ sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }\ninline\
    \ bool equal(const Double &a, const Double &b) { return sign(a - b) == 0; }\n\
    inline Double radian_to_degree(const Double &r) { return r * 180.0 / PI; }\ninline\
    \ Double degree_to_radian(const Double &d) { return d * PI / 180.0; }\n#line 4\
    \ \"geometry/point.hpp\"\n\n// point\nusing Point = std::complex<Double>;\nstd::istream\
    \ &operator>>(std::istream &is, Point &p) {\n    Double x, y;\n    is >> x >>\
    \ y;\n    p = Point(x, y);\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
    \ &os, const Point &p) {\n    os << std::fixed << std::setprecision(15);\n   \
    \ return os << p.real() << ' ' << p.imag();\n}\n\n// for std::set, std::map, ...\n\
    namespace std {\ninline bool operator<(const Point &a, const Point &b) { return\
    \ a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }\n}  // namespace\
    \ std\n\ninline Point operator*(const Point &p, const Double &k) { return Point(p.real()\
    \ * k, p.imag() * k); }\ninline Point operator/(const Point &p, const Double &k)\
    \ { return Point(p.real() / k, p.imag() / k); }\n// equal (point and point)\n\
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
    \   Line() = default;\n\n    Line(const Point &a, const Point &b) : a(a), b(b)\
    \ {}\n\n    // Ax + By = C\n    Line(const Double &A, const Double &B, const Double\
    \ &C) {\n        assert(equal(A, 0) and equal(B, 0));\n        if (equal(A, 0))\
    \ {\n            a = Point(0, C / B), b = Point(1, C / B);\n        } else if\
    \ (equal(B, 0)) {\n            a = Point(C / A, 0), b = Point(C / A, 1);\n   \
    \     } else if (equal(C, 0)) {\n            a = Point(0, 0), b = Point(1, B /\
    \ A);\n        } else {\n            a = Point(0, C / B), b = Point(C / A, 0);\n\
    \        }\n    }\n\n    friend std::istream &operator>>(std::istream &is, Line\
    \ &p) { return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 2 \"geometry/projection.hpp\"\
    \n\n#line 5 \"geometry/projection.hpp\"\n\n// projection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    Point projection(const Line &l, const Point &p) {\n    Double t = dot(p - l.a,\
    \ l.b - l.a) / std::norm(l.b - l.a);\n    return l.a + t * (l.b - l.a);\n}\n#line\
    \ 6 \"geometry/reflection.hpp\"\n\n// reflection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\n\
    Point reflection(const Line &l, const Point &p) { return p + (projection(l, p)\
    \ - p) * Double(2.0); }\n#line 7 \"verify/aoj_cgl/aoj_cgl_1_b.test.cpp\"\n\nint\
    \ main() {\n    Line L;\n    std::cin >> L;\n    int Q;\n    std::cin >> Q;\n\
    \    while (Q--) {\n        Point P;\n        std::cin >> P;\n        auto ans\
    \ = reflection(L, P);\n        std::cout << ans << '\\n';\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\"\
    \n#define ERROR 0.00000001\n\n#include <bits/stdc++.h>\n\n#include \"geometry/reflection.hpp\"\
    \n\nint main() {\n    Line L;\n    std::cin >> L;\n    int Q;\n    std::cin >>\
    \ Q;\n    while (Q--) {\n        Point P;\n        std::cin >> P;\n        auto\
    \ ans = reflection(L, P);\n        std::cout << ans << '\\n';\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - geometry/reflection.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/projection.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_1_b.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 00:14:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_1_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_1_b.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_1_b.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_1_b.test.cpp
---