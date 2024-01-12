---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Edge<T> &e) {\n        // output format:\
    \ \"{ id : from -> to, cost }\"\n        return os << \"{ \" << e.id << \" : \"\
    \ << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\n\
    template <class T> using Edges = std::vector<Edge<T>>;\ntemplate <class T> using\
    \ Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"graph/low_link.hpp\"\n\
    \ntemplate <class T> struct LowLink {\n    int n;\n    std::vector<int> ord, low,\
    \ articulation;\n    std::vector<std::pair<int, int>> bridge;  // edges {u, v}\
    \ (u < v)\n\n    LowLink(const Graph<T> &g) : n(int(g.size())), ord(n, -1), low(n,\
    \ -1) {\n        int k = 0;\n        auto dfs = [&](auto f, int cur, int par)\
    \ -> void {\n            low[cur] = ord[cur] = k;\n            k++;\n        \
    \    int cnt = 0;\n            bool is_articulation = false;\n            for\
    \ (auto &e : g[cur]) {\n                if (ord[e.to] == -1) {\n             \
    \       cnt++;\n                    f(f, e.to, cur);\n                    low[cur]\
    \ = std::min(low[cur], low[e.to]);\n                    is_articulation |= (par\
    \ != -1) && (ord[cur] <= low[e.to]);\n                    if (ord[cur] < low[e.to])\
    \ {\n                        bridge.emplace_back(std::minmax(cur, e.to));\n  \
    \                  }\n                } else if (e.to != par) {\n            \
    \        low[cur] = std::min(low[cur], ord[e.to]);\n                }\n      \
    \      }\n            is_articulation |= par == -1 && cnt > 1;\n            if\
    \ (is_articulation) articulation.push_back(cur);\n            return;\n      \
    \  };\n        for (int i = 0; i < n; i++) {\n            if (ord[i] == -1) {\n\
    \                dfs(dfs, i, -1);\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> struct LowLink {\n    int n;\n    std::vector<int> ord, low, articulation;\n\
    \    std::vector<std::pair<int, int>> bridge;  // edges {u, v} (u < v)\n\n   \
    \ LowLink(const Graph<T> &g) : n(int(g.size())), ord(n, -1), low(n, -1) {\n  \
    \      int k = 0;\n        auto dfs = [&](auto f, int cur, int par) -> void {\n\
    \            low[cur] = ord[cur] = k;\n            k++;\n            int cnt =\
    \ 0;\n            bool is_articulation = false;\n            for (auto &e : g[cur])\
    \ {\n                if (ord[e.to] == -1) {\n                    cnt++;\n    \
    \                f(f, e.to, cur);\n                    low[cur] = std::min(low[cur],\
    \ low[e.to]);\n                    is_articulation |= (par != -1) && (ord[cur]\
    \ <= low[e.to]);\n                    if (ord[cur] < low[e.to]) {\n          \
    \              bridge.emplace_back(std::minmax(cur, e.to));\n                \
    \    }\n                } else if (e.to != par) {\n                    low[cur]\
    \ = std::min(low[cur], ord[e.to]);\n                }\n            }\n       \
    \     is_articulation |= par == -1 && cnt > 1;\n            if (is_articulation)\
    \ articulation.push_back(cur);\n            return;\n        };\n        for (int\
    \ i = 0; i < n; i++) {\n            if (ord[i] == -1) {\n                dfs(dfs,\
    \ i, -1);\n            }\n        }\n    }\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/low_link.hpp
  requiredBy: []
  timestamp: '2024-01-12 19:15:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_grl/aoj_grl_3_a.test.cpp
  - verify/aoj_grl/aoj_grl_3_b.test.cpp
documentation_of: graph/low_link.hpp
layout: document
title: "Low Link (\u95A2\u7BC0\u70B9\u30FB\u6A4B)"
---

- `LowLink llink(G);` で作成
- `llink.articulation` に関節点が、`llink.bridge` に橋となる辺が含まれる
