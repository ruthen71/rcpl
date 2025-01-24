---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_f/monoid_add.hpp
    title: algebra/monoid_f/monoid_add.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s/monoid_sum_size.hpp
    title: algebra/monoid_s/monoid_sum_size.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_1.test.cpp
    title: verify/graph/heavy_light_decomposition_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_sum_size.hpp\"\n// MS\ntemplate\
    \ <class T> struct MonoidSumSize {\n    using S = std::pair<T, int>;\n    static\
    \ constexpr S op(S a, S b) { return {a.first + b.first, a.second + b.second};\
    \ }\n    static constexpr S e() { return {T(0), 0}; }\n};\n#line 2 \"algebra/monoid_f/monoid_add.hpp\"\
    \n// MF\ntemplate <class T> struct MonoidAdd {\n    using F = T;\n    static constexpr\
    \ F composition(F f, F g) { return f + g; }\n    static constexpr F id() { return\
    \ T(0); }\n};\n#line 4 \"algebra/monoid_s_f/monoid_sum_size_add.hpp\"\n// MSF\n\
    template <class T> struct MonoidSumSizeAdd {\n    using MS = MonoidSumSize<T>;\n\
    \    using MF = MonoidAdd<T>;\n    using S = typename MS::S;\n    using F = typename\
    \ MF::F;\n    static constexpr S mapping(F f, S x) { return {x.first + f * x.second,\
    \ x.second}; }\n};\n"
  code: "#pragma once\n#include \"algebra/monoid_s/monoid_sum_size.hpp\"\n#include\
    \ \"algebra/monoid_f/monoid_add.hpp\"\n// MSF\ntemplate <class T> struct MonoidSumSizeAdd\
    \ {\n    using MS = MonoidSumSize<T>;\n    using MF = MonoidAdd<T>;\n    using\
    \ S = typename MS::S;\n    using F = typename MF::F;\n    static constexpr S mapping(F\
    \ f, S x) { return {x.first + f * x.second, x.second}; }\n};"
  dependsOn:
  - algebra/monoid_s/monoid_sum_size.hpp
  - algebra/monoid_f/monoid_add.hpp
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_sum_size_add.hpp
  requiredBy: []
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/heavy_light_decomposition_1.test.cpp
  - verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
documentation_of: algebra/monoid_s_f/monoid_sum_size_add.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_sum_size_add.hpp
- /library/algebra/monoid_s_f/monoid_sum_size_add.hpp.html
title: algebra/monoid_s_f/monoid_sum_size_add.hpp
---
