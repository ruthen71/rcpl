---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_f/monoid_set.hpp
    title: algebra/monoid_f/monoid_set.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/dual_segment_tree.hpp
    title: "Dual Segment Tree (\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"algebra/monoid_f/monoid_set.hpp\"\n\
    // MF\ntemplate <class T> struct MonoidSet {\n    using F = T;\n    static constexpr\
    \ F composition(F f, F g) { return f == id() ? g : f; }\n    static constexpr\
    \ F id() { return std::numeric_limits<F>::max(); }\n};\n#line 2 \"data_structure/dual_segment_tree.hpp\"\
    \n\n#line 5 \"data_structure/dual_segment_tree.hpp\"\ntemplate <class MF> struct\
    \ DualSegmentTree {\n   public:\n    using F = typename MF::F;\n    DualSegmentTree()\
    \ : DualSegmentTree(0) {}\n    DualSegmentTree(int n) : DualSegmentTree(std::vector<F>(n,\
    \ MF::id())) {}\n    DualSegmentTree(const std::vector<F>& v) : n((int)(v.size()))\
    \ {\n        log = 0;\n        while ((1U << log) < (unsigned int)(n)) log++;\n\
    \        size = 1 << log;\n        lz = std::vector<F>(size << 1, MF::id());\n\
    \        for (int i = 0; i < n; i++) lz[i + size] = v[i];\n    }\n\n    F operator[](int\
    \ p) {\n        assert(0 <= p and p < n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return lz[p];\n    }\n\n    F get(int\
    \ p) {\n        assert(0 <= p and p < n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return lz[p];\n    }\n\n    void\
    \ apply(int p, const F& f) {\n        assert(0 <= p and p < n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        lz[p] =\
    \ f;\n    }\n\n    void apply(int l, int r, const F& f) {\n        assert(0 <=\
    \ l and l <= r and r <= n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n    }\n\n    std::vector<F> make_vector() {\n        std::vector<F>\
    \ vec(n);\n        for (int i = 0; i < n; i++) vec[i] = get(i);\n        return\
    \ vec;\n    }\n\n   private:\n    int n, log, size;\n    std::vector<F> lz;\n\
    \    void all_apply(int k, const F& f) { lz[k] = MF::composition(f, lz[k]); }\n\
    \    void push(int k) {\n        all_apply(k << 1, lz[k]);\n        all_apply((k\
    \ << 1) | 1, lz[k]);\n        lz[k] = MF::id();\n    }\n};\n#line 7 \"verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    DualSegmentTree<MonoidSet<int>>\
    \ seg(N);\n    while (Q--) {\n        int t;\n        std::cin >> t;\n       \
    \ if (t == 0) {\n            int l, r, x;\n            std::cin >> l >> r >> x;\n\
    \            seg.apply(l, r + 1, x);\n        } else {\n            int i;\n \
    \           std::cin >> i;\n            std::cout << seg[i] << '\\n';\n      \
    \  }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"algebra/monoid_f/monoid_set.hpp\"\n\
    #include \"data_structure/dual_segment_tree.hpp\"\n\nint main() {\n    int N,\
    \ Q;\n    std::cin >> N >> Q;\n    DualSegmentTree<MonoidSet<int>> seg(N);\n \
    \   while (Q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int l, r, x;\n            std::cin >> l >> r >> x;\n        \
    \    seg.apply(l, r + 1, x);\n        } else {\n            int i;\n         \
    \   std::cin >> i;\n            std::cout << seg[i] << '\\n';\n        }\n   \
    \ }\n    return 0;\n}\n"
  dependsOn:
  - algebra/monoid_f/monoid_set.hpp
  - data_structure/dual_segment_tree.hpp
  isVerificationFile: true
  path: verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2024-07-13 11:37:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
- /verify/verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp.html
title: verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
---
