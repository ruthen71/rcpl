---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/closest_pair.hpp
    title: "\u6700\u8FD1\u70B9\u5BFE"
  - icon: ':x:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_5_a.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\"\n#define ERROR\
    \ 0.000001\n\n#include <bits/stdc++.h>\n\n#line 2 \"geometry/closest_pair.hpp\"\
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
    \ { return rotate(Point(rho, 0), theta); }\n#line 4 \"geometry/closest_pair.hpp\"\
    \n\n// closest pair\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\n\
    // return {index1, index2, distance}\n// using divide-and-conquer algorithm\n\
    // complexity: O(n \\log n) (n: the number of points)\nstd::tuple<int, int, Double>\
    \ closest_pair(const std::vector<Point> &p) {\n    int n = int(p.size());\n  \
    \  assert(n >= 2);\n    if (n == 2) {\n        return {0, 1, abs(p[0] - p[1])};\n\
    \    }\n    // may not be efficient due to indirect references ...\n    std::vector<int>\
    \ ind(n);\n    std::iota(ind.begin(), ind.end(), 0);\n    std::sort(ind.begin(),\
    \ ind.end(), [&](int i, int j) { return compare_x(p[i], p[j]); });\n    auto divide_and_conquer\
    \ = [&](auto f, int l, int r) -> std::tuple<int, int, Double> {\n        if (r\
    \ - l <= 1) return {-1, -1, std::numeric_limits<Double>::max()};\n        int\
    \ md = (l + r) / 2;\n        Double x = p[ind[md]].x;\n        // divide and conquer\n\
    \        auto [i1l, i2l, dl] = f(f, l, md);\n        auto [i1r, i2r, dr] = f(f,\
    \ md, r);\n        int i1, i2;\n        Double d;\n        if (dl < dr) {\n  \
    \          d = dl, i1 = i1l, i2 = i2l;\n        } else {\n            d = dr,\
    \ i1 = i1r, i2 = i2r;\n        }\n        std::inplace_merge(ind.begin() + l,\
    \ ind.begin() + md, ind.begin() + r, [&](int i, int j) { return compare_y(p[i],\
    \ p[j]); });\n        // ind are sorted by y\n        std::vector<int> near_x;\
    \  // index of vertices whose distance from the line x is less than d\n      \
    \  for (int i = l; i < r; i++) {\n            if (sign(std::abs(p[ind[i]].x -\
    \ x) - d) >= 0) continue;  // std::abs(p[ind[i]].x - x) >= d\n            int\
    \ sz = int(near_x.size());\n            // iterate from the end until the distance\
    \ in y-coordinates is greater than or equal to d\n            for (int j = sz\
    \ - 1; j >= 0; j--) {\n                Point cp = p[ind[i]] - p[near_x[j]];\n\
    \                if (sign(cp.y - d) >= 0) break;  // cp.y >= d\n             \
    \   Double cd = abs(cp);\n                if (cd < d) {\n                    d\
    \ = cd, i1 = ind[i], i2 = near_x[j];\n                }\n            }\n     \
    \       near_x.push_back(ind[i]);\n        }\n        return {i1, i2, d};\n  \
    \  };\n    return divide_and_conquer(divide_and_conquer, 0, n);\n}\n#line 7 \"\
    verify/aoj_cgl/aoj_cgl_5_a.test.cpp\"\n\nint main() {\n    int N;\n    std::cin\
    \ >> N;\n    std::vector<Point> P(N);\n    for (int i = 0; i < N; i++) std::cin\
    \ >> P[i];\n    auto [i, j, d] = closest_pair(P);\n    assert(equal(d, std::abs(P[i]\
    \ - P[j])));\n    std::cout << std::fixed << std::setprecision(15) << std::abs(P[i]\
    \ - P[j]) << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\"\
    \n#define ERROR 0.000001\n\n#include <bits/stdc++.h>\n\n#include \"geometry/closest_pair.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    std::vector<Point> P(N);\n\
    \    for (int i = 0; i < N; i++) std::cin >> P[i];\n    auto [i, j, d] = closest_pair(P);\n\
    \    assert(equal(d, std::abs(P[i] - P[j])));\n    std::cout << std::fixed <<\
    \ std::setprecision(15) << std::abs(P[i] - P[j]) << '\\n';\n    return 0;\n}"
  dependsOn:
  - geometry/closest_pair.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_5_a.test.cpp
  requiredBy: []
  timestamp: '2023-04-04 18:27:06+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_5_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_5_a.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_5_a.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_5_a.test.cpp
---
