---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: icpc/template.hpp
    title: icpc/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/dice.hpp\"\n\n#line 1 \"icpc/template.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#define REP(i, n) for (int i = 0; i <\
    \ (n); i++)\ntemplate <class T> ostream &operator<<(ostream &os, const vector<T>\
    \ &v) {\n    os << \"[ \";\n    for (auto &vi : v) os << vi << \", \";\n    return\
    \ os << \"]\";\n}\n#if 1\n#define show(x) cerr << __LINE__ << \" : \" << #x <<\
    \ \" = \" << x << endl;\n#else\n#define show(x) true\n#endif\n#line 4 \"icpc/dice.hpp\"\
    \n\n// d = {x-, x+, y-, y+, z-, z+}\n// d = {0,  1,  2,  3,  4,  5}\nstruct Dice\
    \ {\n    vector<long long> d;\n    Dice(vector<long long> &d) : d(d) {}\n    void\
    \ right() { d = {d[2], d[3], d[1], d[0], d[4], d[5]}; }\n    void left() { REP(i,\
    \ 3) right(); }\n    void xm() { d = {d[5], d[4], d[2], d[3], d[0], d[1]}; }\n\
    \    void xp() { REP(i, 3) xm(); }\n    void ym() { d = {d[0], d[1], d[5], d[4],\
    \ d[2], d[3]}; }\n    void yp() { REP(i, 3) ym(); }\n};\n"
  code: "#pragma once\n\n#include \"icpc/template.hpp\"\n\n// d = {x-, x+, y-, y+,\
    \ z-, z+}\n// d = {0,  1,  2,  3,  4,  5}\nstruct Dice {\n    vector<long long>\
    \ d;\n    Dice(vector<long long> &d) : d(d) {}\n    void right() { d = {d[2],\
    \ d[3], d[1], d[0], d[4], d[5]}; }\n    void left() { REP(i, 3) right(); }\n \
    \   void xm() { d = {d[5], d[4], d[2], d[3], d[0], d[1]}; }\n    void xp() { REP(i,\
    \ 3) xm(); }\n    void ym() { d = {d[0], d[1], d[5], d[4], d[2], d[3]}; }\n  \
    \  void yp() { REP(i, 3) ym(); }\n};"
  dependsOn:
  - icpc/template.hpp
  isVerificationFile: false
  path: icpc/dice.hpp
  requiredBy: []
  timestamp: '2023-05-01 05:45:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/dice.hpp
layout: document
redirect_from:
- /library/icpc/dice.hpp
- /library/icpc/dice.hpp.html
title: icpc/dice.hpp
---
