---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_max_index_set.hpp
    title: algebra/monoid_s_f/monoid_max_index_set.hpp
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_max_set.hpp
    title: algebra/monoid_s_f/monoid_max_set.hpp
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_min_index_set.hpp
    title: algebra/monoid_s_f/monoid_min_index_set.hpp
  - icon: ':x:'
    path: algebra/monoid_s_f/monoid_min_set.hpp
    title: algebra/monoid_s_f/monoid_min_set.hpp
  - icon: ':x:'
    path: algebra/monoid_s_f/monoid_sum_size_set.hpp
    title: algebra/monoid_s_f/monoid_sum_size_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
  - icon: ':x:'
    path: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
  - icon: ':x:'
    path: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_f/monoid_set.hpp\"\n// MF\ntemplate <class\
    \ T> struct MonoidSet {\n    using F = T;\n    static constexpr F composition(F\
    \ f, F g) { return f == id() ? g : f; }\n    static constexpr F id() { return\
    \ std::numeric_limits<F>::max(); }\n};\n"
  code: "#pragma once\n// MF\ntemplate <class T> struct MonoidSet {\n    using F =\
    \ T;\n    static constexpr F composition(F f, F g) { return f == id() ? g : f;\
    \ }\n    static constexpr F id() { return std::numeric_limits<F>::max(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_f/monoid_set.hpp
  requiredBy:
  - algebra/monoid_s_f/monoid_max_set.hpp
  - algebra/monoid_s_f/monoid_sum_size_set.hpp
  - algebra/monoid_s_f/monoid_min_index_set.hpp
  - algebra/monoid_s_f/monoid_max_index_set.hpp
  - algebra/monoid_s_f/monoid_min_set.hpp
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
documentation_of: algebra/monoid_f/monoid_set.hpp
layout: document
redirect_from:
- /library/algebra/monoid_f/monoid_set.hpp
- /library/algebra/monoid_f/monoid_set.hpp.html
title: algebra/monoid_f/monoid_set.hpp
---
