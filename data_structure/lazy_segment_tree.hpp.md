---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/lazy_segment_tree.hpp\"\n\ntemplate <class\
    \ Lazy> struct LazySegmentTree {\n   public:\n    using S = typename Lazy::value_type_S;\n\
    \    using F = typename Lazy::value_type_F;\n    LazySegmentTree(int n) : LazySegmentTree(std::vector<S>(n,\
    \ Lazy::e())) {}\n    LazySegmentTree(const std::vector<S>& v) : _n((int)v.size())\
    \ {\n        log = 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n\
    \        size = 1 << log;\n        d = std::vector<S>(size << 1, Lazy::e());\n\
    \        lz = std::vector<F>(size, Lazy::id());\n        for (int i = 0; i < _n;\
    \ i++) d[i + size] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n  \
    \          update(i);\n        }\n    }\n\n    void set(int p, const S& x) {\n\
    \        assert(0 <= p and p < _n);\n        p += size;\n        for (int i =\
    \ log; i >= 1; i--) push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\
    \n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);  //\
    \ \u4E0B\u304B\u3089\u4E0A\u306B\u66F4\u65B0\n    }\n\n    void chset(int p, const\
    \ S& x) {\n        assert(0 <= p and p < _n);\n        p += size;\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\
    \u642C\n        d[p] = Lazy::op(d[p], x);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);  // \u4E0B\u304B\u3089\u4E0A\u306B\u66F4\u65B0\n    }\n\n  \
    \  S operator[](int p) {\n        assert(0 <= p and p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\
    \u3078\u4F1D\u642C\n        return d[p];\n    }\n\n    S get(int p) {\n      \
    \  assert(0 <= p and p < _n);\n        p += size;\n        for (int i = log; i\
    \ >= 1; i--) push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\n  \
    \      return d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <=\
    \ l and l <= r and r <= _n);\n        if (l == r) return Lazy::e();\n\n      \
    \  l += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--) {\n\
    \            if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n        }\n\n        S sml = Lazy::e(), smr\
    \ = Lazy::e();\n        while (l < r) {\n            if (l & 1) sml = Lazy::op(sml,\
    \ d[l++]);\n            if (r & 1) smr = Lazy::op(d[--r], smr);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n        return Lazy::op(sml, smr);\n\
    \    }\n\n    S all_prod() { return d[1]; }\n\n    void apply(int p, const F&\
    \ f) {\n        assert(0 <= p and p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        d[p] = Lazy::mapping(f, d[p]);\n\
    \        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void apply(int\
    \ l, int r, const F& f) {\n        assert(0 <= l and l <= r and r <= _n);\n  \
    \      if (l == r) return;\n\n        l += size;\n        r += size;\n\n     \
    \   for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        {\n            int l2 = l, r2 = r;\n            while (l < r) {\n  \
    \              if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i\
    \ <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n    \
    \        if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n\
    \    template <class G> int max_right(int l, G& g) {\n        assert(0 <= l &&\
    \ l <= _n);\n        assert(g(Lazy::e()));\n        if (l == _n) return _n;\n\
    \        l += size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n  \
    \      S sm = Lazy::e();\n        do {\n            while ((l & 1) == 0) l >>=\
    \ 1;\n            if (!g(Lazy::op(sm, d[l]))) {\n                while (l < size)\
    \ {\n                    push(l);\n                    l <<= 1;\n            \
    \        if (g(Lazy::op(sm, d[l]))) {\n                        sm = Lazy::op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = Lazy::op(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);  // 2\u3079\u304D\
    \u307E\u305F\u306F0\u306E\u3068\u304Dfalse\n        return _n;\n    }\n\n    template\
    \ <class G> int min_left(int r, G& g) {\n        assert(0 <= r && r <= _n);\n\
    \        assert(g(Lazy::e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = Lazy::e();\n\
    \        do {\n            r--;\n            while (r > 1 && (r & 1)) r >>= 1;\n\
    \            if (!g(Lazy::op(d[r], sm))) {\n                while (r < size) {\n\
    \                    push(r);\n                    r = (r << 1) | 1;\n       \
    \             if (g(Lazy::op(d[r], sm))) {\n                        sm = Lazy::op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = Lazy::op(d[r],\
    \ sm);\n        } while ((r & -r) != r);  // 2\u3079\u304D\u307E\u305F\u306F0\u306E\
    \u3068\u304Dfalse\n        return 0;\n    }\n\n   private:\n    int _n, log, size;\n\
    \    std::vector<S> d;\n    std::vector<F> lz;\n    inline void update(int k)\
    \ { d[k] = Lazy::op(d[k << 1], d[(k << 1) | 1]); }\n    void all_apply(int k,\
    \ const F& f) {\n        d[k] = Lazy::mapping(f, d[k]);\n        if (k < size)\
    \ lz[k] = Lazy::composition(f, lz[k]);\n    }\n    void push(int k) {\n      \
    \  all_apply(k << 1, lz[k]);\n        all_apply((k << 1) | 1, lz[k]);\n      \
    \  lz[k] = Lazy::id();\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class Lazy> struct LazySegmentTree {\n   public:\n\
    \    using S = typename Lazy::value_type_S;\n    using F = typename Lazy::value_type_F;\n\
    \    LazySegmentTree(int n) : LazySegmentTree(std::vector<S>(n, Lazy::e())) {}\n\
    \    LazySegmentTree(const std::vector<S>& v) : _n((int)v.size()) {\n        log\
    \ = 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n        size\
    \ = 1 << log;\n        d = std::vector<S>(size << 1, Lazy::e());\n        lz =\
    \ std::vector<F>(size, Lazy::id());\n        for (int i = 0; i < _n; i++) d[i\
    \ + size] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n           \
    \ update(i);\n        }\n    }\n\n    void set(int p, const S& x) {\n        assert(0\
    \ <= p and p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\n        d[p] =\
    \ x;\n        for (int i = 1; i <= log; i++) update(p >> i);  // \u4E0B\u304B\u3089\
    \u4E0A\u306B\u66F4\u65B0\n    }\n\n    void chset(int p, const S& x) {\n     \
    \   assert(0 <= p and p < _n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\n\
    \        d[p] = Lazy::op(d[p], x);\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);  // \u4E0B\u304B\u3089\u4E0A\u306B\u66F4\u65B0\n    }\n\n    S operator[](int\
    \ p) {\n        assert(0 <= p and p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\
    \u642C\n        return d[p];\n    }\n\n    S get(int p) {\n        assert(0 <=\
    \ p and p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);  // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\n        return d[p];\n\
    \    }\n\n    S prod(int l, int r) {\n        assert(0 <= l and l <= r and r <=\
    \ _n);\n        if (l == r) return Lazy::e();\n\n        l += size;\n        r\
    \ += size;\n\n        for (int i = log; i >= 1; i--) {\n            if (((l >>\
    \ i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n\n        S sml = Lazy::e(), smr = Lazy::e();\n    \
    \    while (l < r) {\n            if (l & 1) sml = Lazy::op(sml, d[l++]);\n  \
    \          if (r & 1) smr = Lazy::op(d[--r], smr);\n            l >>= 1;\n   \
    \         r >>= 1;\n        }\n        return Lazy::op(sml, smr);\n    }\n\n \
    \   S all_prod() { return d[1]; }\n\n    void apply(int p, const F& f) {\n   \
    \     assert(0 <= p and p < _n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = Lazy::mapping(f, d[p]);\n       \
    \ for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void apply(int\
    \ l, int r, const F& f) {\n        assert(0 <= l and l <= r and r <= _n);\n  \
    \      if (l == r) return;\n\n        l += size;\n        r += size;\n\n     \
    \   for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        {\n            int l2 = l, r2 = r;\n            while (l < r) {\n  \
    \              if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i\
    \ <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n    \
    \        if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n\
    \    template <class G> int max_right(int l, G& g) {\n        assert(0 <= l &&\
    \ l <= _n);\n        assert(g(Lazy::e()));\n        if (l == _n) return _n;\n\
    \        l += size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n  \
    \      S sm = Lazy::e();\n        do {\n            while ((l & 1) == 0) l >>=\
    \ 1;\n            if (!g(Lazy::op(sm, d[l]))) {\n                while (l < size)\
    \ {\n                    push(l);\n                    l <<= 1;\n            \
    \        if (g(Lazy::op(sm, d[l]))) {\n                        sm = Lazy::op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = Lazy::op(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);  // 2\u3079\u304D\
    \u307E\u305F\u306F0\u306E\u3068\u304Dfalse\n        return _n;\n    }\n\n    template\
    \ <class G> int min_left(int r, G& g) {\n        assert(0 <= r && r <= _n);\n\
    \        assert(g(Lazy::e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = Lazy::e();\n\
    \        do {\n            r--;\n            while (r > 1 && (r & 1)) r >>= 1;\n\
    \            if (!g(Lazy::op(d[r], sm))) {\n                while (r < size) {\n\
    \                    push(r);\n                    r = (r << 1) | 1;\n       \
    \             if (g(Lazy::op(d[r], sm))) {\n                        sm = Lazy::op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = Lazy::op(d[r],\
    \ sm);\n        } while ((r & -r) != r);  // 2\u3079\u304D\u307E\u305F\u306F0\u306E\
    \u3068\u304Dfalse\n        return 0;\n    }\n\n   private:\n    int _n, log, size;\n\
    \    std::vector<S> d;\n    std::vector<F> lz;\n    inline void update(int k)\
    \ { d[k] = Lazy::op(d[k << 1], d[(k << 1) | 1]); }\n    void all_apply(int k,\
    \ const F& f) {\n        d[k] = Lazy::mapping(f, d[k]);\n        if (k < size)\
    \ lz[k] = Lazy::composition(f, lz[k]);\n    }\n    void push(int k) {\n      \
    \  all_apply(k << 1, lz[k]);\n        all_apply((k << 1) | 1, lz[k]);\n      \
    \  lz[k] = Lazy::id();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
