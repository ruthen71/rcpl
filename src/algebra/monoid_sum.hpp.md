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
  bundledCode: "#line 2 \"src/algebra/monoid_sum.hpp\"\n\ntemplate <class S> struct\
    \ monoid_sum {\n    using value_type = S;\n    static constexpr S op(S a, S b)\
    \ { return a + b; }\n    static constexpr S e() { return 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct monoid_sum {\n    using value_type\
    \ = S;\n    static constexpr S op(S a, S b) { return a + b; }\n    static constexpr\
    \ S e() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/monoid_sum.hpp
  requiredBy: []
  timestamp: '2022-08-23 22:12:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_point_add_range_sum_segment_tree.test.cpp
documentation_of: src/algebra/monoid_sum.hpp
layout: document
redirect_from:
- /library/src/algebra/monoid_sum.hpp
- /library/src/algebra/monoid_sum.hpp.html
title: src/algebra/monoid_sum.hpp
---
