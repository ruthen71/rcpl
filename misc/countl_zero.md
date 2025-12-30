---
title: Count Leading Zeros
documentation_of: ./countl_zero.hpp
---

## countl_zero

```cpp
int countl_zero(T x)
```

先頭の連続する $0$ の個数を返します。

$x = 0$ のときはビット幅（$32$ または $64$）を返します。

## topbit

```cpp
int topbit(T x)
```

最上位に立っているビットの位置を返します。

$x = 0$ のときは $-1$ を返します。
