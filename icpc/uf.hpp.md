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
    - https://onlinejudge.u-aizu.ac.jp/problems/3324
  bundledCode: "#line 2 \"icpc/uf.hpp\"\n\n#line 2 \"icpc/template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n#define REP(i,\
    \ n) for (int i = 0; i < (n); i++)\ntemplate <class T> using V = vector<T>;\n\
    template <class T> ostream& operator<<(ostream &os, const V<T>& v) {\n    os <<\
    \ \"[ \";\n    for (auto &vi : v) os << vi << \", \";\n    return os << \"]\"\
    ;\n}\n\n#ifdef LOCAL\n#define show(x) cerr << __LINE__ << \" : \" << #x << \"\
    \ = \" << x << endl;\n#else\n#define show(x) true\n#endif\n\n// g++ -g -fsanitize=undefined,address\
    \ -DLOCAL -std=gnu++17\n#line 4 \"icpc/uf.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3324\n\
    \nstruct UF {\n    V<int> par;\n\n    UF() {}\n    UF(int n) : par(n, -1) {}\n\
    \n    int leader(int x) { return par[x] < 0 ? x : par[x] = leader(par[x]); }\n\
    \n    bool merge(int x, int y) {\n        x = leader(x), y = leader(y);\n    \
    \    if (x == y) return false;\n        if (par[x] > par[y]) swap(x, y);\n   \
    \     par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\n\
    \    bool same(int x, int y) { return leader(x) == leader(y); }\n\n    int size(int\
    \ x) { return -par[leader(x)]; }\n};\n"
  code: "#pragma once\n\n#include \"icpc/template.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3324\n\
    \nstruct UF {\n    V<int> par;\n\n    UF() {}\n    UF(int n) : par(n, -1) {}\n\
    \n    int leader(int x) { return par[x] < 0 ? x : par[x] = leader(par[x]); }\n\
    \n    bool merge(int x, int y) {\n        x = leader(x), y = leader(y);\n    \
    \    if (x == y) return false;\n        if (par[x] > par[y]) swap(x, y);\n   \
    \     par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\n\
    \    bool same(int x, int y) { return leader(x) == leader(y); }\n\n    int size(int\
    \ x) { return -par[leader(x)]; }\n};"
  dependsOn:
  - icpc/template.hpp
  isVerificationFile: false
  path: icpc/uf.hpp
  requiredBy: []
  timestamp: '2023-05-18 16:04:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/uf.hpp
layout: document
redirect_from:
- /library/icpc/uf.hpp
- /library/icpc/uf.hpp.html
title: icpc/uf.hpp
---
