---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: icpc/dice.hpp
    title: icpc/dice.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"icpc/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define REP(i, n) for (int i = 0; i < (n); i++)\ntemplate <class T> ostream\
    \ &operator<<(ostream &os, const vector<T> &v) {\n    os << \"[ \";\n    for (auto\
    \ &vi : v) os << vi << \", \";\n    return os << \"]\";\n}\n#if 1\n#define show(x)\
    \ cerr << __LINE__ << \" : \" << #x << \" = \" << x << endl;\n#else\n#define show(x)\
    \ true\n#endif\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#define REP(i, n) for (int\
    \ i = 0; i < (n); i++)\ntemplate <class T> ostream &operator<<(ostream &os, const\
    \ vector<T> &v) {\n    os << \"[ \";\n    for (auto &vi : v) os << vi << \", \"\
    ;\n    return os << \"]\";\n}\n#if 1\n#define show(x) cerr << __LINE__ << \" :\
    \ \" << #x << \" = \" << x << endl;\n#else\n#define show(x) true\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/template.hpp
  requiredBy:
  - icpc/dice.hpp
  timestamp: '2023-05-01 05:45:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/template.hpp
layout: document
redirect_from:
- /library/icpc/template.hpp
- /library/icpc/template.hpp.html
title: icpc/template.hpp
---
