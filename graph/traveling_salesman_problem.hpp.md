---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/traveling_salesman_problem.test.cpp
    title: verify/graph/traveling_salesman_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/traveling_salesman_problem.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\ntemplate <class T> struct Edge {\n\
    \    int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const\
    \ int from, const int to, const T cost = T(1), const int id = -1)\n        : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend bool operator<(const Edge<T>& a,\
    \ const Edge<T>& b) {\n        return a.cost < b.cost;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Edge<T>& e) {\n        // output format:\
    \ {id: cost(from, to) = cost}\n        return os << \"{\" << e.id << \": cost(\"\
    \ << e.from << \", \" << e.to\n                  << \") = \" << e.cost << \"}\"\
    ;\n    }\n};\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\ntemplate\
    \ <class T> struct Graph {\n    struct EdgeIterators {\n      public:\n      \
    \  using Iterator = typename std::vector<Edge<T>>::iterator;\n        EdgeIterators()\
    \ = default;\n        EdgeIterators(const Iterator& begit, const Iterator& endit)\n\
    \            : begit(begit), endit(endit) {}\n        Iterator begin() const {\
    \ return begit; }\n        Iterator end() const { return endit; }\n        size_t\
    \ size() const { return std::distance(begit, endit); }\n        Edge<T>& operator[](int\
    \ i) const { return begit[i]; }\n\n      private:\n        Iterator begit, endit;\n\
    \    };\n\n    int n, m;\n    bool is_build, is_directed;\n    std::vector<Edge<T>>\
    \ edges;\n\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\u7528\n    std::vector<int>\
    \ start;\n    std::vector<Edge<T>> csr_edges;\n\n    Graph() = default;\n    Graph(const\
    \ int n, const bool directed = false)\n        : n(n), m(0), is_build(false),\
    \ is_directed(directed), start(n + 1, 0) {}\n\n    // \u8FBA\u3092\u8FFD\u52A0\
    \u3057, \u305D\u306E\u8FBA\u304C\u4F55\u756A\u76EE\u306B\u8FFD\u52A0\u3055\u308C\
    \u305F\u304B\u3092\u8FD4\u3059\n    int add_edge(const int from,\n           \
    \      const int to,\n                 const T cost = T(1),\n                \
    \ int id = -1) {\n        assert(!is_build);\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        if (id == -1) id = m;\n\
    \        edges.emplace_back(from, to, cost, id);\n        return m++;\n    }\n\
    \n    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\n    void\
    \ build() {\n        assert(!is_build);\n        for (auto&& e : edges) {\n  \
    \          start[e.from + 1]++;\n            if (!is_directed) start[e.to + 1]++;\n\
    \        }\n        for (int v = 0; v < n; v++) start[v + 1] += start[v];\n  \
    \      auto counter = start;\n        csr_edges.resize(start.back() + 1);\n  \
    \      for (auto&& e : edges) {\n            csr_edges[counter[e.from]++] = e;\n\
    \            if (!is_directed)\n                csr_edges[counter[e.to]++] = Edge(e.to,\
    \ e.from, e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
    \ operator[](int i) {\n        if (!is_build) build();\n        return EdgeIterators(csr_edges.begin()\
    \ + start[i],\n                             csr_edges.begin() + start[i + 1]);\n\
    \    }\n\n    size_t size() const { return (size_t)(n); }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, Graph<T>& g) {\n        os << \"[\";\n        for\
    \ (int i = 0; i < (int)(g.size()); i++) {\n            os << \"[\";\n        \
    \    for (int j = 0; j < (int)(g[i].size()); j++) {\n                os << g[i][j];\n\
    \                if (j + 1 != (int)(g[i].size())) os << \", \";\n            }\n\
    \            os << \"]\";\n            if (i + 1 != (int)(g.size())) os << \"\
    , \";\n        }\n        return os << \"]\";\n    }\n};\n#line 4 \"graph/traveling_salesman_problem.hpp\"\
    \n\ntemplate <class T> std::vector<std::vector<T>> traveling_salesman_problem(Graph<T>&\
    \ g, const T inf) {\n    const int n = (int)(g.size());\n    const int n2 = 1\
    \ << n;\n\n    std::vector dp(n2, std::vector<T>(n, inf));\n    dp[0][0] = 0;\n\
    \    for (int bit = 0; bit < n2; bit++) {\n        for (int u = 0; u < n; u++)\
    \ {\n            if (dp[bit][u] == inf) continue;\n            for (auto&& e :\
    \ g[u]) {\n                if (bit >> e.to & 1) continue;\n                dp[bit\
    \ | (1 << e.to)][e.to] = std::min(dp[bit | (1 << e.to)][e.to], dp[bit][u] + e.cost);\n\
    \            }\n        }\n    }\n    return dp;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\ntemplate <class\
    \ T> std::vector<std::vector<T>> traveling_salesman_problem(Graph<T>& g, const\
    \ T inf) {\n    const int n = (int)(g.size());\n    const int n2 = 1 << n;\n\n\
    \    std::vector dp(n2, std::vector<T>(n, inf));\n    dp[0][0] = 0;\n    for (int\
    \ bit = 0; bit < n2; bit++) {\n        for (int u = 0; u < n; u++) {\n       \
    \     if (dp[bit][u] == inf) continue;\n            for (auto&& e : g[u]) {\n\
    \                if (bit >> e.to & 1) continue;\n                dp[bit | (1 <<\
    \ e.to)][e.to] = std::min(dp[bit | (1 << e.to)][e.to], dp[bit][u] + e.cost);\n\
    \            }\n        }\n    }\n    return dp;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/traveling_salesman_problem.hpp
  requiredBy: []
  timestamp: '2026-01-20 04:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/traveling_salesman_problem.test.cpp
documentation_of: graph/traveling_salesman_problem.hpp
layout: document
title: "Traveling Salesman Problem (\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\
  \u554F\u984C)"
---

## 使い方

```cpp
Graph<T> g;
const T INF;
auto res = traveling_salesman_problem<T>(g, INF);
// res.back()[0] が 答え
```

初期化

- 最短ハミルトン閉路問題 (= TSP) の場合
    - 始点は任意
    - 始点を `s` とすると、「まだどこにも行ってないけど `s` にいる」ので `dp[0][s] = 0`
- 最短ハミルトン路問題の場合
    - 始点を `s` とすると、「 `s` は訪問済みと考えて良い」ので `dp[1 << s][s] = 0`

## 参考文献
