---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dpl/aoj_dpl_1_d.test.cpp
    title: verify/aoj_dpl/aoj_dpl_1_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/longest_increasing_subsequence.hpp\"\n\n#include <vector>\n\
    #include <limits>\n#include <algorithm>\n\ntemplate <class T> int longest_increasing_subsequence(const\
    \ std::vector<T>& a, bool strict = true) {\n    // strict = true  -> A[i] <  A[i\
    \ + 1]\n    // strict = false -> A[i] <= A[i + 1]\n    const int n = (int)(a.size());\n\
    \    const T INF = std::numeric_limits<T>::max();\n    std::vector<T> dp(n, INF);\n\
    \    // dp \u914D\u5217\u4E2D\u306B A[i] \u304C\u3042\u3063\u305F\u3068\u304D\u306B\
    , \u3069\u306E\u5024\u3092\u66F8\u304D\u63DB\u3048\u308B\u304B\u3092\u8003\u3048\
    \u308B\u3068 lower \u304B upper \u3092\u533A\u5225\u3067\u304D\u308B\n    if (strict)\
    \ {\n        for (int i = 0; i < n; i++) {\n            *std::lower_bound(dp.begin(),\
    \ dp.end(), a[i]) = a[i];  // strict \u306A\u306E\u3067\u305D\u306E\u5024\n  \
    \      }\n    } else {\n        for (int i = 0; i < n; i++) {\n            *std::upper_bound(dp.begin(),\
    \ dp.end(), a[i]) = a[i];  // strict \u3067\u306F\u306A\u3044\u306E\u3067\u305D\
    \u306E\u6B21\u306E\u5024\n        }\n    }\n    return lower_bound(dp.begin(),\
    \ dp.end(), INF) - dp.begin();\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <limits>\n#include <algorithm>\n\
    \ntemplate <class T> int longest_increasing_subsequence(const std::vector<T>&\
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
    \ dp.end(), INF) - dp.begin();\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2024-07-04 21:01:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dpl/aoj_dpl_1_d.test.cpp
documentation_of: dp/longest_increasing_subsequence.hpp
layout: document
title: "Longest Increasing Subsequence (\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\
  )"
---

`dp[i] = 長さ i + 1 の LIS の末尾の最小値` として求める

`strict = true` では狭義単調増加列を、`strict = false` では広義単調増加列を求める
