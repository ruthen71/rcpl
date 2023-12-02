---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_alds1/aoj_alds1_14_b.test.cpp
    title: verify/aoj_alds1/aoj_alds1_14_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint261.hpp\"\n\nstruct ModInt261 {\n    static constexpr\
    \ uint64_t m = (1ULL << 61) - 1;\n    using uint128_t = __uint128_t;\n    using\
    \ mint = ModInt261;\n    uint64_t _v;\n\n    static constexpr uint64_t mod() {\
    \ return m; }\n\n    ModInt261() : _v(0ULL) {}\n\n    template <class T> ModInt261(T\
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
    \ z -= mod();\n        _v = (uint64_t)z;\n        return *this;\n    }\n    mint\
    \ &operator/=(const mint &rhs) { return (*this *= rhs.inv()); }\n\n    mint operator-()\
    \ const { return mint() - *this; }\n\n    mint pow(long long n) const {\n    \
    \    assert(n >= 0);\n        mint x = *this, r = 1;\n        while (n) {\n  \
    \          if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n   \
    \     }\n        return r;\n    }\n\n    mint inv() const { return pow(m - 2);\
    \ }\n\n    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs)\
    \ += rhs; }\n    friend mint operator-(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) -= rhs; }\n    friend mint operator*(const mint &lhs, const mint &rhs)\
    \ { return mint(lhs) *= rhs; }\n    friend mint operator/(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const mint\
    \ &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }\n};\n"
  code: "#pragma once\n\nstruct ModInt261 {\n    static constexpr uint64_t m = (1ULL\
    \ << 61) - 1;\n    using uint128_t = __uint128_t;\n    using mint = ModInt261;\n\
    \    uint64_t _v;\n\n    static constexpr uint64_t mod() { return m; }\n\n   \
    \ ModInt261() : _v(0ULL) {}\n\n    template <class T> ModInt261(T v) {\n     \
    \   long long x = (long long)(v % (long long)mod());\n        if (x < 0) x +=\
    \ mod();\n        _v = x;\n    }\n\n    uint64_t val() const { return _v; }\n\n\
    \    mint &operator++() {\n        _v++;\n        if (_v == mod()) _v = 0;\n \
    \       return *this;\n    }\n    mint &operator--() {\n        if (_v == 0) _v\
    \ = mod();\n        _v--;\n        return *this;\n    }\n\n    mint &operator+=(const\
    \ mint &rhs) {\n        _v += rhs._v;\n        if (_v >= mod()) _v -= mod();\n\
    \        return *this;\n    }\n    mint &operator-=(const mint &rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= mod()) _v += mod();\n        return *this;\n\
    \    }\n    mint &operator*=(const mint &rhs) {\n        uint128_t z = _v;\n \
    \       z *= rhs._v;\n        z = (z >> 61) + (z & mod());\n        if (z >= mod())\
    \ z -= mod();\n        _v = (uint64_t)z;\n        return *this;\n    }\n    mint\
    \ &operator/=(const mint &rhs) { return (*this *= rhs.inv()); }\n\n    mint operator-()\
    \ const { return mint() - *this; }\n\n    mint pow(long long n) const {\n    \
    \    assert(n >= 0);\n        mint x = *this, r = 1;\n        while (n) {\n  \
    \          if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n   \
    \     }\n        return r;\n    }\n\n    mint inv() const { return pow(m - 2);\
    \ }\n\n    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs)\
    \ += rhs; }\n    friend mint operator-(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) -= rhs; }\n    friend mint operator*(const mint &lhs, const mint &rhs)\
    \ { return mint(lhs) *= rhs; }\n    friend mint operator/(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const mint\
    \ &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/modint261.hpp
  requiredBy:
  - string/rolling_hash.hpp
  timestamp: '2023-12-02 23:15:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_alds1/aoj_alds1_14_b.test.cpp
documentation_of: math/modint261.hpp
layout: document
title: ModInt $\pmod{2^{61}-1} $
---

## 参考文献
- [安全で爆速なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6) `a * b` を `z = a * b` として `(z >> 61) + (z & mod)` でできる理由など