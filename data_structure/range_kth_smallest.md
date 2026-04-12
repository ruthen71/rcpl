---
title: 区間の k 番目に小さい値を求めるクエリ
documentation_of: ./range_kth_smallest.hpp
---

長さ $n$ の配列 $a$ に対し、区間 $[l, r)$ の $k$ 番目に小さい値を求めます。

## コンストラクタ

```cpp
RangeKthSmallest<T> rks(std::vector<T> a)
```

長さ $n$ の数列 $a$ で初期化します。

### 計算量

- $O(n \log n)$

## query

```cpp
T query(int l, int r, int k)
```

長さ $n$ の配列 $a$ に対し、区間 $[l, r)$ の $k$ 番目に小さい値を求めます。

$k$ は 0-indexed です。

### 制約

- $0 \leq l < r \leq n$
- $0 \leq k < r - l$

### 計算量

- $O(\log^2 n)$

## 参考文献

- [永続セグメント木 - AtCoderInfo](https://info.atcoder.jp/entry/algorithm_lectures/persistent_segment_tree)
