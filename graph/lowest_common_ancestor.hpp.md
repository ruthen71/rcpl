---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/auxiliary_tree.hpp
    title: "Auxiliary Tree (\u865A\u6811)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/lowest_common_ancestor.test.cpp
    title: verify/graph/lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/lowest_common_ancestor.hpp\"\n\n#include <vector>\n\
    \n#line 2 \"graph/graph_template.hpp\"\n\n#line 4 \"graph/graph_template.hpp\"\
    \n#include <cassert>\n\ntemplate <class T> struct Edge {\n    int from, to;\n\
    \    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const int from, const\
    \ int to, const T cost = T(1), const int id = -1) : from(from), to(to), cost(cost),\
    \ id(id) {}\n\n    friend std::ostream& operator<<(std::ostream& os, const Edge<T>&\
    \ e) {\n        // output format: {id: cost(from, to) = cost}\n        return\
    \ os << \"{\" << e.id << \": cost(\" << e.from << \", \" << e.to << \") = \" <<\
    \ e.cost << \"}\";\n    }\n};\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
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
    };\n#line 6 \"graph/lowest_common_ancestor.hpp\"\n\ntemplate <class T> struct\
    \ LowestCommonAncestor {\n    int n, lg;\n    std::vector<int> depth;\n    std::vector<std::vector<int>>\
    \ parent;\n\n    LowestCommonAncestor(Graph<T>& g, const int root = 0) : n((int)(g.size())),\
    \ lg(32 - __builtin_clz(n)), depth(n, 0), parent(lg, std::vector<int>(n)) {\n\
    \        auto dfs = [&](auto f, int cur, int par) -> void {\n            parent[0][cur]\
    \ = par;\n            for (auto&& e : g[cur]) {\n                if (e.to == par)\
    \ continue;\n                depth[e.to] = depth[cur] + 1;\n                f(f,\
    \ e.to, cur);\n            }\n        };\n        dfs(dfs, root, -1);\n      \
    \  for (int k = 0; k + 1 < lg; k++) {\n            for (int v = 0; v < n; v++)\
    \ {\n                parent[k + 1][v] = parent[k][v] < 0 ? -1 : parent[k][parent[k][v]];\n\
    \            }\n        }\n    }\n\n    int lca(int u, int v) {\n        assert((int)(depth.size())\
    \ == n);\n        if (depth[u] > depth[v]) std::swap(u, v);\n        // depth[u]\
    \ <= depth[v]\n        for (int k = 0; k < lg; k++) {\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) v = parent[k][v];\n        }\n        if (u == v) return\
    \ u;\n        for (int k = lg - 1; k >= 0; k--) {\n            if (parent[k][u]\
    \ != parent[k][v]) {\n                u = parent[k][u];\n                v = parent[k][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    int level_ancestor(int\
    \ u, const int d) {\n        assert((int)(depth.size()) == n);\n        if (depth[u]\
    \ < d) return -1;\n        for (int k = 0; k < lg; k++) {\n            if (d >>\
    \ k & 1) u = parent[k][u];\n        }\n        return u;\n    }\n\n    int distance(const\
    \ int u, const int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)];\
    \ }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct LowestCommonAncestor {\n    int n, lg;\n    std::vector<int>\
    \ depth;\n    std::vector<std::vector<int>> parent;\n\n    LowestCommonAncestor(Graph<T>&\
    \ g, const int root = 0) : n((int)(g.size())), lg(32 - __builtin_clz(n)), depth(n,\
    \ 0), parent(lg, std::vector<int>(n)) {\n        auto dfs = [&](auto f, int cur,\
    \ int par) -> void {\n            parent[0][cur] = par;\n            for (auto&&\
    \ e : g[cur]) {\n                if (e.to == par) continue;\n                depth[e.to]\
    \ = depth[cur] + 1;\n                f(f, e.to, cur);\n            }\n       \
    \ };\n        dfs(dfs, root, -1);\n        for (int k = 0; k + 1 < lg; k++) {\n\
    \            for (int v = 0; v < n; v++) {\n                parent[k + 1][v] =\
    \ parent[k][v] < 0 ? -1 : parent[k][parent[k][v]];\n            }\n        }\n\
    \    }\n\n    int lca(int u, int v) {\n        assert((int)(depth.size()) == n);\n\
    \        if (depth[u] > depth[v]) std::swap(u, v);\n        // depth[u] <= depth[v]\n\
    \        for (int k = 0; k < lg; k++) {\n            if ((depth[v] - depth[u])\
    \ >> k & 1) v = parent[k][v];\n        }\n        if (u == v) return u;\n    \
    \    for (int k = lg - 1; k >= 0; k--) {\n            if (parent[k][u] != parent[k][v])\
    \ {\n                u = parent[k][u];\n                v = parent[k][v];\n  \
    \          }\n        }\n        return parent[0][u];\n    }\n\n    int level_ancestor(int\
    \ u, const int d) {\n        assert((int)(depth.size()) == n);\n        if (depth[u]\
    \ < d) return -1;\n        for (int k = 0; k < lg; k++) {\n            if (d >>\
    \ k & 1) u = parent[k][u];\n        }\n        return u;\n    }\n\n    int distance(const\
    \ int u, const int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)];\
    \ }\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/lowest_common_ancestor.hpp
  requiredBy:
  - graph/auxiliary_tree.hpp
  timestamp: '2024-07-31 16:51:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/lowest_common_ancestor.test.cpp
documentation_of: graph/lowest_common_ancestor.hpp
layout: document
title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
---

- `LowestCommonAncestor tq(G, root);` で作成
- `tq.lca(u, v)` で `u` と `v` の最小共通祖先を出力
- `tq.level_ancestor(u, d)` で `u` から `d` 本の辺を昇った頂点を出力(辺の重みは考慮しない)

