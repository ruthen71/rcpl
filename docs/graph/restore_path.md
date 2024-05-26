---
title: Restore path
documentation_of: //graph/restore_path.hpp
---

$s$ から $t$ への最短路を

```cpp
int n;
Graph<T> g(n);
auto [d, p, r] = dijkstra(g, s, INF);
```

として求めた後に

```cpp
auto path = restore_path(p, t);
```

とすることで通った頂点の列を `s -> ... -> t` の順に `std::vector<int>` に格納して求める
