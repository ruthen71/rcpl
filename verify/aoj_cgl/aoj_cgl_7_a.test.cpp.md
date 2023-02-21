---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_7_a.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"geometry/circle.hpp\"\n\n#line 2 \"geometry/point.hpp\"\
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
    \ }\n}  // namespace std\n\n// equal (point and point)\ninline bool equal(const\
    \ Point &a, const Point &b) { return equal(a.real(), b.real()) and equal(a.imag(),\
    \ b.imag()); }\n// inner product\ninline Double dot(const Point &a, const Point\
    \ &b) { return a.real() * b.real() + a.imag() * b.imag(); }\n// outer product\n\
    inline Double cross(const Point &a, const Point &b) { return a.real() * b.imag()\
    \ - a.imag() * b.real(); }\n// rotate Point p counterclockwise by theta radian\n\
    inline Point rotate(const Point &p, const Double &theta) { return p * Point(cos(theta),\
    \ sin(theta)); }\n// compare (x, y)\ninline bool compare_x(const Point &a, const\
    \ Point &b) { return equal(a.real(), b.real()) ? sign(a.imag() - b.imag()) < 0\
    \ : sign(a.real() - b.real()) < 0; }\n// compare (y, x)\ninline bool compare_y(const\
    \ Point &a, const Point &b) { return equal(a.imag(), b.imag()) ? sign(a.real()\
    \ - b.real()) < 0 : sign(a.imag() - b.imag()) < 0; }\n#line 4 \"geometry/circle.hpp\"\
    \n\n// circle\nstruct Circle {\n    Point o;\n    Double r;\n\n    Circle() =\
    \ default;\n\n    Circle(Point o, Double r) : o(o), r(r) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Circle &c) { return os << c.o << ' ' <<\
    \ c.r; }\n    friend std::istream &operator>>(std::istream &is, Circle &c) { return\
    \ is >> c.o >> c.r; }  // format : x y r\n};\n#line 3 \"geometry/tangent_number_cc.hpp\"\
    \n\n// return the number of tangent\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\n\
    int tangent_number_cc(Circle c1, Circle c2) {\n    if (c1.r < c2.r) std::swap(c1,\
    \ c2);\n    Double d = std::abs(c1.o - c2.o);\n    if (sign(d - c1.r - c2.r) ==\
    \ 1) return 4;  // d > c1.r + c2.r\n    if (sign(d - c1.r - c2.r) == 0) return\
    \ 3;  // d = c1.r + c2.r\n    if (sign(d - c1.r + c2.r) == 1) return 2;  // d\
    \ > c1.r - c2.r\n    if (sign(d - c1.r + c2.r) == 0) return 1;  // d = c1.r -\
    \ c2.r\n    return 0;\n}\n#line 6 \"verify/aoj_cgl/aoj_cgl_7_a.test.cpp\"\n\n\
    int main() {\n    Circle C1, C2;\n    std::cin >> C1 >> C2;\n    std::cout <<\
    \ tangent_number_cc(C1, C2) << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"geometry/tangent_number_cc.hpp\"\n\n\
    int main() {\n    Circle C1, C2;\n    std::cin >> C1 >> C2;\n    std::cout <<\
    \ tangent_number_cc(C1, C2) << '\\n';\n    return 0;\n}"
  dependsOn:
  - geometry/tangent_number_cc.hpp
  - geometry/circle.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
  requiredBy: []
  timestamp: '2023-02-21 18:01:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_7_a.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_7_a.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
---
