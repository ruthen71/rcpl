---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/auxiliary_tree.hpp
    title: "Auxiliary Tree (\u865A\u6811)"
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
  - icon: ':x:'
    path: graph/kruskal.hpp
    title: "Kruskal's algorithm (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: "Low Link (\u95A2\u7BC0\u70B9\u30FB\u6A4B)"
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: graph/minimum_steiner_tree.hpp
    title: "Minimum Steiner Tree (\u6700\u5C0F\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\
      \u6728)"
  - icon: ':question:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':warning:'
    path: graph/shortest_path_tree.hpp
    title: "Shortest Path Tree (\u6700\u77ED\u7D4C\u8DEF\u6728)"
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_component.hpp
    title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206)"
  - icon: ':x:'
    path: graph/topological_sort.hpp
    title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      )"
  - icon: ':heavy_check_mark:'
    path: graph/traveling_salesman_problem.hpp
    title: "Traveling Salesman Problem (\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
      \u30F3\u554F\u984C)"
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
  - icon: ':heavy_check_mark:'
    path: graph/zero_one_bfs.hpp
    title: 01-BFS
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
    title: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/bellman_ford.test.cpp
    title: verify/graph/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/dijkstra.test.cpp
    title: verify/graph/dijkstra.test.cpp
  - icon: ':x:'
    path: verify/graph/kruskal.test.cpp
    title: verify/graph/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/low_link_1.test.cpp
    title: verify/graph/low_link_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/low_link_2.test.cpp
    title: verify/graph/low_link_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/lowest_common_ancestor.test.cpp
    title: verify/graph/lowest_common_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/minimum_steiner_tree.test.cpp
    title: verify/graph/minimum_steiner_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/strongly_connected_component.test.cpp
    title: verify/graph/strongly_connected_component.test.cpp
  - icon: ':x:'
    path: verify/graph/topological_sort.test.cpp
    title: verify/graph/topological_sort.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter.test.cpp
    title: verify/graph/tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/zero_one_bfs.test.cpp
    title: verify/graph/zero_one_bfs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph_template.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n\
    \    int id;\n\n    Edge() = default;\n    Edge(const int from, const int to,\
    \ const T cost = T(1), const int id = -1) : from(from), to(to), cost(cost), id(id)\
    \ {}\n\n    friend std::ostream& operator<<(std::ostream& os, const Edge<T>& e)\
    \ {\n        // output format: {id: cost(from, to) = cost}\n        return os\
    \ << \"{\" << e.id << \": cost(\" << e.from << \", \" << e.to << \") = \" << e.cost\
    \ << \"}\";\n    }\n};\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    \ntemplate <class T> struct Graph {\n    struct EdgeIterators {\n       public:\n\
    \        using Iterator = typename std::vector<Edge<T>>::iterator;\n        EdgeIterators()\
    \ = default;\n        EdgeIterators(const Iterator& begit, const Iterator& endit)\
    \ : begit(begit), endit(endit) {}\n        Iterator begin() const { return begit;\
    \ }\n        Iterator end() const { return endit; }\n        size_t size() const\
    \ { return std::distance(begit, endit); }\n        Edge<T>& operator[](int i)\
    \ const { return begit[i]; }\n\n       private:\n        Iterator begit, endit;\n\
    \    };\n\n    int n, m;\n    bool is_build, is_directed;\n    std::vector<Edge<T>>\
    \ edges;\n\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\u7528\n    std::vector<int>\
    \ start;\n    std::vector<Edge<T>> csr_edges;\n\n    Graph() = default;\n    Graph(const\
    \ int n, const bool directed = false) : n(n), m(0), is_build(false), is_directed(directed),\
    \ start(n + 1, 0) {}\n\n    // \u8FBA\u3092\u8FFD\u52A0\u3057, \u305D\u306E\u8FBA\
    \u304C\u4F55\u756A\u76EE\u306B\u8FFD\u52A0\u3055\u308C\u305F\u304B\u3092\u8FD4\
    \u3059\n    int add_edge(const int from, const int to, const T cost = T(1), int\
    \ id = -1) {\n        assert(!is_build);\n        assert(0 <= from and from <\
    \ n);\n        assert(0 <= to and to < n);\n        if (id == -1) id = m;\n  \
    \      edges.emplace_back(from, to, cost, id);\n        return m++;\n    }\n\n\
    \    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\n    void build()\
    \ {\n        assert(!is_build);\n        for (auto&& e : edges) {\n          \
    \  start[e.from + 1]++;\n            if (!is_directed) start[e.to + 1]++;\n  \
    \      }\n        for (int v = 0; v < n; v++) start[v + 1] += start[v];\n    \
    \    auto counter = start;\n        csr_edges.resize(start.back() + 1);\n    \
    \    for (auto&& e : edges) {\n            csr_edges[counter[e.from]++] = e;\n\
    \            if (!is_directed) csr_edges[counter[e.to]++] = Edge(e.to, e.from,\
    \ e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
    \ operator[](int i) {\n        if (!is_build) build();\n        return EdgeIterators(csr_edges.begin()\
    \ + start[i], csr_edges.begin() + start[i + 1]);\n    }\n\n    size_t size() const\
    \ { return (size_t)(n); }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, Graph<T>& g) {\n        os << \"[\";\n        for (int i = 0; i < g.size();\
    \ i++) {\n            os << \"[\";\n            for (int j = 0; j < g[i].size();\
    \ j++) {\n                os << g[i][j];\n                if (j + 1 != g[i].size())\
    \ os << \", \";\n            }\n            os << \"]\";\n            if (i +\
    \ 1 != g.size()) os << \", \";\n        }\n        return os << \"]\";\n    }\n\
    };\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\ntemplate <class\
    \ T> struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\n    Edge()\
    \ = default;\n    Edge(const int from, const int to, const T cost = T(1), const\
    \ int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Edge<T>& e) {\n        // output format:\
    \ {id: cost(from, to) = cost}\n        return os << \"{\" << e.id << \": cost(\"\
    \ << e.from << \", \" << e.to << \") = \" << e.cost << \"}\";\n    }\n};\ntemplate\
    \ <class T> using Edges = std::vector<Edge<T>>;\n\ntemplate <class T> struct Graph\
    \ {\n    struct EdgeIterators {\n       public:\n        using Iterator = typename\
    \ std::vector<Edge<T>>::iterator;\n        EdgeIterators() = default;\n      \
    \  EdgeIterators(const Iterator& begit, const Iterator& endit) : begit(begit),\
    \ endit(endit) {}\n        Iterator begin() const { return begit; }\n        Iterator\
    \ end() const { return endit; }\n        size_t size() const { return std::distance(begit,\
    \ endit); }\n        Edge<T>& operator[](int i) const { return begit[i]; }\n\n\
    \       private:\n        Iterator begit, endit;\n    };\n\n    int n, m;\n  \
    \  bool is_build, is_directed;\n    std::vector<Edge<T>> edges;\n\n    // CSR\
    \ (Compressed Row Storage) \u5F62\u5F0F\u7528\n    std::vector<int> start;\n \
    \   std::vector<Edge<T>> csr_edges;\n\n    Graph() = default;\n    Graph(const\
    \ int n, const bool directed = false) : n(n), m(0), is_build(false), is_directed(directed),\
    \ start(n + 1, 0) {}\n\n    // \u8FBA\u3092\u8FFD\u52A0\u3057, \u305D\u306E\u8FBA\
    \u304C\u4F55\u756A\u76EE\u306B\u8FFD\u52A0\u3055\u308C\u305F\u304B\u3092\u8FD4\
    \u3059\n    int add_edge(const int from, const int to, const T cost = T(1), int\
    \ id = -1) {\n        assert(!is_build);\n        assert(0 <= from and from <\
    \ n);\n        assert(0 <= to and to < n);\n        if (id == -1) id = m;\n  \
    \      edges.emplace_back(from, to, cost, id);\n        return m++;\n    }\n\n\
    \    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\n    void build()\
    \ {\n        assert(!is_build);\n        for (auto&& e : edges) {\n          \
    \  start[e.from + 1]++;\n            if (!is_directed) start[e.to + 1]++;\n  \
    \      }\n        for (int v = 0; v < n; v++) start[v + 1] += start[v];\n    \
    \    auto counter = start;\n        csr_edges.resize(start.back() + 1);\n    \
    \    for (auto&& e : edges) {\n            csr_edges[counter[e.from]++] = e;\n\
    \            if (!is_directed) csr_edges[counter[e.to]++] = Edge(e.to, e.from,\
    \ e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
    \ operator[](int i) {\n        if (!is_build) build();\n        return EdgeIterators(csr_edges.begin()\
    \ + start[i], csr_edges.begin() + start[i + 1]);\n    }\n\n    size_t size() const\
    \ { return (size_t)(n); }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, Graph<T>& g) {\n        os << \"[\";\n        for (int i = 0; i < g.size();\
    \ i++) {\n            os << \"[\";\n            for (int j = 0; j < g[i].size();\
    \ j++) {\n                os << g[i][j];\n                if (j + 1 != g[i].size())\
    \ os << \", \";\n            }\n            os << \"]\";\n            if (i +\
    \ 1 != g.size()) os << \", \";\n        }\n        return os << \"]\";\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_template.hpp
  requiredBy:
  - graph/euler_tour.hpp
  - graph/auxiliary_tree.hpp
  - graph/lowest_common_ancestor.hpp
  - graph/minimum_steiner_tree.hpp
  - graph/read_graph.hpp
  - graph/dijkstra.hpp
  - graph/kruskal.hpp
  - graph/shortest_path_tree.hpp
  - graph/strongly_connected_component.hpp
  - graph/topological_sort.hpp
  - graph/bellman_ford.hpp
  - graph/zero_one_bfs.hpp
  - graph/low_link.hpp
  - graph/traveling_salesman_problem.hpp
  - graph/tree_diameter.hpp
  timestamp: '2024-07-31 16:51:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/graph/bellman_ford.test.cpp
  - verify/graph/topological_sort.test.cpp
  - verify/graph/low_link_1.test.cpp
  - verify/graph/lowest_common_ancestor.test.cpp
  - verify/graph/kruskal.test.cpp
  - verify/graph/strongly_connected_component.test.cpp
  - verify/graph/minimum_steiner_tree.test.cpp
  - verify/graph/dijkstra.test.cpp
  - verify/graph/low_link_2.test.cpp
  - verify/graph/tree_diameter.test.cpp
  - verify/graph/zero_one_bfs.test.cpp
  - verify/aoj_dpl/aoj_dpl_2_a.test.cpp
documentation_of: graph/graph_template.hpp
layout: document
title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---

隣接リストを CSR (Compressed Row Storage) 形式で管理しているため定数倍が良い

## 使い方

`add_edge()` は辺が何番目に追加されたかを返す

```cpp
Graph<int> g(n, false); // 無向グラフ
Graph<int> g(n, true);  // 有向グラフ
for (int i = 0; i < m; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    int edge_id = g.add_edge(a, b, c);
}
g.build();
```

はじめて `g[v]` などを実行した際に自動的に `build()` を実行する

注意点
- `g[v]` などとした後に辺を追加することはできない (`build()` が走ってしまうため)
- 関数の引数に与えるときに `function(const Graph<T>& g)` とはできず, `function(Graph<T>& g)` とする必要がある
    - `g[v]` の中で `build()` が走る可能性があるため `const` にできない


## 参考文献
- [【競プロ/C++】2次元ベクタを潰してグラフライブラリを軒並み高速化](https://qiita.com/Nachia/items/d420c08b333296f54526)