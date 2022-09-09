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
    \ binomial {\n    std::vector<Mint> fact, finv;\n\n    binomial(int N) : fact(N\
    \ + 1), finv(N + 1) {\n        fact[0] = 1;\n        for (int i = 1; i <= N; i++)\
    \ fact[i] = fact[i - 1] * i;\n        finv[N] = 1 / fact[N];\n        for (int\
    \ i = N - 1; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1);\n    }\n\n    Mint\
    \ C(int N, int K) {\n        if (N < 0 || K < 0 || N < K) return 0;\n        return\
    \ fact[N] * finv[N - K] * finv[K];\n    }\n\n    Mint P(int N, int K) {\n    \
    \    if (N < 0 || K < 0 || N < K) return 0;\n        return fact[N] * finv[N -\
    \ K];\n    }\n\n    Mint C_naive(int N, int K) {\n        if (N < 0 || K < 0 ||\
    \ N < K) return 0;\n        Mint res = 1;\n        K = min(K, N - K);\n      \
    \  for (int i = 1; i <= K; i++) {\n            res *= N--;\n            res /=\
    \ i;\n        }\n        return res;\n    }\n};\n\n/**\n * @brief Binomial (\u524D\
    \u8A08\u7B97\u3042\u308A\u4E8C\u9805\u4FC2\u6570)\n * @docs docs/math/binomial.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <class Mint> struct binomial {\n    std::vector<Mint>\
    \ fact, finv;\n\n    binomial(int N) : fact(N + 1), finv(N + 1) {\n        fact[0]\
    \ = 1;\n        for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i;\n    \
    \    finv[N] = 1 / fact[N];\n        for (int i = N - 1; i >= 0; i--) finv[i]\
    \ = finv[i + 1] * (i + 1);\n    }\n\n    Mint C(int N, int K) {\n        if (N\
    \ < 0 || K < 0 || N < K) return 0;\n        return fact[N] * finv[N - K] * finv[K];\n\
    \    }\n\n    Mint P(int N, int K) {\n        if (N < 0 || K < 0 || N < K) return\
    \ 0;\n        return fact[N] * finv[N - K];\n    }\n\n    Mint C_naive(int N,\
    \ int K) {\n        if (N < 0 || K < 0 || N < K) return 0;\n        Mint res =\
    \ 1;\n        K = min(K, N - K);\n        for (int i = 1; i <= K; i++) {\n   \
    \         res *= N--;\n            res /= i;\n        }\n        return res;\n\
    \    }\n};\n\n/**\n * @brief Binomial (\u524D\u8A08\u7B97\u3042\u308A\u4E8C\u9805\
    \u4FC2\u6570)\n * @docs docs/math/binomial.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/math/binomial.hpp
  requiredBy: []
  timestamp: '2022-09-10 04:52:40+09:00'
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
- `using mint = atcoder::modint998244353;` などとしておき、`binomial<mint> B(1000);` とすれば $ 1000Cr (r=0,1,...,1000) $ までは計算できる
