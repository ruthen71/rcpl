---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/baby_step_giant_step.hpp
    title: src/math/baby_step_giant_step.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_ntl/aoj_ntl_1_b.test.cpp
    title: verify/aoj_ntl/aoj_ntl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/pow_mod.hpp\"\n\nlong long pow_mod(long long a,\
    \ long long n, const long long mod) {\n    assert(n >= 0 and mod >= 1);\n    if\
    \ (mod == 1) return 0;\n    a %= mod;\n    if (a < 0) a += mod;\n    long long\
    \ res = 1;\n    while (n) {\n        if (n & 1) res = res * a % mod;\n       \
    \ a = a * a % mod;\n        n >>= 1;\n    }\n    return res;\n}\n"
  code: "#pragma once\n\nlong long pow_mod(long long a, long long n, const long long\
    \ mod) {\n    assert(n >= 0 and mod >= 1);\n    if (mod == 1) return 0;\n    a\
    \ %= mod;\n    if (a < 0) a += mod;\n    long long res = 1;\n    while (n) {\n\
    \        if (n & 1) res = res * a % mod;\n        a = a * a % mod;\n        n\
    \ >>= 1;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/pow_mod.hpp
  requiredBy:
  - src/math/baby_step_giant_step.hpp
  timestamp: '2022-09-26 06:39:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_ntl/aoj_ntl_1_b.test.cpp
documentation_of: src/math/pow_mod.hpp
layout: document
redirect_from:
- /library/src/math/pow_mod.hpp
- /library/src/math/pow_mod.hpp.html
title: src/math/pow_mod.hpp
---