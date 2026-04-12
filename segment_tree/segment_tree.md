---
title: Segment Tree (セグメント木)
documentation_of: ./segment_tree.hpp
---

長さ $n$ の配列 $a$ に対し

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
