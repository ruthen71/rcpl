---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dpl/aoj_dpl_1_g.test.cpp
    title: verify/aoj_dpl/aoj_dpl_1_g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/knapsack_limitations.hpp\"\n\ntemplate <class T, class\
    \ F = std::greater<T>>\nstd::vector<T> knapsack_limitations(const std::vector<int>\
    \ &w, const std::vector<T> &v, const std::vector<int> &m,  //\n              \
    \                      const int W, const T &e, const F &comp = F(), const int\
    \ s = 0) {\n    const int n = (int)w.size();\n    std::vector<T> dp(W + 1, e),\
    \ deqv(W + 1);\n    std::vector<int> deq(W + 1);\n    dp[s] = T(0);\n    for (int\
    \ i = 0; i < n; i++) {\n        if (w[i] > 0) {\n            for (int a = 0; a\
    \ < w[i]; a++) {\n                int s = 0, t = 0;\n                for (int\
    \ j = 0; a + j * w[i] <= W; j++) {\n                    if (dp[a + j * w[i]] !=\
    \ e) {\n                        T val = dp[a + j * w[i]] - j * v[i];\n       \
    \                 while (s < t and comp(val, deqv[t - 1])) t--;\n            \
    \            deq[t] = j;\n                        deqv[t++] = val;\n         \
    \           }\n                    if (s < t) {\n                        dp[a\
    \ + j * w[i]] = deqv[s] + j * v[i];\n                        if (deq[s] == j -\
    \ m[i]) s++;\n                    }\n                }\n            }\n      \
    \  } else if (w[i] < 0) {\n            for (int a = 0; a < -w[i]; a++) {\n   \
    \             int s = 0, t = 0;\n                for (int j = 0; W - a + j * w[i]\
    \ >= 0; j++) {\n                    if (dp[W - a + j * w[i]] != e) {\n       \
    \                 T val = dp[W - a + j * w[i]] - j * v[i];\n                 \
    \       while (s < t and comp(val, deqv[t - 1])) t--;\n                      \
    \  deq[t] = j;\n                        deqv[t++] = val;\n                   \
    \ }\n                    if (s < t) {\n                        dp[W - a + j *\
    \ w[i]] = deqv[s] + j * v[i];\n                        if (deq[s] == j - m[i])\
    \ s++;\n                    }\n                }\n            }\n        } else\
    \ {\n            // w[i] = 0\n            continue;\n        }\n    }\n    return\
    \ dp;\n}\n"
  code: "#pragma once\n\ntemplate <class T, class F = std::greater<T>>\nstd::vector<T>\
    \ knapsack_limitations(const std::vector<int> &w, const std::vector<T> &v, const\
    \ std::vector<int> &m,  //\n                                    const int W, const\
    \ T &e, const F &comp = F(), const int s = 0) {\n    const int n = (int)w.size();\n\
    \    std::vector<T> dp(W + 1, e), deqv(W + 1);\n    std::vector<int> deq(W + 1);\n\
    \    dp[s] = T(0);\n    for (int i = 0; i < n; i++) {\n        if (w[i] > 0) {\n\
    \            for (int a = 0; a < w[i]; a++) {\n                int s = 0, t =\
    \ 0;\n                for (int j = 0; a + j * w[i] <= W; j++) {\n            \
    \        if (dp[a + j * w[i]] != e) {\n                        T val = dp[a +\
    \ j * w[i]] - j * v[i];\n                        while (s < t and comp(val, deqv[t\
    \ - 1])) t--;\n                        deq[t] = j;\n                        deqv[t++]\
    \ = val;\n                    }\n                    if (s < t) {\n          \
    \              dp[a + j * w[i]] = deqv[s] + j * v[i];\n                      \
    \  if (deq[s] == j - m[i]) s++;\n                    }\n                }\n  \
    \          }\n        } else if (w[i] < 0) {\n            for (int a = 0; a <\
    \ -w[i]; a++) {\n                int s = 0, t = 0;\n                for (int j\
    \ = 0; W - a + j * w[i] >= 0; j++) {\n                    if (dp[W - a + j * w[i]]\
    \ != e) {\n                        T val = dp[W - a + j * w[i]] - j * v[i];\n\
    \                        while (s < t and comp(val, deqv[t - 1])) t--;\n     \
    \                   deq[t] = j;\n                        deqv[t++] = val;\n  \
    \                  }\n                    if (s < t) {\n                     \
    \   dp[W - a + j * w[i]] = deqv[s] + j * v[i];\n                        if (deq[s]\
    \ == j - m[i]) s++;\n                    }\n                }\n            }\n\
    \        } else {\n            // w[i] = 0\n            continue;\n        }\n\
    \    }\n    return dp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/knapsack_limitations.hpp
  requiredBy: []
  timestamp: '2023-02-06 19:40:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dpl/aoj_dpl_1_g.test.cpp
documentation_of: dp/knapsack_limitations.hpp
layout: document
title: "Knapsack Limitations (\u500B\u6570\u5236\u9650\u4ED8\u304D\u30CA\u30C3\u30D7\
  \u30B5\u30C3\u30AF\u554F\u984C)"
---

- 個数制限付きナップサック問題をスライド最大値のテクニックを使って解く
    - `w` : 荷物の重さ
    - `v` : 荷物の価値
    - `m` : 荷物の個数
    - `W` : ナップサックの容量
    - `e` : 価値の総和として絶対に取らない値 (普通のナップサック問題なら-1など)
    - `comp` : 比較関数 (最小値を求めたいときには `std::less` を使う)
    - `s` : 初期値 (普通は0だが、部分和問題などでは違うかもしれない)
- $ O(nW) $
- 部分和問題を解くために `w[i] < 0` の処理も加えた

## 使用例
- [ABC269-G](https://atcoder.jp/contests/abc269/submissions/35003309)
    - `w[i] < 0` の処理を加えたおかげ
- [ABC286-D](https://atcoder.jp/contests/abc286/submissions/38232340)
    - $ O \left( X \sum_{i=1}^{N} B_{i} \right) $ で通る制約なので必要ないが、$ O(XN) $ で解くなら必要

