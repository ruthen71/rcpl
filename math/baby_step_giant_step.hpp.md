---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext_gcd.hpp
    title: math/ext_gcd.hpp
  - icon: ':warning:'
    path: math/inv_mod.hpp
    title: math/inv_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/pow_mod.hpp
    title: math/pow_mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/baby_step_giant_step.hpp\"\n\n#line 2 \"math/inv_mod.hpp\"\
    \n\n#line 2 \"math/ext_gcd.hpp\"\n\n// find (x, y) s.t. ax + by = gcd(a, b)\n\
    long long ext_gcd(long long a, long long b, long long &x, long long &y) {\n  \
    \  if (b == 0) {\n        x = 1, y = 0;\n        return a;\n    }\n    long long\
    \ d = ext_gcd(b, a % b, y, x);\n    y -= (a / b) * x;\n    return d;\n}\n#line\
    \ 4 \"math/inv_mod.hpp\"\n\nlong long inv_mod(long long a, long long mod) {\n\
    \    a %= mod;\n    if (a < 0) a += mod;\n    assert(a != 0);\n    long long x,\
    \ y;\n    ext_gcd(a, mod, x, y);\n    x %= mod;\n    if (x < 0) x += mod;\n  \
    \  return x;\n}\n#line 2 \"math/pow_mod.hpp\"\n\nlong long pow_mod(long long a,\
    \ long long n, const long long mod) {\n    assert(n >= 0 and mod >= 1);\n    if\
    \ (mod == 1) return 0;\n    a %= mod;\n    if (a < 0) a += mod;\n    long long\
    \ res = 1;\n    while (n) {\n        if (n & 1) res = res * a % mod;\n       \
    \ a = a * a % mod;\n        n >>= 1;\n    }\n    return res;\n}\n#line 5 \"math/baby_step_giant_step.hpp\"\
    \n\n// find minimum K s.t. X ^ K = Y (mod M) and K >= lb\n// O(sqrt(M))\nlong\
    \ long baby_step_giant_step(long long X, long long Y, long long M, long long lb\
    \ = 0LL) {\n    X %= M, Y %= M;\n    if (X < 0) X += M;\n    if (Y < 0) Y += M;\n\
    \    if (std::gcd(X, M) != 1) return -1;\n    long long sqM = sqrt(M) + 1;\n \
    \   std::unordered_map<long long, long long> mp;\n    // Baby-step\n    long long\
    \ Z = pow_mod(X, lb, M);  // Z = X ^ lb (mod M)\n    for (int i = 0; i < sqM;\
    \ i++) {\n        if (mp.find(Z) == mp.end()) mp[Z] = i + lb;\n        Z = Z *\
    \ X % M;\n    }\n    // Z = X ^ sqM (mod M)\n    // R = Z ^ (-1) (mod M)\n   \
    \ long long R = inv_mod(pow_mod(X, sqM, M), M);\n    // Giant-step\n    for (int\
    \ i = 0; i <= sqM; i++) {\n        if (mp.find(Y) != mp.end()) return mp[Y] +\
    \ i * sqM;\n        Y = Y * R % M;\n    }\n    return -1;\n}\n"
  code: "#pragma once\n\n#include \"math/inv_mod.hpp\"\n#include \"math/pow_mod.hpp\"\
    \n\n// find minimum K s.t. X ^ K = Y (mod M) and K >= lb\n// O(sqrt(M))\nlong\
    \ long baby_step_giant_step(long long X, long long Y, long long M, long long lb\
    \ = 0LL) {\n    X %= M, Y %= M;\n    if (X < 0) X += M;\n    if (Y < 0) Y += M;\n\
    \    if (std::gcd(X, M) != 1) return -1;\n    long long sqM = sqrt(M) + 1;\n \
    \   std::unordered_map<long long, long long> mp;\n    // Baby-step\n    long long\
    \ Z = pow_mod(X, lb, M);  // Z = X ^ lb (mod M)\n    for (int i = 0; i < sqM;\
    \ i++) {\n        if (mp.find(Z) == mp.end()) mp[Z] = i + lb;\n        Z = Z *\
    \ X % M;\n    }\n    // Z = X ^ sqM (mod M)\n    // R = Z ^ (-1) (mod M)\n   \
    \ long long R = inv_mod(pow_mod(X, sqM, M), M);\n    // Giant-step\n    for (int\
    \ i = 0; i <= sqM; i++) {\n        if (mp.find(Y) != mp.end()) return mp[Y] +\
    \ i * sqM;\n        Y = Y * R % M;\n    }\n    return -1;\n}"
  dependsOn:
  - math/inv_mod.hpp
  - math/ext_gcd.hpp
  - math/pow_mod.hpp
  isVerificationFile: false
  path: math/baby_step_giant_step.hpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/baby_step_giant_step.hpp
layout: document
redirect_from:
- /library/math/baby_step_giant_step.hpp
- /library/math/baby_step_giant_step.hpp.html
title: math/baby_step_giant_step.hpp
---
