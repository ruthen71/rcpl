---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':question:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':question:'
    path: geometry/polygon_area.hpp
    title: geometry/polygon_area.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_3_a.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\n#define ERROR\
    \ 0.00000001\n\n#include <bits/stdc++.h>\n\n#line 2 \"geometry/polygon_area.hpp\"\
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
    \ os;\n}\n#line 4 \"geometry/polygon_area.hpp\"\n\n// area of polygon\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    Double polygon_area(const Polygon &p) {\n    int n = (int)p.size();\n    assert(n\
    \ >= 2);\n    Double ret = Double(0);\n    for (int i = 0; i < n - 1; i++) {\n\
    \        ret += cross(p[i], p[i + 1]);\n    }\n    ret += cross(p[n - 1], p[0]);\n\
    \    // counter clockwise: ret > 0\n    // clockwise: ret < 0\n    return std::abs(ret)\
    \ / 2;\n}\n#line 7 \"verify/aoj_cgl/aoj_cgl_3_a.test.cpp\"\n\nint main() {\n \
    \   int N;\n    std::cin >> N;\n    Polygon P(N);\n    std::cin >> P;\n    std::cout\
    \ << std::fixed << std::setprecision(15) << polygon_area(P) << '\\n';\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
    \n#define ERROR 0.00000001\n\n#include <bits/stdc++.h>\n\n#include \"geometry/polygon_area.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    Polygon P(N);\n    std::cin\
    \ >> P;\n    std::cout << std::fixed << std::setprecision(15) << polygon_area(P)\
    \ << '\\n';\n    return 0;\n}"
  dependsOn:
  - geometry/polygon_area.hpp
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_3_a.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 00:14:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_3_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_3_a.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_3_a.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_3_a.test.cpp
---