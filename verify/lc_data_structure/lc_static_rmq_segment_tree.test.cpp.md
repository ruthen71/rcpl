---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid_min.hpp
    title: src/algebra/monoid_min.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/segment_tree.hpp
    title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <bits/stdc++.h>\n\
    \n#line 2 \"src/algebra/monoid_min.hpp\"\n\ntemplate <class S> struct monoid_min\
    \ {\n    using value_type = S;\n    static constexpr S op(S a, S b) { return std::min(a,\
    \ b); }\n    static constexpr S e() { return std::numeric_limits<S>::max(); }\n\
    };\n#line 2 \"src/data_structure/segment_tree.hpp\"\n\ntemplate <class Monoid>\
    \ struct segment_tree {\n    using S = typename Monoid::value_type;\n    int _n,\
    \ log, size;\n    std::vector<S> d;\n    segment_tree() : segment_tree(0) {}\n\
    \    segment_tree(int n) : segment_tree(std::vector<S>(n, Monoid::e())) {}\n \
    \   segment_tree(const std::vector<S>& v) : _n((int)v.size()) {\n        log =\
    \ 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n        size =\
    \ 1 << log;\n        d = std::vector<S>(2 * size, Monoid::e());\n        for (int\
    \ i = 0; i < _n; i++) d[i + size] = v[i];\n        for (int i = size - 1; i >=\
    \ 1; i--) {\n            update(i);\n        }\n    }\n\n    void update(int k)\
    \ { d[k] = Monoid::op(d[k << 1], d[(k << 1) | 1]); }\n\n    void set(int p, S\
    \ x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p] =\
    \ x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int\
    \ p) const {\n        assert(0 <= p && p < _n);\n        return d[p + size];\n\
    \    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        S vl = Monoid::e(), vr = Monoid::e();\n        l += size;\n\
    \        r += size;\n\n        while (l < r) {\n            if (l & 1) vl = Monoid::op(vl,\
    \ d[l++]);\n            if (r & 1) vr = Monoid::op(d[--r], vr);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n        return Monoid::op(vl, vr);\n\
    \    }\n\n    S all_prod() const { return d[1]; }\n\n    template <class F> int\
    \ max_right(int l, F& f) const {\n        assert(0 <= l && l <= _n);\n       \
    \ assert(f(Monoid::e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = Monoid::e();\n        do {\n            while ((l & 1) == 0) l\
    \ >>= 1;\n            if (!f(Monoid::op(sm, d[l]))) {\n                while (l\
    \ < size) {\n                    l <<= 1;\n                    if (f(Monoid::op(sm,\
    \ d[l]))) {\n                        sm = Monoid::op(sm, d[l]);\n            \
    \            l++;\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = Monoid::op(sm, d[l]);\n         \
    \   l++;\n        } while ((l & -l) != l);  // 2\u3079\u304D\u307E\u305F\u306F\
    0\u306E\u3068\u304Dfalse\n        return _n;\n    }\n\n    template <class F>\
    \ int min_left(int r, F& f) const {\n        assert(0 <= r && r <= _n);\n    \
    \    assert(f(Monoid::e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = Monoid::e();\n        do {\n            r--;\n            while\
    \ (r > 1 && (r & 1)) r >>= 1;\n            if (!f(Monoid::op(d[r], sm))) {\n \
    \               while (r < size) {\n                    r = (r << 1) | 1;\n  \
    \                  if (f(Monoid::op(d[r], sm))) {\n                        sm\
    \ = Monoid::op(d[r], sm);\n                        r--;\n                    }\n\
    \                }\n                return r + 1 - size;\n            }\n    \
    \        sm = Monoid::op(d[r], sm);\n        } while ((r & -r) != r);  // 2\u3079\
    \u304D\u307E\u305F\u306F0\u306E\u3068\u304Dfalse\n        return 0;\n    }\n};\n\
    \n/**\n * @brief Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs\
    \ docs/data_structure/segment_tree.md\n */\n#line 7 \"verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int>\
    \ A(N);\n    for (int i = 0; i < N; i++) std::cin >> A[i];\n    segment_tree<monoid_min<int>>\
    \ seg(A);\n    while (Q--) {\n        int l, r;\n        std::cin >> l >> r;\n\
    \        std::cout << seg.prod(l, r) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../src/algebra/monoid_min.hpp\"\n#include \"\
    ../../src/data_structure/segment_tree.hpp\"\n\nint main() {\n    int N, Q;\n \
    \   std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for (int i = 0; i < N;\
    \ i++) std::cin >> A[i];\n    segment_tree<monoid_min<int>> seg(A);\n    while\
    \ (Q--) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout <<\
    \ seg.prod(l, r) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - src/algebra/monoid_min.hpp
  - src/data_structure/segment_tree.hpp
  isVerificationFile: true
  path: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2022-08-23 20:30:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
- /verify/verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp.html
title: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
---
