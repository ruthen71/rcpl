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
  bundledCode: "#line 2 \"math/static_modint.hpp\"\n\ntemplate <int m> struct StaticModint\
    \ {\n    using mint = StaticModint;\n    unsigned int _v;\n\n    static constexpr\
    \ int mod() { return m; }\n    static constexpr unsigned int umod() { return m;\
    \ }\n\n    StaticModint() : _v(0) {}\n\n    template <class T> StaticModint(T\
    \ v) {\n        long long x = (long long)(v % (long long)(umod()));\n        if\
    \ (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n\n    unsigned\
    \ int val() const { return _v; }\n\n    mint &operator++() {\n        _v++;\n\
    \        if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint &operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint &operator+=(const\
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
    \     }\n        return r;\n    }\n\n    mint inv() const { return pow(umod()\
    \ - 2); }\n\n    friend mint operator+(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) += rhs; }\n    friend mint operator-(const mint &lhs, const mint &rhs)\
    \ { return mint(lhs) -= rhs; }\n    friend mint operator*(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const mint\
    \ &lhs, const mint &rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }\n};\n\
    using mint107 = StaticModint<1000000007>;\nusing mint998 = StaticModint<998244353>;\n"
  code: "#pragma once\n\ntemplate <int m> struct StaticModint {\n    using mint =\
    \ StaticModint;\n    unsigned int _v;\n\n    static constexpr int mod() { return\
    \ m; }\n    static constexpr unsigned int umod() { return m; }\n\n    StaticModint()\
    \ : _v(0) {}\n\n    template <class T> StaticModint(T v) {\n        long long\
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
    \     }\n        return r;\n    }\n\n    mint inv() const { return pow(umod()\
    \ - 2); }\n\n    friend mint operator+(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) += rhs; }\n    friend mint operator-(const mint &lhs, const mint &rhs)\
    \ { return mint(lhs) -= rhs; }\n    friend mint operator*(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const mint\
    \ &lhs, const mint &rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }\n};\n\
    using mint107 = StaticModint<1000000007>;\nusing mint998 = StaticModint<998244353>;"
  dependsOn: []
  isVerificationFile: false
  path: math/static_modint.hpp
  requiredBy: []
  timestamp: '2024-01-11 16:01:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
documentation_of: math/static_modint.hpp
layout: document
redirect_from:
- /library/math/static_modint.hpp
- /library/math/static_modint.hpp.html
title: math/static_modint.hpp
---
