---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/range_kth_smallest.hpp
    title: "\u533A\u9593\u306E k \u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u6C42\
      \u3081\u308B\u30AF\u30A8\u30EA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_kth_smallest.test.cpp
    title: data_structure/test/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segment_tree/persistent_segment_tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n// Persistent Segment Tree\n// N + Q log_2(N) \u306F N =\
    \ Q = 500000 \u306E\u3068\u304D 10000000 \u304F\u3089\u3044\ntemplate <class MS,\
    \ int MAX_NODES = 20'000'000> struct PersistentSegmentTree {\n  public:\n    using\
    \ S = typename MS::value_type;\n\n    struct Node {\n        S d;\n        Node\
    \ *l, *r;\n        Node() = default;\n        Node(S v, Node* l = nullptr, Node*\
    \ r = nullptr) : d(v), l(l), r(r) {}\n    };\n\n    PersistentSegmentTree() =\
    \ default;\n\n    explicit PersistentSegmentTree(int n)\n        : PersistentSegmentTree(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit PersistentSegmentTree(const std::vector<S>&\
    \ v)\n        : n((int)(v.size())) {\n        roots.push_back(build(v, 0, n));\n\
    \    }\n\n    int get_time() { return (int)(roots.size()) - 1; }\n\n    Node*\
    \ set(int p, const S& x, Node* root) {\n        assert(0 <= p and p < n);\n  \
    \      roots.push_back(set(p, x, 0, n, root));\n        return roots.back();\n\
    \    }\n\n    Node* set(int p, const S& x) { return set(p, x, roots.back()); }\n\
    \n    Node* set(int p, const S& x, int t) {\n        assert(0 <= t and t < (int)(roots.size()));\n\
    \        return set(p, x, roots[t]);\n    }\n\n    Node* add(int p, const S& x,\
    \ Node* root) {\n        assert(0 <= p and p < n);\n        roots.push_back(add(p,\
    \ x, 0, n, root));\n        return roots.back();\n    }\n\n    Node* add(int p,\
    \ const S& x) { return add(p, x, roots.back()); }\n\n    Node* add(int p, const\
    \ S& x, int t) {\n        assert(0 <= t and t < (int)(roots.size()));\n      \
    \  return add(p, x, roots[t]);\n    }\n\n    S get(int p, Node* root) const {\n\
    \        assert(0 <= p and p < n);\n        return prod(p, p + 1, root);\n   \
    \ }\n\n    S get(int p) const { return get(p, roots.back()); }\n\n    S get(int\
    \ p, int t) const {\n        assert(0 <= t and t < (int)(roots.size()));\n   \
    \     return get(p, roots[t]);\n    }\n\n    S operator[](int p) const {\n   \
    \     assert(0 <= p and p < n);\n        return prod(p, p + 1);\n    }\n\n   \
    \ S prod(int l, int r, Node* root) const {\n        assert(0 <= l and l <= r and\
    \ r <= n);\n        return prod(l, r, 0, n, root);\n    }\n\n    S prod(int l,\
    \ int r) const { return prod(l, r, roots.back()); }\n\n    S prod(int l, int r,\
    \ int t) const {\n        assert(0 <= t and t < (int)(roots.size()));\n      \
    \  return prod(l, r, roots[t]);\n    }\n\n    S all_prod(Node* root) const { return\
    \ root->d; }\n\n    S all_prod() const { return all_prod(roots.back()); }\n\n\
    \    S all_prod(int t) const {\n        assert(0 <= t and t < (int)(roots.size()));\n\
    \        return all_prod(roots[t]);\n    }\n\n    std::vector<S> make_vector(Node*\
    \ root) const {\n        std::vector<S> vec(n);\n        for (int i = 0; i < n;\
    \ i++) vec[i] = get(i, root);\n        return vec;\n    }\n\n    std::vector<S>\
    \ make_vector() const { return make_vector(roots.back()); }\n\n    std::vector<S>\
    \ make_vector(int t) const {\n        assert(0 <= t and t < (int)(roots.size()));\n\
    \        return make_vector(roots[t]);\n    }\n\n  private:\n    int n;\n    std::vector<Node*>\
    \ roots;\n    static inline Node pool[MAX_NODES];\n    static inline int pool_idx\
    \ = 0;\n\n    Node* new_node(S v, Node* l = nullptr, Node* r = nullptr) {\n  \
    \      return &(pool[pool_idx++] = Node(v, l, r));\n    }\n\n    Node* merge(Node*\
    \ l, Node* r) {\n        return new_node(MS::operation(l->d, r->d), l, r);\n \
    \   }\n\n    Node* build(const std::vector<S>& v, int l, int r) {\n        if\
    \ (l + 1 == r) {\n            return new_node(v[l]);\n        }\n        int m\
    \ = (l + r) / 2;\n        return merge(build(v, l, m), build(v, m, r));\n    }\n\
    \n    Node* set(int p, const S& x, int l, int r, Node* np) {\n        if (l +\
    \ 1 == r) {\n            return new_node(x);\n        }\n        int m = (l +\
    \ r) / 2;\n        if (l <= p and p < m) {\n            return merge(set(p, x,\
    \ l, m, np->l), np->r);\n        } else {\n            return merge(np->l, set(p,\
    \ x, m, r, np->r));\n        }\n    }\n\n    Node* add(int p, const S& x, int\
    \ l, int r, Node* np) {\n        if (l + 1 == r) {\n            return new_node(MS::operation(np->d,\
    \ x));\n        }\n        int m = (l + r) / 2;\n        if (l <= p and p < m)\
    \ {\n            return merge(add(p, x, l, m, np->l), np->r);\n        } else\
    \ {\n            return merge(np->l, add(p, x, m, r, np->r));\n        }\n   \
    \ }\n\n    S prod(int ql, int qr, int l, int r, Node* np) const {\n        //\
    \ [ql, qr) \u3068 [l, r) \u304C\u4EA4\u5DEE\u3057\u306A\u3044\n        if (qr\
    \ <= l or r <= ql) return MS::identity();\n        // [ql, qr) \u304C [l, r) \u3092\
    \u5B8C\u5168\u306B\u542B\u3093\u3067\u3044\u308B\n        if (ql <= l and r <=\
    \ qr) return np->d;\n        int m = (l + r) / 2;\n        return MS::operation(prod(ql,\
    \ qr, l, m, np->l),\n                             prod(ql, qr, m, r, np->r));\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n// Persistent Segment\
    \ Tree\n// N + Q log_2(N) \u306F N = Q = 500000 \u306E\u3068\u304D 10000000 \u304F\
    \u3089\u3044\ntemplate <class MS, int MAX_NODES = 20'000'000> struct PersistentSegmentTree\
    \ {\n  public:\n    using S = typename MS::value_type;\n\n    struct Node {\n\
    \        S d;\n        Node *l, *r;\n        Node() = default;\n        Node(S\
    \ v, Node* l = nullptr, Node* r = nullptr) : d(v), l(l), r(r) {}\n    };\n\n \
    \   PersistentSegmentTree() = default;\n\n    explicit PersistentSegmentTree(int\
    \ n)\n        : PersistentSegmentTree(std::vector<S>(n, MS::identity())) {}\n\n\
    \    explicit PersistentSegmentTree(const std::vector<S>& v)\n        : n((int)(v.size()))\
    \ {\n        roots.push_back(build(v, 0, n));\n    }\n\n    int get_time() { return\
    \ (int)(roots.size()) - 1; }\n\n    Node* set(int p, const S& x, Node* root) {\n\
    \        assert(0 <= p and p < n);\n        roots.push_back(set(p, x, 0, n, root));\n\
    \        return roots.back();\n    }\n\n    Node* set(int p, const S& x) { return\
    \ set(p, x, roots.back()); }\n\n    Node* set(int p, const S& x, int t) {\n  \
    \      assert(0 <= t and t < (int)(roots.size()));\n        return set(p, x, roots[t]);\n\
    \    }\n\n    Node* add(int p, const S& x, Node* root) {\n        assert(0 <=\
    \ p and p < n);\n        roots.push_back(add(p, x, 0, n, root));\n        return\
    \ roots.back();\n    }\n\n    Node* add(int p, const S& x) { return add(p, x,\
    \ roots.back()); }\n\n    Node* add(int p, const S& x, int t) {\n        assert(0\
    \ <= t and t < (int)(roots.size()));\n        return add(p, x, roots[t]);\n  \
    \  }\n\n    S get(int p, Node* root) const {\n        assert(0 <= p and p < n);\n\
    \        return prod(p, p + 1, root);\n    }\n\n    S get(int p) const { return\
    \ get(p, roots.back()); }\n\n    S get(int p, int t) const {\n        assert(0\
    \ <= t and t < (int)(roots.size()));\n        return get(p, roots[t]);\n    }\n\
    \n    S operator[](int p) const {\n        assert(0 <= p and p < n);\n       \
    \ return prod(p, p + 1);\n    }\n\n    S prod(int l, int r, Node* root) const\
    \ {\n        assert(0 <= l and l <= r and r <= n);\n        return prod(l, r,\
    \ 0, n, root);\n    }\n\n    S prod(int l, int r) const { return prod(l, r, roots.back());\
    \ }\n\n    S prod(int l, int r, int t) const {\n        assert(0 <= t and t <\
    \ (int)(roots.size()));\n        return prod(l, r, roots[t]);\n    }\n\n    S\
    \ all_prod(Node* root) const { return root->d; }\n\n    S all_prod() const { return\
    \ all_prod(roots.back()); }\n\n    S all_prod(int t) const {\n        assert(0\
    \ <= t and t < (int)(roots.size()));\n        return all_prod(roots[t]);\n   \
    \ }\n\n    std::vector<S> make_vector(Node* root) const {\n        std::vector<S>\
    \ vec(n);\n        for (int i = 0; i < n; i++) vec[i] = get(i, root);\n      \
    \  return vec;\n    }\n\n    std::vector<S> make_vector() const { return make_vector(roots.back());\
    \ }\n\n    std::vector<S> make_vector(int t) const {\n        assert(0 <= t and\
    \ t < (int)(roots.size()));\n        return make_vector(roots[t]);\n    }\n\n\
    \  private:\n    int n;\n    std::vector<Node*> roots;\n    static inline Node\
    \ pool[MAX_NODES];\n    static inline int pool_idx = 0;\n\n    Node* new_node(S\
    \ v, Node* l = nullptr, Node* r = nullptr) {\n        return &(pool[pool_idx++]\
    \ = Node(v, l, r));\n    }\n\n    Node* merge(Node* l, Node* r) {\n        return\
    \ new_node(MS::operation(l->d, r->d), l, r);\n    }\n\n    Node* build(const std::vector<S>&\
    \ v, int l, int r) {\n        if (l + 1 == r) {\n            return new_node(v[l]);\n\
    \        }\n        int m = (l + r) / 2;\n        return merge(build(v, l, m),\
    \ build(v, m, r));\n    }\n\n    Node* set(int p, const S& x, int l, int r, Node*\
    \ np) {\n        if (l + 1 == r) {\n            return new_node(x);\n        }\n\
    \        int m = (l + r) / 2;\n        if (l <= p and p < m) {\n            return\
    \ merge(set(p, x, l, m, np->l), np->r);\n        } else {\n            return\
    \ merge(np->l, set(p, x, m, r, np->r));\n        }\n    }\n\n    Node* add(int\
    \ p, const S& x, int l, int r, Node* np) {\n        if (l + 1 == r) {\n      \
    \      return new_node(MS::operation(np->d, x));\n        }\n        int m = (l\
    \ + r) / 2;\n        if (l <= p and p < m) {\n            return merge(add(p,\
    \ x, l, m, np->l), np->r);\n        } else {\n            return merge(np->l,\
    \ add(p, x, m, r, np->r));\n        }\n    }\n\n    S prod(int ql, int qr, int\
    \ l, int r, Node* np) const {\n        // [ql, qr) \u3068 [l, r) \u304C\u4EA4\u5DEE\
    \u3057\u306A\u3044\n        if (qr <= l or r <= ql) return MS::identity();\n \
    \       // [ql, qr) \u304C [l, r) \u3092\u5B8C\u5168\u306B\u542B\u3093\u3067\u3044\
    \u308B\n        if (ql <= l and r <= qr) return np->d;\n        int m = (l + r)\
    \ / 2;\n        return MS::operation(prod(ql, qr, l, m, np->l),\n            \
    \                 prod(ql, qr, m, r, np->r));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/persistent_segment_tree.hpp
  requiredBy:
  - data_structure/range_kth_smallest.hpp
  timestamp: '2026-04-12 20:46:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/range_kth_smallest.test.cpp
documentation_of: segment_tree/persistent_segment_tree.hpp
layout: document
title: "Persistent Segment Tree (\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

通常のセグメント木に加えて、過去のすべての状態に対して 1 点変更と総積の取得が可能なデータ構造です。

$t$ 回目の 1 点変更後が行われた後の長さ $n$ の 配列 $a^t$ に対し

- 要素の $1$ 点変更
- 区間の要素の総積の取得

を $O(\log n)$ 時間で処理することが出来ます。

テンプレート引数として、モノイド $(S, \cdot)$ を `M` として受け取ります。
モノイドとは以下の条件を満たす代数構造です。

- 結合律（ $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ ）が成立する。
- 単位元（ $a \cdot e=e \cdot a=a$ となる $e$ ）が存在する。

例えば、$\cdot$ として $\max$ を計算するモノイドは [ここ](../algebra/monoid/monoid_max.hpp) に定義されています。

計算量は $\cdot$, $e$ が定数時間で計算できると仮定したときのものを記述します。

## コンストラクタ

```cpp
(1) PersistentSegmentTree<M> seg(int n)
(2) PersistentSegmentTree<M> seg(std::vector<S> v)
```

(1)

長さ $n$ の数列 $a^0$ を作ります。初期値は全部 $e$ です。

(2)

長さ $ n = \left| v \right| $ の数列 $a^0$ を作ります。
$v$ の内容が初期値となります。

### 計算量

- $O(n)$

## get_time

```cpp
int seg.get_time()
```

永続セグメント木が作成された時刻を 0 とし、最後の set・add が行われた時刻を返します。

### 計算量

- $O(1)$

## set

```cpp
(1) Node* seg.set(int p, S x)
(2) Node* seg.set(int p, S x, int t)
(3) Node* seg.set(int p, S x, Node* root)
```

(1)

最新の状態の $a_p$ に $x$ を代入します。

(2)

時刻 $t$ の $a_p^t$ に $x$ を代入します。

(3)

時刻 $t$ のセグメント木のルートノードのポインタを `root` とし、$a_p^t$ に $x$ を代入します。

set のいずれについても、更新後のセグメント木のルートノードのポインタを返します。
このポインタでその後の set・add での操作対象のセグメント木を指定することができます。

### 制約

- $0 \leq p < n$

### 計算量

- $O(\log n)$

## add

```cpp
(1) Node* seg.add(int p, S x)
(2) Node* seg.add(int p, S x, int t)
(3) Node* seg.add(int p, S x, Node* root)
```

(1)

最新の状態の $a_p$ に $a_p \cdot x$ を代入します。

(2)

時刻 $t$ の $a_p^t$ に $a_p^t \cdot x$ を代入します。

(3)

時刻 $t$ のセグメント木のルートノードのポインタを `root` とし、$a_p^t$ に $a_p^t \cdot x$ を代入します。


add のいずれについても、更新後のセグメント木のルートノードのポインタを返します。
このポインタでその後の set・add での操作対象のセグメント木を指定することができます。


### 制約

- $0 \leq p < n$

### 計算量

- $O(\log n)$

## get

```cpp
(1-1) S seg.get(int p)
(1-2) S seg[int p]
(2) S seg.get(int p, int t)
(3) S seg.get(int p, Node* root)
```

(1)

最新の状態の $a_p$ を返します。

(2)

時刻 $t$ の $a_p^t$ を返します。

(3)

時刻 $t$ のセグメント木のルートノードのポインタを `root` とし、$a_p^t$ を返します。


### 制約

- $0 \leq p < n$

### 計算量

- $O(\log n)$

## prod

```cpp
(1) S seg.prod(int l, int r)
(2) S seg.prod(int l, int r, int t)
(3) S seg.prod(int l, int r, Node* root)
```


(1)

最新の状態の $a_l \cdot ... \cdot a_{r - 1}$ を計算します。

(2)

時刻 $t$ の $a_l^t \cdot ... \cdot a_{r - 1}^t$ を計算します。

(3)

時刻 $t$ のセグメント木のルートノードのポインタを `root` とし、$a_l^t \cdot ... \cdot a_{r - 1}^t$ を計算します。

prod のいずれについても、モノイドの性質を満たしていると仮定して計算します。
$l = r$ のときは $e$ を返します。

### 制約

- $0 \leq l \leq r \leq n$

### 計算量

- $O(\log n)$

## all_prod

```cpp
(1) S seg.all_prod()
(2) S seg.all_prod(int t)
(3) S seg.all_prod(Node* root)
```

(1)

最新の状態の $a_0 \cdot ...\cdot a_{n - 1}$ を計算します。

(2)

時刻 $t$ の $a_0^t \cdot ...\cdot a_{n - 1}^t$ を計算します。

(3)

時刻 $t$ のセグメント木のルートノードのポインタを `root` とし、$a_0^t \cdot ...\cdot a_{n - 1}^t$ を計算します。

all_prod のいずれについても、$n = 0$ のときは $e$ を返します。

### 計算量

- $O(1)$

## make_vector

```cpp
(1) std::vector<S> seg.make_vector()
(2) std::vector<S> seg.make_vector(int t)
(3) std::vector<S> seg.make_vector(Node* root)
```

(1)

最新の状態の数列 $a$ を返します。

(2)

時刻 $t$ の数列 $a^t$ を返します。

(3)

時刻 $t$ のセグメント木のルートノードのポインタを `root` とし、数列 $a^t$ を返します。

### 計算量

- $O(n \log n)$

## 参考文献

- [永続セグメント木 - AtCoderInfo](https://info.atcoder.jp/entry/algorithm_lectures/persistent_segment_tree)
