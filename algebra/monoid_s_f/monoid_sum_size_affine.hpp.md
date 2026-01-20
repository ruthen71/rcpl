---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_f/monoid_affine.hpp
    title: algebra/monoid_f/monoid_affine.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s/monoid_sum_size.hpp
    title: algebra/monoid_s/monoid_sum_size.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
    title: verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/tasks/practice2_k
  bundledCode: "#line 2 \"algebra/monoid_f/monoid_affine.hpp\"\n// MF\ntemplate <class\
    \ T> struct MonoidAffine {\n    using F = std::pair<T, T>;  // a * x + b -> {a,\
    \ b}\n    // f(x) = f.first * x + f.second, g(x) = g.first * x + g.second\n  \
    \  // f(g(x)) = f.first * (g.first * x + g.second) + f.second\n    //        \
    \ = f.first * g.first * x + f.first * g.second + f.second\n    static constexpr\
    \ F composition(F f, F g) { return {f.first * g.first, f.first * g.second + f.second};\
    \ }\n    static constexpr F id() { return {T(1), T(0)}; }\n};\n#line 2 \"algebra/monoid_s/monoid_sum_size.hpp\"\
    \n// MS\ntemplate <class T> struct MonoidSumSize {\n    using S = std::pair<T,\
    \ int>;\n    static constexpr S op(S a, S b) { return {a.first + b.first, a.second\
    \ + b.second}; }\n    static constexpr S e() { return {T(0), 0}; }\n};\n#line\
    \ 4 \"algebra/monoid_s_f/monoid_sum_size_affine.hpp\"\n// https://atcoder.jp/contests/practice2/tasks/practice2_k\n\
    // MSF\ntemplate <class T> struct MonoidSumSizeAffine {\n    using MS = MonoidSumSize<T>;\n\
    \    using MF = MonoidAffine<T>;\n    using S = typename MS::S;\n    using F =\
    \ typename MF::F;\n    static constexpr S mapping(F f, S x) {\n        return\
    \ {f.first * x.first + f.second * x.second, x.second};\n    }\n};\n"
  code: "#pragma once\n#include \"../../algebra/monoid_f/monoid_affine.hpp\"\n#include\
    \ \"../../algebra/monoid_s/monoid_sum_size.hpp\"\n// https://atcoder.jp/contests/practice2/tasks/practice2_k\n\
    // MSF\ntemplate <class T> struct MonoidSumSizeAffine {\n    using MS = MonoidSumSize<T>;\n\
    \    using MF = MonoidAffine<T>;\n    using S = typename MS::S;\n    using F =\
    \ typename MF::F;\n    static constexpr S mapping(F f, S x) {\n        return\
    \ {f.first * x.first + f.second * x.second, x.second};\n    }\n};\n"
  dependsOn:
  - algebra/monoid_f/monoid_affine.hpp
  - algebra/monoid_s/monoid_sum_size.hpp
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_sum_size_affine.hpp
  requiredBy: []
  timestamp: '2026-01-20 14:43:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_range_affine_range_sum.test.cpp
documentation_of: algebra/monoid_s_f/monoid_sum_size_affine.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_sum_size_affine.hpp
- /library/algebra/monoid_s_f/monoid_sum_size_affine.hpp.html
title: algebra/monoid_s_f/monoid_sum_size_affine.hpp
---
