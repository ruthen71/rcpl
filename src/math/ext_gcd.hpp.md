---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/baby_step_giant_step.hpp
    title: src/math/baby_step_giant_step.hpp
  - icon: ':warning:'
    path: src/math/inv.hpp
    title: src/math/inv.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  - src/math/baby_step_giant_step.hpp
  - src/math/inv.hpp
  timestamp: '2022-09-26 05:21:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/ext_gcd.hpp
layout: document
redirect_from:
- /library/src/math/ext_gcd.hpp
- /library/src/math/ext_gcd.hpp.html
title: src/math/ext_gcd.hpp
---
