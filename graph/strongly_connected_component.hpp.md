---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_graph/lc_scc.test.cpp
    title: verify/lc_graph/lc_scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/strongly_connected_component.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\ntemplate <class T> struct Edge {\n    int from, to;\n \
    \   T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int to,\
    \ T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n    \
    \    // output format: \"{ id : from -> to, cost }\"\n        return os << \"\
    { \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \"\
    \ }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    graph/strongly_connected_component.hpp\"\n\ntemplate <class T> std::vector<std::vector<int>>\
    \ strongly_connected_component(Graph<T>& g) {\n    int n = int(g.size());\n  \
    \  int now_ord = 0, group_num = 0;\n    std::vector<int> visited, low(n), ord(n,\
    \ -1), ids(n);\n    visited.reserve(n);\n    auto dfs = [&](auto f, int cur) ->\
    \ void {\n        low[cur] = ord[cur] = now_ord++;\n        visited.push_back(cur);\n\
    \        for (auto& e : g[cur]) {\n            if (ord[e.to] == -1) {\n      \
    \          f(f, e.to);\n                low[cur] = std::min(low[cur], low[e.to]);\n\
    \            } else {\n                low[cur] = std::min(low[cur], ord[e.to]);\n\
    \            }\n        }\n        if (low[cur] == ord[cur]) {\n            while\
    \ (true) {\n                int u = visited.back();\n                visited.pop_back();\n\
    \                ord[u] = n;\n                ids[u] = group_num;\n          \
    \      if (u == cur) break;\n            }\n            group_num++;\n       \
    \ }\n    };\n    for (int i = 0; i < n; i++) {\n        if (ord[i] == -1) dfs(dfs,\
    \ i);\n    }\n    for (auto& x : ids) {\n        x = group_num - 1 - x;\n    }\n\
    \    std::vector<int> counts(group_num);\n    for (auto& x : ids) counts[x]++;\n\
    \    std::vector<std::vector<int>> groups(group_num);\n    for (int i = 0; i <\
    \ group_num; i++) {\n        groups[i].reserve(counts[i]);\n    }\n    for (int\
    \ i = 0; i < n; i++) {\n        groups[ids[i]].push_back(i);\n    }\n    return\
    \ groups;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> std::vector<std::vector<int>> strongly_connected_component(Graph<T>& g) {\n\
    \    int n = int(g.size());\n    int now_ord = 0, group_num = 0;\n    std::vector<int>\
    \ visited, low(n), ord(n, -1), ids(n);\n    visited.reserve(n);\n    auto dfs\
    \ = [&](auto f, int cur) -> void {\n        low[cur] = ord[cur] = now_ord++;\n\
    \        visited.push_back(cur);\n        for (auto& e : g[cur]) {\n         \
    \   if (ord[e.to] == -1) {\n                f(f, e.to);\n                low[cur]\
    \ = std::min(low[cur], low[e.to]);\n            } else {\n                low[cur]\
    \ = std::min(low[cur], ord[e.to]);\n            }\n        }\n        if (low[cur]\
    \ == ord[cur]) {\n            while (true) {\n                int u = visited.back();\n\
    \                visited.pop_back();\n                ord[u] = n;\n          \
    \      ids[u] = group_num;\n                if (u == cur) break;\n           \
    \ }\n            group_num++;\n        }\n    };\n    for (int i = 0; i < n; i++)\
    \ {\n        if (ord[i] == -1) dfs(dfs, i);\n    }\n    for (auto& x : ids) {\n\
    \        x = group_num - 1 - x;\n    }\n    std::vector<int> counts(group_num);\n\
    \    for (auto& x : ids) counts[x]++;\n    std::vector<std::vector<int>> groups(group_num);\n\
    \    for (int i = 0; i < group_num; i++) {\n        groups[i].reserve(counts[i]);\n\
    \    }\n    for (int i = 0; i < n; i++) {\n        groups[ids[i]].push_back(i);\n\
    \    }\n    return groups;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/strongly_connected_component.hpp
  requiredBy: []
  timestamp: '2024-01-25 10:46:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_graph/lc_scc.test.cpp
documentation_of: graph/strongly_connected_component.hpp
layout: document
title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206)"
---

- `strongly_connected_component(G)` で「頂点のリスト」のリストを返す
- トポロジカルソートされている
