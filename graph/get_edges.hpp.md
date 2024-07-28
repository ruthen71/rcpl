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
    \n\n#include <vector>\n#include <cassert>\n\ntemplate <class T> struct Edge {\n\
    \    int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const\
    \ int from, const int to, const T cost = T(1), const int id = -1) : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Edge<T>& e) {\n        // output format: {id: cost(from, to) = cost}\n\
    \        return os << \"{\" << e.id << \": cost(\" << e.from << \", \" << e.to\
    \ << \") = \" << e.cost << \"}\";\n    }\n};\ntemplate <class T> using Edges =\
    \ std::vector<Edge<T>>;\n\ntemplate <class T> struct Graph {\n    struct EdgeIterators\
    \ {\n       public:\n        using Iterator = typename std::vector<Edge<T>>::iterator;\n\
    \        EdgeIterators() = default;\n        EdgeIterators(const Iterator& begit,\
    \ const Iterator& endit) : begit(begit), endit(endit) {}\n        Iterator begin()\
    \ const { return begit; }\n        Iterator end() const { return endit; }\n  \
    \      size_t size() const { return std::distance(begit, endit); }\n        Edge<T>&\
    \ operator[](int i) const { return begit[i]; }\n\n       private:\n        Iterator\
    \ begit, endit;\n    };\n\n    int n, m;\n    bool is_build, is_directed;\n  \
    \  std::vector<Edge<T>> edges;\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\
    \u7528\n    std::vector<int> start;\n    std::vector<Edge<T>> csr_edges;\n\n \
    \   Graph() : Graph(0) {}\n    Graph(const int n, const bool directed = false)\
    \ : n(n), m(0), is_build(false), start(n + 1, 0), is_directed(directed) {}\n\n\
    \    // \u8FBA\u3092\u8FFD\u52A0\u3057, \u305D\u306E\u8FBA\u304C\u4F55\u756A\u76EE\
    \u306B\u8FFD\u52A0\u3055\u308C\u305F\u304B\u3092\u8FD4\u3059\n    int add_edge(const\
    \ int from, const int to, const T cost = T(1), int id = -1) {\n        assert(!is_build);\n\
    \        assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n\
    \        if (id == -1) id = m;\n        edges.emplace_back(from, to, cost, id);\n\
    \        return m++;\n    }\n\n    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\
    \u3092\u69CB\u7BC9\n    void build() {\n        assert(!is_build);\n        for\
    \ (auto&& e : edges) {\n            start[e.from + 1]++;\n            if (!is_directed)\
    \ start[e.to + 1]++;\n        }\n        for (int v = 0; v < n; v++) start[v +\
    \ 1] += start[v];\n        auto counter = start;\n        csr_edges.resize(start.back()\
    \ + 1);\n        for (auto&& e : edges) {\n            csr_edges[counter[e.from]++]\
    \ = e;\n            if (!is_directed) csr_edges[counter[e.to]++] = Edge(e.to,\
    \ e.from, e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
    \ operator[](int i) {\n        if (!is_build) build();\n        return EdgeIterators(csr_edges.begin()\
    \ + start[i], csr_edges.begin() + start[i + 1]);\n    }\n\n    size_t size() const\
    \ { return (size_t)(n); }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, Graph<T>& g) {\n        // output format: {id: cost(from, to) = cost}\n\
    \        os << \"[\";\n        for (int i = 0; i < g.size(); i++) {\n        \
    \    os << \"[\";\n            for (int j = 0; j < g[i].size(); j++) {\n     \
    \           os << g[i][j];\n                if (j + 1 != g[i].size()) os << \"\
    , \";\n            }\n            os << \"]\";\n            if (i + 1 != g.size())\
    \ os << \", \";\n        }\n        return os << \"]\";\n    }\n};\n#line 4 \"\
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
  timestamp: '2024-07-28 20:02:10+09:00'
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
