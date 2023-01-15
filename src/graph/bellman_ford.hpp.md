---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: src/graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_1_b.test.cpp
    title: verify/aoj_grl/aoj_grl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/bellman_ford.md
    document_title: "Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\
      \u30C9\u6CD5)"
    links: []
  bundledCode: "#line 2 \"src/graph/bellman_ford.hpp\"\n\n#line 2 \"src/graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"src/graph/bellman_ford.hpp\"\n\ntemplate <class T, class Graph>\nstd::tuple<std::vector<T>,\
    \ std::vector<int>, std::vector<int>>  //\nbellman_ford(Graph &G, std::vector<int>\
    \ &s, const T INF) {\n    int N = (int)G.size();\n    std::vector<T> dist(N, INF);\n\
    \    std::vector<int> par(N, -1), root(N, -1);\n\n    for (auto &v : s) {\n  \
    \      dist[v] = 0;\n        root[v] = v;\n    }\n    int loop_count = 0;\n\n\
    \    while (true) {\n        loop_count++;\n        bool update = false;\n   \
    \     for (int cur = 0; cur < N; cur++) {\n            if (dist[cur] == INF) continue;\n\
    \            for (auto &e : G[cur]) {\n                T nd = std::max(-INF, dist[cur]\
    \ + e.cost);\n                if (dist[e.to] > nd) {\n                    par[e.to]\
    \ = cur;\n                    root[e.to] = root[cur];\n                    update\
    \ = true;\n                    if (loop_count >= N) nd = -INF;\n             \
    \       dist[e.to] = nd;\n                }\n            }\n        }\n      \
    \  if (!update) break;\n    }\n    return {dist, par, root};\n}\n\n/**\n * @brief\
    \ Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\
    )\n * @docs docs/graph/bellman_ford.md\n */\n"
  code: "#pragma once\n\n#include \"src/graph/graph_template.hpp\"\n\ntemplate <class\
    \ T, class Graph>\nstd::tuple<std::vector<T>, std::vector<int>, std::vector<int>>\
    \  //\nbellman_ford(Graph &G, std::vector<int> &s, const T INF) {\n    int N =\
    \ (int)G.size();\n    std::vector<T> dist(N, INF);\n    std::vector<int> par(N,\
    \ -1), root(N, -1);\n\n    for (auto &v : s) {\n        dist[v] = 0;\n       \
    \ root[v] = v;\n    }\n    int loop_count = 0;\n\n    while (true) {\n       \
    \ loop_count++;\n        bool update = false;\n        for (int cur = 0; cur <\
    \ N; cur++) {\n            if (dist[cur] == INF) continue;\n            for (auto\
    \ &e : G[cur]) {\n                T nd = std::max(-INF, dist[cur] + e.cost);\n\
    \                if (dist[e.to] > nd) {\n                    par[e.to] = cur;\n\
    \                    root[e.to] = root[cur];\n                    update = true;\n\
    \                    if (loop_count >= N) nd = -INF;\n                    dist[e.to]\
    \ = nd;\n                }\n            }\n        }\n        if (!update) break;\n\
    \    }\n    return {dist, par, root};\n}\n\n/**\n * @brief Bellman-Ford algorithm\
    \ (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5)\n * @docs docs/graph/bellman_ford.md\n\
    \ */\n"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2022-11-16 19:50:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_grl/aoj_grl_1_b.test.cpp
documentation_of: src/graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/src/graph/bellman_ford.hpp
- /library/src/graph/bellman_ford.hpp.html
title: "Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\
  )"
---
# Bellman-Ford algorithm (ベルマンフォード法)

## 概要

- 到達できない場合は `INF`
- 負閉路を使って小さくできる場合は `-INF`
- 多始点スタートに対応
- `s` に始点となる頂点を入れて、`auto [dist, par, root] = bellman_ford(G, s, INF);` で距離、親、始点が各頂点について得られる