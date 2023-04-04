---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':x:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':x:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':x:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':x:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj_cgl/aoj_cgl_7_f.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
  bundledCode: "#line 2 \"geometry/tangent_point_cp.hpp\"\n\n#line 2 \"geometry/cross_point_cc.hpp\"\
    \n\n#line 2 \"geometry/is_intersect_cc.hpp\"\n\n#line 2 \"geometry/circle.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\
    \n\n// template\nusing Double = double;\nconst Double EPS = 1e-8;\n// using Double\
    \ = long double;\n// const Double EPS = 1e-10;\n// using Double = long long;\n\
    // const Double EPS = 0;\n// using Double = __int128_t;\n// const Double EPS =\
    \ 0;\nconst Double PI = std::acos(Double(-1));\ninline int sign(const Double &x)\
    \ { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }\ninline bool equal(const Double\
    \ &a, const Double &b) { return sign(a - b) == 0; }\ninline Double radian_to_degree(const\
    \ Double &r) { return r * 180.0 / PI; }\ninline Double degree_to_radian(const\
    \ Double &d) { return d * PI / 180.0; }\nconstexpr int IN = 2;\nconstexpr int\
    \ ON = 1;\nconstexpr int OUT = 0;\n#line 4 \"geometry/point.hpp\"\n\n// point\n\
    struct Point {\n    Double x, y;\n    Point(const Double x = Double(0), const\
    \ Double y = Double(0)) : x(x), y(y) {}\n    Point &operator+=(const Point &p)\
    \ {\n        x += p.x;\n        y += p.y;\n        return *this;\n    }\n    Point\
    \ &operator-=(const Point &p) {\n        x -= p.x;\n        y -= p.y;\n      \
    \  return *this;\n    }\n    Point &operator*=(const Point &p) { return *this\
    \ = Point(x * p.x - y * p.y, x * p.y + y * p.x); }\n    Point &operator*=(const\
    \ Double &k) {\n        x *= k;\n        y *= k;\n        return *this;\n    }\n\
    \    Point &operator/=(const Point &p) { return *this = Point(x * p.x + y * p.y,\
    \ -x * p.y + y * p.x) / norm(p); }\n    Point &operator/=(const Double &k) {\n\
    \        x /= k;\n        y /= k;\n        return *this;\n    }\n\n    Point operator+()\
    \ const { return *this; }\n    Point operator-() const { return Point(-x, -y);\
    \ }\n\n    friend Point operator+(const Point &a, const Point &b) { return Point(a)\
    \ += b; }\n    friend Point operator-(const Point &a, const Point &b) { return\
    \ Point(a) -= b; }\n    friend Point operator*(const Point &a, const Point &b)\
    \ { return Point(a) *= b; }\n    friend Point operator*(const Point &p, const\
    \ Double &k) { return Point(p) *= k; }\n    friend Point operator/(const Point\
    \ &a, const Point &b) { return Point(a) /= b; }\n    friend Point operator/(const\
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
    \ { return rotate(Point(rho, 0), theta); }\n#line 4 \"geometry/circle.hpp\"\n\n\
    // circle\nstruct Circle {\n    Point o;\n    Double r;\n\n    Circle() = default;\n\
    \n    Circle(const Point &o, const Double &r) : o(o), r(r) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Circle &c) { return os << c.o << ' ' <<\
    \ c.r; }\n    friend std::istream &operator>>(std::istream &is, Circle &c) { return\
    \ is >> c.o >> c.r; }  // format : x y r\n};\n#line 3 \"geometry/tangent_number_cc.hpp\"\
    \n\n// return the number of tangent\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\n\
    int tangent_number_cc(Circle c1, Circle c2) {\n    if (c1.r < c2.r) std::swap(c1,\
    \ c2);\n    const Double d2 = norm(c1.o - c2.o);\n    if (sign(d2 - (c1.r + c2.r)\
    \ * (c1.r + c2.r)) == 1) return 4;  // d > c1.r + c2.r and c1.r + c2.r >= 0 <=>\
    \ d * d > (c1.r + c2.r) * (c1.r + c2.r)\n    if (sign(d2 - (c1.r + c2.r) * (c1.r\
    \ + c2.r)) == 0) return 3;  // d = c1.r + c2.r and c1.r + c2.r >= 0 <=> d * d\
    \ = (c1.r + c2.r) * (c1.r + c2.r)\n    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r))\
    \ == 1) return 2;  // d > c1.r - c2.r and c1.r - c2.r >= 0 <=> d * d > (c1.r -\
    \ c2.r) * (c1.r - c2.r)\n    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r)) == 0)\
    \ return 1;  // d = c1.r - c2.r and c1.r - c2.r >= 0 <=> d * d = (c1.r - c2.r)\
    \ * (c1.r - c2.r)\n    return 0;\n}\n#line 5 \"geometry/is_intersect_cc.hpp\"\n\
    \n// intersection (circle and circle)\n// intersect = number of tangent is 1,\
    \ 2, 3\ninline bool is_intersect_cc(const Circle &c1, const Circle &c2) {\n  \
    \  int num = tangent_number_cc(c1, c2);\n    return 1 <= num and num <= 3;\n}\n\
    #line 4 \"geometry/cross_point_cc.hpp\"\n\n// cross point (circle and circle)\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E\nstd::vector<Point>\
    \ cross_point_cc(const Circle &c1, const Circle &c2) {\n    if (!is_intersect_cc(c1,\
    \ c2)) return {};\n    Double d = abs(c1.o - c2.o);\n    Double a = std::acos((norm(c1.r)\
    \ - norm(c2.r) + norm(d)) / (Double(2) * c1.r * d));\n    Double t = arg(c2.o\
    \ - c1.o);\n    Point p = c1.o + polar(c1.r, t + a);\n    Point q = c1.o + polar(c1.r,\
    \ t - a);\n    if (equal(p.x, q.x) and equal(p.y, q.y)) return {p};\n    return\
    \ {p, q};\n}\n#line 4 \"geometry/tangent_point_cp.hpp\"\n\n// tangent point (circle\
    \ and point)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\n\
    std::pair<Point, Point> tangent_point_cp(const Circle &c, const Point &p) {\n\
    \    assert(sign(std::abs(c.o - p) - c.r) == 1);\n    auto res = cross_point_cc(c,\
    \ Circle(p, sqrt(norm(c.o - p) - norm(c.r))));\n    return {res[0], res[1]};\n\
    }\n"
  code: "#pragma once\n\n#include \"geometry/cross_point_cc.hpp\"\n\n// tangent point\
    \ (circle and point)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\n\
    std::pair<Point, Point> tangent_point_cp(const Circle &c, const Point &p) {\n\
    \    assert(sign(std::abs(c.o - p) - c.r) == 1);\n    auto res = cross_point_cc(c,\
    \ Circle(p, sqrt(norm(c.o - p) - norm(c.r))));\n    return {res[0], res[1]};\n\
    }"
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
  timestamp: '2023-04-04 18:27:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_7_f.test.cpp
documentation_of: geometry/tangent_point_cp.hpp
layout: document
redirect_from:
- /library/geometry/tangent_point_cp.hpp
- /library/geometry/tangent_point_cp.hpp.html
title: geometry/tangent_point_cp.hpp
---
