---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  - icon: ':heavy_check_mark:'
    path: src/dp/inversion_number.hpp
    title: "Inversion Number (\u8EE2\u5012\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"verify/aoj_alds1/aoj_alds1_5_d.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\n\n\
    #include <bits/stdc++.h>\n\n#line 2 \"src/dp/inversion_number.hpp\"\n\n#line 2\
    \ \"src/data_structure/fenwick_tree.hpp\"\n\ntemplate <class T> struct fenwick_tree\
    \ {\n    int N;\n    std::vector<T> seg;\n    fenwick_tree(int N) : N(N), seg(N\
    \ + 1, 0) {}\n    fenwick_tree(std::vector<T> &A) {\n        N = (int)A.size();\n\
    \        seg.resize(N + 1);\n        for (int i = 0; i < N; i++) add(i, A[i]);\n\
    \    }\n    // A[i] += x\n    void add(int i, T x) {\n        assert(0 <= i and\
    \ i < N);\n        i++;  // 1-indexed\n        while (i <= N) {\n            seg[i]\
    \ += x;\n            i += i & -i;\n        }\n    }\n    // A[0] + ... + A[i -\
    \ 1]\n    T sum(int i) const {\n        assert(0 <= i and i <= N);\n        T\
    \ s = 0;\n        while (i > 0) {\n            s += seg[i];\n            i -=\
    \ i & -i;\n        }\n        return s;\n    }\n    // A[a] + ... + A[b - 1]\n\
    \    T sum(int a, int b) const {\n        assert(0 <= a and a <= b and b <= N);\n\
    \        return sum(b) - sum(a);\n    }\n\n    // output\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const fenwick_tree &A) {\n        for (int i =\
    \ 0; i < A.N; i++) os << A.sum(i, i + 1) << \" \\n\"[i == A.N - 1];\n        return\
    \ os;\n    }\n};\n\n/**\n * @brief Fenwick Tree (Binary Indexed Tree)\n * @docs\
    \ docs/data_structure/fenwick_tree.md\n */\n#line 4 \"src/dp/inversion_number.hpp\"\
    \n\ntemplate <class T> long long inversion_number(std::vector<T>& A) {\n    auto\
    \ B = A;\n    sort(B.begin(), B.end());\n    B.erase(unique(B.begin(), B.end()),\
    \ B.end());\n    int N = (int)B.size();\n    fenwick_tree<int> fen(N);\n    long\
    \ long ret = 0;\n    for (auto& ai : A) {\n        int i = lower_bound(B.begin(),\
    \ B.end(), ai) - B.begin();\n        ret += fen.sum(i + 1, N);\n        fen.add(i,\
    \ 1);\n    }\n    return ret;\n}\n\n/**\n * @brief Inversion Number (\u8EE2\u5012\
    \u6570)\n * @docs docs/dp/inversion_number.md\n */\n#line 6 \"verify/aoj_alds1/aoj_alds1_5_d.test.cpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    std::vector<int> A(N);\n\
    \    for (int i = 0; i < N; i++) std::cin >> A[i];\n    std::cout << inversion_number<int>(A)\
    \ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"src/dp/inversion_number.hpp\"\n\nint\
    \ main() {\n    int N;\n    std::cin >> N;\n    std::vector<int> A(N);\n    for\
    \ (int i = 0; i < N; i++) std::cin >> A[i];\n    std::cout << inversion_number<int>(A)\
    \ << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - src/dp/inversion_number.hpp
  - src/data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/aoj_alds1/aoj_alds1_5_d.test.cpp
  requiredBy: []
  timestamp: '2022-08-30 02:21:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_alds1/aoj_alds1_5_d.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_alds1/aoj_alds1_5_d.test.cpp
- /verify/verify/aoj_alds1/aoj_alds1_5_d.test.cpp.html
title: verify/aoj_alds1/aoj_alds1_5_d.test.cpp
---