---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dpl/aoj_dpl_3_c.test.cpp
    title: verify/aoj_dpl/aoj_dpl_3_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dp/histogram_largest_rectangle.md
    document_title: "histogram largest rectangle (\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\
      \u306E\u6700\u5927\u9577\u65B9\u5F62)"
    links: []
  bundledCode: "#line 2 \"src/dp/histogram_largest_rectangle.hpp\"\n\ntemplate <class\
    \ T> T histogram_largest_rectangle(std::vector<T> &h) {\n    int n = (int)h.size();\n\
    \    std::vector<int> st(n), L(n), R(n);\n    int t = 0;\n    for (int i = 0;\
    \ i < n; i++) {\n        while (t > 0 and h[st[t - 1]] >= h[i]) t--;\n       \
    \ L[i] = (t == 0 ? 0 : st[t - 1] + 1);\n        st[t++] = i;\n    }\n    t = 0;\n\
    \    for (int i = n - 1; i >= 0; i--) {\n        while (t > 0 and h[st[t - 1]]\
    \ >= h[i]) t--;\n        R[i] = (t == 0 ? n : st[t - 1]);\n        st[t++] = i;\n\
    \    }\n    T res = 0;\n    for (int i = 0; i < n; i++) res = std::max(res, h[i]\
    \ * (R[i] - L[i]));\n    return res;\n}\n\n/**\n * @brief histogram largest rectangle\
    \ (\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u306E\u6700\u5927\u9577\u65B9\u5F62)\n\
    \ * @docs docs/dp/histogram_largest_rectangle.md\n */\n"
  code: "#pragma once\n\ntemplate <class T> T histogram_largest_rectangle(std::vector<T>\
    \ &h) {\n    int n = (int)h.size();\n    std::vector<int> st(n), L(n), R(n);\n\
    \    int t = 0;\n    for (int i = 0; i < n; i++) {\n        while (t > 0 and h[st[t\
    \ - 1]] >= h[i]) t--;\n        L[i] = (t == 0 ? 0 : st[t - 1] + 1);\n        st[t++]\
    \ = i;\n    }\n    t = 0;\n    for (int i = n - 1; i >= 0; i--) {\n        while\
    \ (t > 0 and h[st[t - 1]] >= h[i]) t--;\n        R[i] = (t == 0 ? n : st[t - 1]);\n\
    \        st[t++] = i;\n    }\n    T res = 0;\n    for (int i = 0; i < n; i++)\
    \ res = std::max(res, h[i] * (R[i] - L[i]));\n    return res;\n}\n\n/**\n * @brief\
    \ histogram largest rectangle (\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u306E\u6700\
    \u5927\u9577\u65B9\u5F62)\n * @docs docs/dp/histogram_largest_rectangle.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/histogram_largest_rectangle.hpp
  requiredBy: []
  timestamp: '2022-09-19 18:59:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dpl/aoj_dpl_3_c.test.cpp
documentation_of: src/dp/histogram_largest_rectangle.hpp
layout: document
redirect_from:
- /library/src/dp/histogram_largest_rectangle.hpp
- /library/src/dp/histogram_largest_rectangle.hpp.html
title: "histogram largest rectangle (\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u306E\u6700\
  \u5927\u9577\u65B9\u5F62)"
---
## 概要

- ヒストグラムの最大長方形を求める
- $ O(N) $
