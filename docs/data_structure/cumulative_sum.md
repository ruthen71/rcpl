# 累積和

## 概要
2つの使い方が想定される
1. ある配列を入力し、さまざまな区間和を求める場合
    - コンストラクタ引数にその配列を直接取ると、勝手に構築する
    - `sum(l, r)`で `A[l] + A[l + 1] + ... + A[r - 1]` を返す
1. imos法のように使いたい場合
    - コンストラクタ引数には配列のサイズを入力する
    - このとき、配列サイズは1大きくする
        - 長さ $ N $ の配列に区間加算する場合、配列自体は右端を考慮して長さを $ N+1 $ にするのと同じ
    - `imos(l, r, z)`で $ [l, r) $ に $ z $ を加算する
    - `build()`で構築
    - `rui[p]`でimos法をする前での配列`A`の`A[p]`にアクセスできる
