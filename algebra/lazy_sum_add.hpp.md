---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/lazy_sum_add.hpp\"\n\ntemplate <class T> struct\
    \ LazySumAdd {\n    using S = std::pair<T, int>;\n    using F = T;\n    using\
    \ value_type_S = S;\n    using value_type_F = F;\n    static constexpr S op(S\
    \ a, S b) { return {a.first + b.first, a.second + b.second}; }\n    static constexpr\
    \ S e() { return {0, 0}; }\n    static constexpr S mapping(F f, S x) { return\
    \ {x.first + f * x.second, x.second}; }\n    static constexpr F composition(F\
    \ f, F g) { return f + g; }\n    static constexpr F id() { return 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct LazySumAdd {\n    using S = std::pair<T,\
    \ int>;\n    using F = T;\n    using value_type_S = S;\n    using value_type_F\
    \ = F;\n    static constexpr S op(S a, S b) { return {a.first + b.first, a.second\
    \ + b.second}; }\n    static constexpr S e() { return {0, 0}; }\n    static constexpr\
    \ S mapping(F f, S x) { return {x.first + f * x.second, x.second}; }\n    static\
    \ constexpr F composition(F f, F g) { return f + g; }\n    static constexpr F\
    \ id() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/lazy_sum_add.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_g_lazy_segment_tree.test.cpp
documentation_of: algebra/lazy_sum_add.hpp
layout: document
redirect_from:
- /library/algebra/lazy_sum_add.hpp
- /library/algebra/lazy_sum_add.hpp.html
title: algebra/lazy_sum_add.hpp
---
