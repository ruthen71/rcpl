---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: dp/traveling_salesman_problem.hpp
    title: "Traveling Salesman Problem (\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
      \u30F3\u554F\u984C)"
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: "Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\
      \u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "Dijkstra's algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  - icon: ':warning:'
    path: graph/euler_tour.hpp
    title: "Euler Tour (\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
  - icon: ':heavy_check_mark:'
    path: graph/get_edges.hpp
    title: graph/get_edges.hpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal's algorithm (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: graph/read_graph.hpp
    title: graph/read_graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_component.hpp
    title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206)"
  - icon: ':warning:'
    path: graph/topological_sort.hpp
    title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      )"
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
  - icon: ':warning:'
    path: graph/zero_one_bfs.hpp
    title: 01-BFS
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
    path: verify/lc_graph/lc_scc.test.cpp
    title: verify/lc_graph/lc_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
    title: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_tree/lc_lowest_common_ancestor.test.cpp
    title: verify/lc_tree/lc_lowest_common_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_tree/lc_tree_diameter.test.cpp
    title: verify/lc_tree/lc_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph_template.hpp\"\n\ntemplate <class T> struct\
    \ Edge {\n    int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n\
    \    Edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost),\
    \ id(id) {}\n\n    friend std::ostream &operator<<(std::ostream &os, const Edge<T>\
    \ &e) {\n        // output format: \"{ id : from -> to, cost }\"\n        return\
    \ os << \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n"
  code: "#pragma once\n\ntemplate <class T> struct Edge {\n    int from, to;\n   \
    \ T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int to, T\
    \ cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n        // output\
    \ format: \"{ id : from -> to, cost }\"\n        return os << \"{ \" << e.id <<\
    \ \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n\
    };\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\ntemplate <class\
    \ T> using Graph = std::vector<std::vector<Edge<T>>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_template.hpp
  requiredBy:
  - dp/traveling_salesman_problem.hpp
  - graph/lowest_common_ancestor.hpp
  - graph/read_graph.hpp
  - graph/euler_tour.hpp
  - graph/zero_one_bfs.hpp
  - graph/topological_sort.hpp
  - graph/strongly_connected_component.hpp
  - graph/get_edges.hpp
  - graph/dijkstra.hpp
  - graph/tree_diameter.hpp
  - graph/bellman_ford.hpp
  - graph/kruskal.hpp
  timestamp: '2023-02-10 01:10:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  - verify/lc_graph/lc_scc.test.cpp
  - verify/lc_tree/lc_lowest_common_ancestor.test.cpp
  - verify/lc_tree/lc_tree_diameter.test.cpp
  - verify/aoj_grl/aoj_grl_2_a.test.cpp
  - verify/aoj_grl/aoj_grl_1_b.test.cpp
  - verify/aoj_dpl/aoj_dpl_2_a.test.cpp
documentation_of: graph/graph_template.hpp
layout: document
redirect_from:
- /library/graph/graph_template.hpp
- /library/graph/graph_template.hpp.html
title: graph/graph_template.hpp
---
