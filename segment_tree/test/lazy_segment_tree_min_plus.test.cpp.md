---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_max_plus.hpp
    title: algebra/acted_monoid/acted_monoid_max_plus.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_min_plus.hpp
    title: algebra/acted_monoid/acted_monoid_min_plus.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_max.hpp
    title: algebra/monoid/monoid_max.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_min.hpp
    title: algebra/monoid/monoid_min.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
  - icon: ':heavy_check_mark:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  - icon: ':heavy_check_mark:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  - icon: ':heavy_check_mark:'
    path: misc/topbit.hpp
    title: Topbit
  - icon: ':heavy_check_mark:'
    path: segment_tree/lazy_segment_tree.hpp
    title: "Lazy Segment Tree (\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
  bundledCode: "#line 1 \"segment_tree/test/lazy_segment_tree_min_plus.test.cpp\"\n\
    #define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n\n#include <iostream>\n#include <limits>\n\n#line 2 \"algebra/acted_monoid/acted_monoid_max_plus.hpp\"\
    \n\n#line 2 \"algebra/monoid/monoid_max.hpp\"\n\ntemplate <class T, T inf> struct\
    \ MonoidMax {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return std::max(a, b);\n    }\n    static\
    \ constexpr T identity() noexcept { return -inf; }\n    static constexpr bool\
    \ commutative = true;\n};\n#line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate\
    \ <class T> struct MonoidPlus {\n    using value_type = T;\n    static constexpr\
    \ T operation(const T& a, const T& b) noexcept {\n        return a + b;\n    }\n\
    \    static constexpr T identity() noexcept { return T(0); }\n    static constexpr\
    \ T inverse(const T& a) noexcept { return -a; }\n    static constexpr bool commutative\
    \ = true;\n};\n#line 5 \"algebra/acted_monoid/acted_monoid_max_plus.hpp\"\n\n\
    template <class T, T inf> struct ActedMonoidMaxPlus {\n    using MS = MonoidMax<T,\
    \ inf>;\n    using MF = MonoidPlus<T>;\n    using S = typename MS::value_type;\n\
    \    using F = typename MF::value_type;\n    static constexpr S mapping(const\
    \ F f, const S x, const int size) {\n        return x + f;\n    }\n};\n#line 2\
    \ \"algebra/acted_monoid/acted_monoid_min_plus.hpp\"\n\n#line 2 \"algebra/monoid/monoid_min.hpp\"\
    \n\ntemplate <class T, T inf> struct MonoidMin {\n    using value_type = T;\n\
    \    static constexpr T operation(const T& a, const T& b) noexcept {\n       \
    \ return std::min(a, b);\n    }\n    static constexpr T identity() noexcept {\
    \ return inf; }\n    static constexpr bool commutative = true;\n};\n#line 5 \"\
    algebra/acted_monoid/acted_monoid_min_plus.hpp\"\n\ntemplate <class T, T inf>\
    \ struct ActedMonoidMinPlus {\n    using MS = MonoidMin<T, inf>;\n    using MF\
    \ = MonoidPlus<T>;\n    using S = typename MS::value_type;\n    using F = typename\
    \ MF::value_type;\n    static constexpr S mapping(const F f, const S x, const\
    \ int size) {\n        return x + f;\n    }\n};\n#line 2 \"segment_tree/lazy_segment_tree.hpp\"\
    \n\n#line 2 \"misc/bit_ceil.hpp\"\n\n#include <cassert>\n\n#if __cplusplus >=\
    \ 202002L\n#include <bit>\n#endif\n\n// bit_ceil\n// (0, 1, 2, 3, 4) -> (1, 1,\
    \ 2, 4, 4)\n#if __cplusplus >= 202002L\nusing std::bit_ceil;\n#else\nunsigned\
    \ int bit_ceil(unsigned int x) {\n    unsigned int p = 1;\n    while (p < x) p\
    \ *= 2;\n    return p;\n}\nunsigned long long int bit_ceil(unsigned long long\
    \ int x) {\n    unsigned long long int p = 1;\n    while (p < x) p *= 2;\n   \
    \ return p;\n}\n#endif\nint bit_ceil(int x) {\n    assert(x >= 0);\n    return\
    \ bit_ceil((unsigned int)(x));\n}\nlong long int bit_ceil(long long int x) {\n\
    \    assert(x >= 0);\n    return bit_ceil((unsigned long long int)(x));\n}\n#line\
    \ 2 \"misc/countr_zero.hpp\"\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\
    \n// countr_zero\n// (000, 001, 010, 011, 100) -> (32, 0, 1, 0, 2)\n#if __cplusplus\
    \ >= 202002L\nusing std::countr_zero;\n#else\nint countr_zero(unsigned int x)\
    \ {\n    return x == 0 ? 32 : __builtin_ctz(x);\n}\nint countr_zero(unsigned long\
    \ long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n}\n#endif\nint\
    \ countr_zero(int x) { return countr_zero((unsigned int)(x)); }\nint countr_zero(long\
    \ long int x) {\n    return countr_zero((unsigned long long int)(x));\n}\n#line\
    \ 2 \"misc/topbit.hpp\"\n\n#line 2 \"misc/countl_zero.hpp\"\n\n#if __cplusplus\
    \ >= 202002L\n#include <bit>\n#endif\n\n// countl_zero\n// (000, 001, 010, 011,\
    \ 100) -> (32, 31, 30, 30, 29)\n#if __cplusplus >= 202002L\nusing std::countl_zero;\n\
    #else\nint countl_zero(unsigned int x) {\n    return x == 0 ? 32 : __builtin_clz(x);\n\
    }\nint countl_zero(unsigned long long int x) {\n    return x == 0 ? 64 : __builtin_clzll(x);\n\
    }\n#endif\nint countl_zero(int x) { return countl_zero((unsigned int)(x)); }\n\
    int countl_zero(long long int x) {\n    return countl_zero((unsigned long long\
    \ int)(x));\n}\n#line 4 \"misc/topbit.hpp\"\n\n// topbit\n// (000, 001, 010, 011,\
    \ 100) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return 31 - countl_zero(x); }\n\
    int topbit(unsigned int x) { return 31 - countl_zero(x); }\nint topbit(long long\
    \ int x) { return 63 - countl_zero(x); }\nint topbit(unsigned long long int x)\
    \ { return 63 - countl_zero(x); }\n#line 6 \"segment_tree/lazy_segment_tree.hpp\"\
    \n\n#line 8 \"segment_tree/lazy_segment_tree.hpp\"\n#include <vector>\n\n// Lazy\
    \ Segment Tree\ntemplate <class AM> struct LazySegmentTree {\n  public:\n    using\
    \ MS = typename AM::MS;\n    using MF = typename AM::MF;\n    using S = typename\
    \ MS::value_type;\n    using F = typename MF::value_type;\n\n    LazySegmentTree()\
    \ = default;\n\n    explicit LazySegmentTree(int n)\n        : LazySegmentTree(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit LazySegmentTree(const std::vector<S>& v)\
    \ : n((int)(v.size())) {\n        size = bit_ceil(n);\n        log = countr_zero(size);\n\
    \        d = std::vector<S>(size << 1, MS::identity());\n        lz = std::vector<F>(size,\
    \ MF::identity());\n        for (int i = 0; i < n; i++) d[i + size] = v[i];\n\
    \        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n     \
    \   }\n    }\n\n    void set(int p, const S& x) {\n        assert(0 <= p and p\
    \ < n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n\
    \    }\n\n    void add(int p, const S& x) {\n        assert(0 <= p and p < n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      d[p] = MS::operation(d[p], x);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S operator[](int p) {\n        assert(0 <= p and\
    \ p < n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        return d[p];\n    }\n\n    S get(int p) {\n        assert(0 <=\
    \ p and p < n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        if (l == r) return MS::identity();\n\n\
    \        l += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        S sml = MS::identity(),\
    \ smr = MS::identity();\n        while (l < r) {\n            if (l & 1) sml =\
    \ MS::operation(sml, d[l++]);\n            if (r & 1) smr = MS::operation(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ MS::operation(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n   \
    \ void apply(int p, const F& f) {\n        assert(0 <= p and p < n);\n       \
    \ p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p]\
    \ = AM::mapping(f, d[p], 1);\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    void apply(int l, int r, const F& f) {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l >>\
    \ i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <class G> int max_right(int l,\
    \ G& g) {\n        assert(0 <= l and l <= n);\n        assert(g(MS::identity()));\n\
    \        if (l == n) return n;\n        l += size;\n        for (int i = log;\
    \ i >= 1; i--) push(l >> i);\n        S sm = MS::identity();\n        do {\n \
    \           while ((l & 1) == 0) l >>= 1;\n            if (!g(MS::operation(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l <<= 1;\n                    if (g(MS::operation(sm, d[l])))\
    \ {\n                        sm = MS::operation(sm, d[l]);\n                 \
    \       l++;\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = MS::operation(sm, d[l]);\n      \
    \      l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\n  \
    \  template <class G> int min_left(int r, G& g) {\n        assert(0 <= r and r\
    \ <= n);\n        assert(g(MS::identity()));\n        if (r == 0) return 0;\n\
    \        r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = MS::identity();\n        do {\n            r--;\n            while\
    \ (r > 1 and (r & 1)) r >>= 1;\n            if (!g(MS::operation(d[r], sm))) {\n\
    \                while (r < size) {\n                    push(r);\n          \
    \          r = (r << 1) | 1;\n                    if (g(MS::operation(d[r], sm)))\
    \ {\n                        sm = MS::operation(d[r], sm);\n                 \
    \       r--;\n                    }\n                }\n                return\
    \ r + 1 - size;\n            }\n            sm = MS::operation(d[r], sm);\n  \
    \      } while ((r & -r) != r);\n        return 0;\n    }\n\n    std::vector<S>\
    \ make_vector() {\n        std::vector<S> vec(n);\n        for (int i = 0; i <\
    \ n; i++) vec[i] = get(i);\n        return vec;\n    }\n\n  private:\n    int\
    \ n, log, size;\n    std::vector<S> d;\n    std::vector<F> lz;\n\n    inline void\
    \ update(int k) {\n        d[k] = MS::operation(d[k << 1], d[(k << 1) | 1]);\n\
    \    }\n\n    void all_apply(int k, const F& f) {\n        d[k] = AM::mapping(f,\
    \ d[k], 1 << (log - topbit(k)));\n        // MF::operation(f, g), g(f(x))\n  \
    \      if (k < size) lz[k] = MF::operation(lz[k], f);\n    }\n\n    void push(int\
    \ k) {\n        all_apply(k << 1, lz[k]);\n        all_apply((k << 1) | 1, lz[k]);\n\
    \        lz[k] = MF::identity();\n    }\n};\n#line 10 \"segment_tree/test/lazy_segment_tree_min_plus.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    constexpr long long\
    \ INF = std::numeric_limits<long long>::max();\n    std::vector<long long> a(N);\n\
    \    LazySegmentTree<ActedMonoidMinPlus<long long, INF>> segmin(a);\n    LazySegmentTree<ActedMonoidMaxPlus<long\
    \ long, INF>> segmax(a);\n    while (Q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if (t == 0) {\n            int l, r, x;\n            std::cin\
    \ >> l >> r >> x;\n            r++;\n            segmin.apply(l, r, x);\n    \
    \        segmax.apply(l, r, -x);\n        } else {\n            int l, r;\n  \
    \          std::cin >> l >> r;\n            r++;\n            assert(segmin.prod(l,\
    \ r) == -segmax.prod(l, r));\n            std::cout << segmin.prod(l, r) << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n\n#include <iostream>\n#include <limits>\n\n#include \"../../algebra/acted_monoid/acted_monoid_max_plus.hpp\"\
    \n#include \"../../algebra/acted_monoid/acted_monoid_min_plus.hpp\"\n#include\
    \ \"../../segment_tree/lazy_segment_tree.hpp\"\n\nint main() {\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    constexpr long long INF = std::numeric_limits<long\
    \ long>::max();\n    std::vector<long long> a(N);\n    LazySegmentTree<ActedMonoidMinPlus<long\
    \ long, INF>> segmin(a);\n    LazySegmentTree<ActedMonoidMaxPlus<long long, INF>>\
    \ segmax(a);\n    while (Q--) {\n        int t;\n        std::cin >> t;\n    \
    \    if (t == 0) {\n            int l, r, x;\n            std::cin >> l >> r >>\
    \ x;\n            r++;\n            segmin.apply(l, r, x);\n            segmax.apply(l,\
    \ r, -x);\n        } else {\n            int l, r;\n            std::cin >> l\
    \ >> r;\n            r++;\n            assert(segmin.prod(l, r) == -segmax.prod(l,\
    \ r));\n            std::cout << segmin.prod(l, r) << '\\n';\n        }\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - algebra/acted_monoid/acted_monoid_max_plus.hpp
  - algebra/monoid/monoid_max.hpp
  - algebra/monoid/monoid_plus.hpp
  - algebra/acted_monoid/acted_monoid_min_plus.hpp
  - algebra/monoid/monoid_min.hpp
  - segment_tree/lazy_segment_tree.hpp
  - misc/bit_ceil.hpp
  - misc/countr_zero.hpp
  - misc/topbit.hpp
  - misc/countl_zero.hpp
  isVerificationFile: true
  path: segment_tree/test/lazy_segment_tree_min_plus.test.cpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/lazy_segment_tree_min_plus.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/lazy_segment_tree_min_plus.test.cpp
- /verify/segment_tree/test/lazy_segment_tree_min_plus.test.cpp.html
title: segment_tree/test/lazy_segment_tree_min_plus.test.cpp
---
