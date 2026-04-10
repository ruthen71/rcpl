---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_and.test.cpp
    title: segment_tree/test/segment_tree_and.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_and.hpp\"\n\ntemplate <class T> struct\
    \ MonoidAnd {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return a & b;\n    }\n    static constexpr\
    \ T identity() noexcept { return T(-1); }\n    static constexpr bool commutative\
    \ = true;\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct MonoidAnd {\n    using value_type\
    \ = T;\n    static constexpr T operation(const T& a, const T& b) noexcept {\n\
    \        return a & b;\n    }\n    static constexpr T identity() noexcept { return\
    \ T(-1); }\n    static constexpr bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/monoid_and.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/segment_tree_and.test.cpp
documentation_of: algebra/monoid/monoid_and.hpp
layout: document
redirect_from:
- /library/algebra/monoid/monoid_and.hpp
- /library/algebra/monoid/monoid_and.hpp.html
title: algebra/monoid/monoid_and.hpp
---
