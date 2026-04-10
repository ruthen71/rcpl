---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_times.hpp\"\n\ntemplate <class T>\
    \ struct MonoidTimes {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return a * b;\n    }\n    static constexpr\
    \ T identity() noexcept { return T(1); }\n    static constexpr T inverse(const\
    \ T& a) noexcept { return T(1) / a; }\n    static constexpr bool commutative =\
    \ true;\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct MonoidTimes {\n    using value_type\
    \ = T;\n    static constexpr T operation(const T& a, const T& b) noexcept {\n\
    \        return a * b;\n    }\n    static constexpr T identity() noexcept { return\
    \ T(1); }\n    static constexpr T inverse(const T& a) noexcept { return T(1) /\
    \ a; }\n    static constexpr bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/monoid_times.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid/monoid_times.hpp
layout: document
redirect_from:
- /library/algebra/monoid/monoid_times.hpp
- /library/algebra/monoid/monoid_times.hpp.html
title: algebra/monoid/monoid_times.hpp
---