documentation_of: data_structure/lazy_segment_tree.hpp
layout: document
title: "Lazy Segment Tree (\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

基本は `ac-library` と同じ。

- 非再帰
- 2冪
- 抽象化済
- 外部 `0-indexed` 、内部 `1-indexed`


工夫点は以下。

- 毎回モノイドを書くのはめんどくさい、ということで、モノイド構造体をインクルードすれば済むようになっている
    - `#include "algebra/lazy_min_set.hpp"` などでインクルードできる
    - `lazy_segment_tree<lazy_min_set<int>> seg(n);` などで RMQ and RUQ が使える
- `ac-library` の `seg.get(i)` に相当する機能を `seg[i]` で実現している
- `seg[p] = op(seg[p], x)` とする `seg.chset(p, x)` を採用
    - `seg[p] = x` とするのは `seg.set(p, x)`
    - 案外 `seg.set(p, op(seg[p], x))` みたいなコードを書く機会は多いと思っている
    - 計算量は $ O(\log N) $
    - モノイドが可換でないなどの理由により、`op(seg[p], x)` と `op(x, seg[p])` の結果が異なる場合に注意
- マクロ不使用
    - 使いやすさを意識
- RSQ など区間長を別で持つ必要がある場合の初期化の方法は [ここ](https://ruthen71.github.io/rcpl/verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp) を参考にすること
    - 要するに `std::pair` の `first` に値を、`second` に区間長を入れる

## 謝辞

変数やメソッドの命名規則、メソッドの実装は [ac-library](https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp) を、モノイドの抽象化は [maspyさんのライブラリ](https://github.com/maspypy/library/blob/main/ds/segtree.hpp) および [ARMERIAさんのブログ](https://betrue12.hateblo.jp/entry/2020/09/23/005940) を参考にさせていただきました。ありがとうございます。

## 雑なメモ
- [maspyさんの解説記事](https://maspypy.com/segment-tree-%e3%81%ae%e3%81%8a%e5%8b%89%e5%bc%b72) と言葉遣いを合わせると、区間作用=apply(2引数)、伝搬=push、作用にhogeを追加=all_apply、再計算・更新=update、区間積=prod、1点更新=set
- `if (((l >> i) << i) != l)` みたいなやつは `push` では定数倍高速化なのか？(とりあえず消しても動いた)
- `update` では必要？
    - `apply` の途中の `all_apply` で書き換えた `d[i]` を、 `lz[i]` を下( `d[2*i]` と `d[2*i+1]` をはじめとする下層ノード) に伝播させて下の値が正しくなる前に書き換えてしまうからだと思う (多分)
- 上の議論は微妙で、そもそも `apply` や `prod` で見る可能性のあるノードに関する伝播や更新だけやっておけば良い、というだけの話な気がしてきた
    - 例えば $ N = 8 $ で `[0,6)` に区間作用させたいとき、ノード的には `d[2],lz[2],d[6],lz[6]` だけ触れば良い。よって伝播は `d[1]->d[2]&d[3], d[3]->d[6]&d[7]` ができれば良く、更新は `d[2]&d[3]->d[1], d[6]&d[7]->d[3]` だけできれば良い。
- 「初めて計算対象になるノード=奇数になるまで2で割り続けた後のノード」で、これより上のノード(=奇数を右シフトすることで得られるノード)で伝播や更新を行うと考えれば良い

