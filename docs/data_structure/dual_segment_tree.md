---
title: Dual Segment Tree (双対セグメント木)
documentation_of: ./data_structure/dual_segment_tree.hpp
---

`ac-library` を参考に。

- 非再帰
- 2冪
- 抽象化済
- 外部 `0-indexed` 、内部 `1-indexed`


機能面のイメージとしては、普通のセグメント木+双対セグメント木=遅延セグメント木。
どちらも遅延セグメント木ができることの一部しかできない代わりに定数倍が良いとみなせる。

普通のセグメント木では区間取得 (`prod`) が、双対セグメント木では区間作用 (`apply`) ができる。

工夫点は以下。

- 毎回モノイドを書くのはめんどくさい、ということで、モノイド構造体をインクルードすれば済むようになっている
    - `#include "algebra/dual_set.hpp"` などでインクルードできる
    - `dual_segment_tree<dual_set<int>> seg(n);` などで RUQ が使える
- `ac-library` の `seg.get(i)` に相当する機能を `seg[i]` で実現している
- マクロ不使用
    - 使いやすさを意識
- 普通のセグメント木、遅延セグメント木で採用していた `seg.chset(p, x)` は、双対セグメント木では区間幅1に対する `apply` 演算とみなせる
