---
title: Dijkstra's algorithm (ダイクストラ法)
documentation_of: ./dijkstra.hpp
---

## 使い方

```cpp
Graph<T> g;
std::vector<int> s = {0};   // 始点の集合
const T INF;
auto [dist, par, root] = dijkstra(g, s, INF);
```

`dist[i]` について
- 到達できない場合は `INF`

## 参考文献
