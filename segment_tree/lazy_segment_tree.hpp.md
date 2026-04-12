---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
  - icon: ':heavy_check_mark:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  - icon: ':heavy_check_mark:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  - icon: ':heavy_check_mark:'
    path: misc/topbit.hpp
    title: Topbit
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
    title: segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
    title: segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_assign.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
    title: segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_product_sum_add2.test.cpp
    title: segment_tree/test/lazy_segment_tree_product_sum_add2.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
    title: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
    title: verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment_tree/lazy_segment_tree.hpp\"\n\n#line 2 \"misc/bit_ceil.hpp\"\
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
    \ int)(x));\n}\n#line 2 \"misc/topbit.hpp\"\n\n#line 2 \"misc/countl_zero.hpp\"\
    \n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n// countl_zero\n// (000,\
    \ 001, 010, 011, 100) -> (32, 31, 30, 30, 29)\n#if __cplusplus >= 202002L\nusing\
    \ std::countl_zero;\n#else\nint countl_zero(unsigned int x) {\n    return x ==\
    \ 0 ? 32 : __builtin_clz(x);\n}\nint countl_zero(unsigned long long int x) {\n\
    \    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#endif\nint countl_zero(int\
    \ x) { return countl_zero((unsigned int)(x)); }\nint countl_zero(long long int\
    \ x) {\n    return countl_zero((unsigned long long int)(x));\n}\n#line 4 \"misc/topbit.hpp\"\
    \n\n// topbit\n// (000, 001, 010, 011, 100) -> (-1, 0, 1, 1, 2)\nint topbit(int\
    \ x) { return 31 - countl_zero(x); }\nint topbit(unsigned int x) { return 31 -\
    \ countl_zero(x); }\nint topbit(long long int x) { return 63 - countl_zero(x);\
    \ }\nint topbit(unsigned long long int x) { return 63 - countl_zero(x); }\n#line\
    \ 6 \"segment_tree/lazy_segment_tree.hpp\"\n\n#line 8 \"segment_tree/lazy_segment_tree.hpp\"\
    \n#include <vector>\n\n// Lazy Segment Tree\ntemplate <class AM> struct LazySegmentTree\
    \ {\n  public:\n    using MS = typename AM::MS;\n    using MF = typename AM::MF;\n\
    \    using S = typename MS::value_type;\n    using F = typename MF::value_type;\n\
    \n    LazySegmentTree() = default;\n\n    explicit LazySegmentTree(int n)\n  \
    \      : LazySegmentTree(std::vector<S>(n, MS::identity())) {}\n\n    explicit\
    \ LazySegmentTree(const std::vector<S>& v) : n((int)(v.size())) {\n        size\
    \ = bit_ceil(n);\n        log = countr_zero(size);\n        d = std::vector<S>(size\
    \ << 1, MS::identity());\n        lz = std::vector<F>(size, MF::identity());\n\
    \        for (int i = 0; i < n; i++) d[i + size] = v[i];\n        for (int i =\
    \ size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void\
    \ set(int p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n   \
    \     for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void add(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n  \
    \      for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = MS::operation(d[p],\
    \ x);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ operator[](int p) {\n        assert(0 <= p and p < n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n\
    \    }\n\n    S get(int p) {\n        assert(0 <= p and p < n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        return\
    \ d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l and l <= r\
    \ and r <= n);\n        if (l == r) return MS::identity();\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        S sml = MS::identity(), smr = MS::identity();\n\
    \        while (l < r) {\n            if (l & 1) sml = MS::operation(sml, d[l++]);\n\
    \            if (r & 1) smr = MS::operation(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return MS::operation(sml, smr);\n  \
    \  }\n\n    S all_prod() { return d[1]; }\n\n    void apply(int p, const F& f)\
    \ {\n        assert(0 <= p and p < n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = AM::mapping(f, d[p], 1);\n\
    \        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void apply(int\
    \ l, int r, const F& f) {\n        assert(0 <= l and l <= r and r <= n);\n   \
    \     if (l == r) return;\n\n        l += size;\n        r += size;\n\n      \
    \  for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        {\n            int l2 = l, r2 = r;\n            while (l < r) {\n  \
    \              if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i\
    \ <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n    \
    \        if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n\
    \    template <class G> int max_right(int l, G& g) {\n        assert(0 <= l and\
    \ l <= n);\n        assert(g(MS::identity()));\n        if (l == n) return n;\n\
    \        l += size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n  \
    \      S sm = MS::identity();\n        do {\n            while ((l & 1) == 0)\
    \ l >>= 1;\n            if (!g(MS::operation(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    push(l);\n                    l <<= 1;\n \
    \                   if (g(MS::operation(sm, d[l]))) {\n                      \
    \  sm = MS::operation(sm, d[l]);\n                        l++;\n             \
    \       }\n                }\n                return l - size;\n            }\n\
    \            sm = MS::operation(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return n;\n    }\n\n    template <class G> int min_left(int\
    \ r, G& g) {\n        assert(0 <= r and r <= n);\n        assert(g(MS::identity()));\n\
    \        if (r == 0) return 0;\n        r += size;\n        for (int i = log;\
    \ i >= 1; i--) push((r - 1) >> i);\n        S sm = MS::identity();\n        do\
    \ {\n            r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n      \
    \      if (!g(MS::operation(d[r], sm))) {\n                while (r < size) {\n\
    \                    push(r);\n                    r = (r << 1) | 1;\n       \
    \             if (g(MS::operation(d[r], sm))) {\n                        sm =\
    \ MS::operation(d[r], sm);\n                        r--;\n                   \
    \ }\n                }\n                return r + 1 - size;\n            }\n\
    \            sm = MS::operation(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n    std::vector<S> make_vector() {\n        std::vector<S>\
    \ vec(n);\n        for (int i = 0; i < n; i++) vec[i] = get(i);\n        return\
    \ vec;\n    }\n\n  private:\n    int n, log, size;\n    std::vector<S> d;\n  \
    \  std::vector<F> lz;\n\n    inline void update(int k) {\n        d[k] = MS::operation(d[k\
    \ << 1], d[(k << 1) | 1]);\n    }\n\n    void all_apply(int k, const F& f) {\n\
    \        d[k] = AM::mapping(f, d[k], 1 << (log - topbit(k)));\n        // MF::operation(f,\
    \ g), g(f(x))\n        if (k < size) lz[k] = MF::operation(lz[k], f);\n    }\n\
    \n    void push(int k) {\n        all_apply(k << 1, lz[k]);\n        all_apply((k\
    \ << 1) | 1, lz[k]);\n        lz[k] = MF::identity();\n    }\n};\n"
  code: "#pragma once\n\n#include \"../misc/bit_ceil.hpp\"\n#include \"../misc/countr_zero.hpp\"\
    \n#include \"../misc/topbit.hpp\"\n\n#include <cassert>\n#include <vector>\n\n\
    // Lazy Segment Tree\ntemplate <class AM> struct LazySegmentTree {\n  public:\n\
    \    using MS = typename AM::MS;\n    using MF = typename AM::MF;\n    using S\
    \ = typename MS::value_type;\n    using F = typename MF::value_type;\n\n    LazySegmentTree()\
    \ = default;\n\n    explicit LazySegmentTree(int n)\n        : LazySegmentTree(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit LazySegmentTree(const std::vector<S>& v)\
    \ : n((int)(v.size())) {\n        size = bit_ceil(n);\n        log = countr_zero(size);\n\
    \        d = std::vector<S>(size << 1, MS::identity());\n        lz = std::vector<F>(size,\
    \ MF::identity());\n        for (int i = 0; i < n; i++) d[i + size] = v[i];\n\
    \        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n     \
    \   }\n    }\n\n    void set(int p, const S& x) {\n        assert(0 <= p and p\
    \ < n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n\
    \    }\n\n    void add(int p, const S& x) {\n        assert(0 <= p and p < n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      d[p] = MS::operation(d[p], x);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S operator[](int p) {\n        assert(0 <= p and\
    \ p < n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        return d[p];\n    }\n\n    S get(int p) {\n        assert(0 <=\
    \ p and p < n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        if (l == r) return MS::identity();\n\n\
    \        l += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        S sml = MS::identity(),\
    \ smr = MS::identity();\n        while (l < r) {\n            if (l & 1) sml =\
    \ MS::operation(sml, d[l++]);\n            if (r & 1) smr = MS::operation(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ MS::operation(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n   \
    \ void apply(int p, const F& f) {\n        assert(0 <= p and p < n);\n       \
    \ p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p]\
    \ = AM::mapping(f, d[p], 1);\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    void apply(int l, int r, const F& f) {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l >>\
    \ i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <class G> int max_right(int l,\
    \ G& g) {\n        assert(0 <= l and l <= n);\n        assert(g(MS::identity()));\n\
    \        if (l == n) return n;\n        l += size;\n        for (int i = log;\
    \ i >= 1; i--) push(l >> i);\n        S sm = MS::identity();\n        do {\n \
    \           while ((l & 1) == 0) l >>= 1;\n            if (!g(MS::operation(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l <<= 1;\n                    if (g(MS::operation(sm, d[l])))\
    \ {\n                        sm = MS::operation(sm, d[l]);\n                 \
    \       l++;\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = MS::operation(sm, d[l]);\n      \
    \      l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\n  \
    \  template <class G> int min_left(int r, G& g) {\n        assert(0 <= r and r\
    \ <= n);\n        assert(g(MS::identity()));\n        if (r == 0) return 0;\n\
    \        r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = MS::identity();\n        do {\n            r--;\n            while\
    \ (r > 1 and (r & 1)) r >>= 1;\n            if (!g(MS::operation(d[r], sm))) {\n\
    \                while (r < size) {\n                    push(r);\n          \
    \          r = (r << 1) | 1;\n                    if (g(MS::operation(d[r], sm)))\
    \ {\n                        sm = MS::operation(d[r], sm);\n                 \
    \       r--;\n                    }\n                }\n                return\
    \ r + 1 - size;\n            }\n            sm = MS::operation(d[r], sm);\n  \
    \      } while ((r & -r) != r);\n        return 0;\n    }\n\n    std::vector<S>\
    \ make_vector() {\n        std::vector<S> vec(n);\n        for (int i = 0; i <\
    \ n; i++) vec[i] = get(i);\n        return vec;\n    }\n\n  private:\n    int\
    \ n, log, size;\n    std::vector<S> d;\n    std::vector<F> lz;\n\n    inline void\
    \ update(int k) {\n        d[k] = MS::operation(d[k << 1], d[(k << 1) | 1]);\n\
    \    }\n\n    void all_apply(int k, const F& f) {\n        d[k] = AM::mapping(f,\
    \ d[k], 1 << (log - topbit(k)));\n        // MF::operation(f, g), g(f(x))\n  \
    \      if (k < size) lz[k] = MF::operation(lz[k], f);\n    }\n\n    void push(int\
    \ k) {\n        all_apply(k << 1, lz[k]);\n        all_apply((k << 1) | 1, lz[k]);\n\
    \        lz[k] = MF::identity();\n    }\n};\n"
  dependsOn:
  - misc/bit_ceil.hpp
  - misc/countr_zero.hpp
  - misc/topbit.hpp
  - misc/countl_zero.hpp
  isVerificationFile: false
  path: segment_tree/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
  - segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
  - segment_tree/test/lazy_segment_tree_min_assign.test.cpp
  - segment_tree/test/lazy_segment_tree_min_plus.test.cpp
  - segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
  - segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
  - segment_tree/test/lazy_segment_tree_product_sum_add2.test.cpp
  - segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
  - segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
  - segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
