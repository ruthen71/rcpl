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
  bundledCode: "#line 2 \"src/string/rolling_hash.hpp\"\n\ntemplate <class Mint> struct\
    \ rolling_hash {\n    std::vector<Mint> pwr;\n    const Mint base;\n\n    static\
    \ inline Mint generate_base() {\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<int> rand(1, Mint::mod() - 1);\n      \
    \  return Mint(rand(mt));\n    }\n\n    void extend() {\n        int n = pwr.size();\n\
    \        int m = n * 2;\n        pwr.resize(m);\n        for (int i = n; i < m;\
    \ i++) pwr[i] = pwr[i - 1] * base;\n    }\n\n    rolling_hash(int N = 0, Mint\
    \ base = generate_base()) : base(base) {\n        pwr.resize(1, Mint(1));\n  \
    \      while (N >= (int)pwr.size()) extend();\n    }\n\n    Mint power(int i)\
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
  code: "#pragma once\n\ntemplate <class Mint> struct rolling_hash {\n    std::vector<Mint>\
    \ pwr;\n    const Mint base;\n\n    static inline Mint generate_base() {\n   \
    \     std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<int> rand(1, Mint::mod() - 1);\n      \
    \  return Mint(rand(mt));\n    }\n\n    void extend() {\n        int n = pwr.size();\n\
    \        int m = n * 2;\n        pwr.resize(m);\n        for (int i = n; i < m;\
    \ i++) pwr[i] = pwr[i - 1] * base;\n    }\n\n    rolling_hash(int N = 0, Mint\
    \ base = generate_base()) : base(base) {\n        pwr.resize(1, Mint(1));\n  \
    \      while (N >= (int)pwr.size()) extend();\n    }\n\n    Mint power(int i)\
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
  dependsOn: []
  isVerificationFile: false
  path: src/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-01-16 00:56:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/rolling_hash.hpp
layout: document
redirect_from:
- /library/src/string/rolling_hash.hpp
- /library/src/string/rolling_hash.hpp.html
title: src/string/rolling_hash.hpp
---
