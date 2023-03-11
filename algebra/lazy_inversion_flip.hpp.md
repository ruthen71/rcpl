---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/tasks/practice2_l
  bundledCode: "#line 2 \"algebra/lazy_inversion_flip.hpp\"\n\n// https://atcoder.jp/contests/practice2/tasks/practice2_l\n\
    template <class T> struct LazyInversionFlip {\n    using S = std::tuple<T, T,\
    \ T, T>;  // {0, 1, 01, 10}\n    using F = bool;\n    using value_type_S = S;\n\
    \    using value_type_F = F;\n    static constexpr S op(S a, S b) {\n        auto\
    \ &&[a0, a1, a01, a10] = a;\n        auto &&[b0, b1, b01, b10] = b;\n        return\
    \ {a0 + b0, a1 + b1, a01 + b01 + a0 * b1, a10 + b10 + a1 * b0};\n    }\n    static\
    \ constexpr S e() { return {0, 0, 0, 0}; }\n    static constexpr S mapping(F f,\
    \ S x) {\n        auto &&[x0, x1, x01, x10] = x;\n        if (f) {\n         \
    \   return {x1, x0, x10, x01};\n        } else {\n            return x;\n    \
    \    }\n    }\n    static constexpr F composition(F f, F g) { return f ^ g; }\n\
    \    static constexpr F id() { return false; }\n};\n"
  code: "#pragma once\n\n// https://atcoder.jp/contests/practice2/tasks/practice2_l\n\
    template <class T> struct LazyInversionFlip {\n    using S = std::tuple<T, T,\
    \ T, T>;  // {0, 1, 01, 10}\n    using F = bool;\n    using value_type_S = S;\n\
    \    using value_type_F = F;\n    static constexpr S op(S a, S b) {\n        auto\
    \ &&[a0, a1, a01, a10] = a;\n        auto &&[b0, b1, b01, b10] = b;\n        return\
    \ {a0 + b0, a1 + b1, a01 + b01 + a0 * b1, a10 + b10 + a1 * b0};\n    }\n    static\
    \ constexpr S e() { return {0, 0, 0, 0}; }\n    static constexpr S mapping(F f,\
    \ S x) {\n        auto &&[x0, x1, x01, x10] = x;\n        if (f) {\n         \
    \   return {x1, x0, x10, x01};\n        } else {\n            return x;\n    \
    \    }\n    }\n    static constexpr F composition(F f, F g) { return f ^ g; }\n\
    \    static constexpr F id() { return false; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/lazy_inversion_flip.hpp
  requiredBy: []
  timestamp: '2023-03-12 00:30:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/lazy_inversion_flip.hpp
layout: document
redirect_from:
- /library/algebra/lazy_inversion_flip.hpp
- /library/algebra/lazy_inversion_flip.hpp.html
title: algebra/lazy_inversion_flip.hpp
---
