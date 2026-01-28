---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: dp/test/inversion_number.test.cpp
    title: dp/test/inversion_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/inversion_number.hpp\"\n\n#include <algorithm>\n#line\
    \ 2 \"data_structure/fenwick_tree.hpp\"\n\n#include <vector>\n#include <cassert>\n\
    \ntemplate <class T> struct FenwickTree {\n    int n;\n    std::vector<T> seg;\n\
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
    \ i, const T x) { add(i, x - get(i)); }\n\n    std::vector<T> make_vector() {\n\
    \        std::vector<T> vec(n);\n        for (int i = 0; i < n; i++) vec[i] =\
    \ get(i);\n        return vec;\n    }\n};\n#line 5 \"dp/inversion_number.hpp\"\
    \n\n// a \u3092 sorted \u306B\u3059\u308B\u305F\u3081\u306E\u96A3\u63A5 swap \u306E\
    \u64CD\u4F5C\u56DE\u6570\ntemplate <class T> long long inversion_number(std::vector<T>&\
    \ a) {\n    auto za = a;\n    std::sort(za.begin(), za.end());\n    za.erase(std::unique(za.begin(),\
    \ za.end()), za.end());\n    const int m = (int)(za.size());\n    FenwickTree<int>\
    \ seg(m);\n    long long res = 0;\n    for (auto&& e : a) {\n        int i = std::lower_bound(za.begin(),\
    \ za.end(), e) - za.begin();\n        res += seg.sum(i + 1, m);\n        seg.add(i,\
    \ 1);\n    }\n    return res;\n}\n\n// a -> b \u306B\u3059\u308B\u305F\u3081\u306E\
    \u96A3\u63A5 swap \u306E\u64CD\u4F5C\u56DE\u6570\ntemplate <class T>\nlong long\
    \ inversion_number(std::vector<T>& a, std::vector<T>& b) {\n    auto za = a;\n\
    \    auto zb = b;\n    std::sort(za.begin(), za.end());\n    std::sort(zb.begin(),\
    \ zb.end());\n    assert(za == zb);\n    za.erase(std::unique(za.begin(), za.end()),\
    \ za.end());\n    // a = [100, 1, 10, 1], b = [10, 1, 1, 100] (n = 4, m = 3)\n\
    \    // a = [3, 1, 0, 2] \u3092 b = [0, 1, 2, 3] \u306B\u3059\u308B\u305F\u3081\
    \u306E\u64CD\u4F5C\u56DE\u6570\u306B\u5E30\u7740\u3059\u308B\n    // g = [[1,\
    \ 2], [0], [3]] \u306B\u306A\u308B\n    const int n = (int)(a.size());\n    const\
    \ int m = (int)(za.size());\n    std::vector<std::vector<int>> g(m);\n    for\
    \ (int i = 0; i < n; i++) {\n        int index = std::lower_bound(za.begin(),\
    \ za.end(), b[i]) - za.begin();\n        g[index].push_back(i);\n    }\n    std::vector<int>\
    \ g_offset(m, 0);\n    FenwickTree<int> seg(n);\n    long long res = 0;\n    for\
    \ (int i = 0; i < n; i++) {\n        int index = std::lower_bound(za.begin(),\
    \ za.end(), a[i]) - za.begin();\n        int offset = g_offset[index];\n     \
    \   int a_pos = g[index][offset];\n        res += seg.sum(a_pos + 1, n);\n   \
    \     seg.add(a_pos, 1);\n        g_offset[index]++;\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n\n#include <algorithm>\n#include \"../data_structure/fenwick_tree.hpp\"\
    \n\n// a \u3092 sorted \u306B\u3059\u308B\u305F\u3081\u306E\u96A3\u63A5 swap \u306E\
    \u64CD\u4F5C\u56DE\u6570\ntemplate <class T> long long inversion_number(std::vector<T>&\
    \ a) {\n    auto za = a;\n    std::sort(za.begin(), za.end());\n    za.erase(std::unique(za.begin(),\
    \ za.end()), za.end());\n    const int m = (int)(za.size());\n    FenwickTree<int>\
    \ seg(m);\n    long long res = 0;\n    for (auto&& e : a) {\n        int i = std::lower_bound(za.begin(),\
    \ za.end(), e) - za.begin();\n        res += seg.sum(i + 1, m);\n        seg.add(i,\
    \ 1);\n    }\n    return res;\n}\n\n// a -> b \u306B\u3059\u308B\u305F\u3081\u306E\
    \u96A3\u63A5 swap \u306E\u64CD\u4F5C\u56DE\u6570\ntemplate <class T>\nlong long\
    \ inversion_number(std::vector<T>& a, std::vector<T>& b) {\n    auto za = a;\n\
    \    auto zb = b;\n    std::sort(za.begin(), za.end());\n    std::sort(zb.begin(),\
    \ zb.end());\n    assert(za == zb);\n    za.erase(std::unique(za.begin(), za.end()),\
    \ za.end());\n    // a = [100, 1, 10, 1], b = [10, 1, 1, 100] (n = 4, m = 3)\n\
    \    // a = [3, 1, 0, 2] \u3092 b = [0, 1, 2, 3] \u306B\u3059\u308B\u305F\u3081\
    \u306E\u64CD\u4F5C\u56DE\u6570\u306B\u5E30\u7740\u3059\u308B\n    // g = [[1,\
    \ 2], [0], [3]] \u306B\u306A\u308B\n    const int n = (int)(a.size());\n    const\
    \ int m = (int)(za.size());\n    std::vector<std::vector<int>> g(m);\n    for\
    \ (int i = 0; i < n; i++) {\n        int index = std::lower_bound(za.begin(),\
    \ za.end(), b[i]) - za.begin();\n        g[index].push_back(i);\n    }\n    std::vector<int>\
    \ g_offset(m, 0);\n    FenwickTree<int> seg(n);\n    long long res = 0;\n    for\
    \ (int i = 0; i < n; i++) {\n        int index = std::lower_bound(za.begin(),\
    \ za.end(), a[i]) - za.begin();\n        int offset = g_offset[index];\n     \
    \   int a_pos = g[index][offset];\n        res += seg.sum(a_pos + 1, n);\n   \
    \     seg.add(a_pos, 1);\n        g_offset[index]++;\n    }\n    return res;\n\
    }\n"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  isVerificationFile: false
  path: dp/inversion_number.hpp
  requiredBy: []
  timestamp: '2026-01-28 15:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - dp/test/inversion_number.test.cpp
documentation_of: dp/inversion_number.hpp
layout: document
title: "Inversion Number (\u8EE2\u5012\u6570)"
---

転倒数（$i < j$ かつ $a_i > a_j$ となる組の数）を求めます。

転倒数（反転数）は数列 $a$ をソートするための隣接 swap の最小操作回数と等しいです。

## inversion_number

```cpp
(1) template <class T> long long inversion_number(std::vector<T>& a)
(2) template <class T> long long inversion_number(std::vector<T>& a, std::vector<T>& b)
```

(1)

長さ $n$ の数列 $a$ の転倒数を返します。

(2)

長さ $n$ の数列 $a$ を 数列 $b$ にするための隣接 swap の最小操作回数を返します。

### 制約

(2)

- 隣接 swap を有限回繰り返すことで数列 $a$ を 数列 $b$ にすることができる、すなわち、多重集合として $a$ と $b$ は一致する


### 計算量

- $O(n \log n)$
