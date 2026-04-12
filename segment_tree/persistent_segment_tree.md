---
title: Persistent Segment Tree (永続セグメント木)
documentation_of: ./persistent_segment_tree.hpp
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

例えば、$\cdot$ として $\max$ を計算するモノイドは [ここ](../algebra/monoid//monoid_max.hpp) に定義されています。

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
std::vector<S> seg.make_vector()
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
