---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_3_a.test.cpp
    title: verify/aoj_grl/aoj_grl_3_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_3_b.test.cpp
    title: verify/aoj_grl/aoj_grl_3_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/low_link.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\ntemplate <class T> struct Edge {\n    int from, to;\n \
    \   T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int to,\
    \ T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n    \
    \    // output format: \"{ id : from -> to, cost }\"\n        return os << \"\
    { \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \"\
    \ }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    graph/low_link.hpp\"\n\ntemplate <class T> struct LowLink {\n    int n;\n    std::vector<int>\
    \ ord, low;\n    std::vector<int> articulations;\n    std::vector<int> roots;\n\
    \    std::vector<std::pair<int, int>> bridges;  // edges {u, v} (u < v)\n    std::vector<std::vector<int>>\
    \ dfs_tree;\n\n    LowLink(const Graph<T>& g) : n(int(g.size())) {\n        ord.assign(n,\
    \ -1);\n        low.assign(n, -1);\n        dfs_tree.resize(n);\n        int ord_id\
    \ = 0;\n        auto dfs = [&](auto f, int cur, int par) -> void {\n         \
    \   low[cur] = ord[cur] = ord_id++;\n            bool is_articulation = false;\n\
    \            for (auto& e : g[cur]) {\n                if (ord[e.to] == -1) {\n\
    \                    // DFS \u6728\u4E0A\u306E\u8FBA\u306B\u5BFE\u3059\u308B\u51E6\
    \u7406\n                    f(f, e.to, cur);\n                    dfs_tree[cur].push_back(e.to);\n\
    \                    // e \u304C DFS \u6728\u306B\u542B\u307E\u308C\u3066\u3044\
    \u308B\u306E\u3067\u5F8C\u9000\u8FBA\u3092\u3059\u3067\u306B\u901A\u3063\u305F\
    \ low[e.to] \u3092\u4F7F\u3063\u3066\u66F4\u65B0\u3057\u3066\u826F\u3044\n   \
    \                 low[cur] = std::min(low[cur], low[e.to]);\n                \
    \    is_articulation |= (par != -1) and (ord[cur] <= low[e.to]);\n           \
    \         if (ord[cur] < low[e.to]) {\n                        bridges.emplace_back(std::minmax(cur,\
    \ e.to));\n                    }\n                } else if (e.to != par) {\n\
    \                    // \u5F8C\u9000\u8FBA\u306B\u5BFE\u3059\u308B\u51E6\u7406\
    \n                    // Todo: multiple edges\n                    low[cur] =\
    \ std::min(low[cur], ord[e.to]);\n                }\n            }\n         \
    \   is_articulation |= par == -1 and int(dfs_tree[cur].size()) > 1;\n        \
    \    if (is_articulation) articulations.push_back(cur);\n            return;\n\
    \        };\n        for (int i = 0; i < n; i++) {\n            if (ord[i] ==\
    \ -1) {\n                roots.push_back(i);\n                dfs(dfs, i, -1);\n\
    \            }\n        }\n    }\n    // \u9023\u7D50\u6210\u5206\u6570\n    int\
    \ count_components() { return int(roots.size()); }\n    // \u9802\u70B9 x \u3092\
    \u53D6\u308A\u9664\u304F\u3068\u3082\u3068\u3082\u3068 1 \u3064\u3060\u3063\u305F\
    \u9023\u7D50\u6210\u5206\u304C\u3044\u304F\u3064\u306B\u306A\u308B\u304B\n   \
    \ int count_components_remove(int x) {\n        if (std::binary_search(roots.begin(),\
    \ roots.end(), x)) {\n            int c = int(dfs_tree[x].size());\n         \
    \   return c;\n        } else {\n            int c = 0;\n            for (auto&\
    \ e : dfs_tree[x]) {\n                if (ord[x] <= low[e]) c++;\n           \
    \ }\n            // \u89AA\u306E\u5206\u3067 +1\n            return c + 1;\n \
    \       }\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> struct LowLink {\n    int n;\n    std::vector<int> ord, low;\n    std::vector<int>\
    \ articulations;\n    std::vector<int> roots;\n    std::vector<std::pair<int,\
    \ int>> bridges;  // edges {u, v} (u < v)\n    std::vector<std::vector<int>> dfs_tree;\n\
    \n    LowLink(const Graph<T>& g) : n(int(g.size())) {\n        ord.assign(n, -1);\n\
    \        low.assign(n, -1);\n        dfs_tree.resize(n);\n        int ord_id =\
    \ 0;\n        auto dfs = [&](auto f, int cur, int par) -> void {\n           \
    \ low[cur] = ord[cur] = ord_id++;\n            bool is_articulation = false;\n\
    \            for (auto& e : g[cur]) {\n                if (ord[e.to] == -1) {\n\
    \                    // DFS \u6728\u4E0A\u306E\u8FBA\u306B\u5BFE\u3059\u308B\u51E6\
    \u7406\n                    f(f, e.to, cur);\n                    dfs_tree[cur].push_back(e.to);\n\
    \                    // e \u304C DFS \u6728\u306B\u542B\u307E\u308C\u3066\u3044\
    \u308B\u306E\u3067\u5F8C\u9000\u8FBA\u3092\u3059\u3067\u306B\u901A\u3063\u305F\
    \ low[e.to] \u3092\u4F7F\u3063\u3066\u66F4\u65B0\u3057\u3066\u826F\u3044\n   \
    \                 low[cur] = std::min(low[cur], low[e.to]);\n                \
    \    is_articulation |= (par != -1) and (ord[cur] <= low[e.to]);\n           \
    \         if (ord[cur] < low[e.to]) {\n                        bridges.emplace_back(std::minmax(cur,\
    \ e.to));\n                    }\n                } else if (e.to != par) {\n\
    \                    // \u5F8C\u9000\u8FBA\u306B\u5BFE\u3059\u308B\u51E6\u7406\
    \n                    // Todo: multiple edges\n                    low[cur] =\
    \ std::min(low[cur], ord[e.to]);\n                }\n            }\n         \
    \   is_articulation |= par == -1 and int(dfs_tree[cur].size()) > 1;\n        \
    \    if (is_articulation) articulations.push_back(cur);\n            return;\n\
    \        };\n        for (int i = 0; i < n; i++) {\n            if (ord[i] ==\
    \ -1) {\n                roots.push_back(i);\n                dfs(dfs, i, -1);\n\
    \            }\n        }\n    }\n    // \u9023\u7D50\u6210\u5206\u6570\n    int\
    \ count_components() { return int(roots.size()); }\n    // \u9802\u70B9 x \u3092\
    \u53D6\u308A\u9664\u304F\u3068\u3082\u3068\u3082\u3068 1 \u3064\u3060\u3063\u305F\
    \u9023\u7D50\u6210\u5206\u304C\u3044\u304F\u3064\u306B\u306A\u308B\u304B\n   \
    \ int count_components_remove(int x) {\n        if (std::binary_search(roots.begin(),\
    \ roots.end(), x)) {\n            int c = int(dfs_tree[x].size());\n         \
    \   return c;\n        } else {\n            int c = 0;\n            for (auto&\
    \ e : dfs_tree[x]) {\n                if (ord[x] <= low[e]) c++;\n           \
    \ }\n            // \u89AA\u306E\u5206\u3067 +1\n            return c + 1;\n \
    \       }\n    }\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/low_link.hpp
  requiredBy: []
  timestamp: '2024-01-25 10:46:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_grl/aoj_grl_3_b.test.cpp
  - verify/aoj_grl/aoj_grl_3_a.test.cpp
documentation_of: graph/low_link.hpp
layout: document
title: "Low Link (\u95A2\u7BC0\u70B9\u30FB\u6A4B)"
---

- `LowLink llink(G);` で作成
- `llink.articulations` に関節点が、`llink.bridges` に橋となる辺が含まれる
