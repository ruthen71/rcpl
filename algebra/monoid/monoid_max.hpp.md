---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_max_assign.hpp
    title: algebra/acted_monoid/acted_monoid_max_assign.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_max_plus.hpp
    title: algebra/acted_monoid/acted_monoid_max_plus.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_assign.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_min.test.cpp
    title: segment_tree/test/segment_tree_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_max.hpp\"\n\ntemplate <class T, T\
    \ inf> struct MonoidMax {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return std::max(a, b);\n    }\n    static\
    \ constexpr T identity() noexcept { return -inf; }\n    static constexpr bool\
    \ commutative = true;\n};\n"
  code: "#pragma once\n\ntemplate <class T, T inf> struct MonoidMax {\n    using value_type\
    \ = T;\n    static constexpr T operation(const T& a, const T& b) noexcept {\n\
    \        return std::max(a, b);\n    }\n    static constexpr T identity() noexcept\
    \ { return -inf; }\n    static constexpr bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/monoid_max.hpp
  requiredBy:
  - algebra/acted_monoid/acted_monoid_max_assign.hpp
  - algebra/acted_monoid/acted_monoid_max_plus.hpp
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_min_assign.test.cpp
  - segment_tree/test/lazy_segment_tree_min_plus.test.cpp
  - segment_tree/test/segment_tree_min.test.cpp
documentation_of: algebra/monoid/monoid_max.hpp
layout: document
redirect_from:
- /library/algebra/monoid/monoid_max.hpp
- /library/algebra/monoid/monoid_max.hpp.html
title: algebra/monoid/monoid_max.hpp
---
