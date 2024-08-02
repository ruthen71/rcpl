---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_inversion_flip.hpp
    title: algebra/monoid_s_f/monoid_inversion_flip.hpp
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_max01_flip.hpp
    title: algebra/monoid_s_f/monoid_max01_flip.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_f/monoid_flip.hpp\"\n\n// MF\nstruct MonoidFlip\
    \ {\n    using F = int;\n    static constexpr F composition(F f, F g) { return\
    \ f ^ g; }\n    static constexpr F id() { return 0; }\n};\n"
  code: "#pragma once\n\n// MF\nstruct MonoidFlip {\n    using F = int;\n    static\
    \ constexpr F composition(F f, F g) { return f ^ g; }\n    static constexpr F\
    \ id() { return 0; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_f/monoid_flip.hpp
  requiredBy:
  - algebra/monoid_s_f/monoid_inversion_flip.hpp
  - algebra/monoid_s_f/monoid_max01_flip.hpp
  timestamp: '2024-03-24 19:02:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_f/monoid_flip.hpp
layout: document
redirect_from:
- /library/algebra/monoid_f/monoid_flip.hpp
- /library/algebra/monoid_f/monoid_flip.hpp.html
title: algebra/monoid_f/monoid_flip.hpp
---
