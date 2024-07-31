---
title: Low Link (関節点・橋)
documentation_of: ./low_link.hpp
---

## 使い方

```cpp
Graph<T> g;
LowLink lk(g);
auto articulations = lk.articulations    // 関節点の集合
auto bridges = lk.bridges          // 橋である辺の集合
```

## 参考文献

