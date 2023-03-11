---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  - icon: ':heavy_check_mark:'
    path: misc/mo.hpp
    title: Mo's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"verify/lc_data_structure/lc_static_range_inversions_query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"misc/mo.hpp\"\n\n// Mo's Algorithm\n\
    // https://snuke.hatenablog.com/entry/2016/07/01/000000\n// complexity: O(N^2/B\
    \ + QB)\n// -> O(N sqrt(Q)) (B := N / sqrt(Q))\ntemplate <class AddLeft, class\
    \ AddRight, class DelLeft, class DelRight, class Out>  //\nvoid mo(const int &n,\
    \ const std::vector<int> &l, const std::vector<int> &r,         //\n        const\
    \ AddLeft &add_left, const AddRight &add_right,                         //\n \
    \       const DelLeft &del_left, const DelRight &del_right, const Out &out) {\n\
    \    const int q = (int)l.size();\n    // normal\n    // const int bucket_size\
    \ = n / std::min(n, (int)sqrt(q));\n    // speed up by https://nyaannyaan.github.io/library/misc/mo.hpp\n\
    \    const int bucket_size = n / std::min(n, (int)sqrt(2.0 * q / 3.0));\n    std::vector<int>\
    \ ind(q), lbs(q);\n    // reduce the number of divisions by memoization\n    for\
    \ (int i = 0; i < q; i++) lbs[i] = l[i] / bucket_size;\n    std::iota(ind.begin(),\
    \ ind.end(), 0);\n    std::sort(ind.begin(), ind.end(), [&](int i, int j) {\n\
    \        if (lbs[i] != lbs[j]) return l[i] < l[j];\n        return (lbs[i] & 1)\
    \ ? r[i] > r[j] : r[i] < r[j];\n    });\n    int now_l = l[ind[0]], now_r = now_l;\n\
    \    for (auto &&i : ind) {\n        while (now_l > l[i]) add_left(--now_l);\n\
    \        while (now_r < r[i]) add_right(now_r++);\n        while (now_l < l[i])\
    \ del_left(now_l++);\n        while (now_r > r[i]) del_right(--now_r);\n     \
    \   out(i);\n    }\n}\n\ntemplate <class Add, class Del, class Out>          \
    \                        //\nvoid mo(const int n, const std::vector<int> &l, const\
    \ std::vector<int> &r,  //\n        const Add &add, const Del &del, const Out\
    \ &out) {\n    mo(n, l, r, add, add, del, del, out);\n}\n#line 2 \"data_structure/fenwick_tree.hpp\"\
    \n\ntemplate <class T> struct FenwickTree {\n    int N;\n    std::vector<T> seg;\n\
    \    FenwickTree(int N) : N(N), seg(N + 1, 0) {}\n    FenwickTree(std::vector<T>\
    \ &A) {\n        N = (int)A.size();\n        seg.resize(N + 1);\n        for (int\
    \ i = 0; i < N; i++) add(i, A[i]);\n    }\n    // A[i] += x\n    void add(int\
    \ i, T x) {\n        assert(0 <= i and i < N);\n        i++;  // 1-indexed\n \
    \       while (i <= N) {\n            seg[i] += x;\n            i += i & -i;\n\
    \        }\n    }\n    // A[0] + ... + A[i - 1]\n    T sum(int i) const {\n  \
    \      assert(0 <= i and i <= N);\n        T s = 0;\n        while (i > 0) {\n\
    \            s += seg[i];\n            i -= i & -i;\n        }\n        return\
    \ s;\n    }\n    // A[a] + ... + A[b - 1]\n    T sum(int a, int b) const {\n \
    \       assert(0 <= a and a <= b and b <= N);\n        return sum(b) - sum(a);\n\
    \    }\n\n    // output\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const FenwickTree &A) {\n        for (int i = 0; i < A.N; i++) os << A.sum(i,\
    \ i + 1) << \" \\n\"[i == A.N - 1];\n        return os;\n    }\n};\n#line 7 \"\
    verify/lc_data_structure/lc_static_range_inversions_query.test.cpp\"\n\nint main()\
    \ {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for\
    \ (int i = 0; i < N; i++) std::cin >> A[i];\n    std::vector<int> L(Q), R(Q);\n\
    \    for (int i = 0; i < Q; i++) std::cin >> L[i] >> R[i];\n\n    auto B = A;\n\
    \    std::sort(B.begin(), B.end());\n    B.erase(std::unique(B.begin(), B.end()),\
    \ B.end());\n    for (auto &&e : A) e = std::lower_bound(B.begin(), B.end(), e)\
    \ - B.begin();\n\n    const int M = (int)B.size();\n    FenwickTree<long long>\
    \ fen(M);\n    std::vector<long long> ans(Q);\n    long long cur = 0;\n    auto\
    \ add_left = [&](int i) {\n        cur += fen.sum(A[i]);\n        fen.add(A[i],\
    \ 1);\n    };\n    auto add_right = [&](int i) {\n        cur += fen.sum(A[i]\
    \ + 1, M);\n        fen.add(A[i], 1);\n    };\n    auto del_left = [&](int i)\
    \ {\n        cur -= fen.sum(A[i]);\n        fen.add(A[i], -1);\n    };\n    auto\
    \ del_right = [&](int i) {\n        cur -= fen.sum(A[i] + 1, M);\n        fen.add(A[i],\
    \ -1);\n    };\n    auto out = [&](int i) { ans[i] = cur; };\n    mo(N, L, R,\
    \ add_left, add_right, del_left, del_right, out);\n    for (int i = 0; i < Q;\
    \ i++) std::cout << ans[i] << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"misc/mo.hpp\"\n#include \"data_structure/fenwick_tree.hpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int>\
    \ A(N);\n    for (int i = 0; i < N; i++) std::cin >> A[i];\n    std::vector<int>\
    \ L(Q), R(Q);\n    for (int i = 0; i < Q; i++) std::cin >> L[i] >> R[i];\n\n \
    \   auto B = A;\n    std::sort(B.begin(), B.end());\n    B.erase(std::unique(B.begin(),\
    \ B.end()), B.end());\n    for (auto &&e : A) e = std::lower_bound(B.begin(),\
    \ B.end(), e) - B.begin();\n\n    const int M = (int)B.size();\n    FenwickTree<long\
    \ long> fen(M);\n    std::vector<long long> ans(Q);\n    long long cur = 0;\n\
    \    auto add_left = [&](int i) {\n        cur += fen.sum(A[i]);\n        fen.add(A[i],\
    \ 1);\n    };\n    auto add_right = [&](int i) {\n        cur += fen.sum(A[i]\
    \ + 1, M);\n        fen.add(A[i], 1);\n    };\n    auto del_left = [&](int i)\
    \ {\n        cur -= fen.sum(A[i]);\n        fen.add(A[i], -1);\n    };\n    auto\
    \ del_right = [&](int i) {\n        cur -= fen.sum(A[i] + 1, M);\n        fen.add(A[i],\
    \ -1);\n    };\n    auto out = [&](int i) { ans[i] = cur; };\n    mo(N, L, R,\
    \ add_left, add_right, del_left, del_right, out);\n    for (int i = 0; i < Q;\
    \ i++) std::cout << ans[i] << '\\n';\n    return 0;\n}"
  dependsOn:
  - misc/mo.hpp
  - data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/lc_data_structure/lc_static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2023-03-12 07:07:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_data_structure/lc_static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_data_structure/lc_static_range_inversions_query.test.cpp
- /verify/verify/lc_data_structure/lc_static_range_inversions_query.test.cpp.html
title: verify/lc_data_structure/lc_static_range_inversions_query.test.cpp
---
