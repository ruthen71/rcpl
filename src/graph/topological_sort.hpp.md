---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/graph/template.hpp
    title: src/graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj_other/aoj_0519.test.cpp
    title: verify/aoj_other/aoj_0519.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/topological_sort.md
    document_title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\
      \u30C8)"
    links: []
  bundledCode: "#line 2 \"src/graph/topological_sort.hpp\"\n\n#line 2 \"src/graph/template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to),\
    \ cost(cost), id(id) {}\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const edge<T> &e) {\n        // { id : from -> to, cost }\n        return os\
    \ << \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T, bool directed = false> struct graph\
    \ {\n    int N, M;\n    using cost_type = T;\n    using edge_type = edge<T>;\n\
    \    std::vector<std::vector<edge_type>> G;\n    std::vector<edge_type> es;\n\n\
    \    graph() : N(0), M(0) {}\n    graph(int N) : N(N), M(0), G(N) {}\n\n    constexpr\
    \ bool is_directed() { return directed; }\n\n    size_t size() const { return\
    \ G.size(); }\n\n    void read_tree(bool weight = false, int offset = 1) { read_graph(N\
    \ - 1, weight, offset); }\n\n    void read_graph(int _M, bool weight = false,\
    \ int offset = 1) {\n        es.reserve(_M);\n        for (int i = 0; i < _M;\
    \ i++) {\n            int a, b;\n            std::cin >> a >> b;\n           \
    \ a -= offset, b -= offset;\n            if (weight) {\n                T c;\n\
    \                std::cin >> c;\n                add_edge(a, b, c);\n        \
    \    } else {\n                add_edge(a, b);\n            }\n        }\n   \
    \ }\n\n    void read_parent(int offset = 1) {\n        es.reserve(N - 1);\n  \
    \      for (int i = 1; i < N; i++) {\n            int p;\n            std::cin\
    \ >> p;\n            p -= offset;\n            add_edge(i, p);\n        }\n  \
    \  }\n\n    void add_edge(const int &a, const int &b, T cost = 1) {\n        assert(0\
    \ <= a and a < N and 0 <= b and b < N);\n        if (!directed) G[b].push_back(edge_type(b,\
    \ a, cost, M));\n        G[a].push_back(edge_type(a, b, cost, M));\n        es.push_back(edge_type(a,\
    \ b, cost, M++));\n    }\n\n    inline std::vector<edge_type> &operator[](const\
    \ int &k) { return G[k]; }\n\n    inline const std::vector<edge_type> &operator[](const\
    \ int &k) const { return G[k]; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const graph<T, directed> &G) {\n        os << \"V: \" << G.N << \"\\nE:\
    \ \" << G.M << '\\n';\n        for (int v = 0; v < G.N; v++) {\n            os\
    \ << \"G[\" << v << \"] = [\";\n            for (auto &e : G[v]) os << e << \"\
    \ \";\n            os << \"]\\n\";\n        }\n        return os;\n    }\n};\n\
    #line 4 \"src/graph/topological_sort.hpp\"\n\ntemplate <class Graph> std::vector<int>\
    \ topological_sort(Graph &G) {\n    assert(G.is_directed());\n    int N = (int)G.size();\n\
    \    std::vector<int> indeg(N, 0);\n    for (int i = 0; i < N; i++) {\n      \
    \  for (auto &e : G[i]) indeg[e.to]++;\n    }\n    std::vector<int> res;\n   \
    \ for (int i = 0; i < N; i++) {\n        if (indeg[i] == 0) res.push_back(i);\n\
    \    }\n    int i = 0;\n    while (i < (int)res.size()) {\n        int v = res[i];\n\
    \        i++;\n        for (auto &e : G[v]) {\n            indeg[e.to]--;\n  \
    \          if (indeg[e.to] == 0) res.push_back(e.to);\n        }\n    }\n    if\
    \ ((int)res.size() != N) {\n        return std::vector<int>();\n    }\n    return\
    \ res;\n}\n\n/**\n * @brief Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8)\n * @docs docs/graph/topological_sort.md\n */\n"
  code: "#pragma once\n\n#include \"src/graph/template.hpp\"\n\ntemplate <class Graph>\
    \ std::vector<int> topological_sort(Graph &G) {\n    assert(G.is_directed());\n\
    \    int N = (int)G.size();\n    std::vector<int> indeg(N, 0);\n    for (int i\
    \ = 0; i < N; i++) {\n        for (auto &e : G[i]) indeg[e.to]++;\n    }\n   \
    \ std::vector<int> res;\n    for (int i = 0; i < N; i++) {\n        if (indeg[i]\
    \ == 0) res.push_back(i);\n    }\n    int i = 0;\n    while (i < (int)res.size())\
    \ {\n        int v = res[i];\n        i++;\n        for (auto &e : G[v]) {\n \
    \           indeg[e.to]--;\n            if (indeg[e.to] == 0) res.push_back(e.to);\n\
    \        }\n    }\n    if ((int)res.size() != N) {\n        return std::vector<int>();\n\
    \    }\n    return res;\n}\n\n/**\n * @brief Topological Sort (\u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)\n * @docs docs/graph/topological_sort.md\n\
    \ */\n"
  dependsOn:
  - src/graph/template.hpp
  isVerificationFile: false
  path: src/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2022-11-13 01:20:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj_other/aoj_0519.test.cpp
documentation_of: src/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/src/graph/topological_sort.hpp
- /library/src/graph/topological_sort.hpp.html
title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)"
---
- トポロジカルソートできない場合、空の配列を返す
