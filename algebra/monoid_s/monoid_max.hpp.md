---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_max_set.hpp
    title: algebra/monoid_s_f/monoid_max_set.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_max.hpp\"\n// MS\ntemplate <class\
    \ T> struct MonoidMax {\n    using S = T;\n    static constexpr S op(S a, S b)\
    \ { return std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<T>::lowest();\
    \ }\n};\n"
  code: "#pragma once\n// MS\ntemplate <class T> struct MonoidMax {\n    using S =\
    \ T;\n    static constexpr S op(S a, S b) { return std::max(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<T>::lowest(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_s/monoid_max.hpp
  requiredBy:
  - algebra/monoid_s_f/monoid_max_set.hpp
  timestamp: '2026-01-20 04:06:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s/monoid_max.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s/monoid_max.hpp
- /library/algebra/monoid_s/monoid_max.hpp.html
title: algebra/monoid_s/monoid_max.hpp
---
