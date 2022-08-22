---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_unionfind.test.cpp
    title: verify/lc_data_structure/lc_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/unionfind.md
    document_title: UnionFind
    links: []
  bundledCode: "#line 2 \"src/data_structure/unionfind.hpp\"\n\nstruct unionfind {\n\
    \    std::vector<int> parents;\n\n    unionfind() {}\n    unionfind(int n) : parents(n,\
    \ -1) {}\n\n    int leader(int x) { return parents[x] < 0 ? x : parents[x] = leader(parents[x]);\
    \ }\n\n    bool merge(int x, int y) {\n        x = leader(x), y = leader(y);\n\
    \        if (x == y) return false;\n        if (parents[x] > parents[y]) std::swap(x,\
    \ y);\n        parents[x] += parents[y];\n        parents[y] = x;\n        return\
    \ true;\n    }\n\n    bool same(int x, int y) { return leader(x) == leader(y);\
    \ }\n\n    int size(int x) { return -parents[leader(x)]; }\n\n    void init(int\
    \ n) { parents.assign(n, -1); }  // reset\n};\n\n/**\n * @brief UnionFind\n *\
    \ @docs docs/data-structure/unionfind.md\n */\n"
  code: "#pragma once\n\nstruct unionfind {\n    std::vector<int> parents;\n\n   \
    \ unionfind() {}\n    unionfind(int n) : parents(n, -1) {}\n\n    int leader(int\
    \ x) { return parents[x] < 0 ? x : parents[x] = leader(parents[x]); }\n\n    bool\
    \ merge(int x, int y) {\n        x = leader(x), y = leader(y);\n        if (x\
    \ == y) return false;\n        if (parents[x] > parents[y]) std::swap(x, y);\n\
    \        parents[x] += parents[y];\n        parents[y] = x;\n        return true;\n\
    \    }\n\n    bool same(int x, int y) { return leader(x) == leader(y); }\n\n \
    \   int size(int x) { return -parents[leader(x)]; }\n\n    void init(int n) {\
    \ parents.assign(n, -1); }  // reset\n};\n\n/**\n * @brief UnionFind\n * @docs\
    \ docs/data-structure/unionfind.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/unionfind.hpp
  requiredBy: []
  timestamp: '2022-08-22 13:53:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_unionfind.test.cpp
documentation_of: src/data_structure/unionfind.hpp
layout: document
redirect_from:
- /library/src/data_structure/unionfind.hpp
- /library/src/data_structure/unionfind.hpp.html
title: UnionFind
---
