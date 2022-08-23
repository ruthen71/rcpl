---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
    title: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algebra/monoid_min.hpp\"\n\ntemplate <class S> struct\
    \ monoid_min {\n    using value_type = S;\n    static constexpr S op(S a, S b)\
    \ { return std::min(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::max();\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct monoid_min {\n    using value_type\
    \ = S;\n    static constexpr S op(S a, S b) { return std::min(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::max(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/monoid_min.hpp
  requiredBy: []
  timestamp: '2022-08-23 17:30:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
documentation_of: src/algebra/monoid_min.hpp
layout: document
redirect_from:
- /library/src/algebra/monoid_min.hpp
- /library/src/algebra/monoid_min.hpp.html
title: src/algebra/monoid_min.hpp
---
