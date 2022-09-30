---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/baby_step_giant_step.hpp
    title: src/math/baby_step_giant_step.hpp
  - icon: ':warning:'
    path: src/math/inv_mod.hpp
    title: src/math/inv_mod.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
    title: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/ext_gcd.hpp\"\n\n// find (x, y) s.t. ax + by =\
    \ gcd(a, b)\nlong long ext_gcd(long long a, long long b, long long &x, long long\
    \ &y) {\n    if (b == 0) {\n        x = 1, y = 0;\n        return a;\n    }\n\
    \    long long d = ext_gcd(b, a % b, y, x);\n    y -= (a / b) * x;\n    return\
    \ d;\n}\n"
  code: "#pragma once\n\n// find (x, y) s.t. ax + by = gcd(a, b)\nlong long ext_gcd(long\
    \ long a, long long b, long long &x, long long &y) {\n    if (b == 0) {\n    \
    \    x = 1, y = 0;\n        return a;\n    }\n    long long d = ext_gcd(b, a %\
    \ b, y, x);\n    y -= (a / b) * x;\n    return d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/ext_gcd.hpp
  requiredBy:
  - src/math/inv_mod.hpp
  - src/math/baby_step_giant_step.hpp
  timestamp: '2022-09-26 05:21:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_ntl/aoj_ntl_1_e.test.cpp
documentation_of: src/math/ext_gcd.hpp
layout: document
redirect_from:
- /library/src/math/ext_gcd.hpp
- /library/src/math/ext_gcd.hpp.html
title: src/math/ext_gcd.hpp
---
