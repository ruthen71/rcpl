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
    \ MS> struct SegmentTree2D {\n   public:\n    using S = typename MS::S;\n    SegmentTree2D()\
    \ : SegmentTree2D(0, 0) {}\n    SegmentTree2D(int h, int w) : SegmentTree2D(std::vector<std::vector<S>>(h,\
    \ std::vector<S>(w, MS::e()))) {}\n    SegmentTree2D(const std::vector<std::vector<S>>&\
    \ v) : h((int)(v.size())), w((int)(v[0].size())) {\n        logh = 0;\n      \
    \  while ((1U << logh) < (unsigned int)(h)) logh++;\n        sizeh = 1 << logh;\n\
    \        logw = 0;\n        while ((1U << logw) < (unsigned int)(w)) logw++;\n\
    \        sizew = 1 << logw;\n        d = std::vector<std::vector<S>>(sizeh <<\
    \ 1, std::vector<S>(sizew << 1, MS::e()));\n        for (int i = 0; i < h; i++)\
    \ {\n            for (int j = 0; j < w; j++) {\n                d[i + sizeh][j\
    \ + sizew] = v[i][j];\n            }\n        }\n        for (int i = sizeh -\
    \ 1; i >= 1; i--) {\n            for (int j = sizew; j < (sizew << 1); j++) {\n\
    \                update_bottom(i, j);\n            }\n        }\n        for (int\
    \ i = 0; i < (sizeh << 1); i++) {\n            for (int j = sizew - 1; j >= 1;\
    \ j--) {\n                update_else(i, j);\n            }\n        }\n    }\n\
    \n    void set(int h, int w, const S& x) {\n        assert(0 <= h and h < h and\
    \ 0 <= w and w < w);\n        h += sizeh;\n        w += sizew;\n        d[h][w]\
    \ = x;\n        for (int i = 1; i <= logh; i++) update_bottom(h >> i, w);\n  \
    \      for (int i = 0; i <= logh; i++) {\n            for (int j = 1; j <= logw;\
    \ j++) {\n                update_else(h >> i, w >> j);\n            }\n      \
    \  }\n    }\n\n    void chset(int h, int w, const S& x) {\n        assert(0 <=\
    \ h and h < h and 0 <= w and w < w);\n        h += sizeh;\n        w += sizew;\n\
    \        d[h][w] = MS::op(d[h][w], x);\n        for (int i = 1; i <= logh; i++)\
    \ update_bottom(h >> i, w);\n        for (int i = 0; i <= logh; i++) {\n     \
    \       for (int j = 1; j <= logw; j++) {\n                update_else(h >> i,\
    \ w >> j);\n            }\n        }\n    }\n\n    S operator()(int h, int w)\
    \ const {\n        assert(0 <= h and h < h and 0 <= w and w < w);\n        return\
    \ d[h + sizeh][w + sizew];\n    }\n\n    S get(int h, int w) const {\n       \
    \ assert(0 <= h and h < h and 0 <= w and w < w);\n        return d[h + sizeh][w\
    \ + sizew];\n    }\n\n    S inner_prod(int h, int w1, int w2) {\n        S sml\
    \ = MS::e(), smr = MS::e();\n        while (w1 < w2) {\n            if (w1 & 1)\
    \ sml = MS::op(sml, d[h][w1++]);\n            if (w2 & 1) smr = MS::op(d[h][--w2],\
    \ smr);\n            w1 >>= 1;\n            w2 >>= 1;\n        }\n        return\
    \ MS::op(sml, smr);\n    }\n\n    S prod(int h1, int w1, int h2, int w2) {\n \
    \       assert(0 <= h1 and h1 <= h2 and h2 <= h);\n        assert(0 <= w1 and\
    \ w1 <= w2 and w2 <= w);\n        S sml = MS::e(), smr = MS::e();\n        h1\
    \ += sizeh;\n        h2 += sizeh;\n        w1 += sizew;\n        w2 += sizew;\n\
    \n        while (h1 < h2) {\n            if (h1 & 1) sml = MS::op(sml, inner_prod(h1++,\
    \ w1, w2));\n            if (h2 & 1) smr = MS::op(inner_prod(--h2, w1, w2), smr);\n\
    \            h1 >>= 1;\n            h2 >>= 1;\n        }\n        return MS::op(sml,\
    \ smr);\n    }\n\n    S all_prod() const { return d[1][1]; }\n\n    std::vector<std::vector<S>>\
    \ make_vector() {\n        std::vector vec(h, std::vector<S>(w));\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) vec[i][j]\
    \ = get(i, j);\n        }\n        return vec;\n    }\n\n   private:\n    int\
    \ h, logh, sizeh, w, logw, sizew;\n    std::vector<std::vector<S>> d;\n    inline\
    \ void update_bottom(int i, int j) { d[i][j] = MS::op(d[(i << 1) | 0][j], d[(i\
    \ << 1) | 1][j]); }\n    inline void update_else(int i, int j) { d[i][j] = MS::op(d[i][(j\
    \ << 1) | 0], d[i][(j << 1) | 1]); }\n};\n"
  code: "#pragma once\n\ntemplate <class MS> struct SegmentTree2D {\n   public:\n\
    \    using S = typename MS::S;\n    SegmentTree2D() : SegmentTree2D(0, 0) {}\n\
    \    SegmentTree2D(int h, int w) : SegmentTree2D(std::vector<std::vector<S>>(h,\
    \ std::vector<S>(w, MS::e()))) {}\n    SegmentTree2D(const std::vector<std::vector<S>>&\
    \ v) : h((int)(v.size())), w((int)(v[0].size())) {\n        logh = 0;\n      \
    \  while ((1U << logh) < (unsigned int)(h)) logh++;\n        sizeh = 1 << logh;\n\
    \        logw = 0;\n        while ((1U << logw) < (unsigned int)(w)) logw++;\n\
    \        sizew = 1 << logw;\n        d = std::vector<std::vector<S>>(sizeh <<\
    \ 1, std::vector<S>(sizew << 1, MS::e()));\n        for (int i = 0; i < h; i++)\
    \ {\n            for (int j = 0; j < w; j++) {\n                d[i + sizeh][j\
    \ + sizew] = v[i][j];\n            }\n        }\n        for (int i = sizeh -\
    \ 1; i >= 1; i--) {\n            for (int j = sizew; j < (sizew << 1); j++) {\n\
    \                update_bottom(i, j);\n            }\n        }\n        for (int\
    \ i = 0; i < (sizeh << 1); i++) {\n            for (int j = sizew - 1; j >= 1;\
    \ j--) {\n                update_else(i, j);\n            }\n        }\n    }\n\
    \n    void set(int h, int w, const S& x) {\n        assert(0 <= h and h < h and\
    \ 0 <= w and w < w);\n        h += sizeh;\n        w += sizew;\n        d[h][w]\
    \ = x;\n        for (int i = 1; i <= logh; i++) update_bottom(h >> i, w);\n  \
    \      for (int i = 0; i <= logh; i++) {\n            for (int j = 1; j <= logw;\
    \ j++) {\n                update_else(h >> i, w >> j);\n            }\n      \
    \  }\n    }\n\n    void chset(int h, int w, const S& x) {\n        assert(0 <=\
    \ h and h < h and 0 <= w and w < w);\n        h += sizeh;\n        w += sizew;\n\
    \        d[h][w] = MS::op(d[h][w], x);\n        for (int i = 1; i <= logh; i++)\
    \ update_bottom(h >> i, w);\n        for (int i = 0; i <= logh; i++) {\n     \
    \       for (int j = 1; j <= logw; j++) {\n                update_else(h >> i,\
    \ w >> j);\n            }\n        }\n    }\n\n    S operator()(int h, int w)\
    \ const {\n        assert(0 <= h and h < h and 0 <= w and w < w);\n        return\
    \ d[h + sizeh][w + sizew];\n    }\n\n    S get(int h, int w) const {\n       \
    \ assert(0 <= h and h < h and 0 <= w and w < w);\n        return d[h + sizeh][w\
    \ + sizew];\n    }\n\n    S inner_prod(int h, int w1, int w2) {\n        S sml\
    \ = MS::e(), smr = MS::e();\n        while (w1 < w2) {\n            if (w1 & 1)\
    \ sml = MS::op(sml, d[h][w1++]);\n            if (w2 & 1) smr = MS::op(d[h][--w2],\
    \ smr);\n            w1 >>= 1;\n            w2 >>= 1;\n        }\n        return\
    \ MS::op(sml, smr);\n    }\n\n    S prod(int h1, int w1, int h2, int w2) {\n \
    \       assert(0 <= h1 and h1 <= h2 and h2 <= h);\n        assert(0 <= w1 and\
    \ w1 <= w2 and w2 <= w);\n        S sml = MS::e(), smr = MS::e();\n        h1\
    \ += sizeh;\n        h2 += sizeh;\n        w1 += sizew;\n        w2 += sizew;\n\
    \n        while (h1 < h2) {\n            if (h1 & 1) sml = MS::op(sml, inner_prod(h1++,\
    \ w1, w2));\n            if (h2 & 1) smr = MS::op(inner_prod(--h2, w1, w2), smr);\n\
    \            h1 >>= 1;\n            h2 >>= 1;\n        }\n        return MS::op(sml,\
    \ smr);\n    }\n\n    S all_prod() const { return d[1][1]; }\n\n    std::vector<std::vector<S>>\
    \ make_vector() {\n        std::vector vec(h, std::vector<S>(w));\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) vec[i][j]\
    \ = get(i, j);\n        }\n        return vec;\n    }\n\n   private:\n    int\
    \ h, logh, sizeh, w, logw, sizew;\n    std::vector<std::vector<S>> d;\n    inline\
    \ void update_bottom(int i, int j) { d[i][j] = MS::op(d[(i << 1) | 0][j], d[(i\
    \ << 1) | 1][j]); }\n    inline void update_else(int i, int j) { d[i][j] = MS::op(d[i][(j\
    \ << 1) | 0], d[i][(j << 1) | 1]); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree_2d.hpp
  requiredBy: []
  timestamp: '2024-07-13 11:37:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_other/aoj_1068.test.cpp
documentation_of: data_structure/segment_tree_2d.hpp
layout: document
title: "2D Segment Tree (2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

基本的に `algebra/monoid_s` 以下のファイルをインクルードして使う

```cpp
// 1 点更新矩形和
#include "algebra/monoid_s/monoid_sum.hpp"
#include "data_structure/segment_tree_2d.hpp"
int main() {
    vector<vector<int>> A;
    SegmentTree2D<MonoidSum<int>> seg(A);
}
```

- `seg(h, w)` は `seg.get(h, w)` と同じ
- `seg.chset(h, w, x)` は `seg.set(h, w, op(seg.get(h, w), x))` と同じ (`seg.set(h, w, op(x, seg.get(h, w)))` ではない)
    - 計算量は $ O(\log H \log W) $
