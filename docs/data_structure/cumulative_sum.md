---
title: 累積和
documentation_of: //data_structure/cumulative_sum.hpp
---


使い方
1. ある配列の区間和を求める場合
    - コンストラクタ引数に配列を入力
    - `sum(l, r)`で `A[l] + A[l + 1] + ... + A[r - 1]` を返す
1. imos法のように使う場合
    - コンストラクタ引数に入力した値を`n`とすると、$[0, n)$ への加算ができる(加算しうる半開区間の右端の値を入力する)
    - `imos(l, r, z)`で $ [l, r) $ に $ z $ を加算
    - `build()`で構築
    - `rui.get(p)`でアクセス
