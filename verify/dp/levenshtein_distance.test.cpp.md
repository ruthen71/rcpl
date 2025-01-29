---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/levenshtein_distance.hpp
    title: "Levenshtein Distance (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\
      \u30F3\u8DDD\u96E2)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
  bundledCode: "#line 1 \"verify/dp/levenshtein_distance.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\n\n#include\
    \ <iostream>\n\n#line 2 \"dp/levenshtein_distance.hpp\"\n\n#include <vector>\n\
    #include <string>\n\ntemplate <class T>\nint levenshtein_distance(std::vector<T>&\
    \ a, std::vector<T>& b, const int inf = 1000000000) {\n    const int n = (int)(a.size()),\
    \ m = (int)(b.size());\n    std::vector dp(n + 1, std::vector<int>(m + 1, inf));\n\
    \    // initialize\n    dp[0][0] = 0;\n    // \u3082\u3089\u3046 DP \u3060\u3068\
    \ dp[i][0], dp[0][j] \u306B\u3064\u3044\u3066\u521D\u671F\u5316\u304C\u5FC5\u8981\
    \n    // for (int i = 0; i < n + 1; i++) dp[i][0] = i;\n    // for (int j = 0;\
    \ j < m + 1; j++) dp[0][j] = j;\n    // dp\n    for (int i = 0; i <= n; i++) {\n\
    \        for (int j = 0; j <= m; j++) {\n            // a += ?\n            if\
    \ (j + 1 <= m and dp[i][j + 1] > dp[i][j] + 1) {\n                dp[i][j + 1]\
    \ = dp[i][j] + 1;\n            }\n            // b += ?\n            if (i + 1\
    \ <= n and dp[i + 1][j] > dp[i][j] + 1) {\n                dp[i + 1][j] = dp[i][j]\
    \ + 1;\n            }\n            // a[i] = b[i]\n            if (i + 1 <= n\
    \ and j + 1 <= m) {\n                int cost = a[i] == b[j] ? 0 : 1;\n      \
    \          if (dp[i + 1][j + 1] > dp[i][j] + cost) {\n                    dp[i\
    \ + 1][j + 1] = dp[i][j] + cost;\n                }\n            }\n        }\n\
    \    }\n    return dp[n][m];\n}\n\nint levenshtein_distance(std::string& s, std::string&\
    \ t, const int inf = 1000000000) {\n    const int n = (int)(s.size()), m = (int)(t.size());\n\
    \    std::vector<int> a(n), b(m);\n    for (int i = 0; i < n; i++) a[i] = s[i];\n\
    \    for (int j = 0; j < m; j++) b[j] = t[j];\n    return levenshtein_distance(a,\
    \ b, inf);\n}\n#line 6 \"verify/dp/levenshtein_distance.test.cpp\"\n\nint main()\
    \ {\n    std::string s, t;\n    std::cin >> s >> t;\n    std::cout << levenshtein_distance(s,\
    \ t) << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \n\n#include <iostream>\n\n#include \"dp/levenshtein_distance.hpp\"\n\nint main()\
    \ {\n    std::string s, t;\n    std::cin >> s >> t;\n    std::cout << levenshtein_distance(s,\
    \ t) << '\\n';\n    return 0;\n}"
  dependsOn:
  - dp/levenshtein_distance.hpp
  isVerificationFile: true
  path: verify/dp/levenshtein_distance.test.cpp
  requiredBy: []
  timestamp: '2025-01-29 15:54:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dp/levenshtein_distance.test.cpp
layout: document
redirect_from:
- /verify/verify/dp/levenshtein_distance.test.cpp
- /verify/verify/dp/levenshtein_distance.test.cpp.html
title: verify/dp/levenshtein_distance.test.cpp
---
