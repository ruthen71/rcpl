---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_sum_affine.hpp
    title: algebra/lazy_sum_affine.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: "Lazy Segment Tree (\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: math/static_modint.hpp
    title: math/static_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/lc_data_structure/lc_range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <bits/stdc++.h>\n\n#line 2 \"algebra/lazy_sum_affine.hpp\"\n\n// https://atcoder.jp/contests/practice2/tasks/practice2_k\n\
    template <class T> struct LazySumAffine {\n    using S = std::pair<T, int>;\n\
    \    using F = std::pair<T, T>;  // a * x + b -> {a, b}\n    using value_type_S\
    \ = S;\n    using value_type_F = F;\n    static constexpr S op(S a, S b) { return\
    \ {a.first + b.first, a.second + b.second}; }\n    static constexpr S e() { return\
    \ {T(0), 0}; }\n    // f(x) = f.first * x + f.second, g(x) = g.first * x + g.second\n\
    \    // f(g(x)) = f.first * (g.first * x + g.second) + f.second\n    //      \
    \   = f.first * g.first * x + f.first * g.second + f.second\n    static constexpr\
    \ S mapping(F f, S x) { return {f.first * x.first + f.second * x.second, x.second};\
    \ }\n    static constexpr F composition(F f, F g) { return {f.first * g.first,\
    \ f.first * g.second + f.second}; }\n    static constexpr F id() { return {T(1),\
    \ T(0)}; }\n};\n#line 2 \"data_structure/lazy_segment_tree.hpp\"\n\ntemplate <class\
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
    \  lz[k] = Lazy::id();\n    }\n};\n#line 2 \"math/static_modint.hpp\"\n\ntemplate\
    \ <int m> struct StaticModint {\n    using mint = StaticModint;\n    unsigned\
    \ int _v;\n\n    static constexpr int mod() { return m; }\n    static constexpr\
    \ unsigned int umod() { return m; }\n\n    StaticModint() : _v(0) {}\n\n    template\
    \ <class T> StaticModint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n\n \
    \   unsigned int val() const { return _v; }\n\n    mint &operator++() {\n    \
    \    _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n    }\n\
    \    mint &operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint &operator+=(const mint &rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint\
    \ &operator-=(const mint &rhs) {\n        _v -= rhs._v;\n        if (_v >= umod())\
    \ _v += umod();\n        return *this;\n    }\n    mint &operator*=(const mint\
    \ &rhs) {\n        unsigned long long z = _v;\n        z *= rhs._v;\n        _v\
    \ = (unsigned int)(z % umod());\n        return *this;\n    }\n    mint &operator/=(const\
    \ mint &rhs) { return (*this *= rhs.inv()); }\n\n    mint operator+() const {\
    \ return *this; }\n    mint operator-() const { return mint() - *this; }\n\n \
    \   mint pow(long long n) const {\n        assert(n >= 0);\n        mint x = *this,\
    \ r = 1;\n        while (n) {\n            if (n & 1) r *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return r;\n    }\n\n    mint inv()\
    \ const { return pow(umod() - 2); }\n\n    friend mint operator+(const mint &lhs,\
    \ const mint &rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }\n};\n\
    using mint107 = StaticModint<1000000007>;\nusing mint998 = StaticModint<998244353>;\n\
    #line 8 \"verify/lc_data_structure/lc_range_affine_range_sum.test.cpp\"\nusing\
    \ mint = mint998;\n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n  \
    \  std::vector<std::pair<mint, int>> A(N);\n    for (int i = 0; i < N; i++) {\n\
    \        int a;\n        std::cin >> a;\n        A[i] = {mint(a), 1};\n    }\n\
    \    LazySegmentTree<LazySumAffine<mint>> seg(A);\n    while (Q--) {\n       \
    \ int t;\n        std::cin >> t;\n        if (t == 0) {\n            int l, r,\
    \ b, c;\n            std::cin >> l >> r >> b >> c;\n            seg.apply(l, r,\
    \ {b, c});\n        } else {\n            int l, r;\n            std::cin >> l\
    \ >> r;\n            std::cout << seg.prod(l, r).first.val() << '\\n';\n     \
    \   }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"algebra/lazy_sum_affine.hpp\"\n#include\
    \ \"data_structure/lazy_segment_tree.hpp\"\n#include \"math/static_modint.hpp\"\
    \nusing mint = mint998;\n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n\
    \    std::vector<std::pair<mint, int>> A(N);\n    for (int i = 0; i < N; i++)\
    \ {\n        int a;\n        std::cin >> a;\n        A[i] = {mint(a), 1};\n  \
    \  }\n    LazySegmentTree<LazySumAffine<mint>> seg(A);\n    while (Q--) {\n  \
    \      int t;\n        std::cin >> t;\n        if (t == 0) {\n            int\
    \ l, r, b, c;\n            std::cin >> l >> r >> b >> c;\n            seg.apply(l,\
    \ r, {b, c});\n        } else {\n            int l, r;\n            std::cin >>\
    \ l >> r;\n            std::cout << seg.prod(l, r).first.val() << '\\n';\n   \
    \     }\n    }\n    return 0;\n}\n"
  dependsOn:
  - algebra/lazy_sum_affine.hpp
  - data_structure/lazy_segment_tree.hpp
  - math/static_modint.hpp
  isVerificationFile: true
  path: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-11 16:01:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
- /verify/verify/lc_data_structure/lc_range_affine_range_sum.test.cpp.html
title: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
---
