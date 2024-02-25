---
title: Erasable Priority Queue (削除可能優先度付きキュー)
documentation_of: //data_structure/erasable_priority_queue.hpp
---

要素が含まれていることが保証されている場合に削除可能

`std::multiset` よりも定数倍が良い

比較関数を自分で定義する場合は `ErasablePriorityQueue<int, std::greater<int>>` などとする
