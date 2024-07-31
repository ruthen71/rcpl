---
title: Restore path
documentation_of: ./restore_path.hpp
---

## 使い方

$s$ から $t$ への最短路を

```cpp
Graph<T> g;
std::vector<int> s = {0};   // 始点の集合
const T INF;
auto [dist, par, root] = dijkstra(g, s, INF);
```

として求めた後に

```cpp
auto path = restore_path(par, t);
```

とすることで通った頂点の列を `s -> ... -> t` の順に `std::vector<int>` に格納して求める

## 参考文献

