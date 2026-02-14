---
title: TopTwo
documentation_of: ./top_two.hpp
---

大きい 2 つの要素を管理する構造体です。

## コンストラクタ

```cpp
(1) TopTwo<T, inf> t()
(2) TopTwo<T, inf> t(T a, T b)
```

大きい 2 つの要素を `a`, `b` として作成します。

`a` と `b` は順不同です。

`a` と `b` を指定しなかった場合、それぞれ `-inf` で初期化されます。

## add

```cpp
bool t.add(T x)
```

`x` を追加します。

$(a, b)$ が更新された場合には `true` を、更新されなかった場合は `false` を返します。
