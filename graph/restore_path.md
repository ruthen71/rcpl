---
title: Restore path
documentation_of: ./restore_path.hpp
---

## 使い方

`s` から `t` への最短路を求めたあと, パス上の頂点列を `s -> ... -> t` の順に `std::vector<int>` に格納して求める

```cpp
Graph<T> g;
std::vector<int> s = {0};   // 始点の集合
const T INF;
auto [dist, par, root] = dijkstra(g, s, INF);
auto path = restore_path(par, t);
```

## 参考文献
