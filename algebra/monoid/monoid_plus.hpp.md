---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_max_index_plus.hpp
    title: algebra/acted_monoid/acted_monoid_max_index_plus.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_max_plus.hpp
    title: algebra/acted_monoid/acted_monoid_max_plus.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_min_index_plus.hpp
    title: algebra/acted_monoid/acted_monoid_min_index_plus.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_min_plus.hpp
    title: algebra/acted_monoid/acted_monoid_min_plus.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_plus_affine.hpp
    title: algebra/acted_monoid/acted_monoid_plus_affine.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_plus_assign.hpp
    title: algebra/acted_monoid/acted_monoid_plus_assign.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_plus_plus.hpp
    title: algebra/acted_monoid/acted_monoid_plus_plus.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/range_kth_smallest.hpp
    title: "\u533A\u9593\u306E k \u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u6C42\
      \u3081\u308B\u30AF\u30A8\u30EA"
  - icon: ':heavy_check_mark:'
    path: dp/inversion_number.hpp
    title: "Inversion Number (\u8EE2\u5012\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_kth_smallest.test.cpp
    title: data_structure/test/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: dp/test/inversion_number.test.cpp
    title: dp/test/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/dual_segment_tree_plus.test.cpp
    title: segment_tree/test/dual_segment_tree_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/dynamic_segment_tree.test.cpp
    title: segment_tree/test/dynamic_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/fenwick_tree_plus.test.cpp
    title: segment_tree/test/fenwick_tree_plus.test.cpp
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
    path: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
    title: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_plus.test.cpp
    title: segment_tree/test/segment_tree_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_recursion.test.cpp
    title: segment_tree/test/segment_tree_recursion.test.cpp
  - icon: ':heavy_check_mark:'
    path: unionfind/test/potentialized_unionfind.test.cpp
    title: unionfind/test/potentialized_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: unionfind/test/potentialized_unionfind_groups.test.cpp
    title: unionfind/test/potentialized_unionfind_groups.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: verify/misc/mo.test.cpp
    title: verify/misc/mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate <class T> struct\
    \ MonoidPlus {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return a + b;\n    }\n    static constexpr\
    \ T identity() noexcept { return T(0); }\n    static constexpr T inverse(const\
    \ T& a) noexcept { return -a; }\n    static constexpr bool commutative = true;\n\
    };\n"
  code: "#pragma once\n\ntemplate <class T> struct MonoidPlus {\n    using value_type\
    \ = T;\n    static constexpr T operation(const T& a, const T& b) noexcept {\n\
    \        return a + b;\n    }\n    static constexpr T identity() noexcept { return\
    \ T(0); }\n    static constexpr T inverse(const T& a) noexcept { return -a; }\n\
    \    static constexpr bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/monoid_plus.hpp
  requiredBy:
  - algebra/acted_monoid/acted_monoid_plus_assign.hpp
  - algebra/acted_monoid/acted_monoid_min_plus.hpp
  - algebra/acted_monoid/acted_monoid_plus_affine.hpp
  - algebra/acted_monoid/acted_monoid_plus_plus.hpp
  - algebra/acted_monoid/acted_monoid_max_index_plus.hpp
  - algebra/acted_monoid/acted_monoid_max_plus.hpp
  - algebra/acted_monoid/acted_monoid_min_index_plus.hpp
  - dp/inversion_number.hpp
  - data_structure/range_kth_smallest.hpp
  timestamp: '2025-12-10 04:21:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/misc/mo.test.cpp
  - verify/graph/heavy_light_decomposition_vertex_add_subtree_sum.test.cpp
  - verify/graph/heavy_light_decomposition_vertex_add_path_sum.test.cpp
  - verify/graph/euler_tour.test.cpp
  - verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
  - dp/test/inversion_number.test.cpp
  - segment_tree/test/segment_tree_plus.test.cpp
  - segment_tree/test/dual_segment_tree_plus.test.cpp
  - segment_tree/test/lazy_segment_tree_min_plus.test.cpp
  - segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
  - segment_tree/test/fenwick_tree_plus.test.cpp
  - segment_tree/test/dynamic_segment_tree.test.cpp
  - segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
  - segment_tree/test/segment_tree_recursion.test.cpp
  - segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
  - segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
  - data_structure/test/range_kth_smallest.test.cpp
  - unionfind/test/potentialized_unionfind.test.cpp
  - unionfind/test/potentialized_unionfind_groups.test.cpp
documentation_of: algebra/monoid/monoid_plus.hpp
layout: document
redirect_from:
- /library/algebra/monoid/monoid_plus.hpp
- /library/algebra/monoid/monoid_plus.hpp.html
title: algebra/monoid/monoid_plus.hpp
---
