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

### お気持ち

- 高さを $ h_i $ と決め打つと、左右に広げるイメージで、左側で初めて $ h_i > h_j $ となる $ j $ と、右側で初めて $ h_i > h_j $ となる $ j $ の両方が求められれば良い。前者について考えることにする。
- $ i=0,1,2,... $ の順 (昇順) に計算しているとする。$ i $ の計算が終わり、$ i+1 $ の計算を行う場合、$ 0,1,...,i $ が $ j $ の候補となるのだが (※いずれも $ j $ とならない場合もある)、実際には $j=i,i-1,i-2,...,0 $ の順 (降順) で見たときに、それまでに見ていた $ h_j $ と $ h_{i+1} $ の最小値を更新した添字のみが候補になる。(そうでない添字が選ばれるとしたら、もっと早い段階で $ h_i > h_j $ となる $ j $ が出てきているはずである)
- しかもここで候補となっていない添字は $i+2,i+3,...,n-1$ に対する計算でも出てくることがない。(最小値を更新する、という条件が、$h_{i+2}, h_{i+3},...$ の登場によりどんどん厳しくなるだけなため)
- よってこの候補をスタックで管理すれば良い
- 後者については $ i $ の降順に計算すれば同じようにできる
