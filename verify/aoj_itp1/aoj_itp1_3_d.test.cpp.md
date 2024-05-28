---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/divisor.hpp
    title: math/divisor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
  bundledCode: "#line 1 \"verify/aoj_itp1/aoj_itp1_3_d.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"math/divisor.hpp\"\n\ntemplate <class T> std::vector<T>\
    \ divisor(const T n) {\n    std::vector<T> res;\n    for (T i = T(1); i * i <=\
    \ n; i++) {\n        if (n % i == 0) {\n            res.push_back(i);\n      \
    \      if (i * i != n) res.push_back(n / i);\n        }\n    }\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n}\n#line 6 \"verify/aoj_itp1/aoj_itp1_3_d.test.cpp\"\
    \n\nint main() {\n    long long a, b, c;\n    std::cin >> a >> b >> c;\n    auto\
    \ dv = divisor(c);\n    int ans = 0;\n    for (auto &d : dv) {\n        if (a\
    \ <= d and d <= b) {\n            ans++;\n        }\n    }\n    std::cout << ans\
    \ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"math/divisor.hpp\"\n\nint main() {\n\
    \    long long a, b, c;\n    std::cin >> a >> b >> c;\n    auto dv = divisor(c);\n\
    \    int ans = 0;\n    for (auto &d : dv) {\n        if (a <= d and d <= b) {\n\
    \            ans++;\n        }\n    }\n    std::cout << ans << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - math/divisor.hpp
  isVerificationFile: true
  path: verify/aoj_itp1/aoj_itp1_3_d.test.cpp
  requiredBy: []
  timestamp: '2024-05-28 13:48:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_itp1/aoj_itp1_3_d.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_itp1/aoj_itp1_3_d.test.cpp
- /verify/verify/aoj_itp1/aoj_itp1_3_d.test.cpp.html
title: verify/aoj_itp1/aoj_itp1_3_d.test.cpp
---
