# 2次元累積和

## 概要
2つの使い方が想定される
1. ある2次元配列を入力し、さまざまな矩形和を求める場合
    - コンストラクタ引数にその2次元配列を直接取ると、勝手に構築する
    - `sum(lx, ly, rx, ry)`で $ [lx, rx) \times [ly, ry) $ の和を返す
1. 2次元imos法のように使いたい場合
    - コンストラクタ引数には配列のサイズを入力する
    - このとき、配列サイズは行列ともに1大きくする
        - 1次元imos法をするときに、長さ $ N $ の配列に区間加算する場合も配列自体は右端を考慮して長さを $ N+1 $ にするのと同じイメージ
    - `imos(lx, ly, rx, ry, z)`で $ [lx, rx) \times [ly, ry) $ に $ z $ を加算する
    - `build()`で構築
    - `get(x, y)`でimos法をする前での配列`A`の`A[x][y]`にアクセスできる
