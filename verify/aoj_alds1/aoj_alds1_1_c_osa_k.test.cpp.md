---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/osak.hpp
    title: math/osak.hpp
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
  bundledCode: "#line 1 \"verify/aoj_alds1/aoj_alds1_1_c_osa_k.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"math/osak.hpp\"\n\nstruct Osak {\n \
    \   int n;\n    std::vector<int> min_factor;\n\n    Osak(int n) : n(n), min_factor(n\
    \ + 1) {\n        std::iota(min_factor.begin(), min_factor.end(), 0);\n      \
    \  if (n >= 0) min_factor[0] = -1;\n        if (n >= 1) min_factor[1] = -1;\n\
    \        for (int p = 2; p * p <= n; p++) {\n            if (min_factor[p] !=\
    \ p) continue;\n            for (int i = p * p; i <= n; i += p) {\n          \
    \      if (min_factor[i] != i) continue;\n                min_factor[i] = p;\n\
    \            }\n        }\n    }\n\n    bool is_prime(int x) {\n        assert(x\
    \ <= n);\n        return min_factor[x] == x;\n    }\n\n    std::map<int, int>\
    \ prime_factor(int x) {\n        assert(x <= n);\n        std::map<int, int> pf;\n\
    \        while (x > 1) {\n            pf[min_factor[x]]++;\n            x /= min_factor[x];\n\
    \        }\n        return pf;\n    }\n};\n#line 6 \"verify/aoj_alds1/aoj_alds1_1_c_osa_k.test.cpp\"\
    \n\nint main() {\n    auto osak = Osak(100000000);\n    int n;\n    std::cin >>\
    \ n;\n    int ans = 0;\n    for (int i = 0; i < n; i++) {\n        int a;\n  \
    \      std::cin >> a;\n        ans += osak.is_prime(a);\n    }\n    std::cout\
    \ << ans << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"math/osak.hpp\"\n\nint main() {\n \
    \   auto osak = Osak(100000000);\n    int n;\n    std::cin >> n;\n    int ans\
    \ = 0;\n    for (int i = 0; i < n; i++) {\n        int a;\n        std::cin >>\
    \ a;\n        ans += osak.is_prime(a);\n    }\n    std::cout << ans << '\\n';\n\
    \    return 0;\n}"
  dependsOn:
  - math/osak.hpp
  isVerificationFile: true
  path: verify/aoj_alds1/aoj_alds1_1_c_osa_k.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_alds1/aoj_alds1_1_c_osa_k.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_alds1/aoj_alds1_1_c_osa_k.test.cpp
- /verify/verify/aoj_alds1/aoj_alds1_1_c_osa_k.test.cpp.html
title: verify/aoj_alds1/aoj_alds1_1_c_osa_k.test.cpp
---
