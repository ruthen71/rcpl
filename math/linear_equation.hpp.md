---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/gauss_jordan_elimination.hpp
    title: "Gauss-Jordan elimination (\u30AC\u30A6\u30B9\u30B8\u30E7\u30EB\u30C0\u30F3\
      \u306E\u6383\u304D\u51FA\u3057\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/linear_equation.hpp\"\n\n#line 2 \"math/gauss_jordan_elimination.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\n// \u884C\u5217 a \u3092\u6383\u304D\
    \u51FA\u3057, \u30E9\u30F3\u30AF\u3092\u8FD4\u3059\ntemplate <class T> int gauss_jordan_elimination(std::vector<std::vector<T>>&\
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
    \    return rank;\n}\n#line 4 \"math/linear_equation.hpp\"\n\n#line 6 \"math/linear_equation.hpp\"\
    \n#include <utility>\n#line 8 \"math/linear_equation.hpp\"\n\n// \u7DDA\u5F62\u65B9\
    \u7A0B\u5F0F Ax = b \u3092\u89E3\u304F\n// {rank, x} \u3092\u8FD4\u3059\ntemplate\
    \ <class T> std::pair<int, std::vector<T>> linear_equation(const std::vector<std::vector<T>>&\
    \ A, const std::vector<T>& b) {\n    assert(A.size() > 0);\n    const int m =\
    \ (int)(A.size()), n = (int)(A[0].size());\n    std::vector M(m, std::vector<T>(n\
    \ + 1));\n    for (int i = 0; i < m; i++) {\n        for (int j = 0; j < n; j++)\
    \ {\n            M[i][j] = A[i][j];\n        }\n        M[i][n] = b[i];\n    }\n\
    \    int rank = gauss_jordan_elimination(M, n);\n    show(M);\n\n    // \u89E3\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408, rank = -1 \u3092\u8FD4\u3059\
    \n    for (int i = rank; i < m; i++) {\n        if (M[i][n] != T(0)) {\n     \
    \       return {-1, {}};\n        }\n    }\n    std::vector<T> x(n);\n    for\
    \ (int i = 0; i < rank; i++) x[i] = M[i][n];\n    return {rank, x};\n}\n"
  code: "#pragma once\n\n#include \"math/gauss_jordan_elimination.hpp\"\n\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\n// \u7DDA\u5F62\u65B9\u7A0B\
    \u5F0F Ax = b \u3092\u89E3\u304F\n// {rank, x} \u3092\u8FD4\u3059\ntemplate <class\
    \ T> std::pair<int, std::vector<T>> linear_equation(const std::vector<std::vector<T>>&\
    \ A, const std::vector<T>& b) {\n    assert(A.size() > 0);\n    const int m =\
    \ (int)(A.size()), n = (int)(A[0].size());\n    std::vector M(m, std::vector<T>(n\
    \ + 1));\n    for (int i = 0; i < m; i++) {\n        for (int j = 0; j < n; j++)\
    \ {\n            M[i][j] = A[i][j];\n        }\n        M[i][n] = b[i];\n    }\n\
    \    int rank = gauss_jordan_elimination(M, n);\n    show(M);\n\n    // \u89E3\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408, rank = -1 \u3092\u8FD4\u3059\
    \n    for (int i = rank; i < m; i++) {\n        if (M[i][n] != T(0)) {\n     \
    \       return {-1, {}};\n        }\n    }\n    std::vector<T> x(n);\n    for\
    \ (int i = 0; i < rank; i++) x[i] = M[i][n];\n    return {rank, x};\n}"
  dependsOn:
  - math/gauss_jordan_elimination.hpp
  isVerificationFile: false
  path: math/linear_equation.hpp
  requiredBy: []
  timestamp: '2026-04-11 01:01:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear_equation.hpp
layout: document
title: "Linear Equation (\u7DDA\u5F62\u65B9\u7A0B\u5F0F)"
---

## 使い方


```cpp
// 線形方程式 Ax = b を解き, {rank, x} を返す
auto [rank, x] = linear_equation(A, b);
```

## 参考文献

- [けんちょんの競プロ精進記録, Gauss-Jordan の掃き出し法と、連立一次方程式の解き方](https://drken1215.hatenablog.com/entry/2019/03/20/202800)
- [競プロ典型 90 問 057 - Flip Flap（★6）](https://atcoder.jp/contests/typical90/tasks/typical90_be)
