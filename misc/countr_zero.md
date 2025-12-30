---
title: Count Trailing Zeros
documentation_of: ./countr_zero.hpp
---

## countr_zero

```cpp
int countr_zero(T x)
```

末尾の連続する $0$ の個数を返します。

$x = 0$ のときはビット幅（$32$ または $64$）を返します。

## lowbit

```cpp
int lowbit(T x)
```

最下位に立っているビットの位置を返します。

$x = 0$ のときは $-1$ を返します。
