---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_diameter.hpp
    title: geometry/convex_polygon_diameter.hpp
  - icon: ':question:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':question:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon_is_convex.hpp
    title: geometry/polygon_is_convex.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_4_b.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\"\n#define ERROR\
    \ 0.000001\n\n#include <bits/stdc++.h>\n\n#line 2 \"geometry/convex_polygon_diameter.hpp\"\
    \n\n#line 2 \"geometry/polygon.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n#line\
    \ 2 \"geometry/geometry_template.hpp\"\n\n// template\nusing Double = double;\n\
    const Double EPS = 1e-10;\nconst Double PI = std::acos(Double(-1));\ninline int\
    \ sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }\ninline\
    \ bool equal(const Double &a, const Double &b) { return sign(a - b) == 0; }\n\
    inline Double radian_to_degree(const Double &r) { return r * 180.0 / PI; }\ninline\
    \ Double degree_to_radian(const Double &d) { return d * PI / 180.0; }\n#line 4\
    \ \"geometry/point.hpp\"\n\n// point\nusing Point = std::complex<Double>;\nstd::istream\
    \ &operator>>(std::istream &is, Point &p) {\n    Double x, y;\n    is >> x >>\
    \ y;\n    p = Point(x, y);\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
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
    #line 4 \"geometry/polygon.hpp\"\n\n// polygon\nusing Polygon = std::vector<Point>;\n\
    std::istream &operator>>(std::istream &is, Polygon &p) {\n    for (auto &&pi :\
    \ p) is >> pi;\n    return is;\n}\nstd::ostream &operator<<(std::ostream &os,\
    \ const Polygon &p) {\n    for (auto &&pi : p) os << pi << \" -> \";\n    return\
    \ os;\n}\n#line 2 \"geometry/polygon_is_convex.hpp\"\n\n#line 2 \"geometry/ccw.hpp\"\
    \n\n#line 4 \"geometry/ccw.hpp\"\n\n// counter clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int\
    \ CLOCKWISE = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2; \
    \       // c-a-b line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr\
    \ int ON_SEGMENT = 0;         // a-c-b line\nint ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b, c)) == 1) return\
    \ COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return CLOCKWISE;\n   \
    \ if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (std::norm(b) < std::norm(c))\
    \ return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n#line 5 \"geometry/polygon_is_convex.hpp\"\
    \n\n// check polygon is convex (not strictly, 0 <= angle <= 180 degrees)\n// angle\
    \ = 180 degrees -> ON_SEGMENT\n// angle = 0 degrees -> ONLINE_FRONT or ONLINE_BACK\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\nbool polygon_is_convex(const\
    \ Polygon &p) {\n    int n = (int)p.size();\n    assert(n >= 3);\n    bool okccw\
    \ = true, okcw = true;\n    for (int i = 0; i < n - 2; i++) {\n        int res\
    \ = ccw(p[i], p[i + 1], p[i + 2]);\n        if (res == CLOCKWISE) okccw = false;\n\
    \        if (res == COUNTER_CLOCKWISE) okcw = false;\n        if (!okccw and !okcw)\
    \ return false;\n    }\n    {\n        int res = ccw(p[n - 2], p[n - 1], p[0]);\n\
    \        if (res == CLOCKWISE) okccw = false;\n        if (res == COUNTER_CLOCKWISE)\
    \ okcw = false;\n        if (!okccw and !okcw) return false;\n    }\n    {\n \
    \       int res = ccw(p[n - 1], p[0], p[1]);\n        if (res == CLOCKWISE) okccw\
    \ = false;\n        if (res == COUNTER_CLOCKWISE) okcw = false;\n        if (!okccw\
    \ and !okcw) return false;\n    }\n    return true;\n}\n#line 5 \"geometry/convex_polygon_diameter.hpp\"\
    \n\n// convex polygon diameter\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\n\
    // return {index1, index2, diameter}\n// using the method of rotating calipers\
    \ (https://en.wikipedia.org/wiki/Rotating_calipers)\n// complexity: O(n)\nstd::tuple<int,\
    \ int, Double> convex_polygon_diameter(const Polygon &p) {\n    assert(polygon_is_convex(p));\n\
    \    int n = (int)p.size();\n    assert(n >= 2);\n    if (n == 2) {\n        return\
    \ {0, 1, std::abs(p[0] - p[1])};\n    }\n    auto [it_min, it_max] = std::minmax_element(p.begin(),\
    \ p.end(), compare_x);\n    int idx_min = it_min - p.begin();\n    int idx_max\
    \ = it_max - p.begin();\n\n    Double maxdis = std::norm(p[idx_max] - p[idx_min]);\n\
    \    int maxi = idx_min, i = idx_min, maxj = idx_max, j = idx_max;\n    do {\n\
    \        int ni = (i + 1 == n ? 0 : i + 1), nj = (j + 1 == n ? 0 : j + 1);\n \
    \       if (sign(cross(p[ni] - p[i], p[nj] - p[j])) < 0) {\n            i = ni;\n\
    \        } else {\n            j = nj;\n        }\n        if (std::norm(p[i]\
    \ - p[j]) > maxdis) {\n            maxdis = std::norm(p[i] - p[j]);\n        \
    \    maxi = i;\n            maxj = j;\n        }\n    } while (i != idx_min ||\
    \ j != idx_max);\n    return {maxi, maxj, std::abs(p[maxi] - p[maxj])};\n}\n#line\
    \ 7 \"verify/aoj_cgl/aoj_cgl_4_b.test.cpp\"\n\nint main() {\n    int N;\n    std::cin\
    \ >> N;\n    Polygon P(N);\n    std::cin >> P;\n    auto [i, j, d] = convex_polygon_diameter(P);\n\
    \    std::cout << std::fixed << std::setprecision(15) << d << '\\n';\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\"\
    \n#define ERROR 0.000001\n\n#include <bits/stdc++.h>\n\n#include \"geometry/convex_polygon_diameter.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    Polygon P(N);\n    std::cin\
    \ >> P;\n    auto [i, j, d] = convex_polygon_diameter(P);\n    std::cout << std::fixed\
    \ << std::setprecision(15) << d << '\\n';\n    return 0;\n}"
  dependsOn:
  - geometry/convex_polygon_diameter.hpp
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/polygon_is_convex.hpp
  - geometry/ccw.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_4_b.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 00:14:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_4_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_4_b.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_4_b.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_4_b.test.cpp
---
