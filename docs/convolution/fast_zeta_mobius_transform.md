---
title: Fast Zeta/Mobius Transform (高速ゼータ変換・高速メビウス変換)
documentation_of: //convolution/fast_zeta_mobius_transform.hpp
---

1. 下位集合に対する高速ゼータ変換
1. 下位集合に対する高速メビウス変換
1. 上位集合に対する高速ゼータ変換
1. 上位集合に対する高速メビウス変換

## 使用例

- [PAST12 O](https://atcoder.jp/contests/past202209-open/submissions/40173852)
    - 各 popcount ごとに Bitwise OR Convolution を $ O(N^2) $ 回行い、全体の計算量は $ O(N^3 2^N + Q) $ であると思いきや、Fast Mobius Transform をまとめて行うことができるため、全体の計算量は $ O(N^2 2^N + Q) $ である
