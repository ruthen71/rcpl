---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: enumerate/test/enumerate_product.test.cpp
    title: enumerate/test/enumerate_product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"enumerate/enumerate_product.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n// enumerate product\n// enumerate p (0 <= p[i] < a[i])\n\
    template <class F> void enumerate_product(std::vector<int> a, F f) {\n    const\
    \ int n = (int)(a.size());\n    std::vector<int> p;\n    auto dfs = [&](auto g,\
    \ int i) -> void {\n        if (i == n) {\n            f(p);\n            return;\n\
    \        }\n        for (int x = 0; x < a[i]; x++) {\n            p.push_back(x);\n\
    \            g(g, i + 1);\n            p.pop_back();\n        }\n    };\n    dfs(dfs,\
    \ 0);\n    return;\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n// enumerate product\n\
    // enumerate p (0 <= p[i] < a[i])\ntemplate <class F> void enumerate_product(std::vector<int>\
    \ a, F f) {\n    const int n = (int)(a.size());\n    std::vector<int> p;\n   \
    \ auto dfs = [&](auto g, int i) -> void {\n        if (i == n) {\n           \
    \ f(p);\n            return;\n        }\n        for (int x = 0; x < a[i]; x++)\
    \ {\n            p.push_back(x);\n            g(g, i + 1);\n            p.pop_back();\n\
    \        }\n    };\n    dfs(dfs, 0);\n    return;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_product.hpp
  requiredBy: []
  timestamp: '2026-04-11 01:00:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - enumerate/test/enumerate_product.test.cpp
documentation_of: enumerate/enumerate_product.hpp
layout: document
title: "$ 0 \\leq p_{i} < a_{i} $ \u3092\u6E80\u305F\u3059\u6574\u6570\u5217 $p$ \u306E\
  \u5217\u6319"
---

## enumerate_product

```cpp
void enumerate_product(std::vector<int> a, F f)
```

長さ $n$ の整数列 $a$ と `std::vector<int>` を引数にとる関数オブジェクト $f$ が与えられたとき、 $ i = 0, ..., n - 1 $ について $ 0 \leq p_{i} < a_{i} $ を満たす整数列 $p$ を列挙し、それぞれの $p$ に対して $ f(p) $ を実行します。


例えば $p$ を `std::vector<std::vector<int>>` に格納する場合、$f$ は以下のようになります。

```cpp
auto f = [&](std::vector<int> p) -> void {
    ps.push_back(p);
    return;
};
```

### 制約

- $a_{i}$ は `int` 型で表現可能

### 計算量

$f$ が定数時間で計算できると仮定したとき

- $ O \left( \prod_{i=0}^{n-1} a_{i} \right) $

$f$ の計算は多くの場合において $O(n)$ 以上必要です。
