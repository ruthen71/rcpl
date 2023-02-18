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
    \ struct CumulativeSum {\n    std::vector<T> seg;\n    int _n;\n\n    CumulativeSum(int\
    \ _n) : _n(_n), seg(_n + 1, 0) {}\n    CumulativeSum(std::vector<T> &A) {\n  \
    \      _n = (int)A.size();\n        seg.assign(_n + 1, T(0));\n        for (int\
    \ i = 0; i < _n; i++) seg[i + 1] = seg[i] + A[i];\n    }\n\n    // [l, r)\n  \
    \  T sum(int l, int r) const {\n        assert(0 <= l and l <= r and r <= _n);\n\
    \        return seg[r] - seg[l];\n    }\n\n    // A[p] = x\n    void set(int p,\
    \ T x) {\n        assert(0 <= p and p < _n);\n        seg[p + 1] = x;\n    }\n\
    \n    // A[p] += x\n    void add(int p, T x) {\n        assert(0 <= p and p <\
    \ _n);\n        seg[p + 1] += x;\n    }\n\n    // A[l] += x, A[l + 1] += x, ...\
    \ , A[r - 1] += x\n    void imos(int l, int r, T x = T(1)) {\n        add(l, x);\n\
    \        add(r, -x);\n    }\n\n    void build() {\n        for (int i = 0; i <\
    \ _n; i++) seg[i + 1] += seg[i];\n    }\n\n    T operator[](int p) const {\n \
    \       assert(0 <= p and p < _n);\n        return seg[p + 1];\n    }\n\n    //\
    \ output\n    friend std::ostream &operator<<(std::ostream &os, const CumulativeSum\
    \ &A) {\n        for (int i = 0; i <= A._n; i++) os << A.seg[i] << \" \\n\"[i\
    \ == A._n];\n        return os;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct CumulativeSum {\n    std::vector<T>\
    \ seg;\n    int _n;\n\n    CumulativeSum(int _n) : _n(_n), seg(_n + 1, 0) {}\n\
    \    CumulativeSum(std::vector<T> &A) {\n        _n = (int)A.size();\n       \
    \ seg.assign(_n + 1, T(0));\n        for (int i = 0; i < _n; i++) seg[i + 1] =\
    \ seg[i] + A[i];\n    }\n\n    // [l, r)\n    T sum(int l, int r) const {\n  \
    \      assert(0 <= l and l <= r and r <= _n);\n        return seg[r] - seg[l];\n\
    \    }\n\n    // A[p] = x\n    void set(int p, T x) {\n        assert(0 <= p and\
    \ p < _n);\n        seg[p + 1] = x;\n    }\n\n    // A[p] += x\n    void add(int\
    \ p, T x) {\n        assert(0 <= p and p < _n);\n        seg[p + 1] += x;\n  \
    \  }\n\n    // A[l] += x, A[l + 1] += x, ... , A[r - 1] += x\n    void imos(int\
    \ l, int r, T x = T(1)) {\n        add(l, x);\n        add(r, -x);\n    }\n\n\
    \    void build() {\n        for (int i = 0; i < _n; i++) seg[i + 1] += seg[i];\n\
    \    }\n\n    T operator[](int p) const {\n        assert(0 <= p and p < _n);\n\
    \        return seg[p + 1];\n    }\n\n    // output\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const CumulativeSum &A) {\n        for (int i = 0; i <= A._n; i++) os <<\
    \ A.seg[i] << \" \\n\"[i == A._n];\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_other/aoj_2286.test.cpp
  - verify/aoj_other/aoj_0360.test.cpp
  - verify/lc_data_structure/lc_static_range_sum.test.cpp
documentation_of: data_structure/cumulative_sum.hpp
layout: document
title: "\u7D2F\u7A4D\u548C"
---


2つの使い方が想定される
1. ある配列を入力し、さまざまな区間和を求める場合
    - コンストラクタ引数にその配列を直接取ると、勝手に構築する
    - `sum(l, r)`で `A[l] + A[l + 1] + ... + A[r - 1]` を返す
1. imos法のように使いたい場合
    - コンストラクタ引数には配列のサイズを入力する
    - このとき、配列サイズは1大きくする
        - 長さ $ N $ の配列に区間加算する場合、配列自体は右端を考慮して長さを $ N+1 $ にするのと同じ
    - `imos(l, r, z)`で $ [l, r) $ に $ z $ を加算する
    - `build()`で構築
    - `rui[p]`でimos法をする前での配列`A`の`A[p]`にアクセスできる
