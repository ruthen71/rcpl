---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_2286.test.cpp
    title: verify/aoj_other/aoj_2286.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/totient_table.hpp\"\n\nstd::vector<int> totient_table(int\
    \ n) {\n    std::vector<int> res(n + 1);\n    std::iota(res.begin(), res.end(),\
    \ 0);\n    for (int p = 2; p <= n; p++) {\n        if (res[p] != p) continue;\n\
    \        for (int i = p; i <= n; i += p) {\n            res[i] /= p;\n       \
    \     res[i] *= p - 1;\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\nstd::vector<int> totient_table(int n) {\n    std::vector<int>\
    \ res(n + 1);\n    std::iota(res.begin(), res.end(), 0);\n    for (int p = 2;\
    \ p <= n; p++) {\n        if (res[p] != p) continue;\n        for (int i = p;\
    \ i <= n; i += p) {\n            res[i] /= p;\n            res[i] *= p - 1;\n\
    \        }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/totient_table.hpp
  requiredBy: []
  timestamp: '2022-09-06 18:11:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_other/aoj_2286.test.cpp
documentation_of: src/math/totient_table.hpp
layout: document
redirect_from:
- /library/src/math/totient_table.hpp
- /library/src/math/totient_table.hpp.html
title: src/math/totient_table.hpp
---
