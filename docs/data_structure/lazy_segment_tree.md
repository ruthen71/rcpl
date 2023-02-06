---
title:Lazy Segment Tree (遅延セグメント木)
documentation_of: ./data_structure/lazy_segment_tree.hpp
---

基本は `ac-library` と同じ。

- 非再帰
- 2冪
- 抽象化済
- 外部 `0-indexed` 、内部 `1-indexed`


工夫点は以下。

- 毎回モノイドを書くのはめんどくさい、ということで、モノイド構造体をインクルードすれば済むようになっている
    - `#include "algebra/lazy_min_set.hpp"` などでインクルードできる
    - `lazy_segment_tree<lazy_min_set<int>> seg(n);` などで RMQ and RUQ が使える
- `ac-library` の `seg.get(i)` に相当する機能を `seg[i]` で実現している
- `seg[p] = op(seg[p], x)` とする `seg.chset(p, x)` を採用
    - `seg[p] = x` とするのは `seg.set(p, x)`
    - 案外 `seg.set(p, op(seg[p], x))` みたいなコードを書く機会は多いと思っている
    - 計算量は $ O(\log N) $
    - モノイドが可換でないなどの理由により、`op(seg[p], x)` と `op(x, seg[p])` の結果が異なる場合に注意
- マクロ不使用
    - 使いやすさを意識
- RSQ など区間長を別で持つ必要がある場合の初期化の方法は [ここ](https://ruthen71.github.io/rcpl/verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp) を参考にすること
    - 要するに `std::pair` の `first` に値を、`second` に区間長を入れる

## 謝辞

変数やメソッドの命名規則、メソッドの実装は [ac-library](https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp) を、モノイドの抽象化は [maspyさんのライブラリ](https://github.com/maspypy/library/blob/main/ds/segtree.hpp) および [ARMERIAさんのブログ](https://betrue12.hateblo.jp/entry/2020/09/23/005940) を参考にさせていただきました。ありがとうございます。

## 雑なメモ
- [maspyさんの解説記事](https://maspypy.com/segment-tree-%e3%81%ae%e3%81%8a%e5%8b%89%e5%bc%b72) と言葉遣いを合わせると、区間作用=apply(2引数)、伝搬=push、作用にhogeを追加=all_apply、再計算・更新=update、区間積=prod、1点更新=set
- `if (((l >> i) << i) != l)` みたいなやつは `push` では定数倍高速化なのか？(とりあえず消しても動いた)
- `update` では必要？
    - `apply` の途中の `all_apply` で書き換えた `d[i]` を、 `lz[i]` を下( `d[2*i]` と `d[2*i+1]` をはじめとする下層ノード) に伝播させて下の値が正しくなる前に書き換えてしまうからだと思う (多分)
- 上の議論は微妙で、そもそも `apply` や `prod` で見る可能性のあるノードに関する伝播や更新だけやっておけば良い、というだけの話な気がしてきた
    - 例えば $ N = 8 $ で `[0,6)` に区間作用させたいとき、ノード的には `d[2],lz[2],d[6],lz[6]` だけ触れば良い。よって伝播は `d[1]->d[2]&d[3], d[3]->d[6]&d[7]` ができれば良く、更新は `d[2]&d[3]->d[1], d[6]&d[7]->d[3]` だけできれば良い。
- 「初めて計算対象になるノード=奇数になるまで2で割り続けた後のノード」で、これより上のノード(=奇数を右シフトすることで得られるノード)で伝播や更新を行うと考えれば良い

