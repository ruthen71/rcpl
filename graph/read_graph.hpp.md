---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/graph/auxiliary_tree.test.cpp
    title: verify/graph/auxiliary_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/bellman_ford.test.cpp
    title: verify/graph/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/dijkstra_1.test.cpp
    title: verify/graph/dijkstra_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/dijkstra_2.test.cpp
    title: verify/graph/dijkstra_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/euler_tour.test.cpp
    title: verify/graph/euler_tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_1.test.cpp
    title: verify/graph/heavy_light_decomposition_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_2.test.cpp
    title: verify/graph/heavy_light_decomposition_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_3.test.cpp
    title: verify/graph/heavy_light_decomposition_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/kruskal.test.cpp
    title: verify/graph/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/low_link_1.test.cpp
    title: verify/graph/low_link_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/low_link_2.test.cpp
    title: verify/graph/low_link_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/lowest_common_ancestor_1.test.cpp
    title: verify/graph/lowest_common_ancestor_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/lowest_common_ancestor_2.test.cpp
    title: verify/graph/lowest_common_ancestor_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/minimum_steiner_tree.test.cpp
    title: verify/graph/minimum_steiner_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/strongly_connected_component_1.test.cpp
    title: verify/graph/strongly_connected_component_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/strongly_connected_component_2.test.cpp
    title: verify/graph/strongly_connected_component_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/topological_sort_1.test.cpp
    title: verify/graph/topological_sort_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/topological_sort_2.test.cpp
    title: verify/graph/topological_sort_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/traveling_salesman_problem.test.cpp
    title: verify/graph/traveling_salesman_problem.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter_1.test.cpp
    title: verify/graph/tree_diameter_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter_2.test.cpp
    title: verify/graph/tree_diameter_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/warshall_floyd.test.cpp
    title: verify/graph/warshall_floyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/zero_one_bfs.test.cpp
    title: verify/graph/zero_one_bfs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n\ntemplate <class T> struct Edge {\n\
    \    int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const\
    \ int from, const int to, const T cost = T(1), const int id = -1) : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend bool operator<(const Edge<T>& a,\
    \ const Edge<T>& b) { return a.cost < b.cost; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Edge<T>& e) {\n        // output format: {id: cost(from, to) = cost}\n\
    \        return os << \"{\" << e.id << \": cost(\" << e.from << \", \" << e.to\
    \ << \") = \" << e.cost << \"}\";\n    }\n};\ntemplate <class T> using Edges =\
    \ std::vector<Edge<T>>;\n\ntemplate <class T> struct Graph {\n    struct EdgeIterators\
    \ {\n       public:\n        using Iterator = typename std::vector<Edge<T>>::iterator;\n\
    \        EdgeIterators() = default;\n        EdgeIterators(const Iterator& begit,\
    \ const Iterator& endit) : begit(begit), endit(endit) {}\n        Iterator begin()\
    \ const { return begit; }\n        Iterator end() const { return endit; }\n  \
    \      size_t size() const { return std::distance(begit, endit); }\n        Edge<T>&\
    \ operator[](int i) const { return begit[i]; }\n\n       private:\n        Iterator\
    \ begit, endit;\n    };\n\n    int n, m;\n    bool is_build, is_directed;\n  \
    \  std::vector<Edge<T>> edges;\n\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\
    \u7528\n    std::vector<int> start;\n    std::vector<Edge<T>> csr_edges;\n\n \
    \   Graph() = default;\n    Graph(const int n, const bool directed = false) :\
    \ n(n), m(0), is_build(false), is_directed(directed), start(n + 1, 0) {}\n\n \
    \   // \u8FBA\u3092\u8FFD\u52A0\u3057, \u305D\u306E\u8FBA\u304C\u4F55\u756A\u76EE\
    \u306B\u8FFD\u52A0\u3055\u308C\u305F\u304B\u3092\u8FD4\u3059\n    int add_edge(const\
    \ int from, const int to, const T cost = T(1), int id = -1) {\n        assert(!is_build);\n\
    \        assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n\
    \        if (id == -1) id = m;\n        edges.emplace_back(from, to, cost, id);\n\
    \        return m++;\n    }\n\n    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\
    \u3092\u69CB\u7BC9\n    void build() {\n        assert(!is_build);\n        for\
    \ (auto&& e : edges) {\n            start[e.from + 1]++;\n            if (!is_directed)\
    \ start[e.to + 1]++;\n        }\n        for (int v = 0; v < n; v++) start[v +\
    \ 1] += start[v];\n        auto counter = start;\n        csr_edges.resize(start.back()\
    \ + 1);\n        for (auto&& e : edges) {\n            csr_edges[counter[e.from]++]\
    \ = e;\n            if (!is_directed) csr_edges[counter[e.to]++] = Edge(e.to,\
    \ e.from, e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
    \ operator[](int i) {\n        if (!is_build) build();\n        return EdgeIterators(csr_edges.begin()\
    \ + start[i], csr_edges.begin() + start[i + 1]);\n    }\n\n    size_t size() const\
    \ { return (size_t)(n); }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, Graph<T>& g) {\n        os << \"[\";\n        for (int i = 0; i < (int)(g.size());\
    \ i++) {\n            os << \"[\";\n            for (int j = 0; j < (int)(g[i].size());\
    \ j++) {\n                os << g[i][j];\n                if (j + 1 != (int)(g[i].size()))\
    \ os << \", \";\n            }\n            os << \"]\";\n            if (i +\
    \ 1 != (int)(g.size())) os << \", \";\n        }\n        return os << \"]\";\n\
    \    }\n};\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate <class T> Graph<T> read_graph(const\
    \ int n, const int m, const bool weight = false, const bool directed = false,\
    \ const int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int i = 0; i\
    \ < m; i++) {\n        int a, b;\n        std::cin >> a >> b;\n        a -= offset,\
    \ b -= offset;\n        T c = 1;\n        if (weight) std::cin >> c;\n       \
    \ g.add_edge(a, b, c);\n    }\n    g.build();\n    return g;\n}\n\ntemplate <class\
    \ T> Graph<T> read_parent(const int n, const bool weight = false, const bool directed\
    \ = false, const int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int\
    \ i = 1; i < n; i++) {\n        int p;\n        std::cin >> p;\n        p -= offset;\n\
    \        T c = 1;\n        if (weight) std::cin >> c;\n        g.add_edge(p, i,\
    \ c);\n    }\n    g.build();\n    return g;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> Graph<T> read_graph(const int n, const int m, const bool weight = false,\
    \ const bool directed = false, const int offset = 1) {\n    Graph<T> g(n, directed);\n\
    \    for (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        a -= offset, b -= offset;\n        T c = 1;\n        if (weight)\
    \ std::cin >> c;\n        g.add_edge(a, b, c);\n    }\n    g.build();\n    return\
    \ g;\n}\n\ntemplate <class T> Graph<T> read_parent(const int n, const bool weight\
    \ = false, const bool directed = false, const int offset = 1) {\n    Graph<T>\
    \ g(n, directed);\n    for (int i = 1; i < n; i++) {\n        int p;\n       \
    \ std::cin >> p;\n        p -= offset;\n        T c = 1;\n        if (weight)\
    \ std::cin >> c;\n        g.add_edge(p, i, c);\n    }\n    g.build();\n    return\
    \ g;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/read_graph.hpp
  requiredBy: []
  timestamp: '2024-07-31 21:19:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/graph/strongly_connected_component_2.test.cpp
  - verify/graph/topological_sort_1.test.cpp
  - verify/graph/bellman_ford.test.cpp
  - verify/graph/low_link_2.test.cpp
  - verify/graph/lowest_common_ancestor_2.test.cpp
  - verify/graph/euler_tour.test.cpp
  - verify/graph/kruskal.test.cpp
  - verify/graph/warshall_floyd.test.cpp
  - verify/graph/tree_diameter_2.test.cpp
  - verify/graph/heavy_light_decomposition_1.test.cpp
  - verify/graph/dijkstra_1.test.cpp
  - verify/graph/low_link_1.test.cpp
  - verify/graph/traveling_salesman_problem.test.cpp
  - verify/graph/heavy_light_decomposition_3.test.cpp
  - verify/graph/auxiliary_tree.test.cpp
  - verify/graph/zero_one_bfs.test.cpp
  - verify/graph/heavy_light_decomposition_2.test.cpp
  - verify/graph/tree_diameter_1.test.cpp
  - verify/graph/dijkstra_2.test.cpp
  - verify/graph/minimum_steiner_tree.test.cpp
  - verify/graph/topological_sort_2.test.cpp
  - verify/graph/strongly_connected_component_1.test.cpp
  - verify/graph/lowest_common_ancestor_1.test.cpp
documentation_of: graph/read_graph.hpp
layout: document
title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
---

## 使い方

```cpp
auto g = read_graph<T>(n, m, true, true, 1);     // 重みあり, 有向グラフ
auto g = read_graph<T>(n, m, true, false, 1);    // 重みあり, 無向グラフ
auto g = read_graph<T>(n, m, false, true, 1);    // 重みなし, 有向グラフ
auto g = read_graph<T>(n, m, false, false, 1);   // 重みなし, 無向グラフ
```

## 参考文献
