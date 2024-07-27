---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
    title: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/traveling_salesman_problem.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\ntemplate <class T> struct Edge {\n    int from, to;\n \
    \   T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int to,\
    \ T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n    \
    \    // output format: \"{ id : from -> to, cost }\"\n        return os << \"\
    { \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \"\
    \ }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    dp/traveling_salesman_problem.hpp\"\n\ntemplate <class T>\nstd::vector<std::vector<T>>\
    \  //\ntraveling_salesman_problem(Graph<T> &G, const T INF) {\n    const int N\
    \ = (int)G.size();\n    const int N2 = 1 << N;\n\n    std::vector dist(N, std::vector<T>(N,\
    \ INF));\n    for (int i = 0; i < N; i++) dist[i][i] = T(0);\n    for (int i =\
    \ 0; i < N; i++) {\n        for (auto &&e : G[i]) {\n            dist[e.from][e.to]\
    \ = std::min(dist[e.from][e.to], e.cost);\n        }\n    }\n    std::vector dp(N2,\
    \ std::vector<T>(N, INF));\n    dp[0][0] = 0;\n    for (int bit = 0; bit < N2;\
    \ bit++) {\n        for (int u = 0; u < N; u++) {\n            if (dp[bit][u]\
    \ == INF) continue;\n            for (int v = 0; v < N; v++) {\n             \
    \   if (bit >> v & 1) continue;\n                if (dist[u][v] == INF) continue;\n\
    \                dp[bit | (1 << v)][v] = std::min(dp[bit | (1 << v)][v], dp[bit][u]\
    \ + dist[u][v]);\n            }\n        }\n    }\n    return dp;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T>\nstd::vector<std::vector<T>>  //\ntraveling_salesman_problem(Graph<T> &G,\
    \ const T INF) {\n    const int N = (int)G.size();\n    const int N2 = 1 << N;\n\
    \n    std::vector dist(N, std::vector<T>(N, INF));\n    for (int i = 0; i < N;\
    \ i++) dist[i][i] = T(0);\n    for (int i = 0; i < N; i++) {\n        for (auto\
    \ &&e : G[i]) {\n            dist[e.from][e.to] = std::min(dist[e.from][e.to],\
    \ e.cost);\n        }\n    }\n    std::vector dp(N2, std::vector<T>(N, INF));\n\
    \    dp[0][0] = 0;\n    for (int bit = 0; bit < N2; bit++) {\n        for (int\
    \ u = 0; u < N; u++) {\n            if (dp[bit][u] == INF) continue;\n       \
    \     for (int v = 0; v < N; v++) {\n                if (bit >> v & 1) continue;\n\
    \                if (dist[u][v] == INF) continue;\n                dp[bit | (1\
    \ << v)][v] = std::min(dp[bit | (1 << v)][v], dp[bit][u] + dist[u][v]);\n    \
    \        }\n        }\n    }\n    return dp;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: dp/traveling_salesman_problem.hpp
  requiredBy: []
  timestamp: '2024-01-30 13:51:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dpl/aoj_dpl_2_a.test.cpp
documentation_of: dp/traveling_salesman_problem.hpp
layout: document
title: "Traveling Salesman Problem (\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\
  \u554F\u984C)"
---

- 初期化 (TSP = 最短ハミルトン閉路問題の場合)
    - TSP は閉路なのでどこを始点にしても良い
    - 始点を `s` とすると、「まだどこにも行ってないけど `s` にいる」ので `dp[0][s] = 0`
- 初期化 (最短ハミルトン路問題の場合)
    - 始点を `s` とすると、「 `s` は訪問済みと考えて良い」ので `dp[1 << s][s] = 0`
