---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/topological_sort_1.test.cpp
    title: verify/graph/topological_sort_1.test.cpp
  - icon: ':x:'
    path: verify/graph/topological_sort_2.test.cpp
    title: verify/graph/topological_sort_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
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
    \    }\n};\n#line 4 \"graph/topological_sort.hpp\"\n\n#line 6 \"graph/topological_sort.hpp\"\
    \n#include <queue>\n\n// topological sort \u304C\u5B58\u5728\u3059\u308B\u306A\
    \u3089, \u8F9E\u66F8\u9806\u6700\u5C0F\u306E\u3082\u306E\u3092\u8FD4\u3059\n//\
    \ O((n + m) log n)\n// topological sort \u304C\u4E00\u610F\u306B\u5B9A\u307E\u308B\
    \ <=> \u6700\u9577\u30D1\u30B9\u306E\u9577\u3055\u304C n - 1\ntemplate <class\
    \ T> std::vector<int> topological_sort(Graph<T>& g) {\n    const int n = (int)(g.size());\n\
    \    assert(n > 0);\n    std::vector<int> indeg(n, 0);\n    for (int i = 0; i\
    \ < n; i++) {\n        for (auto&& e : g[i]) indeg[e.to]++;\n    }\n    // O(n\
    \ + m) \u306B\u3057\u305F\u3044\u5834\u5408\u306F std::queue \u306B\u3059\u308B\
    \n    std::priority_queue<int, std::vector<int>, std::greater<>> que;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (indeg[i] == 0) {\n            que.push(i);\n\
    \        }\n    }\n    std::vector<int> res;\n    while (!que.empty()) {\n   \
    \     auto v = que.top();\n        que.pop();\n        res.push_back(v);\n   \
    \     for (auto&& e : g[v]) {\n            indeg[e.to]--;\n            if (indeg[e.to]\
    \ == 0) que.push(e.to);\n        }\n    }\n    // topological sort \u3067\u304D\
    \u306A\u3044\n    if ((int)(res.size()) != n) {\n        return std::vector<int>();\n\
    \    }\n    return res;\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\n#include <cassert>\n\
    #include <queue>\n\n// topological sort \u304C\u5B58\u5728\u3059\u308B\u306A\u3089\
    , \u8F9E\u66F8\u9806\u6700\u5C0F\u306E\u3082\u306E\u3092\u8FD4\u3059\n// O((n\
    \ + m) log n)\n// topological sort \u304C\u4E00\u610F\u306B\u5B9A\u307E\u308B\
    \ <=> \u6700\u9577\u30D1\u30B9\u306E\u9577\u3055\u304C n - 1\ntemplate <class\
    \ T> std::vector<int> topological_sort(Graph<T>& g) {\n    const int n = (int)(g.size());\n\
    \    assert(n > 0);\n    std::vector<int> indeg(n, 0);\n    for (int i = 0; i\
    \ < n; i++) {\n        for (auto&& e : g[i]) indeg[e.to]++;\n    }\n    // O(n\
    \ + m) \u306B\u3057\u305F\u3044\u5834\u5408\u306F std::queue \u306B\u3059\u308B\
    \n    std::priority_queue<int, std::vector<int>, std::greater<>> que;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (indeg[i] == 0) {\n            que.push(i);\n\
    \        }\n    }\n    std::vector<int> res;\n    while (!que.empty()) {\n   \
    \     auto v = que.top();\n        que.pop();\n        res.push_back(v);\n   \
    \     for (auto&& e : g[v]) {\n            indeg[e.to]--;\n            if (indeg[e.to]\
    \ == 0) que.push(e.to);\n        }\n    }\n    // topological sort \u3067\u304D\
    \u306A\u3044\n    if ((int)(res.size()) != n) {\n        return std::vector<int>();\n\
    \    }\n    return res;\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-08-05 02:15:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/graph/topological_sort_2.test.cpp
  - verify/graph/topological_sort_1.test.cpp
documentation_of: graph/topological_sort.hpp
layout: document
title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)"
---

## 使い方

```cpp
Graph<int> g;
auto vec = topological_sort(g);
```

トポロジカルソートできない場合、空の配列を返す

## 参考文献
