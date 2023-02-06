---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/sliding_window_minimum.hpp
    title: "Sliding Window Minimum (\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"verify/aoj_dsl/aoj_dsl_3_d.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"dp/sliding_window_minimum.hpp\"\n\ntemplate <class\
    \ T> std::vector<T> sliding_window_minimum(const std::vector<T> &a, const int\
    \ k) {\n    int n = (int)a.size();\n    std::vector<T> res(n - k + 1);\n    std::deque<T>\
    \ deq;\n    for (int i = 0; i < n; i++) {\n        while (!deq.empty() and a[deq.back()]\
    \ >= a[i]) deq.pop_back();\n        deq.push_back(i);\n        if (i - k + 1 >=\
    \ 0) {\n            res[i - k + 1] = a[deq.front()];\n            if (deq.front()\
    \ == i - k + 1) deq.pop_front();\n        }\n    }\n    return res;\n}\n#line\
    \ 6 \"verify/aoj_dsl/aoj_dsl_3_d.test.cpp\"\n\nint main() {\n    int N, L;\n \
    \   std::cin >> N >> L;\n    std::vector<int> a(N);\n    for (int i = 0; i < N;\
    \ i++) std::cin >> a[i];\n    auto b = sliding_window_minimum(a, L);\n    for\
    \ (int i = 0; i < N - L + 1; i++) std::cout << b[i] << \" \\n\"[i == N - L];\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"dp/sliding_window_minimum.hpp\"\n\n\
    int main() {\n    int N, L;\n    std::cin >> N >> L;\n    std::vector<int> a(N);\n\
    \    for (int i = 0; i < N; i++) std::cin >> a[i];\n    auto b = sliding_window_minimum(a,\
    \ L);\n    for (int i = 0; i < N - L + 1; i++) std::cout << b[i] << \" \\n\"[i\
    \ == N - L];\n    return 0;\n}"
  dependsOn:
  - dp/sliding_window_minimum.hpp
  isVerificationFile: true
  path: verify/aoj_dsl/aoj_dsl_3_d.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 19:40:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_dsl/aoj_dsl_3_d.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dsl/aoj_dsl_3_d.test.cpp
- /verify/verify/aoj_dsl/aoj_dsl_3_d.test.cpp.html
title: verify/aoj_dsl/aoj_dsl_3_d.test.cpp
---
