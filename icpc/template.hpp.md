---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: icpc/dice.hpp
    title: icpc/dice.hpp
  - icon: ':x:'
    path: icpc/modint.hpp
    title: icpc/modint.hpp
  - icon: ':x:'
    path: icpc/ntt.hpp
    title: icpc/ntt.hpp
  - icon: ':x:'
    path: icpc/segtree.hpp
    title: icpc/segtree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_2703.test.cpp
    title: verify/aoj_other/aoj_2703.test.cpp
  - icon: ':x:'
    path: verify/aoj_other/aoj_3326.test.cpp
    title: verify/aoj_other/aoj_3326.test.cpp
  - icon: ':x:'
    path: verify/aoj_other/aoj_3331.test.cpp
    title: verify/aoj_other/aoj_3331.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\
    template <class T> using V = vector<T>;\ntemplate <class T> ostream& operator<<(ostream\
    \ &os, const V<T>& v) {\n    os << \"[ \";\n    for (auto &vi : v) os << vi <<\
    \ \", \";\n    return os << \"]\";\n}\n\n#ifdef LOCAL\n#define show(x) cerr <<\
    \ __LINE__ << \" : \" << #x << \" = \" << x << endl;\n#else\n#define show(x) true\n\
    #endif\n\n// g++ -g -fsanitize=undefined,address -DLOCAL -std=gnu++17\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll\
    \ = long long;\n#define REP(i, n) for (int i = 0; i < (n); i++)\ntemplate <class\
    \ T> using V = vector<T>;\ntemplate <class T> ostream& operator<<(ostream &os,\
    \ const V<T>& v) {\n    os << \"[ \";\n    for (auto &vi : v) os << vi << \",\
    \ \";\n    return os << \"]\";\n}\n\n#ifdef LOCAL\n#define show(x) cerr << __LINE__\
    \ << \" : \" << #x << \" = \" << x << endl;\n#else\n#define show(x) true\n#endif\n\
    \n// g++ -g -fsanitize=undefined,address -DLOCAL -std=gnu++17"
  dependsOn: []
  isVerificationFile: false
  path: icpc/template.hpp
  requiredBy:
  - icpc/dice.hpp
  - icpc/ntt.hpp
  - icpc/segtree.hpp
  - icpc/modint.hpp
  timestamp: '2023-05-15 01:12:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj_other/aoj_3331.test.cpp
  - verify/aoj_other/aoj_3326.test.cpp
  - verify/aoj_other/aoj_2703.test.cpp
documentation_of: icpc/template.hpp
layout: document
redirect_from:
- /library/icpc/template.hpp
- /library/icpc/template.hpp.html
title: icpc/template.hpp
---
