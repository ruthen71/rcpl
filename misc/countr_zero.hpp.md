---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: misc/lowbit.hpp
    title: Lowbit
  - icon: ':warning:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':warning:'
    path: my_template_int128.hpp
    title: my_template_int128.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/dual_segment_tree.hpp
    title: "Dual Segment Tree (\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: segment_tree/lazy_segment_tree.hpp
    title: "Lazy Segment Tree (\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree.hpp
    title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree_2d.hpp
    title: "2D Segment Tree (2 \u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: misc/test/bit_operation.test.cpp
    title: misc/test/bit_operation.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/dual_segment_tree_assign.test.cpp
    title: segment_tree/test/dual_segment_tree_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/dual_segment_tree_plus.test.cpp
    title: segment_tree/test/dual_segment_tree_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
    title: segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
    title: segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_assign.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
    title: segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_product_sum_add2.test.cpp
    title: segment_tree/test/lazy_segment_tree_product_sum_add2.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
    title: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_2d.test.cpp
    title: segment_tree/test/segment_tree_2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_and.test.cpp
    title: segment_tree/test/segment_tree_and.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_gcd.test.cpp
    title: segment_tree/test/segment_tree_gcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_min.test.cpp
    title: segment_tree/test/segment_tree_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_or.test.cpp
    title: segment_tree/test/segment_tree_or.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_plus.test.cpp
    title: segment_tree/test/segment_tree_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_rolling_hash.test.cpp
    title: segment_tree/test/segment_tree_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_times.test.cpp
    title: segment_tree/test/segment_tree_times.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_xor.test.cpp
    title: segment_tree/test/segment_tree_xor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/euler_tour.test.cpp
    title: verify/graph/euler_tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
    title: verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_vertex_add_path_sum.test.cpp
    title: verify/graph/heavy_light_decomposition_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_vertex_add_subtree_sum.test.cpp
    title: verify/graph/heavy_light_decomposition_vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - misc/lowbit.hpp
  - my_template_int128.hpp
  - my_template.hpp
  - segment_tree/lazy_segment_tree.hpp
  - segment_tree/dual_segment_tree.hpp
  - segment_tree/segment_tree.hpp
  - segment_tree/segment_tree_2d.hpp
  timestamp: '2025-12-31 07:11:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - misc/test/bit_operation.test.cpp
  - verify/graph/heavy_light_decomposition_vertex_add_subtree_sum.test.cpp
  - verify/graph/heavy_light_decomposition_vertex_add_path_sum.test.cpp
  - verify/graph/euler_tour.test.cpp
  - verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
  - segment_tree/test/segment_tree_and.test.cpp
  - segment_tree/test/dual_segment_tree_assign.test.cpp
  - segment_tree/test/segment_tree_plus.test.cpp
  - segment_tree/test/dual_segment_tree_plus.test.cpp
  - segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
  - segment_tree/test/segment_tree_2d.test.cpp
  - segment_tree/test/lazy_segment_tree_min_assign.test.cpp
  - segment_tree/test/lazy_segment_tree_min_plus.test.cpp
  - segment_tree/test/segment_tree_rolling_hash.test.cpp
  - segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
  - segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
  - segment_tree/test/lazy_segment_tree_product_sum_add2.test.cpp
  - segment_tree/test/segment_tree_gcd.test.cpp
  - segment_tree/test/segment_tree_times.test.cpp
  - segment_tree/test/segment_tree_xor.test.cpp
  - segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
  - segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
  - segment_tree/test/segment_tree_min.test.cpp
  - segment_tree/test/segment_tree_or.test.cpp
  - segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
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
