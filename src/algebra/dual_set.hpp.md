---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algebra/dual_set.hpp\"\n\ntemplate <class F> struct\
    \ dual_set {\n    using value_type = F;\n    static constexpr F composition(F\
    \ f, F g) { return f == id() ? g : f; }\n    static constexpr F id() { return\
    \ std::numeric_limits<F>::max(); }\n};\n"
  code: "#pragma once\n\ntemplate <class F> struct dual_set {\n    using value_type\
    \ = F;\n    static constexpr F composition(F f, F g) { return f == id() ? g :\
    \ f; }\n    static constexpr F id() { return std::numeric_limits<F>::max(); }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/dual_set.hpp
  requiredBy: []
  timestamp: '2022-08-26 04:45:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_d_dual_segment_tree.test.cpp
documentation_of: src/algebra/dual_set.hpp
layout: document
redirect_from:
- /library/src/algebra/dual_set.hpp
- /library/src/algebra/dual_set.hpp.html
title: src/algebra/dual_set.hpp
---
