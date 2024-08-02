---
title: Convex Polygon Cut (凸多角形の直線での切断)
documentation_of: ./convex_polyon_cut.hpp
---

## 使い方

直線の進行方向から見て, 左側の凸多角形, 右側の凸多角形の順で返す

```cpp
Polygon<T> P;
Line<T> L;
auto [polyl, polyr] = convex_polygon_cut(P, L);
```

## 参考文献
