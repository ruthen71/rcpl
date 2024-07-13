---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_max_add.hpp
    title: algebra/monoid_s_f/monoid_max_add.hpp
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_max_index_add.hpp
    title: algebra/monoid_s_f/monoid_max_index_add.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s_f/monoid_min_add.hpp
    title: algebra/monoid_s_f/monoid_min_add.hpp
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_min_index_add.hpp
    title: algebra/monoid_s_f/monoid_min_index_add.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s_f/monoid_sum_size_add.hpp
    title: algebra/monoid_s_f/monoid_sum_size_add.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_e_dual_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_e_dual_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_f/monoid_add.hpp\"\n// MF\ntemplate <class\
    \ T> struct MonoidAdd {\n    using F = T;\n    static constexpr F composition(F\
    \ f, F g) { return f + g; }\n    static constexpr F id() { return T(0); }\n};\n"
  code: "#pragma once\n// MF\ntemplate <class T> struct MonoidAdd {\n    using F =\
    \ T;\n    static constexpr F composition(F f, F g) { return f + g; }\n    static\
    \ constexpr F id() { return T(0); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_f/monoid_add.hpp
  requiredBy:
  - algebra/monoid_s_f/monoid_min_add.hpp
  - algebra/monoid_s_f/monoid_max_index_add.hpp
  - algebra/monoid_s_f/monoid_min_index_add.hpp
  - algebra/monoid_s_f/monoid_max_add.hpp
  - algebra/monoid_s_f/monoid_sum_size_add.hpp
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_e_dual_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
documentation_of: algebra/monoid_f/monoid_add.hpp
layout: document
redirect_from:
- /library/algebra/monoid_f/monoid_add.hpp
- /library/algebra/monoid_f/monoid_add.hpp.html
title: algebra/monoid_f/monoid_add.hpp
---
