---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_tree/lc_tree_diameter.test.cpp
    title: verify/lc_tree/lc_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree_diameter.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ Edges = std::vector<Edge<T>>;\ntemplate <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n\
    #line 4 \"graph/tree_diameter.hpp\"\n\ntemplate <class T> std::pair<T, std::vector<Edge<T>>>\
    \ tree_diameter(Graph<T> &G) {\n    std::vector<int> to(G.size(), -1);\n\n   \
    \ auto dfs = [&](auto f, int cur, int par) -> std::pair<T, int> {\n        std::pair<T,\
    \ int> ret = {0, cur};\n        for (auto &e : G[cur]) {\n            if (e.to\
    \ == par) continue;\n            auto cost = f(f, e.to, cur);\n            cost.first\
    \ += e.cost;\n            if (ret.first < cost.first) {\n                ret =\
    \ cost;\n                to[cur] = e.to;\n            }\n        }\n        return\
    \ ret;\n    };\n\n    auto s = dfs(dfs, 0, -1);\n    auto t = dfs(dfs, s.second,\
    \ -1);\n\n    int cur = s.second;\n    std::vector<Edge<T>> path;\n    while (cur\
    \ != t.second) {\n        for (auto &e : G[cur]) {\n            if (to[cur] ==\
    \ e.to) {\n                path.emplace_back(e);\n            }\n        }\n \
    \       cur = to[cur];\n    }\n    return {t.first, path};\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> std::pair<T, std::vector<Edge<T>>> tree_diameter(Graph<T> &G) {\n    std::vector<int>\
    \ to(G.size(), -1);\n\n    auto dfs = [&](auto f, int cur, int par) -> std::pair<T,\
    \ int> {\n        std::pair<T, int> ret = {0, cur};\n        for (auto &e : G[cur])\
    \ {\n            if (e.to == par) continue;\n            auto cost = f(f, e.to,\
    \ cur);\n            cost.first += e.cost;\n            if (ret.first < cost.first)\
    \ {\n                ret = cost;\n                to[cur] = e.to;\n          \
    \  }\n        }\n        return ret;\n    };\n\n    auto s = dfs(dfs, 0, -1);\n\
    \    auto t = dfs(dfs, s.second, -1);\n\n    int cur = s.second;\n    std::vector<Edge<T>>\
    \ path;\n    while (cur != t.second) {\n        for (auto &e : G[cur]) {\n   \
    \         if (to[cur] == e.to) {\n                path.emplace_back(e);\n    \
    \        }\n        }\n        cur = to[cur];\n    }\n    return {t.first, path};\n\
    }"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_tree/lc_tree_diameter.test.cpp
documentation_of: graph/tree_diameter.hpp
layout: document
title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
---

- `auto [d, path] = tree_diameter(G);` で `d` に直径の長さが、`path` に辺の集合が入る
