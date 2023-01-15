---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/prime_factor.hpp
    title: src/math/prime_factor.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/totient.hpp
    title: src/math/totient.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"verify/aoj_ntl/aoj_ntl_1_d.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"src/math/totient.hpp\"\n\n#line 2 \"src/math/prime_factor.hpp\"\
    \n\nstd::map<long long, int> prime_factor(long long n) {\n    std::map<long long,\
    \ int> res;\n    for (long long i = 2; i * i <= n; i++) {\n        while (n %\
    \ i == 0) {\n            res[i]++;\n            n /= i;\n        }\n    }\n  \
    \  if (n != 1) res[n]++;\n    return res;\n}\n#line 4 \"src/math/totient.hpp\"\
    \n\nlong long totient(long long n) {\n    auto pf = prime_factor(n);\n    for\
    \ (auto &[p, e] : pf) {\n        n /= p;\n        n *= p - 1;\n    }\n    return\
    \ n;\n}\n#line 6 \"verify/aoj_ntl/aoj_ntl_1_d.test.cpp\"\n\nint main() {\n   \
    \ long long n;\n    std::cin >> n;\n    std::cout << totient(n) << '\\n';\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"src/math/totient.hpp\"\n\nint main()\
    \ {\n    long long n;\n    std::cin >> n;\n    std::cout << totient(n) << '\\\
    n';\n    return 0;\n}"
  dependsOn:
  - src/math/totient.hpp
  - src/math/prime_factor.hpp
  isVerificationFile: true
  path: verify/aoj_ntl/aoj_ntl_1_d.test.cpp
  requiredBy: []
  timestamp: '2022-09-06 04:24:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_ntl/aoj_ntl_1_d.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_ntl/aoj_ntl_1_d.test.cpp
- /verify/verify/aoj_ntl/aoj_ntl_1_d.test.cpp.html
title: verify/aoj_ntl/aoj_ntl_1_d.test.cpp
---