documentation_of: segment_tree/lazy_segment_tree.hpp
layout: document
title: "Lazy Segment Tree (\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

長さ $n$ の配列 $a$ に対し

- 区間の要素の一括変更
- 区間の要素の総積の取得

を $O(\log n)$ 時間で処理することが出来ます。

テンプレート引数として、モノイド $(S, \cdot)$ と写像の集合 $F$ を `AM` として受け取ります。
モノイドとは以下の条件を満たす代数構造です。

- 結合律（ $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ ）が成立する。
- 単位元（ $a \cdot e=e \cdot a=a$ となる $e$ ）が存在する。

写像は以下の条件を満たします。

- 恒等写像（ $\mathrm{id}(x) = x$ となる $\mathrm{id}$ ）が存在する。
- 写像の合成について閉じている（$ f, g \in F $ ならば $ f \circ g \in F$ である）。
- $ f \in F, x, y \in S $ ならば $ f(x \cdot y) = f(x) \cdot f(y) $ である。

例えば、$\cdot$ として $\max$ を、$f(x)$ として加算を計算するモノイドは [ここ](../algebra/acted_monoid_max_plus.hpp) に定義されています。

計算量は $\cdot$, $e$, $f(x)$, $\circ$, $\mathrm{id}$ が定数時間で計算できると仮定したときのものを記述します。

