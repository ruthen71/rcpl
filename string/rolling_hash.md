---
title: Rolling Hash (ローリングハッシュ)
documentation_of: ./rolling_hash.hpp
---

## 使い方

```cpp
RollingHash<mint261> rh;
auto rhs = rh.build(s);
mint261 hs = rh.prod(rhs, l, r);    // [l, r) のハッシュ値
```

## 参考文献
