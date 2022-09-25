---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/ext_gcd.hpp
    title: src/math/ext_gcd.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/baby_step_giant_step.hpp
    title: src/math/baby_step_giant_step.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/inv.hpp\"\n\n#line 2 \"src/math/ext_gcd.hpp\"\n\
    \n// find (x, y) s.t. ax + by = gcd(a, b)\nlong long ext_gcd(long long a, long\
    \ long b, long long &x, long long &y) {\n    if (b == 0) {\n        x = 1, y =\
    \ 0;\n        return a;\n    }\n    long long d = ext_gcd(b, a % b, y, x);\n \
    \   y -= (a / b) * x;\n    return d;\n}\n#line 4 \"src/math/inv.hpp\"\n\nlong\
    \ long inv(long long a, long long mod) {\n    assert(a != 0);\n    long long x,\
    \ y;\n    ext_gcd(a, mod, x, y);\n    x %= mod;\n    if (x < 0) x += mod;\n  \
    \  return x;\n}\n"
  code: "#pragma once\n\n#include \"src/math/ext_gcd.hpp\"\n\nlong long inv(long long\
    \ a, long long mod) {\n    assert(a != 0);\n    long long x, y;\n    ext_gcd(a,\
    \ mod, x, y);\n    x %= mod;\n    if (x < 0) x += mod;\n    return x;\n}\n"
  dependsOn:
  - src/math/ext_gcd.hpp
  isVerificationFile: false
  path: src/math/inv.hpp
  requiredBy:
  - src/math/baby_step_giant_step.hpp
  timestamp: '2022-09-26 05:21:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/inv.hpp
layout: document
redirect_from:
- /library/src/math/inv.hpp
- /library/src/math/inv.hpp.html
title: src/math/inv.hpp
---