## コンストラクタ

```cpp
(1) LazySegmentTree<M> seg(int n)
(2) LazySegmentTree<M> seg(std::vector<S> v)
```

(1)

長さ $n$ の数列 $a$ を作ります。初期値は全部 $e$ です。

(2)

長さ $ n = \left| v \right| $ の数列 $a$ を作ります。
$v$ の内容が初期値となります。

### 計算量

- $O(n)$

## set

```cpp
void seg.set(int p, S x)
```

$a_p$ に $x$ を代入します。

### 制約

- $0 \leq p < n$

### 計算量

- $O(\log n)$

## add

```cpp
void seg.add(int p, S x)
```

$a_p$ に $a_p \cdot x$ を代入します。

### 制約

- $0 \leq p < n$

### 計算量

- $O(\log n)$

## get

```cpp
(1) S seg.get(int p)
(2) S seg[int p]
```

$a_p$ を返します。

### 制約

- $0 \leq p < n$

### 計算量

- $O(\log n)$

## prod

```cpp
S seg.prod(int l, int r)
```

$a_l \cdot ... \cdot a_{r - 1}$ を、モノイドの性質を満たしていると仮定して計算します。
$l = r$ のときは $e$ を返します。

### 制約

- $0 \leq l \leq r \leq n$

### 計算量

