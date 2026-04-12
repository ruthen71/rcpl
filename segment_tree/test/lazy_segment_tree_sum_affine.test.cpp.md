---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_plus_affine.hpp
    title: algebra/acted_monoid/acted_monoid_plus_affine.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_affine.hpp
    title: algebra/monoid/monoid_affine.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.hpp
    title: Static Modint
  - icon: ':heavy_check_mark:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
  - icon: ':heavy_check_mark:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  - icon: ':heavy_check_mark:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  - icon: ':heavy_check_mark:'
    path: misc/topbit.hpp
    title: Topbit
  - icon: ':heavy_check_mark:'
    path: segment_tree/lazy_segment_tree.hpp
    title: "Lazy Segment Tree (\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
  bundledCode: "#line 1 \"segment_tree/test/lazy_segment_tree_sum_affine.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <iostream>\n\n#line 2 \"algebra/acted_monoid/acted_monoid_plus_affine.hpp\"\
    \n\n#line 2 \"algebra/monoid/monoid_affine.hpp\"\n\ntemplate <class T> struct\
    \ Affine {\n    T a;\n    T b;\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Affine& f) {\n        return os << f.a << \", \" << f.b;\n    }\n\
    };\n\ntemplate <class T> struct MonoidAffine {\n    using value_type = Affine<T>;\n\
    \    static constexpr value_type operation(const value_type& f,\n            \
    \                              const value_type& g) noexcept {\n        // f(x)\
    \ := ax + b, g(x) := cx + d\n        // g(f(x)) = c(ax + b) + d = cax + cb + d\n\
    \        return {g.a * f.a, g.a * f.b + g.b};\n    }\n    static constexpr value_type\
    \ identity() noexcept { return {T(1), T(0)}; }\n};\n#line 2 \"algebra/monoid/monoid_plus.hpp\"\
    \n\ntemplate <class T> struct MonoidPlus {\n    using value_type = T;\n    static\
    \ constexpr T operation(const T& a, const T& b) noexcept {\n        return a +\
    \ b;\n    }\n    static constexpr T identity() noexcept { return T(0); }\n   \
    \ static constexpr T inverse(const T& a) noexcept { return -a; }\n    static constexpr\
    \ bool commutative = true;\n};\n#line 5 \"algebra/acted_monoid/acted_monoid_plus_affine.hpp\"\
    \n\ntemplate <class T> struct ActedMonoidPlusAffine {\n    using MS = MonoidPlus<T>;\n\
    \    using MF = MonoidAffine<T>;\n    using S = typename MS::value_type;\n   \
    \ using F = typename MF::value_type;\n    static constexpr S mapping(const F f,\
    \ const S x, const int size) {\n        return f.a * x + f.b * T(size);\n    }\n\
    };\n#line 2 \"math/static_modint.hpp\"\n\n#include <utility>\n#include <cassert>\n\
    \n// constexpr ... for constexpr bool prime()\ntemplate <int m> struct StaticModint\
    \ {\n    using mint = StaticModint;\n    unsigned int _v;\n\n    static constexpr\
    \ int mod() { return m; }\n    static constexpr unsigned int umod() { return m;\
    \ }\n\n    constexpr StaticModint() : _v(0) {}\n\n    template <class T> constexpr\
    \ StaticModint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n\n \
    \   constexpr unsigned int val() const { return _v; }\n\n    constexpr mint &operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    constexpr mint &operator--() {\n        if (_v == 0) _v = umod();\n\
    \        _v--;\n        return *this;\n    }\n    constexpr mint operator++(int)\
    \ {\n        mint result = *this;\n        ++*this;\n        return result;\n\
    \    }\n    constexpr mint operator--(int) {\n        mint result = *this;\n \
    \       --*this;\n        return result;\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    constexpr mint &operator-=(const mint &rhs)\
    \ {\n        _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return\
    \ *this;\n    }\n    constexpr mint &operator*=(const mint &rhs) {\n        unsigned\
    \ long long z = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n\
    \        return *this;\n    }\n    constexpr mint &operator/=(const mint &rhs)\
    \ { return (*this *= rhs.inv()); }\n\n    constexpr mint operator+() const { return\
    \ *this; }\n    constexpr mint operator-() const { return mint() - *this; }\n\n\
    \    constexpr mint pow(long long n) const {\n        assert(n >= 0);\n      \
    \  mint x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *= x;\n\
    \            x *= x;\n            n >>= 1;\n        }\n        return r;\n   \
    \ }\n\n    constexpr mint inv() const {\n        if (prime) {\n            assert(_v);\n\
    \            return pow(umod() - 2);\n        } else {\n            auto eg =\
    \ inv_gcd(_v, m);\n            assert(eg.first == 1);\n            return eg.second;\n\
    \        }\n    }\n\n    friend constexpr mint operator+(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) += rhs; }\n    friend constexpr mint operator-(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }\n    friend constexpr\
    \ mint operator*(const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs;\
    \ }\n    friend constexpr mint operator/(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) /= rhs; }\n    friend constexpr bool operator==(const mint &lhs, const\
    \ mint &rhs) { return lhs._v == rhs._v; }\n    friend constexpr bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }\n\n \
    \   static constexpr bool prime = []() -> bool {\n        if (m == 1) return false;\n\
    \        if (m == 2 || m == 7 || m == 61) return true;\n        if (m % 2 == 0)\
    \ return false;\n        unsigned int d = m - 1;\n        while (d % 2 == 0) d\
    \ /= 2;\n        for (unsigned int a : {2, 7, 61}) {\n            unsigned int\
    \ t = d;\n            mint y = mint(a).pow(t);\n            while (t != m - 1\
    \ and y != 1 and y != m - 1) {\n                y *= y;\n                t <<=\
    \ 1;\n            }\n            if (y != m - 1 and t % 2 == 0) {\n          \
    \      return false;\n            }\n        }\n        return true;\n    }();\n\
    \    static constexpr std::pair<int, int> inv_gcd(int a, int b) {\n        if\
    \ (a == 0) return {b, 0};\n        int s = b, t = a, m0 = 0, m1 = 1;\n       \
    \ while (t) {\n            const int u = s / t;\n            s -= t * u;\n   \
    \         m0 -= m1 * u;\n            std::swap(s, t);\n            std::swap(m0,\
    \ m1);\n        }\n        if (m0 < 0) m0 += b / s;\n        return {s, m0};\n\
    \    }\n};\nusing mint107 = StaticModint<1000000007>;\nusing mint998 = StaticModint<998244353>;\n\
    #line 2 \"segment_tree/lazy_segment_tree.hpp\"\n\n#line 2 \"misc/bit_ceil.hpp\"\
    \n\n#line 4 \"misc/bit_ceil.hpp\"\n\n#if __cplusplus >= 202002L\n#include <bit>\n\
    #endif\n\n// bit_ceil\n// (0, 1, 2, 3, 4) -> (1, 1, 2, 4, 4)\n#if __cplusplus\
    \ >= 202002L\nusing std::bit_ceil;\n#else\nunsigned int bit_ceil(unsigned int\
    \ x) {\n    unsigned int p = 1;\n    while (p < x) p *= 2;\n    return p;\n}\n\
    unsigned long long int bit_ceil(unsigned long long int x) {\n    unsigned long\
    \ long int p = 1;\n    while (p < x) p *= 2;\n    return p;\n}\n#endif\nint bit_ceil(int\
    \ x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned int)(x));\n}\nlong\
    \ long int bit_ceil(long long int x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned\
    \ long long int)(x));\n}\n#line 2 \"misc/countr_zero.hpp\"\n\n#if __cplusplus\
    \ >= 202002L\n#include <bit>\n#endif\n\n// countr_zero\n// (000, 001, 010, 011,\
    \ 100) -> (32, 0, 1, 0, 2)\n#if __cplusplus >= 202002L\nusing std::countr_zero;\n\
    #else\nint countr_zero(unsigned int x) {\n    return x == 0 ? 32 : __builtin_ctz(x);\n\
    }\nint countr_zero(unsigned long long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n#endif\nint countr_zero(int x) { return countr_zero((unsigned int)(x)); }\n\
    int countr_zero(long long int x) {\n    return countr_zero((unsigned long long\
    \ int)(x));\n}\n#line 2 \"misc/topbit.hpp\"\n\n#line 2 \"misc/countl_zero.hpp\"\
    \n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n// countl_zero\n// (000,\
    \ 001, 010, 011, 100) -> (32, 31, 30, 30, 29)\n#if __cplusplus >= 202002L\nusing\
    \ std::countl_zero;\n#else\nint countl_zero(unsigned int x) {\n    return x ==\
    \ 0 ? 32 : __builtin_clz(x);\n}\nint countl_zero(unsigned long long int x) {\n\
    \    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#endif\nint countl_zero(int\
    \ x) { return countl_zero((unsigned int)(x)); }\nint countl_zero(long long int\
    \ x) {\n    return countl_zero((unsigned long long int)(x));\n}\n#line 4 \"misc/topbit.hpp\"\
    \n\n// topbit\n// (000, 001, 010, 011, 100) -> (-1, 0, 1, 1, 2)\nint topbit(int\
    \ x) { return 31 - countl_zero(x); }\nint topbit(unsigned int x) { return 31 -\
    \ countl_zero(x); }\nint topbit(long long int x) { return 63 - countl_zero(x);\
    \ }\nint topbit(unsigned long long int x) { return 63 - countl_zero(x); }\n#line\
    \ 6 \"segment_tree/lazy_segment_tree.hpp\"\n\n#line 8 \"segment_tree/lazy_segment_tree.hpp\"\
    \n#include <vector>\n\n// Lazy Segment Tree\ntemplate <class AM> struct LazySegmentTree\
    \ {\n  public:\n    using MS = typename AM::MS;\n    using MF = typename AM::MF;\n\
    \    using S = typename MS::value_type;\n    using F = typename MF::value_type;\n\
    \n    LazySegmentTree() = default;\n\n    explicit LazySegmentTree(int n)\n  \
    \      : LazySegmentTree(std::vector<S>(n, MS::identity())) {}\n\n    explicit\
    \ LazySegmentTree(const std::vector<S>& v) : n((int)(v.size())) {\n        size\
    \ = bit_ceil(n);\n        log = countr_zero(size);\n        d = std::vector<S>(size\
    \ << 1, MS::identity());\n        lz = std::vector<F>(size, MF::identity());\n\
    \        for (int i = 0; i < n; i++) d[i + size] = v[i];\n        for (int i =\
    \ size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void\
    \ set(int p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n   \
    \     for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void add(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n  \
    \      for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = MS::operation(d[p],\
    \ x);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ operator[](int p) {\n        assert(0 <= p and p < n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n\
    \    }\n\n    S get(int p) {\n        assert(0 <= p and p < n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        return\
    \ d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l and l <= r\
    \ and r <= n);\n        if (l == r) return MS::identity();\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        S sml = MS::identity(), smr = MS::identity();\n\
    \        while (l < r) {\n            if (l & 1) sml = MS::operation(sml, d[l++]);\n\
    \            if (r & 1) smr = MS::operation(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return MS::operation(sml, smr);\n  \
    \  }\n\n    S all_prod() { return d[1]; }\n\n    void apply(int p, const F& f)\
    \ {\n        assert(0 <= p and p < n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = AM::mapping(f, d[p], 1);\n\
    \        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void apply(int\
    \ l, int r, const F& f) {\n        assert(0 <= l and l <= r and r <= n);\n   \
    \     if (l == r) return;\n\n        l += size;\n        r += size;\n\n      \
    \  for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        {\n            int l2 = l, r2 = r;\n            while (l < r) {\n  \
    \              if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i\
    \ <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n    \
    \        if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n\
    \    template <class G> int max_right(int l, G& g) {\n        assert(0 <= l and\
    \ l <= n);\n        assert(g(MS::identity()));\n        if (l == n) return n;\n\
    \        l += size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n  \
    \      S sm = MS::identity();\n        do {\n            while ((l & 1) == 0)\
    \ l >>= 1;\n            if (!g(MS::operation(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    push(l);\n                    l <<= 1;\n \
    \                   if (g(MS::operation(sm, d[l]))) {\n                      \
    \  sm = MS::operation(sm, d[l]);\n                        l++;\n             \
    \       }\n                }\n                return l - size;\n            }\n\
    \            sm = MS::operation(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return n;\n    }\n\n    template <class G> int min_left(int\
    \ r, G& g) {\n        assert(0 <= r and r <= n);\n        assert(g(MS::identity()));\n\
    \        if (r == 0) return 0;\n        r += size;\n        for (int i = log;\
    \ i >= 1; i--) push((r - 1) >> i);\n        S sm = MS::identity();\n        do\
    \ {\n            r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n      \
    \      if (!g(MS::operation(d[r], sm))) {\n                while (r < size) {\n\
    \                    push(r);\n                    r = (r << 1) | 1;\n       \
    \             if (g(MS::operation(d[r], sm))) {\n                        sm =\
    \ MS::operation(d[r], sm);\n                        r--;\n                   \
    \ }\n                }\n                return r + 1 - size;\n            }\n\
    \            sm = MS::operation(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n    std::vector<S> make_vector() {\n        std::vector<S>\
    \ vec(n);\n        for (int i = 0; i < n; i++) vec[i] = get(i);\n        return\
    \ vec;\n    }\n\n  private:\n    int n, log, size;\n    std::vector<S> d;\n  \
    \  std::vector<F> lz;\n\n    inline void update(int k) {\n        d[k] = MS::operation(d[k\
    \ << 1], d[(k << 1) | 1]);\n    }\n\n    void all_apply(int k, const F& f) {\n\
    \        d[k] = AM::mapping(f, d[k], 1 << (log - topbit(k)));\n        // MF::operation(f,\
    \ g), g(f(x))\n        if (k < size) lz[k] = MF::operation(lz[k], f);\n    }\n\
    \n    void push(int k) {\n        all_apply(k << 1, lz[k]);\n        all_apply((k\
    \ << 1) | 1, lz[k]);\n        lz[k] = MF::identity();\n    }\n};\n#line 8 \"segment_tree/test/lazy_segment_tree_sum_affine.test.cpp\"\
    \nusing mint = mint998;\n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n\
    \    std::vector<mint> A(N);\n    for (int i = 0; i < N; i++) {\n        int a;\n\
    \        std::cin >> a;\n        A[i] = mint(a);\n    }\n    LazySegmentTree<ActedMonoidPlusAffine<mint>>\
    \ seg(A);\n    while (Q--) {\n        int t;\n        std::cin >> t;\n       \
    \ if (t == 0) {\n            int l, r, b, c;\n            std::cin >> l >> r >>\
    \ b >> c;\n            seg.apply(l, r, {mint(b), mint(c)});\n        } else {\n\
    \            int l, r;\n            std::cin >> l >> r;\n            std::cout\
    \ << seg.prod(l, r).val() << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n\n#include \"../../algebra/acted_monoid/acted_monoid_plus_affine.hpp\"\
    \n#include \"../../math/static_modint.hpp\"\n#include \"../../segment_tree/lazy_segment_tree.hpp\"\
    \nusing mint = mint998;\n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n\
    \    std::vector<mint> A(N);\n    for (int i = 0; i < N; i++) {\n        int a;\n\
    \        std::cin >> a;\n        A[i] = mint(a);\n    }\n    LazySegmentTree<ActedMonoidPlusAffine<mint>>\
    \ seg(A);\n    while (Q--) {\n        int t;\n        std::cin >> t;\n       \
    \ if (t == 0) {\n            int l, r, b, c;\n            std::cin >> l >> r >>\
    \ b >> c;\n            seg.apply(l, r, {mint(b), mint(c)});\n        } else {\n\
    \            int l, r;\n            std::cin >> l >> r;\n            std::cout\
    \ << seg.prod(l, r).val() << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - algebra/acted_monoid/acted_monoid_plus_affine.hpp
  - algebra/monoid/monoid_affine.hpp
  - algebra/monoid/monoid_plus.hpp
  - math/static_modint.hpp
  - segment_tree/lazy_segment_tree.hpp
  - misc/bit_ceil.hpp
  - misc/countr_zero.hpp
  - misc/topbit.hpp
  - misc/countl_zero.hpp
  isVerificationFile: true
  path: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
- /verify/segment_tree/test/lazy_segment_tree_sum_affine.test.cpp.html
title: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
---
