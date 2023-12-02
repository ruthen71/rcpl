---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/baby_step_giant_step.hpp
    title: math/baby_step_giant_step.hpp
  - icon: ':warning:'
    path: math/inv_mod.hpp
    title: math/inv_mod.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
    title: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ext_gcd.hpp\"\n\n// find (x, y) s.t. ax + by = gcd(a,\
    \ b)\nlong long ext_gcd(long long a, long long b, long long &x, long long &y)\
    \ {\n    if (b == 0) {\n        x = 1, y = 0;\n        return a;\n    }\n    long\
    \ long d = ext_gcd(b, a % b, y, x);\n    y -= (a / b) * x;\n    return d;\n}\n"
  code: "#pragma once\n\n// find (x, y) s.t. ax + by = gcd(a, b)\nlong long ext_gcd(long\
    \ long a, long long b, long long &x, long long &y) {\n    if (b == 0) {\n    \
    \    x = 1, y = 0;\n        return a;\n    }\n    long long d = ext_gcd(b, a %\
    \ b, y, x);\n    y -= (a / b) * x;\n    return d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/ext_gcd.hpp
  requiredBy:
  - math/baby_step_giant_step.hpp
  - math/inv_mod.hpp
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_ntl/aoj_ntl_1_e.test.cpp
documentation_of: math/ext_gcd.hpp
layout: document
redirect_from:
- /library/math/ext_gcd.hpp
- /library/math/ext_gcd.hpp.html
title: math/ext_gcd.hpp
---
