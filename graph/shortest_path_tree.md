---
title: Shortest Path Tree (最短経路木)
documentation_of: ./shortest_path_tree.hpp
---

最短経路木 (有向グラフ) を返す

## 使い方

```cpp
Graph<int> g(n);
vector<int> s;
auto [d, p, r] = dijkstra(g, s, inf);   // zero_one_bfs, bellman_ford でも OK
auto sptree = shortest_path_tree(g, p); // 最短経路木の 1 つが得られる
```

## 参考文献
