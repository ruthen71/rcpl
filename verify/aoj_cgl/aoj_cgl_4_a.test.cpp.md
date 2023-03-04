---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':question:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/monotone_chain.hpp
    title: geometry/monotone_chain.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':question:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_4_a.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"geometry/monotone_chain.hpp\"\n\n#line 2 \"geometry/polygon.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\
    \n\n// template\nusing Double = double;\nconst Double EPS = 1e-10;\nconst Double\
    \ PI = std::acos(Double(-1));\ninline int sign(const Double &x) { return x <=\
    \ -EPS ? -1 : (x >= EPS ? 1 : 0); }\ninline bool equal(const Double &a, const\
    \ Double &b) { return sign(a - b) == 0; }\ninline Double radian_to_degree(const\
    \ Double &r) { return r * 180.0 / PI; }\ninline Double degree_to_radian(const\
    \ Double &d) { return d * PI / 180.0; }\n#line 4 \"geometry/point.hpp\"\n\n//\
    \ point\nusing Point = std::complex<Double>;\nstd::istream &operator>>(std::istream\
    \ &is, Point &p) {\n    Double x, y;\n    is >> x >> y;\n    p = Point(x, y);\n\
    \    return is;\n}\nstd::ostream &operator<<(std::ostream &os, const Point &p)\
    \ {\n    os << std::fixed << std::setprecision(15);\n    return os << p.real()\
    \ << ' ' << p.imag();\n}\n\n// for std::set, std::map, ...\nnamespace std {\n\
    inline bool operator<(const Point &a, const Point &b) { return a.real() != b.real()\
    \ ? a.real() < b.real() : a.imag() < b.imag(); }\n}  // namespace std\n\ninline\
    \ Point operator*(const Point &p, const Double &k) { return Point(p.real() * k,\
    \ p.imag() * k); }\ninline Point operator/(const Point &p, const Double &k) {\
    \ return Point(p.real() / k, p.imag() / k); }\n// equal (point and point)\ninline\
    \ bool equal(const Point &a, const Point &b) { return equal(a.real(), b.real())\
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
    \ os;\n}\n#line 2 \"geometry/ccw.hpp\"\n\n#line 4 \"geometry/ccw.hpp\"\n\n// counter\
    \ clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
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
    Polygon monotone_chain(std::vector<Point> &p, bool strict = true) {\n    int n\
    \ = (int)p.size();\n    if (n <= 2) return p;\n    std::sort(p.begin(), p.end(),\
    \ compare_x);\n    Polygon r;\n    r.reserve(n * 2);\n    if (strict) {\n    \
    \    for (int i = 0; i < n; i++) {\n            while (r.size() >= 2 and ccw(r[r.size()\
    \ - 2], r[r.size() - 1], p[i]) != CLOCKWISE) {\n                r.pop_back();\n\
    \            }\n            r.push_back(p[i]);\n        }\n        int t = r.size()\
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
    \    std::reverse(r.begin(), r.end());\n    return r;\n}\n#line 6 \"verify/aoj_cgl/aoj_cgl_4_a.test.cpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    Polygon P(N);\n    std::cin\
    \ >> P;\n    auto res = monotone_chain(P, false);\n    int minidx = 0;\n    for\
    \ (int i = 0; i < res.size(); i++) {\n        if (compare_y(res[i], res[minidx]))\
    \ {\n            minidx = i;\n        }\n    }\n    std::rotate(res.begin(), res.begin()\
    \ + minidx, res.end());\n    std::cout << res.size() << '\\n';\n    for (int i\
    \ = 0; i < res.size(); i++) std::cout << std::fixed << std::setprecision(0) <<\
    \ res[i].real() << ' ' << res[i].imag() << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"geometry/monotone_chain.hpp\"\n\nint\
    \ main() {\n    int N;\n    std::cin >> N;\n    Polygon P(N);\n    std::cin >>\
    \ P;\n    auto res = monotone_chain(P, false);\n    int minidx = 0;\n    for (int\
    \ i = 0; i < res.size(); i++) {\n        if (compare_y(res[i], res[minidx])) {\n\
    \            minidx = i;\n        }\n    }\n    std::rotate(res.begin(), res.begin()\
    \ + minidx, res.end());\n    std::cout << res.size() << '\\n';\n    for (int i\
    \ = 0; i < res.size(); i++) std::cout << std::fixed << std::setprecision(0) <<\
    \ res[i].real() << ' ' << res[i].imag() << '\\n';\n    return 0;\n}"
  dependsOn:
  - geometry/monotone_chain.hpp
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/ccw.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_4_a.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 00:14:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_4_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_4_a.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_4_a.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_4_a.test.cpp
---