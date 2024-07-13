---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/lc_other/lc_aplusb_compare_arg.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    \n#line 2 \"geometry/point.hpp\"\n\n// point\ntemplate <typename T> struct Point\
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
    #line 6 \"verify/lc_other/lc_aplusb_compare_arg.test.cpp\"\n\nint main() {\n \
    \   using Pt = Point<long long>;\n    std::vector<Pt> p = {{1, 0}, {2, 0}, {1,\
    \ 1}, {2, 2}, {0, 1}, {0, 2}, {-1, 1}, {-2, 2}, {-1, 0}, {-2, 0}, {-1, -1}, {-2,\
    \ -2}, {0, -1}, {0, -2}, {1, -1}, {2, -2}};\n    for (int i = 0; i < 16; i++)\
    \ {\n        for (int j = i + 1; j < 16; j++) {\n            assert(compare_arg(p[i],\
    \ p[j]));\n        }\n    }\n    long long a, b;\n    std::cin >> a >> b;\n  \
    \  std::cout << a + b << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    \n#include \"geometry/point.hpp\"\n\nint main() {\n    using Pt = Point<long long>;\n\
    \    std::vector<Pt> p = {{1, 0}, {2, 0}, {1, 1}, {2, 2}, {0, 1}, {0, 2}, {-1,\
    \ 1}, {-2, 2}, {-1, 0}, {-2, 0}, {-1, -1}, {-2, -2}, {0, -1}, {0, -2}, {1, -1},\
    \ {2, -2}};\n    for (int i = 0; i < 16; i++) {\n        for (int j = i + 1; j\
    \ < 16; j++) {\n            assert(compare_arg(p[i], p[j]));\n        }\n    }\n\
    \    long long a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n\
    \    return 0;\n}"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: true
  path: verify/lc_other/lc_aplusb_compare_arg.test.cpp
  requiredBy: []
  timestamp: '2023-06-01 23:47:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_other/lc_aplusb_compare_arg.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_other/lc_aplusb_compare_arg.test.cpp
- /verify/verify/lc_other/lc_aplusb_compare_arg.test.cpp.html
title: verify/lc_other/lc_aplusb_compare_arg.test.cpp
---