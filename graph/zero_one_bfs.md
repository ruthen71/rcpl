---
title: 01-BFS
documentation_of: ./zero_one_bfs.hpp
---

## 使い方

```cpp
Graph<T> g;
std::vector<int> s = {0};   // 始点の集合
const T INF;
auto [dist, par, root] = bellman_ford(g, s, INF);
```

`dist[i]` について
- 到達できない場合は `INF`

## 参考文献
