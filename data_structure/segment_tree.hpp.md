---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/euler_tour.test.cpp
    title: verify/graph/euler_tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_1.test.cpp
    title: verify/graph/heavy_light_decomposition_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_3.test.cpp
    title: verify/graph/heavy_light_decomposition_3.test.cpp
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
  bundledCode: "#line 2 \"data_structure/segment_tree.hpp\"\n#include <vector>\n#include\
    \ <cassert>\ntemplate <class MS> struct SegmentTree {\n   public:\n    using S\
    \ = typename MS::S;\n    SegmentTree() : SegmentTree(0) {}\n    SegmentTree(int\
    \ n) : SegmentTree(std::vector<S>(n, MS::e())) {}\n    SegmentTree(const std::vector<S>&\
    \ v) : n((int)(v.size())) {\n        log = 0;\n        while ((1U << log) < (unsigned\
    \ int)(n)) log++;\n        size = 1 << log;\n        d = std::vector<S>(size <<\
    \ 1, MS::e());\n        for (int i = 0; i < n; i++) d[i + size] = v[i];\n    \
    \    for (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n\
    \    }\n\n    void set(int p, const S& x) {\n        assert(0 <= p and p < n);\n\
    \        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    void chset(int p, const S& x) {\n        assert(0\
    \ <= p and p < n);\n        p += size;\n        d[p] = MS::op(d[p], x);\n    \
    \    for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S operator[](int\
    \ p) const {\n        assert(0 <= p and p < n);\n        return d[p + size];\n\
    \    }\n\n    S get(int p) const {\n        assert(0 <= p && p < n);\n       \
    \ return d[p + size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        S sml = MS::e(), smr = MS::e();\n    \
    \    l += size;\n        r += size;\n\n        while (l < r) {\n            if\
    \ (l & 1) sml = MS::op(sml, d[l++]);\n            if (r & 1) smr = MS::op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ MS::op(sml, smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template\
    \ <class G> int max_right(int l, G& g) const {\n        assert(0 <= l and l <=\
    \ n);\n        assert(g(MS::e()));\n        if (l == n) return n;\n        l +=\
    \ size;\n        S sm = MS::e();\n        do {\n            while ((l & 1) ==\
    \ 0) l >>= 1;\n            if (!g(MS::op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    l <<= 1;\n                    if (g(MS::op(sm,\
    \ d[l]))) {\n                        sm = MS::op(sm, d[l]);\n                \
    \        l++;\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = MS::op(sm, d[l]);\n            l++;\n\
    \        } while ((l & -l) != l);\n        return n;\n    }\n\n    template <class\
    \ G> int min_left(int r, G& g) const {\n        assert(0 <= r and r <= n);\n \
    \       assert(g(MS::e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = MS::e();\n        do {\n            r--;\n            while (r\
    \ > 1 and (r & 1)) r >>= 1;\n            if (!g(MS::op(d[r], sm))) {\n       \
    \         while (r < size) {\n                    r = (r << 1) | 1;\n        \
    \            if (g(MS::op(d[r], sm))) {\n                        sm = MS::op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = MS::op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n    std::vector<S>\
    \ make_vector() {\n        std::vector<S> vec(n);\n        for (int i = 0; i <\
    \ n; i++) vec[i] = get(i);\n        return vec;\n    }\n\n   private:\n    int\
    \ n, log, size;\n    std::vector<S> d;\n    inline void update(int k) { d[k] =\
    \ MS::op(d[k << 1], d[(k << 1) | 1]); }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\ntemplate <class MS>\
    \ struct SegmentTree {\n   public:\n    using S = typename MS::S;\n    SegmentTree()\
    \ : SegmentTree(0) {}\n    SegmentTree(int n) : SegmentTree(std::vector<S>(n,\
    \ MS::e())) {}\n    SegmentTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        log = 0;\n        while ((1U << log) < (unsigned int)(n)) log++;\n\
    \        size = 1 << log;\n        d = std::vector<S>(size << 1, MS::e());\n \
    \       for (int i = 0; i < n; i++) d[i + size] = v[i];\n        for (int i =\
    \ size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void\
    \ set(int p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n\
    \        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n\n    void chset(int p, const S& x) {\n        assert(0 <= p and p < n);\n\
    \        p += size;\n        d[p] = MS::op(d[p], x);\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S operator[](int p) const {\n \
    \       assert(0 <= p and p < n);\n        return d[p + size];\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < n);\n        return d[p + size];\n\
    \    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and\
    \ r <= n);\n        S sml = MS::e(), smr = MS::e();\n        l += size;\n    \
    \    r += size;\n\n        while (l < r) {\n            if (l & 1) sml = MS::op(sml,\
    \ d[l++]);\n            if (r & 1) smr = MS::op(d[--r], smr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return MS::op(sml, smr);\n    }\n\
    \n    S all_prod() const { return d[1]; }\n\n    template <class G> int max_right(int\
    \ l, G& g) const {\n        assert(0 <= l and l <= n);\n        assert(g(MS::e()));\n\
    \        if (l == n) return n;\n        l += size;\n        S sm = MS::e();\n\
    \        do {\n            while ((l & 1) == 0) l >>= 1;\n            if (!g(MS::op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l <<= 1;\n\
    \                    if (g(MS::op(sm, d[l]))) {\n                        sm =\
    \ MS::op(sm, d[l]);\n                        l++;\n                    }\n   \
    \             }\n                return l - size;\n            }\n           \
    \ sm = MS::op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n\
    \        return n;\n    }\n\n    template <class G> int min_left(int r, G& g)\
    \ const {\n        assert(0 <= r and r <= n);\n        assert(g(MS::e()));\n \
    \       if (r == 0) return 0;\n        r += size;\n        S sm = MS::e();\n \
    \       do {\n            r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n\
    \            if (!g(MS::op(d[r], sm))) {\n                while (r < size) {\n\
    \                    r = (r << 1) | 1;\n                    if (g(MS::op(d[r],\
    \ sm))) {\n                        sm = MS::op(d[r], sm);\n                  \
    \      r--;\n                    }\n                }\n                return\
    \ r + 1 - size;\n            }\n            sm = MS::op(d[r], sm);\n        }\
    \ while ((r & -r) != r);\n        return 0;\n    }\n\n    std::vector<S> make_vector()\
    \ {\n        std::vector<S> vec(n);\n        for (int i = 0; i < n; i++) vec[i]\
    \ = get(i);\n        return vec;\n    }\n\n   private:\n    int n, log, size;\n\
    \    std::vector<S> d;\n    inline void update(int k) { d[k] = MS::op(d[k << 1],\
    \ d[(k << 1) | 1]); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-07-13 11:37:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki/yuki_1036_segment_tree.test.cpp
  - verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
  - verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
  - verify/graph/heavy_light_decomposition_3.test.cpp
  - verify/graph/heavy_light_decomposition_1.test.cpp
  - verify/graph/euler_tour.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

基本的に `algebra/monoid_s` 以下のファイルをインクルードして使う

```cpp
// 1 点更新区間和
#include "algebra/monoid_s/monoid_sum.hpp"
#include "data_structure/segment_tree.hpp"
int main() {
    vector<int> A;
    SegmentTree<MonoidSum<int>> seg(A);
}
```

- `seg[i]` は `seg.get(i)` と同じ
- `seg.chset(p, x)` は `seg.set(p, op(seg.get(p), x))` と同じ (`seg.set(p, op(x, seg.get(p)))` ではない)


## 謝辞

実装の参考にした [ac-library](https://github.com/atcoder/ac-library) や [maspyさんのライブラリ](https://github.com/maspypy/library) に感謝申し上げます。
