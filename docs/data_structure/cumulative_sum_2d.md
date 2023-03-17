---
title: 2次元累積和
documentation_of: //data_structure/cumulative_sum_2d.hpp
---

使い方
1. ある2次元配列の矩形和を求める場合
    - コンストラクタ引数に2次元配列を入力
    - `sum(lx, ly, rx, ry)`で $ [lx, rx) \times [ly, ry) $ の和を返す
1. 2次元imos法のように使う場合
    - コンストラクタ引数に入力した値を`h, w`とすると、$[0, h) \times [0, w)$ への加算ができる(加算しうる半開区間の右端の値を入力する)
    - `imos(lx, ly, rx, ry, z)`で $ [lx, rx) \times [ly, ry) $ に $ z $ を加算
    - `build()`で構築
    - `rui.get(x, y)`でアクセス
