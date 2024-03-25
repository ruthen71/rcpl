---
title: Segment Tree (セグメント木)
documentation_of: //data_structure/segment_tree.hpp
---

基本的に `algebra/monoid_s` 以下のファイルをインクルードして使う

```cpp
// 1 点更新区間和
#include "algebra/monoid_s/monoid_sum.hpp"
#include "data_structure/segment_tree.hpp"
int main() {
    vector<int> A;
    SegmentTree<MonoidSum<int>> seg(A);
}
```

- `seg[i]` は `seg.get(i)` と同じ
- `seg.chset(p, x)` は `seg.set(p, op(seg.get(p), x))` と同じ (`seg.set(p, op(x, seg.get(p)))` ではない)


## 謝辞

実装の参考にした [ac-library](https://github.com/atcoder/ac-library) や [maspyさんのライブラリ](https://github.com/maspypy/library) に感謝申し上げます。
