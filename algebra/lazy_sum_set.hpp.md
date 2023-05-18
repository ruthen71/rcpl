---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"algebra/lazy_sum_set.hpp\"\n\ntemplate <class T> struct\
    \ LazySumSet {\n    using S = std::pair<T, int>;\n    using F = T;\n    using\
    \ value_type_S = S;\n    using value_type_F = F;\n    static constexpr S op(S\
    \ a, S b) { return {a.first + b.first, a.second + b.second}; }\n    static constexpr\
    \ S e() { return {0, 0}; }\n    static constexpr S mapping(F f, S x) {\n     \
    \   if (f != id()) x.first = f * x.second;\n        return x;\n    }\n    static\
    \ constexpr F composition(F f, F g) { return f == id() ? g : f; }\n    static\
    \ constexpr F id() { return std::numeric_limits<F>::max(); }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct LazySumSet {\n    using S = std::pair<T,\
    \ int>;\n    using F = T;\n    using value_type_S = S;\n    using value_type_F\
    \ = F;\n    static constexpr S op(S a, S b) { return {a.first + b.first, a.second\
    \ + b.second}; }\n    static constexpr S e() { return {0, 0}; }\n    static constexpr\
    \ S mapping(F f, S x) {\n        if (f != id()) x.first = f * x.second;\n    \
    \    return x;\n    }\n    static constexpr F composition(F f, F g) { return f\
    \ == id() ? g : f; }\n    static constexpr F id() { return std::numeric_limits<F>::max();\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/lazy_sum_set.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
documentation_of: algebra/lazy_sum_set.hpp
layout: document
redirect_from:
- /library/algebra/lazy_sum_set.hpp
- /library/algebra/lazy_sum_set.hpp.html
title: algebra/lazy_sum_set.hpp
---