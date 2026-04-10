---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: dp/inversion_number.hpp
    title: "Inversion Number (\u8EE2\u5012\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: dp/test/inversion_number.test.cpp
    title: dp/test/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/fenwick_tree_plus.test.cpp
    title: segment_tree/test/fenwick_tree_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/misc/mo.test.cpp
    title: verify/misc/mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment_tree/fenwick_tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n// Fenwick Tree\ntemplate <class MS> struct FenwickTree {\n\
    \  public:\n    using S = typename MS::value_type;\n\n    FenwickTree() = default;\n\
    \n    explicit FenwickTree(int n)\n        : FenwickTree(std::vector<S>(n, MS::identity()))\
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
    \    int n;\n    std::vector<S> d;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n// Fenwick Tree\n\
    template <class MS> struct FenwickTree {\n  public:\n    using S = typename MS::value_type;\n\
    \n    FenwickTree() = default;\n\n    explicit FenwickTree(int n)\n        : FenwickTree(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit FenwickTree(const std::vector<S>& v) : n((int)(v.size()))\
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
    \    int n;\n    std::vector<S> d;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/fenwick_tree.hpp
  requiredBy:
  - dp/inversion_number.hpp
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/misc/mo.test.cpp
  - dp/test/inversion_number.test.cpp
  - segment_tree/test/fenwick_tree_plus.test.cpp
documentation_of: segment_tree/fenwick_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/fenwick_tree.hpp
- /library/segment_tree/fenwick_tree.hpp.html
title: segment_tree/fenwick_tree.hpp
---
