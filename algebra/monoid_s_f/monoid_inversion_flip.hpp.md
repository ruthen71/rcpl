---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algebra/monoid_f/monoid_flip.hpp
    title: algebra/monoid_f/monoid_flip.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/tasks/practice2_l
  bundledCode: "#line 2 \"algebra/monoid_s_f/monoid_inversion_flip.hpp\"\n\n// https://atcoder.jp/contests/practice2/tasks/practice2_l\n\
    // MS\ntemplate <class T> struct MonoidInversion {\n    using S = std::tuple<T,\
    \ T, T, T>;  // {0, 1, 01, 10}\n    static constexpr S op(S a, S b) {\n      \
    \  auto&& [a0, a1, a01, a10] = a;\n        auto&& [b0, b1, b01, b10] = b;\n  \
    \      return {a0 + b0, a1 + b1, a01 + b01 + a0 * b1, a10 + b10 + a1 * b0};\n\
    \    }\n    static constexpr S e() { return {T(0), T(0), T(0), T(0)}; }\n};\n\
    #line 2 \"algebra/monoid_f/monoid_flip.hpp\"\n\n// MF\nstruct MonoidFlip {\n \
    \   using F = int;\n    static constexpr F composition(F f, F g) { return f ^\
    \ g; }\n    static constexpr F id() { return 0; }\n};\n#line 15 \"algebra/monoid_s_f/monoid_inversion_flip.hpp\"\
    \n// MSF\ntemplate <class T> struct MonoidInversionFlip {\n    using MS = MonoidInversion<T>;\n\
    \    using MF = MonoidFlip;\n    using S = typename MS::S;\n    using F = typename\
    \ MF::F;\n    static constexpr S mapping(F f, S x) {\n        if (!f) return x;\n\
    \        auto&& [x0, x1, x01, x10] = x;\n        return {x1, x0, x10, x01};\n\
    \    }\n};\n"
  code: "#pragma once\n\n// https://atcoder.jp/contests/practice2/tasks/practice2_l\n\
    // MS\ntemplate <class T> struct MonoidInversion {\n    using S = std::tuple<T,\
    \ T, T, T>;  // {0, 1, 01, 10}\n    static constexpr S op(S a, S b) {\n      \
    \  auto&& [a0, a1, a01, a10] = a;\n        auto&& [b0, b1, b01, b10] = b;\n  \
    \      return {a0 + b0, a1 + b1, a01 + b01 + a0 * b1, a10 + b10 + a1 * b0};\n\
    \    }\n    static constexpr S e() { return {T(0), T(0), T(0), T(0)}; }\n};\n\
    #include \"../../algebra/monoid_f/monoid_flip.hpp\"\n// MSF\ntemplate <class T>\
    \ struct MonoidInversionFlip {\n    using MS = MonoidInversion<T>;\n    using\
    \ MF = MonoidFlip;\n    using S = typename MS::S;\n    using F = typename MF::F;\n\
    \    static constexpr S mapping(F f, S x) {\n        if (!f) return x;\n     \
    \   auto&& [x0, x1, x01, x10] = x;\n        return {x1, x0, x10, x01};\n    }\n\
    };\n"
  dependsOn:
  - algebra/monoid_f/monoid_flip.hpp
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_inversion_flip.hpp
  requiredBy: []
  timestamp: '2026-01-20 14:43:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s_f/monoid_inversion_flip.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_inversion_flip.hpp
- /library/algebra/monoid_s_f/monoid_inversion_flip.hpp.html
title: algebra/monoid_s_f/monoid_inversion_flip.hpp
---
