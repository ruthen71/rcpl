---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
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
    \ long long n, const long long mod) {\n    assert(n >= 0 and mod >= 1);\n    a\
    \ %= mod;\n    if (a < 0) a += mod;\n    if (a == 0) return (n == 0 ? (mod !=\
    \ 1 ? 1 : 0) : 0);  // 0 ^ 0 = 1\n    long long res = 1;\n    while (n) {\n  \
    \      if (n & 1) res = res * a % mod;\n        a = a * a % mod;\n        n >>=\
    \ 1;\n    }\n    return res;\n}\n"
  code: "#pragma once\n\nlong long pow_mod(long long a, long long n, const long long\
    \ mod) {\n    assert(n >= 0 and mod >= 1);\n    a %= mod;\n    if (a < 0) a +=\
    \ mod;\n    if (a == 0) return (n == 0 ? (mod != 1 ? 1 : 0) : 0);  // 0 ^ 0 =\
    \ 1\n    long long res = 1;\n    while (n) {\n        if (n & 1) res = res * a\
    \ % mod;\n        a = a * a % mod;\n        n >>= 1;\n    }\n    return res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/pow_mod.hpp
  requiredBy: []
  timestamp: '2022-09-26 00:37:29+09:00'
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
