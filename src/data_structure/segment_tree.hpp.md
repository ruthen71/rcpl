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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/segment_tree.md
    document_title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "#line 2 \"src/data_structure/segment_tree.hpp\"\n\ntemplate <class\
    \ Monoid> struct segment_tree {\n    using S = typename Monoid::value_type;\n\
    \    int _n, log, size;\n    std::vector<S> d;\n    segment_tree() : segment_tree(0)\
    \ {}\n    segment_tree(int n) : segment_tree(std::vector<S>(n, Monoid::e())) {}\n\
    \    segment_tree(const std::vector<S>& v) : _n((int)v.size()) {\n        log\
    \ = 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n        size\
    \ = 1 << log;\n        d = std::vector<S>(2 * size, Monoid::e());\n        for\
    \ (int i = 0; i < _n; i++) d[i + size] = v[i];\n        for (int i = size - 1;\
    \ i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void update(int\
    \ k) { d[k] = Monoid::op(d[k << 1], d[(k << 1) | 1]); }\n\n    void set(int p,\
    \ const S& x) {\n        assert(0 <= p && p < _n);\n        p += size;\n     \
    \   d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\
    \n    void chset(int p, const S& x) {\n        assert(0 <= p && p < _n);\n   \
    \     p += size;\n        d[p] = Monoid::op(d[p], x);\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S operator[](int p) const {\n \
    \       assert(0 <= p && p < _n);\n        return d[p + size];\n    }\n\n    S\
    \ prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <= _n);\n \
    \       S sml = Monoid::e(), smr = Monoid::e();\n        l += size;\n        r\
    \ += size;\n\n        while (l < r) {\n            if (l & 1) sml = Monoid::op(sml,\
    \ d[l++]);\n            if (r & 1) smr = Monoid::op(d[--r], smr);\n          \
    \  l >>= 1;\n            r >>= 1;\n        }\n        return Monoid::op(sml, smr);\n\
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
    \ docs/data_structure/segment_tree.md\n */\n"
  code: "#pragma once\n\ntemplate <class Monoid> struct segment_tree {\n    using\
    \ S = typename Monoid::value_type;\n    int _n, log, size;\n    std::vector<S>\
    \ d;\n    segment_tree() : segment_tree(0) {}\n    segment_tree(int n) : segment_tree(std::vector<S>(n,\
    \ Monoid::e())) {}\n    segment_tree(const std::vector<S>& v) : _n((int)v.size())\
    \ {\n        log = 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n\
    \        size = 1 << log;\n        d = std::vector<S>(2 * size, Monoid::e());\n\
    \        for (int i = 0; i < _n; i++) d[i + size] = v[i];\n        for (int i\
    \ = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n   \
    \ void update(int k) { d[k] = Monoid::op(d[k << 1], d[(k << 1) | 1]); }\n\n  \
    \  void set(int p, const S& x) {\n        assert(0 <= p && p < _n);\n        p\
    \ += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    void chset(int p, const S& x) {\n        assert(0 <= p\
    \ && p < _n);\n        p += size;\n        d[p] = Monoid::op(d[p], x);\n     \
    \   for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S operator[](int\
    \ p) const {\n        assert(0 <= p && p < _n);\n        return d[p + size];\n\
    \    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        S sml = Monoid::e(), smr = Monoid::e();\n        l += size;\n\
    \        r += size;\n\n        while (l < r) {\n            if (l & 1) sml = Monoid::op(sml,\
    \ d[l++]);\n            if (r & 1) smr = Monoid::op(d[--r], smr);\n          \
    \  l >>= 1;\n            r >>= 1;\n        }\n        return Monoid::op(sml, smr);\n\
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
    \ docs/data_structure/segment_tree.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2022-08-23 21:51:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
  - verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
documentation_of: src/data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segment_tree.hpp
- /library/src/data_structure/segment_tree.hpp.html
title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
# Segment Tree (セグメント木)

## 概要

実装は [ac-library](https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp) と [maspyさんのライブラリ](https://github.com/maspypy/library/blob/main/ds/segtree.hpp) を大いに参考にさせていただきました。この場を借りてお礼申し上げます。


基本は `ac-library` と同じ。

- 非再帰
- 2冪
- 抽象化済
- 外部 `0-indexed` 、内部 `1-indexed`


工夫点は以下。

- 毎回モノイドを書くのはめんどくさい、ということで、モノイド構造体をインクルードすれば済むようになっている
    - `#include "src/algebra/monoid_max.hpp"` などでインクルードできる
    - `segment_tree<monoid_max<int>> seg(n);` などでRMQが使える
- `ac-library` の `seg.get(i)` に相当する機能を `seg[i]` で実現している
    - より直感的
- `op(a[p], x) == x` が成立するときのみ `set()` を行う `chset()` を採用
    - 案外 `seg.set(i, op(seg[i], x))` みたいなコードを書く機会は多いと思っている
    - `op(a[p], x) == x` の成立・不成立によらず、計算量は $ O(\log N) $
        - 条件分岐させても良かったが、モノイドが複雑になると `==` などでややこしくなりそうな気がした

