---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_table.hpp
    title: math/prime_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_math/lc_enumerate_primes.test.cpp
    title: verify/lc_math/lc_enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/enumerate_primes.hpp\"\n\n#line 2 \"math/prime_table.hpp\"\
    \n\nstd::vector<bool> prime_table(int n) {\n    std::vector<bool> res(n + 1, true);\n\
    \    if (n >= 0) res[0] = false;\n    if (n >= 1) res[1] = false;\n    for (int\
    \ p = 2; p * p <= n; p++) {\n        if (!res[p]) continue;\n        for (int\
    \ i = p * p; i <= n; i += p) {\n            res[i] = false;\n        }\n    }\n\
    \    return res;\n}\n#line 4 \"math/enumerate_primes.hpp\"\n\nstd::vector<int>\
    \ enumerate_primes(int n) {\n    auto pt = prime_table(n);\n    std::vector<int>\
    \ res;\n    res.reserve(std::count(pt.begin(), pt.end(), true));\n    for (int\
    \ i = 0; i < pt.size(); i++) {\n        if (pt[i]) res.push_back(i);\n    }\n\
    \    return res;\n}\n"
  code: "#pragma once\n\n#include \"math/prime_table.hpp\"\n\nstd::vector<int> enumerate_primes(int\
    \ n) {\n    auto pt = prime_table(n);\n    std::vector<int> res;\n    res.reserve(std::count(pt.begin(),\
    \ pt.end(), true));\n    for (int i = 0; i < pt.size(); i++) {\n        if (pt[i])\
    \ res.push_back(i);\n    }\n    return res;\n}"
  dependsOn:
  - math/prime_table.hpp
  isVerificationFile: false
  path: math/enumerate_primes.hpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_math/lc_enumerate_primes.test.cpp
documentation_of: math/enumerate_primes.hpp
layout: document
redirect_from:
- /library/math/enumerate_primes.hpp
- /library/math/enumerate_primes.hpp.html
title: math/enumerate_primes.hpp
---
