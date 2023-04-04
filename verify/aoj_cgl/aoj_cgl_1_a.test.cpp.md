---
data:
  _extendedDependsOn:
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
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_1_a.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\"\n#define ERROR\
    \ 0.00000001\n\n#include <bits/stdc++.h>\n\n#line 2 \"geometry/projection.hpp\"\
    \n\n#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n#line 2\
    \ \"geometry/geometry_template.hpp\"\n\n// template\nusing Double = double;\n\
    const Double EPS = 1e-8;\n// using Double = long double;\n// const Double EPS\
    \ = 1e-10;\n// using Double = long long;\n// const Double EPS = 0;\n// using Double\
    \ = __int128_t;\n// const Double EPS = 0;\nconst Double PI = std::acos(Double(-1));\n\
    inline int sign(const Double &x) { return x < -EPS ? -1 : (x > EPS ? 1 : 0); }\n\
    inline bool equal(const Double &a, const Double &b) { return sign(a - b) == 0;\
    \ }\ninline Double radian_to_degree(const Double &r) { return r * 180.0 / PI;\
    \ }\ninline Double degree_to_radian(const Double &d) { return d * PI / 180.0;\
    \ }\nconstexpr int IN = 2;\nconstexpr int ON = 1;\nconstexpr int OUT = 0;\n#line\
    \ 4 \"geometry/point.hpp\"\n\n// point\nstruct Point {\n    Double x, y;\n   \
    \ Point(const Double x = Double(0), const Double y = Double(0)) : x(x), y(y) {}\n\
    \    Point &operator+=(const Point &p) {\n        x += p.x;\n        y += p.y;\n\
    \        return *this;\n    }\n    Point &operator-=(const Point &p) {\n     \
    \   x -= p.x;\n        y -= p.y;\n        return *this;\n    }\n    Point &operator*=(const\
    \ Point &p) { return *this = Point(x * p.x - y * p.y, x * p.y + y * p.x); }\n\
    \    Point &operator*=(const Double &k) {\n        x *= k;\n        y *= k;\n\
    \        return *this;\n    }\n    Point &operator/=(const Point &p) { return\
    \ *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / (p.x * p.x + p.y * p.y);\
    \ }\n    Point &operator/=(const Double &k) {\n        x /= k;\n        y /= k;\n\
    \        return *this;\n    }\n\n    Point operator+() const { return *this; }\n\
    \    Point operator-() const { return Point(-x, -y); }\n\n    friend Point operator+(const\
    \ Point &a, const Point &b) { return Point(a) += b; }\n    friend Point operator-(const\
    \ Point &a, const Point &b) { return Point(a) -= b; }\n    friend Point operator*(const\
    \ Point &a, const Point &b) { return Point(a) *= b; }\n    friend Point operator*(const\
    \ Point &p, const Double &k) { return Point(p) *= k; }\n    friend Point operator/(const\
    \ Point &a, const Point &b) { return Point(a) /= b; }\n    friend Point operator/(const\
    \ Point &p, const Double &k) { return Point(p) /= k; }\n    // for std::set, std::map,\
    \ compare_arg, ...\n    friend bool operator<(const Point &a, const Point &b)\
    \ { return a.x == b.x ? a.y < b.y : a.x < b.x; }\n};\n\n// using Point = std::complex<Double>;\n\
    std::istream &operator>>(std::istream &is, Point &p) { return is >> p.x >> p.y;\
    \ }\nstd::ostream &operator<<(std::ostream &os, const Point &p) { return os <<\
    \ std::fixed << std::setprecision(15) << p.x << ' ' << p.y; }\n\n// equal (point\
    \ and point)\ninline bool equal(const Point &a, const Point &b) { return equal(a.x,\
    \ b.x) and equal(a.y, b.y); }\n// inner product\ninline Double dot(const Point\
    \ &a, const Point &b) { return a.x * b.x + a.y * b.y; }\n// outer product\ninline\
    \ Double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x;\
    \ }\n// rotate Point p counterclockwise by theta radian\ninline Point rotate(const\
    \ Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }\n\
    // compare (x, y)\ninline bool compare_x(const Point &a, const Point &b) { return\
    \ equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x - b.x) < 0; }\n// compare (y,\
    \ x)\ninline bool compare_y(const Point &a, const Point &b) { return equal(a.y,\
    \ b.y) ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }\n// compare by arg (start\
    \ from 90.0000000001~)\ninline bool compare_arg(const Point &a, const Point &b)\
    \ {\n    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n    return\
    \ (Point(0, 0) < a) == (Point(0, 0) < b) ? a.x * b.y > a.y * b.x : a < b;\n}\n\
    // |p| ^ 2\ninline Double norm(const Point &p) { return p.x * p.x + p.y * p.y;\
    \ }\n// |p|\ninline Double abs(const Point &p) { return sqrt(norm(p)); }\n// arg\n\
    inline Double arg(const Point &p) { return std::atan2(p.y, p.x); }\n// polar\n\
    inline Point polar(const Double &rho, const Double &theta = Double(0)) { return\
    \ rotate(Point(rho, 0), theta); }\n#line 4 \"geometry/line.hpp\"\n\n// line\n\
    struct Line {\n    Point a, b;\n\n    Line() = default;\n\n    Line(const Point\
    \ &a, const Point &b) : a(a), b(b) {}\n\n    // Ax + By = C\n    Line(const Double\
    \ &A, const Double &B, const Double &C) {\n        assert(equal(A, 0) and equal(B,\
    \ 0));\n        if (equal(A, 0)) {\n            a = Point(0, C / B), b = Point(1,\
    \ C / B);\n        } else if (equal(B, 0)) {\n            a = Point(C / A, 0),\
    \ b = Point(C / A, 1);\n        } else if (equal(C, 0)) {\n            a = Point(0,\
    \ 0), b = Point(1, B / A);\n        } else {\n            a = Point(0, C / B),\
    \ b = Point(C / A, 0);\n        }\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Line &p) { return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 5 \"geometry/projection.hpp\"\
    \n\n// projection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    Point projection(const Line &l, const Point &p) {\n    Double t = dot(p - l.a,\
    \ l.b - l.a) / norm(l.b - l.a);\n    return l.a + t * (l.b - l.a);\n}\n#line 7\
    \ \"verify/aoj_cgl/aoj_cgl_1_a.test.cpp\"\n\nint main() {\n    Line L;\n    std::cin\
    \ >> L;\n    int Q;\n    std::cin >> Q;\n    while (Q--) {\n        Point P;\n\
    \        std::cin >> P;\n        auto ans = projection(L, P);\n        std::cout\
    \ << ans << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\"\
    \n#define ERROR 0.00000001\n\n#include <bits/stdc++.h>\n\n#include \"geometry/projection.hpp\"\
    \n\nint main() {\n    Line L;\n    std::cin >> L;\n    int Q;\n    std::cin >>\
    \ Q;\n    while (Q--) {\n        Point P;\n        std::cin >> P;\n        auto\
    \ ans = projection(L, P);\n        std::cout << ans << '\\n';\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - geometry/projection.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_1_a.test.cpp
  requiredBy: []
  timestamp: '2023-04-04 19:34:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_1_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_1_a.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_1_a.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_1_a.test.cpp
---
