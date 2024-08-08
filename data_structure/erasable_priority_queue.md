---
title: Erasable Priority Queue (削除可能優先度付きキュー)
documentation_of: ./erasable_priority_queue.hpp
---

## 使い方

```cpp
ErasablePriorityQueue<int> que;                                         // 大きい順
ErasablePriorityQueue<int, std::vector<int>, std::greater<int>> que;    // 小さい順
```

要素が含まれていることが保証されている場合に削除可能

`std::multiset` よりも定数倍が良い

## 参考文献

- [AtCoder Beginner Contest 342 G - Retroactive Range Chmax](https://atcoder.jp/contests/abc342/tasks/abc342_g)
    - Dual Segment Tree における作用素を `ErasablePriorityQueue` を用いてすべて持っておくことで Undo 操作を実現している
