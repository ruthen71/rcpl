---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_cut.hpp
    title: geometry/convex_polygon_cut.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_ll.hpp
    title: geometry/cross_point_ll.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon_area.hpp
    title: geometry/polygon_area.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_4_c.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\"\n#define ERROR\
    \ 0.00001\n\n#include <bits/stdc++.h>\n\n#line 2 \"geometry/convex_polygon_cut.hpp\"\
    \n\n#line 2 \"geometry/polygon.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n#line\
    \ 2 \"geometry/geometry_template.hpp\"\n\n// template\nusing Double = double;\n\
    const Double EPS = 1e-8;\nconst Double PI = std::acos(-1);\ninline int sign(const\
    \ Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }\ninline bool equal(const\
    \ Double &a, const Double &b) { return sign(a - b) == 0; }\nDouble radian_to_degree(const\
    \ Double &r) { return r * 180.0 / PI; }\nDouble degree_to_radian(const Double\
    \ &d) { return d * PI / 180.0; }\n#line 4 \"geometry/point.hpp\"\n\n// point\n\
    using Point = std::complex<Double>;\nstd::istream &operator>>(std::istream &is,\
    \ Point &p) {\n    Double x, y;\n    is >> x >> y;\n    p = Point(x, y);\n   \
    \ return is;\n}\nstd::ostream &operator<<(std::ostream &os, Point &p) {\n    os\
    \ << std::fixed << std::setprecision(15);\n    return os << p.real() << ' ' <<\
    \ p.imag();\n}\n\nnamespace std {\nbool operator<(const Point &a, const Point\
    \ &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();\
    \ }\n}  // namespace std\n\n// inner product\nDouble dot(const Point &a, const\
    \ Point &b) { return a.real() * b.real() + a.imag() * b.imag(); }\n// outer product\n\
    Double cross(const Point &a, const Point &b) { return a.real() * b.imag() - a.imag()\
    \ * b.real(); }\n// rotate Point p counterclockwise by theta radian\nPoint rotate(const\
    \ Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }\n\
    // compare (x, y)\nbool compare_x(const Point &a, const Point &b) { return equal(a.real(),\
    \ b.real()) ? sign(a.imag() - b.imag()) < 0 : sign(a.real() - b.real()) < 0; }\n\
    // compare (y, x)\nbool compare_y(const Point &a, const Point &b) { return equal(a.imag(),\
    \ b.imag()) ? sign(a.real() - b.real()) < 0 : sign(a.imag() - b.imag()) < 0; }\n\
    #line 4 \"geometry/polygon.hpp\"\n\n// polygon\nusing Polygon = std::vector<Point>;\n\
    std::istream &operator>>(std::istream &is, Polygon &p) {\n    for (auto &&pi :\
    \ p) is >> pi;\n    return is;\n}\nstd::ostream &operator<<(std::ostream &os,\
    \ Polygon &p) {\n    for (auto &&pi : p) os << pi << \" -> \";\n    return os;\n\
    }\n#line 2 \"geometry/cross_point_ll.hpp\"\n\n#line 2 \"geometry/line.hpp\"\n\n\
    #line 4 \"geometry/line.hpp\"\n\n// line\nstruct Line {\n    Point a, b;\n\n \
    \   Line() = default;\n\n    Line(Point a, Point b) : a(a), b(b) {}\n\n    //\
    \ Ax + By = C\n    Line(Double A, Double B, Double C) {\n        assert(equal(A,\
    \ 0) and equal(B, 0));\n        if (equal(A, 0)) {\n            a = Point(0, C\
    \ / B), b = Point(1, C / B);\n        } else if (equal(B, 0)) {\n            a\
    \ = Point(C / A, 0), b = Point(C / A, 1);\n        } else if (equal(C, 0)) {\n\
    \            a = Point(0, 0), b = Point(1, B / A);\n        } else {\n       \
    \     a = Point(0, C / B), b = Point(C / A, 0);\n        }\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, Line &p) { return is >> p.a >> p.b;\
    \ }\n    friend std::ostream &operator<<(std::ostream &os, const Line &p) { return\
    \ os << p.a << \"->\" << p.b; }\n};\n#line 4 \"geometry/cross_point_ll.hpp\"\n\
    \n// cross point (line and line)\nPoint cross_point_ll(const Line &l1, const Line\
    \ &l2) {\n    Point base = l1.b - l1.a;\n    Double d12 = cross(base, l2.b - l2.a);\n\
    \    Double d1 = cross(base, l1.b - l2.a);\n    if (sign(d12) == 0) {\n      \
    \  // parallel\n        if (sign(d1) == 0) {\n            // cross\n         \
    \   return l2.a;\n        } else {\n            // not cross\n            assert(false);\n\
    \        }\n    }\n    return l2.a + (l2.b - l2.a) * (d1 / d12);\n}\n#line 5 \"\
    geometry/convex_polygon_cut.hpp\"\n\n// cut convex polygon p by line l\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\n\
    // return {left polygon, right polygon}\n// whether each point is included is\
    \ determined by the sign of the outer product of the two vectors to the endpoints\
    \ of the line\nstd::pair<Polygon, Polygon> convex_polygon_cut(const Polygon &p,\
    \ const Line &l) {\n    int n = (int)p.size();\n    assert(n >= 3);\n    Polygon\
    \ pl, pr;\n    for (int i = 0; i < n - 1; i++) {\n        int s1 = sign(cross(l.a\
    \ - p[i], l.b - p[i]));\n        int s2 = sign(cross(l.a - p[i + 1], l.b - p[i\
    \ + 1]));\n        if (s1 >= 0) {\n            pl.push_back(p[i]);\n        }\n\
    \        if (s1 <= 0) {\n            pr.push_back(p[i]);\n        }\n        if\
    \ (s1 * s2 < 0) {\n            // don't use \"<=\", use \"<\" to exclude endpoints\n\
    \            auto pc = cross_point_ll(Line(p[i], p[i + 1]), l);\n            pl.push_back(pc);\n\
    \            pr.push_back(pc);\n        }\n    }\n    {\n        int s1 = sign(cross(l.a\
    \ - p[n - 1], l.b - p[n - 1]));\n        int s2 = sign(cross(l.a - p[0], l.b -\
    \ p[0]));\n        if (s1 >= 0) {\n            pl.push_back(p[n - 1]);\n     \
    \   }\n        if (s1 <= 0) {\n            pr.push_back(p[n - 1]);\n        }\n\
    \        if (s1 * s2 < 0) {\n            // don't use \"<=\", use \"<\" to exclude\
    \ endpoints\n            auto pc = cross_point_ll(Line(p[n - 1], p[0]), l);\n\
    \            pl.push_back(pc);\n            pr.push_back(pc);\n        }\n   \
    \ }\n    return {pl, pr};\n}\n#line 2 \"geometry/polygon_area.hpp\"\n\n#line 4\
    \ \"geometry/polygon_area.hpp\"\n\n// area of polygon\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    Double polygon_area(const Polygon &p) {\n    int n = (int)p.size();\n    assert(n\
    \ >= 2);\n    Double ret = Double(0);\n    for (int i = 0; i < n - 1; i++) {\n\
    \        ret += cross(p[i], p[i + 1]);\n    }\n    ret += cross(p[n - 1], p[0]);\n\
    \    // counter clockwise: ret > 0\n    // clockwise: ret < 0\n    return std::abs(ret)\
    \ / 2;\n}\n#line 8 \"verify/aoj_cgl/aoj_cgl_4_c.test.cpp\"\n\nint main() {\n \
    \   int N;\n    std::cin >> N;\n    Polygon P(N);\n    std::cin >> P;\n    int\
    \ Q;\n    std::cin >> Q;\n    while (Q--) {\n        Line L1;\n        std::cin\
    \ >> L1;\n        Line L2(L1.b, L1.a);\n        auto [rl1, rr1] = convex_polygon_cut(P,\
    \ L1);\n        auto [rl2, rr2] = convex_polygon_cut(P, L2);\n        if (rl1.size()\
    \ >= 2) {\n            assert(equal(polygon_area(rl1), polygon_area(rr2)));\n\
    \        }\n        if (rr1.size() >= 2) {\n            assert(equal(polygon_area(rl2),\
    \ polygon_area(rr1)));\n        }\n        Double ans = (rl1.size() >= 2 ? polygon_area(rl1)\
    \ : 0);\n        std::cout << std::fixed << std::setprecision(15) << ans << '\\\
    n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\"\
    \n#define ERROR 0.00001\n\n#include <bits/stdc++.h>\n\n#include \"geometry/convex_polygon_cut.hpp\"\
    \n#include \"geometry/polygon_area.hpp\"\n\nint main() {\n    int N;\n    std::cin\
    \ >> N;\n    Polygon P(N);\n    std::cin >> P;\n    int Q;\n    std::cin >> Q;\n\
    \    while (Q--) {\n        Line L1;\n        std::cin >> L1;\n        Line L2(L1.b,\
    \ L1.a);\n        auto [rl1, rr1] = convex_polygon_cut(P, L1);\n        auto [rl2,\
    \ rr2] = convex_polygon_cut(P, L2);\n        if (rl1.size() >= 2) {\n        \
    \    assert(equal(polygon_area(rl1), polygon_area(rr2)));\n        }\n       \
    \ if (rr1.size() >= 2) {\n            assert(equal(polygon_area(rl2), polygon_area(rr1)));\n\
    \        }\n        Double ans = (rl1.size() >= 2 ? polygon_area(rl1) : 0);\n\
    \        std::cout << std::fixed << std::setprecision(15) << ans << '\\n';\n \
    \   }\n    return 0;\n}"
  dependsOn:
  - geometry/convex_polygon_cut.hpp
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/cross_point_ll.hpp
  - geometry/line.hpp
  - geometry/polygon_area.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
  requiredBy: []
  timestamp: '2023-02-21 09:00:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_4_c.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_4_c.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_4_c.test.cpp
---
