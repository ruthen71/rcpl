---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/zero_one_bfs.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\ntemplate <class T> struct Edge {\n    int from, to;\n \
    \   T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int to,\
    \ T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n    \
    \    // output format: \"{ id : from -> to, cost }\"\n        return os << \"\
    { \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \"\
    \ }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    graph/zero_one_bfs.hpp\"\n\ntemplate <class T>\nstd::tuple<std::vector<T>, std::vector<int>,\
    \ std::vector<int>>  //\nzero_one_bfs(Graph<T> &g, std::vector<int> &s, const\
    \ T INF) {\n    const int n = (int)(g.size());\n    std::vector<T> dist(n, INF);\n\
    \    std::vector<int> par(n, -1), root(n, -1);\n\n    std::deque<int> que;\n\n\
    \    for (auto &v : s) {\n        dist[v] = 0;\n        root[v] = v;\n       \
    \ que.push_back(v);\n    }\n\n    while (!que.empty()) {\n        auto v = que.front();\n\
    \        que.pop_front();\n        for (auto &e : g[v]) {\n            if (dist[e.to]\
    \ > dist[v] + e.cost) {\n                dist[e.to] = dist[v] + e.cost;\n    \
    \            root[e.to] = root[v];\n                par[e.to] = v;\n         \
    \       if (e.cost != 0) {\n                    que.push_back(e.to);\n       \
    \         } else {\n                    que.push_front(e.to);\n              \
    \  }\n            }\n        }\n    }\n    return {dist, par, root};\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T>\nstd::tuple<std::vector<T>, std::vector<int>, std::vector<int>>  //\nzero_one_bfs(Graph<T>\
    \ &g, std::vector<int> &s, const T INF) {\n    const int n = (int)(g.size());\n\
    \    std::vector<T> dist(n, INF);\n    std::vector<int> par(n, -1), root(n, -1);\n\
    \n    std::deque<int> que;\n\n    for (auto &v : s) {\n        dist[v] = 0;\n\
    \        root[v] = v;\n        que.push_back(v);\n    }\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop_front();\n        for (auto\
    \ &e : g[v]) {\n            if (dist[e.to] > dist[v] + e.cost) {\n           \
    \     dist[e.to] = dist[v] + e.cost;\n                root[e.to] = root[v];\n\
    \                par[e.to] = v;\n                if (e.cost != 0) {\n        \
    \            que.push_back(e.to);\n                } else {\n                \
    \    que.push_front(e.to);\n                }\n            }\n        }\n    }\n\
    \    return {dist, par, root};\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/zero_one_bfs.hpp
  requiredBy: []
  timestamp: '2024-05-26 20:33:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/zero_one_bfs.hpp
layout: document
title: 01-BFS
---