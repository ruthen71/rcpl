---
title: Random
documentation_of: ./base.hpp
---

64bit の疑似乱数生成器です。内部で SplitMix64 を用いており、固定シードで決定的に生成する `RandomFixed` と、実行時刻から自動でシードを振る `RandomAuto` を提供します。簡易利用向けに自動シード済みのグローバル変数 `rng_auto` も用意されています。

## コンストラクタ（固定シード）

```cpp
RandomFixed rng(uint64_t seed = 0)
```

`seed` で初期化された決定的な生成器を作ります。

### 計算量

- $O(1)$

## コンストラクタ（自動シード）

```cpp
RandomAuto rng
```

実行時刻をもとにシードを決めた生成器を作ります。`seed` 引数を渡すこともできますが、`auto_seed` モードでは `seed == 0` を仮定しているため、非 0 を渡すと `assert` に引っかかります。

### 計算量

- $O(1)$

## rand_int

```cpp
uint64_t rng.rand_int()
```

$[0, 2^{64} - 1]$ の一様乱数を返します。

### 計算量

- $O(1)$

## rand_int(mod)

```cpp
uint64_t rng.rand_int(uint64_t mod)
```

$[0, \bmod - 1]$ の乱数を返します。

### 制約

- $\bmod > 0$

### 計算量

- $O(1)$

## rand_int(l, r)

```cpp
template <class T>
T rng.rand_int(T l, T r)
```

$[l, r]$ の乱数を返します。

### 制約

- $l \leq r$

### 計算量

- $O(1)$
