---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/enumerate_primes.hpp
    title: src/math/enumerate_primes.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_alds1/aoj_alds1_1_c.test.cpp
    title: verify/aoj_alds1/aoj_alds1_1_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_math/lc_enumerate_primes.test.cpp
    title: verify/lc_math/lc_enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/prime_table.hpp\"\n\nstd::vector<bool> prime_table(int\
    \ n) {\n    std::vector<bool> res(n + 1, true);\n    if (n >= 0) res[0] = false;\n\
    \    if (n >= 1) res[1] = false;\n    for (int p = 2; p * p <= n; p++) {\n   \
    \     if (!res[p]) continue;\n        for (int i = p * p; i <= n; i += p) {\n\
    \            res[i] = false;\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\nstd::vector<bool> prime_table(int n) {\n    std::vector<bool>\
    \ res(n + 1, true);\n    if (n >= 0) res[0] = false;\n    if (n >= 1) res[1] =\
    \ false;\n    for (int p = 2; p * p <= n; p++) {\n        if (!res[p]) continue;\n\
    \        for (int i = p * p; i <= n; i += p) {\n            res[i] = false;\n\
    \        }\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/prime_table.hpp
  requiredBy:
  - src/math/enumerate_primes.hpp
  timestamp: '2022-09-06 17:08:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_alds1/aoj_alds1_1_c.test.cpp
  - verify/lc_math/lc_enumerate_primes.test.cpp
documentation_of: src/math/prime_table.hpp
layout: document
redirect_from:
- /library/src/math/prime_table.hpp
- /library/src/math/prime_table.hpp.html
title: src/math/prime_table.hpp
---
