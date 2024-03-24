---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
    title: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_1_b.test.cpp
    title: verify/aoj_grl/aoj_grl_1_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_2_a.test.cpp
    title: verify/aoj_grl/aoj_grl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_3_a.test.cpp
    title: verify/aoj_grl/aoj_grl_3_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_3_b.test.cpp
    title: verify/aoj_grl/aoj_grl_3_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_graph/lc_scc.test.cpp
    title: verify/lc_graph/lc_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
    title: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_tree/lc_tree_diameter.test.cpp
    title: verify/lc_tree/lc_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\ntemplate <class T> struct Edge {\n    int from, to;\n \
    \   T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int to,\
    \ T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n    \
    \    // output format: \"{ id : from -> to, cost }\"\n        return os << \"\
    { \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \"\
    \ }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    graph/read_graph.hpp\"\n\ntemplate <class T> Graph<T> read_graph(const int n,\
    \ const int m, const bool weight = false, const bool directed = false, const int\
    \ offset = 1) {\n    Graph<T> g(n);\n    for (int i = 0; i < m; i++) {\n     \
    \   int a, b;\n        std::cin >> a >> b;\n        a -= offset, b -= offset;\n\
    \        if (weight) {\n            T c;\n            std::cin >> c;\n       \
    \     if (!directed) g[b].push_back(Edge(b, a, c, i));\n            g[a].push_back(Edge(a,\
    \ b, c, i));\n        } else {\n            // c = 1\n            if (!directed)\
    \ g[b].push_back(Edge(b, a, T(1), i));\n            g[a].push_back(Edge(a, b,\
    \ T(1), i));\n        }\n    }\n    return g;\n}\n\ntemplate <class T> Graph<T>\
    \ read_parent(const int n, const bool weight = false, const bool directed = false,\
    \ const int offset = 1) {\n    Graph<T> g(n);\n    for (int i = 1; i < n; i++)\
    \ {\n        int p;\n        std::cin >> p;\n        p -= offset;\n        if\
    \ (weight) {\n            T c;\n            std::cin >> c;\n            if (!directed)\
    \ g[i].push_back(Edge(i, p, c, i - 1));\n            g[p].push_back(Edge(p, i,\
    \ c, i - 1));\n        } else {\n            // c = 1\n            if (!directed)\
    \ g[i].push_back(Edge(i, p, T(1), i - 1));\n            g[p].push_back(Edge(p,\
    \ i, T(1), i - 1));\n        }\n    }\n    return g;\n}\n\nstd::tuple<Graph<int>,\
    \ std::vector<std::vector<int>>, std::vector<std::pair<int, int>>> read_grid(const\
    \ int h, const int w, std::string rel = \".#\") {\n    std::vector<std::string>\
    \ s(h);\n    std::vector id(h, std::vector<int>(w, -1));\n    std::vector<std::pair<int,\
    \ int>> loc;\n    int n = 0;\n    for (int i = 0; i < h; i++) {\n        std::cin\
    \ >> s[i];\n        for (int j = 0; j < w; j++) {\n            if (s[i][j] ==\
    \ rel[1]) {\n                id[i][j] = n++;\n                loc.emplace_back(i,\
    \ j);\n            }\n        }\n    }\n    int m = 0;\n    Graph<int> g(n);\n\
    \    for (int i = 0; i < h; i++) {\n        for (int j = 0; j < w; j++) {\n  \
    \          if (s[i][j] == rel[1]) {\n                if (i + 1 < h and s[i + 1][j]\
    \ == rel[1]) {\n                    g[id[i][j]].push_back(Edge(id[i][j], id[i\
    \ + 1][j], 1, m));\n                    g[id[i + 1][j]].push_back(Edge(id[i +\
    \ 1][j], id[i][j], 1, m++));\n                }\n                if (j + 1 < w\
    \ and s[i][j + 1] == rel[1]) {\n                    g[id[i][j]].push_back(Edge(id[i][j],\
    \ id[i][j + 1], 1, m));\n                    g[id[i][j + 1]].push_back(Edge(id[i][j\
    \ + 1], id[i][j], 1, m++));\n                }\n            }\n        }\n   \
    \ }\n    return {g, id, loc};\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> Graph<T> read_graph(const int n, const int m, const bool weight = false,\
    \ const bool directed = false, const int offset = 1) {\n    Graph<T> g(n);\n \
    \   for (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        a -= offset, b -= offset;\n        if (weight) {\n            T\
    \ c;\n            std::cin >> c;\n            if (!directed) g[b].push_back(Edge(b,\
    \ a, c, i));\n            g[a].push_back(Edge(a, b, c, i));\n        } else {\n\
    \            // c = 1\n            if (!directed) g[b].push_back(Edge(b, a, T(1),\
    \ i));\n            g[a].push_back(Edge(a, b, T(1), i));\n        }\n    }\n \
    \   return g;\n}\n\ntemplate <class T> Graph<T> read_parent(const int n, const\
    \ bool weight = false, const bool directed = false, const int offset = 1) {\n\
    \    Graph<T> g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n     \
    \   std::cin >> p;\n        p -= offset;\n        if (weight) {\n            T\
    \ c;\n            std::cin >> c;\n            if (!directed) g[i].push_back(Edge(i,\
    \ p, c, i - 1));\n            g[p].push_back(Edge(p, i, c, i - 1));\n        }\
    \ else {\n            // c = 1\n            if (!directed) g[i].push_back(Edge(i,\
    \ p, T(1), i - 1));\n            g[p].push_back(Edge(p, i, T(1), i - 1));\n  \
    \      }\n    }\n    return g;\n}\n\nstd::tuple<Graph<int>, std::vector<std::vector<int>>,\
    \ std::vector<std::pair<int, int>>> read_grid(const int h, const int w, std::string\
    \ rel = \".#\") {\n    std::vector<std::string> s(h);\n    std::vector id(h, std::vector<int>(w,\
    \ -1));\n    std::vector<std::pair<int, int>> loc;\n    int n = 0;\n    for (int\
    \ i = 0; i < h; i++) {\n        std::cin >> s[i];\n        for (int j = 0; j <\
    \ w; j++) {\n            if (s[i][j] == rel[1]) {\n                id[i][j] =\
    \ n++;\n                loc.emplace_back(i, j);\n            }\n        }\n  \
    \  }\n    int m = 0;\n    Graph<int> g(n);\n    for (int i = 0; i < h; i++) {\n\
    \        for (int j = 0; j < w; j++) {\n            if (s[i][j] == rel[1]) {\n\
    \                if (i + 1 < h and s[i + 1][j] == rel[1]) {\n                \
    \    g[id[i][j]].push_back(Edge(id[i][j], id[i + 1][j], 1, m));\n            \
    \        g[id[i + 1][j]].push_back(Edge(id[i + 1][j], id[i][j], 1, m++));\n  \
    \              }\n                if (j + 1 < w and s[i][j + 1] == rel[1]) {\n\
    \                    g[id[i][j]].push_back(Edge(id[i][j], id[i][j + 1], 1, m));\n\
    \                    g[id[i][j + 1]].push_back(Edge(id[i][j + 1], id[i][j], 1,\
    \ m++));\n                }\n            }\n        }\n    }\n    return {g, id,\
    \ loc};\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/read_graph.hpp
  requiredBy: []
  timestamp: '2024-01-25 10:46:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_grl/aoj_grl_2_a.test.cpp
  - verify/aoj_grl/aoj_grl_3_b.test.cpp
  - verify/aoj_grl/aoj_grl_3_a.test.cpp
  - verify/aoj_grl/aoj_grl_1_b.test.cpp
  - verify/aoj_dpl/aoj_dpl_2_a.test.cpp
  - verify/lc_tree/lc_tree_diameter.test.cpp
  - verify/lc_graph/lc_scc.test.cpp
  - verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
documentation_of: graph/read_graph.hpp
layout: document
redirect_from:
- /library/graph/read_graph.hpp
- /library/graph/read_graph.hpp.html
title: graph/read_graph.hpp
---
