---
title: Auxiliary Tree (虚树)
documentation_of: //graph/auxiliary_tree.hpp
---

Virtual Tree とも呼ばれる

## 使い方

```cpp
Graph<T> g; // 木
AuxiliaryTree<T> aux(g, root);
std::vector<int> vs; // 頂点集合
auto [caux, label] = aux.get(vs);
```

圧縮後の木は頂点番号が `0` から `圧縮後の木の頂点数 - 1` になっている

圧縮後の木の頂点 `v` に対応するもとの木における頂点番号を知りたいときには `label[v]` を呼べば良い

圧縮後の木の辺 `u - v` の重みは、もとの木における `u - v` パスの辺の重みの総和と等しい

## 使用例

- [ABC359 G](https://atcoder.jp/contests/abc359/submissions/54857051)

## 参考文献

- [LCAをベースに構築するAuxiliary Treeのメモ](https://smijake3.hatenablog.com/entry/2019/09/15/200200)
- [AtCoder Beginner Contest 340 G - Leaf Color 解説](https://atcoder.jp/contests/abc340/editorial/9249)
