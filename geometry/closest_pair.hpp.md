---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_5_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_5_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
  bundledCode: "#line 2 \"geometry/closest_pair.hpp\"\n\n#line 2 \"geometry/point.hpp\"\
    \n\n// point\ntemplate <typename T> struct Point {\n    static T EPS;\n    static\
    \ constexpr T PI = 3.1415926535'8979323846'2643383279L;\n    static void set_eps(const\
    \ T &e) { EPS = e; }\n    T x, y;\n    Point(const T x = T(0), const T y = T(0))\
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
    #line 4 \"geometry/closest_pair.hpp\"\n\n// closest pair\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\n\
    // return {index1, index2, distance}\n// using divide-and-conquer algorithm\n\
    // complexity: O(n \\log n) (n: the number of points)\ntemplate <typename T> std::tuple<int,\
    \ int, T> closest_pair(const std::vector<Point<T>> &p) {\n    int n = int(p.size());\n\
    \    assert(n >= 2);\n    if (n == 2) {\n        return {0, 1, abs(p[0] - p[1])};\n\
    \    }\n    // may not be efficient due to indirect references ...\n    std::vector<int>\
    \ ind(n);\n    std::iota(ind.begin(), ind.end(), 0);\n    std::sort(ind.begin(),\
    \ ind.end(), [&](int i, int j) { return compare_x(p[i], p[j]); });\n    auto divide_and_conquer\
    \ = [&](auto f, int l, int r) -> std::tuple<int, int, T> {\n        if (r - l\
    \ <= 1) return {-1, -1, std::numeric_limits<T>::max()};\n        int md = (l +\
    \ r) / 2;\n        T x = p[ind[md]].x;\n        // divide and conquer\n      \
    \  auto [i1l, i2l, dl] = f(f, l, md);\n        auto [i1r, i2r, dr] = f(f, md,\
    \ r);\n        int i1, i2;\n        T d;\n        if (dl < dr) {\n           \
    \ d = dl, i1 = i1l, i2 = i2l;\n        } else {\n            d = dr, i1 = i1r,\
    \ i2 = i2r;\n        }\n        std::inplace_merge(ind.begin() + l, ind.begin()\
    \ + md, ind.begin() + r, [&](int i, int j) { return compare_y(p[i], p[j]); });\n\
    \        // ind are sorted by y\n        std::vector<int> near_x;  // index of\
    \ vertices whose distance from the line x is less than d\n        for (int i =\
    \ l; i < r; i++) {\n            if (sign(std::abs(p[ind[i]].x - x) - d) >= 0)\
    \ continue;  // std::abs(p[ind[i]].x - x) >= d\n            int sz = int(near_x.size());\n\
    \            // iterate from the end until the distance in y-coordinates is greater\
    \ than or equal to d\n            for (int j = sz - 1; j >= 0; j--) {\n      \
    \          Point cp = p[ind[i]] - p[near_x[j]];\n                if (sign(cp.y\
    \ - d) >= 0) break;  // cp.y >= d\n                T cd = abs(cp);\n         \
    \       if (cd < d) {\n                    d = cd, i1 = ind[i], i2 = near_x[j];\n\
    \                }\n            }\n            near_x.push_back(ind[i]);\n   \
    \     }\n        return {i1, i2, d};\n    };\n    return divide_and_conquer(divide_and_conquer,\
    \ 0, n);\n}\n"
  code: "#pragma once\n\n#include \"geometry/point.hpp\"\n\n// closest pair\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\n\
    // return {index1, index2, distance}\n// using divide-and-conquer algorithm\n\
    // complexity: O(n \\log n) (n: the number of points)\ntemplate <typename T> std::tuple<int,\
    \ int, T> closest_pair(const std::vector<Point<T>> &p) {\n    int n = int(p.size());\n\
    \    assert(n >= 2);\n    if (n == 2) {\n        return {0, 1, abs(p[0] - p[1])};\n\
    \    }\n    // may not be efficient due to indirect references ...\n    std::vector<int>\
    \ ind(n);\n    std::iota(ind.begin(), ind.end(), 0);\n    std::sort(ind.begin(),\
    \ ind.end(), [&](int i, int j) { return compare_x(p[i], p[j]); });\n    auto divide_and_conquer\
    \ = [&](auto f, int l, int r) -> std::tuple<int, int, T> {\n        if (r - l\
    \ <= 1) return {-1, -1, std::numeric_limits<T>::max()};\n        int md = (l +\
    \ r) / 2;\n        T x = p[ind[md]].x;\n        // divide and conquer\n      \
    \  auto [i1l, i2l, dl] = f(f, l, md);\n        auto [i1r, i2r, dr] = f(f, md,\
    \ r);\n        int i1, i2;\n        T d;\n        if (dl < dr) {\n           \
    \ d = dl, i1 = i1l, i2 = i2l;\n        } else {\n            d = dr, i1 = i1r,\
    \ i2 = i2r;\n        }\n        std::inplace_merge(ind.begin() + l, ind.begin()\
    \ + md, ind.begin() + r, [&](int i, int j) { return compare_y(p[i], p[j]); });\n\
    \        // ind are sorted by y\n        std::vector<int> near_x;  // index of\
    \ vertices whose distance from the line x is less than d\n        for (int i =\
    \ l; i < r; i++) {\n            if (sign(std::abs(p[ind[i]].x - x) - d) >= 0)\
    \ continue;  // std::abs(p[ind[i]].x - x) >= d\n            int sz = int(near_x.size());\n\
    \            // iterate from the end until the distance in y-coordinates is greater\
    \ than or equal to d\n            for (int j = sz - 1; j >= 0; j--) {\n      \
    \          Point cp = p[ind[i]] - p[near_x[j]];\n                if (sign(cp.y\
    \ - d) >= 0) break;  // cp.y >= d\n                T cd = abs(cp);\n         \
    \       if (cd < d) {\n                    d = cd, i1 = ind[i], i2 = near_x[j];\n\
    \                }\n            }\n            near_x.push_back(ind[i]);\n   \
    \     }\n        return {i1, i2, d};\n    };\n    return divide_and_conquer(divide_and_conquer,\
    \ 0, n);\n}"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/closest_pair.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2023-06-01 23:47:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_5_a.test.cpp
documentation_of: geometry/closest_pair.hpp
layout: document
title: "\u6700\u8FD1\u70B9\u5BFE"
---

## 使用例

- [ABC022 D](https://atcoder.jp/contests/abc022/submissions/39102044)