---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_3_d.test.cpp
    title: verify/aoj_dsl/aoj_dsl_3_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/sliding_window_minimum.hpp\"\n\ntemplate <class T> std::vector<T>\
    \ sliding_window_minimum(const std::vector<T> &a, const int k) {\n    int n =\
    \ (int)a.size();\n    std::vector<T> res(n - k + 1);\n    std::deque<T> deq;\n\
    \    for (int i = 0; i < n; i++) {\n        while (!deq.empty() and a[deq.back()]\
    \ >= a[i]) deq.pop_back();\n        deq.push_back(i);\n        if (i - k + 1 >=\
    \ 0) {\n            res[i - k + 1] = a[deq.front()];\n            if (deq.front()\
    \ == i - k + 1) deq.pop_front();\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\ntemplate <class T> std::vector<T> sliding_window_minimum(const\
    \ std::vector<T> &a, const int k) {\n    int n = (int)a.size();\n    std::vector<T>\
    \ res(n - k + 1);\n    std::deque<T> deq;\n    for (int i = 0; i < n; i++) {\n\
    \        while (!deq.empty() and a[deq.back()] >= a[i]) deq.pop_back();\n    \
    \    deq.push_back(i);\n        if (i - k + 1 >= 0) {\n            res[i - k +\
    \ 1] = a[deq.front()];\n            if (deq.front() == i - k + 1) deq.pop_front();\n\
    \        }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/sliding_window_minimum.hpp
  requiredBy: []
  timestamp: '2023-02-06 19:40:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_3_d.test.cpp
documentation_of: dp/sliding_window_minimum.hpp
layout: document
title: "Sliding Window Minimum (\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024)"
---

- 長さ $ n $ の数列 $ a $ と正整数 $k$ に対し、$ b_i = min \{ a_{i}, a_{i+1}, ... , a_{i+k-1} \} $ として定義される数列 $b$ を計算する
- $ O(n) $

### お気持ち
- 1つ右端を進めたら1つ左端を進める、というイメージでアルゴリズムは進み、デックに入れる値が常に小さい順になるようにすることで、先頭の値が最小値になるようにしている
