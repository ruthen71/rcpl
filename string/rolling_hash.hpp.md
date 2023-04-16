---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint261.hpp
    title: ModInt $\pmod{2^{61}-1} $
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_alds1/aoj_alds1_14_b.test.cpp
    title: verify/aoj_alds1/aoj_alds1_14_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n\n#line 2 \"math/modint261.hpp\"\
    \n\nstruct ModInt261 {\n    static constexpr uint64_t m = (1ULL << 61) - 1;\n\
    \    using uint128_t = __uint128_t;\n    using mint = ModInt261;\n    uint64_t\
    \ _v;\n\n    static constexpr uint64_t mod() { return m; }\n\n    ModInt261()\
    \ : _v(0ULL) {}\n\n    template <class T> ModInt261(T v) {\n        long long\
    \ x = (long long)(v % (long long)mod());\n        if (x < 0) x += mod();\n   \
    \     _v = x;\n    }\n\n    uint64_t val() const { return _v; }\n\n    mint &operator++()\
    \ {\n        _v++;\n        if (_v == mod()) _v = 0;\n        return *this;\n\
    \    }\n    mint &operator--() {\n        if (_v == 0) _v = mod();\n        _v--;\n\
    \        return *this;\n    }\n\n    mint &operator+=(const mint &rhs) {\n   \
    \     _v += rhs._v;\n        if (_v >= mod()) _v -= mod();\n        return *this;\n\
    \    }\n    mint &operator-=(const mint &rhs) {\n        _v -= rhs._v;\n     \
    \   if (_v >= mod()) _v += mod();\n        return *this;\n    }\n    mint &operator*=(const\
    \ mint &rhs) {\n        uint128_t z = _v;\n        z *= rhs._v;\n        z = (z\
    \ >> 61) + (z & mod());\n        if (z >= mod()) z -= mod();\n        _v = (uint64_t)z;\n\
    \        return *this;\n    }\n\n    mint operator-() const { return mint() -\
    \ *this; }\n\n    mint pow(long long n) const {\n        assert(n >= 0);\n   \
    \     mint x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *=\
    \ x;\n            x *= x;\n            n >>= 1;\n        }\n        return r;\n\
    \    }\n\n    friend mint operator+(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) += rhs; }\n    friend mint operator-(const mint &lhs, const mint &rhs)\
    \ { return mint(lhs) -= rhs; }\n    friend mint operator*(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) *= rhs; }\n    friend bool operator==(const mint\
    \ &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n};\n#line 4 \"string/rolling_hash.hpp\"\
    \n\ntemplate <class Mint> struct RollingHash {\n    std::vector<Mint> pwr;\n \
    \   const Mint base;\n\n    static inline Mint generate_base() {\n        std::mt19937_64\
    \ mt(std::chrono::steady_clock::now().time_since_epoch().count());\n        std::uniform_int_distribution<uint64_t>\
    \ rand(1, Mint::mod() - 1);\n        return Mint(rand(mt));\n    }\n\n    void\
    \ extend() {\n        int n = pwr.size();\n        int m = n * 2;\n        pwr.resize(m);\n\
    \        for (int i = n; i < m; i++) pwr[i] = pwr[i - 1] * base;\n    }\n\n  \
    \  RollingHash(int N = 0, Mint base = generate_base()) : base(base) {\n      \
    \  pwr.resize(1, Mint(1));\n        while (N >= (int)pwr.size()) extend();\n \
    \   }\n\n    Mint power(int i) {  // return base ^ i\n        assert(i >= 0);\n\
    \        while (i >= (int)pwr.size()) extend();\n        return pwr[i];\n    }\n\
    \n    std::vector<Mint> build(const std::string &s) const {\n        int N = (int)s.size();\n\
    \        std::vector<Mint> res(N + 1);\n        for (int i = 0; i < N; i++) {\n\
    \            res[i + 1] = res[i] * base + s[i];\n        }\n        return res;\n\
    \    }\n\n    template <class T> std::vector<Mint> build(const std::vector<T>\
    \ &s) const {\n        int N = (int)s.size();\n        std::vector<Mint> res(N\
    \ + 1);\n        for (int i = 0; i < N; i++) {\n            res[i + 1] = res[i]\
    \ * base + s[i];\n        }\n        return res;\n    }\n\n    Mint prod(const\
    \ std::vector<Mint> &hs, int l, int r) {\n        assert(0 <= l and l <= r and\
    \ r < hs.size());\n        return hs[r] - hs[l] * power(r - l);\n    }\n\n   \
    \ Mint combine(Mint h1, Mint h2, int h2len) { return h1 * power(h2len) + h2; }\n\
    };\n"
  code: "#pragma once\n\n#include \"math/modint261.hpp\"\n\ntemplate <class Mint>\
    \ struct RollingHash {\n    std::vector<Mint> pwr;\n    const Mint base;\n\n \
    \   static inline Mint generate_base() {\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);\n \
    \       return Mint(rand(mt));\n    }\n\n    void extend() {\n        int n =\
    \ pwr.size();\n        int m = n * 2;\n        pwr.resize(m);\n        for (int\
    \ i = n; i < m; i++) pwr[i] = pwr[i - 1] * base;\n    }\n\n    RollingHash(int\
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
    \ Mint h2, int h2len) { return h1 * power(h2len) + h2; }\n};\n"
  dependsOn:
  - math/modint261.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_alds1/aoj_alds1_14_b.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
