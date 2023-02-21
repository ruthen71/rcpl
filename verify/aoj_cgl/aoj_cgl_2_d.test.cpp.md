---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_sp.hpp
    title: geometry/distance_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_ss.hpp
    title: geometry/distance_ss.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_sp.hpp
    title: geometry/is_intersect_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_ss.hpp
    title: geometry/is_intersect_ss.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_2_d.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\"\n#define ERROR\
    \ 0.00000001\n\n#include <bits/stdc++.h>\n\n#line 2 \"geometry/distance_ss.hpp\"\
    \n\n#line 2 \"geometry/segment.hpp\"\n\n#line 2 \"geometry/line.hpp\"\n\n#line\
    \ 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\n\n//\
    \ template\nusing Double = double;\nconst Double EPS = 1e-8;\nconst Double PI\
    \ = std::acos(-1);\ninline int sign(const Double &x) { return x <= -EPS ? -1 :\
    \ (x >= EPS ? 1 : 0); }\ninline bool equal(const Double &a, const Double &b) {\
    \ return sign(a - b) == 0; }\nDouble radian_to_degree(const Double &r) { return\
    \ r * 180.0 / PI; }\nDouble degree_to_radian(const Double &d) { return d * PI\
    \ / 180.0; }\n#line 4 \"geometry/point.hpp\"\n\n// point\nusing Point = std::complex<Double>;\n\
    std::istream &operator>>(std::istream &is, Point &p) {\n    Double x, y;\n   \
    \ is >> x >> y;\n    p = Point(x, y);\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
    \ &os, Point &p) {\n    os << std::fixed << std::setprecision(15);\n    return\
    \ os << p.real() << ' ' << p.imag();\n}\n\nnamespace std {\nbool operator<(const\
    \ Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real()\
    \ : a.imag() < b.imag(); }\n}  // namespace std\n\nPoint operator*(const Point\
    \ &p, const Double &k) { return Point(p.real() * k, p.imag() * k); }\nPoint operator/(const\
    \ Point &p, const Double &k) { return Point(p.real() / k, p.imag() / k); }\n//\
    \ equal (point and point)\ninline bool equal(const Point &a, const Point &b) {\
    \ return equal(a.real(), b.real()) and equal(a.imag(), b.imag()); }\n// inner\
    \ product\ninline Double dot(const Point &a, const Point &b) { return a.real()\
    \ * b.real() + a.imag() * b.imag(); }\n// outer product\ninline Double cross(const\
    \ Point &a, const Point &b) { return a.real() * b.imag() - a.imag() * b.real();\
    \ }\n// rotate Point p counterclockwise by theta radian\ninline Point rotate(const\
    \ Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }\n\
    // compare (x, y)\ninline bool compare_x(const Point &a, const Point &b) { return\
    \ equal(a.real(), b.real()) ? sign(a.imag() - b.imag()) < 0 : sign(a.real() -\
    \ b.real()) < 0; }\n// compare (y, x)\ninline bool compare_y(const Point &a, const\
    \ Point &b) { return equal(a.imag(), b.imag()) ? sign(a.real() - b.real()) < 0\
    \ : sign(a.imag() - b.imag()) < 0; }\n#line 4 \"geometry/line.hpp\"\n\n// line\n\
    struct Line {\n    Point a, b;\n\n    Line() = default;\n\n    Line(Point a, Point\
    \ b) : a(a), b(b) {}\n\n    // Ax + By = C\n    Line(Double A, Double B, Double\
    \ C) {\n        assert(equal(A, 0) and equal(B, 0));\n        if (equal(A, 0))\
    \ {\n            a = Point(0, C / B), b = Point(1, C / B);\n        } else if\
    \ (equal(B, 0)) {\n            a = Point(C / A, 0), b = Point(C / A, 1);\n   \
    \     } else if (equal(C, 0)) {\n            a = Point(0, 0), b = Point(1, B /\
    \ A);\n        } else {\n            a = Point(0, C / B), b = Point(C / A, 0);\n\
    \        }\n    }\n\n    friend std::istream &operator>>(std::istream &is, Line\
    \ &p) { return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 4 \"geometry/segment.hpp\"\
    \n\n// segment\nstruct Segment : Line {\n    Segment() = default;\n\n    Segment(Point\
    \ a, Point b) : Line(a, b) {}\n};\n#line 2 \"geometry/is_intersect_ss.hpp\"\n\n\
    #line 2 \"geometry/ccw.hpp\"\n\n#line 4 \"geometry/ccw.hpp\"\n\n// counter clockwise\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\nconstexpr\
    \ int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int CLOCKWISE\
    \ = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2;        // c-a-b\
    \ line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr int ON_SEGMENT\
    \ = 0;         // a-c-b line\nint ccw(const Point &a, Point b, Point c) {\n  \
    \  b = b - a, c = c - a;\n    if (sign(cross(b, c)) == 1) return COUNTER_CLOCKWISE;\n\
    \    if (sign(cross(b, c)) == -1) return CLOCKWISE;\n    if (sign(dot(b, c)) ==\
    \ -1) return ONLINE_BACK;\n    if (std::norm(b) < std::norm(c)) return ONLINE_FRONT;\n\
    \    return ON_SEGMENT;\n}\n#line 5 \"geometry/is_intersect_ss.hpp\"\n\n// intersection\
    \ (segment and segment)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B\n\
    bool is_intersect_ss(const Segment &s1, const Segment &s2) { return (ccw(s1.a,\
    \ s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 and ccw(s2.a, s2.b, s1.a) * ccw(s2.a,\
    \ s2.b, s1.b) <= 0); }\n#line 2 \"geometry/distance_sp.hpp\"\n\n#line 2 \"geometry/projection.hpp\"\
    \n\n#line 5 \"geometry/projection.hpp\"\n\n// projection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    Point projection(const Line &l, const Point &p) {\n    Double t = dot(p - l.a,\
    \ l.b - l.a) / std::norm(l.b - l.a);\n    return l.a + t * (l.b - l.a);\n}\n#line\
    \ 2 \"geometry/is_intersect_sp.hpp\"\n\n#line 5 \"geometry/is_intersect_sp.hpp\"\
    \n\n// intersection (segment and point)\n// ccw(a, b, c) == ON_SEGMENT -> a -\
    \ c - b\nbool is_intersect_sp(const Segment &s, const Point &p) { return ccw(s.a,\
    \ s.b, p) == ON_SEGMENT or sign(std::abs(s.a - p)) == 0 or sign(std::abs(s.b -\
    \ p)) == 0; }\n#line 7 \"geometry/distance_sp.hpp\"\n\n// distance (segment and\
    \ point)\nDouble distance_sp(const Segment &s, const Point &p) {\n    Point r\
    \ = projection(s, p);\n    if (is_intersect_sp(s, r)) {\n        return std::abs(r\
    \ - p);\n    }\n    return std::min(std::abs(s.a - p), std::abs(s.b - p));\n}\n\
    #line 6 \"geometry/distance_ss.hpp\"\n\n// distance (segment and segment)\n//\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\nDouble distance_ss(const\
    \ Segment &s1, const Segment &s2) {\n    if (is_intersect_ss(s1, s2)) return Double(0);\n\
    \    return std::min({distance_sp(s1, s2.a), distance_sp(s1, s2.b), distance_sp(s2,\
    \ s1.a), distance_sp(s2, s1.b)});\n}\n#line 7 \"verify/aoj_cgl/aoj_cgl_2_d.test.cpp\"\
    \n\nint main() {\n    int Q;\n    std::cin >> Q;\n    while (Q--) {\n        Segment\
    \ S1, S2;\n        std::cin >> S1 >> S2;\n        auto d = distance_ss(S1, S2);\n\
    \        std::cout << std::fixed << std::setprecision(15) << d << '\\n';\n   \
    \ }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\"\
    \n#define ERROR 0.00000001\n\n#include <bits/stdc++.h>\n\n#include \"geometry/distance_ss.hpp\"\
    \n\nint main() {\n    int Q;\n    std::cin >> Q;\n    while (Q--) {\n        Segment\
    \ S1, S2;\n        std::cin >> S1 >> S2;\n        auto d = distance_ss(S1, S2);\n\
    \        std::cout << std::fixed << std::setprecision(15) << d << '\\n';\n   \
    \ }\n    return 0;\n}"
  dependsOn:
  - geometry/distance_ss.hpp
  - geometry/segment.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/is_intersect_ss.hpp
  - geometry/ccw.hpp
  - geometry/distance_sp.hpp
  - geometry/projection.hpp
  - geometry/is_intersect_sp.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
  requiredBy: []
  timestamp: '2023-02-21 21:25:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_2_d.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_2_d.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
---
