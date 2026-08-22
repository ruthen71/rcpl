---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
  - icon: ':heavy_check_mark:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/dual_segment_tree_assign.test.cpp
    title: segment_tree/test/dual_segment_tree_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/dual_segment_tree_plus.test.cpp
    title: segment_tree/test/dual_segment_tree_plus.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment_tree/dual_segment_tree.hpp\"\n\n#line 2 \"misc/bit_ceil.hpp\"\
    \n\n#include <cassert>\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\
    \n// bit_ceil\n// (0, 1, 2, 3, 4) -> (1, 1, 2, 4, 4)\n#if __cplusplus >= 202002L\n\
    using std::bit_ceil;\n#else\nunsigned int bit_ceil(unsigned int x) {\n    unsigned\
    \ int p = 1;\n    while (p < x) p *= 2;\n    return p;\n}\nunsigned long long\
    \ int bit_ceil(unsigned long long int x) {\n    unsigned long long int p = 1;\n\
    \    while (p < x) p *= 2;\n    return p;\n}\n#endif\nint bit_ceil(int x) {\n\
    \    assert(x >= 0);\n    return bit_ceil((unsigned int)(x));\n}\nlong long int\
    \ bit_ceil(long long int x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned\
    \ long long int)(x));\n}\n#line 2 \"misc/countr_zero.hpp\"\n\n#if __cplusplus\
    \ >= 202002L\n#include <bit>\n#endif\n\n// countr_zero\n// (000, 001, 010, 011,\
    \ 100) -> (32, 0, 1, 0, 2)\n#if __cplusplus >= 202002L\nusing std::countr_zero;\n\
    #else\nint countr_zero(unsigned int x) {\n    return x == 0 ? 32 : __builtin_ctz(x);\n\
    }\nint countr_zero(unsigned long long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n#endif\nint countr_zero(int x) { return countr_zero((unsigned int)(x)); }\n\
    int countr_zero(long long int x) {\n    return countr_zero((unsigned long long\
    \ int)(x));\n}\n#line 5 \"segment_tree/dual_segment_tree.hpp\"\n\n#line 7 \"segment_tree/dual_segment_tree.hpp\"\
    \n#include <vector>\n\n// Dual Segment Tree\ntemplate <class MF> struct DualSegmentTree\
    \ {\n  public:\n    using F = typename MF::value_type;\n\n    DualSegmentTree()\
    \ = default;\n\n    explicit DualSegmentTree(int n)\n        : DualSegmentTree(std::vector<F>(n,\
    \ MF::identity())) {}\n\n    explicit DualSegmentTree(const std::vector<F>& v)\
    \ : n((int)(v.size())) {\n        size = bit_ceil(n);\n        log = countr_zero(size);\n\
    \        lz = std::vector<F>(size << 1, MF::identity());\n        for (int i =\
    \ 0; i < n; i++) lz[i + size] = v[i];\n    }\n\n    F operator[](int p) {\n  \
    \      assert(0 <= p and p < n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        return lz[p];\n    }\n\n    F get(int p)\
    \ {\n        assert(0 <= p and p < n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return lz[p];\n    }\n\n    void\
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
    \        }\n    }\n\n    std::vector<F> make_vector() {\n        std::vector<F>\
    \ vec(n);\n        for (int i = 0; i < n; i++) vec[i] = get(i);\n        return\
    \ vec;\n    }\n\n  private:\n    int n, log, size;\n    std::vector<F> lz;\n\n\
    \    void all_apply(int k, const F& f) { lz[k] = MF::operation(lz[k], f); }\n\n\
    \    void push(int k) {\n        all_apply(k << 1, lz[k]);\n        all_apply((k\
    \ << 1) | 1, lz[k]);\n        lz[k] = MF::identity();\n    }\n};\n"
  code: "#pragma once\n\n#include \"../misc/bit_ceil.hpp\"\n#include \"../misc/countr_zero.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\n// Dual Segment Tree\ntemplate <class\
    \ MF> struct DualSegmentTree {\n  public:\n    using F = typename MF::value_type;\n\
    \n    DualSegmentTree() = default;\n\n    explicit DualSegmentTree(int n)\n  \
    \      : DualSegmentTree(std::vector<F>(n, MF::identity())) {}\n\n    explicit\
    \ DualSegmentTree(const std::vector<F>& v) : n((int)(v.size())) {\n        size\
    \ = bit_ceil(n);\n        log = countr_zero(size);\n        lz = std::vector<F>(size\
    \ << 1, MF::identity());\n        for (int i = 0; i < n; i++) lz[i + size] = v[i];\n\
    \    }\n\n    F operator[](int p) {\n        assert(0 <= p and p < n);\n     \
    \   p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n       \
    \ return lz[p];\n    }\n\n    F get(int p) {\n        assert(0 <= p and p < n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      return lz[p];\n    }\n\n    void apply(int p, const F& f) {\n        assert(0\
    \ <= p and p < n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        lz[p] = f;\n    }\n\n    void apply(int l, int r, const\
    \ F& f) {\n        assert(0 <= l and l <= r and r <= n);\n        if (l == r)\
    \ return;\n\n        l += size;\n        r += size;\n\n        for (int i = log;\
    \ i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n      \
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n\
    \            int l2 = l, r2 = r;\n            while (l < r) {\n              \
    \  if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r, f);\n\
    \                l >>= 1;\n                r >>= 1;\n            }\n         \
    \   l = l2;\n            r = r2;\n        }\n    }\n\n    std::vector<F> make_vector()\
    \ {\n        std::vector<F> vec(n);\n        for (int i = 0; i < n; i++) vec[i]\
    \ = get(i);\n        return vec;\n    }\n\n  private:\n    int n, log, size;\n\
    \    std::vector<F> lz;\n\n    void all_apply(int k, const F& f) { lz[k] = MF::operation(lz[k],\
    \ f); }\n\n    void push(int k) {\n        all_apply(k << 1, lz[k]);\n       \
    \ all_apply((k << 1) | 1, lz[k]);\n        lz[k] = MF::identity();\n    }\n};\n"
  dependsOn:
  - misc/bit_ceil.hpp
  - misc/countr_zero.hpp
  isVerificationFile: false
  path: segment_tree/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/dual_segment_tree_assign.test.cpp
  - segment_tree/test/dual_segment_tree_plus.test.cpp
documentation_of: segment_tree/dual_segment_tree.hpp
layout: document
title: "Dual Segment Tree (\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

普通のセグメント木+双対セグメント木=遅延セグメント木というイメージ
普通のセグメント木では区間取得 (`prod`) が、双対セグメント木では区間作用 (`apply`) ができる

基本的に `algebra/monoid` 以下のファイルをインクルードして使う

```cpp
// 区間更新 1 点取得
#include "algebra/monoid/monoid_assign.hpp"
#include "data_structure/dual_segment_tree.hpp"
int main() {
    constexpr int NONE = std::numeric_limits<int>::max();
    vector<int> A;
    DualSegmentTree<MonoidAssign<int, NONE>> seg(A);
}
```

- `seg[i]` は `seg.get(i)` と同じ
