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
  - icon: ':x:'
    path: verify/misc/mo.test.cpp
    title: verify/misc/mo.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/fenwick_tree.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate <class T> struct FenwickTree {\n    int n;\n  \
    \  std::vector<T> seg;\n    FenwickTree() : n(0) {}\n    FenwickTree(int n) :\
    \ n(n), seg(n + 1, 0) {}\n    FenwickTree(std::vector<T>& arr) {\n        n =\
    \ int(arr.size());\n        seg.resize(n + 1);\n        for (int i = 0; i < n;\
    \ i++) add(i, arr[i]);\n    }\n    // A[i] += x\n    void add(int i, const T&\
    \ x) {\n        assert(0 <= i and i < n);\n        i++;  // 1-indexed\n      \
    \  while (i <= n) {\n            seg[i] += x;\n            i += i & -i;\n    \
    \    }\n    }\n    // A[0] + ... + A[i - 1]\n    T sum(int i) const {\n      \
    \  assert(0 <= i and i <= n);\n        T s = T(0);\n        while (i > 0) {\n\
    \            s += seg[i];\n            i -= i & -i;\n        }\n        return\
    \ s;\n    }\n    // A[a] + ... + A[b - 1]\n    T sum(int a, int b) const {\n \
    \       assert(0 <= a and a <= b and b <= n);\n        return sum(b) - sum(a);\n\
    \    }\n    // return A[i]\n    T get(int i) const { return sum(i, i + 1); }\n\
    \    // A[i] = x\n    void set(int i, const T x) { add(i, x - get(i)); }\n\n \
    \   std::vector<T> make_vector() {\n        std::vector<T> vec(n);\n        for\
    \ (int i = 0; i < n; i++) vec[i] = get(i);\n        return vec;\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\ntemplate <class\
    \ T> struct FenwickTree {\n    int n;\n    std::vector<T> seg;\n    FenwickTree()\
    \ : n(0) {}\n    FenwickTree(int n) : n(n), seg(n + 1, 0) {}\n    FenwickTree(std::vector<T>&\
    \ arr) {\n        n = int(arr.size());\n        seg.resize(n + 1);\n        for\
    \ (int i = 0; i < n; i++) add(i, arr[i]);\n    }\n    // A[i] += x\n    void add(int\
    \ i, const T& x) {\n        assert(0 <= i and i < n);\n        i++;  // 1-indexed\n\
    \        while (i <= n) {\n            seg[i] += x;\n            i += i & -i;\n\
    \        }\n    }\n    // A[0] + ... + A[i - 1]\n    T sum(int i) const {\n  \
    \      assert(0 <= i and i <= n);\n        T s = T(0);\n        while (i > 0)\
    \ {\n            s += seg[i];\n            i -= i & -i;\n        }\n        return\
    \ s;\n    }\n    // A[a] + ... + A[b - 1]\n    T sum(int a, int b) const {\n \
    \       assert(0 <= a and a <= b and b <= n);\n        return sum(b) - sum(a);\n\
    \    }\n    // return A[i]\n    T get(int i) const { return sum(i, i + 1); }\n\
    \    // A[i] = x\n    void set(int i, const T x) { add(i, x - get(i)); }\n\n \
    \   std::vector<T> make_vector() {\n        std::vector<T> vec(n);\n        for\
    \ (int i = 0; i < n; i++) vec[i] = get(i);\n        return vec;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/fenwick_tree.hpp
  requiredBy:
  - dp/inversion_number.hpp
  timestamp: '2024-12-17 21:01:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
  - verify/misc/mo.test.cpp
  - verify/aoj_alds1/aoj_alds1_5_d.test.cpp
documentation_of: data_structure/fenwick_tree.hpp
layout: document
title: Fenwick Tree (Binary Indexed Tree)
---

- 一点更新区間和取得ができるデータ構造である
- 内部実装では1-indexedで、外部からは0-indexedで利用するようになっている
- `add(i, x)`: `A[i]`に`x`を加算する
- `sum(a, b)`: `A[a] + ... + A[b - 1]`を返す
