---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal's algorithm (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_2_a.test.cpp
    title: verify/aoj_grl/aoj_grl_2_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/get_edges.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\ntemplate <class T> struct Edge {\n    int from, to;\n \
    \   T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int to,\
    \ T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n    \
    \    // output format: \"{ id : from -> to, cost }\"\n        return os << \"\
    { \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \"\
    \ }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    graph/get_edges.hpp\"\n\ntemplate <class T> Edges<T> get_edges(Graph<T> &G) {\n\
    \    int N = (int)G.size(), M = 0;\n    for (int i = 0; i < N; i++) {\n      \
    \  for (auto &&e : G[i]) {\n            M = std::max(M, e.id + 1);\n        }\n\
    \    }\n    Edges<T> es(M);\n    for (int i = N - 1; i >= 0; i--) {\n        for\
    \ (auto &&e : G[i]) {\n            es[e.id] = e;\n        }\n    }\n    return\
    \ es;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> Edges<T> get_edges(Graph<T> &G) {\n    int N = (int)G.size(), M = 0;\n  \
    \  for (int i = 0; i < N; i++) {\n        for (auto &&e : G[i]) {\n          \
    \  M = std::max(M, e.id + 1);\n        }\n    }\n    Edges<T> es(M);\n    for\
    \ (int i = N - 1; i >= 0; i--) {\n        for (auto &&e : G[i]) {\n          \
    \  es[e.id] = e;\n        }\n    }\n    return es;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/get_edges.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2024-01-25 10:46:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_grl/aoj_grl_2_a.test.cpp
documentation_of: graph/get_edges.hpp
layout: document
redirect_from:
- /library/graph/get_edges.hpp
- /library/graph/get_edges.hpp.html
title: graph/get_edges.hpp
---
