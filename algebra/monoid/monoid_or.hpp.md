---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_or.test.cpp
    title: segment_tree/test/segment_tree_or.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_or.hpp\"\n\ntemplate <class T> struct\
    \ MonoidOr {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return a | b;\n    }\n    static constexpr\
    \ T identity() noexcept { return T(0); }\n    static constexpr bool commutative\
    \ = true;\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct MonoidOr {\n    using value_type\
    \ = T;\n    static constexpr T operation(const T& a, const T& b) noexcept {\n\
    \        return a | b;\n    }\n    static constexpr T identity() noexcept { return\
    \ T(0); }\n    static constexpr bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/monoid_or.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/segment_tree_or.test.cpp
documentation_of: algebra/monoid/monoid_or.hpp
layout: document
redirect_from:
- /library/algebra/monoid/monoid_or.hpp
- /library/algebra/monoid/monoid_or.hpp.html
title: algebra/monoid/monoid_or.hpp
---
