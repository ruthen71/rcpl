---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
    title: verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/fenwick_tree.md
    document_title: Fenwick Tree (Binary Indexed Tree)
    links: []
  bundledCode: "#line 2 \"src/data_structure/fenwick_tree.hpp\"\n\ntemplate <class\
    \ T> struct fenwick_tree {\n    int N;\n    std::vector<T> seg;\n    fenwick_tree(int\
    \ N) : N(N), seg(N + 1, 0) {}\n    fenwick_tree(std::vector<T> &A) {\n       \
    \ N = (int)A.size();\n        seg.resize(N + 1);\n        for (int i = 0; i <\
    \ N; i++) add(i, A[i]);\n    }\n    // A[i] += x\n    void add(int i, T x) {\n\
    \        i++;  // 1-indexed\n        while (i <= N) {\n            seg[i] += x;\n\
    \            i += i & -i;\n        }\n    }\n    // A[0] + ... + A[i - 1]\n  \
    \  T sum(int i) {\n        T s = 0;\n        while (i > 0) {\n            s +=\
    \ seg[i];\n            i -= i & -i;\n        }\n        return s;\n    }\n   \
    \ // A[a] + ... + A[b - 1]\n    T sum(int a, int b) { return sum(b) - sum(a);\
    \ }\n};\n\n/**\n * @brief Fenwick Tree (Binary Indexed Tree)\n * @docs docs/data_structure/fenwick_tree.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <class T> struct fenwick_tree {\n    int N;\n  \
    \  std::vector<T> seg;\n    fenwick_tree(int N) : N(N), seg(N + 1, 0) {}\n   \
    \ fenwick_tree(std::vector<T> &A) {\n        N = (int)A.size();\n        seg.resize(N\
    \ + 1);\n        for (int i = 0; i < N; i++) add(i, A[i]);\n    }\n    // A[i]\
    \ += x\n    void add(int i, T x) {\n        i++;  // 1-indexed\n        while\
    \ (i <= N) {\n            seg[i] += x;\n            i += i & -i;\n        }\n\
    \    }\n    // A[0] + ... + A[i - 1]\n    T sum(int i) {\n        T s = 0;\n \
    \       while (i > 0) {\n            s += seg[i];\n            i -= i & -i;\n\
    \        }\n        return s;\n    }\n    // A[a] + ... + A[b - 1]\n    T sum(int\
    \ a, int b) { return sum(b) - sum(a); }\n};\n\n/**\n * @brief Fenwick Tree (Binary\
    \ Indexed Tree)\n * @docs docs/data_structure/fenwick_tree.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2022-08-22 23:08:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
documentation_of: src/data_structure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/src/data_structure/fenwick_tree.hpp
- /library/src/data_structure/fenwick_tree.hpp.html
title: Fenwick Tree (Binary Indexed Tree)
---
# Fenwick Tree (Binary Indexed Tree)

## 概要
- 一点更新区間和取得ができるデータ構造である
- 内部実装では1-indexedで、外部からは0-indexedで利用するようになっている
- `add(i, x)`: `A[i]`に`x`を加算する
- `sum(a, b)`: `A[a] + ... + A[b - 1]`を返す
