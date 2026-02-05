---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  _extendedRequiredBy:
  - icon: ':warning:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':warning:'
    path: my_template_int128.hpp
    title: my_template_int128.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: misc/test/bit_operation.test.cpp
    title: misc/test/bit_operation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/lowbit.hpp\"\n\n#line 2 \"misc/countr_zero.hpp\"\n\n\
    #if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n// countr_zero\n// (000,\
    \ 001, 010, 011, 100) -> (32, 0, 1, 0, 2)\n#if __cplusplus >= 202002L\nusing std::countr_zero;\n\
    #else\nint countr_zero(unsigned int x) {\n    return x == 0 ? 32 : __builtin_ctz(x);\n\
    }\nint countr_zero(unsigned long long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n#endif\nint countr_zero(int x) { return countr_zero((unsigned int)(x)); }\n\
    int countr_zero(long long int x) {\n    return countr_zero((unsigned long long\
    \ int)(x));\n}\n#line 4 \"misc/lowbit.hpp\"\n\n// lowbit\n// (000, 001, 010, 011,\
    \ 100) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : countr_zero(x));\
    \ }\nint lowbit(unsigned int x) { return (x == 0 ? -1 : countr_zero(x)); }\nint\
    \ lowbit(long long int x) { return (x == 0 ? -1 : countr_zero(x)); }\nint lowbit(unsigned\
    \ long long int x) { return (x == 0 ? -1 : countr_zero(x)); }\n"
  code: '#pragma once


    #include "./countr_zero.hpp"


    // lowbit

    // (000, 001, 010, 011, 100) -> (-1, 0, 1, 0, 2)

    int lowbit(int x) { return (x == 0 ? -1 : countr_zero(x)); }

    int lowbit(unsigned int x) { return (x == 0 ? -1 : countr_zero(x)); }

    int lowbit(long long int x) { return (x == 0 ? -1 : countr_zero(x)); }

    int lowbit(unsigned long long int x) { return (x == 0 ? -1 : countr_zero(x));
    }

    '
  dependsOn:
  - misc/countr_zero.hpp
  isVerificationFile: false
  path: misc/lowbit.hpp
  requiredBy:
  - my_template_int128.hpp
  - my_template.hpp
  timestamp: '2025-12-31 07:11:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - misc/test/bit_operation.test.cpp
documentation_of: misc/lowbit.hpp
layout: document
title: Lowbit
---

## lowbit

```cpp
int lowbit(T x)
```

最下位に立っているビットの位置を返します。

$x = 0$ のときは $-1$ を返します。
