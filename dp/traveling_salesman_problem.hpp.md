---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Edge<T> &e) {\n        // output format:\
    \ \"{ id : from -> to, cost }\"\n        return os << \"{ \" << e.id << \" : \"\
    \ << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\n\
    template <class T> using Edges = std::vector<Edge<T>>;\ntemplate <class T> using\
    \ Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"dp/traveling_salesman_problem.hpp\"\
    \n\ntemplate <class T>\nstd::vector<std::vector<T>>  //\ntraveling_salesman_problem(Graph<T>\
    \ &G, const T INF) {\n    int N = (int)G.size();\n    int N2 = 1 << N;\n\n   \
    \ std::vector<std::vector<T>> dist(N, std::vector<T>(N, INF));\n    for (int i\
    \ = 0; i < N; i++) dist[i][i] = T(0);\n    for (int i = 0; i < N; i++) {\n   \
    \     for (auto &&e : G[i]) {\n            dist[e.from][e.to] = std::min(dist[e.from][e.to],\
    \ e.cost);\n        }\n    }\n\n    std::vector<std::vector<T>> dp(N2, std::vector<T>(N,\
    \ INF));\n    dp[0][0] = 0;\n    for (int s = 0; s < (1 << N); s++) {\n      \
    \  for (int v = 0; v < N; v++) {\n            if (s >> v & 1) continue;\n    \
    \        for (int u = 0; u < N; u++) {\n                if (u == v) continue;\n\
    \                dp[s | (1 << v)][v] = std::min(dp[s | (1 << v)][v], dp[s][u]\
    \ + dist[u][v]);\n            }\n        }\n    }\n    return dp;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T>\nstd::vector<std::vector<T>>  //\ntraveling_salesman_problem(Graph<T> &G,\
    \ const T INF) {\n    int N = (int)G.size();\n    int N2 = 1 << N;\n\n    std::vector<std::vector<T>>\
    \ dist(N, std::vector<T>(N, INF));\n    for (int i = 0; i < N; i++) dist[i][i]\
    \ = T(0);\n    for (int i = 0; i < N; i++) {\n        for (auto &&e : G[i]) {\n\
    \            dist[e.from][e.to] = std::min(dist[e.from][e.to], e.cost);\n    \
    \    }\n    }\n\n    std::vector<std::vector<T>> dp(N2, std::vector<T>(N, INF));\n\
    \    dp[0][0] = 0;\n    for (int s = 0; s < (1 << N); s++) {\n        for (int\
    \ v = 0; v < N; v++) {\n            if (s >> v & 1) continue;\n            for\
    \ (int u = 0; u < N; u++) {\n                if (u == v) continue;\n         \
    \       dp[s | (1 << v)][v] = std::min(dp[s | (1 << v)][v], dp[s][u] + dist[u][v]);\n\
    \            }\n        }\n    }\n    return dp;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: dp/traveling_salesman_problem.hpp
  requiredBy: []
  timestamp: '2023-02-10 01:10:41+09:00'
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
