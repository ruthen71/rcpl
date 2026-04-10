---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/fenwick_tree.hpp
    title: segment_tree/fenwick_tree.hpp
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
  bundledCode: "#line 2 \"dp/inversion_number.hpp\"\n\n#include <algorithm>\n\n#line\
    \ 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate <class T> struct MonoidPlus\
    \ {\n    using value_type = T;\n    static constexpr T operation(const T& a, const\
    \ T& b) noexcept {\n        return a + b;\n    }\n    static constexpr T identity()\
    \ noexcept { return T(0); }\n    static constexpr T inverse(const T& a) noexcept\
    \ { return -a; }\n    static constexpr bool commutative = true;\n};\n#line 2 \"\
    segment_tree/fenwick_tree.hpp\"\n\n#include <cassert>\n#include <vector>\n\n//\
    \ Fenwick Tree\ntemplate <class MS> struct FenwickTree {\n  public:\n    using\
    \ S = typename MS::value_type;\n\n    FenwickTree() = default;\n\n    explicit\
    \ FenwickTree(int n)\n        : FenwickTree(std::vector<S>(n, MS::identity()))\
    \ {}\n\n    explicit FenwickTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        d = std::vector<S>(n + 1, MS::identity());\n        for (int i =\
    \ 1; i <= n; i++) {\n            d[i] = MS::operation(d[i], v[i - 1]);\n     \
    \       int j = i + (i & -i);\n            if (j <= n) {\n                d[j]\
    \ = MS::operation(d[j], d[i]);\n            }\n        }\n    }\n\n    void set(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        add(p, MS::operation(MS::inverse(get(p)),\
    \ x));\n    }\n    void add(int p, const S& x) {\n        assert(0 <= p and p\
    \ < n);\n        p++;  // 1-indexed\n        while (p <= n) {\n            d[p]\
    \ = MS::operation(d[p], x);\n            p += p & -p;\n        }\n    }\n\n  \
    \  S operator[](int p) const {\n        assert(0 <= p and p < n);\n        return\
    \ prod(p, p + 1);\n    }\n\n    S get(int p) const {\n        assert(0 <= p and\
    \ p < n);\n        return prod(p, p + 1);\n    }\n\n    S prod(int l, int r) const\
    \ {\n        assert(0 <= l and l <= r and r <= n);\n        return MS::operation(prod(r),\
    \ MS::inverse(prod(l)));\n    }\n\n    S prod(int p) const {\n        assert(0\
    \ <= p and p <= n);\n        S s = MS::identity();\n        while (p > 0) {\n\
    \            s = MS::operation(s, d[p]);\n            p -= p & -p;\n        }\n\
    \        return s;\n    }\n\n    S all_prod() const { return prod(n); }\n\n  \
    \  std::vector<S> make_vector() {\n        std::vector<S> vec(n);\n        for\
    \ (int i = 0; i < n; i++) vec[i] = get(i);\n        return vec;\n    }\n\n  private:\n\
    \    int n;\n    std::vector<S> d;\n};\n#line 7 \"dp/inversion_number.hpp\"\n\n\
    // a \u3092 sorted \u306B\u3059\u308B\u305F\u3081\u306E\u96A3\u63A5 swap \u306E\
    \u64CD\u4F5C\u56DE\u6570\ntemplate <class T> long long inversion_number(std::vector<T>&\
    \ a) {\n    auto za = a;\n    std::sort(za.begin(), za.end());\n    za.erase(std::unique(za.begin(),\
    \ za.end()), za.end());\n    const int m = (int)(za.size());\n    FenwickTree<MonoidPlus<int>>\
    \ seg(m);\n    long long res = 0;\n    for (auto&& e : a) {\n        int i = std::lower_bound(za.begin(),\
    \ za.end(), e) - za.begin();\n        res += seg.prod(i + 1, m);\n        seg.add(i,\
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
    \ g_offset(m, 0);\n    FenwickTree<MonoidPlus<int>> seg(n);\n    long long res\
    \ = 0;\n    for (int i = 0; i < n; i++) {\n        int index = std::lower_bound(za.begin(),\
    \ za.end(), a[i]) - za.begin();\n        int offset = g_offset[index];\n     \
    \   int a_pos = g[index][offset];\n        res += seg.prod(a_pos + 1, n);\n  \
    \      seg.add(a_pos, 1);\n        g_offset[index]++;\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n\n#include <algorithm>\n\n#include \"../algebra/monoid/monoid_plus.hpp\"\
    \n#include \"../segment_tree/fenwick_tree.hpp\"\n\n// a \u3092 sorted \u306B\u3059\
    \u308B\u305F\u3081\u306E\u96A3\u63A5 swap \u306E\u64CD\u4F5C\u56DE\u6570\ntemplate\
    \ <class T> long long inversion_number(std::vector<T>& a) {\n    auto za = a;\n\
    \    std::sort(za.begin(), za.end());\n    za.erase(std::unique(za.begin(), za.end()),\
    \ za.end());\n    const int m = (int)(za.size());\n    FenwickTree<MonoidPlus<int>>\
    \ seg(m);\n    long long res = 0;\n    for (auto&& e : a) {\n        int i = std::lower_bound(za.begin(),\
    \ za.end(), e) - za.begin();\n        res += seg.prod(i + 1, m);\n        seg.add(i,\
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
    \ g_offset(m, 0);\n    FenwickTree<MonoidPlus<int>> seg(n);\n    long long res\
    \ = 0;\n    for (int i = 0; i < n; i++) {\n        int index = std::lower_bound(za.begin(),\
    \ za.end(), a[i]) - za.begin();\n        int offset = g_offset[index];\n     \
    \   int a_pos = g[index][offset];\n        res += seg.prod(a_pos + 1, n);\n  \
    \      seg.add(a_pos, 1);\n        g_offset[index]++;\n    }\n    return res;\n\
    }\n"
  dependsOn:
  - algebra/monoid/monoid_plus.hpp
  - segment_tree/fenwick_tree.hpp
  isVerificationFile: false
  path: dp/inversion_number.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
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
