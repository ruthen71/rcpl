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
    - https://atcoder.jp/contests/practice2/tasks/practice2_k
  bundledCode: "#line 2 \"algebra/lazy_sum_affine.hpp\"\n\n// https://atcoder.jp/contests/practice2/tasks/practice2_k\n\
    template <class T> struct LazySumAffine {\n    using S = std::pair<T, int>;\n\
    \    using F = std::pair<T, T>;  // a * x + b -> {a, b}\n    using value_type_S\
    \ = S;\n    using value_type_F = F;\n    static constexpr S op(S a, S b) { return\
    \ {a.first + b.first, a.second + b.second}; }\n    static constexpr S e() { return\
    \ {T(0), 0}; }\n    // f(x) = f.first * x + f.second, g(x) = g.first * x + g.second\n\
    \    // f(g(x)) = f.first * (g.first * x + g.second) + f.second\n    //      \
    \   = f.first * g.first * x + f.first * g.second + f.second\n    static constexpr\
    \ S mapping(F f, S x) { return {f.first * x.first + f.second * x.second, x.second};\
    \ }\n    static constexpr F composition(F f, F g) { return {f.first * g.first,\
    \ f.first * g.second + f.second}; }\n    static constexpr F id() { return {T(1),\
    \ T(0)}; }\n};\n"
  code: "#pragma once\n\n// https://atcoder.jp/contests/practice2/tasks/practice2_k\n\
    template <class T> struct LazySumAffine {\n    using S = std::pair<T, int>;\n\
    \    using F = std::pair<T, T>;  // a * x + b -> {a, b}\n    using value_type_S\
    \ = S;\n    using value_type_F = F;\n    static constexpr S op(S a, S b) { return\
    \ {a.first + b.first, a.second + b.second}; }\n    static constexpr S e() { return\
    \ {T(0), 0}; }\n    // f(x) = f.first * x + f.second, g(x) = g.first * x + g.second\n\
    \    // f(g(x)) = f.first * (g.first * x + g.second) + f.second\n    //      \
    \   = f.first * g.first * x + f.first * g.second + f.second\n    static constexpr\
    \ S mapping(F f, S x) { return {f.first * x.first + f.second * x.second, x.second};\
    \ }\n    static constexpr F composition(F f, F g) { return {f.first * g.first,\
    \ f.first * g.second + f.second}; }\n    static constexpr F id() { return {T(1),\
    \ T(0)}; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/lazy_sum_affine.hpp
  requiredBy: []
  timestamp: '2023-03-12 00:30:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/lazy_sum_affine.hpp
layout: document
redirect_from:
- /library/algebra/lazy_sum_affine.hpp
- /library/algebra/lazy_sum_affine.hpp.html
title: algebra/lazy_sum_affine.hpp
---
