---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
    title: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  requiredBy: []
  timestamp: '2024-05-26 20:33:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
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
