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
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_1_b.test.cpp
    title: verify/aoj_grl/aoj_grl_1_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_2_a.test.cpp
    title: verify/aoj_grl/aoj_grl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
    title: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_tree/lc_tree_diameter.test.cpp
    title: verify/lc_tree/lc_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/read_graph.hpp\"\n\n#line 2 \"src/graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"src/graph/read_graph.hpp\"\n\ntemplate <class T> graph<T> read_graph(int\
    \ N, int M, const bool weight = false, const bool directed = false, const int\
    \ offset = 1) {\n    graph<T> G(N);\n    for (int i = 0; i < M; i++) {\n     \
    \   int a, b;\n        std::cin >> a >> b;\n        a -= offset, b -= offset;\n\
    \        if (weight) {\n            T c;\n            std::cin >> c;\n       \
    \     if (!directed) G[b].push_back(edge(b, a, c, i));\n            G[a].push_back(edge(a,\
    \ b, c, i));\n        } else {\n            // c = 1\n            if (!directed)\
    \ G[b].push_back(edge(b, a, T(1), i));\n            G[a].push_back(edge(a, b,\
    \ T(1), i));\n        }\n    }\n    return G;\n}\n"
  code: "#pragma once\n\n#include \"src/graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> graph<T> read_graph(int N, int M, const bool weight = false, const bool directed\
    \ = false, const int offset = 1) {\n    graph<T> G(N);\n    for (int i = 0; i\
    \ < M; i++) {\n        int a, b;\n        std::cin >> a >> b;\n        a -= offset,\
    \ b -= offset;\n        if (weight) {\n            T c;\n            std::cin\
    \ >> c;\n            if (!directed) G[b].push_back(edge(b, a, c, i));\n      \
    \      G[a].push_back(edge(a, b, c, i));\n        } else {\n            // c =\
    \ 1\n            if (!directed) G[b].push_back(edge(b, a, T(1), i));\n       \
    \     G[a].push_back(edge(a, b, T(1), i));\n        }\n    }\n    return G;\n}"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/read_graph.hpp
  requiredBy: []
  timestamp: '2022-11-16 19:50:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  - verify/aoj_grl/aoj_grl_2_a.test.cpp
  - verify/aoj_grl/aoj_grl_1_b.test.cpp
  - verify/lc_tree/lc_tree_diameter.test.cpp
  - verify/aoj_dpl/aoj_dpl_2_a.test.cpp
documentation_of: src/graph/read_graph.hpp
layout: document
redirect_from:
- /library/src/graph/read_graph.hpp
- /library/src/graph/read_graph.hpp.html
title: src/graph/read_graph.hpp
---
