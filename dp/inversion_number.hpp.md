---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_alds1/aoj_alds1_5_d.test.cpp
    title: verify/aoj_alds1/aoj_alds1_5_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/inversion_number.hpp\"\n\n#line 2 \"data_structure/fenwick_tree.hpp\"\
    \n\ntemplate <class T> struct FenwickTree {\n    int n;\n    std::vector<T> seg;\n\
    \    FenwickTree() : n(0) {}\n    FenwickTree(int n) : n(n), seg(n + 1, 0) {}\n\
    \    FenwickTree(std::vector<T>& arr) {\n        n = int(arr.size());\n      \
    \  seg.resize(n + 1);\n        for (int i = 0; i < n; i++) add(i, arr[i]);\n \
    \   }\n    // A[i] += x\n    void add(int i, const T& x) {\n        assert(0 <=\
    \ i and i < n);\n        i++;  // 1-indexed\n        while (i <= n) {\n      \
    \      seg[i] += x;\n            i += i & -i;\n        }\n    }\n    // A[0] +\
    \ ... + A[i - 1]\n    T sum(int i) const {\n        assert(0 <= i and i <= n);\n\
    \        T s = T(0);\n        while (i > 0) {\n            s += seg[i];\n    \
    \        i -= i & -i;\n        }\n        return s;\n    }\n    // A[a] + ...\
    \ + A[b - 1]\n    T sum(int a, int b) const {\n        assert(0 <= a and a <=\
    \ b and b <= n);\n        return sum(b) - sum(a);\n    }\n    // return A[i]\n\
    \    T get(int i) const { return sum(i, i + 1); }\n    // A[i] = x\n    void set(int\
    \ i, const T x) { add(i, x - get(i)); }\n    // output\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const FenwickTree& fen) {\n        for (int i =\
    \ 0; i < fen.n; i++) os << fen.get(i) << \" \\n\"[i == fen.n - 1];\n        return\
    \ os;\n    }\n};\n#line 4 \"dp/inversion_number.hpp\"\n\ntemplate <class T> long\
    \ long inversion_number(std::vector<T>& A) {\n    auto B = A;\n    sort(B.begin(),\
    \ B.end());\n    B.erase(unique(B.begin(), B.end()), B.end());\n    int N = (int)B.size();\n\
    \    FenwickTree<int> fen(N);\n    long long ret = 0;\n    for (auto& ai : A)\
    \ {\n        int i = lower_bound(B.begin(), B.end(), ai) - B.begin();\n      \
    \  ret += fen.sum(i + 1, N);\n        fen.add(i, 1);\n    }\n    return ret;\n\
    }\n"
  code: "#pragma once\n\n#include \"data_structure/fenwick_tree.hpp\"\n\ntemplate\
    \ <class T> long long inversion_number(std::vector<T>& A) {\n    auto B = A;\n\
    \    sort(B.begin(), B.end());\n    B.erase(unique(B.begin(), B.end()), B.end());\n\
    \    int N = (int)B.size();\n    FenwickTree<int> fen(N);\n    long long ret =\
    \ 0;\n    for (auto& ai : A) {\n        int i = lower_bound(B.begin(), B.end(),\
    \ ai) - B.begin();\n        ret += fen.sum(i + 1, N);\n        fen.add(i, 1);\n\
    \    }\n    return ret;\n}"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  isVerificationFile: false
  path: dp/inversion_number.hpp
  requiredBy: []
  timestamp: '2024-02-18 06:04:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_alds1/aoj_alds1_5_d.test.cpp
documentation_of: dp/inversion_number.hpp
layout: document
title: "Inversion Number (\u8EE2\u5012\u6570)"
---

$ O(N \log N) $ で転倒数を求める。
座圧する。
転倒数はバブルソートの交換回数と等しい。

