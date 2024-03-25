---
title: Dual Segment Tree (双対セグメント木)
documentation_of: //data_structure/dual_segment_tree.hpp
---

普通のセグメント木+双対セグメント木=遅延セグメント木というイメージ
普通のセグメント木では区間取得 (`prod`) が、双対セグメント木では区間作用 (`apply`) ができる

基本的に `algebra/monoid_f` 以下のファイルをインクルードして使う

```cpp
// 区間更新 1 点取得
#include "algebra/monoid_f/monoid_set.hpp"
#include "data_structure/dual_segment_tree.hpp"
int main() {
    vector<int> A;
    DualSegmentTree<MonoidSet<int>> seg(A);
}
```

- `seg[i]` は `seg.get(i)` と同じ
