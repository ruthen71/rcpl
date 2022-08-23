# Segment Tree (セグメント木)

## 概要

実装は [ac-library](https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp) と [maspyさんのライブラリ](https://github.com/maspypy/library/blob/main/ds/segtree.hpp) を大いに参考にさせていただきました。この場を借りてお礼申し上げます。


基本は `ac-library` と同じ。

- 非再帰
- 2冪
- 抽象化済
- 外部 `0-indexed` 、内部 `1-indexed`


工夫点は以下。

- 毎回モノイドを書くのはめんどくさい、ということで、モノイド構造体をインクルードすれば済むようになっている
    - `#include "src/algebra/monoid_max.hpp"` などでインクルードできる
    - `segment_tree<monoid_max<int>> seg(n);` などでRMQが使える
- `ac-library` の `seg.get(i)` に相当する機能を `seg[i]` で実現している
    - より直感的
- `seg[p] = op(seg[p], x)` とする `seg.chset(p, x)` を採用
    - `seg[p] = x` とするのは `seg.set(p, x)`
    - 案外 `seg.set(p, op(seg[p], x))` みたいなコードを書く機会は多いと思っている
    - 計算量は $ O(\log N) $
        - 条件分岐させても良かったが、モノイドが複雑になると `==` などでややこしくなりそうな気がした
- マクロ不使用
    - 使いやすさを意識
