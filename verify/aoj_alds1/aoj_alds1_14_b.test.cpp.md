---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint261.hpp
    title: Modint $\pmod{2^{61}-1} $
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"verify/aoj_alds1/aoj_alds1_14_b.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #include <bits/stdc++.h>\n\n#line 2 \"string/rolling_hash.hpp\"\n\n#line 2 \"\
    math/modint261.hpp\"\n\nstruct Modint261 {\n    static constexpr unsigned long\
    \ long m = (1ULL << 61) - 1;\n    using mint = Modint261;\n    unsigned long long\
    \ _v;\n\n    static constexpr long long mod() { return m; }\n    static constexpr\
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
    using mint261 = Modint261;\n#line 4 \"string/rolling_hash.hpp\"\n\ntemplate <class\
    \ Mint> struct RollingHash {\n    std::vector<Mint> pwr;\n    const Mint base;\n\
    \n    static inline Mint generate_base() {\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \ Mint h2, int h2len) { return h1 * power(h2len) + h2; }\n};\n#line 6 \"verify/aoj_alds1/aoj_alds1_14_b.test.cpp\"\
    \n\nint main() {\n    std::string T, P;\n    std::cin >> T >> P;\n    RollingHash<mint261>\
    \ rh;\n    auto rht = rh.build(T);\n    auto rhp = rh.build(P);\n    for (int\
    \ i = 0; i + P.size() <= T.size(); i++) {\n        if (rh.prod(rht, i, i + P.size())\
    \ == rh.prod(rhp, 0, P.size())) {\n            std::cout << i << '\\n';\n    \
    \    }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"string/rolling_hash.hpp\"\n\nint main()\
    \ {\n    std::string T, P;\n    std::cin >> T >> P;\n    RollingHash<mint261>\
    \ rh;\n    auto rht = rh.build(T);\n    auto rhp = rh.build(P);\n    for (int\
    \ i = 0; i + P.size() <= T.size(); i++) {\n        if (rh.prod(rht, i, i + P.size())\
    \ == rh.prod(rhp, 0, P.size())) {\n            std::cout << i << '\\n';\n    \
    \    }\n    }\n    return 0;\n}\n"
  dependsOn:
  - string/rolling_hash.hpp
  - math/modint261.hpp
  isVerificationFile: true
  path: verify/aoj_alds1/aoj_alds1_14_b.test.cpp
  requiredBy: []
  timestamp: '2024-01-11 16:01:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_alds1/aoj_alds1_14_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_alds1/aoj_alds1_14_b.test.cpp
- /verify/verify/aoj_alds1/aoj_alds1_14_b.test.cpp.html
title: verify/aoj_alds1/aoj_alds1_14_b.test.cpp
---
