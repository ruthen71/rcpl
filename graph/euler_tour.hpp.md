---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    // complexity: O(N + M)\n// N = 5\n// edges = [{0, 1}, {0, 2}, {2, 3}, {2, 4}]\n\
    //   0\n//  / \\\n// 1   2\n//    / \\\n//   3   4\n// vertices = [0, 1, 0, 2,\
    \ 3, 2, 4, 2, 0]\n// vertex_id = [{0, 8}, {1, 1}, {3, 7}, {4, 4}, {6, 6}]\n//\
    \ edges = [0, 0+N, 1, 2, 2+N, 3, 3+N, 1+N]\n// edge_id = [{0, 1}, {2, 7}, {3,\
    \ 4}, {5, 6}]\n// edges[vertex_id[i].first, vertex_id[i].second) = edges in subtree\
    \ with root i\ntemplate <class T> std::tuple<std::vector<int>, std::vector<std::pair<int,\
    \ int>>, std::vector<int>, std::vector<std::pair<int, int>>> euler_tour(Graph<T>&\
    \ g, const int root = 0) {\n    const int n = (int)(g.size());\n    std::vector<int>\
    \ vertices, edges;\n    std::vector<std::pair<int, int>> vertex_id(n), edge_id(n\
    \ - 1);\n    vertices.reserve(2 * n - 1);\n    edges.reserve(2 * (n - 1));\n\n\
    \    auto dfs = [&](auto f, int cur, int par) -> void {\n        vertex_id[cur].first\
    \ = (int)(vertices.size());\n        vertices.push_back(cur);\n        for (auto&&\
    \ e : g[cur]) {\n            if (e.to == par) continue;\n            edge_id[e.id].first\
    \ = (int)(edges.size());\n            edges.push_back(e.id);\n\n            f(f,\
    \ e.to, cur);\n            vertices.push_back(cur);\n\n            edge_id[e.id].second\
    \ = (int)(edges.size());\n            edges.push_back(e.id + n);\n        }\n\
    \        vertex_id[cur].second = (int)(vertices.size()) - 1;\n    };\n    dfs(dfs,\
    \ root, -1);\n\n    assert((int)(vertices.size()) == 2 * n - 1);\n    assert((int)(edges.size())\
    \ == 2 * (n - 1));\n    return {vertices, vertex_id, edges, edge_id};\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\n#include <tuple>\n\
    \n// Euler Tour\n// complexity: O(N + M)\n// N = 5\n// edges = [{0, 1}, {0, 2},\
    \ {2, 3}, {2, 4}]\n//   0\n//  / \\\n// 1   2\n//    / \\\n//   3   4\n// vertices\
    \ = [0, 1, 0, 2, 3, 2, 4, 2, 0]\n// vertex_id = [{0, 8}, {1, 1}, {3, 7}, {4, 4},\
    \ {6, 6}]\n// edges = [0, 0+N, 1, 2, 2+N, 3, 3+N, 1+N]\n// edge_id = [{0, 1},\
    \ {2, 7}, {3, 4}, {5, 6}]\n// edges[vertex_id[i].first, vertex_id[i].second) =\
    \ edges in subtree with root i\ntemplate <class T> std::tuple<std::vector<int>,\
    \ std::vector<std::pair<int, int>>, std::vector<int>, std::vector<std::pair<int,\
    \ int>>> euler_tour(Graph<T>& g, const int root = 0) {\n    const int n = (int)(g.size());\n\
    \    std::vector<int> vertices, edges;\n    std::vector<std::pair<int, int>> vertex_id(n),\
    \ edge_id(n - 1);\n    vertices.reserve(2 * n - 1);\n    edges.reserve(2 * (n\
    \ - 1));\n\n    auto dfs = [&](auto f, int cur, int par) -> void {\n        vertex_id[cur].first\
    \ = (int)(vertices.size());\n        vertices.push_back(cur);\n        for (auto&&\
    \ e : g[cur]) {\n            if (e.to == par) continue;\n            edge_id[e.id].first\
    \ = (int)(edges.size());\n            edges.push_back(e.id);\n\n            f(f,\
    \ e.to, cur);\n            vertices.push_back(cur);\n\n            edge_id[e.id].second\
    \ = (int)(edges.size());\n            edges.push_back(e.id + n);\n        }\n\
    \        vertex_id[cur].second = (int)(vertices.size()) - 1;\n    };\n    dfs(dfs,\
    \ root, -1);\n\n    assert((int)(vertices.size()) == 2 * n - 1);\n    assert((int)(edges.size())\
    \ == 2 * (n - 1));\n    return {vertices, vertex_id, edges, edge_id};\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/euler_tour.hpp
  requiredBy: []
  timestamp: '2024-07-31 21:19:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/euler_tour.hpp
layout: document
title: "Euler Tour (\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
---

## 使い方



## 使用例

- [ABC294 G](https://atcoder.jp/contests/abc294/submissions/39997126)

## 参考文献