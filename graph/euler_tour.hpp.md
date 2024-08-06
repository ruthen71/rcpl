---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/euler_tour.test.cpp
    title: verify/graph/euler_tour.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/euler_tour.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
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
    \    }\n};\n#line 4 \"graph/euler_tour.hpp\"\n\n#include <tuple>\n\n// Euler Tour\n\
    // O(n + m)\n// \u8FBA\u3068\u9802\u70B9\u306E\u3046\u3061, \u5909\u5316\u3055\
    \u305B\u308B\u3082\u306E\u3092\u8981\u7D20\u3068\u898B\u3066, \u305D\u3046\u3067\
    \u306A\u3044\u3082\u306E\u3067\u8981\u7D20\u3092\u533A\u5207\u308B\u3068\u8003\
    \u3048\u308B\u3068\u826F\u3044\ntemplate <class T> struct EulerTour {\n    int\
    \ n;\n    std::vector<int> vertices;  // DFS \u3067\u8A2A\u554F\u3059\u308B\u9802\
    \u70B9\u306E\u756A\u53F7\u3092\u4E26\u3079\u305F\u3082\u306E, 2 * n - 1 \u8981\
    \u7D20\n    std::vector<int> edges;     // DFS \u3067\u901A\u308B\u8FBA\u306E\u756A\
    \u53F7\u3092\u4E26\u3079\u305F\u3082\u306E, 2 * n - 2 \u8981\u7D20\n    std::vector<int>\
    \ dir;       // DFS \u3067\u901A\u308B\u8FBA\u306E\u5411\u304D\u304C 0 = \u5B50\
    \u4F9B\u65B9\u5411, 1 = \u89AA\u65B9\u5411\n    std::vector<int> vsl;       //\
    \ vsl[v]: vertices[i] = v \u3068\u306A\u308B i \u306E\u6700\u5C0F\u5024\n    std::vector<int>\
    \ vsr;       // vsr[v]: vertices[i] = v \u3068\u306A\u308B i \u306E\u6700\u5927\
    \u5024\n    std::vector<int> esl;       // esl[e]: edges[i] = e \u304B\u3064 dir[i]\
    \ = 0 \u3068\u306A\u308B i\n    std::vector<int> esr;       // esr[e]: edges[i]\
    \ = e \u304B\u3064 dir[i] = 1 \u3068\u306A\u308B i\n\n    EulerTour(Graph<T>&\
    \ g, const int root = 0) : n((int)(g.size())), vsl(n, 2 * n - 1), vsr(n, -1),\
    \ esl(n - 1, -1), esr(n - 1, -1) {\n        vertices.reserve(2 * n - 1);\n   \
    \     edges.reserve(2 * n - 2);\n        dir.reserve(2 * n - 2);\n\n        auto\
    \ dfs = [&](auto f, int cur, int par) -> void {\n            for (auto&& e : g[cur])\
    \ {\n                if (e.to == par) continue;\n                // \u9802\u70B9\
    \u3092\u8FFD\u52A0\n                vertices.emplace_back(cur);\n            \
    \    // \u5B50\u4F9B\u65B9\u5411\u306E\u8FBA\u3092\u8FFD\u52A0\n             \
    \   edges.emplace_back(e.id);\n                dir.emplace_back(0);\n        \
    \        // DFS\n                f(f, e.to, cur);\n                // \u89AA\u65B9\
    \u5411\u306E\u8FBA\u3092\u8FFD\u52A0\n                edges.emplace_back(e.id);\n\
    \                dir.emplace_back(1);\n            }\n            // \u9802\u70B9\
    \u3092\u8FFD\u52A0\n            vertices.emplace_back(cur);\n        };\n    \
    \    dfs(dfs, root, -1);\n        for (int i = 2 * n - 2; i >= 0; i--) vsl[vertices[i]]\
    \ = i;\n        for (int i = 0; i < 2 * n - 1; i++) vsr[vertices[i]] = i;\n  \
    \      for (int i = 0; i < 2 * n - 2; i++) (dir[i] == 0 ? esl[edges[i]] : esr[edges[i]])\
    \ = i;\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\n#include <tuple>\n\
    \n// Euler Tour\n// O(n + m)\n// \u8FBA\u3068\u9802\u70B9\u306E\u3046\u3061, \u5909\
    \u5316\u3055\u305B\u308B\u3082\u306E\u3092\u8981\u7D20\u3068\u898B\u3066, \u305D\
    \u3046\u3067\u306A\u3044\u3082\u306E\u3067\u8981\u7D20\u3092\u533A\u5207\u308B\
    \u3068\u8003\u3048\u308B\u3068\u826F\u3044\ntemplate <class T> struct EulerTour\
    \ {\n    int n;\n    std::vector<int> vertices;  // DFS \u3067\u8A2A\u554F\u3059\
    \u308B\u9802\u70B9\u306E\u756A\u53F7\u3092\u4E26\u3079\u305F\u3082\u306E, 2 *\
    \ n - 1 \u8981\u7D20\n    std::vector<int> edges;     // DFS \u3067\u901A\u308B\
    \u8FBA\u306E\u756A\u53F7\u3092\u4E26\u3079\u305F\u3082\u306E, 2 * n - 2 \u8981\
    \u7D20\n    std::vector<int> dir;       // DFS \u3067\u901A\u308B\u8FBA\u306E\u5411\
    \u304D\u304C 0 = \u5B50\u4F9B\u65B9\u5411, 1 = \u89AA\u65B9\u5411\n    std::vector<int>\
    \ vsl;       // vsl[v]: vertices[i] = v \u3068\u306A\u308B i \u306E\u6700\u5C0F\
    \u5024\n    std::vector<int> vsr;       // vsr[v]: vertices[i] = v \u3068\u306A\
    \u308B i \u306E\u6700\u5927\u5024\n    std::vector<int> esl;       // esl[e]:\
    \ edges[i] = e \u304B\u3064 dir[i] = 0 \u3068\u306A\u308B i\n    std::vector<int>\
    \ esr;       // esr[e]: edges[i] = e \u304B\u3064 dir[i] = 1 \u3068\u306A\u308B\
    \ i\n\n    EulerTour(Graph<T>& g, const int root = 0) : n((int)(g.size())), vsl(n,\
    \ 2 * n - 1), vsr(n, -1), esl(n - 1, -1), esr(n - 1, -1) {\n        vertices.reserve(2\
    \ * n - 1);\n        edges.reserve(2 * n - 2);\n        dir.reserve(2 * n - 2);\n\
    \n        auto dfs = [&](auto f, int cur, int par) -> void {\n            for\
    \ (auto&& e : g[cur]) {\n                if (e.to == par) continue;\n        \
    \        // \u9802\u70B9\u3092\u8FFD\u52A0\n                vertices.emplace_back(cur);\n\
    \                // \u5B50\u4F9B\u65B9\u5411\u306E\u8FBA\u3092\u8FFD\u52A0\n \
    \               edges.emplace_back(e.id);\n                dir.emplace_back(0);\n\
    \                // DFS\n                f(f, e.to, cur);\n                //\
    \ \u89AA\u65B9\u5411\u306E\u8FBA\u3092\u8FFD\u52A0\n                edges.emplace_back(e.id);\n\
    \                dir.emplace_back(1);\n            }\n            // \u9802\u70B9\
    \u3092\u8FFD\u52A0\n            vertices.emplace_back(cur);\n        };\n    \
    \    dfs(dfs, root, -1);\n        for (int i = 2 * n - 2; i >= 0; i--) vsl[vertices[i]]\
    \ = i;\n        for (int i = 0; i < 2 * n - 1; i++) vsr[vertices[i]] = i;\n  \
    \      for (int i = 0; i < 2 * n - 2; i++) (dir[i] == 0 ? esl[edges[i]] : esr[edges[i]])\
    \ = i;\n    }\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/euler_tour.hpp
  requiredBy: []
  timestamp: '2024-08-06 14:48:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/euler_tour.test.cpp
documentation_of: graph/euler_tour.hpp
layout: document
title: "Euler Tour (\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
---

## 使い方

```cpp
Graph<int> g;
EulerTour et(g);
// et.vertices, et.edges, et.dir, et.vsl, et.vsr, et.esl, et.esr が利用可能
```

$ N = 5 $ 頂点の木で辺が $ E = \left( \lbrace 0, 1\rbrace, \lbrace 0, 2\rbrace, \lbrace2, 3\rbrace, \lbrace 2, 4\rbrace \right) $ である場合は以下のようになる


```txt
   0
  / \
 1   2
    / \
   3   4
vertices = [0, 1, 0, 2, 3, 2, 4, 2, 0]
edges    =  [0, 0, 1, 2, 2, 3, 3, 1]
dir      =  [0, 1, 0, 0, 1, 0, 1, 1]
vsl      = [0, 1, 3, 4, 6]
vsr      = [8, 1, 7, 4, 6]
esl      = [0, 2, 3, 5]
esr      = [1, 7, 4, 6]
```

## 参考文献
