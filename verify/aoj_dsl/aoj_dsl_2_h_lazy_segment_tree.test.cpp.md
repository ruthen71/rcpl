---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/monoid_f/monoid_add.hpp
    title: algebra/monoid_f/monoid_add.hpp
  - icon: ':question:'
    path: algebra/monoid_s/monoid_min.hpp
    title: algebra/monoid_s/monoid_min.hpp
  - icon: ':x:'
    path: algebra/monoid_s_f/monoid_min_add.hpp
    title: algebra/monoid_s_f/monoid_min_add.hpp
  - icon: ':x:'
    path: data_structure/lazy_segment_tree.hpp
    title: "Lazy Segment Tree (\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
  - icon: ':question:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
  bundledCode: "#line 1 \"verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"algebra/monoid_f/monoid_add.hpp\"\n\
    // MF\ntemplate <class T> struct MonoidAdd {\n    using F = T;\n    static constexpr\
    \ F composition(F f, F g) { return f + g; }\n    static constexpr F id() { return\
    \ T(0); }\n};\n#line 2 \"algebra/monoid_s/monoid_min.hpp\"\n// MS\ntemplate <class\
    \ T> struct MonoidMin {\n    using S = T;\n    static constexpr S op(S a, S b)\
    \ { return std::min(a, b); }\n    static constexpr S e() { return std::numeric_limits<T>::max();\
    \ }\n};\n#line 4 \"algebra/monoid_s_f/monoid_min_add.hpp\"\n// MSF\ntemplate <class\
    \ T> struct MonoidMinAdd {\n    using MS = MonoidMin<T>;\n    using MF = MonoidAdd<T>;\n\
    \    using S = typename MS::S;\n    using F = typename MF::F;\n    static constexpr\
    \ S mapping(F f, S x) { return f + x; }\n};\n#line 2 \"data_structure/lazy_segment_tree.hpp\"\
    \n\n#line 2 \"misc/bit_ceil.hpp\"\n\n#line 4 \"misc/bit_ceil.hpp\"\n\n#if __cplusplus\
    \ >= 202002L\n#include <bit>\n#endif\n\n// bit_ceil\n// (0, 1, 2, 3, 4) -> (1,\
    \ 1, 2, 4, 4)\n#if __cplusplus >= 202002L\nusing std::bit_ceil;\n#else\nunsigned\
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
    \ 5 \"data_structure/lazy_segment_tree.hpp\"\n\n#line 8 \"data_structure/lazy_segment_tree.hpp\"\
    \n\n// Lazy Segment Tree\ntemplate <class AM> struct LazySegmentTree {\n  public:\n\
    \    using MS = typename AM::MS;\n    using MF = typename AM::MF;\n    using S\
    \ = typename MS::value_type;\n    using F = typename MF::value_type;\n\n    LazySegmentTree()\
    \ = default;\n    explicit LazySegmentTree(int n)\n        : LazySegmentTree(std::vector<S>(n,\
    \ MS::e())) {}\n\n    explicit LazySegmentTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        size = bit_ceil(n);\n        log = countr_zero(size);\n        d\
    \ = std::vector<S>(size << 1, MS::e());\n        lz = std::vector<F>(size, MF::id());\n\
    \        for (int i = 0; i < n; i++) d[i + size] = v[i];\n        for (int i =\
    \ size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void\
    \ set(int p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n   \
    \     for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void chset(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n  \
    \      for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = MS::op(d[p],\
    \ x);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ operator[](int p) {\n        assert(0 <= p and p < n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n\
    \    }\n\n    S get(int p) {\n        assert(0 <= p and p < n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        return\
    \ d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l and l <= r\
    \ and r <= n);\n        if (l == r) return MS::e();\n\n        l += size;\n  \
    \      r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        S sml = MS::e(), smr = MS::e();\n\
    \        while (l < r) {\n            if (l & 1) sml = MS::op(sml, d[l++]);\n\
    \            if (r & 1) smr = MS::op(d[--r], smr);\n            l >>= 1;\n   \
    \         r >>= 1;\n        }\n        return MS::op(sml, smr);\n    }\n\n   \
    \ S all_prod() { return d[1]; }\n\n    void apply(int p, const F& f) {\n     \
    \   assert(0 <= p and p < n);\n        p += size;\n        for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n        d[p] = AM::mapping(f, d[p]);\n        for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void apply(int l, int\
    \ r, const F& f) {\n        assert(0 <= l and l <= r and r <= n);\n        if\
    \ (l == r) return;\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    {\n            int l2 = l, r2 = r;\n            while (l < r) {\n       \
    \         if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i\
    \ <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n    \
    \        if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n\
    \    template <class G> int max_right(int l, G& g) {\n        assert(0 <= l and\
    \ l <= n);\n        assert(g(MS::e()));\n        if (l == n) return n;\n     \
    \   l += size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n       \
    \ S sm = MS::e();\n        do {\n            while ((l & 1) == 0) l >>= 1;\n \
    \           if (!g(MS::op(sm, d[l]))) {\n                while (l < size) {\n\
    \                    push(l);\n                    l <<= 1;\n                \
    \    if (g(MS::op(sm, d[l]))) {\n                        sm = MS::op(sm, d[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = MS::op(sm, d[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\
    \n    template <class G> int min_left(int r, G& g) {\n        assert(0 <= r and\
    \ r <= n);\n        assert(g(MS::e()));\n        if (r == 0) return 0;\n     \
    \   r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n \
    \       S sm = MS::e();\n        do {\n            r--;\n            while (r\
    \ > 1 and (r & 1)) r >>= 1;\n            if (!g(MS::op(d[r], sm))) {\n       \
    \         while (r < size) {\n                    push(r);\n                 \
    \   r = (r << 1) | 1;\n                    if (g(MS::op(d[r], sm))) {\n      \
    \                  sm = MS::op(d[r], sm);\n                        r--;\n    \
    \                }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = MS::op(d[r], sm);\n        } while ((r & -r)\
    \ != r);\n        return 0;\n    }\n\n    std::vector<S> make_vector() {\n   \
    \     std::vector<S> vec(n);\n        for (int i = 0; i < n; i++) vec[i] = get(i);\n\
    \        return vec;\n    }\n\n  private:\n    int n, log, size;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n\n    inline void update(int k) { d[k] = MS::op(d[k\
    \ << 1], d[(k << 1) | 1]); }\n\n    void all_apply(int k, const F& f) {\n    \
    \    d[k] = AM::mapping(f, d[k]);\n        if (k < size) lz[k] = MF::composition(f,\
    \ lz[k]);\n    }\n\n    void push(int k) {\n        all_apply(k << 1, lz[k]);\n\
    \        all_apply((k << 1) | 1, lz[k]);\n        lz[k] = MF::id();\n    }\n};\n\
    #line 7 \"verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp\"\n\nint main()\
    \ {\n    int N, Q;\n    std::cin >> N >> Q;\n    LazySegmentTree<MonoidMinAdd<long\
    \ long>> seg(std::vector<long long>(N, 0));\n    while (Q--) {\n        int t;\n\
    \        std::cin >> t;\n        if (t == 0) {\n            int l, r, x;\n   \
    \         std::cin >> l >> r >> x;\n            seg.apply(l, r + 1, x);\n    \
    \    } else {\n            int l, r;\n            std::cin >> l >> r;\n      \
    \      std::cout << seg.prod(l, r + 1) << '\\n';\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"algebra/monoid_s_f/monoid_min_add.hpp\"\
    \n#include \"data_structure/lazy_segment_tree.hpp\"\n\nint main() {\n    int N,\
    \ Q;\n    std::cin >> N >> Q;\n    LazySegmentTree<MonoidMinAdd<long long>> seg(std::vector<long\
    \ long>(N, 0));\n    while (Q--) {\n        int t;\n        std::cin >> t;\n \
    \       if (t == 0) {\n            int l, r, x;\n            std::cin >> l >>\
    \ r >> x;\n            seg.apply(l, r + 1, x);\n        } else {\n           \
    \ int l, r;\n            std::cin >> l >> r;\n            std::cout << seg.prod(l,\
    \ r + 1) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - algebra/monoid_s_f/monoid_min_add.hpp
  - algebra/monoid_f/monoid_add.hpp
  - algebra/monoid_s/monoid_min.hpp
  - data_structure/lazy_segment_tree.hpp
  - misc/bit_ceil.hpp
  - misc/countr_zero.hpp
  isVerificationFile: true
  path: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2026-02-06 01:02:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
- /verify/verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp.html
title: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
---
