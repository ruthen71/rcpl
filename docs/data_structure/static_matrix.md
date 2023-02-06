---
title: Static Matrix (行列, サイズ固定)
documentation_of: //data_structure/static_matrix.hpp
---

行列のサイズが入力を受け取る前に決まっている場合、使うと速い

## 使用例

- [ABC189 E](https://atcoder.jp/contests/abc267/tasks/abc267_e)
    - 小さいサイズの行列を大量に作る場合、vector の 2 次元配列の場合、「push_back に備えて少し多めに取る」が積もりに積もってメモリ使用量が大きくなる
    - また、(おそらくメモリアクセスが連続しているかの違いにより) 実行時間にも大きな差が出る
    - [matrix 版](https://atcoder.jp/contests/abc189/submissions/35374154)
    - [static_matrix 版](https://atcoder.jp/contests/abc189/submissions/35374254)
