---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: data_structure/lazy_segment_tree.hpp
    title: "Lazy Segment Tree (\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: misc/lowbit.hpp
    title: Lowbit
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
  - icon: ':x:'
    path: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
  - icon: ':x:'
    path: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
  - icon: ':x:'
    path: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
  - icon: ':x:'
    path: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
  - icon: ':x:'
    path: verify/graph/heavy_light_decomposition_1.test.cpp
    title: verify/graph/heavy_light_decomposition_1.test.cpp
  - icon: ':x:'
    path: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
    title: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/countr_zero.hpp\"\n\n#if __cplusplus >= 202002L\n#include\
    \ <bit>\n#endif\n\n// countr_zero\n// (000, 001, 010, 011, 100) -> (32, 0, 1,\
    \ 0, 2)\n#if __cplusplus >= 202002L\nusing std::countr_zero;\n#else\nint countr_zero(unsigned\
    \ int x) {\n    return x == 0 ? 32 : __builtin_ctz(x);\n}\nint countr_zero(unsigned\
    \ long long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n}\n#endif\n\
    int countr_zero(int x) { return countr_zero((unsigned int)(x)); }\nint countr_zero(long\
    \ long int x) {\n    return countr_zero((unsigned long long int)(x));\n}\n"
  code: "#pragma once\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n//\
    \ countr_zero\n// (000, 001, 010, 011, 100) -> (32, 0, 1, 0, 2)\n#if __cplusplus\
    \ >= 202002L\nusing std::countr_zero;\n#else\nint countr_zero(unsigned int x)\
    \ {\n    return x == 0 ? 32 : __builtin_ctz(x);\n}\nint countr_zero(unsigned long\
    \ long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n}\n#endif\nint\
    \ countr_zero(int x) { return countr_zero((unsigned int)(x)); }\nint countr_zero(long\
    \ long int x) {\n    return countr_zero((unsigned long long int)(x));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/countr_zero.hpp
  requiredBy:
  - my_template_int128.hpp
  - data_structure/lazy_segment_tree.hpp
  - my_template.hpp
  - misc/lowbit.hpp
  timestamp: '2025-12-31 07:11:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - misc/test/bit_operation.test.cpp
  - verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
  - verify/graph/heavy_light_decomposition_1.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
documentation_of: misc/countr_zero.hpp
layout: document
title: Countr Zero
---

## countr_zero

```cpp
int countr_zero(T x)
```

末尾の連続する $0$ の個数を返します。

$x = 0$ のときはビット幅（$32$ または $64$）を返します。
