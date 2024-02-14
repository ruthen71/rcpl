---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_0360.test.cpp
    title: verify/aoj_other/aoj_0360.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_2286.test.cpp
    title: verify/aoj_other/aoj_2286.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_static_range_sum.test.cpp
    title: verify/lc_data_structure/lc_static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/cumulative_sum.hpp\"\n\ntemplate <class T>\
    \ struct CumulativeSum {\n    int n;\n    std::vector<T> seg;\n\n    CumulativeSum()\
    \ = default;\n\n    CumulativeSum(int n) : n(n), seg(n + 1, T(0)) {}\n\n    CumulativeSum(std::vector<T>\
    \ &a) {\n        n = (int)a.size();\n        seg.assign(n + 1, T(0));\n      \
    \  for (int i = 0; i < n; i++) seg[i + 1] = seg[i] + a[i];\n    }\n\n    // [l,\
    \ r)\n    T sum(int l, int r) const {\n        assert(0 <= l and l <= r and r\
    \ <= n);\n        return seg[r] - seg[l];\n    }\n\n    // A[l] += x, A[l + 1]\
    \ += x, ... , A[r - 1] += x\n    void imos(int l, int r, T x = T(1)) {\n     \
    \   assert(0 <= l and l <= r and r <= n);\n        seg[l] += x;\n        seg[r]\
    \ -= x;\n    }\n\n    void build() {\n        for (int i = 0; i < n; i++) seg[i\
    \ + 1] += seg[i];\n    }\n\n    // return A[p]\n    T get(int p) const {\n   \
    \     assert(0 <= p and p < n);\n        return seg[p];\n    }\n\n    // output\n\
    \    friend std::ostream &operator<<(std::ostream &os, const CumulativeSum &A)\
    \ {\n        os << \"n = \" << A.n << \"\\n\";\n        for (int i = 0; i <= A.n;\
    \ i++) os << A.seg[i] << \" \\n\"[i == A.n];\n        return os;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct CumulativeSum {\n    int n;\n \
    \   std::vector<T> seg;\n\n    CumulativeSum() = default;\n\n    CumulativeSum(int\
    \ n) : n(n), seg(n + 1, T(0)) {}\n\n    CumulativeSum(std::vector<T> &a) {\n \
    \       n = (int)a.size();\n        seg.assign(n + 1, T(0));\n        for (int\
    \ i = 0; i < n; i++) seg[i + 1] = seg[i] + a[i];\n    }\n\n    // [l, r)\n   \
    \ T sum(int l, int r) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        return seg[r] - seg[l];\n    }\n\n    // A[l] += x, A[l + 1] += x, ...\
    \ , A[r - 1] += x\n    void imos(int l, int r, T x = T(1)) {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        seg[l] += x;\n        seg[r] -= x;\n \
    \   }\n\n    void build() {\n        for (int i = 0; i < n; i++) seg[i + 1] +=\
    \ seg[i];\n    }\n\n    // return A[p]\n    T get(int p) const {\n        assert(0\
    \ <= p and p < n);\n        return seg[p];\n    }\n\n    // output\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const CumulativeSum &A) {\n     \
    \   os << \"n = \" << A.n << \"\\n\";\n        for (int i = 0; i <= A.n; i++)\
    \ os << A.seg[i] << \" \\n\"[i == A.n];\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2023-03-17 17:11:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_static_range_sum.test.cpp
  - verify/aoj_other/aoj_0360.test.cpp
  - verify/aoj_other/aoj_2286.test.cpp
documentation_of: data_structure/cumulative_sum.hpp
layout: document
title: "\u7D2F\u7A4D\u548C"
---


使い方
1. ある配列の区間和を求める場合
    - コンストラクタ引数に配列を入力
    - `sum(l, r)`で `A[l] + A[l + 1] + ... + A[r - 1]` を返す
1. imos法のように使う場合
    - コンストラクタ引数に入力した値を`n`とすると、$[0, n)$ への加算ができる(加算しうる半開区間の右端の値を入力する)
    - `imos(l, r, z)`で $ [l, r) $ に $ z $ を加算
    - `build()`で構築
    - `rui.get(p)`でアクセス
