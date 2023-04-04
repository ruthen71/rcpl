---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':x:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':x:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':x:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  - icon: ':x:'
    path: geometry/cross_point_ss.hpp
    title: geometry/cross_point_ss.hpp
  - icon: ':x:'
    path: geometry/distance_sp.hpp
    title: geometry/distance_sp.hpp
  - icon: ':x:'
    path: geometry/distance_ss.hpp
    title: geometry/distance_ss.hpp
  - icon: ':x:'
    path: geometry/polygon_contain.hpp
    title: geometry/polygon_contain.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj_cgl/aoj_cgl_2_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_2_c.test.cpp
  - icon: ':x:'
    path: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
    title: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
  - icon: ':x:'
    path: verify/aoj_cgl/aoj_cgl_3_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_3_c.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/is_intersect_sp.hpp\"\n\n#line 2 \"geometry/segment.hpp\"\
    \n\n#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n#line 2\
    \ \"geometry/geometry_template.hpp\"\n\n// template\nusing Double = double;\n\
    const Double EPS = 1e-8;\n// using Double = long double;\n// const Double EPS\
    \ = 1e-10;\n// using Double = long long;\n// const Double EPS = 0;\n// using Double\
    \ = __int128_t;\n// const Double EPS = 0;\nconst Double PI = std::acos(Double(-1));\n\
    inline int sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0);\
    \ }\ninline bool equal(const Double &a, const Double &b) { return sign(a - b)\
    \ == 0; }\ninline Double radian_to_degree(const Double &r) { return r * 180.0\
    \ / PI; }\ninline Double degree_to_radian(const Double &d) { return d * PI / 180.0;\
    \ }\nconstexpr int IN = 2;\nconstexpr int ON = 1;\nconstexpr int OUT = 0;\n#line\
    \ 4 \"geometry/point.hpp\"\n\n// point\nstruct Point {\n    Double x, y;\n   \
    \ Point(const Double x = Double(0), const Double y = Double(0)) : x(x), y(y) {}\n\
    \    Point &operator+=(const Point &p) {\n        x += p.x;\n        y += p.y;\n\
    \        return *this;\n    }\n    Point &operator-=(const Point &p) {\n     \
    \   x -= p.x;\n        y -= p.y;\n        return *this;\n    }\n    Point &operator*=(const\
    \ Point &p) { return *this = Point(x * p.x - y * p.y, x * p.y + y * p.x); }\n\
    \    Point &operator*=(const Double &k) {\n        x *= k;\n        y *= k;\n\
    \        return *this;\n    }\n    Point &operator/=(const Point &p) { return\
    \ *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / norm(p); }\n    Point\
    \ &operator/=(const Double &k) {\n        x /= k;\n        y /= k;\n        return\
    \ *this;\n    }\n\n    Point operator+() const { return *this; }\n    Point operator-()\
    \ const { return Point(-x, -y); }\n\n    friend Point operator+(const Point &a,\
    \ const Point &b) { return Point(a) += b; }\n    friend Point operator-(const\
    \ Point &a, const Point &b) { return Point(a) -= b; }\n    friend Point operator*(const\
    \ Point &a, const Point &b) { return Point(a) *= b; }\n    friend Point operator*(const\
    \ Point &p, const Double &k) { return Point(p) *= k; }\n    friend Point operator/(const\
    \ Point &a, const Point &b) { return Point(a) /= b; }\n    friend Point operator/(const\
    \ Point &p, const Double &k) { return Point(p) /= k; }\n};\n\n// using Point =\
    \ std::complex<Double>;\nstd::istream &operator>>(std::istream &is, Point &p)\
    \ { return is >> p.x >> p.y; }\nstd::ostream &operator<<(std::ostream &os, const\
    \ Point &p) { return os << std::fixed << std::setprecision(15) << p.x << ' ' <<\
    \ p.y; }\n\n// for std::set, std::map, compare_arg, ...\nnamespace std {\ninline\
    \ bool operator<(const Point &a, const Point &b) { return a.x != b.x ? a.x < b.x\
    \ : a.y < b.y; }\n}  // namespace std\n\n// equal (point and point)\ninline bool\
    \ equal(const Point &a, const Point &b) { return equal(a.x, b.x) and equal(a.y,\
    \ b.y); }\n// inner product\ninline Double dot(const Point &a, const Point &b)\
    \ { return a.x * b.x + a.y * b.y; }\n// outer product\ninline Double cross(const\
    \ Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }\n// rotate Point\
    \ p counterclockwise by theta radian\ninline Point rotate(const Point &p, const\
    \ Double &theta) { return p * Point(cos(theta), sin(theta)); }\n// compare (x,\
    \ y)\ninline bool compare_x(const Point &a, const Point &b) { return equal(a.x,\
    \ b.x) ? sign(a.y - b.y) < 0 : sign(a.x - b.x) < 0; }\n// compare (y, x)\ninline\
    \ bool compare_y(const Point &a, const Point &b) { return equal(a.y, b.y) ? sign(a.x\
    \ - b.x) < 0 : sign(a.y - b.y) < 0; }\n// compare by arg (start from 90.0000000001~)\n\
    inline bool compare_arg(const Point &a, const Point &b) {\n    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n\
    \    return (Point(0, 0) < a) == (Point(0, 0) < b) ? a.x * b.y > a.y * b.x : a\
    \ < b;\n}\n// |p| ^ 2\ninline Double norm(const Point &p) { return p.x * p.x +\
    \ p.y * p.y; }\n// |p|\ninline Double abs(const Point &p) { return sqrt(norm(p));\
    \ }\n// arg\ninline Double arg(const Point &p) { return std::atan2(p.y, p.x);\
    \ }\n// polar\ninline Point polar(const Double &rho, const Double &theta = Double(0))\
    \ { return rotate(Point(rho, 0), theta); }\n#line 4 \"geometry/line.hpp\"\n\n\
    // line\nstruct Line {\n    Point a, b;\n\n    Line() = default;\n\n    Line(const\
    \ Point &a, const Point &b) : a(a), b(b) {}\n\n    // Ax + By = C\n    Line(const\
    \ Double &A, const Double &B, const Double &C) {\n        assert(equal(A, 0) and\
    \ equal(B, 0));\n        if (equal(A, 0)) {\n            a = Point(0, C / B),\
    \ b = Point(1, C / B);\n        } else if (equal(B, 0)) {\n            a = Point(C\
    \ / A, 0), b = Point(C / A, 1);\n        } else if (equal(C, 0)) {\n         \
    \   a = Point(0, 0), b = Point(1, B / A);\n        } else {\n            a = Point(0,\
    \ C / B), b = Point(C / A, 0);\n        }\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Line &p) { return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 4 \"geometry/segment.hpp\"\
    \n\n// segment\nstruct Segment : Line {\n    Segment() = default;\n\n    Segment(const\
    \ Point &a, const Point &b) : Line(a, b) {}\n};\n#line 2 \"geometry/ccw.hpp\"\n\
    \n#line 4 \"geometry/ccw.hpp\"\n\n// counter clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int\
    \ CLOCKWISE = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2; \
    \       // c-a-b line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr\
    \ int ON_SEGMENT = 0;         // a-c-b line\nint ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b, c)) == 1) return\
    \ COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return CLOCKWISE;\n   \
    \ if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (norm(b) < norm(c)) return\
    \ ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n#line 5 \"geometry/is_intersect_sp.hpp\"\
    \n\n// intersection (segment and point)\n// ccw(a, b, c) == ON_SEGMENT -> a -\
    \ c - b\ninline bool is_intersect_sp(const Segment &s, const Point &p) { return\
    \ ccw(s.a, s.b, p) == ON_SEGMENT or sign(norm(s.a - p)) == 0 or sign(norm(s.b\
    \ - p)) == 0; }\n"
  code: '#pragma once


    #include "geometry/segment.hpp"

    #include "geometry/ccw.hpp"


    // intersection (segment and point)

    // ccw(a, b, c) == ON_SEGMENT -> a - c - b

    inline bool is_intersect_sp(const Segment &s, const Point &p) { return ccw(s.a,
    s.b, p) == ON_SEGMENT or sign(norm(s.a - p)) == 0 or sign(norm(s.b - p)) == 0;
    }'
  dependsOn:
  - geometry/segment.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/ccw.hpp
  isVerificationFile: false
  path: geometry/is_intersect_sp.hpp
  requiredBy:
  - geometry/distance_ss.hpp
  - geometry/polygon_contain.hpp
  - geometry/cross_point_ss.hpp
  - geometry/all.hpp
  - geometry/distance_sp.hpp
  timestamp: '2023-04-04 18:27:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_2_d.test.cpp
  - verify/aoj_cgl/aoj_cgl_3_c.test.cpp
  - verify/aoj_cgl/aoj_cgl_2_c.test.cpp
documentation_of: geometry/is_intersect_sp.hpp
layout: document
redirect_from:
- /library/geometry/is_intersect_sp.hpp
- /library/geometry/is_intersect_sp.hpp.html
title: geometry/is_intersect_sp.hpp
---
