---
title: Bit Ceil
documentation_of: ./bit_ceil.hpp
---

## bit_ceil

```cpp
T bit_ceil(T x)
```

$x \leq 2^m$ となる最小の $2^m$（$m$ は $0$ 以上の整数）を返します。

$x = 0$ のときは $1$ を返します。

### 制約

- $x \geq 0$
