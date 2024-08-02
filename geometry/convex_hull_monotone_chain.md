---
title: Convex Hull (凸包)
documentation_of: ./convex_hull_monotone_chain.hpp
---

Andrew's Monotone Chain algorithm を用いて与えられた点集合から凸包を求める

## 使い方

```cpp
Polygon<T> P;
bool strict = true; // 凸包の辺上に並ぶ頂点は求めない
auto ch = convex_hull_monotone_chain(P, strict);
```

## 参考文献
