---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
    title: verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_sum.hpp\"\n\ntemplate <class S> struct MonoidSum\
    \ {\n    using value_type = S;\n    static constexpr S op(S a, S b) { return a\
    \ + b; }\n    static constexpr S e() { return 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct MonoidSum {\n    using value_type\
    \ = S;\n    static constexpr S op(S a, S b) { return a + b; }\n    static constexpr\
    \ S e() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_sum.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
documentation_of: algebra/monoid_sum.hpp
layout: document
redirect_from:
- /library/algebra/monoid_sum.hpp
- /library/algebra/monoid_sum.hpp.html
title: algebra/monoid_sum.hpp
---
