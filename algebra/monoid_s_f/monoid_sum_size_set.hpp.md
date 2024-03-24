---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_f/monoid_set.hpp
    title: algebra/monoid_f/monoid_set.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s/monoid_sum_size.hpp
    title: algebra/monoid_s/monoid_sum_size.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_sum_size.hpp\"\n// MS\ntemplate\
    \ <class T> struct MonoidSumSize {\n    using S = std::pair<T, int>;\n    static\
    \ constexpr S op(S a, S b) { return {a.first + b.first, a.second + b.second};\
    \ }\n    static constexpr S e() { return {T(0), 0}; }\n};\n#line 2 \"algebra/monoid_f/monoid_set.hpp\"\
    \n// MF\ntemplate <class T> struct MonoidSet {\n    using F = T;\n    static constexpr\
    \ F composition(F f, F g) { return f == id() ? g : f; }\n    static constexpr\
    \ F id() { return std::numeric_limits<F>::max(); }\n};\n#line 4 \"algebra/monoid_s_f/monoid_sum_size_set.hpp\"\
    \n// MSF\ntemplate <class T> struct MonoidSumSizeSet {\n    using MS = MonoidSumSize<T>;\n\
    \    using MF = MonoidSet<T>;\n    using S = typename MS::S;\n    using F = typename\
    \ MF::F;\n    static constexpr S mapping(F f, S x) { return (f == MF::id() ? x\
    \ : std::make_pair(f * x.second, x.second)); }\n};\n"
  code: "#pragma once\n#include \"algebra/monoid_s/monoid_sum_size.hpp\"\n#include\
    \ \"algebra/monoid_f/monoid_set.hpp\"\n// MSF\ntemplate <class T> struct MonoidSumSizeSet\
    \ {\n    using MS = MonoidSumSize<T>;\n    using MF = MonoidSet<T>;\n    using\
    \ S = typename MS::S;\n    using F = typename MF::F;\n    static constexpr S mapping(F\
    \ f, S x) { return (f == MF::id() ? x : std::make_pair(f * x.second, x.second));\
    \ }\n};"
  dependsOn:
  - algebra/monoid_s/monoid_sum_size.hpp
  - algebra/monoid_f/monoid_set.hpp
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_sum_size_set.hpp
  requiredBy: []
  timestamp: '2024-03-24 17:17:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
documentation_of: algebra/monoid_s_f/monoid_sum_size_set.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_sum_size_set.hpp
- /library/algebra/monoid_s_f/monoid_sum_size_set.hpp.html
title: algebra/monoid_s_f/monoid_sum_size_set.hpp
---
