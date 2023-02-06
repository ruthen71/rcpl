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
  bundledCode: "#line 2 \"algebra/monoid_gcd.hpp\"\n\ntemplate <class S> struct MonoidGcd\
    \ {\n    using value_type = S;\n    static constexpr S op(S a, S b) { return std::gcd(a,\
    \ b); }\n    static constexpr S e() { return 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct MonoidGcd {\n    using value_type\
    \ = S;\n    static constexpr S op(S a, S b) { return std::gcd(a, b); }\n    static\
    \ constexpr S e() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_gcd.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki/yuki_1036_segment_tree.test.cpp
documentation_of: algebra/monoid_gcd.hpp
layout: document
redirect_from:
- /library/algebra/monoid_gcd.hpp
- /library/algebra/monoid_gcd.hpp.html
title: algebra/monoid_gcd.hpp
---
