---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree_recursion.hpp
    title: "Segment Tree (\u518D\u5E30 + \u30DD\u30A4\u30F3\u30BF\u6728)"
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
  bundledCode: "#line 1 \"segment_tree/test/segment_tree_recursion.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include\
    \ <iostream>\n\n#line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate <class\
    \ T> struct MonoidPlus {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return a + b;\n    }\n    static constexpr\
    \ T identity() noexcept { return T(0); }\n    static constexpr T inverse(const\
    \ T& a) noexcept { return -a; }\n    static constexpr bool commutative = true;\n\
    };\n#line 2 \"segment_tree/segment_tree_recursion.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n// Segment Tree (\u518D\u5E30 + \u30DD\u30A4\u30F3\u30BF\u6728\
    )\n// 2N \u306F N = 500000 \u306E\u3068\u304D 1000000 \u304F\u3089\u3044\ntemplate\
    \ <class MS, int MAX_NODES = 2'000'000> struct SegmentTreeRecursion {\n  public:\n\
    \    using S = typename MS::value_type;\n\n    struct Node {\n        S d;\n \
    \       Node *l, *r;\n        Node() = default;\n        Node(S v, Node* l = nullptr,\
    \ Node* r = nullptr) : d(v), l(l), r(r) {}\n    };\n\n    SegmentTreeRecursion()\
    \ = default;\n\n    explicit SegmentTreeRecursion(int n)\n        : SegmentTreeRecursion(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit SegmentTreeRecursion(const std::vector<S>&\
    \ v)\n        : n((int)(v.size())) {\n        root = build(v, 0, n);\n    }\n\n\
    \    void set(int p, const S& x) {\n        assert(0 <= p and p < n);\n      \
    \  set(p, x, 0, n, root);\n    }\n\n    void add(int p, const S& x) {\n      \
    \  assert(0 <= p and p < n);\n        add(p, x, 0, n, root);\n    }\n\n    S operator[](int\
    \ p) const {\n        assert(0 <= p and p < n);\n        return prod(p, p + 1);\n\
    \    }\n\n    S get(int p) const {\n        assert(0 <= p and p < n);\n      \
    \  return prod(p, p + 1);\n    }\n\n    S prod(int l, int r) const {\n       \
    \ assert(0 <= l and l <= r and r <= n);\n        return prod(l, r, 0, n, root);\n\
    \    }\n\n    S all_prod() const { return root->d; }\n\n    std::vector<S> make_vector()\
    \ const {\n        std::vector<S> vec(n);\n        for (int i = 0; i < n; i++)\
    \ vec[i] = get(i);\n        return vec;\n    }\n\n  private:\n    int n;\n   \
    \ Node* root;\n    static inline Node pool[MAX_NODES];\n    static inline int\
    \ pool_idx = 0;\n\n    Node* new_node(S v, Node* l = nullptr, Node* r = nullptr)\
    \ {\n        return &(pool[pool_idx++] = Node(v, l, r));\n    }\n\n    Node* merge(Node*\
    \ l, Node* r, Node* np = nullptr) {\n        if (np == nullptr) {\n          \
    \  np = new_node(MS::operation(l->d, r->d), l, r);\n        } else {\n       \
    \     np->d = MS::operation(l->d, r->d);\n        }\n        return np;\n    }\n\
    \n    Node* build(const std::vector<S>& v, int l, int r) {\n        if (l + 1\
    \ == r) {\n            return new_node(v[l]);\n        }\n        int m = (l +\
    \ r) / 2;\n        return merge(build(v, l, m), build(v, m, r));\n    }\n\n  \
    \  Node* set(int p, const S& x, int l, int r, Node* np) {\n        if (l + 1 ==\
    \ r) {\n            np->d = x;\n            return np;\n        }\n        int\
    \ m = (l + r) / 2;\n        if (l <= p and p < m) {\n            return merge(set(p,\
    \ x, l, m, np->l), np->r, np);\n        } else {\n            return merge(np->l,\
    \ set(p, x, m, r, np->r), np);\n        }\n    }\n\n    Node* add(int p, const\
    \ S& x, int l, int r, Node* np) {\n        if (l + 1 == r) {\n            np->d\
    \ = MS::operation(np->d, x);\n            return np;\n        }\n        int m\
    \ = (l + r) / 2;\n        if (l <= p and p < m) {\n            return merge(add(p,\
    \ x, l, m, np->l), np->r, np);\n        } else {\n            return merge(np->l,\
    \ add(p, x, m, r, np->r), np);\n        }\n    }\n\n    S prod(int ql, int qr,\
    \ int l, int r, Node* np) const {\n        // [ql, qr) \u3068 [l, r) \u304C\u4EA4\
    \u5DEE\u3057\u306A\u3044\n        if (qr <= l or r <= ql) return MS::identity();\n\
    \        // [ql, qr) \u304C [l, r) \u3092\u5B8C\u5168\u306B\u542B\u3093\u3067\u3044\
    \u308B\n        if (ql <= l and r <= qr) return np->d;\n        int m = (l + r)\
    \ / 2;\n        return MS::operation(prod(ql, qr, l, m, np->l),\n            \
    \                 prod(ql, qr, m, r, np->r));\n    }\n};\n#line 7 \"segment_tree/test/segment_tree_recursion.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<long\
    \ long> a(N);\n    for (int i = 0; i < N; i++) std::cin >> a[i];\n    SegmentTreeRecursion<MonoidPlus<long\
    \ long>> seg_add(a);\n    SegmentTreeRecursion<MonoidPlus<long long>> seg_set(a);\n\
    \    while (Q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int p, x;\n            std::cin >> p >> x;\n            seg_add.add(p,\
    \ x);\n            seg_set.set(p, seg_set.get(p) + x);\n        } else {\n   \
    \         int l, r;\n            std::cin >> l >> r;\n            assert(seg_add.prod(l,\
    \ r) == seg_set.prod(l, r));\n            std::cout << seg_add.prod(l, r) << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n\n#include \"../../algebra/monoid/monoid_plus.hpp\"\n#include\
    \ \"../../segment_tree/segment_tree_recursion.hpp\"\n\nint main() {\n    int N,\
    \ Q;\n    std::cin >> N >> Q;\n    std::vector<long long> a(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> a[i];\n    SegmentTreeRecursion<MonoidPlus<long\
    \ long>> seg_add(a);\n    SegmentTreeRecursion<MonoidPlus<long long>> seg_set(a);\n\
    \    while (Q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int p, x;\n            std::cin >> p >> x;\n            seg_add.add(p,\
    \ x);\n            seg_set.set(p, seg_set.get(p) + x);\n        } else {\n   \
    \         int l, r;\n            std::cin >> l >> r;\n            assert(seg_add.prod(l,\
    \ r) == seg_set.prod(l, r));\n            std::cout << seg_add.prod(l, r) << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - algebra/monoid/monoid_plus.hpp
  - segment_tree/segment_tree_recursion.hpp
  isVerificationFile: true
  path: segment_tree/test/segment_tree_recursion.test.cpp
  requiredBy: []
  timestamp: '2026-04-12 20:46:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/segment_tree_recursion.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/segment_tree_recursion.test.cpp
- /verify/segment_tree/test/segment_tree_recursion.test.cpp.html
title: segment_tree/test/segment_tree_recursion.test.cpp
---
