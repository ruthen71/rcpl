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
    links: []
  bundledCode: "#line 2 \"data_structure/dual_segment_tree.hpp\"\n#include <vector>\n\
    #include <cassert>\ntemplate <class MF> struct DualSegmentTree {\n   public:\n\
    \    using F = typename MF::F;\n    DualSegmentTree() : DualSegmentTree(0) {}\n\
    \    DualSegmentTree(int n) : DualSegmentTree(std::vector<F>(n, MF::id())) {}\n\
    \    DualSegmentTree(const std::vector<F>& v) : n((int)(v.size())) {\n       \
    \ log = 0;\n        while ((1U << log) < (unsigned int)(n)) log++;\n        size\
    \ = 1 << log;\n        lz = std::vector<F>(size << 1, MF::id());\n        for\
    \ (int i = 0; i < n; i++) lz[i + size] = v[i];\n    }\n\n    F operator[](int\
    \ p) {\n        assert(0 <= p and p < n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return lz[p];\n    }\n\n    F get(int\
    \ p) {\n        assert(0 <= p and p < n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return lz[p];\n    }\n\n    void\
    \ apply(int p, const F& f) {\n        assert(0 <= p and p < n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        lz[p] =\
    \ f;\n    }\n\n    void apply(int l, int r, const F& f) {\n        assert(0 <=\
    \ l and l <= r and r <= n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n    }\n\n   private:\n    int n, log, size;\n    std::vector<F> lz;\n\
    \    void all_apply(int k, const F& f) { lz[k] = MF::composition(f, lz[k]); }\n\
    \    void push(int k) {\n        all_apply(k << 1, lz[k]);\n        all_apply((k\
    \ << 1) | 1, lz[k]);\n        lz[k] = MF::id();\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\ntemplate <class MF>\
    \ struct DualSegmentTree {\n   public:\n    using F = typename MF::F;\n    DualSegmentTree()\
    \ : DualSegmentTree(0) {}\n    DualSegmentTree(int n) : DualSegmentTree(std::vector<F>(n,\
    \ MF::id())) {}\n    DualSegmentTree(const std::vector<F>& v) : n((int)(v.size()))\
    \ {\n        log = 0;\n        while ((1U << log) < (unsigned int)(n)) log++;\n\
    \        size = 1 << log;\n        lz = std::vector<F>(size << 1, MF::id());\n\
    \        for (int i = 0; i < n; i++) lz[i + size] = v[i];\n    }\n\n    F operator[](int\
    \ p) {\n        assert(0 <= p and p < n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return lz[p];\n    }\n\n    F get(int\
    \ p) {\n        assert(0 <= p and p < n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return lz[p];\n    }\n\n    void\
    \ apply(int p, const F& f) {\n        assert(0 <= p and p < n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        lz[p] =\
    \ f;\n    }\n\n    void apply(int l, int r, const F& f) {\n        assert(0 <=\
    \ l and l <= r and r <= n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n    }\n\n   private:\n    int n, log, size;\n    std::vector<F> lz;\n\
    \    void all_apply(int k, const F& f) { lz[k] = MF::composition(f, lz[k]); }\n\
    \    void push(int k) {\n        all_apply(k << 1, lz[k]);\n        all_apply((k\
    \ << 1) | 1, lz[k]);\n        lz[k] = MF::id();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_e_dual_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
documentation_of: data_structure/dual_segment_tree.hpp
layout: document
title: "Dual Segment Tree (\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

普通のセグメント木+双対セグメント木=遅延セグメント木というイメージ
普通のセグメント木では区間取得 (`prod`) が、双対セグメント木では区間作用 (`apply`) ができる

基本的に `algebra/monoid_f` 以下のファイルをインクルードして使う

```cpp
// 区間更新 1 点取得
#include "algebra/monoid_f/monoid_set.hpp"
#include "data_structure/dual_segment_tree.hpp"
int main() {
    vector<int> A;
    DualSegmentTree<MonoidSet<int>> seg(A);
}
```

- `seg[i]` は `seg.get(i)` と同じ
