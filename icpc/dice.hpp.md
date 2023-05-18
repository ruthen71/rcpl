---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/template.hpp
    title: icpc/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_2703.test.cpp
    title: verify/aoj_other/aoj_2703.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2703
  bundledCode: "#line 2 \"icpc/dice.hpp\"\n\n#line 2 \"icpc/template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n#define REP(i,\
    \ n) for (int i = 0; i < (n); i++)\ntemplate <class T> using V = vector<T>;\n\
    template <class T> ostream& operator<<(ostream &os, const V<T>& v) {\n    os <<\
    \ \"[ \";\n    for (auto &vi : v) os << vi << \", \";\n    return os << \"]\"\
    ;\n}\n\n#ifdef LOCAL\n#define show(x) cerr << __LINE__ << \" : \" << #x << \"\
    \ = \" << x << endl;\n#else\n#define show(x) true\n#endif\n\n// g++ -g -fsanitize=undefined,address\
    \ -DLOCAL -std=gnu++17\n#line 4 \"icpc/dice.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/2703\n\
    // d = {x-, x+, y-, y+, z-, z+}\n// d = {0,  1,  2,  3,  4,  5}\nstruct Dice {\n\
    \    vector<long long> d;\n    Dice(vector<long long> &d) : d(d) {}\n    void\
    \ right() { d = {d[2], d[3], d[1], d[0], d[4], d[5]}; }\n    void left() { REP(i,\
    \ 3) right(); }\n    void xm() { d = {d[5], d[4], d[2], d[3], d[0], d[1]}; }\n\
    \    void xp() { REP(i, 3) xm(); }\n    void ym() { d = {d[0], d[1], d[5], d[4],\
    \ d[2], d[3]}; }\n    void yp() { REP(i, 3) ym(); }\n};\n"
  code: "#pragma once\n\n#include \"icpc/template.hpp\"\n\n// https://onlinejudge.u-aizu.ac.jp/problems/2703\n\
    // d = {x-, x+, y-, y+, z-, z+}\n// d = {0,  1,  2,  3,  4,  5}\nstruct Dice {\n\
    \    vector<long long> d;\n    Dice(vector<long long> &d) : d(d) {}\n    void\
    \ right() { d = {d[2], d[3], d[1], d[0], d[4], d[5]}; }\n    void left() { REP(i,\
    \ 3) right(); }\n    void xm() { d = {d[5], d[4], d[2], d[3], d[0], d[1]}; }\n\
    \    void xp() { REP(i, 3) xm(); }\n    void ym() { d = {d[0], d[1], d[5], d[4],\
    \ d[2], d[3]}; }\n    void yp() { REP(i, 3) ym(); }\n};"
  dependsOn:
  - icpc/template.hpp
  isVerificationFile: false
  path: icpc/dice.hpp
  requiredBy: []
  timestamp: '2023-05-18 16:04:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_other/aoj_2703.test.cpp
documentation_of: icpc/dice.hpp
layout: document
redirect_from:
- /library/icpc/dice.hpp
- /library/icpc/dice.hpp.html
title: icpc/dice.hpp
---