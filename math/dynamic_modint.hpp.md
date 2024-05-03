---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/dynamic_modint.hpp\"\n\n#include <utility>\n#include\
    \ <cassert>\n\ntemplate <int id> struct DynamicModint {\n    using mint = DynamicModint;\n\
    \    unsigned int _v;\n\n    static int m;\n    static void set_mod(const int\
    \ _m) {\n        assert(_m >= 1);\n        m = _m;\n    }\n\n    static int mod()\
    \ { return m; }\n    static unsigned int umod() { return m; }\n\n    DynamicModint()\
    \ : _v(0) {}\n\n    template <class T> DynamicModint(T v) {\n        long long\
    \ x = (long long)(v % (long long)(umod()));\n        if (x < 0) x += umod();\n\
    \        _v = (unsigned int)(x);\n    }\n\n    unsigned int val() const { return\
    \ _v; }\n\n    mint &operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    mint &operator--() {\n        if\
    \ (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    mint\
    \ operator++(int) {\n        mint result = *this;\n        ++*this;\n        return\
    \ result;\n    }\n    mint operator--(int) {\n        mint result = *this;\n \
    \       --*this;\n        return result;\n    }\n\n    mint &operator+=(const\
    \ mint &rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint &operator-=(const mint &rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint &operator*=(const mint &rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint &operator/=(const mint &rhs) { return (*this\
    \ *= rhs.inv()); }\n\n    mint operator+() const { return *this; }\n    mint operator-()\
    \ const { return mint() - *this; }\n\n    mint pow(long long n) const {\n    \
    \    assert(n >= 0);\n        mint x = *this, r = 1;\n        while (n) {\n  \
    \          if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n   \
    \     }\n        return r;\n    }\n\n    mint inv() const {\n        auto eg =\
    \ inv_gcd(_v, mod());\n        assert(eg.first == 1);\n        return eg.second;\n\
    \    }\n\n    friend mint operator+(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) += rhs; }\n    friend mint operator-(const mint &lhs, const mint &rhs)\
    \ { return mint(lhs) -= rhs; }\n    friend mint operator*(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const mint\
    \ &lhs, const mint &rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }\n\n \
    \   static constexpr std::pair<int, int> inv_gcd(int a, int b) {\n        if (a\
    \ == 0) return {b, 0};\n        int s = b, t = a, m0 = 0, m1 = 1;\n        while\
    \ (t) {\n            const int u = s / t;\n            s -= t * u;\n         \
    \   m0 -= m1 * u;\n            std::swap(s, t);\n            std::swap(m0, m1);\n\
    \        }\n        if (m0 < 0) m0 += b / s;\n        return {s, m0};\n    }\n\
    };\ntemplate <int id> int DynamicModint<id>::m = 998244353;\nusing mintd = DynamicModint<0>;\n"
  code: "#pragma once\n\n#include <utility>\n#include <cassert>\n\ntemplate <int id>\
    \ struct DynamicModint {\n    using mint = DynamicModint;\n    unsigned int _v;\n\
    \n    static int m;\n    static void set_mod(const int _m) {\n        assert(_m\
    \ >= 1);\n        m = _m;\n    }\n\n    static int mod() { return m; }\n    static\
    \ unsigned int umod() { return m; }\n\n    DynamicModint() : _v(0) {}\n\n    template\
    \ <class T> DynamicModint(T v) {\n        long long x = (long long)(v % (long\
    \ long)(umod()));\n        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint &operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint &operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
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
    \ const {\n        auto eg = inv_gcd(_v, mod());\n        assert(eg.first == 1);\n\
    \        return eg.second;\n    }\n\n    friend mint operator+(const mint &lhs,\
    \ const mint &rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }\n\n \
    \   static constexpr std::pair<int, int> inv_gcd(int a, int b) {\n        if (a\
    \ == 0) return {b, 0};\n        int s = b, t = a, m0 = 0, m1 = 1;\n        while\
    \ (t) {\n            const int u = s / t;\n            s -= t * u;\n         \
    \   m0 -= m1 * u;\n            std::swap(s, t);\n            std::swap(m0, m1);\n\
    \        }\n        if (m0 < 0) m0 += b / s;\n        return {s, m0};\n    }\n\
    };\ntemplate <int id> int DynamicModint<id>::m = 998244353;\nusing mintd = DynamicModint<0>;"
  dependsOn: []
  isVerificationFile: false
  path: math/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2024-05-04 00:04:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dynamic_modint.hpp
layout: document
title: Dynamic Modint
---

コンパイル時に $ \bmod $ が確定しないときに使える

- すでに `using mintd = DynamicModint<0>;` が宣言されており、`mintd::set_mod(m)` などでセット可能
- 複数の $ \bmod $ に対して利用したい場合は `using mintd1 = DynamicModint<-1>` などとして増やす
