---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/tree_diameter.hpp
    title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/graph/dijkstra.test.cpp
    title: verify/graph/dijkstra.test.cpp
  - icon: ':x:'
    path: verify/graph/tree_diameter.test.cpp
    title: verify/graph/tree_diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/restore_path.hpp\"\n\n#include <vector>\n// restore\
    \ path from root[t] to t\nstd::vector<int> restore_path(std::vector<int>& par,\
    \ int t) {\n    std::vector<int> path = {t};\n    while (par[path.back()] != -1)\
    \ path.emplace_back(par[path.back()]);\n    std::reverse(path.begin(), path.end());\n\
    \    return path;\n}\n"
  code: "#pragma once\n\n#include <vector>\n// restore path from root[t] to t\nstd::vector<int>\
    \ restore_path(std::vector<int>& par, int t) {\n    std::vector<int> path = {t};\n\
    \    while (par[path.back()] != -1) path.emplace_back(par[path.back()]);\n   \
    \ std::reverse(path.begin(), path.end());\n    return path;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/restore_path.hpp
  requiredBy:
  - graph/tree_diameter.hpp
  timestamp: '2024-05-26 20:33:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/graph/dijkstra.test.cpp
  - verify/graph/tree_diameter.test.cpp
documentation_of: graph/restore_path.hpp
layout: document
title: Restore path
---

$s$ から $t$ への最短路を

```cpp
int n;
Graph<T> g(n);
auto [d, p, r] = dijkstra(g, s, INF);
```

として求めた後に

```cpp
auto path = restore_path(p, t);
```

とすることで通った頂点の列を `s -> ... -> t` の順に `std::vector<int>` に格納して求める
