---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/dp/traveling_salesman_problem.hpp
    title: "Traveling Salesman Problem (\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
      \u30F3\u554F\u984C)"
  - icon: ':heavy_check_mark:'
    path: src/graph/bellman_ford.hpp
    title: "Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\
      \u6CD5)"
  - icon: ':warning:'
    path: src/graph/bfs01.hpp
    title: 01-BFS
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: "Dijkstra's algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: src/graph/get_edges.hpp
    title: src/graph/get_edges.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/kruskal.hpp
    title: "Kruskal's algorithm (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: src/graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: src/graph/read_graph.hpp
    title: src/graph/read_graph.hpp
  - icon: ':warning:'
    path: src/graph/topological_sort.hpp
    title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      )"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree_diameter.hpp
    title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
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
  bundledCode: "#line 2 \"src/graph/graph_template.hpp\"\n\ntemplate <class T> struct\
    \ edge {\n    int from, to;\n    T cost;\n    int id;\n\n    edge() = default;\n\
    \    edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost),\
    \ id(id) {}\n\n    friend std::ostream &operator<<(std::ostream &os, const edge<T>\
    \ &e) {\n        // { id : from -> to, cost }\n        return os << \"{ \" <<\
    \ e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\"\
    ;\n    }\n};\n\ntemplate <class T> using edges = std::vector<edge<T>>;\ntemplate\
    \ <class T> using graph = std::vector<std::vector<edge<T>>>;\n"
  code: "#pragma once\n\ntemplate <class T> struct edge {\n    int from, to;\n   \
    \ T cost;\n    int id;\n\n    edge() = default;\n    edge(int from, int to, T\
    \ cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const edge<T> &e) {\n        // {\
    \ id : from -> to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from\
    \ << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class\
    \ T> using edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/graph_template.hpp
  requiredBy:
  - src/graph/bfs01.hpp
  - src/graph/dijkstra.hpp
  - src/graph/get_edges.hpp
  - src/graph/bellman_ford.hpp
  - src/graph/lowest_common_ancestor.hpp
  - src/graph/topological_sort.hpp
  - src/graph/kruskal.hpp
  - src/graph/tree_diameter.hpp
  - src/graph/read_graph.hpp
  - src/dp/traveling_salesman_problem.hpp
  timestamp: '2022-11-16 19:50:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dpl/aoj_dpl_2_a.test.cpp
  - verify/lc_tree/lc_tree_diameter.test.cpp
  - verify/lc_tree/lc_lowest_common_ancestor.test.cpp
  - verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  - verify/aoj_grl/aoj_grl_1_b.test.cpp
  - verify/aoj_grl/aoj_grl_2_a.test.cpp
documentation_of: src/graph/graph_template.hpp
layout: document
redirect_from:
- /library/src/graph/graph_template.hpp
- /library/src/graph/graph_template.hpp.html
title: src/graph/graph_template.hpp
---
