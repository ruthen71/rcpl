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
  bundledCode: "#line 2 \"graph/bfs01.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"graph/bfs01.hpp\"\n\ntemplate <class T, class Graph>\nstd::tuple<std::vector<T>,\
    \ std::vector<int>, std::vector<int>>  //\nbfs01(Graph &G, std::vector<int> &s,\
    \ const T INF) {\n    int N = (int)G.size();\n    std::vector<T> dist(N, INF);\n\
    \    std::vector<int> par(N, -1), root(N, -1);\n\n    std::deque<int> que;\n\n\
    \    for (auto &v : s) {\n        dist[v] = 0;\n        root[v] = v;\n       \
    \ que.push_back(v);\n    }\n\n    while (!que.empty()) {\n        auto v = que.front();\n\
    \        que.pop_front();\n        for (auto &e : G[v]) {\n            if (dist[e.to]\
    \ > dist[v] + e.cost) {\n                dist[e.to] = dist[v] + e.cost;\n    \
    \            root[e.to] = root[v];\n                par[e.to] = v;\n         \
    \       if (e.cost != 0) {\n                    que.push_back(e.to);\n       \
    \         } else {\n                    que.push_front(e.to);\n              \
    \  }\n            }\n        }\n    }\n    return {dist, par, root};\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T, class Graph>\nstd::tuple<std::vector<T>, std::vector<int>, std::vector<int>>\
    \  //\nbfs01(Graph &G, std::vector<int> &s, const T INF) {\n    int N = (int)G.size();\n\
    \    std::vector<T> dist(N, INF);\n    std::vector<int> par(N, -1), root(N, -1);\n\
    \n    std::deque<int> que;\n\n    for (auto &v : s) {\n        dist[v] = 0;\n\
    \        root[v] = v;\n        que.push_back(v);\n    }\n\n    while (!que.empty())\
    \ {\n        auto v = que.front();\n        que.pop_front();\n        for (auto\
    \ &e : G[v]) {\n            if (dist[e.to] > dist[v] + e.cost) {\n           \
    \     dist[e.to] = dist[v] + e.cost;\n                root[e.to] = root[v];\n\
    \                par[e.to] = v;\n                if (e.cost != 0) {\n        \
    \            que.push_back(e.to);\n                } else {\n                \
    \    que.push_front(e.to);\n                }\n            }\n        }\n    }\n\
    \    return {dist, par, root};\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/bfs01.hpp
  requiredBy: []
  timestamp: '2023-02-06 19:40:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bfs01.hpp
layout: document
title: 01-BFS
---
