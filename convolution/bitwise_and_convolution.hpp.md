---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: convolution/fast_zeta_mobius_transform.hpp
    title: "Fast Zeta/Mobius Transform (\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\
      \u30FB\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/bitwise_and_convolution.hpp\"\n\n#line 2 \"\
    convolution/fast_zeta_mobius_transform.hpp\"\n\n// fast zeta transform (subset)\n\
    // input: A\n// output: B\n// B_i = \\sum_{j \\subset i} A_j\ntemplate <class\
    \ T> void fast_zeta_transform_subset(std::vector<T> &a) {\n    const int n = (int)a.size();\n\
    \    assert((n & (n - 1)) == 0);\n    for (int j = 1; j < n; j <<= 1) {\n    \
    \    for (int i = 0; i < n; i++) {\n            if (i & j) {\n               \
    \ a[i] += a[i ^ j];\n            }\n        }\n    }\n}\n\n// fast mobius transform\
    \ (subset)\n// input: B\n// output: A\n// B_i = \\sum_{j \\subset i} A_j\ntemplate\
    \ <class T> void fast_mobius_transform_subset(std::vector<T> &b) {\n    const\
    \ int n = (int)b.size();\n    assert((n & (n - 1)) == 0);\n    for (int j = 1;\
    \ j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n            if (i\
    \ & j) {\n                b[i] -= b[i ^ j];\n            }\n        }\n    }\n\
    }\n\n// fast zeta transform (supset)\n// input: A\n// output: B\n// B_i = \\sum_{j\
    \ \\supset i} A_j\ntemplate <class T> void fast_zeta_transform_supset(std::vector<T>\
    \ &a) {\n    const int n = (int)a.size();\n    assert((n & (n - 1)) == 0);\n \
    \   for (int j = 1; j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n\
    \            if (i & j) {\n                a[i ^ j] += a[i];\n            }\n\
    \        }\n    }\n}\n\n// fast mobius transform (supset)\n// input: B\n// output:\
    \ A\n// B_i = \\sum_{j \\supset i} A_j\ntemplate <class T> void fast_mobius_transform_supset(std::vector<T>\
    \ &b) {\n    const int n = (int)b.size();\n    assert((n & (n - 1)) == 0);\n \
    \   for (int j = 1; j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n\
    \            if (i & j) {\n                b[i ^ j] -= b[i];\n            }\n\
    \        }\n    }\n}\n#line 4 \"convolution/bitwise_and_convolution.hpp\"\n\n\
    // bitwise and convolution\n// input: A, B\n// output: C\n// C_i = \\sum_{j \\\
    & k = i} A_j B_k\ntemplate <class T> std::vector<T> bitwise_and_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    const int n = (int)a.size();\n    assert(a.size()\
    \ == b.size());\n    assert((n & (n - 1)) == 0);\n    fast_zeta_transform_supset(a);\n\
    \    fast_zeta_transform_supset(b);\n    for (int i = 0; i < n; i++) a[i] *= b[i];\n\
    \    fast_mobius_transform_supset(a);\n    return a;\n}\n"
  code: "#pragma once\n\n#include \"convolution/fast_zeta_mobius_transform.hpp\"\n\
    \n// bitwise and convolution\n// input: A, B\n// output: C\n// C_i = \\sum_{j\
    \ \\& k = i} A_j B_k\ntemplate <class T> std::vector<T> bitwise_and_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    const int n = (int)a.size();\n    assert(a.size()\
    \ == b.size());\n    assert((n & (n - 1)) == 0);\n    fast_zeta_transform_supset(a);\n\
    \    fast_zeta_transform_supset(b);\n    for (int i = 0; i < n; i++) a[i] *= b[i];\n\
    \    fast_mobius_transform_supset(a);\n    return a;\n}"
  dependsOn:
  - convolution/fast_zeta_mobius_transform.hpp
  isVerificationFile: false
  path: convolution/bitwise_and_convolution.hpp
  requiredBy: []
  timestamp: '2023-03-31 06:51:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/bitwise_and_convolution.hpp
layout: document
redirect_from:
- /library/convolution/bitwise_and_convolution.hpp
- /library/convolution/bitwise_and_convolution.hpp.html
title: convolution/bitwise_and_convolution.hpp
---
