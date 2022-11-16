---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: src/graph/graph_template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/kruskal.hpp
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
  bundledCode: "#line 2 \"src/graph/get_edges.hpp\"\n\n#line 2 \"src/graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"src/graph/get_edges.hpp\"\n\ntemplate <class T, class Graph> edges<T>\
    \ get_edges(Graph &G) {\n    int N = (int)G.size(), M = 0;\n    for (int i = 0;\
    \ i < N; i++) {\n        for (auto &&e : G[i]) {\n            M = std::max(M,\
    \ e.id + 1);\n        }\n    }\n    edges<T> es(M);\n    for (int i = N - 1; i\
    \ >= 0; i--) {\n        for (auto &&e : G[i]) {\n            es[e.id] = e;\n \
    \       }\n    }\n    return es;\n}\n"
  code: "#pragma once\n\n#include \"src/graph/graph_template.hpp\"\n\ntemplate <class\
    \ T, class Graph> edges<T> get_edges(Graph &G) {\n    int N = (int)G.size(), M\
    \ = 0;\n    for (int i = 0; i < N; i++) {\n        for (auto &&e : G[i]) {\n \
    \           M = std::max(M, e.id + 1);\n        }\n    }\n    edges<T> es(M);\n\
    \    for (int i = N - 1; i >= 0; i--) {\n        for (auto &&e : G[i]) {\n   \
    \         es[e.id] = e;\n        }\n    }\n    return es;\n}"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/get_edges.hpp
  requiredBy:
  - src/graph/kruskal.hpp
  timestamp: '2022-11-16 19:50:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_grl/aoj_grl_2_a.test.cpp
documentation_of: src/graph/get_edges.hpp
layout: document
redirect_from:
- /library/src/graph/get_edges.hpp
- /library/src/graph/get_edges.hpp.html
title: src/graph/get_edges.hpp
---
