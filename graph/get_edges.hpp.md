---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"graph/get_edges.hpp\"\n\ntemplate <class T, class Graph> edges<T> get_edges(Graph\
    \ &G) {\n    int N = (int)G.size(), M = 0;\n    for (int i = 0; i < N; i++) {\n\
    \        for (auto &&e : G[i]) {\n            M = std::max(M, e.id + 1);\n   \
    \     }\n    }\n    edges<T> es(M);\n    for (int i = N - 1; i >= 0; i--) {\n\
    \        for (auto &&e : G[i]) {\n            es[e.id] = e;\n        }\n    }\n\
    \    return es;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T, class Graph> edges<T> get_edges(Graph &G) {\n    int N = (int)G.size(), M\
    \ = 0;\n    for (int i = 0; i < N; i++) {\n        for (auto &&e : G[i]) {\n \
    \           M = std::max(M, e.id + 1);\n        }\n    }\n    edges<T> es(M);\n\
    \    for (int i = N - 1; i >= 0; i--) {\n        for (auto &&e : G[i]) {\n   \
    \         es[e.id] = e;\n        }\n    }\n    return es;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/get_edges.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2023-02-06 17:52:27+09:00'
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
