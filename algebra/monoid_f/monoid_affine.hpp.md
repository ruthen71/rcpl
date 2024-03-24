---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s_f/monoid_sum_size_affine.hpp
    title: algebra/monoid_s_f/monoid_sum_size_affine.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
    title: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_f/monoid_affine.hpp\"\n// MF\ntemplate <class\
    \ T> struct MonoidAffine {\n    using F = std::pair<T, T>;  // a * x + b -> {a,\
    \ b}\n    // f(x) = f.first * x + f.second, g(x) = g.first * x + g.second\n  \
    \  // f(g(x)) = f.first * (g.first * x + g.second) + f.second\n    //        \
    \ = f.first * g.first * x + f.first * g.second + f.second\n    static constexpr\
    \ F composition(F f, F g) { return {f.first * g.first, f.first * g.second + f.second};\
    \ }\n    static constexpr F id() { return {T(1), T(0)}; }\n};\n"
  code: "#pragma once\n// MF\ntemplate <class T> struct MonoidAffine {\n    using\
    \ F = std::pair<T, T>;  // a * x + b -> {a, b}\n    // f(x) = f.first * x + f.second,\
    \ g(x) = g.first * x + g.second\n    // f(g(x)) = f.first * (g.first * x + g.second)\
    \ + f.second\n    //         = f.first * g.first * x + f.first * g.second + f.second\n\
    \    static constexpr F composition(F f, F g) { return {f.first * g.first, f.first\
    \ * g.second + f.second}; }\n    static constexpr F id() { return {T(1), T(0)};\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_f/monoid_affine.hpp
  requiredBy:
  - algebra/monoid_s_f/monoid_sum_size_affine.hpp
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
documentation_of: algebra/monoid_f/monoid_affine.hpp
layout: document
redirect_from:
- /library/algebra/monoid_f/monoid_affine.hpp
- /library/algebra/monoid_f/monoid_affine.hpp.html
title: algebra/monoid_f/monoid_affine.hpp
---
