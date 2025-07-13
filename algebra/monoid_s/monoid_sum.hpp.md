---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/euler_tour.test.cpp
    title: verify/graph/euler_tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_2.test.cpp
    title: verify/graph/heavy_light_decomposition_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_3.test.cpp
    title: verify/graph/heavy_light_decomposition_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
    title: verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_sum.hpp\"\n// MS\ntemplate <class\
    \ T> struct MonoidSum {\n    using S = T;\n    static constexpr S op(S a, S b)\
    \ { return a + b; }\n    static constexpr S e() { return T(0); }\n};\n"
  code: "#pragma once\n// MS\ntemplate <class T> struct MonoidSum {\n    using S =\
    \ T;\n    static constexpr S op(S a, S b) { return a + b; }\n    static constexpr\
    \ S e() { return T(0); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_s/monoid_sum.hpp
  requiredBy: []
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/euler_tour.test.cpp
  - verify/graph/heavy_light_decomposition_2.test.cpp
  - verify/graph/heavy_light_decomposition_3.test.cpp
  - verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
documentation_of: algebra/monoid_s/monoid_sum.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s/monoid_sum.hpp
- /library/algebra/monoid_s/monoid_sum.hpp.html
title: algebra/monoid_s/monoid_sum.hpp
---
