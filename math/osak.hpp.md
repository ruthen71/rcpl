---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_alds1/aoj_alds1_1_c_osa_k.test.cpp
    title: verify/aoj_alds1/aoj_alds1_1_c_osa_k.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/osak.hpp\"\n\nstruct Osak {\n    int n;\n    std::vector<int>\
    \ min_factor;\n\n    Osak(int n) : n(n), min_factor(n + 1) {\n        std::iota(min_factor.begin(),\
    \ min_factor.end(), 0);\n        if (n >= 0) min_factor[0] = -1;\n        if (n\
    \ >= 1) min_factor[1] = -1;\n        for (int p = 2; p * p <= n; p++) {\n    \
    \        if (min_factor[p] != p) continue;\n            for (int i = p * p; i\
    \ <= n; i += p) {\n                if (min_factor[i] != i) continue;\n       \
    \         min_factor[i] = p;\n            }\n        }\n    }\n\n    bool is_prime(int\
    \ x) {\n        assert(x <= n);\n        return min_factor[x] == x;\n    }\n\n\
    \    std::map<int, int> prime_factor(int x) {\n        assert(x <= n);\n     \
    \   std::map<int, int> pf;\n        while (x > 1) {\n            pf[min_factor[x]]++;\n\
    \            x /= min_factor[x];\n        }\n        return pf;\n    }\n};\n"
  code: "#pragma once\n\nstruct Osak {\n    int n;\n    std::vector<int> min_factor;\n\
    \n    Osak(int n) : n(n), min_factor(n + 1) {\n        std::iota(min_factor.begin(),\
    \ min_factor.end(), 0);\n        if (n >= 0) min_factor[0] = -1;\n        if (n\
    \ >= 1) min_factor[1] = -1;\n        for (int p = 2; p * p <= n; p++) {\n    \
    \        if (min_factor[p] != p) continue;\n            for (int i = p * p; i\
    \ <= n; i += p) {\n                if (min_factor[i] != i) continue;\n       \
    \         min_factor[i] = p;\n            }\n        }\n    }\n\n    bool is_prime(int\
    \ x) {\n        assert(x <= n);\n        return min_factor[x] == x;\n    }\n\n\
    \    std::map<int, int> prime_factor(int x) {\n        assert(x <= n);\n     \
    \   std::map<int, int> pf;\n        while (x > 1) {\n            pf[min_factor[x]]++;\n\
    \            x /= min_factor[x];\n        }\n        return pf;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/osak.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_alds1/aoj_alds1_1_c_osa_k.test.cpp
documentation_of: math/osak.hpp
layout: document
redirect_from:
- /library/math/osak.hpp
- /library/math/osak.hpp.html
title: math/osak.hpp
---
