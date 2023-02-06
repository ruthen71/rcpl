---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_e_dual_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_e_dual_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/dual_segment_tree.md
    document_title: "Dual Segment Tree (\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728)"
    links: []
  bundledCode: "#line 2 \"data_structure/dual_segment_tree.hpp\"\n\ntemplate <class\
    \ Dual> struct dual_segment_tree {\n   public:\n    using F = typename Dual::value_type;\n\
    \    dual_segment_tree(int n) : dual_segment_tree(std::vector<F>(n, Dual::id()))\
    \ {}\n    dual_segment_tree(const std::vector<F>& v) : _n((int)v.size()) {\n \
    \       log = 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n  \
    \      size = 1 << log;\n        lz = std::vector<F>(size << 1, Dual::id());\n\
    \        for (int i = 0; i < _n; i++) lz[i + size] = v[i];\n    }\n\n    F operator[](int\
    \ p) {\n        assert(0 <= p and p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\
    \u642C\n        return lz[p];\n    }\n\n    F get(int p) {\n        assert(0 <=\
    \ p and p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\n        return lz[p];\n\
    \    }\n\n    void set(int p, const F& x) {\n        assert(0 <= p and p < _n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);  //\
    \ \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\n        lz[p] = x;\n    }\n\n  \
    \  void apply(int l, int r, const F& f) {\n        assert(0 <= l and l <= r and\
    \ r <= _n);\n        if (l == r) return;\n\n        l += size;\n        r += size;\n\
    \n        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n\n        {\n            int l2 = l, r2 = r;\n            while (l\
    \ < r) {\n                if (l & 1) all_apply(l++, f);\n                if (r\
    \ & 1) all_apply(--r, f);\n                l >>= 1;\n                r >>= 1;\n\
    \            }\n            l = l2;\n            r = r2;\n        }\n    }\n\n\
    \   private:\n    int _n, log, size;\n    std::vector<F> lz;\n    void all_apply(int\
    \ k, const F& f) { lz[k] = Dual::composition(f, lz[k]); }\n    void push(int k)\
    \ {\n        all_apply(k << 1, lz[k]);\n        all_apply((k << 1) | 1, lz[k]);\n\
    \        lz[k] = Dual::id();\n    }\n};\n\n/**\n * @brief Dual Segment Tree (\u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs docs/data_structure/dual_segment_tree.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <class Dual> struct dual_segment_tree {\n   public:\n\
    \    using F = typename Dual::value_type;\n    dual_segment_tree(int n) : dual_segment_tree(std::vector<F>(n,\
    \ Dual::id())) {}\n    dual_segment_tree(const std::vector<F>& v) : _n((int)v.size())\
    \ {\n        log = 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n\
    \        size = 1 << log;\n        lz = std::vector<F>(size << 1, Dual::id());\n\
    \        for (int i = 0; i < _n; i++) lz[i + size] = v[i];\n    }\n\n    F operator[](int\
    \ p) {\n        assert(0 <= p and p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\
    \u642C\n        return lz[p];\n    }\n\n    F get(int p) {\n        assert(0 <=\
    \ p and p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\n        return lz[p];\n\
    \    }\n\n    void set(int p, const F& x) {\n        assert(0 <= p and p < _n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);  //\
    \ \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\n        lz[p] = x;\n    }\n\n  \
    \  void apply(int l, int r, const F& f) {\n        assert(0 <= l and l <= r and\
    \ r <= _n);\n        if (l == r) return;\n\n        l += size;\n        r += size;\n\
    \n        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n\n        {\n            int l2 = l, r2 = r;\n            while (l\
    \ < r) {\n                if (l & 1) all_apply(l++, f);\n                if (r\
    \ & 1) all_apply(--r, f);\n                l >>= 1;\n                r >>= 1;\n\
    \            }\n            l = l2;\n            r = r2;\n        }\n    }\n\n\
    \   private:\n    int _n, log, size;\n    std::vector<F> lz;\n    void all_apply(int\
    \ k, const F& f) { lz[k] = Dual::composition(f, lz[k]); }\n    void push(int k)\
    \ {\n        all_apply(k << 1, lz[k]);\n        all_apply((k << 1) | 1, lz[k]);\n\
    \        lz[k] = Dual::id();\n    }\n};\n\n/**\n * @brief Dual Segment Tree (\u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs docs/data_structure/dual_segment_tree.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_e_dual_segment_tree.test.cpp
documentation_of: data_structure/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/dual_segment_tree.hpp
- /library/data_structure/dual_segment_tree.hpp.html
title: "Dual Segment Tree (\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
# Dual Segment Tree (双対セグメント木)

## 概要

`ac-library` を参考に。

- 非再帰
- 2冪
- 抽象化済
- 外部 `0-indexed` 、内部 `1-indexed`


機能面のイメージとしては、普通のセグメント木+双対セグメント木=遅延セグメント木。
どちらも遅延セグメント木ができることの一部しかできない代わりに定数倍が良いとみなせる。

普通のセグメント木では区間取得 (`prod`) が、双対セグメント木では区間作用 (`apply`) ができる。

工夫点は以下。

- 毎回モノイドを書くのはめんどくさい、ということで、モノイド構造体をインクルードすれば済むようになっている
    - `#include "algebra/dual_set.hpp"` などでインクルードできる
    - `dual_segment_tree<dual_set<int>> seg(n);` などで RUQ が使える
- `ac-library` の `seg.get(i)` に相当する機能を `seg[i]` で実現している
- マクロ不使用
    - 使いやすさを意識
- 普通のセグメント木、遅延セグメント木で採用していた `seg.chset(p, x)` は、双対セグメント木では区間幅1に対する `apply` 演算とみなせる
