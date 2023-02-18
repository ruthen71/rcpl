---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/totient.hpp
    title: math/totient.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_ntl/aoj_ntl_1_a.test.cpp
    title: verify/aoj_ntl/aoj_ntl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_ntl/aoj_ntl_1_d.test.cpp
    title: verify/aoj_ntl/aoj_ntl_1_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime_factor.hpp\"\n\nstd::map<long long, int> prime_factor(long\
    \ long n) {\n    std::map<long long, int> res;\n    for (long long i = 2; i *\
    \ i <= n; i++) {\n        while (n % i == 0) {\n            res[i]++;\n      \
    \      n /= i;\n        }\n    }\n    if (n != 1) res[n]++;\n    return res;\n\
    }\n"
  code: "#pragma once\n\nstd::map<long long, int> prime_factor(long long n) {\n  \
    \  std::map<long long, int> res;\n    for (long long i = 2; i * i <= n; i++) {\n\
    \        while (n % i == 0) {\n            res[i]++;\n            n /= i;\n  \
    \      }\n    }\n    if (n != 1) res[n]++;\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factor.hpp
  requiredBy:
  - math/totient.hpp
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_ntl/aoj_ntl_1_d.test.cpp
  - verify/aoj_ntl/aoj_ntl_1_a.test.cpp
documentation_of: math/prime_factor.hpp
layout: document
redirect_from:
- /library/math/prime_factor.hpp
- /library/math/prime_factor.hpp.html
title: math/prime_factor.hpp
---
