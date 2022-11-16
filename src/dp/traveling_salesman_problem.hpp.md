---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: src/graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
    title: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dp/traveling_salesman_problem.md
    document_title: "Traveling Salesman Problem (\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\
      \u30DE\u30F3\u554F\u984C)"
    links: []
  bundledCode: "#line 2 \"src/dp/traveling_salesman_problem.hpp\"\n\n#line 2 \"src/graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"src/dp/traveling_salesman_problem.hpp\"\n\ntemplate <class T, class\
    \ Graph>\nstd::vector<std::vector<T>>  //\ntraveling_salesman_problem(Graph &G,\
    \ const T INF) {\n    int N = (int)G.size();\n    int N2 = 1 << N;\n\n    std::vector<std::vector<T>>\
    \ dist(N, std::vector<T>(N, INF));\n    for (int i = 0; i < N; i++) dist[i][i]\
    \ = T(0);\n    for (int i = 0; i < N; i++) {\n        for (auto &&e : G[i]) {\n\
    \            dist[e.from][e.to] = std::min(dist[e.from][e.to], e.cost);\n    \
    \    }\n    }\n\n    std::vector<std::vector<T>> dp(N2, std::vector<T>(N, INF));\n\
    \    dp[0][0] = 0;\n    for (int s = 0; s < (1 << N); s++) {\n        for (int\
    \ v = 0; v < N; v++) {\n            if (s >> v & 1) continue;\n            for\
    \ (int u = 0; u < N; u++) {\n                if (u == v) continue;\n         \
    \       dp[s | (1 << v)][v] = std::min(dp[s | (1 << v)][v], dp[s][u] + dist[u][v]);\n\
    \            }\n        }\n    }\n    return dp;\n}\n\n/**\n * @brief Traveling\
    \ Salesman Problem (\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C\
    )\n * @docs docs/dp/traveling_salesman_problem.md\n */\n"
  code: "#pragma once\n\n#include \"src/graph/graph_template.hpp\"\n\ntemplate <class\
    \ T, class Graph>\nstd::vector<std::vector<T>>  //\ntraveling_salesman_problem(Graph\
    \ &G, const T INF) {\n    int N = (int)G.size();\n    int N2 = 1 << N;\n\n   \
    \ std::vector<std::vector<T>> dist(N, std::vector<T>(N, INF));\n    for (int i\
    \ = 0; i < N; i++) dist[i][i] = T(0);\n    for (int i = 0; i < N; i++) {\n   \
    \     for (auto &&e : G[i]) {\n            dist[e.from][e.to] = std::min(dist[e.from][e.to],\
    \ e.cost);\n        }\n    }\n\n    std::vector<std::vector<T>> dp(N2, std::vector<T>(N,\
    \ INF));\n    dp[0][0] = 0;\n    for (int s = 0; s < (1 << N); s++) {\n      \
    \  for (int v = 0; v < N; v++) {\n            if (s >> v & 1) continue;\n    \
    \        for (int u = 0; u < N; u++) {\n                if (u == v) continue;\n\
    \                dp[s | (1 << v)][v] = std::min(dp[s | (1 << v)][v], dp[s][u]\
    \ + dist[u][v]);\n            }\n        }\n    }\n    return dp;\n}\n\n/**\n\
    \ * @brief Traveling Salesman Problem (\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
    \u30F3\u554F\u984C)\n * @docs docs/dp/traveling_salesman_problem.md\n */"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/dp/traveling_salesman_problem.hpp
  requiredBy: []
  timestamp: '2022-11-16 20:27:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dpl/aoj_dpl_2_a.test.cpp
documentation_of: src/dp/traveling_salesman_problem.hpp
layout: document
redirect_from:
- /library/src/dp/traveling_salesman_problem.hpp
- /library/src/dp/traveling_salesman_problem.hpp.html
title: "Traveling Salesman Problem (\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\
  \u554F\u984C)"
---
- 初期化 (TSP = 最短ハミルトン閉路問題の場合)
    - TSP は閉路なのでどこを始点にしても良い
    - 始点を `s` とすると、「まだどこにも行ってないけど `s` にいる」ので `dp[0][s] = 0`
- 初期化 (最短ハミルトン路問題の場合)
    - 始点を `s` とすると、「 `s` は訪問済みと考えて良い」ので `dp[1 << s][s] = 0`
