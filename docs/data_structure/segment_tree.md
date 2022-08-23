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
- `op(a[p], x) == x` が成立するときのみ `set()` を行う `chset()` を採用
    - 案外 `seg.set(i, op(seg[i], x))` みたいなコードを書く機会は多いと思っている
    - `op(a[p], x) == x` の成立・不成立によらず、計算量は $ O(\log N) $
        - 条件分岐させても良かったが、モノイドが複雑になると `==` などでややこしくなりそうな気がした

