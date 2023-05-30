---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: icpc/template.hpp
    title: icpc/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/3332
  bundledCode: "#line 2 \"icpc/matrix.hpp\"\n\n#line 2 \"icpc/template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n#define REP(i,\
    \ n) for (int i = 0; i < (n); i++)\ntemplate <class T> using V = vector<T>;\n\
    template <class T> ostream& operator<<(ostream &os, const V<T>& v) {\n    os <<\
    \ \"[ \";\n    for (auto &vi : v) os << vi << \", \";\n    return os << \"]\"\
    ;\n}\n\n#ifdef LOCAL\n#define show(x) cerr << __LINE__ << \" : \" << #x << \"\
    \ = \" << x << endl;\n#else\n#define show(x) true\n#endif\n\n// g++ -g -fsanitize=undefined,address\
    \ -DLOCAL -std=gnu++17\n#line 4 \"icpc/matrix.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3332\n\
    \nconstexpr ll MOD = 998244353;\n\nusing Mat = V<V<ll>>;\nMat mul(Mat& a, Mat&\
    \ b) {\n    int N = int(a.size());\n    Mat c(N, V<ll>(N));\n    REP(i, N) REP(k,\
    \ N) REP(j, N) c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;\n    return\
    \ c;\n}\n\nMat pow(Mat& a, ll k) {\n    int N = int(a.size());\n    Mat res(N,\
    \ V<ll>(N));\n    REP(i, N) res[i][i] = 1;\n    while (k) {\n        if (k & 1)\
    \ res = mul(res, a);\n        a = mul(a, a);\n        k >>= 1;\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\n\n#include \"icpc/template.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3332\n\
    \nconstexpr ll MOD = 998244353;\n\nusing Mat = V<V<ll>>;\nMat mul(Mat& a, Mat&\
    \ b) {\n    int N = int(a.size());\n    Mat c(N, V<ll>(N));\n    REP(i, N) REP(k,\
    \ N) REP(j, N) c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;\n    return\
    \ c;\n}\n\nMat pow(Mat& a, ll k) {\n    int N = int(a.size());\n    Mat res(N,\
    \ V<ll>(N));\n    REP(i, N) res[i][i] = 1;\n    while (k) {\n        if (k & 1)\
    \ res = mul(res, a);\n        a = mul(a, a);\n        k >>= 1;\n    }\n    return\
    \ res;\n}"
  dependsOn:
  - icpc/template.hpp
  isVerificationFile: false
  path: icpc/matrix.hpp
  requiredBy: []
  timestamp: '2023-05-18 16:04:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/matrix.hpp
layout: document
redirect_from:
- /library/icpc/matrix.hpp
- /library/icpc/matrix.hpp.html
title: icpc/matrix.hpp
---
