---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: icpc/dice.hpp
    title: icpc/dice.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_2703.test.cpp
    title: verify/aoj_other/aoj_2703.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define REP(i, n) for (int i = 0; i < (n); i++)\ntemplate <class T> ostream\
    \ &operator<<(ostream &os, const vector<T> &v) {\n    os << \"[ \";\n    for (auto\
    \ &vi : v) os << vi << \", \";\n    return os << \"]\";\n}\n#if 1\n#define show(x)\
    \ cerr << __LINE__ << \" : \" << #x << \" = \" << x << endl;\n#else\n#define show(x)\
    \ true\n#endif\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n#define REP(i,\
    \ n) for (int i = 0; i < (n); i++)\ntemplate <class T> ostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n    os << \"[ \";\n    for (auto &vi : v) os <<\
    \ vi << \", \";\n    return os << \"]\";\n}\n#if 1\n#define show(x) cerr << __LINE__\
    \ << \" : \" << #x << \" = \" << x << endl;\n#else\n#define show(x) true\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/template.hpp
  requiredBy:
  - icpc/dice.hpp
  timestamp: '2023-05-01 05:59:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_other/aoj_2703.test.cpp
documentation_of: icpc/template.hpp
layout: document
redirect_from:
- /library/icpc/template.hpp
- /library/icpc/template.hpp.html
title: icpc/template.hpp
---
