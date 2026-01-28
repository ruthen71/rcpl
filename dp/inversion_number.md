---
title: Inversion Number (転倒数)
documentation_of: ./inversion_number.hpp
---

転倒数（$i < j$ かつ $a_i > a_j$ となる組の数）を求めます。

転倒数（反転数）は数列 $a$ をソートするための隣接 swap の最小操作回数と等しいです。

## inversion_number

```cpp
(1) template <class T> long long inversion_number(std::vector<T>& a)
(2) template <class T> long long inversion_number(std::vector<T>& a, std::vector<T>& b)
```

(1)

長さ $n$ の数列 $a$ の転倒数を返します。

(2)

長さ $n$ の数列 $a$ を 数列 $b$ にするための隣接 swap の最小操作回数を返します。

### 制約

(2)

- 隣接 swap を有限回繰り返すことで数列 $a$ を 数列 $b$ にすることができる、すなわち、多重集合として $a$ と $b$ は一致する


### 計算量

- $O(n \log n)$
