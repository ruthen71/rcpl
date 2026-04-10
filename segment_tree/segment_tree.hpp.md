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
    path: segment_tree/test/segment_tree_and.test.cpp
    title: segment_tree/test/segment_tree_and.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_gcd.test.cpp
    title: segment_tree/test/segment_tree_gcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_min.test.cpp
    title: segment_tree/test/segment_tree_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_or.test.cpp
    title: segment_tree/test/segment_tree_or.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_plus.test.cpp
    title: segment_tree/test/segment_tree_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_rolling_hash.test.cpp
    title: segment_tree/test/segment_tree_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_xor.test.cpp
    title: segment_tree/test/segment_tree_xor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/euler_tour.test.cpp
    title: verify/graph/euler_tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_vertex_add_path_sum.test.cpp
    title: verify/graph/heavy_light_decomposition_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_vertex_add_subtree_sum.test.cpp
    title: verify/graph/heavy_light_decomposition_vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment_tree/segment_tree.hpp\"\n\n#line 2 \"misc/bit_ceil.hpp\"\
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
    \ int)(x));\n}\n#line 5 \"segment_tree/segment_tree.hpp\"\n\n#line 7 \"segment_tree/segment_tree.hpp\"\
    \n#include <vector>\n\n// Segment Tree\ntemplate <class MS> struct SegmentTree\
    \ {\n  public:\n    using S = typename MS::value_type;\n\n    SegmentTree() =\
    \ default;\n\n    explicit SegmentTree(int n)\n        : SegmentTree(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit SegmentTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        size = bit_ceil(n);\n        log = countr_zero(size);\n        d\
    \ = std::vector<S>(size << 1, MS::identity());\n        for (int i = 0; i < n;\
    \ i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n  \
    \          update(i);\n        }\n    }\n\n    void set(int p, const S& x) {\n\
    \        assert(0 <= p and p < n);\n        p += size;\n        d[p] = x;\n  \
    \      for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void add(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n  \
    \      d[p] = MS::operation(d[p], x);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S operator[](int p) const {\n        assert(0\
    \ <= p and p < n);\n        return d[p + size];\n    }\n\n    S get(int p) const\
    \ {\n        assert(0 <= p && p < n);\n        return d[p + size];\n    }\n\n\
    \    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        S sml = MS::identity(), smr = MS::identity();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = MS::operation(sml,\
    \ d[l++]);\n            if (r & 1) smr = MS::operation(d[--r], smr);\n       \
    \     l >>= 1;\n            r >>= 1;\n        }\n        return MS::operation(sml,\
    \ smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template <class\
    \ G> int max_right(int l, G& g) const {\n        assert(0 <= l and l <= n);\n\
    \        assert(g(MS::identity()));\n        if (l == n) return n;\n        l\
    \ += size;\n        S sm = MS::identity();\n        do {\n            while ((l\
    \ & 1) == 0) l >>= 1;\n            if (!g(MS::operation(sm, d[l]))) {\n      \
    \          while (l < size) {\n                    l <<= 1;\n                \
    \    if (g(MS::operation(sm, d[l]))) {\n                        sm = MS::operation(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = MS::operation(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);\n        return n;\n\
    \    }\n\n    template <class G> int min_left(int r, G& g) const {\n        assert(0\
    \ <= r and r <= n);\n        assert(g(MS::identity()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        S sm = MS::identity();\n        do {\n     \
    \       r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n            if (!g(MS::operation(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (r << 1)\
    \ | 1;\n                    if (g(MS::operation(d[r], sm))) {\n              \
    \          sm = MS::operation(d[r], sm);\n                        r--;\n     \
    \               }\n                }\n                return r + 1 - size;\n \
    \           }\n            sm = MS::operation(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n    std::vector<S> make_vector() {\n\
    \        std::vector<S> vec(n);\n        for (int i = 0; i < n; i++) vec[i] =\
    \ get(i);\n        return vec;\n    }\n\n  private:\n    int n, log, size;\n \
    \   std::vector<S> d;\n\n    inline void update(int k) {\n        d[k] = MS::operation(d[k\
    \ << 1], d[(k << 1) | 1]);\n    }\n};\n"
  code: "#pragma once\n\n#include \"../misc/bit_ceil.hpp\"\n#include \"../misc/countr_zero.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\n// Segment Tree\ntemplate <class\
    \ MS> struct SegmentTree {\n  public:\n    using S = typename MS::value_type;\n\
    \n    SegmentTree() = default;\n\n    explicit SegmentTree(int n)\n        : SegmentTree(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit SegmentTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        size = bit_ceil(n);\n        log = countr_zero(size);\n        d\
    \ = std::vector<S>(size << 1, MS::identity());\n        for (int i = 0; i < n;\
    \ i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n  \
    \          update(i);\n        }\n    }\n\n    void set(int p, const S& x) {\n\
    \        assert(0 <= p and p < n);\n        p += size;\n        d[p] = x;\n  \
    \      for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void add(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n  \
    \      d[p] = MS::operation(d[p], x);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S operator[](int p) const {\n        assert(0\
    \ <= p and p < n);\n        return d[p + size];\n    }\n\n    S get(int p) const\
    \ {\n        assert(0 <= p && p < n);\n        return d[p + size];\n    }\n\n\
    \    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        S sml = MS::identity(), smr = MS::identity();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = MS::operation(sml,\
    \ d[l++]);\n            if (r & 1) smr = MS::operation(d[--r], smr);\n       \
    \     l >>= 1;\n            r >>= 1;\n        }\n        return MS::operation(sml,\
    \ smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template <class\
    \ G> int max_right(int l, G& g) const {\n        assert(0 <= l and l <= n);\n\
    \        assert(g(MS::identity()));\n        if (l == n) return n;\n        l\
    \ += size;\n        S sm = MS::identity();\n        do {\n            while ((l\
    \ & 1) == 0) l >>= 1;\n            if (!g(MS::operation(sm, d[l]))) {\n      \
    \          while (l < size) {\n                    l <<= 1;\n                \
    \    if (g(MS::operation(sm, d[l]))) {\n                        sm = MS::operation(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = MS::operation(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);\n        return n;\n\
    \    }\n\n    template <class G> int min_left(int r, G& g) const {\n        assert(0\
    \ <= r and r <= n);\n        assert(g(MS::identity()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        S sm = MS::identity();\n        do {\n     \
    \       r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n            if (!g(MS::operation(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (r << 1)\
    \ | 1;\n                    if (g(MS::operation(d[r], sm))) {\n              \
    \          sm = MS::operation(d[r], sm);\n                        r--;\n     \
    \               }\n                }\n                return r + 1 - size;\n \
    \           }\n            sm = MS::operation(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n    std::vector<S> make_vector() {\n\
    \        std::vector<S> vec(n);\n        for (int i = 0; i < n; i++) vec[i] =\
    \ get(i);\n        return vec;\n    }\n\n  private:\n    int n, log, size;\n \
    \   std::vector<S> d;\n\n    inline void update(int k) {\n        d[k] = MS::operation(d[k\
    \ << 1], d[(k << 1) | 1]);\n    }\n};\n"
  dependsOn:
  - misc/bit_ceil.hpp
  - misc/countr_zero.hpp
  isVerificationFile: false
  path: segment_tree/segment_tree.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/heavy_light_decomposition_vertex_add_subtree_sum.test.cpp
  - verify/graph/heavy_light_decomposition_vertex_add_path_sum.test.cpp
  - verify/graph/euler_tour.test.cpp
  - segment_tree/test/segment_tree_and.test.cpp
  - segment_tree/test/segment_tree_plus.test.cpp
  - segment_tree/test/segment_tree_rolling_hash.test.cpp
  - segment_tree/test/segment_tree_gcd.test.cpp
  - segment_tree/test/segment_tree_xor.test.cpp
  - segment_tree/test/segment_tree_min.test.cpp
  - segment_tree/test/segment_tree_or.test.cpp
documentation_of: segment_tree/segment_tree.hpp
layout: document
title: Segment Tree
---

長さ $n$ の配列 $a$ に対し

- 要素の $1$ 点変更
- 区間の要素の総積の取得

を $O(\log n)$ 時間で処理することが出来ます。

テンプレート引数として、モノイド $(S, \cdot)$ を `M` として受け取ります。
モノイドとは以下の条件を満たす代数構造です。

- 結合律（ $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ ）が成立する。
- 単位元（ $a \cdot e=e \cdot a=a$ となる $e$ ）が存在する。

例えば、$\cdot$ として $\max$ を計算するモノイドは [ここ](../algebra/monoid_max.hpp) に定義されています。

計算量は $\cdot$, $e$ が定数時間で計算できると仮定したときのものを記述します。

## コンストラクタ

```cpp
(1) SegmentTree<M> seg(int n)
(2) SegmentTree<M> seg(std::vector<S> v)
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

- $O(1)$

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

- $O(n)$
