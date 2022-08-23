---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yuki/yuki_1036_segment_tree.test.cpp
    title: verify/yuki/yuki_1036_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algebra/monoid_gcd.hpp\"\n\ntemplate <class S> struct\
    \ monoid_gcd {\n    using value_type = S;\n    static constexpr S op(S a, S b)\
    \ { return std::gcd(a, b); }\n    static constexpr S e() { return 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct monoid_gcd {\n    using value_type\
    \ = S;\n    static constexpr S op(S a, S b) { return std::gcd(a, b); }\n    static\
    \ constexpr S e() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/monoid_gcd.hpp
  requiredBy: []
  timestamp: '2022-08-23 23:16:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki/yuki_1036_segment_tree.test.cpp
documentation_of: src/algebra/monoid_gcd.hpp
layout: document
redirect_from:
- /library/src/algebra/monoid_gcd.hpp
- /library/src/algebra/monoid_gcd.hpp.html
title: src/algebra/monoid_gcd.hpp
---
