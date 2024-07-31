---
title: Lowest Common Ancestor (最小共通祖先)
documentation_of: ./lowest_common_ancestor.hpp
---

## 使い方

```cpp
Graph<T> g; // 辺の重みはなし
LowestCommonAncestor lca(g, root);
lca.lca(u, v)               // u, v の lca
lca.level_ancestor(u, d)    // u から d 本の辺を登った頂点を出力
lca.distance(u, v)          // u, v の距離
```

## 参考文献
