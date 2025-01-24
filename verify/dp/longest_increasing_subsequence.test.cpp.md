---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/longest_increasing_subsequence.hpp
    title: "Longest Increasing Subsequence (\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "#line 1 \"verify/dp/longest_increasing_subsequence.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"dp/longest_increasing_subsequence.hpp\"\
    \n\n#line 4 \"dp/longest_increasing_subsequence.hpp\"\n#include <limits>\n#include\
    \ <algorithm>\n\ntemplate <class T> int longest_increasing_subsequence(const std::vector<T>&\
    \ a, bool strict = true) {\n    // strict = true  -> A[i] <  A[i + 1]\n    //\
    \ strict = false -> A[i] <= A[i + 1]\n    const int n = (int)(a.size());\n   \
    \ const T INF = std::numeric_limits<T>::max();\n    std::vector<T> dp(n, INF);\n\
    \    // dp \u914D\u5217\u4E2D\u306B A[i] \u304C\u3042\u3063\u305F\u3068\u304D\u306B\
    , \u3069\u306E\u5024\u3092\u66F8\u304D\u63DB\u3048\u308B\u304B\u3092\u8003\u3048\
    \u308B\u3068 lower \u304B upper \u3092\u533A\u5225\u3067\u304D\u308B\n    if (strict)\
    \ {\n        for (int i = 0; i < n; i++) {\n            *std::lower_bound(dp.begin(),\
    \ dp.end(), a[i]) = a[i];  // strict \u306A\u306E\u3067\u305D\u306E\u5024\n  \
    \      }\n    } else {\n        for (int i = 0; i < n; i++) {\n            *std::upper_bound(dp.begin(),\
    \ dp.end(), a[i]) = a[i];  // strict \u3067\u306F\u306A\u3044\u306E\u3067\u305D\
    \u306E\u6B21\u306E\u5024\n        }\n    }\n    return lower_bound(dp.begin(),\
    \ dp.end(), INF) - dp.begin();\n}\n#line 7 \"verify/dp/longest_increasing_subsequence.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n\
    \    for (int i = 0; i < n; i++) std::cin >> a[i];\n    std::cout << longest_increasing_subsequence(a)\
    \ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"dp/longest_increasing_subsequence.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n\
    \    for (int i = 0; i < n; i++) std::cin >> a[i];\n    std::cout << longest_increasing_subsequence(a)\
    \ << '\\n';\n    return 0;\n}"
  dependsOn:
  - dp/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: verify/dp/longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2025-01-24 21:00:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dp/longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/verify/dp/longest_increasing_subsequence.test.cpp
- /verify/verify/dp/longest_increasing_subsequence.test.cpp.html
title: verify/dp/longest_increasing_subsequence.test.cpp
---
