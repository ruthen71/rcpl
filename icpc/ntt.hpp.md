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
    - https://onlinejudge.u-aizu.ac.jp/problems/3331
  bundledCode: "#line 2 \"icpc/ntt.hpp\"\n\n#line 2 \"icpc/template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n#define REP(i,\
    \ n) for (int i = 0; i < (n); i++)\ntemplate <class T> using V = vector<T>;\n\
    template <class T> ostream& operator<<(ostream &os, const V<T>& v) {\n    os <<\
    \ \"[ \";\n    for (auto &vi : v) os << vi << \", \";\n    return os << \"]\"\
    ;\n}\n\n#ifdef LOCAL\n#define show(x) cerr << __LINE__ << \" : \" << #x << \"\
    \ = \" << x << endl;\n#else\n#define show(x) true\n#endif\n\n// g++ -g -fsanitize=undefined,address\
    \ -DLOCAL -std=gnu++17\n#line 4 \"icpc/ntt.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3331\n\
    \ntemplate <class Mint> void ntt(bool type, V<Mint>& a) {\n    int n = int(a.size()),\
    \ s = 0;\n    while ((1 << s) < n) s++;\n    assert(1 << s == n);\n\n    static\
    \ V<Mint> ep, iep;\n    while (int(ep.size()) <= s) {\n        ep.push_back(Mint::G.pow(Mint(-1).v\
    \ / (1 << ep.size())));\n        iep.push_back(ep.back().inv());\n    }\n    V<Mint>\
    \ b(n);\n    for (int i = 1; i <= s; i++) {\n        int w = 1 << (s - i);\n \
    \       Mint base = type ? iep[i] : ep[i], now = 1;\n        for (int y = 0; y\
    \ < n / 2; y += w) {\n            REP(x, w) {\n                auto l = a[y <<\
    \ 1 | x];\n                auto r = now * a[y << 1 | x | w];\n               \
    \ b[y | x] = l + r;\n                b[y | x | n >> 1] = l - r;\n            }\n\
    \            now *= base;\n        }\n        swap(a, b);\n    }\n}\n\ntemplate\
    \ <class Mint> V<Mint> multiply(const V<Mint>& a, const V<Mint>& b) {\n    int\
    \ n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n    if\
    \ (min(n, m) <= 8) {\n        V<Mint> ans(n + m - 1);\n        REP(i, n) REP(j,\
    \ m) ans[i + j] += a[i] * b[j];\n        return ans;\n    }\n    int lg = 0;\n\
    \    while ((1 << lg) < n + m - 1) lg++;\n    int z = 1 << lg;\n    auto a2 =\
    \ a, b2 = b;\n    a2.resize(z);\n    b2.resize(z);\n    ntt(false, a2);\n    ntt(false,\
    \ b2);\n    REP(i, z) a2[i] *= b2[i];\n    ntt(true, a2);\n    a2.resize(n + m\
    \ - 1);\n    Mint iz = Mint(z).inv();\n    REP(i, n + m - 1) a2[i] *= iz;\n  \
    \  return a2;\n}\n"
  code: "#pragma once\n\n#include \"icpc/template.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3331\n\
    \ntemplate <class Mint> void ntt(bool type, V<Mint>& a) {\n    int n = int(a.size()),\
    \ s = 0;\n    while ((1 << s) < n) s++;\n    assert(1 << s == n);\n\n    static\
    \ V<Mint> ep, iep;\n    while (int(ep.size()) <= s) {\n        ep.push_back(Mint::G.pow(Mint(-1).v\
    \ / (1 << ep.size())));\n        iep.push_back(ep.back().inv());\n    }\n    V<Mint>\
    \ b(n);\n    for (int i = 1; i <= s; i++) {\n        int w = 1 << (s - i);\n \
    \       Mint base = type ? iep[i] : ep[i], now = 1;\n        for (int y = 0; y\
    \ < n / 2; y += w) {\n            REP(x, w) {\n                auto l = a[y <<\
    \ 1 | x];\n                auto r = now * a[y << 1 | x | w];\n               \
    \ b[y | x] = l + r;\n                b[y | x | n >> 1] = l - r;\n            }\n\
    \            now *= base;\n        }\n        swap(a, b);\n    }\n}\n\ntemplate\
    \ <class Mint> V<Mint> multiply(const V<Mint>& a, const V<Mint>& b) {\n    int\
    \ n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n    if\
    \ (min(n, m) <= 8) {\n        V<Mint> ans(n + m - 1);\n        REP(i, n) REP(j,\
    \ m) ans[i + j] += a[i] * b[j];\n        return ans;\n    }\n    int lg = 0;\n\
    \    while ((1 << lg) < n + m - 1) lg++;\n    int z = 1 << lg;\n    auto a2 =\
    \ a, b2 = b;\n    a2.resize(z);\n    b2.resize(z);\n    ntt(false, a2);\n    ntt(false,\
    \ b2);\n    REP(i, z) a2[i] *= b2[i];\n    ntt(true, a2);\n    a2.resize(n + m\
    \ - 1);\n    Mint iz = Mint(z).inv();\n    REP(i, n + m - 1) a2[i] *= iz;\n  \
    \  return a2;\n}"
  dependsOn:
  - icpc/template.hpp
  isVerificationFile: false
  path: icpc/ntt.hpp
  requiredBy: []
  timestamp: '2023-05-18 16:04:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/ntt.hpp
layout: document
redirect_from:
- /library/icpc/ntt.hpp
- /library/icpc/ntt.hpp.html
title: icpc/ntt.hpp
---
