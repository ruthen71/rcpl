---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_1068.test.cpp
    title: verify/aoj_other/aoj_1068.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segment_tree_2d.hpp\"\n\ntemplate <class\
    \ Monoid> struct SegmentTree2D {\n   public:\n    using S = typename Monoid::value_type;\n\
    \    SegmentTree2D() : SegmentTree2D(0, 0) {}\n    SegmentTree2D(int h, int w)\
    \ : SegmentTree2D(std::vector<std::vector<S>>(h, std::vector<S>(w, Monoid::e())))\
    \ {}\n    SegmentTree2D(const std::vector<std::vector<S>>& v) : _h((int)v.size()),\
    \ _w((int)v[0].size()) {\n        logh = 0;\n        while ((1U << logh) < (unsigned\
    \ int)(_h)) logh++;\n        sizeh = 1 << logh;\n        logw = 0;\n        while\
    \ ((1U << logw) < (unsigned int)(_w)) logw++;\n        sizew = 1 << logw;\n  \
    \      d = std::vector<std::vector<S>>(sizeh << 1, std::vector<S>(sizew << 1,\
    \ Monoid::e()));\n        for (int i = 0; i < _h; i++) {\n            for (int\
    \ j = 0; j < _w; j++) {\n                d[i + sizeh][j + sizew] = v[i][j];\n\
    \            }\n        }\n        for (int i = sizeh - 1; i >= 1; i--) {\n  \
    \          for (int j = sizew; j < (sizew << 1); j++) {\n                update_bottom(i,\
    \ j);\n            }\n        }\n        for (int i = 0; i < (sizeh << 1); i++)\
    \ {\n            for (int j = sizew - 1; j >= 1; j--) {\n                update_else(i,\
    \ j);\n            }\n        }\n    }\n\n    void set(int h, int w, const S&\
    \ x) {\n        assert(0 <= h and h < _h and 0 <= w and w < _w);\n        h +=\
    \ sizeh;\n        w += sizew;\n        d[h][w] = x;\n        for (int i = 1; i\
    \ <= logh; i++) update_bottom(h >> i, w);\n        for (int i = 0; i <= logh;\
    \ i++) {\n            for (int j = 1; j <= logw; j++) {\n                update_else(h\
    \ >> i, w >> j);\n            }\n        }\n    }\n\n    void chset(int h, int\
    \ w, const S& x) {\n        assert(0 <= h and h < _h and 0 <= w and w < _w);\n\
    \        h += sizeh;\n        w += sizew;\n        d[h][w] = Monoid::op(d[h][w],\
    \ x);\n        for (int i = 1; i <= logh; i++) update_bottom(h >> i, w);\n   \
    \     for (int i = 0; i <= logh; i++) {\n            for (int j = 1; j <= logw;\
    \ j++) {\n                update_else(h >> i, w >> j);\n            }\n      \
    \  }\n    }\n\n    S operator()(int h, int w) const {\n        assert(0 <= h and\
    \ h < _h and 0 <= w and w < _w);\n        return d[h + sizeh][w + sizew];\n  \
    \  }\n\n    S get(int h, int w) const {\n        assert(0 <= h and h < _h and\
    \ 0 <= w and w < _w);\n        return d[h + sizeh][w + sizew];\n    }\n\n    S\
    \ inner_prod(int h, int w1, int w2) {\n        S sml = Monoid::e(), smr = Monoid::e();\n\
    \        while (w1 < w2) {\n            if (w1 & 1) sml = Monoid::op(sml, d[h][w1++]);\n\
    \            if (w2 & 1) smr = Monoid::op(d[h][--w2], smr);\n            w1 >>=\
    \ 1;\n            w2 >>= 1;\n        }\n        return Monoid::op(sml, smr);\n\
    \    }\n\n    S prod(int h1, int w1, int h2, int w2) {\n        assert(0 <= h1\
    \ and h1 <= h2 and h2 <= _h);\n        assert(0 <= w1 and w1 <= w2 and w2 <= _w);\n\
    \        S sml = Monoid::e(), smr = Monoid::e();\n        h1 += sizeh;\n     \
    \   h2 += sizeh;\n        w1 += sizew;\n        w2 += sizew;\n\n        while\
    \ (h1 < h2) {\n            if (h1 & 1) sml = Monoid::op(sml, inner_prod(h1++,\
    \ w1, w2));\n            if (h2 & 1) smr = Monoid::op(inner_prod(--h2, w1, w2),\
    \ smr);\n            h1 >>= 1;\n            h2 >>= 1;\n        }\n        return\
    \ Monoid::op(sml, smr);\n    }\n\n    S all_prod() const { return d[1][1]; }\n\
    \n   private:\n    int _h, logh, sizeh, _w, logw, sizew;\n    std::vector<std::vector<S>>\
    \ d;\n    inline void update_bottom(int i, int j) { d[i][j] = Monoid::op(d[(i\
    \ << 1) | 0][j], d[(i << 1) | 1][j]); }\n    inline void update_else(int i, int\
    \ j) { d[i][j] = Monoid::op(d[i][(j << 1) | 0], d[i][(j << 1) | 1]); }\n};\n"
  code: "#pragma once\n\ntemplate <class Monoid> struct SegmentTree2D {\n   public:\n\
    \    using S = typename Monoid::value_type;\n    SegmentTree2D() : SegmentTree2D(0,\
    \ 0) {}\n    SegmentTree2D(int h, int w) : SegmentTree2D(std::vector<std::vector<S>>(h,\
    \ std::vector<S>(w, Monoid::e()))) {}\n    SegmentTree2D(const std::vector<std::vector<S>>&\
    \ v) : _h((int)v.size()), _w((int)v[0].size()) {\n        logh = 0;\n        while\
    \ ((1U << logh) < (unsigned int)(_h)) logh++;\n        sizeh = 1 << logh;\n  \
    \      logw = 0;\n        while ((1U << logw) < (unsigned int)(_w)) logw++;\n\
    \        sizew = 1 << logw;\n        d = std::vector<std::vector<S>>(sizeh <<\
    \ 1, std::vector<S>(sizew << 1, Monoid::e()));\n        for (int i = 0; i < _h;\
    \ i++) {\n            for (int j = 0; j < _w; j++) {\n                d[i + sizeh][j\
    \ + sizew] = v[i][j];\n            }\n        }\n        for (int i = sizeh -\
    \ 1; i >= 1; i--) {\n            for (int j = sizew; j < (sizew << 1); j++) {\n\
    \                update_bottom(i, j);\n            }\n        }\n        for (int\
    \ i = 0; i < (sizeh << 1); i++) {\n            for (int j = sizew - 1; j >= 1;\
    \ j--) {\n                update_else(i, j);\n            }\n        }\n    }\n\
    \n    void set(int h, int w, const S& x) {\n        assert(0 <= h and h < _h and\
    \ 0 <= w and w < _w);\n        h += sizeh;\n        w += sizew;\n        d[h][w]\
    \ = x;\n        for (int i = 1; i <= logh; i++) update_bottom(h >> i, w);\n  \
    \      for (int i = 0; i <= logh; i++) {\n            for (int j = 1; j <= logw;\
    \ j++) {\n                update_else(h >> i, w >> j);\n            }\n      \
    \  }\n    }\n\n    void chset(int h, int w, const S& x) {\n        assert(0 <=\
    \ h and h < _h and 0 <= w and w < _w);\n        h += sizeh;\n        w += sizew;\n\
    \        d[h][w] = Monoid::op(d[h][w], x);\n        for (int i = 1; i <= logh;\
    \ i++) update_bottom(h >> i, w);\n        for (int i = 0; i <= logh; i++) {\n\
    \            for (int j = 1; j <= logw; j++) {\n                update_else(h\
    \ >> i, w >> j);\n            }\n        }\n    }\n\n    S operator()(int h, int\
    \ w) const {\n        assert(0 <= h and h < _h and 0 <= w and w < _w);\n     \
    \   return d[h + sizeh][w + sizew];\n    }\n\n    S get(int h, int w) const {\n\
    \        assert(0 <= h and h < _h and 0 <= w and w < _w);\n        return d[h\
    \ + sizeh][w + sizew];\n    }\n\n    S inner_prod(int h, int w1, int w2) {\n \
    \       S sml = Monoid::e(), smr = Monoid::e();\n        while (w1 < w2) {\n \
    \           if (w1 & 1) sml = Monoid::op(sml, d[h][w1++]);\n            if (w2\
    \ & 1) smr = Monoid::op(d[h][--w2], smr);\n            w1 >>= 1;\n           \
    \ w2 >>= 1;\n        }\n        return Monoid::op(sml, smr);\n    }\n\n    S prod(int\
    \ h1, int w1, int h2, int w2) {\n        assert(0 <= h1 and h1 <= h2 and h2 <=\
    \ _h);\n        assert(0 <= w1 and w1 <= w2 and w2 <= _w);\n        S sml = Monoid::e(),\
    \ smr = Monoid::e();\n        h1 += sizeh;\n        h2 += sizeh;\n        w1 +=\
    \ sizew;\n        w2 += sizew;\n\n        while (h1 < h2) {\n            if (h1\
    \ & 1) sml = Monoid::op(sml, inner_prod(h1++, w1, w2));\n            if (h2 &\
    \ 1) smr = Monoid::op(inner_prod(--h2, w1, w2), smr);\n            h1 >>= 1;\n\
    \            h2 >>= 1;\n        }\n        return Monoid::op(sml, smr);\n    }\n\
    \n    S all_prod() const { return d[1][1]; }\n\n   private:\n    int _h, logh,\
    \ sizeh, _w, logw, sizew;\n    std::vector<std::vector<S>> d;\n    inline void\
    \ update_bottom(int i, int j) { d[i][j] = Monoid::op(d[(i << 1) | 0][j], d[(i\
    \ << 1) | 1][j]); }\n    inline void update_else(int i, int j) { d[i][j] = Monoid::op(d[i][(j\
    \ << 1) | 0], d[i][(j << 1) | 1]); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree_2d.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_other/aoj_1068.test.cpp
