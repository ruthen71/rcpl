---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: src/graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
    title: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/dijkstra.md
    document_title: "Dijkstra's algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
      )"
    links: []
  bundledCode: "#line 2 \"src/graph/dijkstra.hpp\"\n\n#line 2 \"src/graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"src/graph/dijkstra.hpp\"\n\ntemplate <class T, class Graph>\nstd::tuple<std::vector<T>,\
    \ std::vector<int>, std::vector<int>>  //\ndijkstra(Graph &G, std::vector<int>\
    \ &s, const T INF) {\n    int N = (int)G.size();\n    std::vector<T> dist(N, INF);\n\
    \    std::vector<int> par(N, -1), root(N, -1);\n\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;\n\
    \n    for (auto &v : s) {\n        dist[v] = 0;\n        root[v] = v;\n      \
    \  que.emplace(T(0), v);\n    }\n\n    while (!que.empty()) {\n        auto [d,\
    \ v] = que.top();\n        que.pop();\n        if (dist[v] != d) continue;  //\
    \ dist[v] < d\n        for (auto &e : G[v]) {\n            if (dist[e.to] > d\
    \ + e.cost) {\n                dist[e.to] = d + e.cost;\n                root[e.to]\
    \ = root[v];\n                par[e.to] = v;\n                que.emplace(dist[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return {dist, par, root};\n}\n\n\
    /**\n * @brief Dijkstra's algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
    )\n * @docs docs/graph/dijkstra.md\n */\n"
  code: "#pragma once\n\n#include \"src/graph/graph_template.hpp\"\n\ntemplate <class\
    \ T, class Graph>\nstd::tuple<std::vector<T>, std::vector<int>, std::vector<int>>\
    \  //\ndijkstra(Graph &G, std::vector<int> &s, const T INF) {\n    int N = (int)G.size();\n\
    \    std::vector<T> dist(N, INF);\n    std::vector<int> par(N, -1), root(N, -1);\n\
    \n    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T,\
    \ int>>> que;\n\n    for (auto &v : s) {\n        dist[v] = 0;\n        root[v]\
    \ = v;\n        que.emplace(T(0), v);\n    }\n\n    while (!que.empty()) {\n \
    \       auto [d, v] = que.top();\n        que.pop();\n        if (dist[v] != d)\
    \ continue;  // dist[v] < d\n        for (auto &e : G[v]) {\n            if (dist[e.to]\
    \ > d + e.cost) {\n                dist[e.to] = d + e.cost;\n                root[e.to]\
    \ = root[v];\n                par[e.to] = v;\n                que.emplace(dist[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return {dist, par, root};\n}\n\n\
    /**\n * @brief Dijkstra's algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
    )\n * @docs docs/graph/dijkstra.md\n */\n"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-11-16 19:50:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: "Dijkstra's algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
---
# Dijkstra's algorithm (ダイクストラ法)

## 概要

- 多始点スタートに対応
- `s` に始点となる頂点を入れて、`auto [dist, par, root] = dijkstra(G, s, INF);` で距離、親、始点が各頂点について得られる