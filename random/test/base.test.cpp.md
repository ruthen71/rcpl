---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  - icon: ':question:'
    path: misc/topbit.hpp
    title: Topbit
  - icon: ':x:'
    path: random/base.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"random/test/base.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#include <cassert>\n#include <cstdint>\n#include <iostream>\n#include <vector>\n\
    \n#line 2 \"random/base.hpp\"\n\n#line 4 \"random/base.hpp\"\n#include <chrono>\n\
    #line 6 \"random/base.hpp\"\n\n#line 2 \"misc/topbit.hpp\"\n\n#line 2 \"misc/countl_zero.hpp\"\
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
    \ lg = topbit(mod);\n        uint64_t mask = (lg == 63) ? ~0ULL : (1ULL << (lg\
    \ + 1)) - 1;\n        while (true) {\n            uint64_t r = rand_int() & mask;\n\
    \            if (r < mod) return r;\n        }\n    }\n\n    // [l, r]\n    template\
    \ <class T> T rand_int(T l, T r) {\n        assert(l <= r);\n        return T(l\
    \ + rand_int(uint64_t(r - l + 1)));\n    }\n\n    // [0.0, 1.0]\n    double rand_double()\
    \ {\n        uint64_t v = rand_int(1ULL << 63);\n        return double(v) / ((1ULL\
    \ << 63) - 1);\n    }\n\n    // [l, r]\n    double rand_double(double l, double\
    \ r) {\n        assert(l <= r);\n        return l + rand_double() * (r - l);\n\
    \    }\n};\n\nusing RandomFixed = Random<false>;\nusing RandomAuto = Random<true>;\n\
    \nRandomAuto rng_auto;\n#line 9 \"random/test/base.test.cpp\"\n\nvoid test1_same_seed()\
    \ {\n    for (int seed = 0; seed < 10; seed++) {\n        RandomFixed rng_a(seed);\n\
    \        RandomFixed rng_b(seed);\n        std::vector<uint64_t> a(10), b(10);\n\
    \        for (int i = 0; i < 10; i++) {\n            a[i] = rng_a.rand_int();\n\
    \            b[i] = rng_b.rand_int();\n        }\n        assert(a == b);\n  \
    \  }\n}\n\nvoid test2_different_seed() {\n    for (int seed = 0; seed < 10; seed++)\
    \ {\n        RandomFixed rng_a(seed);\n        RandomFixed rng_b(seed + 1);\n\
    \        std::vector<uint64_t> a(10), b(10);\n        for (int i = 0; i < 10;\
    \ i++) {\n            a[i] = rng_a.rand_int();\n            b[i] = rng_b.rand_int();\n\
    \        }\n        assert(a != b);\n    }\n}\n\nvoid test3_auto_seed() {\n  \
    \  RandomAuto rng_a;\n    RandomFixed rng_b(0);\n    std::vector<uint64_t> a(10),\
    \ b(10);\n    for (int i = 0; i < 10; i++) {\n        a[i] = rng_a.rand_int();\n\
    \        b[i] = rng_b.rand_int();\n    }\n    assert(a != b);\n}\n\nvoid test4_negative()\
    \ {\n    RandomAuto rng;\n    auto v = rng.rand_int(-100, -1);\n    assert(-100\
    \ <= v and v <= -1);\n}\n\nvoid test5_big() {\n    RandomAuto rng;\n    const\
    \ int BIG_INT = 1000000000;\n    auto v = rng.rand_int(-BIG_INT, BIG_INT);\n \
    \   assert(-BIG_INT <= v and v <= BIG_INT);\n}\n\nvoid test6_double() {\n    RandomAuto\
    \ rng;\n    auto v = rng.rand_double();\n    assert(0.0 <= v and v <= 1.0);\n\
    \    auto v2 = rng.rand_double(-100.0, -1.0);\n    assert(-100.0 <= v2 and v2\
    \ <= -1.0);\n}\n\nint main() {\n    test1_same_seed();\n    test2_different_seed();\n\
    \    test3_auto_seed();\n    test4_negative();\n    test5_big();\n    test6_double();\n\
    \    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <cassert>\n\
    #include <cstdint>\n#include <iostream>\n#include <vector>\n\n#include \"../base.hpp\"\
    \n\nvoid test1_same_seed() {\n    for (int seed = 0; seed < 10; seed++) {\n  \
    \      RandomFixed rng_a(seed);\n        RandomFixed rng_b(seed);\n        std::vector<uint64_t>\
    \ a(10), b(10);\n        for (int i = 0; i < 10; i++) {\n            a[i] = rng_a.rand_int();\n\
    \            b[i] = rng_b.rand_int();\n        }\n        assert(a == b);\n  \
    \  }\n}\n\nvoid test2_different_seed() {\n    for (int seed = 0; seed < 10; seed++)\
    \ {\n        RandomFixed rng_a(seed);\n        RandomFixed rng_b(seed + 1);\n\
    \        std::vector<uint64_t> a(10), b(10);\n        for (int i = 0; i < 10;\
    \ i++) {\n            a[i] = rng_a.rand_int();\n            b[i] = rng_b.rand_int();\n\
    \        }\n        assert(a != b);\n    }\n}\n\nvoid test3_auto_seed() {\n  \
    \  RandomAuto rng_a;\n    RandomFixed rng_b(0);\n    std::vector<uint64_t> a(10),\
    \ b(10);\n    for (int i = 0; i < 10; i++) {\n        a[i] = rng_a.rand_int();\n\
    \        b[i] = rng_b.rand_int();\n    }\n    assert(a != b);\n}\n\nvoid test4_negative()\
    \ {\n    RandomAuto rng;\n    auto v = rng.rand_int(-100, -1);\n    assert(-100\
    \ <= v and v <= -1);\n}\n\nvoid test5_big() {\n    RandomAuto rng;\n    const\
    \ int BIG_INT = 1000000000;\n    auto v = rng.rand_int(-BIG_INT, BIG_INT);\n \
    \   assert(-BIG_INT <= v and v <= BIG_INT);\n}\n\nvoid test6_double() {\n    RandomAuto\
    \ rng;\n    auto v = rng.rand_double();\n    assert(0.0 <= v and v <= 1.0);\n\
    \    auto v2 = rng.rand_double(-100.0, -1.0);\n    assert(-100.0 <= v2 and v2\
    \ <= -1.0);\n}\n\nint main() {\n    test1_same_seed();\n    test2_different_seed();\n\
    \    test3_auto_seed();\n    test4_negative();\n    test5_big();\n    test6_double();\n\
    \    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n  \
    \  return 0;\n}\n"
  dependsOn:
  - random/base.hpp
  - misc/topbit.hpp
  - misc/countl_zero.hpp
  isVerificationFile: true
  path: random/test/base.test.cpp
  requiredBy: []
  timestamp: '2026-01-26 00:49:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: random/test/base.test.cpp
layout: document
redirect_from:
- /verify/random/test/base.test.cpp
- /verify/random/test/base.test.cpp.html
title: random/test/base.test.cpp
---
