---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/longest_common_subsequence.hpp
    title: "Longest Common Subsequence (\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
  bundledCode: "#line 1 \"verify/aoj_alds1/aoj_alds1_10_c.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\n\n\
    #include <bits/stdc++.h>\n#line 2 \"dp/longest_common_subsequence.hpp\"\n\n#line\
    \ 5 \"dp/longest_common_subsequence.hpp\"\n\ntemplate <class T> std::vector<T>\
    \ longest_common_subsequence(std::vector<T>& a, std::vector<T>& b) {\n    const\
    \ int n = (int)(a.size()), m = (int)(b.size());\n    // -INF\n    constexpr int\
    \ e = -1000000000;\n    std::vector dp(n + 1, std::vector<int>(m + 1, e));\n \
    \   std::vector pd(n + 1, std::vector<int>(m + 1, -1));\n    // initialize\n \
    \   for (int i = 0; i < n + 1; i++) dp[i][0] = 0;\n    for (int j = 0; j < m +\
    \ 1; j++) dp[0][j] = 0;\n    // dp\n    for (int i = 0; i < n; i++) {\n      \
    \  for (int j = 0; j < m; j++) {\n            if (a[i] == b[j]) {\n          \
    \      if (dp[i + 1][j + 1] < dp[i][j] + 1) {\n                    dp[i + 1][j\
    \ + 1] = dp[i][j] + 1;\n                    pd[i + 1][j + 1] = 0;\n          \
    \      }\n            } else {\n                if (dp[i + 1][j + 1] < dp[i +\
    \ 1][j]) {\n                    dp[i + 1][j + 1] = dp[i + 1][j];\n           \
    \         pd[i + 1][j + 1] = 1;\n                }\n                if (dp[i +\
    \ 1][j + 1] < dp[i][j + 1]) {\n                    dp[i + 1][j + 1] = dp[i][j\
    \ + 1];\n                    pd[i + 1][j + 1] = 2;\n                }\n      \
    \      }\n        }\n    }\n    // \u5FA9\u5143\n    std::vector<T> res;\n   \
    \ res.reserve(dp[n][m]);\n    int i = n, j = m;\n    while (pd[i][j] != -1) {\n\
    \        if (pd[i][j] == 0) {\n            i--, j--;\n            res.push_back(a[i]);\n\
    \        } else if (pd[i][j] == 1) {\n            j--;\n        } else {\n   \
    \         // pd[i][j] == 2\n            i--;\n        }\n    }\n    std::reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\nstd::string longest_common_subsequence(std::string&\
    \ s, std::string& t) {\n    const int n = (int)(s.size()), m = (int)(t.size());\n\
    \    std::vector<int> a(n), b(m);\n    for (int i = 0; i < n; i++) a[i] = s[i];\n\
    \    for (int j = 0; j < m; j++) b[j] = t[j];\n    auto lcs = longest_common_subsequence(a,\
    \ b);\n    const int k = (int)(lcs.size());\n    std::string res;\n    res.reserve(k);\n\
    \    for (int i = 0; i < k; i++) res += lcs[i];\n    return res;\n}\n#line 5 \"\
    verify/aoj_alds1/aoj_alds1_10_c.test.cpp\"\n\nint main() {\n    int N;\n    std::cin\
    \ >> N;\n    for (int i = 0; i < N; i++) {\n        std::string s, t;\n      \
    \  std::cin >> s >> t;\n        std::cout << longest_common_subsequence(s, t).size()\
    \ << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#include <bits/stdc++.h>\n#include \"dp/longest_common_subsequence.hpp\"\n\
    \nint main() {\n    int N;\n    std::cin >> N;\n    for (int i = 0; i < N; i++)\
    \ {\n        std::string s, t;\n        std::cin >> s >> t;\n        std::cout\
    \ << longest_common_subsequence(s, t).size() << '\\n';\n    }\n    return 0;\n\
    }"
  dependsOn:
  - dp/longest_common_subsequence.hpp
  isVerificationFile: true
  path: verify/aoj_alds1/aoj_alds1_10_c.test.cpp
  requiredBy: []
  timestamp: '2024-04-30 20:58:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_alds1/aoj_alds1_10_c.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_alds1/aoj_alds1_10_c.test.cpp
- /verify/verify/aoj_alds1/aoj_alds1_10_c.test.cpp.html
title: verify/aoj_alds1/aoj_alds1_10_c.test.cpp
---
