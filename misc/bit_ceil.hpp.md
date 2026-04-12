---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
    path: data_structure/test/erasable_priority_queue.test.cpp
    title: data_structure/test/erasable_priority_queue.test.cpp
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
  requiredBy:
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
  - data_structure/test/erasable_priority_queue.test.cpp
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
