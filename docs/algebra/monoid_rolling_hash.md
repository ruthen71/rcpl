---
title: ローリングハッシュ
documentation_of: ../../algebra/monoid_rolling_hash.hpp
---

## 使用例

- [ABC285 F](https://atcoder.jp/contests/abc285/tasks/abc285_f)
- 2つ以上のmodを組み合わせるなら、include ではなくべた書きするしかない
    - が、基数が $ 2^{61} - 1 $ なので余程のことがなければ衝突しないと思われる
