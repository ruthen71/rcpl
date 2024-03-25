---
title: Lazy Segment Tree (遅延セグメント木)
documentation_of: //data_structure/lazy_segment_tree.hpp
---

基本的に `algebra/monoid_s_f` 以下のファイルをインクルードして使う

```cpp
// 区間更新区間和
#include "algebra/monoid_s_f/monoid_sum_size_set.hpp"
#include "data_structure/lazy_segment_tree.hpp"
int main() {
    vector<pair<int, int>> A;
    SegmentTree<MonoidSumSizeSet<int>> seg(A);
}
```

- `seg[i]` は `seg.get(i)` と同じ
- `seg.chset(p, x)` は `seg.set(p, op(seg.get(p), x))` と同じ (`seg.set(p, op(x, seg.get(p)))` ではない)

## 参考資料
[maspyさんの解説記事](https://maspypy.com/segment-tree-%e3%81%ae%e3%81%8a%e5%8b%89%e5%bc%b72)

区間作用 = apply(l, r, f)
- 作用素の伝搬 = push を含む部分
- 作用素の追加 = all_apply を含む部分
- 再計算 = update を含む部分
区間積 = prod(l, r)
- 作用素の伝搬 = push を含む部分
- 区間積の取得 = op を含む部分
1 点更新 = set(p, x)
- 作用素の伝搬 = push を含む部分
- 1 点更新 = `d[p] = x`
- 再計算 = update を含む部分
