---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_itp1/aoj_itp1_3_d.test.cpp
    title: verify/aoj_itp1/aoj_itp1_3_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/divisor.hpp\"\n\nstd::vector<long long> divisor(long\
    \ long n) {\n    std::vector<long long> res;\n    for (long long i = 1; i * i\
    \ <= n; i++) {\n        if (n % i == 0) {\n            res.push_back(i);\n   \
    \         if (i * i != n) res.push_back(n / i);\n        }\n    }\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n}\n"
  code: "#pragma once\n\nstd::vector<long long> divisor(long long n) {\n    std::vector<long\
    \ long> res;\n    for (long long i = 1; i * i <= n; i++) {\n        if (n % i\
    \ == 0) {\n            res.push_back(i);\n            if (i * i != n) res.push_back(n\
    \ / i);\n        }\n    }\n    std::sort(res.begin(), res.end());\n    return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_itp1/aoj_itp1_3_d.test.cpp
documentation_of: math/divisor.hpp
layout: document
redirect_from:
- /library/math/divisor.hpp
- /library/math/divisor.hpp.html
title: math/divisor.hpp
---
