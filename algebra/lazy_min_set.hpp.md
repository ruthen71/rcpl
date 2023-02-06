---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/lazy_min_set.hpp\"\n\ntemplate <class S> struct\
    \ lazy_min_set {\n    using F = S;\n    using value_type_S = S;\n    using value_type_F\
    \ = F;\n    static constexpr S op(S a, S b) { return std::min(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::max(); }\n    static constexpr\
    \ S mapping(F f, S x) { return f == id() ? x : f; }\n    static constexpr F composition(F\
    \ f, F g) { return f == id() ? g : f; }\n    static constexpr F id() { return\
    \ std::numeric_limits<F>::max(); }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct lazy_min_set {\n    using F = S;\n\
    \    using value_type_S = S;\n    using value_type_F = F;\n    static constexpr\
    \ S op(S a, S b) { return std::min(a, b); }\n    static constexpr S e() { return\
    \ std::numeric_limits<S>::max(); }\n    static constexpr S mapping(F f, S x) {\
    \ return f == id() ? x : f; }\n    static constexpr F composition(F f, F g) {\
    \ return f == id() ? g : f; }\n    static constexpr F id() { return std::numeric_limits<F>::max();\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/lazy_min_set.hpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
documentation_of: algebra/lazy_min_set.hpp
layout: document
redirect_from:
- /library/algebra/lazy_min_set.hpp
- /library/algebra/lazy_min_set.hpp.html
title: algebra/lazy_min_set.hpp
---
