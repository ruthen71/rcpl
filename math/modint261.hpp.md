---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: string/rolling_hash.hpp
    title: "Rolling Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/string/rolling_hash.test.cpp
    title: verify/string/rolling_hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint261.hpp\"\n\n#include <cassert>\n\nstruct Modint261\
    \ {\n    static constexpr unsigned long long m = (1ULL << 61) - 1;\n    using\
    \ mint = Modint261;\n    unsigned long long _v;\n\n    static constexpr long long\
    \ mod() { return m; }\n    static constexpr unsigned long long umod() { return\
    \ m; }\n\n    Modint261() : _v(0ULL) {}\n\n    template <class T> Modint261(T\
    \ v) {\n        long long x = (long long)(v % (long long)(umod()));\n        if\
    \ (x < 0) x += umod();\n        _v = (unsigned long long)(x);\n    }\n\n    unsigned\
    \ long long val() const { return _v; }\n\n    mint &operator++() {\n        _v++;\n\
    \        if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint &operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint &operator+=(const\
    \ mint &rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint &operator-=(const mint &rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint &operator*=(const mint &rhs) {\n        __uint128_t z = _v;\n\
    \        z *= rhs._v;\n        z = (z >> 61) + (z & umod());\n        if (z >=\
    \ umod()) z -= umod();\n        _v = (unsigned long long)z;\n        return *this;\n\
    \    }\n    mint &operator/=(const mint &rhs) { return (*this *= rhs.inv()); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(n >=\
    \ 0);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n\n    mint inv() const { return pow(umod() - 2); }\n\n   \
    \ friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) +=\
    \ rhs; }\n    friend mint operator-(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) -= rhs; }\n    friend mint operator*(const mint &lhs, const mint &rhs)\
    \ { return mint(lhs) *= rhs; }\n    friend mint operator/(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const mint\
    \ &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }\n};\n\
    using mint261 = Modint261;\n"
  code: "#pragma once\n\n#include <cassert>\n\nstruct Modint261 {\n    static constexpr\
    \ unsigned long long m = (1ULL << 61) - 1;\n    using mint = Modint261;\n    unsigned\
    \ long long _v;\n\n    static constexpr long long mod() { return m; }\n    static\
    \ constexpr unsigned long long umod() { return m; }\n\n    Modint261() : _v(0ULL)\
    \ {}\n\n    template <class T> Modint261(T v) {\n        long long x = (long long)(v\
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
    using mint261 = Modint261;"
  dependsOn: []
  isVerificationFile: false
  path: math/modint261.hpp
  requiredBy:
  - string/rolling_hash.hpp
  timestamp: '2024-08-27 02:34:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/string/rolling_hash.test.cpp
documentation_of: math/modint261.hpp
layout: document
title: Modint $\pmod{2^{61}-1} $
---

## 参考文献
- [安全で爆速なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6) `a * b` を `z = a * b` として `(z >> 61) + (z & mod)` でできる理由など