- $O(\log n)$

## all_prod

```cpp
S seg.all_prod()
```

$a_0 \cdot ...\cdot a_{n - 1}$ を計算します。
$n = 0$ のときは $e$ を返します。

### 計算量

- $O(1)$

## apply

```cpp
(1) void seg.apply(int p, F f)
(2) void seg.apply(int l, int r, F f)
```

(1)

$a_p$ に $f(a_p)$ を代入します。

(2)

$ i = l, ..., r-1 $ について $a_i$ に $f(a_i)$ を代入します。

### 制約

(1)
- $0 \leq p < n$

(2)
- $0 \leq l \leq r \leq n$

### 計算量

- $O(\log n)$

## max_right

```cpp
int seg.max_right<G>(int l, G g)
```

`S` を引数にとり `bool` を返す関数オブジェクトを渡して使用します。

以下の条件を両方満たす $r$ を（いずれか一つ）返します。

- $r = l$ もしくは $g(a_{l} \cdot a_{l + 1} \cdot ... \cdot a_{r - 1}) = true$
- $r = n$ もしくは $g(a_{l} \cdot a_{l + 1} \cdot ... \cdot a_{r}) = false$

$g$ が単調だとすれば、$g(a_{l} \cdot a_{l + 1} \cdot ... \cdot a_{r - 1}) = true$ となる最大の $r$ と解釈することが可能です。

### 制約

- $g$ を同じ引数で呼んだ時、返り値は等しい（=副作用はない）
- $g(e) = true$
- $0 \leq l \leq n$

### 計算量

- $O(\log n)$

## min_left

```cpp
int seg.min_left<G>(int r, G g)
```

`S` を引数にとり `bool` を返す関数オブジェクトを渡して使用します。

以下の条件を両方満たす $l$ を（いずれか一つ）返します。

- $l = r$ もしくは $g(a_{l} \cdot a_{l + 1} \cdot ... \cdot a_{r - 1}) = true$
- $l = 0$ もしくは $g(a_{l - 1} \cdot a_{l} \cdot ... \cdot a_{r - 1}) = false$

$g$ が単調だとすれば、$g(a_{l} \cdot a_{l + 1} \cdot ... \cdot a_{r - 1}) = true$ となる最小の $l$ と解釈することが可能です。

### 制約

- $g$ を同じ引数で呼んだ時、返り値は等しい（=副作用はない）
- $g(e) = true$
- $0 \leq r \leq n$

### 計算量

- $O(\log n)$

## make_vector

```cpp
std::vector<S> seg.make_vector()
```

現在の数列 $a$ を返します。

### 計算量

- $O(n \log n)$
