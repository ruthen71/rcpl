---
title: Random
documentation_of: ./base.hpp
---

## コンストラクタ

```cpp
(1) RandomFixed rng(uint64_t seed = 0)
(2) RandomAuto rng()
```

(1)

乱数のシード値は `seed` で初期化されます。

(2)

乱数のシード値は実行時刻をもとに初期化されます。

## rand_int

```cpp
(1) uint64_t rng.rand_int()
(2) uint64_t rng.rand_int(uint64_t mod)
(3) template <class T> T rng.rand_int(T l, T r)
```

(1)

$[0, 2^{64} - 1]$ の一様乱数（整数）を返します。

(2)

$[0, \bmod - 1]$ の一様乱数（整数）を返します。

(3)

$[l, r]$ の一様乱数（整数）を返します。

### 制約

(2)
- $\bmod > 0$

(3)
- $l \leq r$
- $r - l + 1$ がオーバーフローしない

## rand_double

```cpp
double rng.rand_double()
```

$[0, 1]$ の一様乱数（浮動小数点数）を返します。
