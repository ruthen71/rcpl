---
title: Segment Tree (再帰 + ポインタ木)
documentation_of: ./segment_tree_recursion.hpp
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
