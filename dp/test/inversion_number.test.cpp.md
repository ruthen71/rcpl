---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: dp/inversion_number.hpp
    title: "Inversion Number (\u8EE2\u5012\u6570)"
  - icon: ':heavy_check_mark:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  - icon: ':heavy_check_mark:'
    path: misc/topbit.hpp
    title: Topbit
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: Random
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"dp/test/inversion_number.test.cpp\"\n#define PROBLEM \\\n\
    \    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\n\
    \n#include <iostream>\n#include <map>\n#include <set>\n\n#line 2 \"random/base.hpp\"\
    \n\n#include <cassert>\n#include <chrono>\n#include <cstdint>\n\n#line 2 \"misc/topbit.hpp\"\
    \n\n#line 2 \"misc/countl_zero.hpp\"\n\n#if __cplusplus >= 202002L\n#include <bit>\n\
    #endif\n\n// countl_zero\n// (000, 001, 010, 011, 100) -> (32, 31, 30, 30, 29)\n\
    #if __cplusplus >= 202002L\nusing std::countl_zero;\n#else\nint countl_zero(unsigned\
    \ int x) {\n    return x == 0 ? 32 : __builtin_clz(x);\n}\nint countl_zero(unsigned\
    \ long long int x) {\n    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#endif\n\
    int countl_zero(int x) { return countl_zero((unsigned int)(x)); }\nint countl_zero(long\
    \ long int x) {\n    return countl_zero((unsigned long long int)(x));\n}\n#line\
    \ 4 \"misc/topbit.hpp\"\n\n// topbit\n// (000, 001, 010, 011, 100) -> (-1, 0,\
    \ 1, 1, 2)\nint topbit(int x) { return 31 - countl_zero(x); }\nint topbit(unsigned\
    \ int x) { return 31 - countl_zero(x); }\nint topbit(long long int x) { return\
    \ 63 - countl_zero(x); }\nint topbit(unsigned long long int x) { return 63 - countl_zero(x);\
    \ }\n#line 8 \"random/base.hpp\"\n\ntemplate <bool auto_seed> struct Random {\n\
    \    uint64_t x_seed;\n\n    Random(uint64_t seed = 0) {\n        if (auto_seed)\
    \ {\n            // set random seed\n            assert(seed == 0);\n        \
    \    x_seed =\n                std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        } else {\n            // set seed\n            x_seed = seed;\n     \
    \   }\n    }\n\n    // http://xorshift.di.unimi.it/splitmix64.c\n    // [0, 2^64\
    \ - 1]\n    uint64_t rand_int() {\n        uint64_t z = (x_seed += 0x9e3779b97f4a7c15);\n\
    \        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;\n        z = (z ^ (z >> 27))\
    \ * 0x94d049bb133111eb;\n        return z ^ (z >> 31);\n    }\n\n    // [0, mod\
    \ - 1]\n    // rand_int() % mod \u3060\u3068 mod \u304C 2 \u3079\u304D\u3067\u306A\
    \u3044\u3068\u304D\u306B\u504F\u308B\n    uint64_t rand_int(uint64_t mod) {\n\
    \        assert(mod > 0);\n        if ((mod & (mod - 1)) == 0) {\n           \
    \ // mod = 2^p\n            // (mod - 1) = 0...01...1\n            return rand_int()\
    \ & (mod - 1);\n        }\n        // mod >= 3 (1 = 2^0, 2 = 2^1)\n        int\
    \ lg = topbit((unsigned long long)mod);\n        uint64_t mask = (lg == 63) ?\
    \ ~0ULL : (1ULL << (lg + 1)) - 1;\n        while (true) {\n            uint64_t\
    \ r = rand_int() & mask;\n            if (r < mod) return r;\n        }\n    }\n\
    \n    // [l, r]\n    template <class T> T rand_int(T l, T r) {\n        assert(l\
    \ <= r);\n        return T(l + rand_int(uint64_t(r - l + 1)));\n    }\n\n    //\
    \ [0.0, 1.0]\n    double rand_double() {\n        uint64_t v = rand_int(1ULL <<\
    \ 63);\n        return double(v) / ((1ULL << 63) - 1);\n    }\n\n    // [l, r]\n\
    \    double rand_double(double l, double r) {\n        assert(l <= r);\n     \
    \   return l + rand_double() * (r - l);\n    }\n};\n\nusing RandomFixed = Random<false>;\n\
    using RandomAuto = Random<true>;\n\nRandomAuto rng_auto;\n#line 2 \"dp/inversion_number.hpp\"\
    \n\n#include <algorithm>\n\n#line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate\
    \ <class T> struct MonoidPlus {\n    using value_type = T;\n    static constexpr\
    \ T operation(const T& a, const T& b) noexcept {\n        return a + b;\n    }\n\
    \    static constexpr T identity() noexcept { return T(0); }\n    static constexpr\
    \ T inverse(const T& a) noexcept { return -a; }\n    static constexpr bool commutative\
    \ = true;\n};\n#line 2 \"segment_tree/fenwick_tree.hpp\"\n\n#line 4 \"segment_tree/fenwick_tree.hpp\"\
    \n#include <vector>\n\n// Fenwick Tree\ntemplate <class MS> struct FenwickTree\
    \ {\n  public:\n    using S = typename MS::value_type;\n\n    FenwickTree() =\
    \ default;\n\n    explicit FenwickTree(int n)\n        : FenwickTree(std::vector<S>(n,\
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
    \    int n;\n    std::vector<S> d;\n};\n#line 7 \"dp/inversion_number.hpp\"\n\n\
    // a \u3092 sorted \u306B\u3059\u308B\u305F\u3081\u306E\u96A3\u63A5 swap \u306E\
    \u64CD\u4F5C\u56DE\u6570\ntemplate <class T> long long inversion_number(std::vector<T>&\
    \ a) {\n    auto za = a;\n    std::sort(za.begin(), za.end());\n    za.erase(std::unique(za.begin(),\
    \ za.end()), za.end());\n    const int m = (int)(za.size());\n    FenwickTree<MonoidPlus<int>>\
    \ seg(m);\n    long long res = 0;\n    for (auto&& e : a) {\n        int i = std::lower_bound(za.begin(),\
    \ za.end(), e) - za.begin();\n        res += seg.prod(i + 1, m);\n        seg.add(i,\
    \ 1);\n    }\n    return res;\n}\n\n// a -> b \u306B\u3059\u308B\u305F\u3081\u306E\
    \u96A3\u63A5 swap \u306E\u64CD\u4F5C\u56DE\u6570\ntemplate <class T>\nlong long\
    \ inversion_number(std::vector<T>& a, std::vector<T>& b) {\n    auto za = a;\n\
    \    auto zb = b;\n    std::sort(za.begin(), za.end());\n    std::sort(zb.begin(),\
    \ zb.end());\n    assert(za == zb);\n    za.erase(std::unique(za.begin(), za.end()),\
    \ za.end());\n    // a = [100, 1, 10, 1], b = [10, 1, 1, 100] (n = 4, m = 3)\n\
    \    // a = [3, 1, 0, 2] \u3092 b = [0, 1, 2, 3] \u306B\u3059\u308B\u305F\u3081\
    \u306E\u64CD\u4F5C\u56DE\u6570\u306B\u5E30\u7740\u3059\u308B\n    // g = [[1,\
    \ 2], [0], [3]] \u306B\u306A\u308B\n    const int n = (int)(a.size());\n    const\
    \ int m = (int)(za.size());\n    std::vector<std::vector<int>> g(m);\n    for\
    \ (int i = 0; i < n; i++) {\n        int index = std::lower_bound(za.begin(),\
    \ za.end(), b[i]) - za.begin();\n        g[index].push_back(i);\n    }\n    std::vector<int>\
    \ g_offset(m, 0);\n    FenwickTree<MonoidPlus<int>> seg(n);\n    long long res\
    \ = 0;\n    for (int i = 0; i < n; i++) {\n        int index = std::lower_bound(za.begin(),\
    \ za.end(), a[i]) - za.begin();\n        int offset = g_offset[index];\n     \
    \   int a_pos = g[index][offset];\n        res += seg.prod(a_pos + 1, n);\n  \
    \      seg.add(a_pos, 1);\n        g_offset[index]++;\n    }\n    return res;\n\
    }\n#line 10 \"dp/test/inversion_number.test.cpp\"\n\nint main() {\n    int n;\n\
    \    std::cin >> n;\n    std::vector<int> a(n);\n    for (auto&& e : a) std::cin\
    \ >> e;\n    long long ans1 = inversion_number<int>(a);\n    // a -> b \u3078\u306E\
    \u5358\u5C04 f \u3092\u4F5C\u6210\n    std::map<int, long long> f;\n    std::set<long\
    \ long> seen;\n    for (int i = 0; i < n; i++) {\n        if (f.count(a[i]) >\
    \ 0) continue;\n        while (true) {\n            auto val = rng_auto.rand_int();\n\
    \            if (seen.count(val) == 0) {\n                f[a[i]] = val;\n   \
    \             seen.insert(val);\n                break;\n            }\n     \
    \   }\n    }\n    // a -> a_sorted \u306E\u8EE2\u5012\u6570 (ans1) \u3068\n  \
    \  // f(a) -> f(a_sorted) \u306E\u8EE2\u5012\u6570 (ans2) \u304C\u4E00\u81F4\u3059\
    \u308B\u3053\u3068\u3092\u78BA\u8A8D\n    auto a_sorted = a;\n    std::sort(a_sorted.begin(),\
    \ a_sorted.end());\n    std::vector<long long> b(n), b_sorted(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        b[i] = f[a[i]];\n        b_sorted[i] = f[a_sorted[i]];\n\
    \    }\n    long long ans2 = inversion_number<long long>(b, b_sorted);\n    assert(ans1\
    \ == ans2);\n    std::cout << ans1 << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <iostream>\n#include <map>\n#include <set>\n\n#include \"../../random/base.hpp\"\
    \n#include \"../inversion_number.hpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<int> a(n);\n    for (auto&& e : a) std::cin >> e;\n \
    \   long long ans1 = inversion_number<int>(a);\n    // a -> b \u3078\u306E\u5358\
    \u5C04 f \u3092\u4F5C\u6210\n    std::map<int, long long> f;\n    std::set<long\
    \ long> seen;\n    for (int i = 0; i < n; i++) {\n        if (f.count(a[i]) >\
    \ 0) continue;\n        while (true) {\n            auto val = rng_auto.rand_int();\n\
    \            if (seen.count(val) == 0) {\n                f[a[i]] = val;\n   \
    \             seen.insert(val);\n                break;\n            }\n     \
    \   }\n    }\n    // a -> a_sorted \u306E\u8EE2\u5012\u6570 (ans1) \u3068\n  \
    \  // f(a) -> f(a_sorted) \u306E\u8EE2\u5012\u6570 (ans2) \u304C\u4E00\u81F4\u3059\
    \u308B\u3053\u3068\u3092\u78BA\u8A8D\n    auto a_sorted = a;\n    std::sort(a_sorted.begin(),\
    \ a_sorted.end());\n    std::vector<long long> b(n), b_sorted(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        b[i] = f[a[i]];\n        b_sorted[i] = f[a_sorted[i]];\n\
    \    }\n    long long ans2 = inversion_number<long long>(b, b_sorted);\n    assert(ans1\
    \ == ans2);\n    std::cout << ans1 << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - random/base.hpp
  - misc/topbit.hpp
  - misc/countl_zero.hpp
  - dp/inversion_number.hpp
  - algebra/monoid/monoid_plus.hpp
  - segment_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: dp/test/inversion_number.test.cpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: dp/test/inversion_number.test.cpp
layout: document
redirect_from:
- /verify/dp/test/inversion_number.test.cpp
- /verify/dp/test/inversion_number.test.cpp.html
title: dp/test/inversion_number.test.cpp
---
