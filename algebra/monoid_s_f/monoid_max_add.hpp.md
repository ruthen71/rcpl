---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/monoid_f/monoid_add.hpp
    title: algebra/monoid_f/monoid_add.hpp
  - icon: ':warning:'
    path: algebra/monoid_s/monoid_max.hpp
    title: algebra/monoid_s/monoid_max.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_f/monoid_add.hpp\"\n// MF\ntemplate <class\
    \ T> struct MonoidAdd {\n    using F = T;\n    static constexpr F composition(F\
    \ f, F g) { return f + g; }\n    static constexpr F id() { return T(0); }\n};\n\
    #line 2 \"algebra/monoid_s/monoid_max.hpp\"\n// MS\ntemplate <class T> struct\
    \ MonoidMax {\n    using S = T;\n    static constexpr S op(S a, S b) { return\
    \ std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<T>::lowest();\
    \ }\n};\n#line 4 \"algebra/monoid_s_f/monoid_max_add.hpp\"\n// MSF\ntemplate <class\
    \ T> struct MonoidMaxAdd {\n    using MS = MonoidMax<T>;\n    using MF = MonoidAdd<T>;\n\
    \    using S = typename MS::S;\n    using F = typename MF::F;\n    static constexpr\
    \ S mapping(F f, S x) { return f + x; }\n};\n"
  code: "#pragma once\n#include \"../../algebra/monoid_f/monoid_add.hpp\"\n#include\
    \ \"../../algebra/monoid_s/monoid_max.hpp\"\n// MSF\ntemplate <class T> struct\
    \ MonoidMaxAdd {\n    using MS = MonoidMax<T>;\n    using MF = MonoidAdd<T>;\n\
    \    using S = typename MS::S;\n    using F = typename MF::F;\n    static constexpr\
    \ S mapping(F f, S x) { return f + x; }\n};\n"
  dependsOn:
  - algebra/monoid_f/monoid_add.hpp
  - algebra/monoid_s/monoid_max.hpp
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_max_add.hpp
  requiredBy: []
  timestamp: '2026-01-20 14:43:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s_f/monoid_max_add.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_max_add.hpp
- /library/algebra/monoid_s_f/monoid_max_add.hpp.html
title: algebra/monoid_s_f/monoid_max_add.hpp
---
