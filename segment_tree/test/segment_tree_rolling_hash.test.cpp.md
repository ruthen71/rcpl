---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_rolling_hash.hpp
    title: monoid_rolling_hash
  - icon: ':heavy_check_mark:'
    path: math/modint261.hpp
    title: Modint $\pmod{2^{61}-1} $
  - icon: ':heavy_check_mark:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
  - icon: ':heavy_check_mark:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"segment_tree/test/segment_tree_rolling_hash.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#line 2 \"algebra/monoid/monoid_rolling_hash.hpp\"\n\n#include <chrono>\n#include\
    \ <cstdint>\n#include <random>\n#include <utility>\n\ntemplate <class Mint> struct\
    \ Hash {\n    // {hash(s), base ^ len(s)}\n    Mint hash;\n    Mint power;\n \
    \   friend std::ostream& operator<<(std::ostream& os, const Hash& v) {\n     \
    \   return os << v.hash << \", \" << v.power;\n    }\n};\n\ntemplate <class Mint>\
    \ struct MonoidRollingHash {\n    using value_type = Hash<Mint>;\n\n    static\
    \ Mint base;\n\n    static void set_base(Mint b = Mint(0)) {\n        if (b ==\
    \ Mint(0)) {\n            std::mt19937_64 mt(\n                std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \            std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);\n\
    \            base = Mint(rand(mt));\n        } else {\n            base = b;\n\
    \        }\n    }\n\n    static constexpr value_type make_element(Mint x) { return\
    \ {x, base}; }\n\n    static constexpr value_type operation(const value_type&\
    \ a,\n                                          const value_type& b) {\n     \
    \   return {a.hash * b.power + b.hash, a.power * b.power};\n    }\n    static\
    \ constexpr value_type identity() {\n        // {hash(\"\"), base ^ len(\"\")}\n\
    \        return {Mint(0), Mint(1)};\n    }\n\n    static constexpr bool commutative\
    \ = false;\n};\n#line 2 \"segment_tree/segment_tree.hpp\"\n\n#line 2 \"misc/bit_ceil.hpp\"\
    \n\n#include <cassert>\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\
    \n// bit_ceil\n// (0, 1, 2, 3, 4) -> (1, 1, 2, 4, 4)\n#if __cplusplus >= 202002L\n\
    using std::bit_ceil;\n#else\nunsigned int bit_ceil(unsigned int x) {\n    unsigned\
    \ int p = 1;\n    while (p < x) p *= 2;\n    return p;\n}\nunsigned long long\
    \ int bit_ceil(unsigned long long int x) {\n    unsigned long long int p = 1;\n\
    \    while (p < x) p *= 2;\n    return p;\n}\n#endif\nint bit_ceil(int x) {\n\
    \    assert(x >= 0);\n    return bit_ceil((unsigned int)(x));\n}\nlong long int\
    \ bit_ceil(long long int x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned\
    \ long long int)(x));\n}\n#line 2 \"misc/countr_zero.hpp\"\n\n#if __cplusplus\
    \ >= 202002L\n#include <bit>\n#endif\n\n// countr_zero\n// (000, 001, 010, 011,\
    \ 100) -> (32, 0, 1, 0, 2)\n#if __cplusplus >= 202002L\nusing std::countr_zero;\n\
    #else\nint countr_zero(unsigned int x) {\n    return x == 0 ? 32 : __builtin_ctz(x);\n\
    }\nint countr_zero(unsigned long long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n#endif\nint countr_zero(int x) { return countr_zero((unsigned int)(x)); }\n\
    int countr_zero(long long int x) {\n    return countr_zero((unsigned long long\
    \ int)(x));\n}\n#line 5 \"segment_tree/segment_tree.hpp\"\n\n#line 7 \"segment_tree/segment_tree.hpp\"\
    \n#include <vector>\n\n// Segment Tree\ntemplate <class MS> struct SegmentTree\
    \ {\n  public:\n    using S = typename MS::value_type;\n\n    SegmentTree() =\
    \ default;\n\n    explicit SegmentTree(int n)\n        : SegmentTree(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit SegmentTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        size = bit_ceil(n);\n        log = countr_zero(size);\n        d\
    \ = std::vector<S>(size << 1, MS::identity());\n        for (int i = 0; i < n;\
    \ i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n  \
    \          update(i);\n        }\n    }\n\n    void set(int p, const S& x) {\n\
    \        assert(0 <= p and p < n);\n        p += size;\n        d[p] = x;\n  \
    \      for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void add(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n  \
    \      d[p] = MS::operation(d[p], x);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S operator[](int p) const {\n        assert(0\
    \ <= p and p < n);\n        return d[p + size];\n    }\n\n    S get(int p) const\
    \ {\n        assert(0 <= p && p < n);\n        return d[p + size];\n    }\n\n\
    \    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        S sml = MS::identity(), smr = MS::identity();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = MS::operation(sml,\
    \ d[l++]);\n            if (r & 1) smr = MS::operation(d[--r], smr);\n       \
    \     l >>= 1;\n            r >>= 1;\n        }\n        return MS::operation(sml,\
    \ smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template <class\
    \ G> int max_right(int l, G& g) const {\n        assert(0 <= l and l <= n);\n\
    \        assert(g(MS::identity()));\n        if (l == n) return n;\n        l\
    \ += size;\n        S sm = MS::identity();\n        do {\n            while ((l\
    \ & 1) == 0) l >>= 1;\n            if (!g(MS::operation(sm, d[l]))) {\n      \
    \          while (l < size) {\n                    l <<= 1;\n                \
    \    if (g(MS::operation(sm, d[l]))) {\n                        sm = MS::operation(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = MS::operation(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);\n        return n;\n\
    \    }\n\n    template <class G> int min_left(int r, G& g) const {\n        assert(0\
    \ <= r and r <= n);\n        assert(g(MS::identity()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        S sm = MS::identity();\n        do {\n     \
    \       r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n            if (!g(MS::operation(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (r << 1)\
    \ | 1;\n                    if (g(MS::operation(d[r], sm))) {\n              \
    \          sm = MS::operation(d[r], sm);\n                        r--;\n     \
    \               }\n                }\n                return r + 1 - size;\n \
    \           }\n            sm = MS::operation(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n    std::vector<S> make_vector() {\n\
    \        std::vector<S> vec(n);\n        for (int i = 0; i < n; i++) vec[i] =\
    \ get(i);\n        return vec;\n    }\n\n  private:\n    int n, log, size;\n \
    \   std::vector<S> d;\n\n    inline void update(int k) {\n        d[k] = MS::operation(d[k\
    \ << 1], d[(k << 1) | 1]);\n    }\n};\n#line 2 \"math/modint261.hpp\"\n\n#line\
    \ 4 \"math/modint261.hpp\"\n\nstruct Modint261 {\n    static constexpr unsigned\
    \ long long m = (1ULL << 61) - 1;\n    using mint = Modint261;\n    unsigned long\
    \ long _v;\n\n    static constexpr long long mod() { return m; }\n    static constexpr\
    \ unsigned long long umod() { return m; }\n\n    Modint261() : _v(0ULL) {}\n\n\
    \    template <class T> Modint261(T v) {\n        long long x = (long long)(v\
    \ % (long long)(umod()));\n        if (x < 0) x += umod();\n        _v = (unsigned\
    \ long long)(x);\n    }\n\n    unsigned long long val() const { return _v; }\n\
    \n    mint &operator++() {\n        _v++;\n        if (_v == umod()) _v = 0;\n\
    \        return *this;\n    }\n    mint &operator--() {\n        if (_v == 0)\
    \ _v = umod();\n        _v--;\n        return *this;\n    }\n    mint operator++(int)\
    \ {\n        mint result = *this;\n        ++*this;\n        return result;\n\
    \    }\n    mint operator--(int) {\n        mint result = *this;\n        --*this;\n\
    \        return result;\n    }\n\n    mint &operator+=(const mint &rhs) {\n  \
    \      _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    mint &operator-=(const mint &rhs) {\n        _v -= rhs._v;\n\
    \        if (_v >= umod()) _v += umod();\n        return *this;\n    }\n    mint\
    \ &operator*=(const mint &rhs) {\n        __uint128_t z = _v;\n        z *= rhs._v;\n\
    \        z = (z >> 61) + (z & umod());\n        if (z >= umod()) z -= umod();\n\
    \        _v = (unsigned long long)z;\n        return *this;\n    }\n    mint &operator/=(const\
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
    using mint261 = Modint261;\n#line 8 \"segment_tree/test/segment_tree_rolling_hash.test.cpp\"\
    \n\nusing mint = mint261;\nusing mrh = MonoidRollingHash<mint>;\ntemplate <> mint\
    \ mrh::base = 0;\n\nvoid test1_basic() {\n    assert(mrh::commutative == false);\n\
    \    assert(mrh::identity().hash == mint(0));\n    assert(mrh::identity().power\
    \ == mint(1));\n}\n\nvoid test2_sequence() {\n    mint B = mrh::base;\n\n    std::vector<Hash<mint>>\
    \ a = {\n        mrh::make_element(mint(3)),\n        mrh::make_element(mint(1)),\n\
    \        mrh::make_element(mint(4)),\n    };\n    SegmentTree<mrh> seg(a);\n\n\
    \    assert(seg.prod(0, 0).hash == mint(0));\n    assert(seg.prod(0, 0).power\
    \ == mint(1));\n\n    assert(seg.prod(0, 1).hash == mint(3));\n    assert(seg.prod(0,\
    \ 1).power == B);\n\n    assert(seg.prod(0, 2).hash == mint(3) * B + mint(1));\n\
    \    assert(seg.prod(0, 2).power == B * B);\n\n    assert(seg.prod(0, 3).hash\
    \ == mint(3) * B * B + mint(1) * B + mint(4));\n    assert(seg.prod(0, 3).power\
    \ == B * B * B);\n\n    assert(seg.prod(1, 3).hash == mint(1) * B + mint(4));\n\
    \    assert(seg.prod(1, 3).power == B * B);\n}\n\nint main() {\n    mrh::set_base(mint(100));\n\
    \    test1_basic();\n    test2_sequence();\n    int a, b;\n    std::cin >> a >>\
    \ b;\n    std::cout << a + b << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#include \"../../algebra/monoid/monoid_rolling_hash.hpp\"\n#include \"../../segment_tree/segment_tree.hpp\"\
    \n#include \"../../math/modint261.hpp\"\n\nusing mint = mint261;\nusing mrh =\
    \ MonoidRollingHash<mint>;\ntemplate <> mint mrh::base = 0;\n\nvoid test1_basic()\
    \ {\n    assert(mrh::commutative == false);\n    assert(mrh::identity().hash ==\
    \ mint(0));\n    assert(mrh::identity().power == mint(1));\n}\n\nvoid test2_sequence()\
    \ {\n    mint B = mrh::base;\n\n    std::vector<Hash<mint>> a = {\n        mrh::make_element(mint(3)),\n\
    \        mrh::make_element(mint(1)),\n        mrh::make_element(mint(4)),\n  \
    \  };\n    SegmentTree<mrh> seg(a);\n\n    assert(seg.prod(0, 0).hash == mint(0));\n\
    \    assert(seg.prod(0, 0).power == mint(1));\n\n    assert(seg.prod(0, 1).hash\
    \ == mint(3));\n    assert(seg.prod(0, 1).power == B);\n\n    assert(seg.prod(0,\
    \ 2).hash == mint(3) * B + mint(1));\n    assert(seg.prod(0, 2).power == B * B);\n\
    \n    assert(seg.prod(0, 3).hash == mint(3) * B * B + mint(1) * B + mint(4));\n\
    \    assert(seg.prod(0, 3).power == B * B * B);\n\n    assert(seg.prod(1, 3).hash\
    \ == mint(1) * B + mint(4));\n    assert(seg.prod(1, 3).power == B * B);\n}\n\n\
    int main() {\n    mrh::set_base(mint(100));\n    test1_basic();\n    test2_sequence();\n\
    \    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n  \
    \  return 0;\n}\n"
  dependsOn:
  - algebra/monoid/monoid_rolling_hash.hpp
  - segment_tree/segment_tree.hpp
  - misc/bit_ceil.hpp
  - misc/countr_zero.hpp
  - math/modint261.hpp
  isVerificationFile: true
  path: segment_tree/test/segment_tree_rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/segment_tree_rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/segment_tree_rolling_hash.test.cpp
- /verify/segment_tree/test/segment_tree_rolling_hash.test.cpp.html
title: segment_tree/test/segment_tree_rolling_hash.test.cpp
---
