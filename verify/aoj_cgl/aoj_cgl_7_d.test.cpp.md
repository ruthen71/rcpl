---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cl.hpp
    title: geometry/cross_point_cl.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_lp.hpp
    title: geometry/distance_lp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cl.hpp
    title: geometry/is_intersect_cl.hpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_7_d.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\"\n#define ERROR\
    \ 0.000001\n\n#include <bits/stdc++.h>\n\n#line 2 \"geometry/cross_point_cl.hpp\"\
    \n\n#line 2 \"geometry/is_intersect_cl.hpp\"\n\n#line 2 \"geometry/distance_lp.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n// point\ntemplate <typename T> struct Point\
    \ {\n    static T EPS;\n    static constexpr T PI = 3.1415926535'8979323846'2643383279L;\n\
    \    static void set_eps(const T &e) { EPS = e; }\n    T x, y;\n    Point(const\
    \ T x = T(0), const T y = T(0)) : x(x), y(y) {}\n    Point &operator+=(const Point\
    \ &p) {\n        x += p.x;\n        y += p.y;\n        return *this;\n    }\n\
    \    Point &operator-=(const Point &p) {\n        x -= p.x;\n        y -= p.y;\n\
    \        return *this;\n    }\n    Point &operator*=(const Point &p) { return\
    \ *this = Point(x * p.x - y * p.y, x * p.y + y * p.x); }\n    Point &operator*=(const\
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
    \ { return a.x == b.x ? a.y < b.y : a.x < b.x; }\n    friend bool operator>(const\
    \ Point &a, const Point &b) { return a.x == b.x ? a.y > b.y : a.x > b.x; }\n \
    \   // I/O\n    friend std::istream &operator>>(std::istream &is, Point &p) {\
    \ return is >> p.x >> p.y; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Point &p) { return os << '(' << p.x << ' ' << p.y << ')'; }\n};\n\
    \n// template\ntemplate <typename T> inline int sign(const T &x) { return x <\
    \ -Point<T>::EPS ? -1 : (x > Point<T>::EPS ? 1 : 0); }\ntemplate <typename T>\
    \ inline bool equal(const T &a, const T &b) { return sign(a - b) == 0; }\ntemplate\
    \ <typename T> inline T radian_to_degree(const T &r) { return r * 180.0 / Point<T>::PI;\
    \ }\ntemplate <typename T> inline T degree_to_radian(const T &d) { return d *\
    \ Point<T>::PI / 180.0; }\n\n// contain enum\nconstexpr int IN = 2;\nconstexpr\
    \ int ON = 1;\nconstexpr int OUT = 0;\n\n// equal (point and point)\ntemplate\
    \ <typename T> inline bool equal(const Point<T> &a, const Point<T> &b) { return\
    \ equal(a.x, b.x) and equal(a.y, b.y); }\n// inner product\ntemplate <typename\
    \ T> inline T dot(const Point<T> &a, const Point<T> &b) { return a.x * b.x + a.y\
    \ * b.y; }\n// outer product\ntemplate <typename T> inline T cross(const Point<T>\
    \ &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }\n// rotate Point p\
    \ counterclockwise by theta radian\ntemplate <typename T> inline Point<T> rotate(const\
    \ Point<T> &p, const T &theta) { return p * Point<T>(std::cos(theta), std::sin(theta));\
    \ }\n// compare (x, y)\ntemplate <typename T> inline bool compare_x(const Point<T>\
    \ &a, const Point<T> &b) { return equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x\
    \ - b.x) < 0; }\n// compare (y, x)\ntemplate <typename T> inline bool compare_y(const\
    \ Point<T> &a, const Point<T> &b) { return equal(a.y, b.y) ? sign(a.x - b.x) <\
    \ 0 : sign(a.y - b.y) < 0; }\n// compare by (arg(p), norm(p)) [0, 360)\ntemplate\
    \ <typename T> inline bool compare_arg(const Point<T> &a, const Point<T> &b) {\n\
    \    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n    assert(!equal(a,\
    \ Point<T>(0, 0)));\n    assert(!equal(b, Point<T>(0, 0)));\n    if ((Point<T>(0,\
    \ 0) < Point<T>(a.y, a.x)) == (Point<T>(0, 0) < Point<T>(b.y, b.x))) {\n     \
    \   return (a.x * b.y == a.y * b.x) ? norm(a) < norm(b) : a.x * b.y > a.y * b.x;\n\
    \    } else {\n        return Point<T>(a.y, a.x) > Point<T>(b.y, b.x);\n    }\n\
    }\n// |p| ^ 2\ntemplate <typename T> inline T norm(const Point<T> &p) { return\
    \ p.x * p.x + p.y * p.y; }\n// |p|\ntemplate <typename T> inline T abs(const Point<T>\
    \ &p) { return std::sqrt(norm(p)); }\n// arg\ntemplate <typename T> inline T arg(const\
    \ Point<T> &p) { return std::atan2(p.y, p.x); }\n// polar\ntemplate <typename\
    \ T> inline Point<T> polar(const T &rho, const T &theta = T(0)) { return rotate(Point<T>(rho,\
    \ 0), theta); }\n// EPS\ntemplate <> double Point<double>::EPS = 1e-9;\ntemplate\
    \ <> long double Point<long double>::EPS = 1e-12;\ntemplate <> long long Point<long\
    \ long>::EPS = 0;\ntemplate <> __int128_t Point<__int128_t>::EPS = 0;\n// change\
    \ EPS\n// using Double = double;\n// using Pt = Point<Double>;\n// Point<Double>::set_eps(new_eps);\n\
    #line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\n\n// line\ntemplate\
    \ <typename T> struct Line {\n    Point<T> a, b;\n\n    Line() = default;\n\n\
    \    Line(const Point<T> &a, const Point<T> &b) : a(a), b(b) {}\n\n    // Ax +\
    \ By = C\n    Line(const T &A, const T &B, const T &C) {\n        assert(equal(A,\
    \ 0) and equal(B, 0));\n        if (equal(A, 0)) {\n            a = Point<T>(0,\
    \ C / B), b = Point<T>(1, C / B);\n        } else if (equal(B, 0)) {\n       \
    \     a = Point<T>(C / A, 0), b = Point<T>(C / A, 1);\n        } else if (equal(C,\
    \ 0)) {\n            a = Point<T>(0, 0), b = Point<T>(1, B / A);\n        } else\
    \ {\n            a = Point<T>(0, C / B), b = Point<T>(C / A, 0);\n        }\n\
    \    }\n\n    friend std::istream &operator>>(std::istream &is, Line &p) { return\
    \ is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 2 \"geometry/projection.hpp\"\
    \n\n#line 5 \"geometry/projection.hpp\"\n\n// projection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    template <typename T> Point<T> projection(const Line<T> &l, const Point<T> &p)\
    \ {\n    T t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);\n    return l.a + t\
    \ * (l.b - l.a);\n}\n#line 6 \"geometry/distance_lp.hpp\"\n\n// distance (line\
    \ and point) (Double = double or long)\ntemplate <typename T> T distance_lp(const\
    \ Line<T> &l, const Point<T> &p) { return abs(p - projection(l, p)); }\ntemplate\
    \ <typename T> T distance2_lp(const Line<T> &l, const Point<T> &p) { return norm(p\
    \ - projection(l, p)); }\n#line 2 \"geometry/circle.hpp\"\n\n#line 4 \"geometry/circle.hpp\"\
    \n\n// circle\ntemplate <typename T> struct Circle {\n    Point<T> o;\n    T r;\n\
    \n    Circle() = default;\n\n    Circle(const Point<T> &o, const T &r) : o(o),\
    \ r(r) {}\n\n    friend std::istream &operator>>(std::istream &is, Circle &c)\
    \ { return is >> c.o >> c.r; }  // format : x y r\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n};\n#line 5 \"geometry/is_intersect_cl.hpp\"\
    \n\n// intersection (circle and line)\ntemplate <typename T> inline bool is_intersect_cl(const\
    \ Circle<T> &c, const Line<T> &l) { return sign(c.r * c.r - distance2_lp(l, c.o))\
    \ >= 0; }\n#line 5 \"geometry/cross_point_cl.hpp\"\n\n// cross point (circle and\
    \ line)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\n\
    template <typename T> std::vector<Point<T>> cross_point_cl(const Circle<T> &c,\
    \ const Line<T> &l) {\n    assert(is_intersect_cl(c, l));\n    auto pr = projection(l,\
    \ c.o);\n    if (equal(norm(pr - c.o), c.r * c.r)) return {pr};\n    Point<T>\
    \ e = (l.b - l.a) * (T(1) / abs(l.b - l.a));\n    auto k = sqrt(c.r * c.r - norm(pr\
    \ - c.o));\n    return {pr - e * k, pr + e * k};\n}\n#line 7 \"verify/aoj_cgl/aoj_cgl_7_d.test.cpp\"\
    \n\nint main() {\n    Circle<double> C;\n    std::cin >> C;\n    int Q;\n    std::cin\
    \ >> Q;\n    while (Q--) {\n        Line<double> L;\n        std::cin >> L;\n\
    \        auto res = cross_point_cl(C, L);\n        std::sort(res.begin(), res.end());\n\
    \        if (res.size() == 1) res.push_back(res[0]);\n        std::cout << std::fixed\
    \ << std::setprecision(15) << res[0].x << ' ' << res[0].y << ' ' << res[1].x <<\
    \ ' ' << res[1].y << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\"\
    \n#define ERROR 0.000001\n\n#include <bits/stdc++.h>\n\n#include \"geometry/cross_point_cl.hpp\"\
    \n\nint main() {\n    Circle<double> C;\n    std::cin >> C;\n    int Q;\n    std::cin\
    \ >> Q;\n    while (Q--) {\n        Line<double> L;\n        std::cin >> L;\n\
    \        auto res = cross_point_cl(C, L);\n        std::sort(res.begin(), res.end());\n\
    \        if (res.size() == 1) res.push_back(res[0]);\n        std::cout << std::fixed\
    \ << std::setprecision(15) << res[0].x << ' ' << res[0].y << ' ' << res[1].x <<\
    \ ' ' << res[1].y << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - geometry/cross_point_cl.hpp
  - geometry/is_intersect_cl.hpp
  - geometry/distance_lp.hpp
  - geometry/point.hpp
  - geometry/line.hpp
  - geometry/projection.hpp
  - geometry/circle.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_7_d.test.cpp
  requiredBy: []
  timestamp: '2023-06-01 23:47:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_7_d.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_7_d.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_7_d.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_7_d.test.cpp
---
