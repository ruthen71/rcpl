---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/template.hpp
    title: src/graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_tree/lc_tree_diameter.test.cpp
    title: verify/lc_tree/lc_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/tree_diameter.md
    document_title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
    links: []
  bundledCode: "#line 2 \"src/graph/tree_diameter.hpp\"\n\n#line 2 \"src/graph/template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to),\
    \ cost(cost), id(id) {}\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const edge<T> &e) {\n        // { id : from -> to, cost }\n        return os\
    \ << \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T, bool directed = false> struct graph\
    \ {\n    int N, M;\n    using cost_type = T;\n    using edge_type = edge<T>;\n\
    \    std::vector<std::vector<edge_type>> G;\n\n    graph() : N(0), M(0) {}\n \
    \   graph(int N) : N(N), M(0), G(N) {}\n\n    constexpr bool is_directed() { return\
    \ directed; }\n\n    size_t size() const { return G.size(); }\n\n    void read_tree(bool\
    \ weight = false, int offset = 1) { read_graph(N - 1, weight, offset); }\n\n \
    \   void read_graph(int _M, bool weight = false, int offset = 1) {\n        for\
    \ (int i = 0; i < _M; i++) {\n            int a, b;\n            std::cin >> a\
    \ >> b;\n            a -= offset, b -= offset;\n            if (weight) {\n  \
    \              T c;\n                std::cin >> c;\n                add_edge(a,\
    \ b, c);\n            } else {\n                add_edge(a, b);\n            }\n\
    \        }\n    }\n\n    void add_edge(const int &a, const int &b, T cost = 1)\
    \ {\n        assert(0 <= a and a < N and 0 <= b and b < N);\n        if (!directed)\
    \ G[b].push_back(edge_type(b, a, cost, M));\n        G[a].push_back(edge_type(a,\
    \ b, cost, M++));\n    }\n\n    inline std::vector<edge_type> &operator[](const\
    \ int &k) { return G[k]; }\n\n    inline const std::vector<edge_type> &operator[](const\
    \ int &k) const { return G[k]; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const graph<T> &G) {\n        os << \"V: \" << G.N << '\\n';\n        os\
    \ << \"E: \" << G.M << '\\n';\n        for (int v = 0; v < G.N; v++) {\n     \
    \       os << \"G[\" << v << \"] = \";\n            os << \"[ \";\n          \
    \  for (auto &e : G[v]) os << e << \" \";\n            os << \"]\\n\";\n     \
    \   }\n        return os;\n    }\n};\n#line 4 \"src/graph/tree_diameter.hpp\"\n\
    \ntemplate <class Graph>\nstd::pair<typename Graph::cost_type, std::vector<typename\
    \ Graph::edge_type>>  //\ntree_diameter(Graph &G) {\n    using T = typename Graph::cost_type;\n\
    \    std::vector<int> to(G.size(), -1);\n\n    auto dfs = [&](auto f, int cur,\
    \ int par) -> std::pair<T, int> {\n        std::pair<T, int> ret = {0, cur};\n\
    \        for (auto &e : G[cur]) {\n            if (e.to == par) continue;\n  \
    \          auto cost = f(f, e.to, cur);\n            cost.first += e.cost;\n \
    \           if (ret.first < cost.first) {\n                ret = cost;\n     \
    \           to[cur] = e.to;\n            }\n        }\n        return ret;\n \
    \   };\n\n    auto s = dfs(dfs, 0, -1);\n    auto t = dfs(dfs, s.second, -1);\n\
    \n    int cur = s.second;\n    std::vector<typename Graph::edge_type> path;\n\
    \    while (cur != t.second) {\n        for (auto &e : G[cur]) {\n           \
    \ if (to[cur] == e.to) {\n                path.emplace_back(e);\n            }\n\
    \        }\n        cur = to[cur];\n    }\n    return {t.first, path};\n}\n\n\
    /**\n * @brief Tree Diameter (\u6728\u306E\u76F4\u5F84)\n * @docs docs/graph/tree_diameter.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"src/graph/template.hpp\"\n\ntemplate <class Graph>\n\
    std::pair<typename Graph::cost_type, std::vector<typename Graph::edge_type>> \
    \ //\ntree_diameter(Graph &G) {\n    using T = typename Graph::cost_type;\n  \
    \  std::vector<int> to(G.size(), -1);\n\n    auto dfs = [&](auto f, int cur, int\
    \ par) -> std::pair<T, int> {\n        std::pair<T, int> ret = {0, cur};\n   \
    \     for (auto &e : G[cur]) {\n            if (e.to == par) continue;\n     \
    \       auto cost = f(f, e.to, cur);\n            cost.first += e.cost;\n    \
    \        if (ret.first < cost.first) {\n                ret = cost;\n        \
    \        to[cur] = e.to;\n            }\n        }\n        return ret;\n    };\n\
    \n    auto s = dfs(dfs, 0, -1);\n    auto t = dfs(dfs, s.second, -1);\n\n    int\
    \ cur = s.second;\n    std::vector<typename Graph::edge_type> path;\n    while\
    \ (cur != t.second) {\n        for (auto &e : G[cur]) {\n            if (to[cur]\
    \ == e.to) {\n                path.emplace_back(e);\n            }\n        }\n\
    \        cur = to[cur];\n    }\n    return {t.first, path};\n}\n\n/**\n * @brief\
    \ Tree Diameter (\u6728\u306E\u76F4\u5F84)\n * @docs docs/graph/tree_diameter.md\n\
    \ */\n"
  dependsOn:
  - src/graph/template.hpp
  isVerificationFile: false
  path: src/graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2022-09-04 19:21:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_tree/lc_tree_diameter.test.cpp
documentation_of: src/graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/src/graph/tree_diameter.hpp
- /library/src/graph/tree_diameter.hpp.html
title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
---
# Tree Diameter (木の直径)

## 概要

- `auto [d, path] = tree_diameter<decltype(G)>(G);` で `d` に直径の長さが、`path` に辺の集合が入る