documentation_of: data_structure/segment_tree_2d.hpp
layout: document
title: "2D Segment Tree (2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

[自分の1次元セグメント木](https://ruthen71.github.io/rcpl/src/data_structure/segment_tree.hpp) をなるべくそのまま2次元に拡張することを意識して設計されている。


基本は `ac-library` と同じ。

- 非再帰
- 2冪
- 抽象化済
- 外部 `0-indexed` 、内部 `1-indexed`

工夫点は以下。

- 毎回モノイドを書くのはめんどくさい、ということで、モノイド構造体をインクルードすれば済むようになっている
    - `#include "algebra/monoid_max.hpp"` などでインクルードできる
    - `segment_tree_2d<monoid_max<int>> seg(h, w);` などで2次元RMQが使える
- `ac-library` の `seg.get(i)` の2次元版に相当する機能を `seg(h, w)` で実現している
- `seg[h][w] = op(seg[h][w], x)` とする `seg.chset(h, w, x)` を採用
    - `seg[h][w] = x` とするのは `seg.set(h, w, x)`
    - 案外 `seg.set(h, w, op(seg[h][w], x))` みたいなコードを書く機会は多いと思っている
    - 計算量は $ O(\log H \log W) $
    - モノイドが可換でないなどの理由により、`op(seg[h][w], x)` と `op(x, seg[h][w])` の結果が異なる場合に注意
- マクロ不使用
    - 使いやすさを意識

## 謝辞

変数やメソッドの命名規則、1次元セグメント木と共通する部分は [ac-library](https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp) を、モノイドの抽象化は [maspyさんのライブラリ](https://github.com/maspypy/library/blob/main/ds/segtree.hpp) を、2次元への拡張による追加の処理の記述は [Nyaanさんのライブラリ](https://github.com/NyaanNyaan/library/blob/master/data-structure-2d/2d-segment-tree.hpp) を参考にさせていただきました。ありがとうございます。
