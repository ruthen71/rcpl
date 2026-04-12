---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_recursion.test.cpp
    title: segment_tree/test/segment_tree_recursion.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment_tree/segment_tree_recursion.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n// Segment Tree (\u518D\u5E30 + \u30DD\u30A4\u30F3\u30BF\u6728\
    )\n// 2N \u306F N = 500000 \u306E\u3068\u304D 1000000 \u304F\u3089\u3044\ntemplate\
    \ <class MS, int MAX_NODES = 2'000'000> struct SegmentTreeRecursion {\n  public:\n\
    \    using S = typename MS::value_type;\n\n    struct Node {\n        S d;\n \
    \       Node *l, *r;\n        Node() = default;\n        Node(S v, Node* l = nullptr,\
    \ Node* r = nullptr) : d(v), l(l), r(r) {}\n    };\n\n    SegmentTreeRecursion()\
    \ = default;\n\n    explicit SegmentTreeRecursion(int n)\n        : SegmentTreeRecursion(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit SegmentTreeRecursion(const std::vector<S>&\
    \ v)\n        : n((int)(v.size())) {\n        root = build(v, 0, n);\n    }\n\n\
    \    void set(int p, const S& x) {\n        assert(0 <= p and p < n);\n      \
    \  set(p, x, 0, n, root);\n    }\n\n    void add(int p, const S& x) {\n      \
    \  assert(0 <= p and p < n);\n        add(p, x, 0, n, root);\n    }\n\n    S operator[](int\
    \ p) const {\n        assert(0 <= p and p < n);\n        return prod(p, p + 1);\n\
    \    }\n\n    S get(int p) const {\n        assert(0 <= p and p < n);\n      \
    \  return prod(p, p + 1);\n    }\n\n    S prod(int l, int r) const {\n       \
    \ assert(0 <= l and l <= r and r <= n);\n        return prod(l, r, 0, n, root);\n\
    \    }\n\n    S all_prod() const { return root->d; }\n\n    std::vector<S> make_vector()\
    \ const {\n        std::vector<S> vec(n);\n        for (int i = 0; i < n; i++)\
    \ vec[i] = get(i);\n        return vec;\n    }\n\n  private:\n    int n;\n   \
    \ Node* root;\n    static inline Node pool[MAX_NODES];\n    static inline int\
    \ pool_idx = 0;\n\n    Node* new_node(S v, Node* l = nullptr, Node* r = nullptr)\
    \ {\n        return &(pool[pool_idx++] = Node(v, l, r));\n    }\n\n    Node* merge(Node*\
    \ l, Node* r, Node* np = nullptr) {\n        if (np == nullptr) {\n          \
    \  np = new_node(MS::operation(l->d, r->d), l, r);\n        } else {\n       \
    \     np->d = MS::operation(l->d, r->d);\n        }\n        return np;\n    }\n\
    \n    Node* build(const std::vector<S>& v, int l, int r) {\n        if (l + 1\
    \ == r) {\n            return new_node(v[l]);\n        }\n        int m = (l +\
    \ r) / 2;\n        return merge(build(v, l, m), build(v, m, r));\n    }\n\n  \
    \  Node* set(int p, const S& x, int l, int r, Node* np) {\n        if (l + 1 ==\
    \ r) {\n            np->d = x;\n            return np;\n        }\n        int\
    \ m = (l + r) / 2;\n        if (l <= p and p < m) {\n            return merge(set(p,\
    \ x, l, m, np->l), np->r, np);\n        } else {\n            return merge(np->l,\
    \ set(p, x, m, r, np->r), np);\n        }\n    }\n\n    Node* add(int p, const\
    \ S& x, int l, int r, Node* np) {\n        if (l + 1 == r) {\n            np->d\
    \ = MS::operation(np->d, x);\n            return np;\n        }\n        int m\
    \ = (l + r) / 2;\n        if (l <= p and p < m) {\n            return merge(add(p,\
    \ x, l, m, np->l), np->r, np);\n        } else {\n            return merge(np->l,\
    \ add(p, x, m, r, np->r), np);\n        }\n    }\n\n    S prod(int ql, int qr,\
    \ int l, int r, Node* np) const {\n        // [ql, qr) \u3068 [l, r) \u304C\u4EA4\
    \u5DEE\u3057\u306A\u3044\n        if (qr <= l or r <= ql) return MS::identity();\n\
    \        // [ql, qr) \u304C [l, r) \u3092\u5B8C\u5168\u306B\u542B\u3093\u3067\u3044\
    \u308B\n        if (ql <= l and r <= qr) return np->d;\n        int m = (l + r)\
    \ / 2;\n        return MS::operation(prod(ql, qr, l, m, np->l),\n            \
    \                 prod(ql, qr, m, r, np->r));\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n// Segment Tree\
    \ (\u518D\u5E30 + \u30DD\u30A4\u30F3\u30BF\u6728)\n// 2N \u306F N = 500000 \u306E\
    \u3068\u304D 1000000 \u304F\u3089\u3044\ntemplate <class MS, int MAX_NODES = 2'000'000>\
    \ struct SegmentTreeRecursion {\n  public:\n    using S = typename MS::value_type;\n\
    \n    struct Node {\n        S d;\n        Node *l, *r;\n        Node() = default;\n\
    \        Node(S v, Node* l = nullptr, Node* r = nullptr) : d(v), l(l), r(r) {}\n\
    \    };\n\n    SegmentTreeRecursion() = default;\n\n    explicit SegmentTreeRecursion(int\
    \ n)\n        : SegmentTreeRecursion(std::vector<S>(n, MS::identity())) {}\n\n\
    \    explicit SegmentTreeRecursion(const std::vector<S>& v)\n        : n((int)(v.size()))\
    \ {\n        root = build(v, 0, n);\n    }\n\n    void set(int p, const S& x)\
    \ {\n        assert(0 <= p and p < n);\n        set(p, x, 0, n, root);\n    }\n\
    \n    void add(int p, const S& x) {\n        assert(0 <= p and p < n);\n     \
    \   add(p, x, 0, n, root);\n    }\n\n    S operator[](int p) const {\n       \
    \ assert(0 <= p and p < n);\n        return prod(p, p + 1);\n    }\n\n    S get(int\
    \ p) const {\n        assert(0 <= p and p < n);\n        return prod(p, p + 1);\n\
    \    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and\
    \ r <= n);\n        return prod(l, r, 0, n, root);\n    }\n\n    S all_prod()\
    \ const { return root->d; }\n\n    std::vector<S> make_vector() const {\n    \
    \    std::vector<S> vec(n);\n        for (int i = 0; i < n; i++) vec[i] = get(i);\n\
    \        return vec;\n    }\n\n  private:\n    int n;\n    Node* root;\n    static\
    \ inline Node pool[MAX_NODES];\n    static inline int pool_idx = 0;\n\n    Node*\
    \ new_node(S v, Node* l = nullptr, Node* r = nullptr) {\n        return &(pool[pool_idx++]\
    \ = Node(v, l, r));\n    }\n\n    Node* merge(Node* l, Node* r, Node* np = nullptr)\
    \ {\n        if (np == nullptr) {\n            np = new_node(MS::operation(l->d,\
    \ r->d), l, r);\n        } else {\n            np->d = MS::operation(l->d, r->d);\n\
    \        }\n        return np;\n    }\n\n    Node* build(const std::vector<S>&\
    \ v, int l, int r) {\n        if (l + 1 == r) {\n            return new_node(v[l]);\n\
    \        }\n        int m = (l + r) / 2;\n        return merge(build(v, l, m),\
    \ build(v, m, r));\n    }\n\n    Node* set(int p, const S& x, int l, int r, Node*\
    \ np) {\n        if (l + 1 == r) {\n            np->d = x;\n            return\
    \ np;\n        }\n        int m = (l + r) / 2;\n        if (l <= p and p < m)\
    \ {\n            return merge(set(p, x, l, m, np->l), np->r, np);\n        } else\
    \ {\n            return merge(np->l, set(p, x, m, r, np->r), np);\n        }\n\
    \    }\n\n    Node* add(int p, const S& x, int l, int r, Node* np) {\n       \
    \ if (l + 1 == r) {\n            np->d = MS::operation(np->d, x);\n          \
    \  return np;\n        }\n        int m = (l + r) / 2;\n        if (l <= p and\
    \ p < m) {\n            return merge(add(p, x, l, m, np->l), np->r, np);\n   \
    \     } else {\n            return merge(np->l, add(p, x, m, r, np->r), np);\n\
    \        }\n    }\n\n    S prod(int ql, int qr, int l, int r, Node* np) const\
    \ {\n        // [ql, qr) \u3068 [l, r) \u304C\u4EA4\u5DEE\u3057\u306A\u3044\n\
    \        if (qr <= l or r <= ql) return MS::identity();\n        // [ql, qr) \u304C\
    \ [l, r) \u3092\u5B8C\u5168\u306B\u542B\u3093\u3067\u3044\u308B\n        if (ql\
    \ <= l and r <= qr) return np->d;\n        int m = (l + r) / 2;\n        return\
    \ MS::operation(prod(ql, qr, l, m, np->l),\n                             prod(ql,\
    \ qr, m, r, np->r));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/segment_tree_recursion.hpp
  requiredBy: []
  timestamp: '2026-04-12 20:46:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/segment_tree_recursion.test.cpp
documentation_of: segment_tree/segment_tree_recursion.hpp
layout: document
title: "Segment Tree (\u518D\u5E30 + \u30DD\u30A4\u30F3\u30BF\u6728)"
---

[Persistent Segment Tree](./persistent_segment_tree.hpp) の理解のために Segment Tree を再帰 + ポインタ木で書き直したものです。

[Segment Tree](./segment_tree.hpp) と比較すると以下のような欠点があります。

- get の計算量が $O(1)$ ではなく、 $O(\log n)$
- make_vector の計算量が $O(n)$ ではなく、 $O(n \log n)$
- max_right, min_left が未実装

したがって、基本的には実際のコンテストで使うメリットはありません。

## コンストラクタ

```cpp
(1) SegmentTreeRecursion<M> seg(int n)
(2) SegmentTreeRecursion<M> seg(std::vector<S> v)
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

## make_vector

```cpp
std::vector<S> seg.make_vector()
```

現在の数列 $a$ を返します。

### 計算量

- $O(n \log n)$
