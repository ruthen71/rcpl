---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: src/graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/topological_sort.md
    document_title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\
      \u30C8)"
    links: []
  bundledCode: "#line 2 \"src/graph/topological_sort.hpp\"\n\n#line 2 \"src/graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"src/graph/topological_sort.hpp\"\n\ntemplate <class Graph> std::vector<int>\
    \ topological_sort(Graph &G) {\n    int N = (int)G.size();\n    std::vector<int>\
    \ indeg(N, 0);\n    for (int i = 0; i < N; i++) {\n        for (auto &e : G[i])\
    \ indeg[e.to]++;\n    }\n    std::vector<int> res;\n    for (int i = 0; i < N;\
    \ i++) {\n        if (indeg[i] == 0) res.push_back(i);\n    }\n    int i = 0;\n\
    \    while (i < (int)res.size()) {\n        int v = res[i];\n        i++;\n  \
    \      for (auto &e : G[v]) {\n            indeg[e.to]--;\n            if (indeg[e.to]\
    \ == 0) res.push_back(e.to);\n        }\n    }\n    if ((int)res.size() != N)\
    \ {\n        return std::vector<int>();\n    }\n    return res;\n}\n\n/**\n *\
    \ @brief Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    )\n * @docs docs/graph/topological_sort.md\n */\n"
  code: "#pragma once\n\n#include \"src/graph/graph_template.hpp\"\n\ntemplate <class\
    \ Graph> std::vector<int> topological_sort(Graph &G) {\n    int N = (int)G.size();\n\
    \    std::vector<int> indeg(N, 0);\n    for (int i = 0; i < N; i++) {\n      \
    \  for (auto &e : G[i]) indeg[e.to]++;\n    }\n    std::vector<int> res;\n   \
    \ for (int i = 0; i < N; i++) {\n        if (indeg[i] == 0) res.push_back(i);\n\
    \    }\n    int i = 0;\n    while (i < (int)res.size()) {\n        int v = res[i];\n\
    \        i++;\n        for (auto &e : G[v]) {\n            indeg[e.to]--;\n  \
    \          if (indeg[e.to] == 0) res.push_back(e.to);\n        }\n    }\n    if\
    \ ((int)res.size() != N) {\n        return std::vector<int>();\n    }\n    return\
    \ res;\n}\n\n/**\n * @brief Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8)\n * @docs docs/graph/topological_sort.md\n */\n"
  dependsOn:
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2022-11-16 19:50:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/src/graph/topological_sort.hpp
- /library/src/graph/topological_sort.hpp.html
title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)"
---
- トポロジカルソートできない場合、空の配列を返す
