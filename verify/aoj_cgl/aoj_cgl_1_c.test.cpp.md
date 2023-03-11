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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
  bundledCode: "#line 1 \"verify/aoj_cgl/aoj_cgl_1_c.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"geometry/ccw.hpp\"\n\n#line 2 \"geometry/point.hpp\"\
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
    #line 4 \"geometry/ccw.hpp\"\n\n// counter clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int\
    \ CLOCKWISE = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2; \
    \       // c-a-b line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr\
    \ int ON_SEGMENT = 0;         // a-c-b line\nint ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b, c)) == 1) return\
    \ COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return CLOCKWISE;\n   \
    \ if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (std::norm(b) < std::norm(c))\
    \ return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n#line 6 \"verify/aoj_cgl/aoj_cgl_1_c.test.cpp\"\
    \n\nint main() {\n    Point P1, P2;\n    std::cin >> P1 >> P2;\n    int Q;\n \
    \   std::cin >> Q;\n    while (Q--) {\n        Point P3;\n        std::cin >>\
    \ P3;\n        auto ans = ccw(P1, P2, P3);\n        if (ans == COUNTER_CLOCKWISE)\
    \ {\n            std::cout << \"COUNTER_CLOCKWISE\\n\";\n        } else if (ans\
    \ == CLOCKWISE) {\n            std::cout << \"CLOCKWISE\\n\";\n        } else\
    \ if (ans == ONLINE_BACK) {\n            std::cout << \"ONLINE_BACK\\n\";\n  \
    \      } else if (ans == ONLINE_FRONT) {\n            std::cout << \"ONLINE_FRONT\\\
    n\";\n        } else {\n            std::cout << \"ON_SEGMENT\\n\";\n        }\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"geometry/ccw.hpp\"\n\nint main() {\n\
    \    Point P1, P2;\n    std::cin >> P1 >> P2;\n    int Q;\n    std::cin >> Q;\n\
    \    while (Q--) {\n        Point P3;\n        std::cin >> P3;\n        auto ans\
    \ = ccw(P1, P2, P3);\n        if (ans == COUNTER_CLOCKWISE) {\n            std::cout\
    \ << \"COUNTER_CLOCKWISE\\n\";\n        } else if (ans == CLOCKWISE) {\n     \
    \       std::cout << \"CLOCKWISE\\n\";\n        } else if (ans == ONLINE_BACK)\
    \ {\n            std::cout << \"ONLINE_BACK\\n\";\n        } else if (ans == ONLINE_FRONT)\
    \ {\n            std::cout << \"ONLINE_FRONT\\n\";\n        } else {\n       \
    \     std::cout << \"ON_SEGMENT\\n\";\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - geometry/ccw.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: true
  path: verify/aoj_cgl/aoj_cgl_1_c.test.cpp
  requiredBy: []
  timestamp: '2023-03-12 06:40:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_cgl/aoj_cgl_1_c.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_cgl/aoj_cgl_1_c.test.cpp
- /verify/verify/aoj_cgl/aoj_cgl_1_c.test.cpp.html
title: verify/aoj_cgl/aoj_cgl_1_c.test.cpp
---
