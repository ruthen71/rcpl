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
  bundledCode: "#line 2 \"math/divisor.hpp\"\n\ntemplate <class T> std::vector<T>\
    \ divisor(const T n) {\n    std::vector<T> res;\n    for (T i = T(1); i * i <=\
    \ n; i++) {\n        if (n % i == 0) {\n            res.push_back(i);\n      \
    \      if (i * i != n) res.push_back(n / i);\n        }\n    }\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n}\n"
  code: "#pragma once\n\ntemplate <class T> std::vector<T> divisor(const T n) {\n\
    \    std::vector<T> res;\n    for (T i = T(1); i * i <= n; i++) {\n        if\
    \ (n % i == 0) {\n            res.push_back(i);\n            if (i * i != n) res.push_back(n\
    \ / i);\n        }\n    }\n    std::sort(res.begin(), res.end());\n    return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2024-05-28 13:48:58+09:00'
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
