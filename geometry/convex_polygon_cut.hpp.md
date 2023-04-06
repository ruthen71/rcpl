---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/cross_point_ll.hpp
    title: geometry/cross_point_ll.hpp
  - icon: ':x:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':x:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
  bundledCode: "#line 2 \"geometry/convex_polygon_cut.hpp\"\n\n#line 2 \"geometry/polygon.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n// point\ntemplate <typename T> struct Point\
    \ {\n    static T EPS;\n    static const T PI = std::acos(T(-1));\n    static\
    \ void set_eps(const T &e) { EPS = e; }\n    T x, y;\n    Point(const T x = T(0),\
    \ const T y = T(0)) : x(x), y(y) {}\n    Point &operator+=(const Point &p) {\n\
    \        x += p.x;\n        y += p.y;\n        return *this;\n    }\n    Point\
    \ &operator-=(const Point &p) {\n        x -= p.x;\n        y -= p.y;\n      \
    \  return *this;\n    }\n    Point &operator*=(const Point &p) { return *this\
    \ = Point(x * p.x - y * p.y, x * p.y + y * p.x); }\n    Point &operator*=(const\
    \ T &k) {\n        x *= k;\n        y *= k;\n        return *this;\n    }\n  \
    \  Point &operator/=(const Point &p) { return *this = Point(x * p.x + y * p.y,\
    \ -x * p.y + y * p.x) / (p.x * p.x + p.y * p.y); }\n    Point &operator/=(const\
    \ T &k) {\n        x /= k;\n        y /= k;\n        return *this;\n    }\n\n\
    \    Point operator+() const { return *this; }\n    Point operator-() const {\
    \ return Point(-x, -y); }\n\n    friend Point operator+(const Point &a, const\
    \ Point &b) { return Point(a) += b; }\n    friend Point operator-(const Point\
    \ &a, const Point &b) { return Point(a) -= b; }\n    friend Point operator*(const\
    \ Point &a, const Point &b) { return Point(a) *= b; }\n    friend Point operator*(const\
    \ Point &p, const T &k) { return Point(p) *= k; }\n    friend Point operator/(const\
    \ Point &a, const Point &b) { return Point(a) /= b; }\n    friend Point operator/(const\
    \ Point &p, const T &k) { return Point(p) /= k; }\n    // for std::set, std::map,\
    \ compare_arg, ...\n    friend bool operator<(const Point &a, const Point &b)\
    \ { return a.x == b.x ? a.y < b.y : a.x < b.x; }\n    // I/O\n    friend std::istream\
    \ &operator>>(std::istream &is, Point &p) { return is >> p.x >> p.y; }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Point &p) { return os << '('\
    \ << p.x << ' ' << p.y << ')'; }\n};\n\n// template\ntemplate <typename T> inline\
    \ int sign(const T &x) { return x < -Point<T>::EPS ? -1 : (x > Point<T>::EPS ?\
    \ 1 : 0); }\ntemplate <typename T> inline bool equal(const T &a, const T &b) {\
    \ return sign(a - b) == 0; }\ntemplate <typename T> inline T radian_to_degree(const\
    \ T &r) { return r * 180.0 / Point<T>::PI; }\ntemplate <typename T> inline T degree_to_radian(const\
    \ T &d) { return d * Point<T>::PI / 180.0; }\n\n// contain enum\nconstexpr int\
    \ IN = 2;\nconstexpr int ON = 1;\nconstexpr int OUT = 0;\n\n// equal (point and\
    \ point)\ntemplate <typename T> inline bool equal(const Point<T> &a, const Point<T>\
    \ &b) { return equal(a.x, b.x) and equal(a.y, b.y); }\n// inner product\ntemplate\
    \ <typename T> inline T dot(const Point<T> &a, const Point<T> &b) { return a.x\
    \ * b.x + a.y * b.y; }\n// outer product\ntemplate <typename T> inline T cross(const\
    \ Point<T> &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }\n// rotate\
    \ Point p counterclockwise by theta radian\ntemplate <typename T> inline Point<T>\
    \ rotate(const Point<T> &p, const T &theta) { return p * Point<T>(std::cos(theta),\
    \ std::sin(theta)); }\n// compare (x, y)\ntemplate <typename T> inline bool compare_x(const\
    \ Point<T> &a, const Point<T> &b) { return equal(a.x, b.x) ? sign(a.y - b.y) <\
    \ 0 : sign(a.x - b.x) < 0; }\n// compare (y, x)\ntemplate <typename T> inline\
    \ bool compare_y(const Point<T> &a, const Point<T> &b) { return equal(a.y, b.y)\
    \ ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }\n// compare by arg (start from\
    \ 90.0000000001~)\ntemplate <typename T> inline bool compare_arg(const Point<T>\
    \ &a, const Point<T> &b) {\n    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n\
    \    return (Point<T>(0, 0) < a) == (Point<T>(0, 0) < b) ? a.x * b.y > a.y * b.x\
    \ : a < b;\n}\n// |p| ^ 2\ntemplate <typename T> inline T norm(const Point<T>\
    \ &p) { return p.x * p.x + p.y * p.y; }\n// |p|\ntemplate <typename T> inline\
    \ T abs(const Point<T> &p) { return std::sqrt(norm(p)); }\n// arg\ntemplate <typename\
    \ T> inline T arg(const Point<T> &p) { return std::atan2(p.y, p.x); }\n// polar\n\
    template <typename T> inline Point<T> polar(const T &rho, const T &theta = T(0))\
    \ { return rotate(Point<T>(rho, 0), theta); }\n// EPS\ntemplate <> double Point<double>::EPS\
    \ = 1e-9;\ntemplate <> long double Point<long double>::EPS = 1e-12;\ntemplate\
    \ <> long long Point<long long>::EPS = 0;\ntemplate <> __int128_t Point<__int128_t>::EPS\
    \ = 0;\n// change EPS\n// using Double = double;\n// using Pt = Point<Double>;\n\
    // Point<Double>::set_eps(new_eps);\n#line 4 \"geometry/polygon.hpp\"\n\n// polygon\n\
    template <typename T> using Polygon = std::vector<Point<T>>;\ntemplate <typename\
    \ T> std::istream &operator>>(std::istream &is, Polygon<T> &p) {\n    for (auto\
    \ &&pi : p) is >> pi;\n    return is;\n}\ntemplate <typename T> std::ostream &operator<<(std::ostream\
    \ &os, const Polygon<T> &p) {\n    for (auto &&pi : p) os << pi << \" -> \";\n\
    \    return os;\n}\n#line 2 \"geometry/cross_point_ll.hpp\"\n\n#line 2 \"geometry/line.hpp\"\
    \n\n#line 4 \"geometry/line.hpp\"\n\n// line\ntemplate <typename T> struct Line\
    \ {\n    Point<T> a, b;\n\n    Line() = default;\n\n    Line(const Point<T> &a,\
    \ const Point<T> &b) : a(a), b(b) {}\n\n    // Ax + By = C\n    Line(const T &A,\
    \ const T &B, const T &C) {\n        assert(equal(A, 0) and equal(B, 0));\n  \
    \      if (equal(A, 0)) {\n            a = Point<T>(0, C / B), b = Point<T>(1,\
    \ C / B);\n        } else if (equal(B, 0)) {\n            a = Point<T>(C / A,\
    \ 0), b = Point<T>(C / A, 1);\n        } else if (equal(C, 0)) {\n           \
    \ a = Point<T>(0, 0), b = Point<T>(1, B / A);\n        } else {\n            a\
    \ = Point<T>(0, C / B), b = Point<T>(C / A, 0);\n        }\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, Line &p) { return is >> p.a >> p.b;\
    \ }\n    friend std::ostream &operator<<(std::ostream &os, const Line &p) { return\
    \ os << p.a << \"->\" << p.b; }\n};\n#line 4 \"geometry/cross_point_ll.hpp\"\n\
    \n// cross point (line and line)\ntemplate <typename T> Point<T> cross_point_ll(const\
    \ Line<T> &l1, const Line<T> &l2) {\n    Point<T> base = l1.b - l1.a;\n    T d12\
    \ = cross(base, l2.b - l2.a);\n    T d1 = cross(base, l1.b - l2.a);\n    if (sign(d12)\
    \ == 0) {\n        // parallel\n        if (sign(d1) == 0) {\n            // cross\n\
    \            return l2.a;\n        } else {\n            // not cross\n      \
    \      assert(false);\n        }\n    }\n    return l2.a + (l2.b - l2.a) * (d1\
    \ / d12);\n}\n#line 5 \"geometry/convex_polygon_cut.hpp\"\n\n// cut convex polygon\
    \ p by line l\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\n\
    // return {left polygon, right polygon}\n// whether each point is included is\
    \ determined by the sign of the outer product of the two vectors to the endpoints\
    \ of the line\ntemplate <typename T> std::pair<Polygon<T>, Polygon<T>> convex_polygon_cut(const\
    \ Polygon<T> &p, const Line<T> &l) {\n    int n = (int)p.size();\n    assert(n\
    \ >= 3);\n    Polygon<T> pl, pr;\n    for (int i = 0; i < n; i++) {\n        int\
    \ s1 = sign(cross(l.a - p[i], l.b - p[i]));\n        int s2 = sign(cross(l.a -\
    \ p[i + 1 == n ? 0 : i + 1], l.b - p[i + 1 == n ? 0 : i + 1]));\n        if (s1\
    \ >= 0) {\n            pl.push_back(p[i]);\n        }\n        if (s1 <= 0) {\n\
    \            pr.push_back(p[i]);\n        }\n        if (s1 * s2 < 0) {\n    \
    \        // don't use \"<=\", use \"<\" to exclude endpoints\n            auto\
    \ pc = cross_point_ll(Line(p[i], p[i + 1 == n ? 0 : i + 1]), l);\n           \
    \ pl.push_back(pc);\n            pr.push_back(pc);\n        }\n    }\n    return\
    \ {pl, pr};\n}\n"
  code: "#pragma once\n\n#include \"geometry/polygon.hpp\"\n#include \"geometry/cross_point_ll.hpp\"\
    \n\n// cut convex polygon p by line l\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\n\
    // return {left polygon, right polygon}\n// whether each point is included is\
    \ determined by the sign of the outer product of the two vectors to the endpoints\
    \ of the line\ntemplate <typename T> std::pair<Polygon<T>, Polygon<T>> convex_polygon_cut(const\
    \ Polygon<T> &p, const Line<T> &l) {\n    int n = (int)p.size();\n    assert(n\
    \ >= 3);\n    Polygon<T> pl, pr;\n    for (int i = 0; i < n; i++) {\n        int\
    \ s1 = sign(cross(l.a - p[i], l.b - p[i]));\n        int s2 = sign(cross(l.a -\
    \ p[i + 1 == n ? 0 : i + 1], l.b - p[i + 1 == n ? 0 : i + 1]));\n        if (s1\
    \ >= 0) {\n            pl.push_back(p[i]);\n        }\n        if (s1 <= 0) {\n\
    \            pr.push_back(p[i]);\n        }\n        if (s1 * s2 < 0) {\n    \
    \        // don't use \"<=\", use \"<\" to exclude endpoints\n            auto\
    \ pc = cross_point_ll(Line(p[i], p[i + 1 == n ? 0 : i + 1]), l);\n           \
    \ pl.push_back(pc);\n            pr.push_back(pc);\n        }\n    }\n    return\
    \ {pl, pr};\n}"
  dependsOn:
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/cross_point_ll.hpp
  - geometry/line.hpp
  isVerificationFile: false
  path: geometry/convex_polygon_cut.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2023-04-06 09:06:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_4_c.test.cpp
documentation_of: geometry/convex_polygon_cut.hpp
layout: document
redirect_from:
- /library/geometry/convex_polygon_cut.hpp
- /library/geometry/convex_polygon_cut.hpp.html
title: geometry/convex_polygon_cut.hpp
---
