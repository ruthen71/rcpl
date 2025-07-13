---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s_f/monoid_sum_size_add.hpp
    title: algebra/monoid_s_f/monoid_sum_size_add.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s_f/monoid_sum_size_affine.hpp
    title: algebra/monoid_s_f/monoid_sum_size_affine.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s_f/monoid_sum_size_set.hpp
    title: algebra/monoid_s_f/monoid_sum_size_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_1.test.cpp
    title: verify/graph/heavy_light_decomposition_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
    title: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_sum_size.hpp\"\n// MS\ntemplate\
    \ <class T> struct MonoidSumSize {\n    using S = std::pair<T, int>;\n    static\
    \ constexpr S op(S a, S b) { return {a.first + b.first, a.second + b.second};\
    \ }\n    static constexpr S e() { return {T(0), 0}; }\n};\n"
  code: "#pragma once\n// MS\ntemplate <class T> struct MonoidSumSize {\n    using\
    \ S = std::pair<T, int>;\n    static constexpr S op(S a, S b) { return {a.first\
    \ + b.first, a.second + b.second}; }\n    static constexpr S e() { return {T(0),\
    \ 0}; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_s/monoid_sum_size.hpp
  requiredBy:
  - algebra/monoid_s_f/monoid_sum_size_add.hpp
  - algebra/monoid_s_f/monoid_sum_size_affine.hpp
  - algebra/monoid_s_f/monoid_sum_size_set.hpp
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/heavy_light_decomposition_1.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
  - verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
documentation_of: algebra/monoid_s/monoid_sum_size.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s/monoid_sum_size.hpp
- /library/algebra/monoid_s/monoid_sum_size.hpp.html
title: algebra/monoid_s/monoid_sum_size.hpp
---
