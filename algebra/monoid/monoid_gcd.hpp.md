---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_gcd.test.cpp
    title: segment_tree/test/segment_tree_gcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_gcd.hpp\"\n\ntemplate <class T> struct\
    \ MonoidGcd {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return std::gcd(a, b);\n    }\n    static\
    \ constexpr T identity() noexcept { return T(0); }\n    static constexpr bool\
    \ commutative = true;\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct MonoidGcd {\n    using value_type\
    \ = T;\n    static constexpr T operation(const T& a, const T& b) noexcept {\n\
    \        return std::gcd(a, b);\n    }\n    static constexpr T identity() noexcept\
    \ { return T(0); }\n    static constexpr bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/monoid_gcd.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/segment_tree_gcd.test.cpp
documentation_of: algebra/monoid/monoid_gcd.hpp
layout: document
redirect_from:
- /library/algebra/monoid/monoid_gcd.hpp
- /library/algebra/monoid/monoid_gcd.hpp.html
title: algebra/monoid/monoid_gcd.hpp
---
