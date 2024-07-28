---
title: Traveling Salesman Problem (巡回セールスマン問題)
documentation_of: //graph/traveling_salesman_problem.hpp
---

- 初期化 (TSP = 最短ハミルトン閉路問題の場合)
    - TSP は閉路なのでどこを始点にしても良い
    - 始点を `s` とすると、「まだどこにも行ってないけど `s` にいる」ので `dp[0][s] = 0`
- 初期化 (最短ハミルトン路問題の場合)
    - 始点を `s` とすると、「 `s` は訪問済みと考えて良い」ので `dp[1 << s][s] = 0`
