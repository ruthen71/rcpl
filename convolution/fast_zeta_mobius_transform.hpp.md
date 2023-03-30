---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/bitwise_and_convolution.hpp
    title: convolution/bitwise_and_convolution.hpp
  - icon: ':warning:'
    path: convolution/bitwise_or_convolution.hpp
    title: convolution/bitwise_or_convolution.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/fast_zeta_mobius_transform.hpp\"\n\n// fast\
    \ zeta transform (subset)\n// input: A\n// output: B\n// B_i = \\sum_{j \\subset\
    \ i} A_j\ntemplate <class T> void fast_zeta_transform_subset(std::vector<T> &a)\
    \ {\n    const int n = (int)a.size();\n    assert((n & (n - 1)) == 0);\n    for\
    \ (int j = 1; j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n     \
    \       if (i & j) {\n                a[i] += a[i ^ j];\n            }\n     \
    \   }\n    }\n}\n\n// fast mobius transform (subset)\n// input: B\n// output:\
    \ A\n// B_i = \\sum_{j \\subset i} A_j\ntemplate <class T> void fast_mobius_transform_subset(std::vector<T>\
    \ &b) {\n    const int n = (int)b.size();\n    assert((n & (n - 1)) == 0);\n \
    \   for (int j = 1; j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n\
    \            if (i & j) {\n                b[i] -= b[i ^ j];\n            }\n\
    \        }\n    }\n}\n\n// fast zeta transform (supset)\n// input: A\n// output:\
    \ B\n// B_i = \\sum_{j \\supset i} A_j\ntemplate <class T> void fast_zeta_transform_supset(std::vector<T>\
    \ &a) {\n    const int n = (int)a.size();\n    assert((n & (n - 1)) == 0);\n \
    \   for (int j = 1; j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n\
    \            if (i & j) {\n                a[i ^ j] += a[i];\n            }\n\
    \        }\n    }\n}\n\n// fast mobius transform (supset)\n// input: B\n// output:\
    \ A\n// B_i = \\sum_{j \\supset i} A_j\ntemplate <class T> void fast_mobius_transform_supset(std::vector<T>\
    \ &b) {\n    const int n = (int)b.size();\n    assert((n & (n - 1)) == 0);\n \
    \   for (int j = 1; j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n\
    \            if (i & j) {\n                b[i ^ j] -= b[i];\n            }\n\
    \        }\n    }\n}\n"
  code: "#pragma once\n\n// fast zeta transform (subset)\n// input: A\n// output:\
    \ B\n// B_i = \\sum_{j \\subset i} A_j\ntemplate <class T> void fast_zeta_transform_subset(std::vector<T>\
    \ &a) {\n    const int n = (int)a.size();\n    assert((n & (n - 1)) == 0);\n \
    \   for (int j = 1; j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n\
    \            if (i & j) {\n                a[i] += a[i ^ j];\n            }\n\
    \        }\n    }\n}\n\n// fast mobius transform (subset)\n// input: B\n// output:\
    \ A\n// B_i = \\sum_{j \\subset i} A_j\ntemplate <class T> void fast_mobius_transform_subset(std::vector<T>\
    \ &b) {\n    const int n = (int)b.size();\n    assert((n & (n - 1)) == 0);\n \
    \   for (int j = 1; j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n\
    \            if (i & j) {\n                b[i] -= b[i ^ j];\n            }\n\
    \        }\n    }\n}\n\n// fast zeta transform (supset)\n// input: A\n// output:\
    \ B\n// B_i = \\sum_{j \\supset i} A_j\ntemplate <class T> void fast_zeta_transform_supset(std::vector<T>\
    \ &a) {\n    const int n = (int)a.size();\n    assert((n & (n - 1)) == 0);\n \
    \   for (int j = 1; j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n\
    \            if (i & j) {\n                a[i ^ j] += a[i];\n            }\n\
    \        }\n    }\n}\n\n// fast mobius transform (supset)\n// input: B\n// output:\
    \ A\n// B_i = \\sum_{j \\supset i} A_j\ntemplate <class T> void fast_mobius_transform_supset(std::vector<T>\
    \ &b) {\n    const int n = (int)b.size();\n    assert((n & (n - 1)) == 0);\n \
    \   for (int j = 1; j < n; j <<= 1) {\n        for (int i = 0; i < n; i++) {\n\
    \            if (i & j) {\n                b[i ^ j] -= b[i];\n            }\n\
    \        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/fast_zeta_mobius_transform.hpp
  requiredBy:
  - convolution/bitwise_or_convolution.hpp
  - convolution/bitwise_and_convolution.hpp
  timestamp: '2023-03-31 06:51:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/fast_zeta_mobius_transform.hpp
layout: document
title: "Fast Zeta/Mobius Transform (\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\u30FB\
  \u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)"
---

1. 下位集合に対する高速ゼータ変換
1. 下位集合に対する高速メビウス変換
1. 上位集合に対する高速ゼータ変換
1. 上位集合に対する高速メビウス変換

## 使用例

- [PAST12 O](https://atcoder.jp/contests/past202209-open/submissions/40173852)
    - 各 popcount ごとに Bitwise OR Convolution を $ O(N^2) $ 回行い、全体の計算量は $ O(N^3 2^N + Q) $ であると思いきや、Fast Mobius Transform をまとめて行うことができるため、全体の計算量は $ O(N^2 2^N + Q) $ である
