---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: dp/inversion_number.hpp
    title: "Inversion Number (\u8EE2\u5012\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_alds1/aoj_alds1_5_d.test.cpp
    title: verify/aoj_alds1/aoj_alds1_5_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
    title: verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_static_range_inversions_query.test.cpp
    title: verify/lc_data_structure/lc_static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/fenwick_tree.hpp\"\n\ntemplate <class T>\
    \ struct FenwickTree {\n    int N;\n    std::vector<T> seg;\n    FenwickTree(int\
    \ N) : N(N), seg(N + 1, 0) {}\n    FenwickTree(std::vector<T> &A) {\n        N\
    \ = (int)A.size();\n        seg.resize(N + 1);\n        for (int i = 0; i < N;\
    \ i++) add(i, A[i]);\n    }\n    // A[i] += x\n    void add(int i, T x) {\n  \
    \      assert(0 <= i and i < N);\n        i++;  // 1-indexed\n        while (i\
    \ <= N) {\n            seg[i] += x;\n            i += i & -i;\n        }\n   \
    \ }\n    // A[0] + ... + A[i - 1]\n    T sum(int i) const {\n        assert(0\
    \ <= i and i <= N);\n        T s = 0;\n        while (i > 0) {\n            s\
    \ += seg[i];\n            i -= i & -i;\n        }\n        return s;\n    }\n\
    \    // A[a] + ... + A[b - 1]\n    T sum(int a, int b) const {\n        assert(0\
    \ <= a and a <= b and b <= N);\n        return sum(b) - sum(a);\n    }\n\n   \
    \ // output\n    friend std::ostream &operator<<(std::ostream &os, const FenwickTree\
    \ &A) {\n        for (int i = 0; i < A.N; i++) os << A.sum(i, i + 1) << \" \\\
    n\"[i == A.N - 1];\n        return os;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct FenwickTree {\n    int N;\n   \
    \ std::vector<T> seg;\n    FenwickTree(int N) : N(N), seg(N + 1, 0) {}\n    FenwickTree(std::vector<T>\
    \ &A) {\n        N = (int)A.size();\n        seg.resize(N + 1);\n        for (int\
    \ i = 0; i < N; i++) add(i, A[i]);\n    }\n    // A[i] += x\n    void add(int\
    \ i, T x) {\n        assert(0 <= i and i < N);\n        i++;  // 1-indexed\n \
    \       while (i <= N) {\n            seg[i] += x;\n            i += i & -i;\n\
    \        }\n    }\n    // A[0] + ... + A[i - 1]\n    T sum(int i) const {\n  \
    \      assert(0 <= i and i <= N);\n        T s = 0;\n        while (i > 0) {\n\
    \            s += seg[i];\n            i -= i & -i;\n        }\n        return\
    \ s;\n    }\n    // A[a] + ... + A[b - 1]\n    T sum(int a, int b) const {\n \
    \       assert(0 <= a and a <= b and b <= N);\n        return sum(b) - sum(a);\n\
    \    }\n\n    // output\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const FenwickTree &A) {\n        for (int i = 0; i < A.N; i++) os << A.sum(i,\
    \ i + 1) << \" \\n\"[i == A.N - 1];\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/fenwick_tree.hpp
  requiredBy:
  - dp/inversion_number.hpp
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_alds1/aoj_alds1_5_d.test.cpp
  - verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
  - verify/lc_data_structure/lc_static_range_inversions_query.test.cpp
documentation_of: data_structure/fenwick_tree.hpp
layout: document
title: Fenwick Tree (Binary Indexed Tree)
---

- 一点更新区間和取得ができるデータ構造である
- 内部実装では1-indexedで、外部からは0-indexedで利用するようになっている
- `add(i, x)`: `A[i]`に`x`を加算する
- `sum(a, b)`: `A[a] + ... + A[b - 1]`を返す
