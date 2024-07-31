---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/dijkstra.test.cpp
    title: verify/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter.test.cpp
    title: verify/graph/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/restore_path.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n\n// restore path from root[t] to t\nstd::vector<int> restore_path(std::vector<int>&\
    \ par, int t) {\n    std::vector<int> path = {t};\n    while (par[path.back()]\
    \ != -1) path.emplace_back(par[path.back()]);\n    std::reverse(path.begin(),\
    \ path.end());\n    return path;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\n// restore path\
    \ from root[t] to t\nstd::vector<int> restore_path(std::vector<int>& par, int\
    \ t) {\n    std::vector<int> path = {t};\n    while (par[path.back()] != -1) path.emplace_back(par[path.back()]);\n\
    \    std::reverse(path.begin(), path.end());\n    return path;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/restore_path.hpp
  requiredBy:
  - graph/tree_diameter.hpp
  timestamp: '2024-07-31 17:14:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/dijkstra.test.cpp
  - verify/graph/tree_diameter.test.cpp
documentation_of: graph/restore_path.hpp
layout: document
title: Restore path
---

## 使い方

$s$ から $t$ への最短路を

```cpp
Graph<T> g;
std::vector<int> s = {0};   // 始点の集合
const T INF;
auto [dist, par, root] = dijkstra(g, s, INF);
```

として求めた後に

```cpp
auto path = restore_path(par, t);
```

とすることで通った頂点の列を `s -> ... -> t` の順に `std::vector<int>` に格納して求める

## 参考文献

