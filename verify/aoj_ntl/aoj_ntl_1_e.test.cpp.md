---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/extgcd.hpp
    title: src/math/extgcd.hpp
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
    \ <bits/stdc++.h>\n\n#line 2 \"src/math/extgcd.hpp\"\n\n// find (x, y) s.t. ax\
    \ + by = gcd(a, b)\nlong long extgcd(long long a, long long b, long long &x, long\
    \ long &y) {\n    if (b == 0) {\n        x = 1, y = 0;\n        return a;\n  \
    \  }\n    long long d = extgcd(b, a % b, y, x);\n    y -= (a / b) * x;\n    return\
    \ d;\n}\n#line 6 \"verify/aoj_ntl/aoj_ntl_1_e.test.cpp\"\n\nint main() {\n   \
    \ long long a, b, x, y;\n    std::cin >> a >> b;\n    extgcd(a, b, x, y);\n  \
    \  std::cout << x << ' ' << y << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"src/math/extgcd.hpp\"\n\nint main()\
    \ {\n    long long a, b, x, y;\n    std::cin >> a >> b;\n    extgcd(a, b, x, y);\n\
    \    std::cout << x << ' ' << y << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/math/extgcd.hpp
  isVerificationFile: true
  path: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
  requiredBy: []
  timestamp: '2022-09-26 05:00:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_ntl/aoj_ntl_1_e.test.cpp
- /verify/verify/aoj_ntl/aoj_ntl_1_e.test.cpp.html
title: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
---
