---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/binomial.md
    document_title: "Binomial (\u524D\u8A08\u7B97\u3042\u308A\u4E8C\u9805\u4FC2\u6570\
      )"
    links: []
  bundledCode: "#line 2 \"src/math/binomial.hpp\"\n\ntemplate <class Mint> struct\
    \ binomial {\n    std::vector<Mint> f, g;\n\n    binomial(int N = 0) {\n     \
    \   f.resize(1, Mint(1));\n        g.resize(1, Mint(1));\n        while (N >=\
    \ (int)f.size()) extend();\n    }\n\n    void extend() {\n        int n = (int)f.size();\n\
    \        int m = n * 2;\n        f.resize(m);\n        g.resize(m);\n        for\
    \ (int i = n; i < m; i++) f[i] = f[i - 1] * Mint(i);\n        g[m - 1] = 1 / f[m\
    \ - 1];\n        for (int i = m - 2; i >= n; i--) g[i] = g[i + 1] * Mint(i + 1);\n\
    \    }\n\n    Mint fact(int i) {\n        if (i < 0) return Mint(0);\n       \
    \ while (i >= (int)f.size()) extend();\n        return f[i];\n    }\n\n    Mint\
    \ finv(int i) {\n        if (i < 0) return Mint(0);\n        while (i >= (int)g.size())\
    \ extend();\n        return g[i];\n    }\n\n    Mint C(int N, int K) {\n     \
    \   if (N < 0 || K < 0 || N < K) return 0;\n        return fact(N) * finv(N -\
    \ K) * finv(K);\n    }\n\n    Mint P(int N, int K) {\n        if (N < 0 || K <\
    \ 0 || N < K) return 0;\n        return fact(N) * finv(N - K);\n    }\n\n    Mint\
    \ C_naive(int N, int K) {\n        if (N < 0 || K < 0 || N < K) return 0;\n  \
    \      Mint res = 1;\n        K = min(K, N - K);\n        for (int i = 1; i <=\
    \ K; i++) {\n            res *= N--;\n            res /= i;\n        }\n     \
    \   return res;\n    }\n};\n\n/**\n * @brief Binomial (\u524D\u8A08\u7B97\u3042\
    \u308A\u4E8C\u9805\u4FC2\u6570)\n * @docs docs/math/binomial.md\n */\n"
  code: "#pragma once\n\ntemplate <class Mint> struct binomial {\n    std::vector<Mint>\
    \ f, g;\n\n    binomial(int N = 0) {\n        f.resize(1, Mint(1));\n        g.resize(1,\
    \ Mint(1));\n        while (N >= (int)f.size()) extend();\n    }\n\n    void extend()\
    \ {\n        int n = (int)f.size();\n        int m = n * 2;\n        f.resize(m);\n\
    \        g.resize(m);\n        for (int i = n; i < m; i++) f[i] = f[i - 1] * Mint(i);\n\
    \        g[m - 1] = 1 / f[m - 1];\n        for (int i = m - 2; i >= n; i--) g[i]\
    \ = g[i + 1] * Mint(i + 1);\n    }\n\n    Mint fact(int i) {\n        if (i <\
    \ 0) return Mint(0);\n        while (i >= (int)f.size()) extend();\n        return\
    \ f[i];\n    }\n\n    Mint finv(int i) {\n        if (i < 0) return Mint(0);\n\
    \        while (i >= (int)g.size()) extend();\n        return g[i];\n    }\n\n\
    \    Mint C(int N, int K) {\n        if (N < 0 || K < 0 || N < K) return 0;\n\
    \        return fact(N) * finv(N - K) * finv(K);\n    }\n\n    Mint P(int N, int\
    \ K) {\n        if (N < 0 || K < 0 || N < K) return 0;\n        return fact(N)\
    \ * finv(N - K);\n    }\n\n    Mint C_naive(int N, int K) {\n        if (N < 0\
    \ || K < 0 || N < K) return 0;\n        Mint res = 1;\n        K = min(K, N -\
    \ K);\n        for (int i = 1; i <= K; i++) {\n            res *= N--;\n     \
    \       res /= i;\n        }\n        return res;\n    }\n};\n\n/**\n * @brief\
    \ Binomial (\u524D\u8A08\u7B97\u3042\u308A\u4E8C\u9805\u4FC2\u6570)\n * @docs\
    \ docs/math/binomial.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/math/binomial.hpp
  requiredBy: []
  timestamp: '2023-01-16 01:16:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/binomial.hpp
layout: document
redirect_from:
- /library/src/math/binomial.hpp
- /library/src/math/binomial.hpp.html
title: "Binomial (\u524D\u8A08\u7B97\u3042\u308A\u4E8C\u9805\u4FC2\u6570)"
---
## 概要

- `ac-library` の `modint` を渡した場合動くことを確認している
- `using mint = atcoder::modint998244353;` などとしておき、`binomial<mint> B;` とする
- 勝手に配列を2べきで拡張するようにした
