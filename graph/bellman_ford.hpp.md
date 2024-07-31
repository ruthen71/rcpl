---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/bellman_ford.test.cpp
    title: verify/graph/bellman_ford.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bellman_ford.hpp\"\n\n#include <tuple>\n#line 2 \"\
    graph/graph_template.hpp\"\n\n#include <vector>\n#include <cassert>\n\ntemplate\
    \ <class T> struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\n   \
    \ Edge() = default;\n    Edge(const int from, const int to, const T cost = T(1),\
    \ const int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Edge<T>& e) {\n        // output\
    \ format: {id: cost(from, to) = cost}\n        return os << \"{\" << e.id << \"\
    : cost(\" << e.from << \", \" << e.to << \") = \" << e.cost << \"}\";\n    }\n\
    };\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\ntemplate <class\
    \ T> struct Graph {\n    struct EdgeIterators {\n       public:\n        using\
    \ Iterator = typename std::vector<Edge<T>>::iterator;\n        EdgeIterators()\
    \ = default;\n        EdgeIterators(const Iterator& begit, const Iterator& endit)\
    \ : begit(begit), endit(endit) {}\n        Iterator begin() const { return begit;\
    \ }\n        Iterator end() const { return endit; }\n        size_t size() const\
    \ { return std::distance(begit, endit); }\n        Edge<T>& operator[](int i)\
    \ const { return begit[i]; }\n\n       private:\n        Iterator begit, endit;\n\
    \    };\n\n    int n, m;\n    bool is_build, is_directed;\n    std::vector<Edge<T>>\
    \ edges;\n\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\u7528\n    std::vector<int>\
    \ start;\n    std::vector<Edge<T>> csr_edges;\n\n    Graph() = default;\n    Graph(const\
    \ int n, const bool directed = false) : n(n), m(0), is_build(false), is_directed(directed),\
    \ start(n + 1, 0) {}\n\n    // \u8FBA\u3092\u8FFD\u52A0\u3057, \u305D\u306E\u8FBA\
    \u304C\u4F55\u756A\u76EE\u306B\u8FFD\u52A0\u3055\u308C\u305F\u304B\u3092\u8FD4\
    \u3059\n    int add_edge(const int from, const int to, const T cost = T(1), int\
    \ id = -1) {\n        assert(!is_build);\n        assert(0 <= from and from <\
    \ n);\n        assert(0 <= to and to < n);\n        if (id == -1) id = m;\n  \
    \      edges.emplace_back(from, to, cost, id);\n        return m++;\n    }\n\n\
    \    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\n    void build()\
    \ {\n        assert(!is_build);\n        for (auto&& e : edges) {\n          \
    \  start[e.from + 1]++;\n            if (!is_directed) start[e.to + 1]++;\n  \
    \      }\n        for (int v = 0; v < n; v++) start[v + 1] += start[v];\n    \
    \    auto counter = start;\n        csr_edges.resize(start.back() + 1);\n    \
    \    for (auto&& e : edges) {\n            csr_edges[counter[e.from]++] = e;\n\
    \            if (!is_directed) csr_edges[counter[e.to]++] = Edge(e.to, e.from,\
    \ e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
    \ operator[](int i) {\n        if (!is_build) build();\n        return EdgeIterators(csr_edges.begin()\
    \ + start[i], csr_edges.begin() + start[i + 1]);\n    }\n\n    size_t size() const\
    \ { return (size_t)(n); }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, Graph<T>& g) {\n        os << \"[\";\n        for (int i = 0; i < g.size();\
    \ i++) {\n            os << \"[\";\n            for (int j = 0; j < g[i].size();\
    \ j++) {\n                os << g[i][j];\n                if (j + 1 != g[i].size())\
    \ os << \", \";\n            }\n            os << \"]\";\n            if (i +\
    \ 1 != g.size()) os << \", \";\n        }\n        return os << \"]\";\n    }\n\
    };\n#line 5 \"graph/bellman_ford.hpp\"\n\n// {dist, par, root}\ntemplate <class\
    \ T> std::tuple<std::vector<T>, std::vector<int>, std::vector<int>> bellman_ford(Graph<T>&\
    \ g, std::vector<int>& s, const T inf) {\n    const int n = (int)(g.size());\n\
    \    std::vector<T> dist(n, inf);\n    std::vector<int> par(n, -1), root(n, -1);\n\
    \n    for (auto&& v : s) {\n        dist[v] = 0;\n        root[v] = v;\n    }\n\
    \    int loop_count = 0;\n\n    while (true) {\n        loop_count++;\n      \
    \  bool update = false;\n        for (int cur = 0; cur < n; cur++) {\n       \
    \     if (dist[cur] == inf) continue;\n            for (auto&& e : g[cur]) {\n\
    \                T nd = std::max(-inf, dist[cur] + e.cost);\n                if\
    \ (dist[e.to] > nd) {\n                    par[e.to] = cur;\n                \
    \    root[e.to] = root[cur];\n                    update = true;\n           \
    \         if (loop_count >= n) nd = -inf;\n                    dist[e.to] = nd;\n\
    \                }\n            }\n        }\n        if (!update) break;\n  \
    \  }\n    return {dist, par, root};\n}\n"
  code: "#pragma once\n\n#include <tuple>\n#include \"graph/graph_template.hpp\"\n\
    \n// {dist, par, root}\ntemplate <class T> std::tuple<std::vector<T>, std::vector<int>,\
    \ std::vector<int>> bellman_ford(Graph<T>& g, std::vector<int>& s, const T inf)\
    \ {\n    const int n = (int)(g.size());\n    std::vector<T> dist(n, inf);\n  \
    \  std::vector<int> par(n, -1), root(n, -1);\n\n    for (auto&& v : s) {\n   \
    \     dist[v] = 0;\n        root[v] = v;\n    }\n    int loop_count = 0;\n\n \
    \   while (true) {\n        loop_count++;\n        bool update = false;\n    \
    \    for (int cur = 0; cur < n; cur++) {\n            if (dist[cur] == inf) continue;\n\
    \            for (auto&& e : g[cur]) {\n                T nd = std::max(-inf,\
    \ dist[cur] + e.cost);\n                if (dist[e.to] > nd) {\n             \
    \       par[e.to] = cur;\n                    root[e.to] = root[cur];\n      \
    \              update = true;\n                    if (loop_count >= n) nd = -inf;\n\
    \                    dist[e.to] = nd;\n                }\n            }\n    \
    \    }\n        if (!update) break;\n    }\n    return {dist, par, root};\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2024-07-31 16:51:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/bellman_ford.test.cpp
documentation_of: graph/bellman_ford.hpp
layout: document
title: "Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\
  )"
---

- 到達できない場合は `INF`
- 負閉路を使って小さくできる場合は `-INF`
- 多始点スタートに対応
- `s` に始点となる頂点を入れて、`auto [dist, par, root] = bellman_ford(G, s, INF);` で距離、親、始点が各頂点について得られる
