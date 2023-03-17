---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal's algorithm (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_grl/aoj_grl_2_a.test.cpp
    title: verify/aoj_grl/aoj_grl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_unionfind.test.cpp
    title: verify/lc_data_structure/lc_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/unionfind.hpp\"\n\nstruct UnionFind {\n \
    \   std::vector<int> parents;\n\n    UnionFind() {}\n    UnionFind(int n) : parents(n,\
    \ -1) {}\n\n    int leader(int x) { return parents[x] < 0 ? x : parents[x] = leader(parents[x]);\
    \ }\n\n    bool merge(int x, int y) {\n        x = leader(x), y = leader(y);\n\
    \        if (x == y) return false;\n        if (parents[x] > parents[y]) std::swap(x,\
    \ y);\n        parents[x] += parents[y];\n        parents[y] = x;\n        return\
    \ true;\n    }\n\n    bool same(int x, int y) { return leader(x) == leader(y);\
    \ }\n\n    int size(int x) { return -parents[leader(x)]; }\n\n    void init(int\
    \ n) { parents.assign(n, -1); }  // reset\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n    std::vector<int> parents;\n\n   \
    \ UnionFind() {}\n    UnionFind(int n) : parents(n, -1) {}\n\n    int leader(int\
    \ x) { return parents[x] < 0 ? x : parents[x] = leader(parents[x]); }\n\n    bool\
    \ merge(int x, int y) {\n        x = leader(x), y = leader(y);\n        if (x\
    \ == y) return false;\n        if (parents[x] > parents[y]) std::swap(x, y);\n\
    \        parents[x] += parents[y];\n        parents[y] = x;\n        return true;\n\
    \    }\n\n    bool same(int x, int y) { return leader(x) == leader(y); }\n\n \
    \   int size(int x) { return -parents[leader(x)]; }\n\n    void init(int n) {\
    \ parents.assign(n, -1); }  // reset\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/unionfind.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_grl/aoj_grl_2_a.test.cpp
  - verify/lc_data_structure/lc_unionfind.test.cpp
documentation_of: data_structure/unionfind.hpp
layout: document
title: UnionFind
---

UnionFind とは、うにおんふぁいんどのことである。
