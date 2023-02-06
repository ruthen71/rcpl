---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext_gcd.hpp
    title: math/ext_gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"verify/aoj_ntl/aoj_ntl_1_e.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"math/ext_gcd.hpp\"\n\n// find (x, y) s.t. ax +\
    \ by = gcd(a, b)\nlong long ext_gcd(long long a, long long b, long long &x, long\
    \ long &y) {\n    if (b == 0) {\n        x = 1, y = 0;\n        return a;\n  \
    \  }\n    long long d = ext_gcd(b, a % b, y, x);\n    y -= (a / b) * x;\n    return\
    \ d;\n}\n#line 6 \"verify/aoj_ntl/aoj_ntl_1_e.test.cpp\"\n\nint main() {\n   \
    \ long long a, b, x, y;\n    std::cin >> a >> b;\n    ext_gcd(a, b, x, y);\n \
    \   std::cout << x << ' ' << y << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"math/ext_gcd.hpp\"\n\nint main() {\n\
    \    long long a, b, x, y;\n    std::cin >> a >> b;\n    ext_gcd(a, b, x, y);\n\
    \    std::cout << x << ' ' << y << '\\n';\n    return 0;\n}"
  dependsOn:
  - math/ext_gcd.hpp
  isVerificationFile: true
  path: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_ntl/aoj_ntl_1_e.test.cpp
- /verify/verify/aoj_ntl/aoj_ntl_1_e.test.cpp.html
title: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
---
