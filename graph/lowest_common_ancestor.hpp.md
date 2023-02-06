---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_tree/lc_lowest_common_ancestor.test.cpp
    title: verify/lc_tree/lc_lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/lowest_common_ancestor.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"graph/lowest_common_ancestor.hpp\"\n\ntemplate <class Graph> struct\
    \ lowest_common_ancestor {\n    std::vector<int> depth;\n    std::vector<std::vector<int>>\
    \ parent;\n    int n, LOG;\n\n    lowest_common_ancestor(Graph &G, int root =\
    \ 0) : n(G.size()), LOG(32 - __builtin_clz(G.size())) {\n        depth.assign(n,\
    \ 0);\n        parent.assign(LOG, std::vector<int>(n));\n        auto dfs = [&](auto\
    \ f, int cur, int par) -> void {\n            parent[0][cur] = par;\n        \
    \    for (auto &e : G[cur]) {\n                if (e.to == par) continue;\n  \
    \              depth[e.to] = depth[cur] + 1;\n                f(f, e.to, cur);\n\
    \            }\n        };\n        dfs(dfs, root, -1);\n        for (int k =\
    \ 0; k + 1 < LOG; k++) {\n            for (int v = 0; v < n; v++) {\n        \
    \        parent[k + 1][v] = (parent[k][v] < 0 ? -1 : parent[k][parent[k][v]]);\n\
    \            }\n        }\n    }\n\n    int lca(int u, int v) {\n        assert((int)depth.size()\
    \ == n);\n        if (depth[u] > depth[v]) std::swap(u, v);\n        // depth[u]\
    \ <= depth[v]\n        for (int k = 0; k < LOG; k++)\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) v = parent[k][v];\n\n        if (u == v) return u;\n \
    \       for (int k = LOG - 1; k >= 0; k--) {\n            if (parent[k][u] !=\
    \ parent[k][v]) {\n                u = parent[k][u];\n                v = parent[k][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    int level_ancestor(int\
    \ u, int d) {\n        assert((int)depth.size() == n);\n        if (depth[u] <\
    \ d) return -1;\n        for (int k = 0; k < LOG; k++)\n            if (d >> k\
    \ & 1) u = parent[k][u];\n        return u;\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ Graph> struct lowest_common_ancestor {\n    std::vector<int> depth;\n    std::vector<std::vector<int>>\
    \ parent;\n    int n, LOG;\n\n    lowest_common_ancestor(Graph &G, int root =\
    \ 0) : n(G.size()), LOG(32 - __builtin_clz(G.size())) {\n        depth.assign(n,\
    \ 0);\n        parent.assign(LOG, std::vector<int>(n));\n        auto dfs = [&](auto\
    \ f, int cur, int par) -> void {\n            parent[0][cur] = par;\n        \
    \    for (auto &e : G[cur]) {\n                if (e.to == par) continue;\n  \
    \              depth[e.to] = depth[cur] + 1;\n                f(f, e.to, cur);\n\
    \            }\n        };\n        dfs(dfs, root, -1);\n        for (int k =\
    \ 0; k + 1 < LOG; k++) {\n            for (int v = 0; v < n; v++) {\n        \
    \        parent[k + 1][v] = (parent[k][v] < 0 ? -1 : parent[k][parent[k][v]]);\n\
    \            }\n        }\n    }\n\n    int lca(int u, int v) {\n        assert((int)depth.size()\
    \ == n);\n        if (depth[u] > depth[v]) std::swap(u, v);\n        // depth[u]\
    \ <= depth[v]\n        for (int k = 0; k < LOG; k++)\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) v = parent[k][v];\n\n        if (u == v) return u;\n \
    \       for (int k = LOG - 1; k >= 0; k--) {\n            if (parent[k][u] !=\
    \ parent[k][v]) {\n                u = parent[k][u];\n                v = parent[k][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    int level_ancestor(int\
    \ u, int d) {\n        assert((int)depth.size() == n);\n        if (depth[u] <\
    \ d) return -1;\n        for (int k = 0; k < LOG; k++)\n            if (d >> k\
    \ & 1) u = parent[k][u];\n        return u;\n    }\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2023-02-06 19:40:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_tree/lc_lowest_common_ancestor.test.cpp
documentation_of: graph/lowest_common_ancestor.hpp
layout: document
title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
---

- `lowest_common_ancestor tq(G, root);` で作成
- `tq.lca(u, v)` で `u` と `v` の最小共通祖先を出力
- `tq.level_ancestor(u, d)` で `u` から `d` 本の辺を昇った頂点を出力(辺の重みは考慮しない)

