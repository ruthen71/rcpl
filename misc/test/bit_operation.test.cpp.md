---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
  - icon: ':question:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  - icon: ':question:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  - icon: ':heavy_check_mark:'
    path: misc/lowbit.hpp
    title: Lowbit
  - icon: ':heavy_check_mark:'
    path: misc/popcount.hpp
    title: Popcount
  - icon: ':question:'
    path: misc/topbit.hpp
    title: Topbit
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"misc/test/bit_operation.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#include <array>\n#include <cassert>\n#include <iostream>\n\n#line 2 \"misc/bit_ceil.hpp\"\
    \n\n#line 4 \"misc/bit_ceil.hpp\"\n\n#if __cplusplus >= 202002L\n#include <bit>\n\
    #endif\n\n// bit_ceil\n// (0, 1, 2, 3, 4) -> (1, 1, 2, 4, 4)\n#if __cplusplus\
    \ >= 202002L\nusing std::bit_ceil;\n#else\nunsigned int bit_ceil(unsigned int\
    \ x) {\n    unsigned int p = 1;\n    while (p < x) p *= 2;\n    return p;\n}\n\
    unsigned long long int bit_ceil(unsigned long long int x) {\n    unsigned long\
    \ long int p = 1;\n    while (p < x) p *= 2;\n    return p;\n}\n#endif\nint bit_ceil(int\
    \ x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned int)(x));\n}\nlong\
    \ long int bit_ceil(long long int x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned\
    \ long long int)(x));\n}\n#line 2 \"misc/countl_zero.hpp\"\n\n#if __cplusplus\
    \ >= 202002L\n#include <bit>\n#endif\n\n// countl_zero\n// (000, 001, 010, 011,\
    \ 100) -> (32, 31, 30, 30, 29)\n#if __cplusplus >= 202002L\nusing std::countl_zero;\n\
    #else\nint countl_zero(unsigned int x) {\n    return x == 0 ? 32 : __builtin_clz(x);\n\
    }\nint countl_zero(unsigned long long int x) {\n    return x == 0 ? 64 : __builtin_clzll(x);\n\
    }\n#endif\nint countl_zero(int x) { return countl_zero((unsigned int)(x)); }\n\
    int countl_zero(long long int x) {\n    return countl_zero((unsigned long long\
    \ int)(x));\n}\n#line 2 \"misc/countr_zero.hpp\"\n\n#if __cplusplus >= 202002L\n\
    #include <bit>\n#endif\n\n// countr_zero\n// (000, 001, 010, 011, 100) -> (32,\
    \ 0, 1, 0, 2)\n#if __cplusplus >= 202002L\nusing std::countr_zero;\n#else\nint\
    \ countr_zero(unsigned int x) {\n    return x == 0 ? 32 : __builtin_ctz(x);\n\
    }\nint countr_zero(unsigned long long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n#endif\nint countr_zero(int x) { return countr_zero((unsigned int)(x)); }\n\
    int countr_zero(long long int x) {\n    return countr_zero((unsigned long long\
    \ int)(x));\n}\n#line 2 \"misc/lowbit.hpp\"\n\n#line 4 \"misc/lowbit.hpp\"\n\n\
    // lowbit\n// (000, 001, 010, 011, 100) -> (-1, 0, 1, 0, 2)\nint lowbit(int x)\
    \ { return (x == 0 ? -1 : countr_zero(x)); }\nint lowbit(unsigned int x) { return\
    \ (x == 0 ? -1 : countr_zero(x)); }\nint lowbit(long long int x) { return (x ==\
    \ 0 ? -1 : countr_zero(x)); }\nint lowbit(unsigned long long int x) { return (x\
    \ == 0 ? -1 : countr_zero(x)); }\n#line 2 \"misc/popcount.hpp\"\n\n#if __cplusplus\
    \ >= 202002L\n#include <bit>\n#endif\n\n// popcount\n// (000, 001, 010, 011, 100)\
    \ -> (0, 1, 1, 2, 1)\n#if __cplusplus >= 202002L\nusing std::popcount;\n#else\n\
    int popcount(unsigned int x) { return __builtin_popcount(x); }\nint popcount(unsigned\
    \ long long int x) { return __builtin_popcountll(x); }\n#endif\nint popcount(int\
    \ x) { return popcount((unsigned int)(x)); }\nint popcount(long long int x) {\
    \ return popcount((unsigned long long int)(x)); }\n#line 2 \"misc/topbit.hpp\"\
    \n\n#line 4 \"misc/topbit.hpp\"\n\n// topbit\n// (000, 001, 010, 011, 100) ->\
    \ (-1, 0, 1, 1, 2)\nint topbit(int x) { return 31 - countl_zero(x); }\nint topbit(unsigned\
    \ int x) { return 31 - countl_zero(x); }\nint topbit(long long int x) { return\
    \ 63 - countl_zero(x); }\nint topbit(unsigned long long int x) { return 63 - countl_zero(x);\
    \ }\n#line 13 \"misc/test/bit_operation.test.cpp\"\n\nvoid test1_bit_ceil() {\n\
    \    const std::array<int, 8> input = {0, 1, 2, 3, 4, 5, 6, 7};\n    const std::array<int,\
    \ 8> expected = {1, 1, 2, 4, 4, 8, 8, 8};\n    for (int i = 0; i < 8; i++) {\n\
    \        assert(bit_ceil(input[i]) == expected[i]);\n    }\n}\n\nvoid test2_countl_zero()\
    \ {\n    using u32 = unsigned int;\n    const std::array<u32, 8> input = {0, 1,\
    \ 2, 3, 4, 5, 6, 7};\n    const std::array<int, 8> expected = {32, 31, 30, 30,\
    \ 29, 29, 29, 29};\n    for (int i = 0; i < 8; i++) {\n        assert(countl_zero(input[i])\
    \ == expected[i]);\n    }\n}\n\nvoid test3_countr_zero() {\n    using u32 = unsigned\
    \ int;\n    const std::array<u32, 8> input = {0, 1, 2, 3, 4, 5, 6, 7};\n    const\
    \ std::array<int, 8> expected = {32, 0, 1, 0, 2, 0, 1, 0};\n    for (int i = 0;\
    \ i < 8; i++) {\n        assert(countr_zero(input[i]) == expected[i]);\n    }\n\
    }\n\nvoid test4_popcount() {\n    const std::array<int, 8> input = {0, 1, 2, 3,\
    \ 4, 5, 6, 7};\n    const std::array<int, 8> expected = {0, 1, 1, 2, 1, 2, 2,\
    \ 3};\n    for (int i = 0; i < 8; i++) {\n        assert(popcount(input[i]) ==\
    \ expected[i]);\n    }\n}\n\nvoid test5_topbit() {\n    const std::array<int,\
    \ 8> input = {0, 1, 2, 3, 4, 5, 6, 7};\n    const std::array<int, 8> expected\
    \ = {-1, 0, 1, 1, 2, 2, 2, 2};\n    for (int i = 0; i < 8; i++) {\n        assert(topbit(input[i])\
    \ == expected[i]);\n    }\n}\n\nvoid test6_lowbit() {\n    const std::array<int,\
    \ 8> input = {0, 1, 2, 3, 4, 5, 6, 7};\n    const std::array<int, 8> expected\
    \ = {-1, 0, 1, 0, 2, 0, 1, 0};\n    for (int i = 0; i < 8; i++) {\n        assert(lowbit(input[i])\
    \ == expected[i]);\n    }\n}\n\nint main() {\n    test1_bit_ceil();\n    test2_countl_zero();\n\
    \    test3_countr_zero();\n    test4_popcount();\n    test5_topbit();\n    test6_lowbit();\n\
    \    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <array>\n\
    #include <cassert>\n#include <iostream>\n\n#include \"../bit_ceil.hpp\"\n#include\
    \ \"../countl_zero.hpp\"\n#include \"../countr_zero.hpp\"\n#include \"../lowbit.hpp\"\
    \n#include \"../popcount.hpp\"\n#include \"../topbit.hpp\"\n\nvoid test1_bit_ceil()\
    \ {\n    const std::array<int, 8> input = {0, 1, 2, 3, 4, 5, 6, 7};\n    const\
    \ std::array<int, 8> expected = {1, 1, 2, 4, 4, 8, 8, 8};\n    for (int i = 0;\
    \ i < 8; i++) {\n        assert(bit_ceil(input[i]) == expected[i]);\n    }\n}\n\
    \nvoid test2_countl_zero() {\n    using u32 = unsigned int;\n    const std::array<u32,\
    \ 8> input = {0, 1, 2, 3, 4, 5, 6, 7};\n    const std::array<int, 8> expected\
    \ = {32, 31, 30, 30, 29, 29, 29, 29};\n    for (int i = 0; i < 8; i++) {\n   \
    \     assert(countl_zero(input[i]) == expected[i]);\n    }\n}\n\nvoid test3_countr_zero()\
    \ {\n    using u32 = unsigned int;\n    const std::array<u32, 8> input = {0, 1,\
    \ 2, 3, 4, 5, 6, 7};\n    const std::array<int, 8> expected = {32, 0, 1, 0, 2,\
    \ 0, 1, 0};\n    for (int i = 0; i < 8; i++) {\n        assert(countr_zero(input[i])\
    \ == expected[i]);\n    }\n}\n\nvoid test4_popcount() {\n    const std::array<int,\
    \ 8> input = {0, 1, 2, 3, 4, 5, 6, 7};\n    const std::array<int, 8> expected\
    \ = {0, 1, 1, 2, 1, 2, 2, 3};\n    for (int i = 0; i < 8; i++) {\n        assert(popcount(input[i])\
    \ == expected[i]);\n    }\n}\n\nvoid test5_topbit() {\n    const std::array<int,\
    \ 8> input = {0, 1, 2, 3, 4, 5, 6, 7};\n    const std::array<int, 8> expected\
    \ = {-1, 0, 1, 1, 2, 2, 2, 2};\n    for (int i = 0; i < 8; i++) {\n        assert(topbit(input[i])\
    \ == expected[i]);\n    }\n}\n\nvoid test6_lowbit() {\n    const std::array<int,\
    \ 8> input = {0, 1, 2, 3, 4, 5, 6, 7};\n    const std::array<int, 8> expected\
    \ = {-1, 0, 1, 0, 2, 0, 1, 0};\n    for (int i = 0; i < 8; i++) {\n        assert(lowbit(input[i])\
    \ == expected[i]);\n    }\n}\n\nint main() {\n    test1_bit_ceil();\n    test2_countl_zero();\n\
    \    test3_countr_zero();\n    test4_popcount();\n    test5_topbit();\n    test6_lowbit();\n\
    \    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n  \
    \  return 0;\n}\n"
  dependsOn:
  - misc/bit_ceil.hpp
  - misc/countl_zero.hpp
  - misc/countr_zero.hpp
  - misc/lowbit.hpp
  - misc/popcount.hpp
  - misc/topbit.hpp
  isVerificationFile: true
  path: misc/test/bit_operation.test.cpp
  requiredBy: []
  timestamp: '2025-12-31 07:11:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: misc/test/bit_operation.test.cpp
layout: document
redirect_from:
- /verify/misc/test/bit_operation.test.cpp
- /verify/misc/test/bit_operation.test.cpp.html
title: misc/test/bit_operation.test.cpp
---
