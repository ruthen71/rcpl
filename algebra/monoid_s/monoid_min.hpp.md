---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s_f/monoid_min_add.hpp
    title: algebra/monoid_s_f/monoid_min_add.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s_f/monoid_min_set.hpp
    title: algebra/monoid_s_f/monoid_min_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_1068.test.cpp
    title: verify/aoj_other/aoj_1068.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
    title: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_min.hpp\"\n// MS\ntemplate <class\
    \ T> struct MonoidMin {\n    using S = T;\n    static constexpr S op(S a, S b)\
    \ { return std::min(a, b); }\n    static constexpr S e() { return std::numeric_limits<T>::max();\
    \ }\n};\n"
  code: "#pragma once\n// MS\ntemplate <class T> struct MonoidMin {\n    using S =\
    \ T;\n    static constexpr S op(S a, S b) { return std::min(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<T>::max(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_s/monoid_min.hpp
  requiredBy:
  - algebra/monoid_s_f/monoid_min_add.hpp
  - algebra/monoid_s_f/monoid_min_set.hpp
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_h_lazy_segment_tree.test.cpp
  - verify/aoj_other/aoj_1068.test.cpp
  - verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
documentation_of: algebra/monoid_s/monoid_min.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s/monoid_min.hpp
- /library/algebra/monoid_s/monoid_min.hpp.html
title: algebra/monoid_s/monoid_min.hpp
---
