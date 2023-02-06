---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/enumerate_primes.hpp
    title: math/enumerate_primes.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"verify/lc_math/lc_enumerate_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include <bits/stdc++.h>\n\
    \n#line 2 \"math/enumerate_primes.hpp\"\n\n#line 2 \"math/prime_table.hpp\"\n\n\
    std::vector<bool> prime_table(int n) {\n    std::vector<bool> res(n + 1, true);\n\
    \    if (n >= 0) res[0] = false;\n    if (n >= 1) res[1] = false;\n    for (int\
    \ p = 2; p * p <= n; p++) {\n        if (!res[p]) continue;\n        for (int\
    \ i = p * p; i <= n; i += p) {\n            res[i] = false;\n        }\n    }\n\
    \    return res;\n}\n#line 4 \"math/enumerate_primes.hpp\"\n\nstd::vector<int>\
    \ enumerate_primes(int n) {\n    auto pt = prime_table(n);\n    std::vector<int>\
    \ res;\n    res.reserve(std::count(pt.begin(), pt.end(), true));\n    for (int\
    \ i = 0; i < pt.size(); i++) {\n        if (pt[i]) res.push_back(i);\n    }\n\
    \    return res;\n}\n#line 6 \"verify/lc_math/lc_enumerate_primes.test.cpp\"\n\
    \nint main() {\n    int n, a, b;\n    std::cin >> n >> a >> b;\n    auto pl =\
    \ enumerate_primes(n);\n    std::vector<int> ans;\n    for (int i = b; i < pl.size();\
    \ i += a) ans.push_back(pl[i]);\n    std::cout << pl.size() << ' ' << ans.size()\
    \ << '\\n';\n    for (int i = 0; i < ans.size(); i++) std::cout << ans[i] << \"\
    \ \\n\"[i == ans.size() - 1];\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <bits/stdc++.h>\n\n#include \"math/enumerate_primes.hpp\"\n\nint main()\
    \ {\n    int n, a, b;\n    std::cin >> n >> a >> b;\n    auto pl = enumerate_primes(n);\n\
    \    std::vector<int> ans;\n    for (int i = b; i < pl.size(); i += a) ans.push_back(pl[i]);\n\
    \    std::cout << pl.size() << ' ' << ans.size() << '\\n';\n    for (int i = 0;\
    \ i < ans.size(); i++) std::cout << ans[i] << \" \\n\"[i == ans.size() - 1];\n\
    \    return 0;\n}"
  dependsOn:
  - math/enumerate_primes.hpp
  - math/prime_table.hpp
  isVerificationFile: true
  path: verify/lc_math/lc_enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_math/lc_enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_math/lc_enumerate_primes.test.cpp
- /verify/verify/lc_math/lc_enumerate_primes.test.cpp.html
title: verify/lc_math/lc_enumerate_primes.test.cpp
---
