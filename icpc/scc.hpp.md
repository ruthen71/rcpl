---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/template.hpp
    title: icpc/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_2748.test.cpp
    title: verify/aoj_other/aoj_2748.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2748
  bundledCode: "#line 2 \"icpc/scc.hpp\"\n\n#line 2 \"icpc/template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n#define REP(i,\
    \ n) for (int i = 0; i < (n); i++)\ntemplate <class T> using V = vector<T>;\n\
    template <class T> ostream& operator<<(ostream& os, const V<T>& v) {\n    os <<\
    \ \"[ \";\n    for (auto& vi : v) os << vi << \", \";\n    return os << \"]\"\
    ;\n}\n\n#ifdef LOCAL\n#define show(x) cerr << __LINE__ << \" : \" << #x << \"\
    \ = \" << x << endl;\n#else\n#define show(x) true\n#endif\n\nusing uint = unsigned\
    \ int;\nusing ull = unsigned long long;\n\n// g++ -g -fsanitize=undefined,address\
    \ -DLOCAL -std=gnu++17\n#line 4 \"icpc/scc.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/2748\n\
    \nV<V<int>> scc(V<V<int>>& g) {\n    int n = int(g.size());\n    int now_ord =\
    \ 0, group_num = 0;\n    V<int> vis, low(n), ord(n, -1), ids(n);\n    vis.reserve(n);\n\
    \    auto dfs = [&](auto f, int c) -> void {\n        low[c] = ord[c] = now_ord++;\n\
    \        vis.push_back(c);\n        for (auto& e : g[c]) {\n            if (ord[e]\
    \ == -1) {\n                f(f, e);\n                low[c] = min(low[c], low[e]);\n\
    \            } else {\n                low[c] = min(low[c], ord[e]);\n       \
    \     }\n        }\n        if (low[c] == ord[c]) {\n            while (true)\
    \ {\n                int u = vis.back();\n                vis.pop_back();\n  \
    \              ord[u] = n;\n                ids[u] = group_num;\n            \
    \    if (u == c) break;\n            }\n            group_num++;\n        }\n\
    \    };\n    REP(i, n) if (ord[i] == -1) dfs(dfs, i);\n    V<V<int>> res(group_num);\n\
    \    REP(i, n) res[group_num - 1 - ids[i]].push_back(i);\n    return res;\n}\n"
  code: "#pragma once\n\n#include \"icpc/template.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/2748\n\
    \nV<V<int>> scc(V<V<int>>& g) {\n    int n = int(g.size());\n    int now_ord =\
    \ 0, group_num = 0;\n    V<int> vis, low(n), ord(n, -1), ids(n);\n    vis.reserve(n);\n\
    \    auto dfs = [&](auto f, int c) -> void {\n        low[c] = ord[c] = now_ord++;\n\
    \        vis.push_back(c);\n        for (auto& e : g[c]) {\n            if (ord[e]\
    \ == -1) {\n                f(f, e);\n                low[c] = min(low[c], low[e]);\n\
    \            } else {\n                low[c] = min(low[c], ord[e]);\n       \
    \     }\n        }\n        if (low[c] == ord[c]) {\n            while (true)\
    \ {\n                int u = vis.back();\n                vis.pop_back();\n  \
    \              ord[u] = n;\n                ids[u] = group_num;\n            \
    \    if (u == c) break;\n            }\n            group_num++;\n        }\n\
    \    };\n    REP(i, n) if (ord[i] == -1) dfs(dfs, i);\n    V<V<int>> res(group_num);\n\
    \    REP(i, n) res[group_num - 1 - ids[i]].push_back(i);\n    return res;\n}"
  dependsOn:
  - icpc/template.hpp
  isVerificationFile: false
  path: icpc/scc.hpp
  requiredBy: []
  timestamp: '2023-05-31 02:53:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_other/aoj_2748.test.cpp
documentation_of: icpc/scc.hpp
layout: document
redirect_from:
- /library/icpc/scc.hpp
- /library/icpc/scc.hpp.html
title: icpc/scc.hpp
---
