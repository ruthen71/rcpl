---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/knapsack_limitations.hpp
    title: "Knapsack Limitations (\u500B\u6570\u5236\u9650\u4ED8\u304D\u30CA\u30C3\
      \u30D7\u30B5\u30C3\u30AF\u554F\u984C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G
  bundledCode: "#line 1 \"verify/aoj_dpl/aoj_dpl_1_g.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"dp/knapsack_limitations.hpp\"\n\ntemplate <class\
    \ T, class F = std::greater<T>>\nstd::vector<T> knapsack_limitations(const std::vector<int>\
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
    \ dp;\n}\n#line 6 \"verify/aoj_dpl/aoj_dpl_1_g.test.cpp\"\n\nint main() {\n  \
    \  int N, W;\n    std::cin >> N >> W;\n    std::vector<int> v(N), w(N), m(N);\n\
    \    for (int i = 0; i < N; i++) std::cin >> v[i] >> w[i] >> m[i];\n    auto ret1\
    \ = knapsack_limitations(w, v, m, W, -1);\n    auto ans1 = *std::max_element(ret1.begin(),\
    \ ret1.end());\n    for (int i = 0; i < N; i++) v[i] = -v[i];\n    auto ret2 =\
    \ knapsack_limitations(w, v, m, W, 1, std::less<int>());\n    auto ans2 = *std::min_element(ret2.begin(),\
    \ ret2.end());\n    assert(ans1 == -ans2);\n    std::cout << ans1 << '\\n';\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"dp/knapsack_limitations.hpp\"\n\nint\
    \ main() {\n    int N, W;\n    std::cin >> N >> W;\n    std::vector<int> v(N),\
    \ w(N), m(N);\n    for (int i = 0; i < N; i++) std::cin >> v[i] >> w[i] >> m[i];\n\
    \    auto ret1 = knapsack_limitations(w, v, m, W, -1);\n    auto ans1 = *std::max_element(ret1.begin(),\
    \ ret1.end());\n    for (int i = 0; i < N; i++) v[i] = -v[i];\n    auto ret2 =\
    \ knapsack_limitations(w, v, m, W, 1, std::less<int>());\n    auto ans2 = *std::min_element(ret2.begin(),\
    \ ret2.end());\n    assert(ans1 == -ans2);\n    std::cout << ans1 << '\\n';\n\
    \    return 0;\n}"
  dependsOn:
  - dp/knapsack_limitations.hpp
  isVerificationFile: true
  path: verify/aoj_dpl/aoj_dpl_1_g.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 19:40:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_dpl/aoj_dpl_1_g.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dpl/aoj_dpl_1_g.test.cpp
- /verify/verify/aoj_dpl/aoj_dpl_1_g.test.cpp.html
title: verify/aoj_dpl/aoj_dpl_1_g.test.cpp
---
