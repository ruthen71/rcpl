---
title: Segment Tree の 1 点変更や区間総積を行う際にアクセスするノード番号の列挙
documentation_of: //data_structure/enumerate_segment_tree_nodes.hpp
---

Segment Tree の `set` や `prod` においてアクセスするノード番号を列挙する

Segment Tree の各ノードにデータ構造を乗せる際などに利用する

## 使用例

- [ABC342 G](https://atcoder.jp/contests/abc342/submissions/50636081)
    - Dual Segment Tree における作用素を `std::multiset` を用いて陽にすべて持っておくことで Undo 操作を実現している

- [ABC349 D](https://atcoder.jp/contests/abc349/tasks/abc349_d)
    - 長さ $2^{60}$ の Segment Tree に区間 $[l, r)$ のクエリを投げたときにアクセスするノード番号を列挙する
    - `segment_tree_node_to_range` でノード番号から区間を求める

- [ABC355 E](https://atcoder.jp/contests/abc355/tasks/abc355_e)
    - `segment_tree_node_to_range` でノード番号から区間を求める