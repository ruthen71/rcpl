---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/template.hpp
    title: icpc/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/3329
  bundledCode: "#line 2 \"icpc/lca.hpp\"\n\n#line 2 \"icpc/template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n#define REP(i,\
    \ n) for (int i = 0; i < (n); i++)\ntemplate <class T> using V = vector<T>;\n\
    template <class T> ostream& operator<<(ostream& os, const V<T>& v) {\n    os <<\
    \ \"[ \";\n    for (auto& vi : v) os << vi << \", \";\n    return os << \"]\"\
    ;\n}\n\n#ifdef LOCAL\n#define show(x) cerr << __LINE__ << \" : \" << #x << \"\
    \ = \" << x << endl;\n#else\n#define show(x) true\n#endif\n\nusing uint = unsigned\
    \ int;\nusing ull = unsigned long long;\n\n// g++ -g -fsanitize=undefined,address\
    \ -DLOCAL -std=gnu++17\n#line 4 \"icpc/lca.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3329\n\
    \nstruct LCA {\n    V<int> dep;\n    V<V<int>> par;\n    int n, log;\n\n    LCA(V<V<int>>&\
    \ g, int root = 0) : n(int(g.size())), log(32 - __builtin_clz(g.size())) {\n \
    \       dep.assign(n, 0);\n        par.assign(log, V<int>(n));\n        auto dfs\
    \ = [&](auto f, int c, int p) -> void {\n            par[0][c] = p;\n        \
    \    for (auto& e : g[c]) {\n                if (e == p) continue;\n         \
    \       dep[e] = dep[c] + 1;\n                f(f, e, c);\n            }\n   \
    \     };\n        dfs(dfs, root, -1);\n        REP(k, log - 1) REP(v, n) par[k\
    \ + 1][v] = (par[k][v] == -1 ? -1 : par[k][par[k][v]]);\n    }\n\n    int lca(int\
    \ u, int v) {\n        assert(int(dep.size()) == n);\n        if (dep[u] > dep[v])\
    \ swap(u, v);\n        REP(k, log) if ((dep[v] - dep[u]) >> k & 1) v = par[k][v];\n\
    \        if (u == v) return u;\n        for (int k = log - 1; k >= 0; k--) {\n\
    \            if (par[k][u] != par[k][v]) {\n                u = par[k][u];\n \
    \               v = par[k][v];\n            }\n        }\n        return par[0][u];\n\
    \    }\n\n    int level_ancestor(int u, int d) {\n        assert(int(dep.size())\
    \ == n);\n        if (dep[u] < d) return -1;\n        REP(k, log) if (d >> k &\
    \ 1) u = par[k][u];\n        return u;\n    }\n\n    int distance(int u, int v)\
    \ {\n        int p = lca(u, v);\n        return dep[u] + dep[v] - 2 * dep[p];\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include \"icpc/template.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3329\n\
    \nstruct LCA {\n    V<int> dep;\n    V<V<int>> par;\n    int n, log;\n\n    LCA(V<V<int>>&\
    \ g, int root = 0) : n(int(g.size())), log(32 - __builtin_clz(g.size())) {\n \
    \       dep.assign(n, 0);\n        par.assign(log, V<int>(n));\n        auto dfs\
    \ = [&](auto f, int c, int p) -> void {\n            par[0][c] = p;\n        \
    \    for (auto& e : g[c]) {\n                if (e == p) continue;\n         \
    \       dep[e] = dep[c] + 1;\n                f(f, e, c);\n            }\n   \
    \     };\n        dfs(dfs, root, -1);\n        REP(k, log - 1) REP(v, n) par[k\
    \ + 1][v] = (par[k][v] == -1 ? -1 : par[k][par[k][v]]);\n    }\n\n    int lca(int\
    \ u, int v) {\n        assert(int(dep.size()) == n);\n        if (dep[u] > dep[v])\
    \ swap(u, v);\n        REP(k, log) if ((dep[v] - dep[u]) >> k & 1) v = par[k][v];\n\
    \        if (u == v) return u;\n        for (int k = log - 1; k >= 0; k--) {\n\
    \            if (par[k][u] != par[k][v]) {\n                u = par[k][u];\n \
    \               v = par[k][v];\n            }\n        }\n        return par[0][u];\n\
    \    }\n\n    int level_ancestor(int u, int d) {\n        assert(int(dep.size())\
    \ == n);\n        if (dep[u] < d) return -1;\n        REP(k, log) if (d >> k &\
    \ 1) u = par[k][u];\n        return u;\n    }\n\n    int distance(int u, int v)\
    \ {\n        int p = lca(u, v);\n        return dep[u] + dep[v] - 2 * dep[p];\n\
    \    }\n};"
  dependsOn:
  - icpc/template.hpp
  isVerificationFile: false
  path: icpc/lca.hpp
  requiredBy: []
  timestamp: '2023-05-31 02:53:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/lca.hpp
layout: document
redirect_from:
- /library/icpc/lca.hpp
- /library/icpc/lca.hpp.html
title: icpc/lca.hpp
---
