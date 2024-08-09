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
  bundledCode: "#line 2 \"math/binomial.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    \n// \u4E8C\u9805\u4FC2\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\ntemplate <class Mint>\
    \ struct Binomial {\n    std::vector<Mint> f, g, h;\n\n    Binomial(const int\
    \ n_max = 0) {\n        f.resize(1, Mint(1));\n        g.resize(1, Mint(1));\n\
    \        h.resize(1, Mint(1));\n        if (n_max > 0) extend(n_max);\n    }\n\
    \n    // \u57FA\u672C\u306F\u9577\u3055\u3092\u500D\u306B\u3059\u308B\n    void\
    \ extend(int m = -1) {\n        const int n = (int)(f.size());  // n >= 1\n  \
    \      if (m == -1) m = n * 2;         // m >= 2\n        m = std::min(m, Mint::mod());\n\
    \        if (n >= m) return;\n        f.resize(m);\n        g.resize(m);\n   \
    \     h.resize(m);\n        // calc f\n        for (int i = n; i < m; i++) f[i]\
    \ = f[i - 1] * Mint(i);\n        // calc g\n        g[m - 1] = 1 / f[m - 1];\n\
    \        for (int i = m - 2; i >= n; i--) g[i] = g[i + 1] * Mint(i + 1);\n   \
    \     // calc h\n        h[m - 1] = g[m - 1] * f[m - 2];\n        for (int i =\
    \ m - 2; i >= n; i--) h[i] = g[i] * f[i - 1];\n    }\n\n    // fact(n) = n!\n\
    \    Mint fact(const int n) {\n        if (n < 0) return Mint(0);\n        while\
    \ (n >= (int)(f.size())) extend();\n        return f[n];\n    }\n\n    // finv(n)\
    \ = 1 / n!\n    Mint finv(const int n) {\n        if (n < 0) return Mint(0);\n\
    \        while (n >= (int)(g.size())) extend();\n        return g[n];\n    }\n\
    \n    // inv(n) = 1 / n\n    Mint inv(const int n) {\n        if (n < 0) return\
    \ Mint(0);\n        while (n >= (int)(h.size())) extend();\n    }\n\n    // n\
    \ C k\n    Mint C(const int n, const int k) {\n        if (n < 0 or k < 0 or n\
    \ < k) return Mint(0);\n        return fact(n) * finv(n - k) * finv(k);\n    }\n\
    \n    // n P k\n    Mint P(const int n, const int k) {\n        if (n < 0 or k\
    \ < 0 or n < k) return Mint(0);\n        return fact(n) * finv(n - k);\n    }\n\
    \n    // n H k\n    // n \u500B\u304B\u3089 k \u500B\u91CD\u8907\u3092\u8A31\u3057\
    \u3066\u53D6\u308B\u7D44\u5408\u305B\n    Mint H(const int n, const int k) {\n\
    \        if (n < 0 or k < 0) return Mint(0);\n        if (k == 0) return Mint(1);\n\
    \        return C(n + k - 1, k);\n    }\n\n    Mint C_naive(int n, int k) {\n\
    \        if (n < 0 or k < 0 or n < k) return Mint(0);\n        Mint res = Mint(1),\
    \ res_inv = Mint(1);\n        k = std::min(k, n - k);\n        for (int i = 1;\
    \ i <= k; i++) {\n            res *= (n--);\n            res_inv *= i;\n     \
    \   }\n        res /= res_inv;\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\n// \u4E8C\u9805\
    \u4FC2\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\ntemplate <class Mint> struct Binomial\
    \ {\n    std::vector<Mint> f, g, h;\n\n    Binomial(const int n_max = 0) {\n \
    \       f.resize(1, Mint(1));\n        g.resize(1, Mint(1));\n        h.resize(1,\
    \ Mint(1));\n        if (n_max > 0) extend(n_max);\n    }\n\n    // \u57FA\u672C\
    \u306F\u9577\u3055\u3092\u500D\u306B\u3059\u308B\n    void extend(int m = -1)\
    \ {\n        const int n = (int)(f.size());  // n >= 1\n        if (m == -1) m\
    \ = n * 2;         // m >= 2\n        m = std::min(m, Mint::mod());\n        if\
    \ (n >= m) return;\n        f.resize(m);\n        g.resize(m);\n        h.resize(m);\n\
    \        // calc f\n        for (int i = n; i < m; i++) f[i] = f[i - 1] * Mint(i);\n\
    \        // calc g\n        g[m - 1] = 1 / f[m - 1];\n        for (int i = m -\
    \ 2; i >= n; i--) g[i] = g[i + 1] * Mint(i + 1);\n        // calc h\n        h[m\
    \ - 1] = g[m - 1] * f[m - 2];\n        for (int i = m - 2; i >= n; i--) h[i] =\
    \ g[i] * f[i - 1];\n    }\n\n    // fact(n) = n!\n    Mint fact(const int n) {\n\
    \        if (n < 0) return Mint(0);\n        while (n >= (int)(f.size())) extend();\n\
    \        return f[n];\n    }\n\n    // finv(n) = 1 / n!\n    Mint finv(const int\
    \ n) {\n        if (n < 0) return Mint(0);\n        while (n >= (int)(g.size()))\
    \ extend();\n        return g[n];\n    }\n\n    // inv(n) = 1 / n\n    Mint inv(const\
    \ int n) {\n        if (n < 0) return Mint(0);\n        while (n >= (int)(h.size()))\
    \ extend();\n    }\n\n    // n C k\n    Mint C(const int n, const int k) {\n \
    \       if (n < 0 or k < 0 or n < k) return Mint(0);\n        return fact(n) *\
    \ finv(n - k) * finv(k);\n    }\n\n    // n P k\n    Mint P(const int n, const\
    \ int k) {\n        if (n < 0 or k < 0 or n < k) return Mint(0);\n        return\
    \ fact(n) * finv(n - k);\n    }\n\n    // n H k\n    // n \u500B\u304B\u3089 k\
    \ \u500B\u91CD\u8907\u3092\u8A31\u3057\u3066\u53D6\u308B\u7D44\u5408\u305B\n \
    \   Mint H(const int n, const int k) {\n        if (n < 0 or k < 0) return Mint(0);\n\
    \        if (k == 0) return Mint(1);\n        return C(n + k - 1, k);\n    }\n\
    \n    Mint C_naive(int n, int k) {\n        if (n < 0 or k < 0 or n < k) return\
    \ Mint(0);\n        Mint res = Mint(1), res_inv = Mint(1);\n        k = std::min(k,\
    \ n - k);\n        for (int i = 1; i <= k; i++) {\n            res *= (n--);\n\
    \            res_inv *= i;\n        }\n        res /= res_inv;\n        return\
    \ res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial.hpp
  requiredBy: []
  timestamp: '2024-08-10 00:43:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/binomial.hpp
layout: document
title: "Binomial (\u4E8C\u9805\u4FC2\u6570\u30E9\u30A4\u30D6\u30E9\u30EA)"
---

## 使い方

配列サイズを指定しなくても勝手に拡張する

```cpp
using mint = mint998;
Binomial<mint> B;
```

## 参考文献
