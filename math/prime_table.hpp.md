---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/enumerate_primes.hpp
    title: math/enumerate_primes.hpp
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
  bundledCode: "#line 2 \"math/prime_table.hpp\"\n\nstd::vector<bool> prime_table(int\
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
  path: math/prime_table.hpp
  requiredBy:
  - math/enumerate_primes.hpp
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_math/lc_enumerate_primes.test.cpp
  - verify/aoj_alds1/aoj_alds1_1_c.test.cpp
documentation_of: math/prime_table.hpp
layout: document
redirect_from:
- /library/math/prime_table.hpp
- /library/math/prime_table.hpp.html
title: math/prime_table.hpp
---