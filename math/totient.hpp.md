---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_factor.hpp
    title: math/prime_factor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_ntl/aoj_ntl_1_d.test.cpp
    title: verify/aoj_ntl/aoj_ntl_1_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/totient.hpp\"\n\n#line 2 \"math/prime_factor.hpp\"\n\
    \nstd::map<long long, int> prime_factor(long long n) {\n    std::map<long long,\
    \ int> res;\n    for (long long i = 2; i * i <= n; i++) {\n        while (n %\
    \ i == 0) {\n            res[i]++;\n            n /= i;\n        }\n    }\n  \
    \  if (n != 1) res[n]++;\n    return res;\n}\n#line 4 \"math/totient.hpp\"\n\n\
    long long totient(long long n) {\n    auto pf = prime_factor(n);\n    for (auto\
    \ &[p, e] : pf) {\n        n /= p;\n        n *= p - 1;\n    }\n    return n;\n\
    }\n"
  code: "#pragma once\n\n#include \"math/prime_factor.hpp\"\n\nlong long totient(long\
    \ long n) {\n    auto pf = prime_factor(n);\n    for (auto &[p, e] : pf) {\n \
    \       n /= p;\n        n *= p - 1;\n    }\n    return n;\n}"
  dependsOn:
  - math/prime_factor.hpp
  isVerificationFile: false
  path: math/totient.hpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_ntl/aoj_ntl_1_d.test.cpp
documentation_of: math/totient.hpp
layout: document
redirect_from:
- /library/math/totient.hpp
- /library/math/totient.hpp.html
title: math/totient.hpp
---
