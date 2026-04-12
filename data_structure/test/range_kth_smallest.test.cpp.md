---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/range_kth_smallest.hpp
    title: "\u533A\u9593\u306E k \u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u6C42\
      \u3081\u308B\u30AF\u30A8\u30EA"
  - icon: ':heavy_check_mark:'
    path: segment_tree/persistent_segment_tree.hpp
    title: "Persistent Segment Tree (\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"data_structure/test/range_kth_smallest.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#include <iostream>\n\
    \n#line 2 \"data_structure/range_kth_smallest.hpp\"\n\n#include <algorithm>\n\n\
    #line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate <class T> struct MonoidPlus\
    \ {\n    using value_type = T;\n    static constexpr T operation(const T& a, const\
    \ T& b) noexcept {\n        return a + b;\n    }\n    static constexpr T identity()\
    \ noexcept { return T(0); }\n    static constexpr T inverse(const T& a) noexcept\
    \ { return -a; }\n    static constexpr bool commutative = true;\n};\n#line 2 \"\
    segment_tree/persistent_segment_tree.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n// Persistent Segment Tree\n// N + Q log_2(N) \u306F N = Q = 500000 \u306E\u3068\
    \u304D 10000000 \u304F\u3089\u3044\ntemplate <class MS, int MAX_NODES = 20'000'000>\
    \ struct PersistentSegmentTree {\n  public:\n    using S = typename MS::value_type;\n\
    \n    struct Node {\n        S d;\n        Node *l, *r;\n        Node() = default;\n\
    \        Node(S v, Node* l = nullptr, Node* r = nullptr) : d(v), l(l), r(r) {}\n\
    \    };\n\n    PersistentSegmentTree() = default;\n\n    explicit PersistentSegmentTree(int\
    \ n)\n        : PersistentSegmentTree(std::vector<S>(n, MS::identity())) {}\n\n\
    \    explicit PersistentSegmentTree(const std::vector<S>& v)\n        : n((int)(v.size()))\
    \ {\n        roots.push_back(build(v, 0, n));\n    }\n\n    int get_time() { return\
    \ (int)(roots.size()) - 1; }\n\n    Node* set(int p, const S& x, Node* root) {\n\
    \        assert(0 <= p and p < n);\n        roots.push_back(set(p, x, 0, n, root));\n\
    \        return roots.back();\n    }\n\n    Node* set(int p, const S& x) { return\
    \ set(p, x, roots.back()); }\n\n    Node* set(int p, const S& x, int t) {\n  \
    \      assert(0 <= t and t < (int)(roots.size()));\n        return set(p, x, roots[t]);\n\
    \    }\n\n    Node* add(int p, const S& x, Node* root) {\n        assert(0 <=\
    \ p and p < n);\n        roots.push_back(add(p, x, 0, n, root));\n        return\
    \ roots.back();\n    }\n\n    Node* add(int p, const S& x) { return add(p, x,\
    \ roots.back()); }\n\n    Node* add(int p, const S& x, int t) {\n        assert(0\
    \ <= t and t < (int)(roots.size()));\n        return add(p, x, roots[t]);\n  \
    \  }\n\n    S get(int p, Node* root) const {\n        assert(0 <= p and p < n);\n\
    \        return prod(p, p + 1, root);\n    }\n\n    S get(int p) const { return\
    \ get(p, roots.back()); }\n\n    S get(int p, int t) const {\n        assert(0\
    \ <= t and t < (int)(roots.size()));\n        return get(p, roots[t]);\n    }\n\
    \n    S operator[](int p) const {\n        assert(0 <= p and p < n);\n       \
    \ return prod(p, p + 1);\n    }\n\n    S prod(int l, int r, Node* root) const\
    \ {\n        assert(0 <= l and l <= r and r <= n);\n        return prod(l, r,\
    \ 0, n, root);\n    }\n\n    S prod(int l, int r) const { return prod(l, r, roots.back());\
    \ }\n\n    S prod(int l, int r, int t) const {\n        assert(0 <= t and t <\
    \ (int)(roots.size()));\n        return prod(l, r, roots[t]);\n    }\n\n    S\
    \ all_prod(Node* root) const { return root->d; }\n\n    S all_prod() const { return\
    \ all_prod(roots.back()); }\n\n    S all_prod(int t) const {\n        assert(0\
    \ <= t and t < (int)(roots.size()));\n        return all_prod(roots[t]);\n   \
    \ }\n\n    std::vector<S> make_vector(Node* root) const {\n        std::vector<S>\
    \ vec(n);\n        for (int i = 0; i < n; i++) vec[i] = get(i, root);\n      \
    \  return vec;\n    }\n\n    std::vector<S> make_vector() const { return make_vector(roots.back());\
    \ }\n\n    std::vector<S> make_vector(int t) const {\n        assert(0 <= t and\
    \ t < (int)(roots.size()));\n        return make_vector(roots[t]);\n    }\n\n\
    \  private:\n    int n;\n    std::vector<Node*> roots;\n    static inline Node\
    \ pool[MAX_NODES];\n    static inline int pool_idx = 0;\n\n    Node* new_node(S\
    \ v, Node* l = nullptr, Node* r = nullptr) {\n        return &(pool[pool_idx++]\
    \ = Node(v, l, r));\n    }\n\n    Node* merge(Node* l, Node* r) {\n        return\
    \ new_node(MS::operation(l->d, r->d), l, r);\n    }\n\n    Node* build(const std::vector<S>&\
    \ v, int l, int r) {\n        if (l + 1 == r) {\n            return new_node(v[l]);\n\
    \        }\n        int m = (l + r) / 2;\n        return merge(build(v, l, m),\
    \ build(v, m, r));\n    }\n\n    Node* set(int p, const S& x, int l, int r, Node*\
    \ np) {\n        if (l + 1 == r) {\n            return new_node(x);\n        }\n\
    \        int m = (l + r) / 2;\n        if (l <= p and p < m) {\n            return\
    \ merge(set(p, x, l, m, np->l), np->r);\n        } else {\n            return\
    \ merge(np->l, set(p, x, m, r, np->r));\n        }\n    }\n\n    Node* add(int\
    \ p, const S& x, int l, int r, Node* np) {\n        if (l + 1 == r) {\n      \
    \      return new_node(MS::operation(np->d, x));\n        }\n        int m = (l\
    \ + r) / 2;\n        if (l <= p and p < m) {\n            return merge(add(p,\
    \ x, l, m, np->l), np->r);\n        } else {\n            return merge(np->l,\
    \ add(p, x, m, r, np->r));\n        }\n    }\n\n    S prod(int ql, int qr, int\
    \ l, int r, Node* np) const {\n        // [ql, qr) \u3068 [l, r) \u304C\u4EA4\u5DEE\
    \u3057\u306A\u3044\n        if (qr <= l or r <= ql) return MS::identity();\n \
    \       // [ql, qr) \u304C [l, r) \u3092\u5B8C\u5168\u306B\u542B\u3093\u3067\u3044\
    \u308B\n        if (ql <= l and r <= qr) return np->d;\n        int m = (l + r)\
    \ / 2;\n        return MS::operation(prod(ql, qr, l, m, np->l),\n            \
    \                 prod(ql, qr, m, r, np->r));\n    }\n};\n#line 7 \"data_structure/range_kth_smallest.hpp\"\
    \n\ntemplate <class T> struct RangeKthSmallest {\n  public:\n    RangeKthSmallest()\
    \ = default;\n\n    explicit RangeKthSmallest(const std::vector<T>& a)\n     \
    \   : n((int)(a.size())), comp(a) {\n        std::sort(comp.begin(), comp.end());\n\
    \        comp.erase(std::unique(comp.begin(), comp.end()), comp.end());\n    \
    \    m = (int)(comp.size());\n        seg = PersistentSegmentTree<MonoidPlus<int>>(m);\n\
    \        for (int i = 0; i < n; i++) {\n            int index =\n            \
    \    std::lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();\n      \
    \      seg.add(index, 1);\n        }\n    }\n\n    T query(int l, int r, int k)\
    \ {\n        assert(0 <= l and l < r and r <= n);\n        assert(0 <= k and k\
    \ < r - l);\n        auto f = [&](int v) -> bool {\n            return seg.prod(0,\
    \ v, r) - seg.prod(0, v, l) >= k + 1;\n        };\n        int ok = m, ng = 0;\n\
    \        while (ok - ng > 1) {\n            int md = (ok + ng) / 2;\n        \
    \    if (f(md)) {\n                ok = md;\n            } else {\n          \
    \      ng = md;\n            }\n        }\n        return comp[ok - 1];\n    }\n\
    \n  private:\n    int n, m;\n    std::vector<T> comp;\n    PersistentSegmentTree<MonoidPlus<int>>\
    \ seg;\n};\n#line 6 \"data_structure/test/range_kth_smallest.test.cpp\"\n\nint\
    \ main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<long long>\
    \ a(N);\n    for (int i = 0; i < N; i++) std::cin >> a[i];\n    RangeKthSmallest\
    \ rks(a);\n    while (Q--) {\n        int l, r, k;\n        std::cin >> l >> r\
    \ >> k;\n        std::cout << rks.query(l, r, k) << '\\n';\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include <iostream>\n\n#include \"../../data_structure/range_kth_smallest.hpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<long\
    \ long> a(N);\n    for (int i = 0; i < N; i++) std::cin >> a[i];\n    RangeKthSmallest\
    \ rks(a);\n    while (Q--) {\n        int l, r, k;\n        std::cin >> l >> r\
    \ >> k;\n        std::cout << rks.query(l, r, k) << '\\n';\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - data_structure/range_kth_smallest.hpp
  - algebra/monoid/monoid_plus.hpp
  - segment_tree/persistent_segment_tree.hpp
  isVerificationFile: true
  path: data_structure/test/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2026-04-12 20:46:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/range_kth_smallest.test.cpp
- /verify/data_structure/test/range_kth_smallest.test.cpp.html
title: data_structure/test/range_kth_smallest.test.cpp
---
