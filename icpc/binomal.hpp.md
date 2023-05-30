---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/template.hpp
    title: icpc/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_2751.test.cpp
    title: verify/aoj_other/aoj_2751.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2751
  bundledCode: "#line 2 \"icpc/binomal.hpp\"\n\n#line 2 \"icpc/template.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n#define\
    \ REP(i, n) for (int i = 0; i < (n); i++)\ntemplate <class T> using V = vector<T>;\n\
    template <class T> ostream& operator<<(ostream& os, const V<T>& v) {\n    os <<\
    \ \"[ \";\n    for (auto& vi : v) os << vi << \", \";\n    return os << \"]\"\
    ;\n}\n\n#ifdef LOCAL\n#define show(x) cerr << __LINE__ << \" : \" << #x << \"\
    \ = \" << x << endl;\n#else\n#define show(x) true\n#endif\n\nusing uint = unsigned\
    \ int;\nusing ull = unsigned long long;\n\n// g++ -g -fsanitize=undefined,address\
    \ -DLOCAL -std=gnu++17\n#line 4 \"icpc/binomal.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/2751\n\
    \ntemplate <class T> struct Binomial {\n    V<T> f, g;\n\n    Binomial(const int\
    \ n = 0) {\n        f.resize(n);\n        g.resize(n);\n        f[0] = g[0] =\
    \ 1;\n        for (int i = 1; i < n; i++) f[i] = f[i - 1] * T(i);\n        g[n\
    \ - 1] = T(1) / f[n - 1];\n        for (int i = n - 2; i >= 1; i--) g[i] = g[i\
    \ + 1] * T(i + 1);\n    }\n\n    T C(int N, int K) {\n        if (N < 0 or K <\
    \ 0 or N < K) return 0;\n        return f[N] * g[N - K] * g[K];\n    }\n\n   \
    \ T P(int N, int K) {\n        if (N < 0 or K < 0 or N < K) return 0;\n      \
    \  return f[N] * g[N - K];\n    }\n\n    T C_naive(int N, int K) {\n        if\
    \ (N < 0 or K < 0 or N < K) return 0;\n        T res(1);\n        K = min(K, N\
    \ - K);\n        for (int i = 1; i <= K; i++) {\n            res *= N--;\n   \
    \         res /= i;\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n#include \"icpc/template.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/2751\n\
    \ntemplate <class T> struct Binomial {\n    V<T> f, g;\n\n    Binomial(const int\
    \ n = 0) {\n        f.resize(n);\n        g.resize(n);\n        f[0] = g[0] =\
    \ 1;\n        for (int i = 1; i < n; i++) f[i] = f[i - 1] * T(i);\n        g[n\
    \ - 1] = T(1) / f[n - 1];\n        for (int i = n - 2; i >= 1; i--) g[i] = g[i\
    \ + 1] * T(i + 1);\n    }\n\n    T C(int N, int K) {\n        if (N < 0 or K <\
    \ 0 or N < K) return 0;\n        return f[N] * g[N - K] * g[K];\n    }\n\n   \
    \ T P(int N, int K) {\n        if (N < 0 or K < 0 or N < K) return 0;\n      \
    \  return f[N] * g[N - K];\n    }\n\n    T C_naive(int N, int K) {\n        if\
    \ (N < 0 or K < 0 or N < K) return 0;\n        T res(1);\n        K = min(K, N\
    \ - K);\n        for (int i = 1; i <= K; i++) {\n            res *= N--;\n   \
    \         res /= i;\n        }\n        return res;\n    }\n};"
  dependsOn:
  - icpc/template.hpp
  isVerificationFile: false
  path: icpc/binomal.hpp
  requiredBy: []
  timestamp: '2023-05-31 02:53:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_other/aoj_2751.test.cpp
documentation_of: icpc/binomal.hpp
layout: document
redirect_from:
- /library/icpc/binomal.hpp
- /library/icpc/binomal.hpp.html
title: icpc/binomal.hpp
---
