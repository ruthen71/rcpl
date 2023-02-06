---
title: 2D Segment Tree (2次元セグメント木)
documentation_of: ./data_structure/segment_tree_2d.hpp
---

[自分の1次元セグメント木](https://ruthen71.github.io/rcpl/src/data_structure/segment_tree.hpp) をなるべくそのまま2次元に拡張することを意識して設計されている。


基本は `ac-library` と同じ。

- 非再帰
- 2冪
- 抽象化済
- 外部 `0-indexed` 、内部 `1-indexed`

工夫点は以下。

- 毎回モノイドを書くのはめんどくさい、ということで、モノイド構造体をインクルードすれば済むようになっている
    - `#include "algebra/monoid_max.hpp"` などでインクルードできる
    - `segment_tree_2d<monoid_max<int>> seg(h, w);` などで2次元RMQが使える
- `ac-library` の `seg.get(i)` の2次元版に相当する機能を `seg(h, w)` で実現している
- `seg[h][w] = op(seg[h][w], x)` とする `seg.chset(h, w, x)` を採用
    - `seg[h][w] = x` とするのは `seg.set(h, w, x)`
    - 案外 `seg.set(h, w, op(seg[h][w], x))` みたいなコードを書く機会は多いと思っている
    - 計算量は $ O(\log H \log W) $
    - モノイドが可換でないなどの理由により、`op(seg[h][w], x)` と `op(x, seg[h][w])` の結果が異なる場合に注意
- マクロ不使用
    - 使いやすさを意識

## 謝辞

変数やメソッドの命名規則、1次元セグメント木と共通する部分は [ac-library](https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp) を、モノイドの抽象化は [maspyさんのライブラリ](https://github.com/maspypy/library/blob/main/ds/segtree.hpp) を、2次元への拡張による追加の処理の記述は [Nyaanさんのライブラリ](https://github.com/NyaanNyaan/library/blob/master/data-structure-2d/2d-segment-tree.hpp) を参考にさせていただきました。ありがとうございます。
