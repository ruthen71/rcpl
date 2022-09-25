---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/pow_mod.hpp
    title: src/math/pow_mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"verify/aoj_ntl/aoj_ntl_1_b.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"src/math/pow_mod.hpp\"\n\nlong long pow_mod(long\
    \ long a, long long n, const long long mod) {\n    assert(n >= 0 and mod >= 1);\n\
    \    a %= mod;\n    if (a < 0) a += mod;\n    if (a == 0) return (n == 0 ? (mod\
    \ != 1 ? 1 : 0) : 0);  // 0 ^ 0 = 1\n    long long res = 1;\n    while (n) {\n\
    \        if (n & 1) res = res * a % mod;\n        a = a * a % mod;\n        n\
    \ >>= 1;\n    }\n    return res;\n}\n#line 6 \"verify/aoj_ntl/aoj_ntl_1_b.test.cpp\"\
    \n\nint main() {\n    long long m, n;\n    std::cin >> m >> n;\n    std::cout\
    \ << pow_mod(m, n, 1000000007) << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"src/math/pow_mod.hpp\"\n\nint main()\
    \ {\n    long long m, n;\n    std::cin >> m >> n;\n    std::cout << pow_mod(m,\
    \ n, 1000000007) << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/math/pow_mod.hpp
  isVerificationFile: true
  path: verify/aoj_ntl/aoj_ntl_1_b.test.cpp
  requiredBy: []
  timestamp: '2022-09-26 00:37:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_ntl/aoj_ntl_1_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_ntl/aoj_ntl_1_b.test.cpp
- /verify/verify/aoj_ntl/aoj_ntl_1_b.test.cpp.html
title: verify/aoj_ntl/aoj_ntl_1_b.test.cpp
---
