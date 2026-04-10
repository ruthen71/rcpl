---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_inversion01_flip.hpp
    title: algebra/acted_monoid/acted_monoid_inversion01_flip.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_max01_flip.hpp
    title: algebra/acted_monoid/acted_monoid_max01_flip.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
    title: segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
    title: segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_xor.test.cpp
    title: segment_tree/test/segment_tree_xor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_xor.hpp\"\n\ntemplate <class T> struct\
    \ MonoidXor {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return a ^ b;\n    }\n    static constexpr\
    \ T identity() noexcept { return T(0); }\n    static constexpr T inverse(const\
    \ T& a) noexcept { return a; }\n    static constexpr bool commutative = true;\n\
    };\n"
  code: "#pragma once\n\ntemplate <class T> struct MonoidXor {\n    using value_type\
    \ = T;\n    static constexpr T operation(const T& a, const T& b) noexcept {\n\
    \        return a ^ b;\n    }\n    static constexpr T identity() noexcept { return\
    \ T(0); }\n    static constexpr T inverse(const T& a) noexcept { return a; }\n\
    \    static constexpr bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/monoid_xor.hpp
  requiredBy:
  - algebra/acted_monoid/acted_monoid_max01_flip.hpp
  - algebra/acted_monoid/acted_monoid_inversion01_flip.hpp
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
  - segment_tree/test/segment_tree_xor.test.cpp
  - segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
documentation_of: algebra/monoid/monoid_xor.hpp
layout: document
redirect_from:
- /library/algebra/monoid/monoid_xor.hpp
- /library/algebra/monoid/monoid_xor.hpp.html
title: algebra/monoid/monoid_xor.hpp
---
