---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: misc/mo.hpp
    title: Mo's Algorithm
  - icon: ':heavy_check_mark:'
    path: segment_tree/fenwick_tree.hpp
    title: segment_tree/fenwick_tree.hpp
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
  bundledCode: "#line 1 \"verify/misc/mo.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <iostream>\n\n#line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate\
    \ <class T> struct MonoidPlus {\n    using value_type = T;\n    static constexpr\
    \ T operation(const T& a, const T& b) noexcept {\n        return a + b;\n    }\n\
    \    static constexpr T identity() noexcept { return T(0); }\n    static constexpr\
    \ T inverse(const T& a) noexcept { return -a; }\n    static constexpr bool commutative\
    \ = true;\n};\n#line 2 \"misc/mo.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    #include <numeric>\n#include <cmath>\n\n// Mo's Algorithm\n// https://snuke.hatenablog.com/entry/2016/07/01/000000\n\
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
    \ out, bucket_size_value);\n}\n#line 2 \"segment_tree/fenwick_tree.hpp\"\n\n#include\
    \ <cassert>\n#line 5 \"segment_tree/fenwick_tree.hpp\"\n\n// Fenwick Tree\ntemplate\
    \ <class MS> struct FenwickTree {\n  public:\n    using S = typename MS::value_type;\n\
    \n    FenwickTree() = default;\n\n    explicit FenwickTree(int n)\n        : FenwickTree(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit FenwickTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        d = std::vector<S>(n + 1, MS::identity());\n        for (int i =\
    \ 1; i <= n; i++) {\n            d[i] = MS::operation(d[i], v[i - 1]);\n     \
    \       int j = i + (i & -i);\n            if (j <= n) {\n                d[j]\
    \ = MS::operation(d[j], d[i]);\n            }\n        }\n    }\n\n    void set(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        add(p, MS::operation(MS::inverse(get(p)),\
    \ x));\n    }\n    void add(int p, const S& x) {\n        assert(0 <= p and p\
    \ < n);\n        p++;  // 1-indexed\n        while (p <= n) {\n            d[p]\
    \ = MS::operation(d[p], x);\n            p += p & -p;\n        }\n    }\n\n  \
    \  S operator[](int p) const {\n        assert(0 <= p and p < n);\n        return\
    \ prod(p, p + 1);\n    }\n\n    S get(int p) const {\n        assert(0 <= p and\
    \ p < n);\n        return prod(p, p + 1);\n    }\n\n    S prod(int l, int r) const\
    \ {\n        assert(0 <= l and l <= r and r <= n);\n        return MS::operation(prod(r),\
    \ MS::inverse(prod(l)));\n    }\n\n    S prod(int p) const {\n        assert(0\
    \ <= p and p <= n);\n        S s = MS::identity();\n        while (p > 0) {\n\
    \            s = MS::operation(s, d[p]);\n            p -= p & -p;\n        }\n\
    \        return s;\n    }\n\n    S all_prod() const { return prod(n); }\n\n  \
    \  std::vector<S> make_vector() {\n        std::vector<S> vec(n);\n        for\
    \ (int i = 0; i < n; i++) vec[i] = get(i);\n        return vec;\n    }\n\n  private:\n\
    \    int n;\n    std::vector<S> d;\n};\n#line 8 \"verify/misc/mo.test.cpp\"\n\n\
    int main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n\
    \    for (int i = 0; i < N; i++) std::cin >> A[i];\n    std::vector<int> L(Q),\
    \ R(Q);\n    for (int i = 0; i < Q; i++) std::cin >> L[i] >> R[i];\n\n    auto\
    \ B = A;\n    std::sort(B.begin(), B.end());\n    B.erase(std::unique(B.begin(),\
    \ B.end()), B.end());\n    for (auto&& e : A) e = std::lower_bound(B.begin(),\
    \ B.end(), e) - B.begin();\n\n    const int M = (int)(B.size());\n    FenwickTree<MonoidPlus<long\
    \ long>> fen(M);\n    std::vector<long long> ans(Q);\n    long long cur = 0;\n\
    \    auto add_left = [&](int i) {\n        cur += fen.prod(0, A[i]);\n       \
    \ fen.add(A[i], 1);\n    };\n    auto add_right = [&](int i) {\n        cur +=\
    \ fen.prod(A[i] + 1, M);\n        fen.add(A[i], 1);\n    };\n    auto del_left\
    \ = [&](int i) {\n        cur -= fen.prod(0, A[i]);\n        fen.add(A[i], -1);\n\
    \    };\n    auto del_right = [&](int i) {\n        cur -= fen.prod(A[i] + 1,\
    \ M);\n        fen.add(A[i], -1);\n    };\n    auto out = [&](int i) { ans[i]\
    \ = cur; };\n    mo(N, L, R, add_left, add_right, del_left, del_right, out);\n\
    \    for (int i = 0; i < Q; i++) std::cout << ans[i] << '\\n';\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <iostream>\n\n#include \"../../algebra/monoid/monoid_plus.hpp\"\n\
    #include \"../../misc/mo.hpp\"\n#include \"../../segment_tree/fenwick_tree.hpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int>\
    \ A(N);\n    for (int i = 0; i < N; i++) std::cin >> A[i];\n    std::vector<int>\
    \ L(Q), R(Q);\n    for (int i = 0; i < Q; i++) std::cin >> L[i] >> R[i];\n\n \
    \   auto B = A;\n    std::sort(B.begin(), B.end());\n    B.erase(std::unique(B.begin(),\
    \ B.end()), B.end());\n    for (auto&& e : A) e = std::lower_bound(B.begin(),\
    \ B.end(), e) - B.begin();\n\n    const int M = (int)(B.size());\n    FenwickTree<MonoidPlus<long\
    \ long>> fen(M);\n    std::vector<long long> ans(Q);\n    long long cur = 0;\n\
    \    auto add_left = [&](int i) {\n        cur += fen.prod(0, A[i]);\n       \
    \ fen.add(A[i], 1);\n    };\n    auto add_right = [&](int i) {\n        cur +=\
    \ fen.prod(A[i] + 1, M);\n        fen.add(A[i], 1);\n    };\n    auto del_left\
    \ = [&](int i) {\n        cur -= fen.prod(0, A[i]);\n        fen.add(A[i], -1);\n\
    \    };\n    auto del_right = [&](int i) {\n        cur -= fen.prod(A[i] + 1,\
    \ M);\n        fen.add(A[i], -1);\n    };\n    auto out = [&](int i) { ans[i]\
    \ = cur; };\n    mo(N, L, R, add_left, add_right, del_left, del_right, out);\n\
    \    for (int i = 0; i < Q; i++) std::cout << ans[i] << '\\n';\n    return 0;\n\
    }\n"
  dependsOn:
  - algebra/monoid/monoid_plus.hpp
  - misc/mo.hpp
  - segment_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/misc/mo.test.cpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/misc/mo.test.cpp
layout: document
redirect_from:
- /verify/verify/misc/mo.test.cpp
- /verify/verify/misc/mo.test.cpp.html
title: verify/misc/mo.test.cpp
---
