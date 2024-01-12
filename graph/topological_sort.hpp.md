---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Edge<T> &e) {\n        // output format:\
    \ \"{ id : from -> to, cost }\"\n        return os << \"{ \" << e.id << \" : \"\
    \ << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\n\
    template <class T> using Edges = std::vector<Edge<T>>;\ntemplate <class T> using\
    \ Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"graph/topological_sort.hpp\"\
    \ntemplate <class T> std::vector<int> topological_sort(Graph<T> &G) {\n    int\
    \ N = (int)G.size();\n    std::vector<int> indeg(N, 0);\n    for (int i = 0; i\
    \ < N; i++) {\n        for (auto &e : G[i]) indeg[e.to]++;\n    }\n    std::vector<int>\
    \ res;\n    for (int i = 0; i < N; i++) {\n        if (indeg[i] == 0) res.push_back(i);\n\
    \    }\n    int i = 0;\n    while (i < (int)res.size()) {\n        // determine\
    \ whether topological sort is unique or not\n        // or by checking the length\
    \ of G's longest path is N - 1\n        // if ((int)res.size() - i != 1) return\
    \ std::vector<int>();\n        int v = res[i];\n        i++;\n        for (auto\
    \ &e : G[v]) {\n            indeg[e.to]--;\n            if (indeg[e.to] == 0)\
    \ res.push_back(e.to);\n        }\n    }\n    if ((int)res.size() != N) {\n  \
    \      return std::vector<int>();\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\ntemplate <class T>\
    \ std::vector<int> topological_sort(Graph<T> &G) {\n    int N = (int)G.size();\n\
    \    std::vector<int> indeg(N, 0);\n    for (int i = 0; i < N; i++) {\n      \
    \  for (auto &e : G[i]) indeg[e.to]++;\n    }\n    std::vector<int> res;\n   \
    \ for (int i = 0; i < N; i++) {\n        if (indeg[i] == 0) res.push_back(i);\n\
    \    }\n    int i = 0;\n    while (i < (int)res.size()) {\n        // determine\
    \ whether topological sort is unique or not\n        // or by checking the length\
    \ of G's longest path is N - 1\n        // if ((int)res.size() - i != 1) return\
    \ std::vector<int>();\n        int v = res[i];\n        i++;\n        for (auto\
    \ &e : G[v]) {\n            indeg[e.to]--;\n            if (indeg[e.to] == 0)\
    \ res.push_back(e.to);\n        }\n    }\n    if ((int)res.size() != N) {\n  \
    \      return std::vector<int>();\n    }\n    return res;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2023-02-26 23:29:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_sort.hpp
layout: document
title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)"
---

- トポロジカルソートできない場合、空の配列を返す
