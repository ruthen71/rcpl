---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_4_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_4_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
  bundledCode: "#line 2 \"geometry/monotone_chain.hpp\"\n\n#line 2 \"geometry/polygon.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\
    \n\n// template\nusing Double = double;\nconst Double EPS = 1e-8;\nconst Double\
    \ PI = std::acos(-1);\ninline int sign(const Double &x) { return x <= -EPS ? -1\
    \ : (x >= EPS ? 1 : 0); }\ninline bool equal(const Double &a, const Double &b)\
    \ { return sign(a - b) == 0; }\nDouble radian_to_degree(const Double &r) { return\
    \ r * 180.0 / PI; }\nDouble degree_to_radian(const Double &d) { return d * PI\
    \ / 180.0; }\n#line 4 \"geometry/point.hpp\"\n\n// point\nusing Point = std::complex<Double>;\n\
    std::istream &operator>>(std::istream &is, Point &p) {\n    Double x, y;\n   \
    \ is >> x >> y;\n    p = Point(x, y);\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
    \ &os, Point &p) {\n    os << std::fixed << std::setprecision(15);\n    return\
    \ os << p.real() << ' ' << p.imag();\n}\n\nnamespace std {\nbool operator<(const\
    \ Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real()\
    \ : a.imag() < b.imag(); }\n}  // namespace std\n\n// inner product\nDouble dot(const\
    \ Point &a, const Point &b) { return a.real() * b.real() + a.imag() * b.imag();\
    \ }\n// outer product\nDouble cross(const Point &a, const Point &b) { return a.real()\
    \ * b.imag() - a.imag() * b.real(); }\n// rotate Point p counterclockwise by theta\
    \ radian\nPoint rotate(const Point &p, const Double &theta) { return p * Point(cos(theta),\
    \ sin(theta)); }\n// compare (x, y)\nbool compare_x(const Point &a, const Point\
    \ &b) { return equal(a.real(), b.real()) ? sign(a.imag() - b.imag()) < 0 : sign(a.real()\
    \ - b.real()) < 0; }\n// compare (y, x)\nbool compare_y(const Point &a, const\
    \ Point &b) { return equal(a.imag(), b.imag()) ? sign(a.real() - b.real()) < 0\
    \ : sign(a.imag() - b.imag()) < 0; }\n#line 4 \"geometry/polygon.hpp\"\n\n// polygon\n\
    using Polygon = std::vector<Point>;\nstd::istream &operator>>(std::istream &is,\
    \ Polygon &p) {\n    for (auto &&pi : p) is >> pi;\n    return is;\n}\nstd::ostream\
    \ &operator<<(std::ostream &os, Polygon &p) {\n    for (auto &&pi : p) os << pi\
    \ << \" -> \";\n    return os;\n}\n#line 2 \"geometry/ccw.hpp\"\n\n#line 4 \"\
    geometry/ccw.hpp\"\n\n// counter clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int\
    \ CLOCKWISE = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2; \
    \       // c-a-b line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr\
    \ int ON_SEGMENT = 0;         // a-c-b line\nint ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b, c)) == 1) return\
    \ COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return CLOCKWISE;\n   \
    \ if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (std::norm(b) < std::norm(c))\
    \ return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n#line 5 \"geometry/monotone_chain.hpp\"\
    \n\n// convex hull (Andrew's monotone chain convex hull algorithm)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\n\
    // sort (x, y) by lexicographical order, use stack, calculate upper convex hull\
    \ and lower convex hull\n// counter clockwise order\n// assume the return value\
    \ of ccw is not ONLINE_BACK or ONLINE_FRONT (lexicographical order)\n// strict\
    \ is true : points on the edges of the convex hull are not included (the number\
    \ of points is minimized)\n// complexity: O(n \\log n) (n: the number of points)\n\
    Polygon monotone_chain(Polygon &p, bool strict = true) {\n    int n = (int)p.size();\n\
    \    if (n <= 2) return p;\n    std::sort(p.begin(), p.end(), compare_x);\n  \
    \  Polygon r;\n    r.reserve(n * 2);\n    if (strict) {\n        for (int i =\
    \ 0; i < n; i++) {\n            while (r.size() >= 2 and ccw(r[r.size() - 2],\
    \ r[r.size() - 1], p[i]) != CLOCKWISE) {\n                r.pop_back();\n    \
    \        }\n            r.push_back(p[i]);\n        }\n        int t = r.size()\
    \ + 1;\n        for (int i = n - 2; i >= 0; i--) {\n            while (r.size()\
    \ >= t and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) != CLOCKWISE) {\n     \
    \           r.pop_back();\n            }\n            r.push_back(p[i]);\n   \
    \     }\n    } else {\n        for (int i = 0; i < n; i++) {\n            while\
    \ (r.size() >= 2 and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) == COUNTER_CLOCKWISE)\
    \ {\n                r.pop_back();\n            }\n            r.push_back(p[i]);\n\
    \        }\n        int t = r.size() + 1;\n        for (int i = n - 2; i >= 0;\
    \ i--) {\n            while (r.size() >= t and ccw(r[r.size() - 2], r[r.size()\
    \ - 1], p[i]) == COUNTER_CLOCKWISE) {\n                r.pop_back();\n       \
    \     }\n            r.push_back(p[i]);\n        }\n    }\n    r.pop_back();\n\
    \    std::reverse(r.begin(), r.end());\n    return r;\n}\n"
  code: "#pragma once\n\n#include \"geometry/polygon.hpp\"\n#include \"geometry/ccw.hpp\"\
    \n\n// convex hull (Andrew's monotone chain convex hull algorithm)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\n\
    // sort (x, y) by lexicographical order, use stack, calculate upper convex hull\
    \ and lower convex hull\n// counter clockwise order\n// assume the return value\
    \ of ccw is not ONLINE_BACK or ONLINE_FRONT (lexicographical order)\n// strict\
    \ is true : points on the edges of the convex hull are not included (the number\
    \ of points is minimized)\n// complexity: O(n \\log n) (n: the number of points)\n\
    Polygon monotone_chain(Polygon &p, bool strict = true) {\n    int n = (int)p.size();\n\
    \    if (n <= 2) return p;\n    std::sort(p.begin(), p.end(), compare_x);\n  \
    \  Polygon r;\n    r.reserve(n * 2);\n    if (strict) {\n        for (int i =\
    \ 0; i < n; i++) {\n            while (r.size() >= 2 and ccw(r[r.size() - 2],\
    \ r[r.size() - 1], p[i]) != CLOCKWISE) {\n                r.pop_back();\n    \
    \        }\n            r.push_back(p[i]);\n        }\n        int t = r.size()\
    \ + 1;\n        for (int i = n - 2; i >= 0; i--) {\n            while (r.size()\
    \ >= t and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) != CLOCKWISE) {\n     \
    \           r.pop_back();\n            }\n            r.push_back(p[i]);\n   \
    \     }\n    } else {\n        for (int i = 0; i < n; i++) {\n            while\
    \ (r.size() >= 2 and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) == COUNTER_CLOCKWISE)\
    \ {\n                r.pop_back();\n            }\n            r.push_back(p[i]);\n\
    \        }\n        int t = r.size() + 1;\n        for (int i = n - 2; i >= 0;\
    \ i--) {\n            while (r.size() >= t and ccw(r[r.size() - 2], r[r.size()\
    \ - 1], p[i]) == COUNTER_CLOCKWISE) {\n                r.pop_back();\n       \
    \     }\n            r.push_back(p[i]);\n        }\n    }\n    r.pop_back();\n\
    \    std::reverse(r.begin(), r.end());\n    return r;\n}"
  dependsOn:
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/ccw.hpp
  isVerificationFile: false
  path: geometry/monotone_chain.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2023-02-18 17:31:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_4_a.test.cpp
documentation_of: geometry/monotone_chain.hpp
layout: document
redirect_from:
- /library/geometry/monotone_chain.hpp
- /library/geometry/monotone_chain.hpp.html
title: geometry/monotone_chain.hpp
---
