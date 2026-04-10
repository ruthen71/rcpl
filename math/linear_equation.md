---
title: Linear Equation (線形方程式)
documentation_of: ./linear_equation.hpp
---

## 使い方


```cpp
// 線形方程式 Ax = b を解き, {rank, x} を返す
auto [rank, x] = linear_equation(A, b);
```

## 参考文献

- [けんちょんの競プロ精進記録, Gauss-Jordan の掃き出し法と、連立一次方程式の解き方](https://drken1215.hatenablog.com/entry/2019/03/20/202800)
- [競プロ典型 90 問 057 - Flip Flap（★6）](https://atcoder.jp/contests/typical90/tasks/typical90_be)
