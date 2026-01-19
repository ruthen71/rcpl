---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/modint261.hpp
    title: Modint $\pmod{2^{61}-1} $
  - icon: ':x:'
    path: string/rolling_hash.hpp
    title: "Rolling Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"verify/string/rolling_hash.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n#include\
    \ <iostream>\n\n#line 2 \"string/rolling_hash.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <chrono>\n#include <random>\n#include <vector>\n\n\
    #line 2 \"math/modint261.hpp\"\n\n#line 4 \"math/modint261.hpp\"\n\nstruct Modint261\
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
    using mint261 = Modint261;\n#line 10 \"string/rolling_hash.hpp\"\n\n// Rolling\
    \ Hash\ntemplate <class Mint> struct RollingHash {\n    std::vector<Mint> pwr;\n\
    \    const Mint base;\n\n    RollingHash(const int n_max = 0, Mint base = generate_base())\
    \ : base(base) {\n        pwr.resize(1, Mint(1));\n        if (n_max > 0) extend(n_max);\n\
    \    }\n\n    static inline Mint generate_base() {\n        std::mt19937_64 mt(\n\
    \            std::chrono::steady_clock::now().time_since_epoch().count());\n \
    \       std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);\n  \
    \      return Mint(rand(mt));\n    }\n\n    void extend(int m = -1) {\n      \
    \  const int n = (int)(pwr.size());  // n >= 1\n        if (m == -1) m = n * 2;\
    \           // m >= 2\n        if (m > Mint::mod()) m = Mint::mod();\n       \
    \ if (n >= m) return;\n        pwr.resize(m);\n        for (int i = n; i < m;\
    \ i++) pwr[i] = pwr[i - 1] * base;\n    }\n\n    // return base ^ n\n    Mint\
    \ power(const int n) {\n        assert(n >= 0);\n        while (n >= (int)(pwr.size()))\
    \ extend();\n        return pwr[n];\n    }\n\n    template <class T> std::vector<Mint>\
    \ build(const std::vector<T>& s) const {\n        const int n = (int)(s.size());\n\
    \        std::vector<Mint> res(n + 1);\n        for (int i = 0; i < n; i++) {\n\
    \            res[i + 1] = res[i] * base + s[i];\n        }\n        return res;\n\
    \    }\n\n    std::vector<Mint> build(const std::string& s) const {\n        const\
    \ int n = (int)(s.size());\n        std::vector<int> s2(n);\n        for (int\
    \ i = 0; i < n; i++) s2[i] = s[i];\n        return build(s2);\n    }\n\n    Mint\
    \ prod(const std::vector<Mint>& hs, const int l, const int r) {\n        assert(0\
    \ <= l and l <= r and r <= (int)(hs.size()));\n        return hs[r] - hs[l] *\
    \ power(r - l);\n    }\n\n    Mint combine(Mint h1, Mint h2, int h2len) { return\
    \ h1 * power(h2len) + h2; }\n};\n#line 6 \"verify/string/rolling_hash.test.cpp\"\
    \n\nint main() {\n    std::string T, P;\n    std::cin >> T >> P;\n    RollingHash<mint261>\
    \ rh;\n    auto rht = rh.build(T);\n    auto rhp = rh.build(P);\n    for (int\
    \ i = 0; i + P.size() <= T.size(); i++) {\n        if (rh.prod(rht, i, i + P.size())\
    \ == rh.prod(rhp, 0, P.size())) {\n            std::cout << i << '\\n';\n    \
    \    }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n\n#include \"string/rolling_hash.hpp\"\n\nint main()\
    \ {\n    std::string T, P;\n    std::cin >> T >> P;\n    RollingHash<mint261>\
    \ rh;\n    auto rht = rh.build(T);\n    auto rhp = rh.build(P);\n    for (int\
    \ i = 0; i + P.size() <= T.size(); i++) {\n        if (rh.prod(rht, i, i + P.size())\
    \ == rh.prod(rhp, 0, P.size())) {\n            std::cout << i << '\\n';\n    \
    \    }\n    }\n    return 0;\n}"
  dependsOn:
  - string/rolling_hash.hpp
  - math/modint261.hpp
  isVerificationFile: true
  path: verify/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2026-01-20 04:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/verify/string/rolling_hash.test.cpp
- /verify/verify/string/rolling_hash.test.cpp.html
title: verify/string/rolling_hash.test.cpp
---
