## 概要

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
    - [ABC269-G](https://atcoder.jp/contests/abc269/tasks/abc269_g) を簡単に解ける