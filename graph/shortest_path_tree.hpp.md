---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc252/tasks/abc252_e
  bundledCode: "#line 2 \"graph/shortest_path_tree.hpp\"\n\n#include <vector>\n\n\
    // https://atcoder.jp/contests/abc252/tasks/abc252_e\ntemplate <class T> std::vector<int>\
    \ shortest_path_tree(Graph<T>& g, std::vector<int>& par) {\n    const int n =\
    \ (int)(g.size());\n    std::map<std::pair<int, int>, int> mp;\n    for (int i\
    \ = 0; i < n; i++) {\n        for (auto& e : g[i]) {\n            mp[{e.from,\
    \ e.to}] = e.id;\n        }\n    }\n    std::vector<int> res;\n    res.reserve(n\
    \ - 1);\n    for (int i = 0; i < n; i++) {\n        if (par[i] != -1) {\n    \
    \        res.push_back(mp[{par[i], i}]);\n        }\n    }\n    assert(int(res.size())\
    \ == n - 1);\n    return res;\n}\n"
  code: "#pragma once\n\n#include <vector>\n\n// https://atcoder.jp/contests/abc252/tasks/abc252_e\n\
    template <class T> std::vector<int> shortest_path_tree(Graph<T>& g, std::vector<int>&\
    \ par) {\n    const int n = (int)(g.size());\n    std::map<std::pair<int, int>,\
    \ int> mp;\n    for (int i = 0; i < n; i++) {\n        for (auto& e : g[i]) {\n\
    \            mp[{e.from, e.to}] = e.id;\n        }\n    }\n    std::vector<int>\
    \ res;\n    res.reserve(n - 1);\n    for (int i = 0; i < n; i++) {\n        if\
    \ (par[i] != -1) {\n            res.push_back(mp[{par[i], i}]);\n        }\n \
    \   }\n    assert(int(res.size()) == n - 1);\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path_tree.hpp
  requiredBy: []
  timestamp: '2024-07-28 21:56:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path_tree.hpp
layout: document
title: "Shortest Path Tree (\u6700\u77ED\u7D4C\u8DEF\u6728)"
---

- 01-BFSやDijkstraやBellman-Fordでparを求めた後に使う
- 辺番号のリストを返す

## 使用例
- [ABC252 F](https://atcoder.jp/contests/abc252/submissions/46239094)
