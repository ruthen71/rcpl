---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_f/monoid_add.hpp
    title: algebra/monoid_f/monoid_add.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s/monoid_min.hpp
    title: algebra/monoid_s/monoid_min.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s_f/monoid_min_add.hpp
    title: algebra/monoid_s_f/monoid_min_add.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
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
    \ S mapping(F f, S x) { return f + x; }\n};\n#line 4 \"data_structure/lazy_segment_tree.hpp\"\
    \ntemplate <class MSF> struct LazySegmentTree {\n   public:\n    using S = typename\
    \ MSF::S;\n    using F = typename MSF::F;\n    using MS = typename MSF::MS;\n\
    \    using MF = typename MSF::MF;\n    LazySegmentTree() : LazySegmentTree(0)\
    \ {}\n    LazySegmentTree(int n) : LazySegmentTree(std::vector<S>(n, MS::e()))\
    \ {}\n    LazySegmentTree(const std::vector<S>& v) : n((int)(v.size())) {\n  \
    \      log = 0;\n        while ((1U << log) < (unsigned int)(n)) log++;\n    \
    \    size = 1 << log;\n        d = std::vector<S>(size << 1, MS::e());\n     \
    \   lz = std::vector<F>(size, MF::id());\n        for (int i = 0; i < n; i++)\
    \ d[i + size] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n       \
    \     update(i);\n        }\n    }\n\n    void set(int p, const S& x) {\n    \
    \    assert(0 <= p and p < n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n\n    void chset(int p, const S& x) {\n  \
    \      assert(0 <= p and p < n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = MS::op(d[p], x);\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S operator[](int p) {\n\
    \        assert(0 <= p and p < n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p and p < n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l and l <= r and r <= n);\n        if (l ==\
    \ r) return MS::e();\n\n        l += size;\n        r += size;\n\n        for\
    \ (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >>\
    \ i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n\
    \        S sml = MS::e(), smr = MS::e();\n        while (l < r) {\n          \
    \  if (l & 1) sml = MS::op(sml, d[l++]);\n            if (r & 1) smr = MS::op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ MS::op(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n    void apply(int\
    \ p, const F& f) {\n        assert(0 <= p and p < n);\n        p += size;\n  \
    \      for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = MSF::mapping(f,\
    \ d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n  \
    \  void apply(int l, int r, const F& f) {\n        assert(0 <= l and l <= r and\
    \ r <= n);\n        if (l == r) return;\n\n        l += size;\n        r += size;\n\
    \n        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n\n        {\n            int l2 = l, r2 = r;\n            while (l\
    \ < r) {\n                if (l & 1) all_apply(l++, f);\n                if (r\
    \ & 1) all_apply(--r, f);\n                l >>= 1;\n                r >>= 1;\n\
    \            }\n            l = l2;\n            r = r2;\n        }\n\n      \
    \  for (int i = 1; i <= log; i++) {\n            if (((l >> i) << i) != l) update(l\
    \ >> i);\n            if (((r >> i) << i) != r) update((r - 1) >> i);\n      \
    \  }\n    }\n\n    template <class G> int max_right(int l, G& g) {\n        assert(0\
    \ <= l and l <= n);\n        assert(g(MS::e()));\n        if (l == n) return n;\n\
    \        l += size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n  \
    \      S sm = MS::e();\n        do {\n            while ((l & 1) == 0) l >>= 1;\n\
    \            if (!g(MS::op(sm, d[l]))) {\n                while (l < size) {\n\
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
    \        return vec;\n    }\n\n   private:\n    int n, log, size;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n    inline void update(int k) { d[k] = MS::op(d[k\
    \ << 1], d[(k << 1) | 1]); }\n    void all_apply(int k, const F& f) {\n      \
    \  d[k] = MSF::mapping(f, d[k]);\n        if (k < size) lz[k] = MF::composition(f,\
    \ lz[k]);\n    }\n    void push(int k) {\n        all_apply(k << 1, lz[k]);\n\
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
  isVerificationFile: true
  path: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2026-01-20 14:43:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
- /verify/verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp.html
title: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
---
