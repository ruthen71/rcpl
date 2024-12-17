---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
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
  bundledCode: "#line 1 \"verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\n\n#line 2 \"data_structure/fenwick_tree.hpp\"\n\n#line\
    \ 5 \"data_structure/fenwick_tree.hpp\"\n\ntemplate <class T> struct FenwickTree\
    \ {\n    int n;\n    std::vector<T> seg;\n    FenwickTree() : n(0) {}\n    FenwickTree(int\
    \ n) : n(n), seg(n + 1, 0) {}\n    FenwickTree(std::vector<T>& arr) {\n      \
    \  n = int(arr.size());\n        seg.resize(n + 1);\n        for (int i = 0; i\
    \ < n; i++) add(i, arr[i]);\n    }\n    // A[i] += x\n    void add(int i, const\
    \ T& x) {\n        assert(0 <= i and i < n);\n        i++;  // 1-indexed\n   \
    \     while (i <= n) {\n            seg[i] += x;\n            i += i & -i;\n \
    \       }\n    }\n    // A[0] + ... + A[i - 1]\n    T sum(int i) const {\n   \
    \     assert(0 <= i and i <= n);\n        T s = T(0);\n        while (i > 0) {\n\
    \            s += seg[i];\n            i -= i & -i;\n        }\n        return\
    \ s;\n    }\n    // A[a] + ... + A[b - 1]\n    T sum(int a, int b) const {\n \
    \       assert(0 <= a and a <= b and b <= n);\n        return sum(b) - sum(a);\n\
    \    }\n    // return A[i]\n    T get(int i) const { return sum(i, i + 1); }\n\
    \    // A[i] = x\n    void set(int i, const T x) { add(i, x - get(i)); }\n\n \
    \   std::vector<T> make_vector() {\n        std::vector<T> vec(n);\n        for\
    \ (int i = 0; i < n; i++) vec[i] = get(i);\n        return vec;\n    }\n};\n#line\
    \ 6 \"verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp\"\n\
    \nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<long long>\
    \ a(N);\n    for (int i = 0; i < N; i++) std::cin >> a[i];\n    FenwickTree<long\
    \ long> fen(a);\n    while (Q--) {\n        int t;\n        std::cin >> t;\n \
    \       if (t == 0) {\n            int p, x;\n            std::cin >> p >> x;\n\
    \            fen.add(p, x);\n        } else {\n            int l, r;\n       \
    \     std::cin >> l >> r;\n            std::cout << fen.sum(l, r) << '\\n';\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\n\n#include \"data_structure/fenwick_tree.hpp\"\n\n\
    int main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<long long>\
    \ a(N);\n    for (int i = 0; i < N; i++) std::cin >> a[i];\n    FenwickTree<long\
    \ long> fen(a);\n    while (Q--) {\n        int t;\n        std::cin >> t;\n \
    \       if (t == 0) {\n            int p, x;\n            std::cin >> p >> x;\n\
    \            fen.add(p, x);\n        } else {\n            int l, r;\n       \
    \     std::cin >> l >> r;\n            std::cout << fen.sum(l, r) << '\\n';\n\
    \        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2024-12-17 21:01:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
- /verify/verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp.html
title: verify/lc_data_structure/lc_point_add_range_sum_fenwick_tree.test.cpp
---
