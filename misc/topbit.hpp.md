---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/auxiliary_tree.hpp
    title: "Auxiliary Tree (\u865A\u6811)"
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':warning:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':warning:'
    path: my_template_int128.hpp
    title: my_template_int128.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: Random
  - icon: ':heavy_check_mark:'
    path: segment_tree/enumerate_segment_tree_nodes.hpp
    title: "Segment Tree \u306E 1 \u70B9\u5909\u66F4\u3084\u533A\u9593\u7DCF\u7A4D\
      \u3092\u884C\u3046\u969B\u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\u30CE\u30FC\
      \u30C9\u756A\u53F7\u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: segment_tree/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/erasable_priority_queue.test.cpp
    title: data_structure/test/erasable_priority_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: dp/test/inversion_number.test.cpp
    title: dp/test/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: misc/test/bit_operation.test.cpp
    title: misc/test/bit_operation.test.cpp
  - icon: ':heavy_check_mark:'
    path: random/test/base.test.cpp
    title: random/test/base.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/enumerate_segment_tree_nodes.test.cpp
    title: segment_tree/test/enumerate_segment_tree_nodes.test.cpp
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
    path: verify/graph/auxiliary_tree.test.cpp
    title: verify/graph/auxiliary_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
    title: verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/lowest_common_ancestor_1.test.cpp
    title: verify/graph/lowest_common_ancestor_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/lowest_common_ancestor_2.test.cpp
    title: verify/graph/lowest_common_ancestor_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/topological_sort_lexicographical_order.test.cpp
    title: verify/graph/topological_sort_lexicographical_order.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/topbit.hpp\"\n\n#line 2 \"misc/countl_zero.hpp\"\n\n\
    #if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n// countl_zero\n// (000,\
    \ 001, 010, 011, 100) -> (32, 31, 30, 30, 29)\n#if __cplusplus >= 202002L\nusing\
    \ std::countl_zero;\n#else\nint countl_zero(unsigned int x) {\n    return x ==\
    \ 0 ? 32 : __builtin_clz(x);\n}\nint countl_zero(unsigned long long int x) {\n\
    \    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#endif\nint countl_zero(int\
    \ x) { return countl_zero((unsigned int)(x)); }\nint countl_zero(long long int\
    \ x) {\n    return countl_zero((unsigned long long int)(x));\n}\n#line 4 \"misc/topbit.hpp\"\
    \n\n// topbit\n// (000, 001, 010, 011, 100) -> (-1, 0, 1, 1, 2)\nint topbit(int\
    \ x) { return 31 - countl_zero(x); }\nint topbit(unsigned int x) { return 31 -\
    \ countl_zero(x); }\nint topbit(long long int x) { return 63 - countl_zero(x);\
    \ }\nint topbit(unsigned long long int x) { return 63 - countl_zero(x); }\n"
  code: '#pragma once


    #include "./countl_zero.hpp"


    // topbit

    // (000, 001, 010, 011, 100) -> (-1, 0, 1, 1, 2)

    int topbit(int x) { return 31 - countl_zero(x); }

    int topbit(unsigned int x) { return 31 - countl_zero(x); }

    int topbit(long long int x) { return 63 - countl_zero(x); }

    int topbit(unsigned long long int x) { return 63 - countl_zero(x); }

    '
  dependsOn:
  - misc/countl_zero.hpp
  isVerificationFile: false
  path: misc/topbit.hpp
  requiredBy:
  - graph/lowest_common_ancestor.hpp
  - graph/auxiliary_tree.hpp
  - random/base.hpp
  - my_template_int128.hpp
  - my_template.hpp
  - segment_tree/enumerate_segment_tree_nodes.hpp
  - segment_tree/lazy_segment_tree.hpp
  timestamp: '2025-12-31 07:11:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - misc/test/bit_operation.test.cpp
  - verify/graph/lowest_common_ancestor_2.test.cpp
  - verify/graph/topological_sort_lexicographical_order.test.cpp
  - verify/graph/auxiliary_tree.test.cpp
  - verify/graph/lowest_common_ancestor_1.test.cpp
  - verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
  - random/test/base.test.cpp
  - dp/test/inversion_number.test.cpp
  - segment_tree/test/enumerate_segment_tree_nodes.test.cpp
  - segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
  - segment_tree/test/lazy_segment_tree_min_assign.test.cpp
  - segment_tree/test/lazy_segment_tree_min_plus.test.cpp
  - segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
  - segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
  - segment_tree/test/lazy_segment_tree_product_sum_add2.test.cpp
  - segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
  - segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
  - segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
  - data_structure/test/erasable_priority_queue.test.cpp
documentation_of: misc/topbit.hpp
layout: document
title: Topbit
---

## topbit

```cpp
int topbit(T x)
```

最上位に立っているビットの位置を返します。

$x = 0$ のときは $-1$ を返します。
