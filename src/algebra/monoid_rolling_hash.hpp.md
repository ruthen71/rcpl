---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modint261.hpp
    title: src/math/modint261.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash.hpp
    title: src/string/rolling_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/algebra/monoid_rolling_hash.md
    links: []
  bundledCode: "#line 2 \"src/algebra/monoid_rolling_hash.hpp\"\n\n#line 2 \"src/string/rolling_hash.hpp\"\
    \n\n#line 2 \"src/math/modint261.hpp\"\n\nstruct modint261 {\n    static constexpr\
    \ uint64_t m = (1ULL << 61) - 1;\n    using uint128_t = __uint128_t;\n    using\
    \ mint = modint261;\n    uint64_t _v;\n\n    static constexpr uint64_t mod() {\
    \ return m; }\n\n    modint261() : _v(0ULL) {}\n\n    template <class T> modint261(T\
    \ v) {\n        long long x = (long long)(v % (long long)mod());\n        if (x\
    \ < 0) x += mod();\n        _v = x;\n    }\n\n    uint64_t val() const { return\
    \ _v; }\n\n    mint &operator++() {\n        _v++;\n        if (_v == mod()) _v\
    \ = 0;\n        return *this;\n    }\n    mint &operator--() {\n        if (_v\
    \ == 0) _v = mod();\n        _v--;\n        return *this;\n    }\n\n    mint &operator+=(const\
    \ mint &rhs) {\n        _v += rhs._v;\n        if (_v >= mod()) _v -= mod();\n\
    \        return *this;\n    }\n    mint &operator-=(const mint &rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= mod()) _v += mod();\n        return *this;\n\
    \    }\n    mint &operator*=(const mint &rhs) {\n        uint128_t z = _v;\n \
    \       z *= rhs._v;\n        z = (z >> 61) + (z & mod());\n        if (z >= mod())\
    \ z -= mod();\n        _v = (uint64_t)z;\n        return *this;\n    }\n\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(n >= 0);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n\n    friend mint operator+(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }\n    friend bool operator==(const\
    \ mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n};\n\n/**\n * @docs\
    \ docs/math/modint261.md\n */\n#line 4 \"src/string/rolling_hash.hpp\"\n\ntemplate\
    \ <class Mint> struct rolling_hash {\n    std::vector<Mint> pwr;\n    const Mint\
    \ base;\n\n    static inline Mint generate_base() {\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);\n \
    \       return Mint(rand(mt));\n    }\n\n    void extend() {\n        int n =\
    \ pwr.size();\n        int m = n * 2;\n        pwr.resize(m);\n        for (int\
    \ i = n; i < m; i++) pwr[i] = pwr[i - 1] * base;\n    }\n\n    rolling_hash(int\
    \ N = 0, Mint base = generate_base()) : base(base) {\n        pwr.resize(1, Mint(1));\n\
    \        while (N >= (int)pwr.size()) extend();\n    }\n\n    Mint power(int i)\
    \ {  // return base ^ i\n        assert(i >= 0);\n        while (i >= (int)pwr.size())\
    \ extend();\n        return pwr[i];\n    }\n\n    std::vector<Mint> build(const\
    \ std::string &s) const {\n        int N = (int)s.size();\n        std::vector<Mint>\
    \ res(N + 1);\n        for (int i = 0; i < N; i++) {\n            res[i + 1] =\
    \ res[i] * base + s[i];\n        }\n        return res;\n    }\n\n    template\
    \ <class T> std::vector<Mint> build(const std::vector<T> &s) const {\n       \
    \ int N = (int)s.size();\n        std::vector<Mint> res(N + 1);\n        for (int\
    \ i = 0; i < N; i++) {\n            res[i + 1] = res[i] * base + s[i];\n     \
    \   }\n        return res;\n    }\n\n    Mint prod(const std::vector<Mint> &hs,\
    \ int l, int r) {\n        assert(0 <= l and l <= r and r < hs.size());\n    \
    \    return hs[r] - hs[l] * power(r - l);\n    }\n\n    Mint combine(Mint h1,\
    \ Mint h2, int h2len) { return h1 * power(h2len) + h2; }\n};\n#line 4 \"src/algebra/monoid_rolling_hash.hpp\"\
    \n\nrolling_hash<modint261> rh;\n\ntemplate <class Mint> struct monoid_rolling_hash\
    \ {\n    using S = std::pair<Mint, int>;\n    using value_type = S;\n    static\
    \ constexpr S op(S a, S b) { return {rh.combine(a.first, b.first, b.second), a.second\
    \ + b.second}; }\n    static constexpr S e() { return {0, 0}; }\n};\n\n/**\n *\
    \ @docs docs/algebra/monoid_rolling_hash.md\n */\n"
  code: "#pragma once\n\n#include \"src/string/rolling_hash.hpp\"\n\nrolling_hash<modint261>\
    \ rh;\n\ntemplate <class Mint> struct monoid_rolling_hash {\n    using S = std::pair<Mint,\
    \ int>;\n    using value_type = S;\n    static constexpr S op(S a, S b) { return\
    \ {rh.combine(a.first, b.first, b.second), a.second + b.second}; }\n    static\
    \ constexpr S e() { return {0, 0}; }\n};\n\n/**\n * @docs docs/algebra/monoid_rolling_hash.md\n\
    \ */"
  dependsOn:
  - src/string/rolling_hash.hpp
  - src/math/modint261.hpp
  isVerificationFile: false
  path: src/algebra/monoid_rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-01-16 02:29:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/monoid_rolling_hash.hpp
layout: document
redirect_from:
- /library/src/algebra/monoid_rolling_hash.hpp
- /library/src/algebra/monoid_rolling_hash.hpp.html
title: src/algebra/monoid_rolling_hash.hpp
---
## 使用例

- [ABC285 F](https://atcoder.jp/contests/abc285/tasks/abc285_f)
- 2つ以上のmodを組み合わせるなら、include ではなくべた書きするしかない
    - が、基数が $ 2^{61} - 1 $ なので余程のことがなければ衝突しないと思われる