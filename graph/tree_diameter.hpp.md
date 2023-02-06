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
    _deprecated_at_docs: docs/graph/tree_diameter.md
    document_title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
    links: []
  bundledCode: "#line 2 \"graph/tree_diameter.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"graph/tree_diameter.hpp\"\n\ntemplate <class T, class Graph> std::pair<T,\
    \ std::vector<edge<T>>> tree_diameter(Graph &G) {\n    std::vector<int> to(G.size(),\
    \ -1);\n\n    auto dfs = [&](auto f, int cur, int par) -> std::pair<T, int> {\n\
    \        std::pair<T, int> ret = {0, cur};\n        for (auto &e : G[cur]) {\n\
    \            if (e.to == par) continue;\n            auto cost = f(f, e.to, cur);\n\
    \            cost.first += e.cost;\n            if (ret.first < cost.first) {\n\
    \                ret = cost;\n                to[cur] = e.to;\n            }\n\
    \        }\n        return ret;\n    };\n\n    auto s = dfs(dfs, 0, -1);\n   \
    \ auto t = dfs(dfs, s.second, -1);\n\n    int cur = s.second;\n    std::vector<edge<T>>\
    \ path;\n    while (cur != t.second) {\n        for (auto &e : G[cur]) {\n   \
    \         if (to[cur] == e.to) {\n                path.emplace_back(e);\n    \
    \        }\n        }\n        cur = to[cur];\n    }\n    return {t.first, path};\n\
    }\n\n/**\n * @brief Tree Diameter (\u6728\u306E\u76F4\u5F84)\n * @docs docs/graph/tree_diameter.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T, class Graph> std::pair<T, std::vector<edge<T>>> tree_diameter(Graph &G) {\n\
    \    std::vector<int> to(G.size(), -1);\n\n    auto dfs = [&](auto f, int cur,\
    \ int par) -> std::pair<T, int> {\n        std::pair<T, int> ret = {0, cur};\n\
    \        for (auto &e : G[cur]) {\n            if (e.to == par) continue;\n  \
    \          auto cost = f(f, e.to, cur);\n            cost.first += e.cost;\n \
    \           if (ret.first < cost.first) {\n                ret = cost;\n     \
    \           to[cur] = e.to;\n            }\n        }\n        return ret;\n \
    \   };\n\n    auto s = dfs(dfs, 0, -1);\n    auto t = dfs(dfs, s.second, -1);\n\
    \n    int cur = s.second;\n    std::vector<edge<T>> path;\n    while (cur != t.second)\
    \ {\n        for (auto &e : G[cur]) {\n            if (to[cur] == e.to) {\n  \
    \              path.emplace_back(e);\n            }\n        }\n        cur =\
    \ to[cur];\n    }\n    return {t.first, path};\n}\n\n/**\n * @brief Tree Diameter\
    \ (\u6728\u306E\u76F4\u5F84)\n * @docs docs/graph/tree_diameter.md\n */\n"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_tree/lc_tree_diameter.test.cpp
documentation_of: graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/graph/tree_diameter.hpp
- /library/graph/tree_diameter.hpp.html
title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
---
# Tree Diameter (木の直径)

## 概要

- `auto [d, path] = tree_diameter(G);` で `d` に直径の長さが、`path` に辺の集合が入る
