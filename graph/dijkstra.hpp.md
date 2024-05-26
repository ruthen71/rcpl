---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
    title: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\ntemplate <class T> struct Edge {\n    int from, to;\n \
    \   T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int to,\
    \ T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n    \
    \    // output format: \"{ id : from -> to, cost }\"\n        return os << \"\
    { \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \"\
    \ }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    graph/dijkstra.hpp\"\n\ntemplate <class T>\nstd::tuple<std::vector<T>, std::vector<int>,\
    \ std::vector<int>>  //\ndijkstra(Graph<T> &g, std::vector<int> &s, const T INF)\
    \ {\n    const int n = (int)(g.size());\n    std::vector<T> dist(n, INF);\n  \
    \  std::vector<int> par(n, -1), root(n, -1);\n\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;\n\
    \n    for (auto &v : s) {\n        dist[v] = 0;\n        root[v] = v;\n      \
    \  que.emplace(T(0), v);\n    }\n\n    while (!que.empty()) {\n        auto [d,\
    \ v] = que.top();\n        que.pop();\n        if (dist[v] != d) continue;  //\
    \ dist[v] < d\n        for (auto &e : g[v]) {\n            if (dist[e.to] > d\
    \ + e.cost) {\n                dist[e.to] = d + e.cost;\n                root[e.to]\
    \ = root[v];\n                par[e.to] = v;\n                que.emplace(dist[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return {dist, par, root};\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T>\nstd::tuple<std::vector<T>, std::vector<int>, std::vector<int>>  //\ndijkstra(Graph<T>\
    \ &g, std::vector<int> &s, const T INF) {\n    const int n = (int)(g.size());\n\
    \    std::vector<T> dist(n, INF);\n    std::vector<int> par(n, -1), root(n, -1);\n\
    \n    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T,\
    \ int>>> que;\n\n    for (auto &v : s) {\n        dist[v] = 0;\n        root[v]\
    \ = v;\n        que.emplace(T(0), v);\n    }\n\n    while (!que.empty()) {\n \
    \       auto [d, v] = que.top();\n        que.pop();\n        if (dist[v] != d)\
    \ continue;  // dist[v] < d\n        for (auto &e : g[v]) {\n            if (dist[e.to]\
    \ > d + e.cost) {\n                dist[e.to] = d + e.cost;\n                root[e.to]\
    \ = root[v];\n                par[e.to] = v;\n                que.emplace(dist[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return {dist, par, root};\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-05-26 20:33:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: "Dijkstra's algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
---

- 多始点スタートに対応
- `s` に始点となる頂点を入れて、`auto [dist, par, root] = dijkstra(G, s, INF);` で距離、親、始点が各頂点について得られる
