---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_point_cp.hpp
    title: geometry/tangent_point_cp.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_7_f.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\"\n#define ERROR\
    \ 0.00001\n\n#include <bits/stdc++.h>\n\n#line 2 \"geometry/tangent_point_cp.hpp\"\
    \n\n#line 2 \"geometry/cross_point_cc.hpp\"\n\n#line 2 \"geometry/is_intersect_cc.hpp\"\
    \n\n#line 2 \"geometry/circle.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n// point\n\
    template <typename T> struct Point {\n    static T EPS;\n    static constexpr\
    \ T PI = 3.1415926535'8979323846'2643383279L;\n    static void set_eps(const T\
    \ &e) { EPS = e; }\n    T x, y;\n    Point(const T x = T(0), const T y = T(0))\
    \ : x(x), y(y) {}\n    Point &operator+=(const Point &p) {\n        x += p.x;\n\
    \        y += p.y;\n        return *this;\n    }\n    Point &operator-=(const\
    \ Point &p) {\n        x -= p.x;\n        y -= p.y;\n        return *this;\n \
    \   }\n    Point &operator*=(const Point &p) { return *this = Point(x * p.x -\
    \ y * p.y, x * p.y + y * p.x); }\n    Point &operator*=(const T &k) {\n      \
    \  x *= k;\n        y *= k;\n        return *this;\n    }\n    Point &operator/=(const\
    \ Point &p) { return *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / (p.x\
    \ * p.x + p.y * p.y); }\n    Point &operator/=(const T &k) {\n        x /= k;\n\
    \        y /= k;\n        return *this;\n    }\n\n    Point operator+() const\
    \ { return *this; }\n    Point operator-() const { return Point(-x, -y); }\n\n\
    \    friend Point operator+(const Point &a, const Point &b) { return Point(a)\
    \ += b; }\n    friend Point operator-(const Point &a, const Point &b) { return\
    \ Point(a) -= b; }\n    friend Point operator*(const Point &a, const Point &b)\
    \ { return Point(a) *= b; }\n    friend Point operator*(const Point &p, const\
    \ T &k) { return Point(p) *= k; }\n    friend Point operator/(const Point &a,\
    \ const Point &b) { return Point(a) /= b; }\n    friend Point operator/(const\
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
    // Point<Double>::set_eps(new_eps);\n#line 4 \"geometry/circle.hpp\"\n\n// circle\n\
    template <typename T> struct Circle {\n    Point<T> o;\n    T r;\n\n    Circle()\
    \ = default;\n\n    Circle(const Point<T> &o, const T &r) : o(o), r(r) {}\n\n\
    \    friend std::istream &operator>>(std::istream &is, Circle &c) { return is\
    \ >> c.o >> c.r; }  // format : x y r\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Circle &c) { return os << c.o << ' ' << c.r; }\n};\n#line 3 \"geometry/tangent_number_cc.hpp\"\
    \n\n// return the number of tangent\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\n\
    template <typename T> int tangent_number_cc(Circle<T> c1, Circle<T> c2) {\n  \
    \  if (c1.r < c2.r) std::swap(c1, c2);\n    const T d2 = norm(c1.o - c2.o);\n\
    \    if (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 1) return 4;  // d > c1.r\
    \ + c2.r and c1.r + c2.r >= 0 <=> d * d > (c1.r + c2.r) * (c1.r + c2.r)\n    if\
    \ (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 0) return 3;  // d = c1.r + c2.r\
    \ and c1.r + c2.r >= 0 <=> d * d = (c1.r + c2.r) * (c1.r + c2.r)\n    if (sign(d2\
    \ - (c1.r - c2.r) * (c1.r - c2.r)) == 1) return 2;  // d > c1.r - c2.r and c1.r\
    \ - c2.r >= 0 <=> d * d > (c1.r - c2.r) * (c1.r - c2.r)\n    if (sign(d2 - (c1.r\
    \ - c2.r) * (c1.r - c2.r)) == 0) return 1;  // d = c1.r - c2.r and c1.r - c2.r\
    \ >= 0 <=> d * d = (c1.r - c2.r) * (c1.r - c2.r)\n    return 0;\n}\n#line 5 \"\
    geometry/is_intersect_cc.hpp\"\n\n// intersection (circle and circle)\n// intersect\
    \ = number of tangent is 1, 2, 3\ntemplate <typename T> inline bool is_intersect_cc(const\
    \ Circle<T> &c1, const Circle<T> &c2) {\n    int num = tangent_number_cc(c1, c2);\n\
    \    return 1 <= num and num <= 3;\n}\n#line 4 \"geometry/cross_point_cc.hpp\"\
    \n\n// cross point (circle and circle)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E\n\
    template <typename T> std::vector<Point<T>> cross_point_cc(const Circle<T> &c1,\
    \ const Circle<T> &c2) {\n    if (!is_intersect_cc(c1, c2)) return {};\n    T\
    \ d = abs(c1.o - c2.o);\n    T a = std::acos((c1.r * c1.r - c2.r * c2.r + d *\
    \ d) / (T(2) * c1.r * d));\n    T t = arg(c2.o - c1.o);\n    Point<T> p = c1.o\
    \ + polar(c1.r, t + a);\n    Point<T> q = c1.o + polar(c1.r, t - a);\n    if (equal(p.x,\
    \ q.x) and equal(p.y, q.y)) return {p};\n    return {p, q};\n}\n#line 4 \"geometry/tangent_point_cp.hpp\"\
    \n\n// tangent point (circle and point)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\n\
    template <typename T> std::pair<Point<T>, Point<T>> tangent_point_cp(const Circle<T>\
    \ &c, const Point<T> &p) {\n    assert(sign(abs(c.o - p) - c.r) == 1);\n    auto\
    \ res = cross_point_cc(c, Circle(p, sqrt(norm(c.o - p) - c.r * c.r)));\n    return\
    \ {res[0], res[1]};\n}\n#line 7 \"verify/aoj_cgl/aoj_cgl_7_f.test.cpp\"\n\nint\
    \ main() {\n    Point<double> P;\n    Circle<double> C;\n    std::cin >> P >>\
    \ C;\n    auto [p, q] = tangent_point_cp(C, P);\n    if (!compare_x(p, q)) std::swap(p,\
    \ q);\n    std::cout << std::fixed << std::setprecision(15) << p.x << ' ' << p.y\
    \ << '\\n';\n    std::cout << std::fixed << std::setprecision(15) << q.x << '\
    \ ' << q.y << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\"\
    \n#define ERROR 0.00001\n\n#include <bits/stdc++.h>\n\n#include \"geometry/tangent_point_cp.hpp\"\
    \n\nint main() {\n    Point<double> P;\n    Circle<double> C;\n    std::cin >>\
    \ P >> C;\n    auto [p, q] = tangent_point_cp(C, P);\n    if (!compare_x(p, q))\
    \ std::swap(p, q);\n    std::cout << std::fixed << std::setprecision(15) << p.x\
    \ << ' ' << p.y << '\\n';\n    std::cout << std::fixed << std::setprecision(15)\
    \ << q.x << ' ' << q.y << '\\n';\n    return 0;\n}"
  dependsOn:
  - geometry/tangent_point_cp.hpp
  - geometry/cross_point_cc.hpp
  - geometry/is_intersect_cc.hpp
  - geometry/circle.hpp
  - geometry/point.hpp
  - geometry/tangent_number_cc.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_7_f.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 10:28:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_7_f.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_7_f.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_7_f.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_7_f.test.cpp
---
