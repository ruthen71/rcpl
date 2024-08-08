---
title: Segment Tree の 1 点変更や区間総積を行う際にアクセスするノード番号の列挙
documentation_of: ./enumerate_segment_tree_nodes.hpp
---

## 使い方

Segment Tree の `set` や `prod` においてアクセスするノード番号を列挙する

Segment Tree の各ノードにデータ構造を乗せる際などに利用する

## 参考文献

- [AtCoder Beginner Contest 342 G - Retroactive Range Chmax](https://atcoder.jp/contests/abc342/tasks/abc342_g)
    - Dual Segment Tree における作用素を `ErasablePriorityQueue` を用いてすべて持っておくことで Undo 操作を実現している

- [AtCoder Beginner Contest 349 D - Divide Interval](https://atcoder.jp/contests/abc349/tasks/abc349_d)
    - 長さ $2^{60}$ の Segment Tree に区間 $[l, r)$ のクエリを投げたときにアクセスするノード番号を列挙する
    - `segment_tree_node_to_range` でノード番号から区間を求める

- [AtCoder Beginner Contest 355 E - Guess the Sum](https://atcoder.jp/contests/abc355/tasks/abc355_e)
    - `segment_tree_node_to_range` でノード番号から区間を求める