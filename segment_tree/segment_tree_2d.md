---
title: 2D Segment Tree (2次元セグメント木)
documentation_of: .//segment_tree_2d.hpp
---

基本的に `algebra/monoid` 以下のファイルをインクルードして使う

```cpp
// 1 点更新矩形和
#include "algebra/monoid/monoid_plus.hpp"
#include "data_structure/segment_tree_2d.hpp"
int main() {
    vector<vector<int>> A;
    SegmentTree2D<MonoidPlus<int>> seg(A);
}
```

- `seg(h, w)` は `seg.get(h, w)` と同じ
- `seg.add(h, w, x)` は `seg.set(h, w, operation(seg.get(h, w), x))` と同じ (`seg.set(h, w, operation(x, seg.get(h, w)))` ではない)
    - 計算量は $ O(\log H \log W) $
