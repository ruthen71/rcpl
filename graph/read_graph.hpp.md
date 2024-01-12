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
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_1_b.test.cpp
    title: verify/aoj_grl/aoj_grl_1_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_2_a.test.cpp
    title: verify/aoj_grl/aoj_grl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_3_a.test.cpp
    title: verify/aoj_grl/aoj_grl_3_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_graph/lc_scc.test.cpp
    title: verify/lc_graph/lc_scc.test.cpp
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
  bundledCode: "#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Edge<T> &e) {\n        // output format:\
    \ \"{ id : from -> to, cost }\"\n        return os << \"{ \" << e.id << \" : \"\
    \ << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\n\
    template <class T> using Edges = std::vector<Edge<T>>;\ntemplate <class T> using\
    \ Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"graph/read_graph.hpp\"\
    \n\ntemplate <class T> Graph<T> read_graph(int N, int M, const bool weight = false,\
    \ const bool directed = false, const int offset = 1) {\n    Graph<T> G(N);\n \
    \   for (int i = 0; i < M; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        a -= offset, b -= offset;\n        if (weight) {\n            T\
    \ c;\n            std::cin >> c;\n            if (!directed) G[b].push_back(Edge(b,\
    \ a, c, i));\n            G[a].push_back(Edge(a, b, c, i));\n        } else {\n\
    \            // c = 1\n            if (!directed) G[b].push_back(Edge(b, a, T(1),\
    \ i));\n            G[a].push_back(Edge(a, b, T(1), i));\n        }\n    }\n \
    \   return G;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> Graph<T> read_graph(int N, int M, const bool weight = false, const bool directed\
    \ = false, const int offset = 1) {\n    Graph<T> G(N);\n    for (int i = 0; i\
    \ < M; i++) {\n        int a, b;\n        std::cin >> a >> b;\n        a -= offset,\
    \ b -= offset;\n        if (weight) {\n            T c;\n            std::cin\
    \ >> c;\n            if (!directed) G[b].push_back(Edge(b, a, c, i));\n      \
    \      G[a].push_back(Edge(a, b, c, i));\n        } else {\n            // c =\
    \ 1\n            if (!directed) G[b].push_back(Edge(b, a, T(1), i));\n       \
    \     G[a].push_back(Edge(a, b, T(1), i));\n        }\n    }\n    return G;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/read_graph.hpp
  requiredBy: []
  timestamp: '2023-02-10 01:10:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_graph/lc_scc.test.cpp
  - verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  - verify/aoj_grl/aoj_grl_3_a.test.cpp
  - verify/aoj_grl/aoj_grl_1_b.test.cpp
  - verify/aoj_grl/aoj_grl_2_a.test.cpp
  - verify/aoj_dpl/aoj_dpl_2_a.test.cpp
  - verify/lc_tree/lc_tree_diameter.test.cpp
documentation_of: graph/read_graph.hpp
layout: document
redirect_from:
- /library/graph/read_graph.hpp
- /library/graph/read_graph.hpp.html
title: graph/read_graph.hpp
---
