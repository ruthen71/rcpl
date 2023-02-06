---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/cumulative_sum.hpp
    title: "\u7D2F\u7A4D\u548C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/lc_data_structure/lc_static_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"data_structure/cumulative_sum.hpp\"\n\ntemplate\
    \ <class T> struct cumulative_sum {\n    std::vector<T> seg;\n    int _n;\n\n\
    \    cumulative_sum(int _n) : _n(_n), seg(_n + 1, 0) {}\n    cumulative_sum(std::vector<T>\
    \ &A) {\n        _n = (int)A.size();\n        seg.assign(_n + 1, T(0));\n    \
    \    for (int i = 0; i < _n; i++) seg[i + 1] = seg[i] + A[i];\n    }\n\n    //\
    \ [l, r)\n    T sum(int l, int r) const {\n        assert(0 <= l and l <= r and\
    \ r <= _n);\n        return seg[r] - seg[l];\n    }\n\n    // A[p] = x\n    void\
    \ set(int p, T x) {\n        assert(0 <= p and p < _n);\n        seg[p + 1] =\
    \ x;\n    }\n\n    // A[p] += x\n    void add(int p, T x) {\n        assert(0\
    \ <= p and p < _n);\n        seg[p + 1] += x;\n    }\n\n    // A[l] += x, A[l\
    \ + 1] += x, ... , A[r - 1] += x\n    void imos(int l, int r, T x = T(1)) {\n\
    \        add(l, x);\n        add(r, -x);\n    }\n\n    void build() {\n      \
    \  for (int i = 0; i < _n; i++) seg[i + 1] += seg[i];\n    }\n\n    T operator[](int\
    \ p) const {\n        assert(0 <= p and p < _n);\n        return seg[p + 1];\n\
    \    }\n\n    // output\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const cumulative_sum &A) {\n        for (int i = 0; i <= A._n; i++) os << A.seg[i]\
    \ << \" \\n\"[i == A._n];\n        return os;\n    }\n};\n\n/**\n * @brief \u7D2F\
    \u7A4D\u548C\n * @docs docs/data_structure/cumulative_sum.md\n */\n#line 6 \"\
    verify/lc_data_structure/lc_static_range_sum.test.cpp\"\n\nint main() {\n    int\
    \ N, Q;\n    std::cin >> N >> Q;\n    std::vector<long long> A(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> A[i];\n    cumulative_sum<long long> rui(A);\n\
    \    while (Q--) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout\
    \ << rui.sum(l, r) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <bits/stdc++.h>\n\n#include \"data_structure/cumulative_sum.hpp\"\n\n\
    int main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<long long>\
    \ A(N);\n    for (int i = 0; i < N; i++) std::cin >> A[i];\n    cumulative_sum<long\
    \ long> rui(A);\n    while (Q--) {\n        int l, r;\n        std::cin >> l >>\
    \ r;\n        std::cout << rui.sum(l, r) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - data_structure/cumulative_sum.hpp
  isVerificationFile: true
  path: verify/lc_data_structure/lc_static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_data_structure/lc_static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_data_structure/lc_static_range_sum.test.cpp
- /verify/verify/lc_data_structure/lc_static_range_sum.test.cpp.html
title: verify/lc_data_structure/lc_static_range_sum.test.cpp
---
