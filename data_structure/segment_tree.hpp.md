---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
    title: verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
    title: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yuki/yuki_1036_segment_tree.test.cpp
    title: verify/yuki/yuki_1036_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segment_tree.hpp\"\n\ntemplate <class Monoid>\
    \ struct SegmentTree {\n   public:\n    using S = typename Monoid::value_type;\n\
    \    SegmentTree() : SegmentTree(0) {}\n    SegmentTree(int n) : SegmentTree(std::vector<S>(n,\
    \ Monoid::e())) {}\n    SegmentTree(const std::vector<S>& v) : _n((int)v.size())\
    \ {\n        log = 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n\
    \        size = 1 << log;\n        d = std::vector<S>(size << 1, Monoid::e());\n\
    \        for (int i = 0; i < _n; i++) d[i + size] = v[i];\n        for (int i\
    \ = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n   \
    \ void set(int p, const S& x) {\n        assert(0 <= p and p < _n);\n        p\
    \ += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    void chset(int p, const S& x) {\n        assert(0 <= p\
    \ and p < _n);\n        p += size;\n        d[p] = Monoid::op(d[p], x);\n    \
    \    for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S operator[](int\
    \ p) const {\n        assert(0 <= p and p < _n);\n        return d[p + size];\n\
    \    }\n\n    S get(int p) const {\n        assert(0 <= p && p < _n);\n      \
    \  return d[p + size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0\
    \ <= l and l <= r and r <= _n);\n        S sml = Monoid::e(), smr = Monoid::e();\n\
    \        l += size;\n        r += size;\n\n        while (l < r) {\n         \
    \   if (l & 1) sml = Monoid::op(sml, d[l++]);\n            if (r & 1) smr = Monoid::op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ Monoid::op(sml, smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n\
    \    template <class F> int max_right(int l, F& f) const {\n        assert(0 <=\
    \ l and l <= _n);\n        assert(f(Monoid::e()));\n        if (l == _n) return\
    \ _n;\n        l += size;\n        S sm = Monoid::e();\n        do {\n       \
    \     while ((l & 1) == 0) l >>= 1;\n            if (!f(Monoid::op(sm, d[l])))\
    \ {\n                while (l < size) {\n                    l <<= 1;\n      \
    \              if (f(Monoid::op(sm, d[l]))) {\n                        sm = Monoid::op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = Monoid::op(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);  // 2\u3079\u304D\
    \u307E\u305F\u306F0\u306E\u3068\u304Dfalse\n        return _n;\n    }\n\n    template\
    \ <class F> int min_left(int r, F& f) const {\n        assert(0 <= r and r <=\
    \ _n);\n        assert(f(Monoid::e()));\n        if (r == 0) return 0;\n     \
    \   r += size;\n        S sm = Monoid::e();\n        do {\n            r--;\n\
    \            while (r > 1 and (r & 1)) r >>= 1;\n            if (!f(Monoid::op(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (r << 1)\
    \ | 1;\n                    if (f(Monoid::op(d[r], sm))) {\n                 \
    \       sm = Monoid::op(d[r], sm);\n                        r--;\n           \
    \         }\n                }\n                return r + 1 - size;\n       \
    \     }\n            sm = Monoid::op(d[r], sm);\n        } while ((r & -r) !=\
    \ r);  // 2\u3079\u304D\u307E\u305F\u306F0\u306E\u3068\u304Dfalse\n        return\
    \ 0;\n    }\n\n   private:\n    int _n, log, size;\n    std::vector<S> d;\n  \
    \  inline void update(int k) { d[k] = Monoid::op(d[k << 1], d[(k << 1) | 1]);\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <class Monoid> struct SegmentTree {\n   public:\n\
    \    using S = typename Monoid::value_type;\n    SegmentTree() : SegmentTree(0)\
    \ {}\n    SegmentTree(int n) : SegmentTree(std::vector<S>(n, Monoid::e())) {}\n\
    \    SegmentTree(const std::vector<S>& v) : _n((int)v.size()) {\n        log =\
    \ 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n        size =\
    \ 1 << log;\n        d = std::vector<S>(size << 1, Monoid::e());\n        for\
    \ (int i = 0; i < _n; i++) d[i + size] = v[i];\n        for (int i = size - 1;\
    \ i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void set(int\
    \ p, const S& x) {\n        assert(0 <= p and p < _n);\n        p += size;\n \
    \       d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n  \
    \  }\n\n    void chset(int p, const S& x) {\n        assert(0 <= p and p < _n);\n\
    \        p += size;\n        d[p] = Monoid::op(d[p], x);\n        for (int i =\
    \ 1; i <= log; i++) update(p >> i);\n    }\n\n    S operator[](int p) const {\n\
    \        assert(0 <= p and p < _n);\n        return d[p + size];\n    }\n\n  \
    \  S get(int p) const {\n        assert(0 <= p && p < _n);\n        return d[p\
    \ + size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l and\
    \ l <= r and r <= _n);\n        S sml = Monoid::e(), smr = Monoid::e();\n    \
    \    l += size;\n        r += size;\n\n        while (l < r) {\n            if\
    \ (l & 1) sml = Monoid::op(sml, d[l++]);\n            if (r & 1) smr = Monoid::op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ Monoid::op(sml, smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n\
    \    template <class F> int max_right(int l, F& f) const {\n        assert(0 <=\
    \ l and l <= _n);\n        assert(f(Monoid::e()));\n        if (l == _n) return\
    \ _n;\n        l += size;\n        S sm = Monoid::e();\n        do {\n       \
    \     while ((l & 1) == 0) l >>= 1;\n            if (!f(Monoid::op(sm, d[l])))\
    \ {\n                while (l < size) {\n                    l <<= 1;\n      \
    \              if (f(Monoid::op(sm, d[l]))) {\n                        sm = Monoid::op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = Monoid::op(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);  // 2\u3079\u304D\
    \u307E\u305F\u306F0\u306E\u3068\u304Dfalse\n        return _n;\n    }\n\n    template\
    \ <class F> int min_left(int r, F& f) const {\n        assert(0 <= r and r <=\
    \ _n);\n        assert(f(Monoid::e()));\n        if (r == 0) return 0;\n     \
    \   r += size;\n        S sm = Monoid::e();\n        do {\n            r--;\n\
    \            while (r > 1 and (r & 1)) r >>= 1;\n            if (!f(Monoid::op(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (r << 1)\
    \ | 1;\n                    if (f(Monoid::op(d[r], sm))) {\n                 \
    \       sm = Monoid::op(d[r], sm);\n                        r--;\n           \
    \         }\n                }\n                return r + 1 - size;\n       \
    \     }\n            sm = Monoid::op(d[r], sm);\n        } while ((r & -r) !=\
    \ r);  // 2\u3079\u304D\u307E\u305F\u306F0\u306E\u3068\u304Dfalse\n        return\
    \ 0;\n    }\n\n   private:\n    int _n, log, size;\n    std::vector<S> d;\n  \
    \  inline void update(int k) { d[k] = Monoid::op(d[k << 1], d[(k << 1) | 1]);\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
  - verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
  - verify/yuki/yuki_1036_segment_tree.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

