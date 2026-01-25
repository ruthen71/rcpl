---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  - icon: ':question:'
    path: misc/topbit.hpp
    title: Topbit
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: random/test/base.test.cpp
    title: random/test/base.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - http://xorshift.di.unimi.it/splitmix64.c
  bundledCode: "#line 2 \"random/base.hpp\"\n\n#include <cassert>\n#include <chrono>\n\
    #include <cstdint>\n\n#line 2 \"misc/topbit.hpp\"\n\n#line 2 \"misc/countl_zero.hpp\"\
    \n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n// countl_zero\n// (000,\
    \ 001, 010, 011, 100) -> (32, 31, 30, 30, 29)\n#if __cplusplus >= 202002L\nusing\
    \ std::countl_zero;\n#else\nint countl_zero(unsigned int x) {\n    return x ==\
    \ 0 ? 32 : __builtin_clz(x);\n}\nint countl_zero(unsigned long long int x) {\n\
    \    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#endif\nint countl_zero(int\
    \ x) { return countl_zero((unsigned int)(x)); }\nint countl_zero(long long int\
    \ x) {\n    return countl_zero((unsigned long long int)(x));\n}\n#line 4 \"misc/topbit.hpp\"\
    \n\n// topbit\n// (000, 001, 010, 011, 100) -> (-1, 0, 1, 1, 2)\nint topbit(int\
    \ x) { return 31 - countl_zero(x); }\nint topbit(unsigned int x) { return 31 -\
    \ countl_zero(x); }\nint topbit(long long int x) { return 63 - countl_zero(x);\
    \ }\nint topbit(unsigned long long int x) { return 63 - countl_zero(x); }\n#line\
    \ 8 \"random/base.hpp\"\n\ntemplate <bool auto_seed> struct Random {\n    uint64_t\
    \ x_seed;\n\n    Random(uint64_t seed = 0) {\n        if (auto_seed) {\n     \
    \       // set random seed\n            assert(seed == 0);\n            x_seed\
    \ =\n                std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        } else {\n            // set seed\n            x_seed = seed;\n     \
    \   }\n    }\n\n    // http://xorshift.di.unimi.it/splitmix64.c\n    // [0, 2^64\
    \ - 1]\n    uint64_t rand_int() {\n        uint64_t z = (x_seed += 0x9e3779b97f4a7c15);\n\
    \        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;\n        z = (z ^ (z >> 27))\
    \ * 0x94d049bb133111eb;\n        return z ^ (z >> 31);\n    }\n\n    // [0, mod\
    \ - 1]\n    // rand_int() % mod \u3060\u3068 mod \u304C 2 \u3079\u304D\u3067\u306A\
    \u3044\u3068\u304D\u306B\u504F\u308B\n    uint64_t rand_int(uint64_t mod) {\n\
    \        assert(mod > 0);\n        if ((mod & (mod - 1)) == 0) {\n           \
    \ // mod = 2^p\n            // (mod - 1) = 0...01...1\n            return rand_int()\
    \ & (mod - 1);\n        }\n        // mod >= 3 (1 = 2^0, 2 = 2^1)\n        int\
    \ lg = topbit((uint64_t)mod);\n        uint64_t mask = (lg == 63) ? ~0ULL : (1ULL\
    \ << (lg + 1)) - 1;\n        while (true) {\n            uint64_t r = rand_int()\
    \ & mask;\n            if (r < mod) return r;\n        }\n    }\n\n    // [l,\
    \ r]\n    template <class T> T rand_int(T l, T r) {\n        assert(l <= r);\n\
    \        return T(l + rand_int(uint64_t(r - l + 1)));\n    }\n\n    // [0.0, 1.0]\n\
    \    double rand_double() {\n        uint64_t v = rand_int(1ULL << 63);\n    \
    \    return double(v) / ((1ULL << 63) - 1);\n    }\n\n    // [l, r]\n    double\
    \ rand_double(double l, double r) {\n        assert(l <= r);\n        return l\
    \ + rand_double() * (r - l);\n    }\n};\n\nusing RandomFixed = Random<false>;\n\
    using RandomAuto = Random<true>;\n\nRandomAuto rng_auto;\n"
  code: "#pragma once\n\n#include <cassert>\n#include <chrono>\n#include <cstdint>\n\
    \n#include \"../misc/topbit.hpp\"\n\ntemplate <bool auto_seed> struct Random {\n\
    \    uint64_t x_seed;\n\n    Random(uint64_t seed = 0) {\n        if (auto_seed)\
    \ {\n            // set random seed\n            assert(seed == 0);\n        \
    \    x_seed =\n                std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        } else {\n            // set seed\n            x_seed = seed;\n     \
    \   }\n    }\n\n    // http://xorshift.di.unimi.it/splitmix64.c\n    // [0, 2^64\
    \ - 1]\n    uint64_t rand_int() {\n        uint64_t z = (x_seed += 0x9e3779b97f4a7c15);\n\
    \        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;\n        z = (z ^ (z >> 27))\
    \ * 0x94d049bb133111eb;\n        return z ^ (z >> 31);\n    }\n\n    // [0, mod\
    \ - 1]\n    // rand_int() % mod \u3060\u3068 mod \u304C 2 \u3079\u304D\u3067\u306A\
    \u3044\u3068\u304D\u306B\u504F\u308B\n    uint64_t rand_int(uint64_t mod) {\n\
    \        assert(mod > 0);\n        if ((mod & (mod - 1)) == 0) {\n           \
    \ // mod = 2^p\n            // (mod - 1) = 0...01...1\n            return rand_int()\
    \ & (mod - 1);\n        }\n        // mod >= 3 (1 = 2^0, 2 = 2^1)\n        int\
    \ lg = topbit((uint64_t)mod);\n        uint64_t mask = (lg == 63) ? ~0ULL : (1ULL\
    \ << (lg + 1)) - 1;\n        while (true) {\n            uint64_t r = rand_int()\
    \ & mask;\n            if (r < mod) return r;\n        }\n    }\n\n    // [l,\
    \ r]\n    template <class T> T rand_int(T l, T r) {\n        assert(l <= r);\n\
    \        return T(l + rand_int(uint64_t(r - l + 1)));\n    }\n\n    // [0.0, 1.0]\n\
    \    double rand_double() {\n        uint64_t v = rand_int(1ULL << 63);\n    \
    \    return double(v) / ((1ULL << 63) - 1);\n    }\n\n    // [l, r]\n    double\
    \ rand_double(double l, double r) {\n        assert(l <= r);\n        return l\
    \ + rand_double() * (r - l);\n    }\n};\n\nusing RandomFixed = Random<false>;\n\
    using RandomAuto = Random<true>;\n\nRandomAuto rng_auto;\n"
  dependsOn:
  - misc/topbit.hpp
  - misc/countl_zero.hpp
  isVerificationFile: false
  path: random/base.hpp
  requiredBy: []
  timestamp: '2026-01-26 01:08:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - random/test/base.test.cpp
