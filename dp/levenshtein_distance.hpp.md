---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dp/levenshtein_distance.test.cpp
    title: verify/dp/levenshtein_distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/levenshtein_distance.hpp\"\n\n#include <vector>\n#include\
    \ <string>\n\ntemplate <class T>\nint levenshtein_distance(std::vector<T>& a,\
    \ std::vector<T>& b, const int inf = 1000000000) {\n    const int n = (int)(a.size()),\
    \ m = (int)(b.size());\n    std::vector dp(n + 1, std::vector<int>(m + 1, inf));\n\
    \    // initialize\n    for (int i = 0; i < n + 1; i++) dp[i][0] = i;\n    for\
    \ (int j = 0; j < m + 1; j++) dp[0][j] = j;\n    // dp\n    for (int i = 0; i\
    \ <= n; i++) {\n        for (int j = 0; j <= m; j++) {\n            // a += ?\n\
    \            if (j + 1 <= m and dp[i][j + 1] > dp[i][j] + 1) {\n             \
    \   dp[i][j + 1] = dp[i][j] + 1;\n            }\n            // b += ?\n     \
    \       if (i + 1 <= n and dp[i + 1][j] > dp[i][j] + 1) {\n                dp[i\
    \ + 1][j] = dp[i][j] + 1;\n            }\n            // a[i] = b[i]\n       \
    \     if (i + 1 <= n and j + 1 <= m) {\n                int cost = a[i] == b[j]\
    \ ? 0 : 1;\n                if (dp[i + 1][j + 1] > dp[i][j] + cost) {\n      \
    \              dp[i + 1][j + 1] = dp[i][j] + cost;\n                }\n      \
    \      }\n        }\n    }\n    return dp[n][m];\n}\n\nint levenshtein_distance(std::string&\
    \ s, std::string& t, const int inf = 1000000000) {\n    const int n = (int)(s.size()),\
    \ m = (int)(t.size());\n    std::vector<int> a(n), b(m);\n    for (int i = 0;\
    \ i < n; i++) a[i] = s[i];\n    for (int j = 0; j < m; j++) b[j] = t[j];\n   \
    \ return levenshtein_distance(a, b, inf);\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\ntemplate <class T>\n\
    int levenshtein_distance(std::vector<T>& a, std::vector<T>& b, const int inf =\
    \ 1000000000) {\n    const int n = (int)(a.size()), m = (int)(b.size());\n   \
    \ std::vector dp(n + 1, std::vector<int>(m + 1, inf));\n    // initialize\n  \
    \  for (int i = 0; i < n + 1; i++) dp[i][0] = i;\n    for (int j = 0; j < m +\
    \ 1; j++) dp[0][j] = j;\n    // dp\n    for (int i = 0; i <= n; i++) {\n     \
    \   for (int j = 0; j <= m; j++) {\n            // a += ?\n            if (j +\
    \ 1 <= m and dp[i][j + 1] > dp[i][j] + 1) {\n                dp[i][j + 1] = dp[i][j]\
    \ + 1;\n            }\n            // b += ?\n            if (i + 1 <= n and dp[i\
    \ + 1][j] > dp[i][j] + 1) {\n                dp[i + 1][j] = dp[i][j] + 1;\n  \
    \          }\n            // a[i] = b[i]\n            if (i + 1 <= n and j + 1\
    \ <= m) {\n                int cost = a[i] == b[j] ? 0 : 1;\n                if\
    \ (dp[i + 1][j + 1] > dp[i][j] + cost) {\n                    dp[i + 1][j + 1]\
    \ = dp[i][j] + cost;\n                }\n            }\n        }\n    }\n   \
    \ return dp[n][m];\n}\n\nint levenshtein_distance(std::string& s, std::string&\
    \ t, const int inf = 1000000000) {\n    const int n = (int)(s.size()), m = (int)(t.size());\n\
    \    std::vector<int> a(n), b(m);\n    for (int i = 0; i < n; i++) a[i] = s[i];\n\
    \    for (int j = 0; j < m; j++) b[j] = t[j];\n    return levenshtein_distance(a,\
    \ b, inf);\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/levenshtein_distance.hpp
  requiredBy: []
  timestamp: '2025-01-24 21:00:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dp/levenshtein_distance.test.cpp
documentation_of: dp/levenshtein_distance.hpp
layout: document
title: "Levenshtein Distance (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\
  \u8DDD\u96E2)"
---

Edit Distance (編集距離) とも呼ばれる
