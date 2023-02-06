---
title: Sliding Window Minimum (スライド最小値)
documentation_of: //dp/sliding_window_minimum.hpp
---

- 長さ $ n $ の数列 $ a $ と正整数 $k$ に対し、$ b_i = min \{ a_{i}, a_{i+1}, ... , a_{i+k-1} \} $ として定義される数列 $b$ を計算する
- $ O(n) $

### お気持ち
- 1つ右端を進めたら1つ左端を進める、というイメージでアルゴリズムは進み、デックに入れる値が常に小さい順になるようにすることで、先頭の値が最小値になるようにしている

