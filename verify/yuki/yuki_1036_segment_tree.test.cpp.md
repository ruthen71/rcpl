---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_gcd.hpp
    title: algebra/monoid_gcd.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1036
    links:
    - https://yukicoder.me/problems/no/1036
  bundledCode: "#line 1 \"verify/yuki/yuki_1036_segment_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1036\"\n\n#include <bits/stdc++.h>\n\n#line\
    \ 2 \"algebra/monoid_gcd.hpp\"\n\ntemplate <class S> struct MonoidGcd {\n    using\
    \ value_type = S;\n    static constexpr S op(S a, S b) { return std::gcd(a, b);\
    \ }\n    static constexpr S e() { return 0; }\n};\n#line 2 \"data_structure/segment_tree.hpp\"\
    \n\ntemplate <class Monoid> struct SegmentTree {\n   public:\n    using S = typename\
    \ Monoid::value_type;\n    SegmentTree() : SegmentTree(0) {}\n    SegmentTree(int\
    \ n) : SegmentTree(std::vector<S>(n, Monoid::e())) {}\n    SegmentTree(const std::vector<S>&\
    \ v) : _n((int)v.size()) {\n        log = 0;\n        while ((1U << log) < (unsigned\
    \ int)(_n)) log++;\n        size = 1 << log;\n        d = std::vector<S>(size\
    \ << 1, Monoid::e());\n        for (int i = 0; i < _n; i++) d[i + size] = v[i];\n\
    \        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n     \
    \   }\n    }\n\n    void set(int p, const S& x) {\n        assert(0 <= p and p\
    \ < _n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n\n    void chset(int p, const S& x) {\n  \
    \      assert(0 <= p and p < _n);\n        p += size;\n        d[p] = Monoid::op(d[p],\
    \ x);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ operator[](int p) const {\n        assert(0 <= p and p < _n);\n        return\
    \ d[p + size];\n    }\n\n    S get(int p) const {\n        assert(0 <= p && p\
    \ < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r) const\
    \ {\n        assert(0 <= l and l <= r and r <= _n);\n        S sml = Monoid::e(),\
    \ smr = Monoid::e();\n        l += size;\n        r += size;\n\n        while\
    \ (l < r) {\n            if (l & 1) sml = Monoid::op(sml, d[l++]);\n         \
    \   if (r & 1) smr = Monoid::op(d[--r], smr);\n            l >>= 1;\n        \
    \    r >>= 1;\n        }\n        return Monoid::op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <class F> int max_right(int\
    \ l, F& f) const {\n        assert(0 <= l and l <= _n);\n        assert(f(Monoid::e()));\n\
    \        if (l == _n) return _n;\n        l += size;\n        S sm = Monoid::e();\n\
    \        do {\n            while ((l & 1) == 0) l >>= 1;\n            if (!f(Monoid::op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l <<= 1;\n\
    \                    if (f(Monoid::op(sm, d[l]))) {\n                        sm\
    \ = Monoid::op(sm, d[l]);\n                        l++;\n                    }\n\
    \                }\n                return l - size;\n            }\n        \
    \    sm = Monoid::op(sm, d[l]);\n            l++;\n        } while ((l & -l) !=\
    \ l);  // 2\u3079\u304D\u307E\u305F\u306F0\u306E\u3068\u304Dfalse\n        return\
    \ _n;\n    }\n\n    template <class F> int min_left(int r, F& f) const {\n   \
    \     assert(0 <= r and r <= _n);\n        assert(f(Monoid::e()));\n        if\
    \ (r == 0) return 0;\n        r += size;\n        S sm = Monoid::e();\n      \
    \  do {\n            r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n  \
    \          if (!f(Monoid::op(d[r], sm))) {\n                while (r < size) {\n\
    \                    r = (r << 1) | 1;\n                    if (f(Monoid::op(d[r],\
    \ sm))) {\n                        sm = Monoid::op(d[r], sm);\n              \
    \          r--;\n                    }\n                }\n                return\
    \ r + 1 - size;\n            }\n            sm = Monoid::op(d[r], sm);\n     \
    \   } while ((r & -r) != r);  // 2\u3079\u304D\u307E\u305F\u306F0\u306E\u3068\u304D\
    false\n        return 0;\n    }\n\n   private:\n    int _n, log, size;\n    std::vector<S>\
    \ d;\n    inline void update(int k) { d[k] = Monoid::op(d[k << 1], d[(k << 1)\
    \ | 1]); }\n};\n#line 7 \"verify/yuki/yuki_1036_segment_tree.test.cpp\"\n\nint\
    \ main() {\n    int N;\n    std::cin >> N;\n    std::vector<long long> A(N);\n\
    \    for (int i = 0; i < N; i++) std::cin >> A[i];\n    SegmentTree<MonoidGcd<long\
    \ long>> seg(A);\n    auto f = [](long long v) -> bool { return v != 1LL; };\n\
    \    long long ansL = 0, ansR = 0;\n    for (int l = 0; l < N; l++) {\n      \
    \  int r = seg.max_right(l, f);\n        ansL += N - r;\n    }\n    for (int r\
    \ = N; r > 0; r--) {\n        int l = seg.min_left(r, f);\n        ansR += l;\n\
    \    }\n    assert(ansL == ansR);\n    std::cout << ansL << '\\n';\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1036\"\n\n#include <bits/stdc++.h>\n\
    \n#include \"algebra/monoid_gcd.hpp\"\n#include \"data_structure/segment_tree.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    std::vector<long long> A(N);\n\
    \    for (int i = 0; i < N; i++) std::cin >> A[i];\n    SegmentTree<MonoidGcd<long\
    \ long>> seg(A);\n    auto f = [](long long v) -> bool { return v != 1LL; };\n\
    \    long long ansL = 0, ansR = 0;\n    for (int l = 0; l < N; l++) {\n      \
    \  int r = seg.max_right(l, f);\n        ansL += N - r;\n    }\n    for (int r\
    \ = N; r > 0; r--) {\n        int l = seg.min_left(r, f);\n        ansR += l;\n\
    \    }\n    assert(ansL == ansR);\n    std::cout << ansL << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - algebra/monoid_gcd.hpp
  - data_structure/segment_tree.hpp
  isVerificationFile: true
  path: verify/yuki/yuki_1036_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yuki/yuki_1036_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yuki/yuki_1036_segment_tree.test.cpp
- /verify/verify/yuki/yuki_1036_segment_tree.test.cpp.html
title: verify/yuki/yuki_1036_segment_tree.test.cpp
---
