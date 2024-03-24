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
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_gcd.hpp\"\n// MS\ntemplate <class\
    \ T> struct MonoidGcd {\n    using S = T;\n    static constexpr S op(S a, S b)\
    \ { return std::gcd(a, b); }\n    static constexpr S e() { return T(0); }\n};\n"
  code: "#pragma once\n// MS\ntemplate <class T> struct MonoidGcd {\n    using S =\
    \ T;\n    static constexpr S op(S a, S b) { return std::gcd(a, b); }\n    static\
    \ constexpr S e() { return T(0); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_s/monoid_gcd.hpp
  requiredBy: []
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki/yuki_1036_segment_tree.test.cpp
documentation_of: algebra/monoid_s/monoid_gcd.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s/monoid_gcd.hpp
- /library/algebra/monoid_s/monoid_gcd.hpp.html
title: algebra/monoid_s/monoid_gcd.hpp
---
