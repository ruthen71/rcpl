---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
    title: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/static_modint.hpp\"\n\n#include <utility>\n#include\
    \ <cassert>\n\n// constexpr ... for constexpr bool prime()\ntemplate <int m> struct\
    \ StaticModint {\n    using mint = StaticModint;\n    unsigned int _v;\n\n   \
    \ static constexpr int mod() { return m; }\n    static constexpr unsigned int\
    \ umod() { return m; }\n\n    constexpr StaticModint() : _v(0) {}\n\n    template\
    \ <class T> constexpr StaticModint(T v) {\n        long long x = (long long)(v\
    \ % (long long)(umod()));\n        if (x < 0) x += umod();\n        _v = (unsigned\
    \ int)(x);\n    }\n\n    constexpr unsigned int val() const { return _v; }\n\n\
    \    constexpr mint &operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    constexpr mint &operator--() {\n\
    \        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n   \
    \ }\n    constexpr mint operator++(int) {\n        mint result = *this;\n    \
    \    ++*this;\n        return result;\n    }\n    constexpr mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    constexpr mint &operator+=(const mint &rhs) {\n        _v += rhs._v;\n\
    \        if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    constexpr\
    \ mint &operator-=(const mint &rhs) {\n        _v -= rhs._v;\n        if (_v >=\
    \ umod()) _v += umod();\n        return *this;\n    }\n    constexpr mint &operator*=(const\
    \ mint &rhs) {\n        unsigned long long z = _v;\n        z *= rhs._v;\n   \
    \     _v = (unsigned int)(z % umod());\n        return *this;\n    }\n    constexpr\
    \ mint &operator/=(const mint &rhs) { return (*this *= rhs.inv()); }\n\n    constexpr\
    \ mint operator+() const { return *this; }\n    constexpr mint operator-() const\
    \ { return mint() - *this; }\n\n    constexpr mint pow(long long n) const {\n\
    \        assert(n >= 0);\n        mint x = *this, r = 1;\n        while (n) {\n\
    \            if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n \
    \       }\n        return r;\n    }\n\n    constexpr mint inv() const {\n    \
    \    if (prime) {\n            assert(_v);\n            return pow(umod() - 2);\n\
    \        } else {\n            auto eg = inv_gcd(_v, m);\n            assert(eg.first\
    \ == 1);\n            return eg.second;\n        }\n    }\n\n    friend constexpr\
    \ mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs;\
    \ }\n    friend constexpr mint operator-(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) -= rhs; }\n    friend constexpr mint operator*(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) *= rhs; }\n    friend constexpr mint operator/(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }\n    friend constexpr\
    \ bool operator==(const mint &lhs, const mint &rhs) { return lhs._v == rhs._v;\
    \ }\n    friend constexpr bool operator!=(const mint &lhs, const mint &rhs) {\
    \ return lhs._v != rhs._v; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &v) { return os << v.val(); }\n\n    static constexpr bool prime\
    \ = []() -> bool {\n        if (m == 1) return false;\n        if (m == 2 || m\
    \ == 7 || m == 61) return true;\n        if (m % 2 == 0) return false;\n     \
    \   unsigned int d = m - 1;\n        while (d % 2 == 0) d /= 2;\n        for (unsigned\
    \ int a : {2, 7, 61}) {\n            unsigned int t = d;\n            mint y =\
    \ mint(a).pow(t);\n            while (t != m - 1 and y != 1 and y != m - 1) {\n\
    \                y *= y;\n                t <<= 1;\n            }\n          \
    \  if (y != m - 1 and t % 2 == 0) {\n                return false;\n         \
    \   }\n        }\n        return true;\n    }();\n    static constexpr std::pair<int,\
    \ int> inv_gcd(int a, int b) {\n        if (a == 0) return {b, 0};\n        int\
    \ s = b, t = a, m0 = 0, m1 = 1;\n        while (t) {\n            const int u\
    \ = s / t;\n            s -= t * u;\n            m0 -= m1 * u;\n            std::swap(s,\
    \ t);\n            std::swap(m0, m1);\n        }\n        if (m0 < 0) m0 += b\
    \ / s;\n        return {s, m0};\n    }\n};\nusing mint107 = StaticModint<1000000007>;\n\
    using mint998 = StaticModint<998244353>;\n"
  code: "#pragma once\n\n#include <utility>\n#include <cassert>\n\n// constexpr ...\
    \ for constexpr bool prime()\ntemplate <int m> struct StaticModint {\n    using\
    \ mint = StaticModint;\n    unsigned int _v;\n\n    static constexpr int mod()\
    \ { return m; }\n    static constexpr unsigned int umod() { return m; }\n\n  \
    \  constexpr StaticModint() : _v(0) {}\n\n    template <class T> constexpr StaticModint(T\
    \ v) {\n        long long x = (long long)(v % (long long)(umod()));\n        if\
    \ (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n\n    constexpr\
    \ unsigned int val() const { return _v; }\n\n    constexpr mint &operator++()\
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
    \    }\n};\nusing mint107 = StaticModint<1000000007>;\nusing mint998 = StaticModint<998244353>;"
  dependsOn: []
  isVerificationFile: false
  path: math/static_modint.hpp
  requiredBy: []
  timestamp: '2024-12-04 12:30:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
documentation_of: math/static_modint.hpp
layout: document
title: Static Modint
---

コンパイル時に $ \bmod $ が確定するときに使える

以下は宣言済み
- `using mint107 = StaticModint<1000000007>;`
- `using mint998 = StaticModint<998244353>;`
