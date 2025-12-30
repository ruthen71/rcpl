---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: misc/test/bit_operation.test.cpp
    title: misc/test/bit_operation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/bit_ceil.hpp\"\n\n#include <cassert>\n\n#if __cplusplus\
    \ >= 202002L\n#include <bit>\n#endif\n\n// bit_ceil\n// (0, 1, 2, 3, 4) -> (1,\
    \ 1, 2, 4, 4)\n#if __cplusplus >= 202002L\nusing std::bit_ceil;\n#else\nunsigned\
    \ int bit_ceil(unsigned int x) {\n    unsigned int p = 1;\n    while (p < x) p\
    \ *= 2;\n    return p;\n}\nunsigned long long int bit_ceil(unsigned long long\
    \ int x) {\n    unsigned long long int p = 1;\n    while (p < x) p *= 2;\n   \
    \ return p;\n}\n#endif\nint bit_ceil(int x) {\n    assert(x >= 0);\n    return\
    \ bit_ceil((unsigned int)(x));\n}\nlong long int bit_ceil(long long int x) {\n\
    \    assert(x >= 0);\n    return bit_ceil((unsigned long long int)(x));\n}\n"
  code: "#pragma once\n\n#include <cassert>\n\n#if __cplusplus >= 202002L\n#include\
    \ <bit>\n#endif\n\n// bit_ceil\n// (0, 1, 2, 3, 4) -> (1, 1, 2, 4, 4)\n#if __cplusplus\
    \ >= 202002L\nusing std::bit_ceil;\n#else\nunsigned int bit_ceil(unsigned int\
    \ x) {\n    unsigned int p = 1;\n    while (p < x) p *= 2;\n    return p;\n}\n\
    unsigned long long int bit_ceil(unsigned long long int x) {\n    unsigned long\
    \ long int p = 1;\n    while (p < x) p *= 2;\n    return p;\n}\n#endif\nint bit_ceil(int\
    \ x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned int)(x));\n}\nlong\
    \ long int bit_ceil(long long int x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned\
    \ long long int)(x));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/bit_ceil.hpp
  requiredBy: []
  timestamp: '2025-12-31 07:11:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - misc/test/bit_operation.test.cpp
documentation_of: misc/bit_ceil.hpp
layout: document
title: Bit Ceil
---

## bit_ceil

```cpp
T bit_ceil(T x)
```

$x \leq 2^m$ となる最小の $2^m$（$m$ は $0$ 以上の整数）を返します。

$x = 0$ のときは $1$ を返します。

### 制約

- $x \geq 0$
