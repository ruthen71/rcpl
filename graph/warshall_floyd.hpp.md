---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/warshall_floyd.test.cpp
    title: verify/graph/warshall_floyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/warshall_floyd.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n\ntemplate <class T> struct Edge {\n\
    \    int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const\
    \ int from, const int to, const T cost = T(1), const int id = -1) : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend bool operator<(const Edge<T>& a,\
    \ const Edge<T>& b) { return a.cost < b.cost; }\n\n    friend std::ostream& operator<<(std::ostream&\
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
    \  std::vector<Edge<T>> edges;\n\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\
    \u7528\n    std::vector<int> start;\n    std::vector<Edge<T>> csr_edges;\n\n \
    \   Graph() = default;\n    Graph(const int n, const bool directed = false) :\
    \ n(n), m(0), is_build(false), is_directed(directed), start(n + 1, 0) {}\n\n \
    \   // \u8FBA\u3092\u8FFD\u52A0\u3057, \u305D\u306E\u8FBA\u304C\u4F55\u756A\u76EE\
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
    \ os, Graph<T>& g) {\n        os << \"[\";\n        for (int i = 0; i < (int)(g.size());\
    \ i++) {\n            os << \"[\";\n            for (int j = 0; j < (int)(g[i].size());\
    \ j++) {\n                os << g[i][j];\n                if (j + 1 != (int)(g[i].size()))\
    \ os << \", \";\n            }\n            os << \"]\";\n            if (i +\
    \ 1 != (int)(g.size())) os << \", \";\n        }\n        return os << \"]\";\n\
    \    }\n};\n#line 4 \"graph/warshall_floyd.hpp\"\n\ntemplate <class T> std::vector<std::vector<T>>\
    \ warshall_floyd(Graph<T>& g, const T inf) {\n    const int n = (int)(g.size());\n\
    \n    std::vector dist(n, std::vector<T>(n, inf));\n    for (int i = 0; i < n;\
    \ i++) {\n        dist[i][i] = 0;\n        for (auto&& e : g[i]) {\n         \
    \   dist[e.from][e.to] = std::min(dist[e.from][e.to], e.cost);\n        }\n  \
    \  }\n\n    for (int k = 0; k < n; k++) {\n        for (int i = 0; i < n; i++)\
    \ {\n            if (dist[i][k] == inf) continue;\n            for (int j = 0;\
    \ j < n; j++) {\n                if (dist[k][j] == inf) continue;\n          \
    \      dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n         \
    \   }\n        }\n    }\n\n    // \u8CA0\u9589\u8DEF\u691C\u51FA\n    for (int\
    \ i = 0; i < n; i++) {\n        if (dist[i][i] < 0) dist[i][i] = -inf;\n    }\n\
    \n    // \u8CA0\u9589\u8DEF\u3092\u3082\u3068\u306B\u5C0F\u3055\u304F\u3067\u304D\
    \u308B\u30D1\u30B9\u306B\u3064\u3044\u3066\u8ABF\u3079\u308B\n    for (int k =\
    \ 0; k < n; k++) {\n        for (int i = 0; i < n; i++) {\n            if (dist[i][k]\
    \ == inf) continue;\n            for (int j = 0; j < n; j++) {\n             \
    \   if (dist[k][j] == inf) continue;\n                T nd = dist[i][k] + dist[k][j];\n\
    \                if (dist[i][k] == -inf or dist[k][j] == -inf) nd = -inf;\n  \
    \              dist[i][j] = std::min(dist[i][j], nd);\n            }\n       \
    \ }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> std::vector<std::vector<T>> warshall_floyd(Graph<T>& g, const T inf) {\n\
    \    const int n = (int)(g.size());\n\n    std::vector dist(n, std::vector<T>(n,\
    \ inf));\n    for (int i = 0; i < n; i++) {\n        dist[i][i] = 0;\n       \
    \ for (auto&& e : g[i]) {\n            dist[e.from][e.to] = std::min(dist[e.from][e.to],\
    \ e.cost);\n        }\n    }\n\n    for (int k = 0; k < n; k++) {\n        for\
    \ (int i = 0; i < n; i++) {\n            if (dist[i][k] == inf) continue;\n  \
    \          for (int j = 0; j < n; j++) {\n                if (dist[k][j] == inf)\
    \ continue;\n                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \            }\n        }\n    }\n\n    // \u8CA0\u9589\u8DEF\u691C\u51FA\n  \
    \  for (int i = 0; i < n; i++) {\n        if (dist[i][i] < 0) dist[i][i] = -inf;\n\
    \    }\n\n    // \u8CA0\u9589\u8DEF\u3092\u3082\u3068\u306B\u5C0F\u3055\u304F\u3067\
    \u304D\u308B\u30D1\u30B9\u306B\u3064\u3044\u3066\u8ABF\u3079\u308B\n    for (int\
    \ k = 0; k < n; k++) {\n        for (int i = 0; i < n; i++) {\n            if\
    \ (dist[i][k] == inf) continue;\n            for (int j = 0; j < n; j++) {\n \
    \               if (dist[k][j] == inf) continue;\n                T nd = dist[i][k]\
    \ + dist[k][j];\n                if (dist[i][k] == -inf or dist[k][j] == -inf)\
    \ nd = -inf;\n                dist[i][j] = std::min(dist[i][j], nd);\n       \
    \     }\n        }\n    }\n    return dist;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2024-08-04 19:37:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/warshall_floyd.test.cpp
documentation_of: graph/warshall_floyd.hpp
layout: document
title: "Warshall-Floyd algorithm (\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\
  \u30C9\u6CD5)"
---

## 使い方

```cpp
Graph<T> g;
const T INF;
auto dist = warshall_floyd(g, INF);
```

`dist[i][j]` について
- 到達できない場合は `INF`
- 負閉路を使っていくらでも小さくできる場合は `-INF`

## 参考文献
