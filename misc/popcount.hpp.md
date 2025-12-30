---
data:
  _extendedDependsOn: []
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
  bundledCode: '#line 2 "misc/popcount.hpp"


    #if __cplusplus >= 202002L

    #include <bit>

    #endif


    // popcount

    // (000, 001, 010, 011, 100) -> (0, 1, 1, 2, 1)

    #if __cplusplus >= 202002L

    using std::popcount;

    #else

    int popcount(unsigned int x) { return __builtin_popcount(x); }

    int popcount(unsigned long long int x) { return __builtin_popcountll(x); }

    #endif

    int popcount(int x) { return popcount((unsigned int)(x)); }

    int popcount(long long int x) { return popcount((unsigned long long int)(x));
    }

    '
  code: '#pragma once


    #if __cplusplus >= 202002L

    #include <bit>

    #endif


    // popcount

    // (000, 001, 010, 011, 100) -> (0, 1, 1, 2, 1)

    #if __cplusplus >= 202002L

    using std::popcount;

    #else

    int popcount(unsigned int x) { return __builtin_popcount(x); }

    int popcount(unsigned long long int x) { return __builtin_popcountll(x); }

    #endif

    int popcount(int x) { return popcount((unsigned int)(x)); }

    int popcount(long long int x) { return popcount((unsigned long long int)(x));
    }

    '
  dependsOn: []
  isVerificationFile: false
  path: misc/popcount.hpp
  requiredBy:
  - my_template_int128.hpp
  - my_template.hpp
  timestamp: '2025-12-31 07:11:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - misc/test/bit_operation.test.cpp
documentation_of: misc/popcount.hpp
layout: document
title: Popcount
---

## popcount

```cpp
int popcount(T x)
```

立っているビットの個数を返します。
