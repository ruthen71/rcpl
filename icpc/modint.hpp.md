---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: icpc/template.hpp
    title: icpc/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj_other/aoj_3331.test.cpp
    title: verify/aoj_other/aoj_3331.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"icpc/modint.hpp\"\n\n#line 2 \"icpc/template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n#define REP(i,\
    \ n) for (int i = 0; i < (n); i++)\ntemplate <class T> using V = vector<T>;\n\
    template <class T> ostream& operator<<(ostream &os, const V<T>& v) {\n    os <<\
    \ \"[ \";\n    for (auto &vi : v) os << vi << \", \";\n    return os << \"]\"\
    ;\n}\n\n#ifdef LOCAL\n#define show(x) cerr << __LINE__ << \" : \" << #x << \"\
    \ = \" << x << endl;\n#else\n#define show(x) true\n#endif\n\n// g++ -g -fsanitize=undefined,address\
    \ -DLOCAL -std=gnu++17\n#line 4 \"icpc/modint.hpp\"\n\nusing uint = unsigned int;\n\
    using ull = unsigned long long;\ntemplate <uint MD> struct Modint {\n    using\
    \ M = Modint;\n    const static M G;\n    uint v;\n    Modint(ll val = 0) { set_v(val\
    \ % MD + MD); }\n    M& set_v(uint val) {\n        v = (val < MD) ? val : val\
    \ - MD;\n        return *this;\n    }\n    explicit operator bool() const { return\
    \ v != 0; }\n    M operator-() const { return M() - *this; }\n    M operator+(const\
    \ M& r) const { return M().set_v(v + r.v); }\n    M operator-(const M& r) const\
    \ { return M().set_v(v + MD - r.v); }\n    M operator*(const M& r) const { return\
    \ M().set_v(ull(v) * r.v % MD); }\n    M operator/(const M& r) const { return\
    \ *this * r.inv(); }\n    M& operator+=(const M& r) { return *this = *this + r;\
    \ }\n    M& operator-=(const M& r) { return *this = *this - r; }\n    M& operator*=(const\
    \ M& r) { return *this = *this * r; }\n    M& operator/=(const M& r) { return\
    \ *this = *this / r; }\n    bool operator==(const M& r) const { return v == r.v;\
    \ }\n    M pow(ll n) const {\n        M x = *this, r = 1;\n        while (n) {\n\
    \            if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n \
    \       }\n        return r;\n    }\n    M inv() const { return pow(MD - 2); }\n\
    \    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }\n\
    };\n// using mint = Modint<998244353>;\n// template<> const mint mint::G = mint(3);\n"
  code: "#pragma once\n\n#include \"icpc/template.hpp\"\n\nusing uint = unsigned int;\n\
    using ull = unsigned long long;\ntemplate <uint MD> struct Modint {\n    using\
    \ M = Modint;\n    const static M G;\n    uint v;\n    Modint(ll val = 0) { set_v(val\
    \ % MD + MD); }\n    M& set_v(uint val) {\n        v = (val < MD) ? val : val\
    \ - MD;\n        return *this;\n    }\n    explicit operator bool() const { return\
    \ v != 0; }\n    M operator-() const { return M() - *this; }\n    M operator+(const\
    \ M& r) const { return M().set_v(v + r.v); }\n    M operator-(const M& r) const\
    \ { return M().set_v(v + MD - r.v); }\n    M operator*(const M& r) const { return\
    \ M().set_v(ull(v) * r.v % MD); }\n    M operator/(const M& r) const { return\
    \ *this * r.inv(); }\n    M& operator+=(const M& r) { return *this = *this + r;\
    \ }\n    M& operator-=(const M& r) { return *this = *this - r; }\n    M& operator*=(const\
    \ M& r) { return *this = *this * r; }\n    M& operator/=(const M& r) { return\
    \ *this = *this / r; }\n    bool operator==(const M& r) const { return v == r.v;\
    \ }\n    M pow(ll n) const {\n        M x = *this, r = 1;\n        while (n) {\n\
    \            if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n \
    \       }\n        return r;\n    }\n    M inv() const { return pow(MD - 2); }\n\
    \    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }\n\
    };\n// using mint = Modint<998244353>;\n// template<> const mint mint::G = mint(3);"
  dependsOn:
  - icpc/template.hpp
  isVerificationFile: false
  path: icpc/modint.hpp
  requiredBy: []
  timestamp: '2023-05-15 01:12:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj_other/aoj_3331.test.cpp
documentation_of: icpc/modint.hpp
layout: document
redirect_from:
- /library/icpc/modint.hpp
- /library/icpc/modint.hpp.html
title: icpc/modint.hpp
---
