---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/dynamic_segment_tree.hpp
    title: "Dynamic Segment Tree (\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/789
    links:
    - https://yukicoder.me/problems/no/789
  bundledCode: "#line 1 \"segment_tree/test/dynamic_segment_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <iostream>\n\n\
    #line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate <class T> struct MonoidPlus\
    \ {\n    using value_type = T;\n    static constexpr T operation(const T& a, const\
    \ T& b) noexcept {\n        return a + b;\n    }\n    static constexpr T identity()\
    \ noexcept { return T(0); }\n    static constexpr T inverse(const T& a) noexcept\
    \ { return -a; }\n    static constexpr bool commutative = true;\n};\n#line 2 \"\
    segment_tree/dynamic_segment_tree.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n// Dynamic Segment Tree\n// Q log_2(N) \u306F Q = 500000, N = 10^18 \u306E\u3068\
    \u304D 30000000 \u304F\u3089\u3044\ntemplate <class MS, int MAX_NODES = 30'000'000>\
    \ struct DynamicSegmentTree {\n  public:\n    using S = typename MS::value_type;\n\
    \n    struct Node {\n        S d;\n        Node *l, *r;\n        Node() = default;\n\
    \        Node(S v, Node* l = nullptr, Node* r = nullptr) : d(v), l(l), r(r) {}\n\
    \    };\n\n    DynamicSegmentTree() = default;\n\n    explicit DynamicSegmentTree(int\
    \ n) : n(n), root(nullptr) {}\n\n    void set(int p, const S& x) {\n        assert(0\
    \ <= p and p < n);\n        set(p, x, 0, n, root);\n    }\n\n    void add(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        add(p, x, 0, n,\
    \ root);\n    }\n\n    S operator[](int p) const {\n        assert(0 <= p and\
    \ p < n);\n        return prod(p, p + 1);\n    }\n\n    S get(int p) const {\n\
    \        assert(0 <= p and p < n);\n        return prod(p, p + 1);\n    }\n\n\
    \    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        return prod(l, r, 0, n, root);\n    }\n\n    S all_prod() const { return\
    \ (root == nullptr ? MS::identity() : root->d); }\n\n    std::vector<std::pair<int,\
    \ S>> make_vector() const {\n        std::vector<std::pair<int, S>> vec;\n   \
    \     auto rec = [&](auto f, int l, int r, Node* np) -> void {\n            if\
    \ (np == nullptr) return;\n            if (l + 1 == r) vec.push_back({l, np->d});\n\
    \            int m = (l + r) / 2;\n            f(f, l, m, np->l);\n          \
    \  f(f, m, r, np->r);\n        };\n        rec(rec, 0, n, root);\n        return\
    \ vec;\n    }\n\n  private:\n    int n;\n    Node* root;\n    static inline Node\
    \ pool[MAX_NODES];\n    static inline int pool_idx = 0;\n\n    Node* new_node(S\
    \ v, Node* l = nullptr, Node* r = nullptr) {\n        return &(pool[pool_idx++]\
    \ = Node(v, l, r));\n    }\n\n    Node* merge(Node* l, Node* r, Node* np) {\n\
    \        np->d = MS::operation((l == nullptr ? MS::identity() : l->d),\n     \
    \                         (r == nullptr ? MS::identity() : r->d));\n        return\
    \ np;\n    }\n\n    Node* set(int p, const S& x, int l, int r, Node*& np) {\n\
    \        if (np == nullptr) {\n            np = new_node(MS::identity());\n  \
    \      }\n        if (l + 1 == r) {\n            np->d = x;\n            return\
    \ np;\n        }\n        int m = (l + r) / 2;\n        if (l <= p and p < m)\
    \ {\n            return merge(set(p, x, l, m, np->l), np->r, np);\n        } else\
    \ {\n            return merge(np->l, set(p, x, m, r, np->r), np);\n        }\n\
    \    }\n\n    Node* add(int p, const S& x, int l, int r, Node*& np) {\n      \
    \  if (np == nullptr) {\n            np = new_node(MS::identity());\n        }\n\
    \        if (l + 1 == r) {\n            np->d = MS::operation(np->d, x);\n   \
    \         return np;\n        }\n        int m = (l + r) / 2;\n        if (l <=\
    \ p and p < m) {\n            return merge(add(p, x, l, m, np->l), np->r, np);\n\
    \        } else {\n            return merge(np->l, add(p, x, m, r, np->r), np);\n\
    \        }\n    }\n\n    S prod(int ql, int qr, int l, int r, Node* np) const\
    \ {\n        if (np == nullptr) return MS::identity();\n        //  [ql, qr) \u3068\
    \ [l, r) \u304C\u4EA4\u5DEE\u3057\u306A\u3044\n        if (qr <= l or r <= ql)\
    \ return MS::identity();\n        // [ql, qr) \u304C [l, r) \u3092\u5B8C\u5168\
    \u306B\u542B\u3093\u3067\u3044\u308B\n        if (ql <= l and r <= qr) return\
    \ np->d;\n        int m = (l + r) / 2;\n        return MS::operation(prod(ql,\
    \ qr, l, m, np->l),\n                             prod(ql, qr, m, r, np->r));\n\
    \    }\n};\n#line 7 \"segment_tree/test/dynamic_segment_tree.test.cpp\"\n\nint\
    \ main() {\n    int n;\n    std::cin >> n;\n    const int m = 1000000001;\n  \
    \  // Q log_2(N) = n log_2(m) = 3000000 \u304F\u3089\u3044\n    DynamicSegmentTree<MonoidPlus<long\
    \ long>, 3000000> seg_add(m);\n    DynamicSegmentTree<MonoidPlus<long long>, 3000000>\
    \ seg_set(m);\n    long long ans = 0;\n    for (int i = 0; i < n; i++) {\n   \
    \     int type;\n        std::cin >> type;\n        if (type == 0) {\n       \
    \     int x, y;\n            std::cin >> x >> y;\n            seg_add.add(x, y);\n\
    \            seg_set.set(x, seg_set.get(x) + y);\n        } else {\n         \
    \   int l, r;\n            std::cin >> l >> r;\n            r++;\n           \
    \ assert(seg_add.prod(l, r) == seg_set.prod(l, r));\n            ans += seg_add.prod(l,\
    \ r);\n        }\n    }\n    std::cout << ans << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <iostream>\n\
    \n#include \"../../algebra/monoid/monoid_plus.hpp\"\n#include \"../../segment_tree/dynamic_segment_tree.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    const int m = 1000000001;\n\
    \    // Q log_2(N) = n log_2(m) = 3000000 \u304F\u3089\u3044\n    DynamicSegmentTree<MonoidPlus<long\
    \ long>, 3000000> seg_add(m);\n    DynamicSegmentTree<MonoidPlus<long long>, 3000000>\
    \ seg_set(m);\n    long long ans = 0;\n    for (int i = 0; i < n; i++) {\n   \
    \     int type;\n        std::cin >> type;\n        if (type == 0) {\n       \
    \     int x, y;\n            std::cin >> x >> y;\n            seg_add.add(x, y);\n\
    \            seg_set.set(x, seg_set.get(x) + y);\n        } else {\n         \
    \   int l, r;\n            std::cin >> l >> r;\n            r++;\n           \
    \ assert(seg_add.prod(l, r) == seg_set.prod(l, r));\n            ans += seg_add.prod(l,\
    \ r);\n        }\n    }\n    std::cout << ans << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - algebra/monoid/monoid_plus.hpp
  - segment_tree/dynamic_segment_tree.hpp
  isVerificationFile: true
  path: segment_tree/test/dynamic_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2026-04-13 20:18:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/dynamic_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/dynamic_segment_tree.test.cpp
- /verify/segment_tree/test/dynamic_segment_tree.test.cpp.html
title: segment_tree/test/dynamic_segment_tree.test.cpp
---
