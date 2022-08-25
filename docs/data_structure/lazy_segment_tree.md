# Lazy Segment Tree (遅延セグメント木)

## 概要

基本は `ac-library` と同じ。

- 非再帰
- 2冪
- 抽象化済
- 外部 `0-indexed` 、内部 `1-indexed`


工夫点は以下。

- 毎回モノイドを書くのはめんどくさい、ということで、モノイド構造体をインクルードすれば済むようになっている
    - `#include "src/algebra/lazy_min_set.hpp"` などでインクルードできる
    - `segment_tree<lazy_min_set<int>> seg(n);` などで RMQ and RUQ が使える
- `ac-library` の `seg.get(i)` に相当する機能を `seg[i]` で実現している
- `seg[p] = op(seg[p], x)` とする `seg.chset(p, x)` を採用
    - `seg[p] = x` とするのは `seg.set(p, x)`
    - 案外 `seg.set(p, op(seg[p], x))` みたいなコードを書く機会は多いと思っている
    - 計算量は $ O(\log N) $
    - モノイドが可換でないなどの理由により、`op(seg[p], x)` と `op(x, seg[p])` の結果が異なる場合に注意
- マクロ不使用
    - 使いやすさを意識
- RSQ など区間長を別で持つ必要がある場合の初期化の方法は [ここ](https://ruthen71.github.io/rcpl/verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp) を参考にすること

## 謝辞

変数やメソッドの命名規則、メソッドの実装は [ac-library](https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp) を、モノイドの抽象化は [maspyさんのライブラリ](https://github.com/maspypy/library/blob/main/ds/segtree.hpp) を参考にさせていただきました。ありがとうございます。

