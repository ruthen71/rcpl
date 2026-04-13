---
title: Dynamic Segment Tree (動的セグメント木)
documentation_of: ./dynamic_segment_tree.hpp
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
