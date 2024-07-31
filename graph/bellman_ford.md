---
title: Bellman-Ford algorithm (ベルマンフォード法)
documentation_of: ./bellman_ford.hpp
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
- 負閉路を使っていくらでも小さくできる場合は `-INF`

## 参考文献
