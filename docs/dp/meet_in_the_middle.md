---
title: Meet in the middle (半分全列挙)
documentation_of: //dp/meet_in_the_middle.hpp
---

- 数列 $ a $ と整数 $ x $ が与えられたとき、$ \sum s_{i} a_{i} = x $ となるような数列 $ s $ ($ s_{i} $ は $1$ または $-1$) が存在するかを半分全列挙で判定する

- `meet_in_the_middle_faster` はソート済み要素の列挙をマージソート(`std::inplace_merge`)で、存在判定を尺取法で行うことで計算量を $ O(n 2^{n})$ から $ O(2^{n}) $ に落としている

## 使用例

- [ABC326 F](https://atcoder.jp/contests/abc326/submissions/49422940)
