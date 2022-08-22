---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwicktree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/lc_data_structure/lc_point_add_range_sum_fenwicktree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"src/data_structure/fenwicktree.hpp\"\
    \n\ntemplate <class T> struct fenwicktree {\n    int N;\n    std::vector<T> seg;\n\
    \    fenwicktree(int N) : N(N), seg(N + 1, 0) {}\n    fenwicktree(std::vector<T>\
    \ &A) {\n        N = (int)A.size();\n        seg.resize(N + 1);\n        for (int\
    \ i = 0; i < N; i++) add(i, A[i]);\n    }\n    // A[i] += x\n    void add(int\
    \ i, T x) {\n        i++;  // 1-indexed\n        while (i <= N) {\n          \
    \  seg[i] += x;\n            i += i & -i;\n        }\n    }\n    // A[0] + ...\
    \ + A[i - 1]\n    T sum(int i) {\n        T s = 0;\n        while (i > 0) {\n\
    \            s += seg[i];\n            i -= i & -i;\n        }\n        return\
    \ s;\n    }\n    // A[a] + ... + A[b - 1]\n    T sum(int a, int b) { return sum(b)\
    \ - sum(a); }\n};\n\n/**\n * @brief Fenwick Tree (Binary Indexed Tree)\n * @docs\
    \ docs/data_structure/fenwicktree.md\n */\n#line 7 \"verify/lc_data_structure/lc_point_add_range_sum_fenwicktree.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    std::vector<long long>\
    \ a(N);\n    for (int i = 0; i < N; i++) cin >> a[i];\n    fenwicktree<long long>\
    \ fen(a);\n    while (Q--) {\n        int t;\n        cin >> t;\n        if (t\
    \ == 0) {\n            int p, x;\n            cin >> p >> x;\n            fen.add(p,\
    \ x);\n        } else {\n            int l, r;\n            cin >> l >> r;\n \
    \           cout << fen.sum(l, r) << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../src/data_structure/fenwicktree.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    std::vector<long long>\
    \ a(N);\n    for (int i = 0; i < N; i++) cin >> a[i];\n    fenwicktree<long long>\
    \ fen(a);\n    while (Q--) {\n        int t;\n        cin >> t;\n        if (t\
    \ == 0) {\n            int p, x;\n            cin >> p >> x;\n            fen.add(p,\
    \ x);\n        } else {\n            int l, r;\n            cin >> l >> r;\n \
    \           cout << fen.sum(l, r) << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  dependsOn:
  - src/data_structure/fenwicktree.hpp
  isVerificationFile: true
  path: verify/lc_data_structure/lc_point_add_range_sum_fenwicktree.test.cpp
  requiredBy: []
  timestamp: '2022-08-22 19:08:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_data_structure/lc_point_add_range_sum_fenwicktree.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_data_structure/lc_point_add_range_sum_fenwicktree.test.cpp
- /verify/verify/lc_data_structure/lc_point_add_range_sum_fenwicktree.test.cpp.html
title: verify/lc_data_structure/lc_point_add_range_sum_fenwicktree.test.cpp
---
