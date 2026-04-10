---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_product_sum_add2.test.cpp
    title: segment_tree/test/lazy_segment_tree_product_sum_add2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc357/tasks/abc357_f
  bundledCode: "#line 2 \"algebra/acted_monoid/acted_monoid_product_sum_add2.hpp\"\
    \n\n// https://atcoder.jp/contests/abc357/tasks/abc357_f\ntemplate <class T> struct\
    \ ProductSum {\n    T ab, a, b;\n};\n\ntemplate <class T> struct MonoidProductSum\
    \ {\n    using value_type = ProductSum<T>;\n    static constexpr value_type operation(const\
    \ value_type& a,\n                                          const value_type&\
    \ b) {\n        return {a.ab + b.ab, a.a + b.a, a.b + b.b};\n    }\n    static\
    \ constexpr value_type identity() { return {T(0), T(0), T(0)}; }\n};\n\ntemplate\
    \ <class T> struct Add2 {\n    T a, b;\n};\n\ntemplate <class T> struct MonoidAdd2\
    \ {\n    using value_type = Add2<T>;\n    static constexpr value_type operation(const\
    \ value_type& f,\n                                          const value_type&\
    \ g) {\n        return {f.a + g.a, f.b + g.b};\n    }\n    static constexpr value_type\
    \ identity() { return {T(0), T(0)}; }\n};\n\ntemplate <class T> struct ActedMonoidProductSumAdd2\
    \ {\n    using MS = MonoidProductSum<T>;\n    using MF = MonoidAdd2<T>;\n    using\
    \ S = typename MS::value_type;\n    using F = typename MF::value_type;\n    static\
    \ constexpr S mapping(const F f, const S x, const int size) {\n        return\
    \ {x.ab + f.a * x.b + f.b * x.a + f.a * f.b * T(size),\n                x.a +\
    \ f.a * T(size), x.b + f.b * T(size)};\n    }\n};\n"
  code: "#pragma once\n\n// https://atcoder.jp/contests/abc357/tasks/abc357_f\ntemplate\
    \ <class T> struct ProductSum {\n    T ab, a, b;\n};\n\ntemplate <class T> struct\
    \ MonoidProductSum {\n    using value_type = ProductSum<T>;\n    static constexpr\
    \ value_type operation(const value_type& a,\n                                \
    \          const value_type& b) {\n        return {a.ab + b.ab, a.a + b.a, a.b\
    \ + b.b};\n    }\n    static constexpr value_type identity() { return {T(0), T(0),\
    \ T(0)}; }\n};\n\ntemplate <class T> struct Add2 {\n    T a, b;\n};\n\ntemplate\
    \ <class T> struct MonoidAdd2 {\n    using value_type = Add2<T>;\n    static constexpr\
    \ value_type operation(const value_type& f,\n                                \
    \          const value_type& g) {\n        return {f.a + g.a, f.b + g.b};\n  \
    \  }\n    static constexpr value_type identity() { return {T(0), T(0)}; }\n};\n\
    \ntemplate <class T> struct ActedMonoidProductSumAdd2 {\n    using MS = MonoidProductSum<T>;\n\
    \    using MF = MonoidAdd2<T>;\n    using S = typename MS::value_type;\n    using\
    \ F = typename MF::value_type;\n    static constexpr S mapping(const F f, const\
    \ S x, const int size) {\n        return {x.ab + f.a * x.b + f.b * x.a + f.a *\
    \ f.b * T(size),\n                x.a + f.a * T(size), x.b + f.b * T(size)};\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/acted_monoid/acted_monoid_product_sum_add2.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_product_sum_add2.test.cpp
documentation_of: algebra/acted_monoid/acted_monoid_product_sum_add2.hpp
layout: document
redirect_from:
- /library/algebra/acted_monoid/acted_monoid_product_sum_add2.hpp
- /library/algebra/acted_monoid/acted_monoid_product_sum_add2.hpp.html
title: algebra/acted_monoid/acted_monoid_product_sum_add2.hpp
---
