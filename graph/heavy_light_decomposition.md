---
title: Heavy-Light Decomposition (重軽分解)
documentation_of: ./heavy_light_decomposition.hpp
---

HL分解とも呼ばれる

## 使い方

```cpp
Graph<int> g;
int root;
HeavyLightDecomposition hld(g, root);
auto intervals = hld.query(u, v);   // u - v パスに対応する区間を列挙 (長さ 0 の場合もあり)
```

## 参考文献
- [【図解】木のパスに関するクエリは HL 分解！ その仕組みと実装を図で理解する｜Heavy-Light Decomposition](https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3)
- [My algorithm, HL Decomposition](https://kopricky.github.io/code/DataStructure_OnGraph/hl_decomposition.html)
- [math314のブログ, Heavy-Light Decomposition](https://math314.hateblo.jp/entry/2014/06/24/220107)