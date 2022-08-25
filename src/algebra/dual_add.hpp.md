---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_2_e_dual_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_e_dual_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algebra/dual_add.hpp\"\n\ntemplate <class F> struct\
    \ dual_add {\n    using value_type = F;\n    static constexpr F composition(F\
    \ f, F g) { return f + g; }\n    static constexpr F id() { return 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class F> struct dual_add {\n    using value_type\
    \ = F;\n    static constexpr F composition(F f, F g) { return f + g; }\n    static\
    \ constexpr F id() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/dual_add.hpp
  requiredBy: []
  timestamp: '2022-08-26 04:52:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_e_dual_segment_tree.test.cpp
documentation_of: src/algebra/dual_add.hpp
layout: document
redirect_from:
- /library/src/algebra/dual_add.hpp
- /library/src/algebra/dual_add.hpp.html
title: src/algebra/dual_add.hpp
---
