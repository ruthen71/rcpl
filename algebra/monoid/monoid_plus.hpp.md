---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: unionfind/test/potentialized_unionfind.test.cpp
    title: unionfind/test/potentialized_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: unionfind/test/potentialized_unionfind_groups.test.cpp
    title: unionfind/test/potentialized_unionfind_groups.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate <class T> struct\
    \ MonoidPlus {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return a + b;\n    }\n    static constexpr\
    \ T identity() noexcept { return T(0); }\n    static constexpr T inverse(const\
    \ T& a) noexcept { return -a; }\n    static constexpr bool commutative = true;\n\
    };\n"
  code: "#pragma once\n\ntemplate <class T> struct MonoidPlus {\n    using value_type\
    \ = T;\n    static constexpr T operation(const T& a, const T& b) noexcept {\n\
    \        return a + b;\n    }\n    static constexpr T identity() noexcept { return\
    \ T(0); }\n    static constexpr T inverse(const T& a) noexcept { return -a; }\n\
    \    static constexpr bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/monoid_plus.hpp
  requiredBy: []
  timestamp: '2025-12-10 04:21:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unionfind/test/potentialized_unionfind_groups.test.cpp
  - unionfind/test/potentialized_unionfind.test.cpp
documentation_of: algebra/monoid/monoid_plus.hpp
layout: document
redirect_from:
- /library/algebra/monoid/monoid_plus.hpp
- /library/algebra/monoid/monoid_plus.hpp.html
title: algebra/monoid/monoid_plus.hpp
---
