---
title: Minimum Steiner Tree (最小シュタイナー木)
documentation_of: ./minimum_steiner_tree.hpp
---

## 使い方

```cpp
Graph<T> g;
std::vector<int> terminals;
auto dp = minimum_steiner_tree(g, terminals, INF);
auto wt = minimum_steiner_tree_mst(g, terminals, INF);
```

- `minimum_steiner_tree(g, terminals, inf)`
    - $ O(3 ^ k n + 2 ^ k m \log m) $
    - 戻り値は dp の配列
- `minimum_steiner_tree_mst(g, terminals, inf)`
    - ほとんどの頂点がターミナル点であるときに残りの点のうち使うものを全探索することで解く方法
    - $ O(2 ^ {n - k} (n + m)) $
    - 戻り値は最小シュタイナー木の辺の重みの総和

## 参考文献
