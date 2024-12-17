---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/fenwick_tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  - icon: ':x:'
    path: misc/mo.hpp
    title: Mo's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"verify/misc/mo.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <iostream>\n\n#line 2 \"misc/mo.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <numeric>\n\n// Mo's Algorithm\n// https://snuke.hatenablog.com/entry/2016/07/01/000000\n\
    // complexity: O(N * N / B + Q * B)\n// -> O(N sqrt(Q)) (B := N / sqrt(Q))\ntemplate\
    \ <class AddLeft, class AddRight, class DelLeft, class DelRight, class Out>\n\
    void mo(const int n, const std::vector<int> l, const std::vector<int> r, const\
    \ AddLeft &add_left,\n        const AddRight &add_right, const DelLeft &del_left,\
    \ const DelRight &del_right,\n        const Out &out, const int bucket_size_value\
    \ = -1) {\n    const int q = (int)(l.size());\n    if (q == 0) return;\n    //\
    \ determine bucket size\n    auto calculate_bucket_size = [&]() {\n        //\
    \ const int bucket_size = std::max(1.0, n / std::max(1.0, sqrt(q)));\n       \
    \ // speed up by https://nyaannyaan.github.io/library/misc/mo.hpp\n        const\
    \ int bucket_size = std::max(1.0, n / std::max(1.0, sqrt(2.0 * q / 3.0)));\n \
    \       return bucket_size;\n    };\n    const int bucket_size = bucket_size_value\
    \ == -1 ? calculate_bucket_size() : bucket_size_value;\n    std::vector<int> ind(q),\
    \ lbs(q);\n    // reduce the number of divisions by memoization\n    for (int\
    \ i = 0; i < q; i++) lbs[i] = l[i] / bucket_size;\n    std::iota(ind.begin(),\
    \ ind.end(), 0);\n    std::sort(ind.begin(), ind.end(), [&](int i, int j) {\n\
    \        if (lbs[i] != lbs[j]) return l[i] < l[j];\n        return (lbs[i] & 1)\
    \ ? r[i] > r[j] : r[i] < r[j];\n    });\n    // \u4EE5\u524D\u306F now_l = now_r\
    \ = l[ind.front()] \u3068\u3057\u3066\u3044\u305F\u304C, \u3053\u308C\u306F [now_l,\
    \ now_r) \u306B\u5BFE\u3059\u308B\u7B54\u3048\u304C\n    // [0, 0) \u3068\u540C\
    \u3058\u3067\u306A\u3044\u3068\u58CA\u308C\u308B\n    int now_l = 0, now_r = 0;\n\
    \    for (auto &&i : ind) {\n        while (now_l > l[i]) add_left(--now_l);\n\
    \        while (now_r < r[i]) add_right(now_r++);\n        while (now_l < l[i])\
    \ del_left(now_l++);\n        while (now_r > r[i]) del_right(--now_r);\n     \
    \   out(i);\n    }\n}\ntemplate <class Add, class Del, class Out>            \
    \                      //\nvoid mo(const int n, const std::vector<int> &l, const\
    \ std::vector<int> &r,  //\n        const Add &add, const Del &del, const Out\
    \ &out, const int bucket_size_value = -1) {\n    mo(n, l, r, add, add, del, del,\
    \ out, bucket_size_value);\n}\n#line 2 \"data_structure/fenwick_tree.hpp\"\n\n\
    #line 4 \"data_structure/fenwick_tree.hpp\"\n#include <cassert>\n\ntemplate <class\
    \ T> struct FenwickTree {\n    int n;\n    std::vector<T> seg;\n    FenwickTree()\
    \ : n(0) {}\n    FenwickTree(int n) : n(n), seg(n + 1, 0) {}\n    FenwickTree(std::vector<T>&\
    \ arr) {\n        n = int(arr.size());\n        seg.resize(n + 1);\n        for\
    \ (int i = 0; i < n; i++) add(i, arr[i]);\n    }\n    // A[i] += x\n    void add(int\
    \ i, const T& x) {\n        assert(0 <= i and i < n);\n        i++;  // 1-indexed\n\
    \        while (i <= n) {\n            seg[i] += x;\n            i += i & -i;\n\
    \        }\n    }\n    // A[0] + ... + A[i - 1]\n    T sum(int i) const {\n  \
    \      assert(0 <= i and i <= n);\n        T s = T(0);\n        while (i > 0)\
    \ {\n            s += seg[i];\n            i -= i & -i;\n        }\n        return\
    \ s;\n    }\n    // A[a] + ... + A[b - 1]\n    T sum(int a, int b) const {\n \
    \       assert(0 <= a and a <= b and b <= n);\n        return sum(b) - sum(a);\n\
    \    }\n    // return A[i]\n    T get(int i) const { return sum(i, i + 1); }\n\
    \    // A[i] = x\n    void set(int i, const T x) { add(i, x - get(i)); }\n\n \
    \   std::vector<T> make_vector() {\n        std::vector<T> vec(n);\n        for\
    \ (int i = 0; i < n; i++) vec[i] = get(i);\n        return vec;\n    }\n};\n#line\
    \ 7 \"verify/misc/mo.test.cpp\"\n\nint main() {\n    int N, Q;\n    std::cin >>\
    \ N >> Q;\n    std::vector<int> A(N);\n    for (int i = 0; i < N; i++) std::cin\
    \ >> A[i];\n    std::vector<int> L(Q), R(Q);\n    for (int i = 0; i < Q; i++)\
    \ std::cin >> L[i] >> R[i];\n\n    auto B = A;\n    std::sort(B.begin(), B.end());\n\
    \    B.erase(std::unique(B.begin(), B.end()), B.end());\n    for (auto &&e : A)\
    \ e = std::lower_bound(B.begin(), B.end(), e) - B.begin();\n\n    const int M\
    \ = (int)(B.size());\n    FenwickTree<long long> fen(M);\n    std::vector<long\
    \ long> ans(Q);\n    long long cur = 0;\n    auto add_left = [&](int i) {\n  \
    \      cur += fen.sum(A[i]);\n        fen.add(A[i], 1);\n    };\n    auto add_right\
    \ = [&](int i) {\n        cur += fen.sum(A[i] + 1, M);\n        fen.add(A[i],\
    \ 1);\n    };\n    auto del_left = [&](int i) {\n        cur -= fen.sum(A[i]);\n\
    \        fen.add(A[i], -1);\n    };\n    auto del_right = [&](int i) {\n     \
    \   cur -= fen.sum(A[i] + 1, M);\n        fen.add(A[i], -1);\n    };\n    auto\
    \ out = [&](int i) { ans[i] = cur; };\n    mo(N, L, R, add_left, add_right, del_left,\
    \ del_right, out);\n    for (int i = 0; i < Q; i++) std::cout << ans[i] << '\\\
    n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <iostream>\n\n#include \"misc/mo.hpp\"\n#include \"data_structure/fenwick_tree.hpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int>\
    \ A(N);\n    for (int i = 0; i < N; i++) std::cin >> A[i];\n    std::vector<int>\
    \ L(Q), R(Q);\n    for (int i = 0; i < Q; i++) std::cin >> L[i] >> R[i];\n\n \
    \   auto B = A;\n    std::sort(B.begin(), B.end());\n    B.erase(std::unique(B.begin(),\
    \ B.end()), B.end());\n    for (auto &&e : A) e = std::lower_bound(B.begin(),\
    \ B.end(), e) - B.begin();\n\n    const int M = (int)(B.size());\n    FenwickTree<long\
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
  path: verify/misc/mo.test.cpp
  requiredBy: []
  timestamp: '2024-12-17 21:01:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/misc/mo.test.cpp
layout: document
redirect_from:
- /verify/verify/misc/mo.test.cpp
- /verify/verify/misc/mo.test.cpp.html
title: verify/misc/mo.test.cpp
---
