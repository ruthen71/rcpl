---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_alds1/aoj_alds1_10_c.test.cpp
    title: verify/aoj_alds1/aoj_alds1_10_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/longest_common_subsequence.hpp\"\n\n#include <vector>\n\
    #include <string>\n\ntemplate <class T> std::vector<T> longest_common_subsequence(std::vector<T>&\
    \ a, std::vector<T>& b) {\n    const int n = (int)(a.size()), m = (int)(b.size());\n\
    \    constexpr int e = -1000000000;  // -INF\n    std::vector dp(n + 1, std::vector<int>(m\
    \ + 1, e));\n    std::vector pd(n + 1, std::vector<int>(m + 1, -1));\n    // initialize\n\
    \    for (int i = 0; i < n + 1; i++) dp[i][0] = 0;\n    for (int j = 0; j < m\
    \ + 1; j++) dp[0][j] = 0;\n    // dp\n    for (int i = 0; i < n; i++) {\n    \
    \    for (int j = 0; j < m; j++) {\n            if (a[i] == b[j]) {\n        \
    \        if (dp[i + 1][j + 1] < dp[i][j] + 1) {\n                    dp[i + 1][j\
    \ + 1] = dp[i][j] + 1;\n                    pd[i + 1][j + 1] = 0;\n          \
    \      }\n            } else {\n                if (dp[i + 1][j + 1] < dp[i +\
    \ 1][j]) {\n                    dp[i + 1][j + 1] = dp[i + 1][j];\n           \
    \         pd[i + 1][j + 1] = 1;\n                }\n                if (dp[i +\
    \ 1][j + 1] < dp[i][j + 1]) {\n                    dp[i + 1][j + 1] = dp[i][j\
    \ + 1];\n                    pd[i + 1][j + 1] = 2;\n                }\n      \
    \      }\n        }\n    }\n    // \u5FA9\u5143\n    std::vector<T> res;\n   \
    \ res.reserve(dp[n][m]);\n    for (int i = n, j = m; pd[i][j] != -1;) {\n    \
    \    if (pd[i][j] == 0) {\n            i--, j--;\n            res.push_back(a[i]);\n\
    \        } else if (pd[i][j] == 1) {\n            j--;\n        } else {\n   \
    \         // pd[i][j] == 2\n            i--;\n        }\n    }\n    std::reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\nstd::string longest_common_subsequence(std::string&\
    \ s, std::string& t) {\n    const int n = (int)(s.size()), m = (int)(t.size());\n\
    \    std::vector<int> a(n), b(m);\n    for (int i = 0; i < n; i++) a[i] = s[i];\n\
    \    for (int j = 0; j < m; j++) b[j] = t[j];\n    auto lcs = longest_common_subsequence(a,\
    \ b);\n    const int k = (int)(lcs.size());\n    std::string res;\n    res.reserve(k);\n\
    \    for (int i = 0; i < k; i++) res += lcs[i];\n    return res;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\ntemplate <class T>\
    \ std::vector<T> longest_common_subsequence(std::vector<T>& a, std::vector<T>&\
    \ b) {\n    const int n = (int)(a.size()), m = (int)(b.size());\n    constexpr\
    \ int e = -1000000000;  // -INF\n    std::vector dp(n + 1, std::vector<int>(m\
    \ + 1, e));\n    std::vector pd(n + 1, std::vector<int>(m + 1, -1));\n    // initialize\n\
    \    for (int i = 0; i < n + 1; i++) dp[i][0] = 0;\n    for (int j = 0; j < m\
    \ + 1; j++) dp[0][j] = 0;\n    // dp\n    for (int i = 0; i < n; i++) {\n    \
    \    for (int j = 0; j < m; j++) {\n            if (a[i] == b[j]) {\n        \
    \        if (dp[i + 1][j + 1] < dp[i][j] + 1) {\n                    dp[i + 1][j\
    \ + 1] = dp[i][j] + 1;\n                    pd[i + 1][j + 1] = 0;\n          \
    \      }\n            } else {\n                if (dp[i + 1][j + 1] < dp[i +\
    \ 1][j]) {\n                    dp[i + 1][j + 1] = dp[i + 1][j];\n           \
    \         pd[i + 1][j + 1] = 1;\n                }\n                if (dp[i +\
    \ 1][j + 1] < dp[i][j + 1]) {\n                    dp[i + 1][j + 1] = dp[i][j\
    \ + 1];\n                    pd[i + 1][j + 1] = 2;\n                }\n      \
    \      }\n        }\n    }\n    // \u5FA9\u5143\n    std::vector<T> res;\n   \
    \ res.reserve(dp[n][m]);\n    for (int i = n, j = m; pd[i][j] != -1;) {\n    \
    \    if (pd[i][j] == 0) {\n            i--, j--;\n            res.push_back(a[i]);\n\
    \        } else if (pd[i][j] == 1) {\n            j--;\n        } else {\n   \
    \         // pd[i][j] == 2\n            i--;\n        }\n    }\n    std::reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\nstd::string longest_common_subsequence(std::string&\
    \ s, std::string& t) {\n    const int n = (int)(s.size()), m = (int)(t.size());\n\
    \    std::vector<int> a(n), b(m);\n    for (int i = 0; i < n; i++) a[i] = s[i];\n\
    \    for (int j = 0; j < m; j++) b[j] = t[j];\n    auto lcs = longest_common_subsequence(a,\
    \ b);\n    const int k = (int)(lcs.size());\n    std::string res;\n    res.reserve(k);\n\
    \    for (int i = 0; i < k; i++) res += lcs[i];\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/longest_common_subsequence.hpp
  requiredBy: []
  timestamp: '2024-04-30 21:09:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_alds1/aoj_alds1_10_c.test.cpp
documentation_of: dp/longest_common_subsequence.hpp
layout: document
title: "Longest Common Subsequence (\u6700\u9577\u5171\u901A\u90E8\u5206\u5217)"
---
