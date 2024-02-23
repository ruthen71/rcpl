---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/extended_gcd.hpp
    title: math/extended_gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"verify/aoj_ntl/aoj_ntl_1_e.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"math/extended_gcd.hpp\"\n\n#line 4 \"math/extended_gcd.hpp\"\
    \n// find (x, y) s.t. ax + by = gcd(a, b)\n// a, b >= 0\n// return {x, y, gcd(a,\
    \ b)}\ntemplate <class T> std::tuple<T, T, T> extended_gcd(T a, T b) {\n    if\
    \ (b == 0) return {1, 0, a};\n    auto [y, x, g] = extended_gcd(b, a % b);\n \
    \   return {x, y - (a / b) * x, g};\n}\n#line 6 \"verify/aoj_ntl/aoj_ntl_1_e.test.cpp\"\
    \n\nint main() {\n    long long a, b, x, y;\n    std::cin >> a >> b;\n    auto\
    \ [x, y, g] = extended_gcd(a, b);\n    std::cout << x << ' ' << y << '\\n';\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"math/extended_gcd.hpp\"\n\nint main()\
    \ {\n    long long a, b, x, y;\n    std::cin >> a >> b;\n    auto [x, y, g] =\
    \ extended_gcd(a, b);\n    std::cout << x << ' ' << y << '\\n';\n    return 0;\n\
    }"
  dependsOn:
  - math/extended_gcd.hpp
  isVerificationFile: true
  path: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
  requiredBy: []
  timestamp: '2024-02-23 10:38:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_ntl/aoj_ntl_1_e.test.cpp
- /verify/verify/aoj_ntl/aoj_ntl_1_e.test.cpp.html
title: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
---