基本は `ac-library` と同じ。

- 非再帰
- 2冪
- 抽象化済
- 外部 `0-indexed` 、内部 `1-indexed`


工夫点は以下。

- 毎回モノイドを書くのはめんどくさい、ということで、モノイド構造体をインクルードすれば済むようになっている
    - `#include "algebra/monoid_max.hpp"` などでインクルードできる
    - `segment_tree<monoid_max<int>> seg(n);` などでRMQが使える
- `ac-library` の `seg.get(i)` に相当する機能を `seg[i]` で実現している
- `seg[p] = op(seg[p], x)` とする `seg.chset(p, x)` を採用
    - `seg[p] = x` とするのは `seg.set(p, x)`
    - 案外 `seg.set(p, op(seg[p], x))` みたいなコードを書く機会は多いと思っている
    - 計算量は $ O(\log N) $
    - モノイドが可換でないなどの理由により、`op(seg[p], x)` と `op(x, seg[p])` の結果が異なる場合に注意
- マクロ不使用
    - 使いやすさを意識

## 謝辞

変数やメソッドの命名規則、メソッドの実装は [ac-library](https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp) を、モノイドの抽象化は [maspyさんのライブラリ](https://github.com/maspypy/library/blob/main/ds/segtree.hpp) を参考にさせていただきました。ありがとうございます。

