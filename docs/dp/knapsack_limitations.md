---
title: Knapsack Limitations (個数制限付きナップサック問題)
documentation_of: //dp/knapsack_limitations.hpp
---

- 個数制限付きナップサック問題をスライド最大値のテクニックを使って解く
    - `w` : 荷物の重さ
    - `v` : 荷物の価値
    - `m` : 荷物の個数
    - `W` : ナップサックの容量
    - `e` : 価値の総和として絶対に取らない値 (普通のナップサック問題なら-1など)
    - `comp` : 比較関数 (最小値を求めたいときには `std::less` を使う)
    - `s` : 初期値 (普通は0だが、部分和問題などでは違うかもしれない)
- $ O(nW) $
- 部分和問題を解くために `w[i] < 0` の処理も加えた

## 使用例
- [ABC269-G](https://atcoder.jp/contests/abc269/submissions/35003309)
    - `w[i] < 0` の処理を加えたおかげ
- [ABC286-D](https://atcoder.jp/contests/abc286/submissions/38232340)
    - $ O \left( X \sum_{i=1}^{N} B_{i} \right) $ で通る制約なので必要ないが、$ O(XN) $ で解くなら必要

