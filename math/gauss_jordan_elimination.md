---
title: Gauss-Jordan elimination (ガウスジョルダンの掃き出し法)
documentation_of: ./gauss_jordan_elimination.hpp
---

## 使い方


```cpp
std::vector A(n, std::vector<T>(m));    // n x m 行列
int rank = gauss_jordan_elimination(A, m)   // 0 ~ m - 1 列目を掃き出す
```

## 参考文献

- [けんちょんの競プロ精進記録, Gauss-Jordan の掃き出し法と、連立一次方程式の解き方](https://drken1215.hatenablog.com/entry/2019/03/20/202800)
