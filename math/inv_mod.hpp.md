---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext_gcd.hpp
    title: math/ext_gcd.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/baby_step_giant_step.hpp
    title: math/baby_step_giant_step.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/inv_mod.hpp\"\n\n#line 2 \"math/ext_gcd.hpp\"\n\n//\
    \ find (x, y) s.t. ax + by = gcd(a, b)\nlong long ext_gcd(long long a, long long\
    \ b, long long &x, long long &y) {\n    if (b == 0) {\n        x = 1, y = 0;\n\
    \        return a;\n    }\n    long long d = ext_gcd(b, a % b, y, x);\n    y -=\
    \ (a / b) * x;\n    return d;\n}\n#line 4 \"math/inv_mod.hpp\"\n\nlong long inv_mod(long\
    \ long a, long long mod) {\n    a %= mod;\n    if (a < 0) a += mod;\n    assert(a\
    \ != 0);\n    long long x, y;\n    ext_gcd(a, mod, x, y);\n    x %= mod;\n   \
    \ if (x < 0) x += mod;\n    return x;\n}\n"
  code: "#pragma once\n\n#include \"math/ext_gcd.hpp\"\n\nlong long inv_mod(long long\
    \ a, long long mod) {\n    a %= mod;\n    if (a < 0) a += mod;\n    assert(a !=\
    \ 0);\n    long long x, y;\n    ext_gcd(a, mod, x, y);\n    x %= mod;\n    if\
    \ (x < 0) x += mod;\n    return x;\n}"
  dependsOn:
  - math/ext_gcd.hpp
  isVerificationFile: false
  path: math/inv_mod.hpp
  requiredBy:
  - math/baby_step_giant_step.hpp
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/inv_mod.hpp
layout: document
redirect_from:
- /library/math/inv_mod.hpp
- /library/math/inv_mod.hpp.html
title: math/inv_mod.hpp
---
