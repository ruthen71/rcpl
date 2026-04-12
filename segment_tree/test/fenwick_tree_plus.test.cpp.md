---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"segment_tree/test/fenwick_tree_plus.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include\
    \ <iostream>\n\n#line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate <class\
    \ T> struct MonoidPlus {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return a + b;\n    }\n    static constexpr\
    \ T identity() noexcept { return T(0); }\n    static constexpr T inverse(const\
    \ T& a) noexcept { return -a; }\n    static constexpr bool commutative = true;\n\
    };\n#line 2 \"segment_tree/fenwick_tree.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\n// Fenwick Tree\ntemplate <class MS> struct FenwickTree {\n  public:\n\
    \    using S = typename MS::value_type;\n\n    FenwickTree() = default;\n\n  \
    \  explicit FenwickTree(int n)\n        : FenwickTree(std::vector<S>(n, MS::identity()))\
    \ {}\n\n    explicit FenwickTree(const std::vector<S>& v) : n((int)(v.size()))\
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
    \    int n;\n    std::vector<S> d;\n};\n#line 7 \"segment_tree/test/fenwick_tree_plus.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<long\
    \ long> a(N);\n    for (int i = 0; i < N; i++) std::cin >> a[i];\n    FenwickTree<MonoidPlus<long\
    \ long>> seg_add(a);\n    FenwickTree<MonoidPlus<long long>> seg_set(a);\n   \
    \ while (Q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n\
    \            int p, x;\n            std::cin >> p >> x;\n            seg_add.add(p,\
    \ x);\n            seg_set.set(p, seg_set.get(p) + x);\n        } else {\n   \
    \         int l, r;\n            std::cin >> l >> r;\n            assert(seg_add.prod(l,\
    \ r) == seg_set.prod(l, r));\n            std::cout << seg_add.prod(l, r) << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n\n#include \"../../algebra/monoid/monoid_plus.hpp\"\n#include\
    \ \"../../segment_tree/fenwick_tree.hpp\"\n\nint main() {\n    int N, Q;\n   \
    \ std::cin >> N >> Q;\n    std::vector<long long> a(N);\n    for (int i = 0; i\
    \ < N; i++) std::cin >> a[i];\n    FenwickTree<MonoidPlus<long long>> seg_add(a);\n\
    \    FenwickTree<MonoidPlus<long long>> seg_set(a);\n    while (Q--) {\n     \
    \   int t;\n        std::cin >> t;\n        if (t == 0) {\n            int p,\
    \ x;\n            std::cin >> p >> x;\n            seg_add.add(p, x);\n      \
    \      seg_set.set(p, seg_set.get(p) + x);\n        } else {\n            int\
    \ l, r;\n            std::cin >> l >> r;\n            assert(seg_add.prod(l, r)\
    \ == seg_set.prod(l, r));\n            std::cout << seg_add.prod(l, r) << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - algebra/monoid/monoid_plus.hpp
  - segment_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: segment_tree/test/fenwick_tree_plus.test.cpp
  requiredBy: []
  timestamp: '2026-04-12 20:46:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/fenwick_tree_plus.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/fenwick_tree_plus.test.cpp
- /verify/segment_tree/test/fenwick_tree_plus.test.cpp.html
title: segment_tree/test/fenwick_tree_plus.test.cpp
---
