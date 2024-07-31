---
title: Traveling Salesman Problem (巡回セールスマン問題)
documentation_of: ./traveling_salesman_problem.hpp
---

## 使い方

```cpp
Graph<T> g;
const T INF;
auto res = traveling_salesman_problem<T>(g, INF);
// res.back()[0] が 答え
```

初期化

- 最短ハミルトン閉路問題 (= TSP) の場合
    - 始点は任意
    - 始点を `s` とすると、「まだどこにも行ってないけど `s` にいる」ので `dp[0][s] = 0`
- 最短ハミルトン路問題の場合
    - 始点を `s` とすると、「 `s` は訪問済みと考えて良い」ので `dp[1 << s][s] = 0`

## 参考文献
