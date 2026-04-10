---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/linear_equation.hpp
    title: "Linear Equation (\u7DDA\u5F62\u65B9\u7A0B\u5F0F)"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/gauss_jordan_elimination.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n// \u884C\u5217 a \u3092\u6383\u304D\u51FA\u3057, \u30E9\u30F3\
    \u30AF\u3092\u8FD4\u3059\ntemplate <class T> int gauss_jordan_elimination(std::vector<std::vector<T>>&\
    \ a, int pivot_end = -1) {\n    assert(a.size() > 0);\n    const int h = (int)(a.size()),\
    \ w = (int)(a[0].size());\n    int rank = 0;\n    if (pivot_end == -1) pivot_end\
    \ = w;\n\n    for (int j = 0; j < pivot_end; j++) {\n        // \u30D4\u30DC\u30C3\
    \u30C8\u3092\u63A2\u3059\n        int pivot = -1;\n        for (int i = rank;\
    \ i < h; i++) {\n            if (a[i][j] != T(0)) {\n                pivot = i;\n\
    \                break;\n            }\n        }\n        if (pivot == -1) continue;\n\
    \n        std::swap(a[pivot], a[rank]);\n\n        // a[rank][j] = 1 \u306B\u306A\
    \u308B\u3088\u3046\u306B a[rank] \u3092\u5B9A\u6570\u500D\n        const T inv\
    \ = T(1) / a[rank][j];\n        for (int j2 = 0; j2 < w; j2++) a[rank][j2] *=\
    \ inv;\n\n        // a[rank] \u3092\u4F7F\u3063\u3066\u4ED6\u306E\u884C\u3092\u6383\
    \u304D\u51FA\u3059\n        for (int i = 0; i < h; i++) {\n            if (i !=\
    \ rank and a[i][j] != T(0)) {\n                const T fac = a[i][j];  // a[rank]\
    \ \u3092 fac \u500D\u3057\u3066 a[i] \u304B\u3089\u5F15\u304F\n              \
    \  for (int j2 = 0; j2 < w; j2++) {\n                    a[i][j2] -= a[rank][j2]\
    \ * fac;\n                }\n            }\n        }\n        rank++;\n    }\n\
    \    return rank;\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n// \u884C\u5217\
    \ a \u3092\u6383\u304D\u51FA\u3057, \u30E9\u30F3\u30AF\u3092\u8FD4\u3059\ntemplate\
    \ <class T> int gauss_jordan_elimination(std::vector<std::vector<T>>& a, int pivot_end\
    \ = -1) {\n    assert(a.size() > 0);\n    const int h = (int)(a.size()), w = (int)(a[0].size());\n\
    \    int rank = 0;\n    if (pivot_end == -1) pivot_end = w;\n\n    for (int j\
    \ = 0; j < pivot_end; j++) {\n        // \u30D4\u30DC\u30C3\u30C8\u3092\u63A2\u3059\
    \n        int pivot = -1;\n        for (int i = rank; i < h; i++) {\n        \
    \    if (a[i][j] != T(0)) {\n                pivot = i;\n                break;\n\
    \            }\n        }\n        if (pivot == -1) continue;\n\n        std::swap(a[pivot],\
    \ a[rank]);\n\n        // a[rank][j] = 1 \u306B\u306A\u308B\u3088\u3046\u306B\
    \ a[rank] \u3092\u5B9A\u6570\u500D\n        const T inv = T(1) / a[rank][j];\n\
    \        for (int j2 = 0; j2 < w; j2++) a[rank][j2] *= inv;\n\n        // a[rank]\
    \ \u3092\u4F7F\u3063\u3066\u4ED6\u306E\u884C\u3092\u6383\u304D\u51FA\u3059\n \
    \       for (int i = 0; i < h; i++) {\n            if (i != rank and a[i][j] !=\
    \ T(0)) {\n                const T fac = a[i][j];  // a[rank] \u3092 fac \u500D\
    \u3057\u3066 a[i] \u304B\u3089\u5F15\u304F\n                for (int j2 = 0; j2\
    \ < w; j2++) {\n                    a[i][j2] -= a[rank][j2] * fac;\n         \
    \       }\n            }\n        }\n        rank++;\n    }\n    return rank;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/gauss_jordan_elimination.hpp
  requiredBy:
  - math/linear_equation.hpp
  timestamp: '2026-04-11 01:01:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gauss_jordan_elimination.hpp
layout: document
title: "Gauss-Jordan elimination (\u30AC\u30A6\u30B9\u30B8\u30E7\u30EB\u30C0\u30F3\
  \u306E\u6383\u304D\u51FA\u3057\u6CD5)"
---

## 使い方


```cpp
std::vector A(n, std::vector<T>(m));    // n x m 行列
int rank = gauss_jordan_elimination(A, m)   // 0 ~ m - 1 列目を掃き出す
```

## 参考文献

- [けんちょんの競プロ精進記録, Gauss-Jordan の掃き出し法と、連立一次方程式の解き方](https://drken1215.hatenablog.com/entry/2019/03/20/202800)
