---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
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
    \n\n#line 2 \"geometry/geometry_template.hpp\"\n\n// template\nusing Double =\
    \ double;    // double or long double\nconst Double EPS = 1e-8;  // change the\
    \ value depending on the problem\nconst Double PI = std::acos(Double(-1));\ninline\
    \ int sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }\n\
    inline bool equal(const Double &a, const Double &b) { return sign(a - b) == 0;\
    \ }\ninline Double radian_to_degree(const Double &r) { return r * 180.0 / PI;\
    \ }\ninline Double degree_to_radian(const Double &d) { return d * PI / 180.0;\
    \ }\n#line 4 \"geometry/point.hpp\"\n\n// point\nusing Point = std::complex<Double>;\n\
    std::istream &operator>>(std::istream &is, Point &p) {\n    Double x, y;\n   \
    \ is >> x >> y;\n    p = Point(x, y);\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
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
    #line 4 \"geometry/closest_pair.hpp\"\n\n// closest pair\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\n\
    // return {index1, index2, distance}\n// using divide-and-conquer algorithm\n\
    // complexity: O(n \\log n) (n: the number of points)\nstd::tuple<int, int, Double>\
    \ closest_pair(const std::vector<Point> &p) {\n    int n = int(p.size());\n  \
    \  assert(n >= 2);\n    if (n == 2) {\n        return {0, 1, std::abs(p[0] - p[1])};\n\
    \    }\n    // may not be efficient due to indirect references ...\n    std::vector<int>\
    \ ind(n);\n    std::iota(ind.begin(), ind.end(), 0);\n    std::sort(ind.begin(),\
    \ ind.end(), [&](int i, int j) { return compare_x(p[i], p[j]); });\n    auto divide_and_conquer\
    \ = [&](auto f, int l, int r) -> std::tuple<int, int, Double> {\n        if (r\
    \ - l <= 1) return {-1, -1, std::numeric_limits<Double>::max()};\n        int\
    \ md = (l + r) / 2;\n        Double x = p[ind[md]].real();\n        // divide\
    \ and conquer\n        auto [i1l, i2l, dl] = f(f, l, md);\n        auto [i1r,\
    \ i2r, dr] = f(f, md, r);\n        int i1, i2;\n        Double d;\n        if\
    \ (dl < dr) {\n            d = dl, i1 = i1l, i2 = i2l;\n        } else {\n   \
    \         d = dr, i1 = i1r, i2 = i2r;\n        }\n        std::inplace_merge(ind.begin()\
    \ + l, ind.begin() + md, ind.begin() + r, [&](int i, int j) { return compare_y(p[i],\
    \ p[j]); });\n        // ind are sorted by y\n        std::vector<int> near_x;\
    \  // index of vertices whose distance from the line x is less than d\n      \
    \  for (int i = l; i < r; i++) {\n            if (sign(std::abs(p[ind[i]].real()\
    \ - x) - d) >= 0) continue;  // std::abs(p[ind[i]].real() - x) >= d\n        \
    \    int sz = int(near_x.size());\n            // iterate from the end until the\
    \ distance in y-coordinates is greater than or equal to d\n            for (int\
    \ j = sz - 1; j >= 0; j--) {\n                Point cp = p[ind[i]] - p[near_x[j]];\n\
    \                if (sign(cp.imag() - d) >= 0) break;  // cp.imag() >= d\n   \
    \             Double cd = std::abs(cp);\n                if (cd < d) {\n     \
    \               d = cd, i1 = ind[i], i2 = near_x[j];\n                }\n    \
    \        }\n            near_x.push_back(ind[i]);\n        }\n        return {i1,\
    \ i2, d};\n    };\n    return divide_and_conquer(divide_and_conquer, 0, n);\n\
    }\n"
  code: "#pragma once\n\n#include \"geometry/point.hpp\"\n\n// closest pair\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\n\
    // return {index1, index2, distance}\n// using divide-and-conquer algorithm\n\
    // complexity: O(n \\log n) (n: the number of points)\nstd::tuple<int, int, Double>\
    \ closest_pair(const std::vector<Point> &p) {\n    int n = int(p.size());\n  \
    \  assert(n >= 2);\n    if (n == 2) {\n        return {0, 1, std::abs(p[0] - p[1])};\n\
    \    }\n    // may not be efficient due to indirect references ...\n    std::vector<int>\
    \ ind(n);\n    std::iota(ind.begin(), ind.end(), 0);\n    std::sort(ind.begin(),\
    \ ind.end(), [&](int i, int j) { return compare_x(p[i], p[j]); });\n    auto divide_and_conquer\
    \ = [&](auto f, int l, int r) -> std::tuple<int, int, Double> {\n        if (r\
    \ - l <= 1) return {-1, -1, std::numeric_limits<Double>::max()};\n        int\
    \ md = (l + r) / 2;\n        Double x = p[ind[md]].real();\n        // divide\
    \ and conquer\n        auto [i1l, i2l, dl] = f(f, l, md);\n        auto [i1r,\
    \ i2r, dr] = f(f, md, r);\n        int i1, i2;\n        Double d;\n        if\
    \ (dl < dr) {\n            d = dl, i1 = i1l, i2 = i2l;\n        } else {\n   \
    \         d = dr, i1 = i1r, i2 = i2r;\n        }\n        std::inplace_merge(ind.begin()\
    \ + l, ind.begin() + md, ind.begin() + r, [&](int i, int j) { return compare_y(p[i],\
    \ p[j]); });\n        // ind are sorted by y\n        std::vector<int> near_x;\
    \  // index of vertices whose distance from the line x is less than d\n      \
    \  for (int i = l; i < r; i++) {\n            if (sign(std::abs(p[ind[i]].real()\
    \ - x) - d) >= 0) continue;  // std::abs(p[ind[i]].real() - x) >= d\n        \
    \    int sz = int(near_x.size());\n            // iterate from the end until the\
    \ distance in y-coordinates is greater than or equal to d\n            for (int\
    \ j = sz - 1; j >= 0; j--) {\n                Point cp = p[ind[i]] - p[near_x[j]];\n\
    \                if (sign(cp.imag() - d) >= 0) break;  // cp.imag() >= d\n   \
    \             Double cd = std::abs(cp);\n                if (cd < d) {\n     \
    \               d = cd, i1 = ind[i], i2 = near_x[j];\n                }\n    \
    \        }\n            near_x.push_back(ind[i]);\n        }\n        return {i1,\
    \ i2, d};\n    };\n    return divide_and_conquer(divide_and_conquer, 0, n);\n}"
  dependsOn:
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: false
  path: geometry/closest_pair.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2023-03-12 06:40:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_5_a.test.cpp
documentation_of: geometry/closest_pair.hpp
layout: document
title: "\u6700\u8FD1\u70B9\u5BFE"
---

## 使用例

- [ABC022 D](https://atcoder.jp/contests/abc022/submissions/39102044)