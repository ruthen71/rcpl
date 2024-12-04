---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal's algorithm (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/minimum_steiner_tree.hpp
    title: "Minimum Steiner Tree (\u6700\u5C0F\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\
      \u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/kruskal.test.cpp
    title: verify/graph/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/minimum_steiner_tree.test.cpp
    title: verify/graph/minimum_steiner_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_unionfind.test.cpp
    title: verify/lc_data_structure/lc_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/unionfind.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n\nstruct UnionFind {\n    int n;\n    std::vector<int> parents;\n\
    \n    UnionFind() {}\n    UnionFind(int n) : n(n), parents(n, -1) {}\n\n    int\
    \ leader(int x) { return parents[x] < 0 ? x : parents[x] = leader(parents[x]);\
    \ }\n\n    bool merge(int x, int y) {\n        x = leader(x), y = leader(y);\n\
    \        if (x == y) return false;\n        if (parents[x] > parents[y]) std::swap(x,\
    \ y);\n        parents[x] += parents[y];\n        parents[y] = x;\n        return\
    \ true;\n    }\n\n    bool same(int x, int y) { return leader(x) == leader(y);\
    \ }\n\n    int size(int x) { return -parents[leader(x)]; }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(n), group_size(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n    \
    \        group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(result.begin(), result.end(),\
    \ [&](const std::vector<int>& v) { return v.empty(); }), result.end());\n    \
    \    return result;\n    }\n\n    void init(int n) { parents.assign(n, -1); }\
    \  // reset\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nstruct UnionFind\
    \ {\n    int n;\n    std::vector<int> parents;\n\n    UnionFind() {}\n    UnionFind(int\
    \ n) : n(n), parents(n, -1) {}\n\n    int leader(int x) { return parents[x] <\
    \ 0 ? x : parents[x] = leader(parents[x]); }\n\n    bool merge(int x, int y) {\n\
    \        x = leader(x), y = leader(y);\n        if (x == y) return false;\n  \
    \      if (parents[x] > parents[y]) std::swap(x, y);\n        parents[x] += parents[y];\n\
    \        parents[y] = x;\n        return true;\n    }\n\n    bool same(int x,\
    \ int y) { return leader(x) == leader(y); }\n\n    int size(int x) { return -parents[leader(x)];\
    \ }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(n), group_size(n);\n        for (int i = 0; i < n; i++) {\n     \
    \       leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n      \
    \  }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(result.begin(), result.end(),\
    \ [&](const std::vector<int>& v) { return v.empty(); }), result.end());\n    \
    \    return result;\n    }\n\n    void init(int n) { parents.assign(n, -1); }\
    \  // reset\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/unionfind.hpp
  requiredBy:
  - graph/minimum_steiner_tree.hpp
  - graph/kruskal.hpp
  timestamp: '2024-07-31 17:25:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_unionfind.test.cpp
  - verify/graph/minimum_steiner_tree.test.cpp
  - verify/graph/kruskal.test.cpp
documentation_of: data_structure/unionfind.hpp
layout: document
title: UnionFind
---

UnionFind とは、うにおんふぁいんどのことである。
