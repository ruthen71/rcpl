---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/histogram_largest_rectangle.hpp
    title: "histogram largest rectangle (\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u306E\
      \u6700\u5927\u9577\u65B9\u5F62)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
  bundledCode: "#line 1 \"verify/aoj_dpl/aoj_dpl_3_c.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"src/dp/histogram_largest_rectangle.hpp\"\n\ntemplate\
    \ <class T> T histogram_largest_rectangle(std::vector<T> &h) {\n    int n = (int)h.size();\n\
    \    std::vector<int> st(n), L(n), R(n);\n    int t = 0;\n    for (int i = 0;\
    \ i < n; i++) {\n        while (t > 0 and h[st[t - 1]] >= h[i]) t--;\n       \
    \ L[i] = (t == 0 ? 0 : st[t - 1] + 1);\n        st[t++] = i;\n    }\n    t = 0;\n\
    \    for (int i = n - 1; i >= 0; i--) {\n        while (t > 0 and h[st[t - 1]]\
    \ >= h[i]) t--;\n        R[i] = (t == 0 ? n : st[t - 1]);\n        st[t++] = i;\n\
    \    }\n    T res = 0;\n    for (int i = 0; i < n; i++) res = std::max(res, h[i]\
    \ * (R[i] - L[i]));\n    return res;\n}\n\n/**\n * @brief histogram largest rectangle\
    \ (\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u306E\u6700\u5927\u9577\u65B9\u5F62)\n\
    \ * @docs docs/dp/histogram_largest_rectangle.md\n */\n#line 6 \"verify/aoj_dpl/aoj_dpl_3_c.test.cpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    std::vector<long long> A(N);\n\
    \    for (int i = 0; i < N; i++) std::cin >> A[i];\n    std::cout << histogram_largest_rectangle(A)\
    \ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"src/dp/histogram_largest_rectangle.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    std::vector<long long> A(N);\n\
    \    for (int i = 0; i < N; i++) std::cin >> A[i];\n    std::cout << histogram_largest_rectangle(A)\
    \ << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/dp/histogram_largest_rectangle.hpp
  isVerificationFile: true
  path: verify/aoj_dpl/aoj_dpl_3_c.test.cpp
  requiredBy: []
  timestamp: '2022-09-19 18:59:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_dpl/aoj_dpl_3_c.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dpl/aoj_dpl_3_c.test.cpp
- /verify/verify/aoj_dpl/aoj_dpl_3_c.test.cpp.html
title: verify/aoj_dpl/aoj_dpl_3_c.test.cpp
---
