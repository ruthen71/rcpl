---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
    title: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/extgcd.hpp\"\n\n// find (x, y) s.t. ax + by = gcd(a,\
    \ b)\nlong long extgcd(long long a, long long b, long long &x, long long &y) {\n\
    \    if (b == 0) {\n        x = 1, y = 0;\n        return a;\n    }\n    long\
    \ long d = extgcd(b, a % b, y, x);\n    y -= (a / b) * x;\n    return d;\n}\n"
  code: "#pragma once\n\n// find (x, y) s.t. ax + by = gcd(a, b)\nlong long extgcd(long\
    \ long a, long long b, long long &x, long long &y) {\n    if (b == 0) {\n    \
    \    x = 1, y = 0;\n        return a;\n    }\n    long long d = extgcd(b, a %\
    \ b, y, x);\n    y -= (a / b) * x;\n    return d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/extgcd.hpp
  requiredBy: []
  timestamp: '2022-09-26 05:00:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_ntl/aoj_ntl_1_e.test.cpp
documentation_of: src/math/extgcd.hpp
layout: document
redirect_from:
- /library/src/math/extgcd.hpp
- /library/src/math/extgcd.hpp.html
title: src/math/extgcd.hpp
---
