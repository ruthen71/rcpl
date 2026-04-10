---
title: $ 0 \leq p_{i} < a_{i} $ を満たす整数列 $p$ の列挙
documentation_of: ./enumerate_product.hpp
---

## enumerate_product

```cpp
void enumerate_product(std::vector<int> a, F f)
```

長さ $n$ の整数列 $a$ と `std::vector<int>` を引数にとる関数オブジェクト $f$ が与えられたとき、 $ i = 0, ..., n - 1 $ について $ 0 \leq p_{i} < a_{i} $ を満たす整数列 $p$ を列挙し、それぞれの $p$ に対して $ f(p) $ を実行します。


例えば $p$ を `std::vector<std::vector<int>>` に格納する場合、$f$ は以下のようになります。

```cpp
auto f = [&](std::vector<int> p) -> void {
    ps.push_back(p);
    return;
};
```

### 制約

- $a_{i}$ は `int` 型で表現可能

### 計算量

$f$ が定数時間で計算できると仮定したとき

- $ O \left( \prod_{i=0}^{n-1} a_{i} \right) $

$f$ の計算は多くの場合において $O(n)$ 以上必要です。
