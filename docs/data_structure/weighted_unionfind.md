---
title: Weighted UnionFind (重みつき UnionFind)
documentation_of: ../data_structure/weighted_unionfind.hpp
---

- ポテンシャルつき UnionFind とも言う
- アーベル群が乗る
    - マグマ(閉じている)
    - 半群(閉じている、結合法則)
    - モノイド(閉じている、結合法則、単位元)
    - 群(閉じている、結合法則、単位元、逆元)
    - アーベル群(閉じている、結合法則、単位元、逆元、交換法則)
- データの持ち方
    - 各頂点に対し、「親の頂点番号」「親への辺の重み」「根なら部分木のサイズ」の 3 つの情報が持てれば良い
    - 「親の頂点番号」「根なら部分木のサイズ」はどの頂点もどちらかあれば OK なので `parents` でまとめている
    - 「親への辺の重み」は `diff_weight` が持つ（頂点が根ならアーベル群の単位元を入れる）
- `merge()` の説明
    - 各頂点 `x` に対し、`weight(x)` は `leader(x)` からの差分となっている
    - もともと `w` は `weight(y) - weight(x)` となっており、`w += weight(x)` によって `w` は `weight(y) - weight(leader(x))` となり、`w -= weight(y)` によって `w` は `weight(leader(y)) - weight(leader(x))` となり、最後に、`leader(x)` と `leader(y)` を Union by Size している
    - `leader(x)` の重みを 0 として、相対的に表現しているため、`diff_weight[y] = w` でOK

