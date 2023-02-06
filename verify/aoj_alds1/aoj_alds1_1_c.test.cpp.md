---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_table.hpp
    title: math/prime_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"verify/aoj_alds1/aoj_alds1_1_c.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"math/prime_table.hpp\"\n\nstd::vector<bool> prime_table(int\
    \ n) {\n    std::vector<bool> res(n + 1, true);\n    if (n >= 0) res[0] = false;\n\
    \    if (n >= 1) res[1] = false;\n    for (int p = 2; p * p <= n; p++) {\n   \
    \     if (!res[p]) continue;\n        for (int i = p * p; i <= n; i += p) {\n\
    \            res[i] = false;\n        }\n    }\n    return res;\n}\n#line 6 \"\
    verify/aoj_alds1/aoj_alds1_1_c.test.cpp\"\n\nint main() {\n    auto pt = prime_table(100000000);\n\
    \    int n;\n    std::cin >> n;\n    int ans = 0;\n    for (int i = 0; i < n;\
    \ i++) {\n        int a;\n        std::cin >> a;\n        ans += pt[a];\n    }\n\
    \    std::cout << ans << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"math/prime_table.hpp\"\n\nint main()\
    \ {\n    auto pt = prime_table(100000000);\n    int n;\n    std::cin >> n;\n \
    \   int ans = 0;\n    for (int i = 0; i < n; i++) {\n        int a;\n        std::cin\
    \ >> a;\n        ans += pt[a];\n    }\n    std::cout << ans << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - math/prime_table.hpp
  isVerificationFile: true
  path: verify/aoj_alds1/aoj_alds1_1_c.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_alds1/aoj_alds1_1_c.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_alds1/aoj_alds1_1_c.test.cpp
- /verify/verify/aoj_alds1/aoj_alds1_1_c.test.cpp.html
title: verify/aoj_alds1/aoj_alds1_1_c.test.cpp
---
