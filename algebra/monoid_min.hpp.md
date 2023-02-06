---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_other/aoj_1068.test.cpp
    title: verify/aoj_other/aoj_1068.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
    title: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_min.hpp\"\n\ntemplate <class S> struct monoid_min\
    \ {\n    using value_type = S;\n    static constexpr S op(S a, S b) { return std::min(a,\
    \ b); }\n    static constexpr S e() { return std::numeric_limits<S>::max(); }\n\
    };\n"
  code: "#pragma once\n\ntemplate <class S> struct monoid_min {\n    using value_type\
    \ = S;\n    static constexpr S op(S a, S b) { return std::min(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::max(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_min.hpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
  - verify/aoj_other/aoj_1068.test.cpp
documentation_of: algebra/monoid_min.hpp
layout: document
redirect_from:
- /library/algebra/monoid_min.hpp
- /library/algebra/monoid_min.hpp.html
title: algebra/monoid_min.hpp
---