documentation_of: random/base.hpp
layout: document
title: Random
---

乱数生成用のライブラリです。
`random/` 以下の他のライブラリなどで利用できるように `RandomAuto rng_auto` が定義されています。
また、固定シードと実行時シードを切り替えることができます。

## コンストラクタ

```cpp
(1) RandomFixed rng(uint64_t seed = 0)
(2) RandomAuto rng()
```

(1)

乱数のシード値は `seed` で初期化されます。

(2)

乱数のシード値は実行時刻をもとに初期化されます。

## rand_int

```cpp
(1) uint64_t rng.rand_int()
(2) uint64_t rng.rand_int(uint64_t mod)
(3) template <class T> T rng.rand_int(T l, T r)
```

(1)

$[0, 2^{64} - 1]$ の一様乱数（整数）を返します。

(2)

$[0, \bmod - 1]$ の一様乱数（整数）を返します。

(3)

$[l, r]$ の一様乱数（整数）を返します。

### 制約

(2)
- $\bmod > 0$

(3)
- $l \leq r$
- $r - l + 1$ が型 `T` でオーバーフローしない

## rand_double

```cpp
double rng.rand_double()
double rng.rand_double(double l, double r)
```

(1)

$[0.0, 1.0]$ の一様乱数（浮動小数点数）を返します。

(2)

$[l, r]$ の一様乱数（浮動小数点数）を返します。

### 制約

(2)
- $l \leq r$
