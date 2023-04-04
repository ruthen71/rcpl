---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_ll.hpp
    title: geometry/cross_point_ll.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C
    - https://drken1215.hatenablog.com/entry/2020/10/16/074400
  bundledCode: "#line 2 \"geometry/circumscribed_circle.hpp\"\n\n#line 2 \"geometry/cross_point_ll.hpp\"\
    \n\n#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n#line 2\
    \ \"geometry/geometry_template.hpp\"\n\n// template\nusing Double = double;\n\
    const Double EPS = 1e-8;\n// using Double = long double;\n// const Double EPS\
    \ = 1e-10;\n// using Double = long long;\n// const Double EPS = 0;\n// using Double\
    \ = __int128_t;\n// const Double EPS = 0;\nconst Double PI = std::acos(Double(-1));\n\
    inline int sign(const Double &x) { return x < -EPS ? -1 : (x > EPS ? 1 : 0); }\n\
    inline bool equal(const Double &a, const Double &b) { return sign(a - b) == 0;\
    \ }\ninline Double radian_to_degree(const Double &r) { return r * 180.0 / PI;\
    \ }\ninline Double degree_to_radian(const Double &d) { return d * PI / 180.0;\
    \ }\nconstexpr int IN = 2;\nconstexpr int ON = 1;\nconstexpr int OUT = 0;\n#line\
    \ 4 \"geometry/point.hpp\"\n\n// point\nstruct Point {\n    Double x, y;\n   \
    \ Point(const Double x = Double(0), const Double y = Double(0)) : x(x), y(y) {}\n\
    \    Point &operator+=(const Point &p) {\n        x += p.x;\n        y += p.y;\n\
    \        return *this;\n    }\n    Point &operator-=(const Point &p) {\n     \
    \   x -= p.x;\n        y -= p.y;\n        return *this;\n    }\n    Point &operator*=(const\
    \ Point &p) { return *this = Point(x * p.x - y * p.y, x * p.y + y * p.x); }\n\
    \    Point &operator*=(const Double &k) {\n        x *= k;\n        y *= k;\n\
    \        return *this;\n    }\n    Point &operator/=(const Point &p) { return\
    \ *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / (p.x * p.x + p.y * p.y);\
    \ }\n    Point &operator/=(const Double &k) {\n        x /= k;\n        y /= k;\n\
    \        return *this;\n    }\n\n    Point operator+() const { return *this; }\n\
    \    Point operator-() const { return Point(-x, -y); }\n\n    friend Point operator+(const\
    \ Point &a, const Point &b) { return Point(a) += b; }\n    friend Point operator-(const\
    \ Point &a, const Point &b) { return Point(a) -= b; }\n    friend Point operator*(const\
    \ Point &a, const Point &b) { return Point(a) *= b; }\n    friend Point operator*(const\
    \ Point &p, const Double &k) { return Point(p) *= k; }\n    friend Point operator/(const\
    \ Point &a, const Point &b) { return Point(a) /= b; }\n    friend Point operator/(const\
    \ Point &p, const Double &k) { return Point(p) /= k; }\n    // for std::set, std::map,\
    \ compare_arg, ...\n    friend bool operator<(const Point &a, const Point &b)\
    \ { return a.x == b.x ? a.y < b.y : a.x < b.x; }\n};\n\n// using Point = std::complex<Double>;\n\
    std::istream &operator>>(std::istream &is, Point &p) { return is >> p.x >> p.y;\
    \ }\nstd::ostream &operator<<(std::ostream &os, const Point &p) { return os <<\
    \ std::fixed << std::setprecision(15) << p.x << ' ' << p.y; }\n\n// equal (point\
    \ and point)\ninline bool equal(const Point &a, const Point &b) { return equal(a.x,\
    \ b.x) and equal(a.y, b.y); }\n// inner product\ninline Double dot(const Point\
    \ &a, const Point &b) { return a.x * b.x + a.y * b.y; }\n// outer product\ninline\
    \ Double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x;\
    \ }\n// rotate Point p counterclockwise by theta radian\ninline Point rotate(const\
    \ Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }\n\
    // compare (x, y)\ninline bool compare_x(const Point &a, const Point &b) { return\
    \ equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x - b.x) < 0; }\n// compare (y,\
    \ x)\ninline bool compare_y(const Point &a, const Point &b) { return equal(a.y,\
    \ b.y) ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }\n// compare by arg (start\
    \ from 90.0000000001~)\ninline bool compare_arg(const Point &a, const Point &b)\
    \ {\n    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n    return\
    \ (Point(0, 0) < a) == (Point(0, 0) < b) ? a.x * b.y > a.y * b.x : a < b;\n}\n\
    // |p| ^ 2\ninline Double norm(const Point &p) { return p.x * p.x + p.y * p.y;\
    \ }\n// |p|\ninline Double abs(const Point &p) { return sqrt(norm(p)); }\n// arg\n\
    inline Double arg(const Point &p) { return std::atan2(p.y, p.x); }\n// polar\n\
    inline Point polar(const Double &rho, const Double &theta = Double(0)) { return\
    \ rotate(Point(rho, 0), theta); }\n#line 4 \"geometry/line.hpp\"\n\n// line\n\
    struct Line {\n    Point a, b;\n\n    Line() = default;\n\n    Line(const Point\
    \ &a, const Point &b) : a(a), b(b) {}\n\n    // Ax + By = C\n    Line(const Double\
    \ &A, const Double &B, const Double &C) {\n        assert(equal(A, 0) and equal(B,\
    \ 0));\n        if (equal(A, 0)) {\n            a = Point(0, C / B), b = Point(1,\
    \ C / B);\n        } else if (equal(B, 0)) {\n            a = Point(C / A, 0),\
    \ b = Point(C / A, 1);\n        } else if (equal(C, 0)) {\n            a = Point(0,\
    \ 0), b = Point(1, B / A);\n        } else {\n            a = Point(0, C / B),\
    \ b = Point(C / A, 0);\n        }\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Line &p) { return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 4 \"geometry/cross_point_ll.hpp\"\
    \n\n// cross point (line and line)\nPoint cross_point_ll(const Line &l1, const\
    \ Line &l2) {\n    Point base = l1.b - l1.a;\n    Double d12 = cross(base, l2.b\
    \ - l2.a);\n    Double d1 = cross(base, l1.b - l2.a);\n    if (sign(d12) == 0)\
    \ {\n        // parallel\n        if (sign(d1) == 0) {\n            // cross\n\
    \            return l2.a;\n        } else {\n            // not cross\n      \
    \      assert(false);\n        }\n    }\n    return l2.a + (l2.b - l2.a) * (d1\
    \ / d12);\n}\n#line 2 \"geometry/circle.hpp\"\n\n#line 4 \"geometry/circle.hpp\"\
    \n\n// circle\nstruct Circle {\n    Point o;\n    Double r;\n\n    Circle() =\
    \ default;\n\n    Circle(const Point &o, const Double &r) : o(o), r(r) {}\n\n\
    \    friend std::ostream &operator<<(std::ostream &os, const Circle &c) { return\
    \ os << c.o << ' ' << c.r; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Circle &c) { return is >> c.o >> c.r; }  // format : x y r\n};\n#line 5\
    \ \"geometry/circumscribed_circle.hpp\"\n\n// circumscribed circle of a triangle\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C\n// https://drken1215.hatenablog.com/entry/2020/10/16/074400\n\
    Circle circumscribed_circle(const Point &a, const Point &b, const Point &c) {\n\
    \    Line l1((a + b) / 2, (a + b) / 2 + rotate(b - a, PI / 2)), l2((b + c) / 2,\
    \ (b + c) / 2 + rotate(c - b, PI / 2));\n    auto o = cross_point_ll(l1, l2);\n\
    \    auto r = abs(o - a);\n    return Circle(o, r);\n}\n"
  code: "#pragma once\n\n#include \"geometry/cross_point_ll.hpp\"\n#include \"geometry/circle.hpp\"\
    \n\n// circumscribed circle of a triangle\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C\n\
    // https://drken1215.hatenablog.com/entry/2020/10/16/074400\nCircle circumscribed_circle(const\
    \ Point &a, const Point &b, const Point &c) {\n    Line l1((a + b) / 2, (a + b)\
    \ / 2 + rotate(b - a, PI / 2)), l2((b + c) / 2, (b + c) / 2 + rotate(c - b, PI\
    \ / 2));\n    auto o = cross_point_ll(l1, l2);\n    auto r = abs(o - a);\n   \
    \ return Circle(o, r);\n}"
  dependsOn:
  - geometry/cross_point_ll.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/circle.hpp
  isVerificationFile: false
  path: geometry/circumscribed_circle.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2023-04-04 19:34:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_7_c.test.cpp
documentation_of: geometry/circumscribed_circle.hpp
layout: document
redirect_from:
- /library/geometry/circumscribed_circle.hpp
- /library/geometry/circumscribed_circle.hpp.html
title: geometry/circumscribed_circle.hpp
---
