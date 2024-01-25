---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/euler_tour.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\ntemplate <class T> struct Edge {\n    int from, to;\n \
    \   T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int to,\
    \ T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n    \
    \    // output format: \"{ id : from -> to, cost }\"\n        return os << \"\
    { \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \"\
    \ }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    graph/euler_tour.hpp\"\n\n// Euler Tour\n// complexity: O(N + M)\n// N = 5\n//\
    \ edges = [{0, 1}, {0, 2}, {2, 3}, {2, 4}]\n//   0\n//  / \\\n// 1   2\n//   \
    \ / \\\n//   3   4\n// vertices = [0, 1, 0, 2, 3, 2, 4, 2, 0]\n// vertex_id =\
    \ [{0, 8}, {1, 1}, {3, 7}, {4, 4}, {6, 6}]\n// edges = [0, 0+N, 1, 2, 2+N, 3,\
    \ 3+N, 1+N]\n// edge_id = [{0, 1}, {2, 7}, {3, 4}, {5, 6}]\n// edges[vertex_id[i].first,\
    \ vertex_id[i].second) = edges in subtree with root i\ntemplate <class T>\nstd::tuple<std::vector<int>,\
    \ std::vector<std::pair<int, int>>, std::vector<int>, std::vector<std::pair<int,\
    \ int>>>  //\neuler_tour(Graph<T> &G, int root = 0) {\n    // compiler bugs\n\
    \    // const int n = (int)G.size();\n    // fix\n    int n = (int)G.size();\n\
    \    std::vector<int> vertices, edges;\n    std::vector<std::pair<int, int>> vertex_id(n),\
    \ edge_id(n - 1);\n    vertices.reserve(2 * n - 1);\n    edges.reserve(2 * (n\
    \ - 1));\n\n    auto dfs = [&](auto f, int cur, int par) -> void {\n        vertex_id[cur].first\
    \ = (int)vertices.size();\n        vertices.push_back(cur);\n        for (auto\
    \ &&e : G[cur]) {\n            if (e.to == par) continue;\n            edge_id[e.id].first\
    \ = (int)edges.size();\n            edges.push_back(e.id);\n\n            f(f,\
    \ e.to, cur);\n            vertices.push_back(cur);\n\n            edge_id[e.id].second\
    \ = (int)edges.size();\n            edges.push_back(e.id + n);\n        }\n  \
    \      vertex_id[cur].second = (int)vertices.size() - 1;\n    };\n    dfs(dfs,\
    \ root, -1);\n\n    assert((int)vertices.size() == 2 * n - 1);\n    assert((int)edges.size()\
    \ == 2 * (n - 1));\n    return {vertices, vertex_id, edges, edge_id};\n}\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\n// Euler Tour\n\
    // complexity: O(N + M)\n// N = 5\n// edges = [{0, 1}, {0, 2}, {2, 3}, {2, 4}]\n\
    //   0\n//  / \\\n// 1   2\n//    / \\\n//   3   4\n// vertices = [0, 1, 0, 2,\
    \ 3, 2, 4, 2, 0]\n// vertex_id = [{0, 8}, {1, 1}, {3, 7}, {4, 4}, {6, 6}]\n//\
    \ edges = [0, 0+N, 1, 2, 2+N, 3, 3+N, 1+N]\n// edge_id = [{0, 1}, {2, 7}, {3,\
    \ 4}, {5, 6}]\n// edges[vertex_id[i].first, vertex_id[i].second) = edges in subtree\
    \ with root i\ntemplate <class T>\nstd::tuple<std::vector<int>, std::vector<std::pair<int,\
    \ int>>, std::vector<int>, std::vector<std::pair<int, int>>>  //\neuler_tour(Graph<T>\
    \ &G, int root = 0) {\n    // compiler bugs\n    // const int n = (int)G.size();\n\
    \    // fix\n    int n = (int)G.size();\n    std::vector<int> vertices, edges;\n\
    \    std::vector<std::pair<int, int>> vertex_id(n), edge_id(n - 1);\n    vertices.reserve(2\
    \ * n - 1);\n    edges.reserve(2 * (n - 1));\n\n    auto dfs = [&](auto f, int\
    \ cur, int par) -> void {\n        vertex_id[cur].first = (int)vertices.size();\n\
    \        vertices.push_back(cur);\n        for (auto &&e : G[cur]) {\n       \
    \     if (e.to == par) continue;\n            edge_id[e.id].first = (int)edges.size();\n\
    \            edges.push_back(e.id);\n\n            f(f, e.to, cur);\n        \
    \    vertices.push_back(cur);\n\n            edge_id[e.id].second = (int)edges.size();\n\
    \            edges.push_back(e.id + n);\n        }\n        vertex_id[cur].second\
    \ = (int)vertices.size() - 1;\n    };\n    dfs(dfs, root, -1);\n\n    assert((int)vertices.size()\
    \ == 2 * n - 1);\n    assert((int)edges.size() == 2 * (n - 1));\n    return {vertices,\
    \ vertex_id, edges, edge_id};\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/euler_tour.hpp
  requiredBy: []
  timestamp: '2024-01-25 10:46:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/euler_tour.hpp
layout: document
title: "Euler Tour (\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
---

## 使用例

- [ABC294 G](https://atcoder.jp/contests/abc294/submissions/39997126)
