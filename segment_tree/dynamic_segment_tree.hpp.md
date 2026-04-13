---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/dynamic_segment_tree.test.cpp
    title: segment_tree/test/dynamic_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment_tree/dynamic_segment_tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n// Dynamic Segment Tree\n// Q log_2(N) \u306F Q = 500000,\
    \ N = 10^18 \u306E\u3068\u304D 30000000 \u304F\u3089\u3044\ntemplate <class MS,\
    \ int MAX_NODES = 30'000'000> struct DynamicSegmentTree {\n  public:\n    using\
    \ S = typename MS::value_type;\n\n    struct Node {\n        S d;\n        Node\
    \ *l, *r;\n        Node() = default;\n        Node(S v, Node* l = nullptr, Node*\
    \ r = nullptr) : d(v), l(l), r(r) {}\n    };\n\n    DynamicSegmentTree() = default;\n\
    \n    explicit DynamicSegmentTree(int n) : n(n), root(nullptr) {}\n\n    void\
    \ set(int p, const S& x) {\n        assert(0 <= p and p < n);\n        set(p,\
    \ x, 0, n, root);\n    }\n\n    void add(int p, const S& x) {\n        assert(0\
    \ <= p and p < n);\n        add(p, x, 0, n, root);\n    }\n\n    S operator[](int\
    \ p) const {\n        assert(0 <= p and p < n);\n        return prod(p, p + 1);\n\
    \    }\n\n    S get(int p) const {\n        assert(0 <= p and p < n);\n      \
    \  return prod(p, p + 1);\n    }\n\n    S prod(int l, int r) const {\n       \
    \ assert(0 <= l and l <= r and r <= n);\n        return prod(l, r, 0, n, root);\n\
    \    }\n\n    S all_prod() const { return (root == nullptr ? MS::identity() :\
    \ root->d); }\n\n    std::vector<std::pair<int, S>> make_vector() const {\n  \
    \      std::vector<std::pair<int, S>> vec;\n        auto rec = [&](auto f, int\
    \ l, int r, Node* np) -> void {\n            if (np == nullptr) return;\n    \
    \        if (l + 1 == r) vec.push_back({l, np->d});\n            int m = (l +\
    \ r) / 2;\n            f(f, l, m, np->l);\n            f(f, m, r, np->r);\n  \
    \      };\n        rec(rec, 0, n, root);\n        return vec;\n    }\n\n  private:\n\
    \    int n;\n    Node* root;\n    static inline Node pool[MAX_NODES];\n    static\
    \ inline int pool_idx = 0;\n\n    Node* new_node(S v, Node* l = nullptr, Node*\
    \ r = nullptr) {\n        return &(pool[pool_idx++] = Node(v, l, r));\n    }\n\
    \n    Node* merge(Node* l, Node* r, Node* np) {\n        np->d = MS::operation((l\
    \ == nullptr ? MS::identity() : l->d),\n                              (r == nullptr\
    \ ? MS::identity() : r->d));\n        return np;\n    }\n\n    Node* set(int p,\
    \ const S& x, int l, int r, Node*& np) {\n        if (np == nullptr) {\n     \
    \       np = new_node(MS::identity());\n        }\n        if (l + 1 == r) {\n\
    \            np->d = x;\n            return np;\n        }\n        int m = (l\
    \ + r) / 2;\n        if (l <= p and p < m) {\n            return merge(set(p,\
    \ x, l, m, np->l), np->r, np);\n        } else {\n            return merge(np->l,\
    \ set(p, x, m, r, np->r), np);\n        }\n    }\n\n    Node* add(int p, const\
    \ S& x, int l, int r, Node*& np) {\n        if (np == nullptr) {\n           \
    \ np = new_node(MS::identity());\n        }\n        if (l + 1 == r) {\n     \
    \       np->d = MS::operation(np->d, x);\n            return np;\n        }\n\
    \        int m = (l + r) / 2;\n        if (l <= p and p < m) {\n            return\
    \ merge(add(p, x, l, m, np->l), np->r, np);\n        } else {\n            return\
    \ merge(np->l, add(p, x, m, r, np->r), np);\n        }\n    }\n\n    S prod(int\
    \ ql, int qr, int l, int r, Node* np) const {\n        if (np == nullptr) return\
    \ MS::identity();\n        //  [ql, qr) \u3068 [l, r) \u304C\u4EA4\u5DEE\u3057\
    \u306A\u3044\n        if (qr <= l or r <= ql) return MS::identity();\n       \
    \ // [ql, qr) \u304C [l, r) \u3092\u5B8C\u5168\u306B\u542B\u3093\u3067\u3044\u308B\
    \n        if (ql <= l and r <= qr) return np->d;\n        int m = (l + r) / 2;\n\
    \        return MS::operation(prod(ql, qr, l, m, np->l),\n                   \
    \          prod(ql, qr, m, r, np->r));\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n// Dynamic Segment\
    \ Tree\n// Q log_2(N) \u306F Q = 500000, N = 10^18 \u306E\u3068\u304D 30000000\
    \ \u304F\u3089\u3044\ntemplate <class MS, int MAX_NODES = 30'000'000> struct DynamicSegmentTree\
    \ {\n  public:\n    using S = typename MS::value_type;\n\n    struct Node {\n\
    \        S d;\n        Node *l, *r;\n        Node() = default;\n        Node(S\
    \ v, Node* l = nullptr, Node* r = nullptr) : d(v), l(l), r(r) {}\n    };\n\n \
    \   DynamicSegmentTree() = default;\n\n    explicit DynamicSegmentTree(int n)\
    \ : n(n), root(nullptr) {}\n\n    void set(int p, const S& x) {\n        assert(0\
    \ <= p and p < n);\n        set(p, x, 0, n, root);\n    }\n\n    void add(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        add(p, x, 0, n,\
    \ root);\n    }\n\n    S operator[](int p) const {\n        assert(0 <= p and\
    \ p < n);\n        return prod(p, p + 1);\n    }\n\n    S get(int p) const {\n\
    \        assert(0 <= p and p < n);\n        return prod(p, p + 1);\n    }\n\n\
    \    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        return prod(l, r, 0, n, root);\n    }\n\n    S all_prod() const { return\
    \ (root == nullptr ? MS::identity() : root->d); }\n\n    std::vector<std::pair<int,\
    \ S>> make_vector() const {\n        std::vector<std::pair<int, S>> vec;\n   \
    \     auto rec = [&](auto f, int l, int r, Node* np) -> void {\n            if\
    \ (np == nullptr) return;\n            if (l + 1 == r) vec.push_back({l, np->d});\n\
    \            int m = (l + r) / 2;\n            f(f, l, m, np->l);\n          \
    \  f(f, m, r, np->r);\n        };\n        rec(rec, 0, n, root);\n        return\
    \ vec;\n    }\n\n  private:\n    int n;\n    Node* root;\n    static inline Node\
    \ pool[MAX_NODES];\n    static inline int pool_idx = 0;\n\n    Node* new_node(S\
    \ v, Node* l = nullptr, Node* r = nullptr) {\n        return &(pool[pool_idx++]\
    \ = Node(v, l, r));\n    }\n\n    Node* merge(Node* l, Node* r, Node* np) {\n\
    \        np->d = MS::operation((l == nullptr ? MS::identity() : l->d),\n     \
    \                         (r == nullptr ? MS::identity() : r->d));\n        return\
    \ np;\n    }\n\n    Node* set(int p, const S& x, int l, int r, Node*& np) {\n\
    \        if (np == nullptr) {\n            np = new_node(MS::identity());\n  \
    \      }\n        if (l + 1 == r) {\n            np->d = x;\n            return\
    \ np;\n        }\n        int m = (l + r) / 2;\n        if (l <= p and p < m)\
    \ {\n            return merge(set(p, x, l, m, np->l), np->r, np);\n        } else\
    \ {\n            return merge(np->l, set(p, x, m, r, np->r), np);\n        }\n\
    \    }\n\n    Node* add(int p, const S& x, int l, int r, Node*& np) {\n      \
    \  if (np == nullptr) {\n            np = new_node(MS::identity());\n        }\n\
    \        if (l + 1 == r) {\n            np->d = MS::operation(np->d, x);\n   \
    \         return np;\n        }\n        int m = (l + r) / 2;\n        if (l <=\
    \ p and p < m) {\n            return merge(add(p, x, l, m, np->l), np->r, np);\n\
    \        } else {\n            return merge(np->l, add(p, x, m, r, np->r), np);\n\
    \        }\n    }\n\n    S prod(int ql, int qr, int l, int r, Node* np) const\
    \ {\n        if (np == nullptr) return MS::identity();\n        //  [ql, qr) \u3068\
    \ [l, r) \u304C\u4EA4\u5DEE\u3057\u306A\u3044\n        if (qr <= l or r <= ql)\
    \ return MS::identity();\n        // [ql, qr) \u304C [l, r) \u3092\u5B8C\u5168\
    \u306B\u542B\u3093\u3067\u3044\u308B\n        if (ql <= l and r <= qr) return\
    \ np->d;\n        int m = (l + r) / 2;\n        return MS::operation(prod(ql,\
    \ qr, l, m, np->l),\n                             prod(ql, qr, m, r, np->r));\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/dynamic_segment_tree.hpp
  requiredBy: []
  timestamp: '2026-04-13 20:18:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/dynamic_segment_tree.test.cpp
documentation_of: segment_tree/dynamic_segment_tree.hpp
layout: document
title: "Dynamic Segment Tree (\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

「必要な部分だけ作るセグメント木」と呼ばれるデータ構造です。

単位元 $e$ で初期化されている長さ $n$ の配列 $a$ に対し

- 要素の $1$ 点変更
- 区間の要素の総積の取得

を $O(\log n)$ 時間で処理することが出来ます。

このとき、$n$ は $10^9$ くらいでも処理することが出来ます。

テンプレート引数として、モノイド $(S, \cdot)$ を `M` として受け取ります。
モノイドとは以下の条件を満たす代数構造です。

- 結合律（ $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ ）が成立する。
- 単位元（ $a \cdot e=e \cdot a=a$ となる $e$ ）が存在する。

例えば、$\cdot$ として $\max$ を計算するモノイドは [ここ](../algebra/monoid/monoid_max.hpp) に定義されています。

計算量は $\cdot$, $e$ が定数時間で計算できると仮定したときのものを記述します。

## コンストラクタ

```cpp
DynamicSegmentTree<M> seg(int n)
```

長さ $n$ の数列 $a$ を作ります。初期値は全部 $e$ です。

### 計算量

- $O(1)$

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

## make_vector

```cpp
std::vector<std::pair<int, S>> seg.make_vector()
```

現在の数列 $a$ のうち、一度でも set・add された $a_i$ に対する $(i, a_i)$ のペアを昇順に並べたものを返します。

### 計算量

一度でも set・add された $a_i$ の要素数を $q$ として

- $O(q \log n)$
