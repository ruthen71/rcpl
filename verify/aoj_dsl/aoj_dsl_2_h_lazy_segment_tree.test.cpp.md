---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/lazy_min_add.hpp
    title: src/algebra/lazy_min_add.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/lazy_segment_tree.hpp
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
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"src/algebra/lazy_min_add.hpp\"\n\ntemplate\
    \ <class S> struct lazy_min_add {\n    using F = S;\n    using value_type_S =\
    \ S;\n    using value_type_F = F;\n    static constexpr S op(S a, S b) { return\
    \ std::min(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::max();\
    \ }\n    static constexpr S mapping(F f, S x) { return f + x; }\n    static constexpr\
    \ F composition(F f, F g) { return f + g; }\n    static constexpr F id() { return\
    \ 0; }\n};\n#line 2 \"src/data_structure/lazy_segment_tree.hpp\"\n\ntemplate <class\
    \ Lazy> struct lazy_segment_tree {\n   public:\n    using S = typename Lazy::value_type_S;\n\
    \    using F = typename Lazy::value_type_F;\n    lazy_segment_tree(int n) : lazy_segment_tree(std::vector<S>(n,\
    \ Lazy::e())) {}\n    lazy_segment_tree(const std::vector<S>& v) : _n((int)v.size())\
    \ {\n        log = 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n\
    \        size = 1 << log;\n        d = std::vector<S>(2 * size, Lazy::e());\n\
    \        lz = std::vector<F>(size, Lazy::id());\n        for (int i = 0; i < _n;\
    \ i++) d[i + size] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n  \
    \          update(i);\n        }\n    }\n\n    void set(int p, const S& x) {\n\
    \        assert(0 <= p and p < _n);\n        p += size;\n        for (int i =\
    \ log; i >= 1; i--) push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\
    \n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);  //\
    \ \u4E0B\u304B\u3089\u4E0A\u306B\u66F4\u65B0\n    }\n\n    void chset(int p, const\
    \ S& x) {\n        assert(0 <= p and p < _n);\n        p += size;\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\
    \u642C\n        d[p] = Lazy::op(d[p], x);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);  // \u4E0B\u304B\u3089\u4E0A\u306B\u66F4\u65B0\n    }\n\n  \
    \  S operator[](int p) const {\n        assert(0 <= p and p < _n);\n        p\
    \ += size;\n        for (int i = log; i >= 1; i--) push(p >> i);  // \u4E0A\u304B\
    \u3089\u4E0B\u3078\u4F1D\u642C\n        return d[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l and l <= r and r <= _n);\n        if (l ==\
    \ r) return Lazy::e();\n\n        l += size;\n        r += size;\n\n        for\
    \ (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >>\
    \ i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n\
    \        S sml = Lazy::e(), smr = Lazy::e();\n        while (l < r) {\n      \
    \      if (l & 1) sml = Lazy::op(sml, d[l++]);\n            if (r & 1) smr = Lazy::op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ Lazy::op(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n    void\
    \ apply(int p, const F& f) {\n        assert(0 <= p and p < _n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] =\
    \ Lazy::mapping(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p >>\
    \ i);\n    }\n\n    void apply(int l, int r, const F& f) {\n        assert(0 <=\
    \ l and l <= r and r <= _n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l >>\
    \ i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <class G> int max_right(int l,\
    \ G& g) {\n        assert(0 <= l && l <= _n);\n        assert(g(Lazy::e()));\n\
    \        if (l == _n) return _n;\n        l += size;\n        for (int i = log;\
    \ i >= 1; i--) push(l >> i);\n        S sm = Lazy::e();\n        do {\n      \
    \      while ((l & 1) == 0) l >>= 1;\n            if (!g(Lazy::op(sm, d[l])))\
    \ {\n                while (l < size) {\n                    push(l);\n      \
    \              l <<= 1;\n                    if (g(Lazy::op(sm, d[l]))) {\n  \
    \                      sm = Lazy::op(sm, d[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - size;\n\
    \            }\n            sm = Lazy::op(sm, d[l]);\n            l++;\n     \
    \   } while ((l & -l) != l);  // 2\u3079\u304D\u307E\u305F\u306F0\u306E\u3068\u304D\
    false\n        return _n;\n    }\n\n    template <class G> int min_left(int r,\
    \ G& g) {\n        assert(0 <= r && r <= _n);\n        assert(g(Lazy::e()));\n\
    \        if (r == 0) return 0;\n        r += size;\n        for (int i = log;\
    \ i >= 1; i--) push((r - 1) >> i);\n        S sm = Lazy::e();\n        do {\n\
    \            r--;\n            while (r > 1 && (r & 1)) r >>= 1;\n           \
    \ if (!g(Lazy::op(d[r], sm))) {\n                while (r < size) {\n        \
    \            push(r);\n                    r = (r << 1) | 1;\n               \
    \     if (g(Lazy::op(d[r], sm))) {\n                        sm = Lazy::op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = Lazy::op(d[r],\
    \ sm);\n        } while ((r & -r) != r);  // 2\u3079\u304D\u307E\u305F\u306F0\u306E\
    \u3068\u304Dfalse\n        return 0;\n    }\n\n   private:\n    int _n, log, size;\n\
    \    std::vector<S> d;\n    std::vector<F> lz;\n    inline void update(int k)\
    \ { d[k] = Lazy::op(d[k << 1], d[(k << 1) | 1]); }\n    void all_apply(int k,\
    \ const F& f) {\n        d[k] = Lazy::mapping(f, d[k]);\n        if (k < size)\
    \ lz[k] = Lazy::composition(f, lz[k]);\n    }\n    void push(int k) {\n      \
    \  all_apply(k << 1, lz[k]);\n        all_apply((k << 1) | 1, lz[k]);\n      \
    \  lz[k] = Lazy::id();\n    }\n};\n\n/**\n * @brief Lazy Segment Tree (\u9045\u5EF6\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs docs/data_structure/lazy_segment_tree.md\n\
    \ */\n#line 7 \"verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp\"\n\nint\
    \ main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    lazy_segment_tree<lazy_min_add<long\
    \ long>> seg(std::vector<long long>(N, 0));\n    while (Q--) {\n        int t;\n\
    \        std::cin >> t;\n        if (t == 0) {\n            int l, r, x;\n   \
    \         std::cin >> l >> r >> x;\n            seg.apply(l, r + 1, x);\n    \
    \    } else {\n            int l, r;\n            std::cin >> l >> r;\n      \
    \      std::cout << seg.prod(l, r + 1) << '\\n';\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"src/algebra/lazy_min_add.hpp\"\n#include\
    \ \"src/data_structure/lazy_segment_tree.hpp\"\n\nint main() {\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    lazy_segment_tree<lazy_min_add<long long>> seg(std::vector<long\
    \ long>(N, 0));\n    while (Q--) {\n        int t;\n        std::cin >> t;\n \
    \       if (t == 0) {\n            int l, r, x;\n            std::cin >> l >>\
    \ r >> x;\n            seg.apply(l, r + 1, x);\n        } else {\n           \
    \ int l, r;\n            std::cin >> l >> r;\n            std::cout << seg.prod(l,\
    \ r + 1) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - src/algebra/lazy_min_add.hpp
  - src/data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2022-08-25 20:59:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
- /verify/verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp.html
title: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
---
