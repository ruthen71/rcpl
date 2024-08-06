---
title: Heavy-Light Decomposition (重軽分解)
documentation_of: ./heavy_light_decomposition.hpp
---

HL分解とも呼ばれる

## 使い方

```cpp
int root;
HeavyLightDecomposition hld(g, root);
auto intervals = hld.query(u, v);   // u - v パスに対応する区間を列挙 (長さ 0 の場合もあり)
```

## 参考文献
- [math314のブログ, Heavy-Light Decomposition](https://math314.hateblo.jp/entry/2014/06/24/220107)
