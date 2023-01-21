---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/algebra/monoid_rolling_hash.hpp
    title: src/algebra/monoid_rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash.hpp
    title: src/string/rolling_hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_alds1/aoj_alds1_14_b.test.cpp
    title: verify/aoj_alds1/aoj_alds1_14_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/modint261.md
    links: []
  bundledCode: "#line 2 \"src/math/modint261.hpp\"\n\nstruct modint261 {\n    static\
    \ constexpr uint64_t m = (1ULL << 61) - 1;\n    using uint128_t = __uint128_t;\n\
    \    using mint = modint261;\n    uint64_t _v;\n\n    static constexpr uint64_t\
    \ mod() { return m; }\n\n    modint261() : _v(0ULL) {}\n\n    template <class\
    \ T> modint261(T v) {\n        long long x = (long long)(v % (long long)mod());\n\
    \        if (x < 0) x += mod();\n        _v = x;\n    }\n\n    uint64_t val()\
    \ const { return _v; }\n\n    mint &operator++() {\n        _v++;\n        if\
    \ (_v == mod()) _v = 0;\n        return *this;\n    }\n    mint &operator--()\
    \ {\n        if (_v == 0) _v = mod();\n        _v--;\n        return *this;\n\
    \    }\n\n    mint &operator+=(const mint &rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= mod()) _v -= mod();\n        return *this;\n    }\n    mint &operator-=(const\
    \ mint &rhs) {\n        _v -= rhs._v;\n        if (_v >= mod()) _v += mod();\n\
    \        return *this;\n    }\n    mint &operator*=(const mint &rhs) {\n     \
    \   uint128_t z = _v;\n        z *= rhs._v;\n        z = (z >> 61) + (z & mod());\n\
    \        if (z >= mod()) z -= mod();\n        _v = (uint64_t)z;\n        return\
    \ *this;\n    }\n\n    mint operator-() const { return mint() - *this; }\n\n \
    \   mint pow(long long n) const {\n        assert(n >= 0);\n        mint x = *this,\
    \ r = 1;\n        while (n) {\n            if (n & 1) r *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return r;\n    }\n\n    friend\
    \ mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs;\
    \ }\n    friend mint operator-(const mint &lhs, const mint &rhs) { return mint(lhs)\
    \ -= rhs; }\n    friend mint operator*(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) *= rhs; }\n    friend bool operator==(const mint &lhs, const mint\
    \ &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const mint &lhs,\
    \ const mint &rhs) { return lhs._v != rhs._v; }\n};\n\n/**\n * @docs docs/math/modint261.md\n\
    \ */\n"
  code: "#pragma once\n\nstruct modint261 {\n    static constexpr uint64_t m = (1ULL\
    \ << 61) - 1;\n    using uint128_t = __uint128_t;\n    using mint = modint261;\n\
    \    uint64_t _v;\n\n    static constexpr uint64_t mod() { return m; }\n\n   \
    \ modint261() : _v(0ULL) {}\n\n    template <class T> modint261(T v) {\n     \
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
    \ docs/math/modint261.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/math/modint261.hpp
  requiredBy:
  - src/string/rolling_hash.hpp
  - src/algebra/monoid_rolling_hash.hpp
  timestamp: '2023-01-16 02:29:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_alds1/aoj_alds1_14_b.test.cpp
documentation_of: src/math/modint261.hpp
layout: document
redirect_from:
- /library/src/math/modint261.hpp
- /library/src/math/modint261.hpp.html
title: src/math/modint261.hpp
---
## 参考
- [安全で爆速なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)
    - `a * b` を `z = a * b` として `(z >> 61) + (z & mod)` でできる理由など