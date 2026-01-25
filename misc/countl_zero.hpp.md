---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/auxiliary_tree.hpp
    title: "Auxiliary Tree (\u865A\u6811)"
  - icon: ':question:'
    path: graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':question:'
    path: misc/topbit.hpp
    title: Topbit
  - icon: ':warning:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':warning:'
    path: my_template_int128.hpp
    title: my_template_int128.hpp
  - icon: ':x:'
    path: random/base.hpp
    title: Random
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: misc/test/bit_operation.test.cpp
    title: misc/test/bit_operation.test.cpp
  - icon: ':x:'
    path: random/test/base.test.cpp
    title: random/test/base.test.cpp
  - icon: ':x:'
    path: verify/graph/auxiliary_tree.test.cpp
    title: verify/graph/auxiliary_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/lowest_common_ancestor_1.test.cpp
    title: verify/graph/lowest_common_ancestor_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/lowest_common_ancestor_2.test.cpp
    title: verify/graph/lowest_common_ancestor_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/countl_zero.hpp\"\n\n#if __cplusplus >= 202002L\n#include\
    \ <bit>\n#endif\n\n// countl_zero\n// (000, 001, 010, 011, 100) -> (32, 31, 30,\
    \ 30, 29)\n#if __cplusplus >= 202002L\nusing std::countl_zero;\n#else\nint countl_zero(unsigned\
    \ int x) {\n    return x == 0 ? 32 : __builtin_clz(x);\n}\nint countl_zero(unsigned\
    \ long long int x) {\n    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#endif\n\
    int countl_zero(int x) { return countl_zero((unsigned int)(x)); }\nint countl_zero(long\
    \ long int x) {\n    return countl_zero((unsigned long long int)(x));\n}\n"
  code: "#pragma once\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n//\
    \ countl_zero\n// (000, 001, 010, 011, 100) -> (32, 31, 30, 30, 29)\n#if __cplusplus\
    \ >= 202002L\nusing std::countl_zero;\n#else\nint countl_zero(unsigned int x)\
    \ {\n    return x == 0 ? 32 : __builtin_clz(x);\n}\nint countl_zero(unsigned long\
    \ long int x) {\n    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#endif\nint\
    \ countl_zero(int x) { return countl_zero((unsigned int)(x)); }\nint countl_zero(long\
    \ long int x) {\n    return countl_zero((unsigned long long int)(x));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/countl_zero.hpp
  requiredBy:
  - my_template_int128.hpp
  - my_template.hpp
  - random/base.hpp
  - misc/topbit.hpp
  - graph/lowest_common_ancestor.hpp
  - graph/auxiliary_tree.hpp
  timestamp: '2025-12-31 07:11:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - random/test/base.test.cpp
  - misc/test/bit_operation.test.cpp
  - verify/graph/lowest_common_ancestor_2.test.cpp
  - verify/graph/auxiliary_tree.test.cpp
  - verify/graph/lowest_common_ancestor_1.test.cpp
documentation_of: misc/countl_zero.hpp
layout: document
title: Countl Zero
---

## countl_zero

```cpp
int countl_zero(T x)
```

先頭の連続する $0$ の個数を返します。

$x = 0$ のときはビット幅（$32$ または $64$）を返します。
