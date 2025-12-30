---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/restore_path.hpp
    title: Restore path
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter_1.test.cpp
    title: verify/graph/tree_diameter_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter_2.test.cpp
    title: verify/graph/tree_diameter_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/zero_one_bfs.test.cpp
    title: verify/graph/zero_one_bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree_diameter.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
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
    \    }\n};\n#line 2 \"graph/restore_path.hpp\"\n\n#line 4 \"graph/restore_path.hpp\"\
    \n#include <algorithm>\n\n// restore path from root[t] to t\nstd::vector<int>\
    \ restore_path(std::vector<int>& par, int t) {\n    std::vector<int> path = {t};\n\
    \    while (par[path.back()] != -1) path.emplace_back(par[path.back()]);\n   \
    \ std::reverse(path.begin(), path.end());\n    return path;\n}\n#line 5 \"graph/tree_diameter.hpp\"\
    \n\n#include <utility>\n#line 8 \"graph/tree_diameter.hpp\"\n\n// {\u76F4\u5F84\
    \u306E\u8FBA\u306E\u91CD\u307F\u306E\u7DCF\u548C, \u901A\u308B\u9802\u70B9\u96C6\
    \u5408}\ntemplate <class T> std::pair<T, std::vector<int>> tree_diameter(Graph<T>&\
    \ g) {\n    const int n = (int)(g.size());\n    std::vector<int> parent(n, -1);\n\
    \    std::vector<T> dist(n);\n\n    auto dfs = [&](auto f, int cur, int par) ->\
    \ void {\n        for (auto&& e : g[cur]) {\n            if (e.to == par) continue;\n\
    \            dist[e.to] = dist[cur] + e.cost;\n            parent[e.to] = cur;\n\
    \            f(f, e.to, cur);\n        }\n        return;\n    };\n\n    dfs(dfs,\
    \ 0, -1);\n    int s = std::max_element(dist.begin(), dist.end()) - dist.begin();\n\
    \    dist.assign(n, 0);\n    parent.assign(n, -1);\n    dfs(dfs, s, -1);\n   \
    \ int t = std::max_element(dist.begin(), dist.end()) - dist.begin();\n    auto\
    \ path = restore_path(parent, t);\n    return {dist[t], path};\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n#include \"graph/restore_path.hpp\"\
    \n\n#include <utility>\n#include <algorithm>\n\n// {\u76F4\u5F84\u306E\u8FBA\u306E\
    \u91CD\u307F\u306E\u7DCF\u548C, \u901A\u308B\u9802\u70B9\u96C6\u5408}\ntemplate\
    \ <class T> std::pair<T, std::vector<int>> tree_diameter(Graph<T>& g) {\n    const\
    \ int n = (int)(g.size());\n    std::vector<int> parent(n, -1);\n    std::vector<T>\
    \ dist(n);\n\n    auto dfs = [&](auto f, int cur, int par) -> void {\n       \
    \ for (auto&& e : g[cur]) {\n            if (e.to == par) continue;\n        \
    \    dist[e.to] = dist[cur] + e.cost;\n            parent[e.to] = cur;\n     \
    \       f(f, e.to, cur);\n        }\n        return;\n    };\n\n    dfs(dfs, 0,\
    \ -1);\n    int s = std::max_element(dist.begin(), dist.end()) - dist.begin();\n\
    \    dist.assign(n, 0);\n    parent.assign(n, -1);\n    dfs(dfs, s, -1);\n   \
    \ int t = std::max_element(dist.begin(), dist.end()) - dist.begin();\n    auto\
    \ path = restore_path(parent, t);\n    return {dist[t], path};\n}"
  dependsOn:
  - graph/graph_template.hpp
  - graph/restore_path.hpp
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2024-07-31 21:19:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/tree_diameter_2.test.cpp
  - verify/graph/zero_one_bfs.test.cpp
  - verify/graph/tree_diameter_1.test.cpp
documentation_of: graph/tree_diameter.hpp
layout: document
title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
---

## 使い方

```cpp
Graph<T> g;
auto [d, path] = tree_diameter(g);  // 直径の長さとパス
```

## 参考文献
