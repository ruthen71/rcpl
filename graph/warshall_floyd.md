---
title: Warshall-Floyd algorithm (ワーシャルフロイド法)
documentation_of: ./warshall_floyd.hpp
---

## 使い方

```cpp
Graph<T> g;
const T INF;
auto dist = warshall_floyd(g, INF);
```

`dist[i][j]` について
- 到達できない場合は `INF`
- 負閉路を使っていくらでも小さくできる場合は `-INF`

## 参考文献
