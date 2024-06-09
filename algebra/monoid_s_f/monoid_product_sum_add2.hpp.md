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
    - https://atcoder.jp/contests/abc357/tasks/abc357_f
  bundledCode: "#line 2 \"algebra/monoid_s_f/monoid_product_sum_add2.hpp\"\n\n#include\
    \ <utility>\n\n// https://atcoder.jp/contests/abc357/tasks/abc357_f\ntemplate\
    \ <class T> struct MonoidProductSum {\n    using S = std::tuple<T, T, T, int>;\
    \  // sum(A[i] * B[i]), sum(A[i]), sum(B[i]), size\n    static constexpr S op(S\
    \ a, S b) {\n        auto [aab, aa, ab, as] = a;\n        auto [bab, ba, bb, bs]\
    \ = b;\n        return {aab + bab, aa + ba, ab + bb, as + bs};\n    }\n    static\
    \ constexpr S e() { return {T(0), T(0), T(0), 0}; }\n};\n\ntemplate <class T>\
    \ struct MonoidAdd2 {\n    using F = std::pair<T, T>;\n    static constexpr F\
    \ composition(F f, F g) {\n        auto [fa, fb] = f;\n        auto [ga, gb] =\
    \ g;\n        return {fa + ga, fb + gb};\n    }\n    static constexpr F id() {\
    \ return {T(0), T(0)}; }\n};\n\ntemplate <class T> struct MonoidProductSumAdd2\
    \ {\n    using MS = MonoidS<T>;\n    using MF = MonoidF<T>;\n    using S = typename\
    \ MS::S;\n    using F = typename MF::F;\n    static constexpr S mapping(F f, S\
    \ x) {\n        auto [fa, fb] = f;\n        auto [xab, xa, xb, xs] = x;\n    \
    \    return {xab + (fa * xb) + (fb * xa) + (fa * fb * xs), xa + (fa * xs), xb\
    \ + (fb * xs), xs};\n    }\n};\n"
  code: "#pragma once\n\n#include <utility>\n\n// https://atcoder.jp/contests/abc357/tasks/abc357_f\n\
    template <class T> struct MonoidProductSum {\n    using S = std::tuple<T, T, T,\
    \ int>;  // sum(A[i] * B[i]), sum(A[i]), sum(B[i]), size\n    static constexpr\
    \ S op(S a, S b) {\n        auto [aab, aa, ab, as] = a;\n        auto [bab, ba,\
    \ bb, bs] = b;\n        return {aab + bab, aa + ba, ab + bb, as + bs};\n    }\n\
    \    static constexpr S e() { return {T(0), T(0), T(0), 0}; }\n};\n\ntemplate\
    \ <class T> struct MonoidAdd2 {\n    using F = std::pair<T, T>;\n    static constexpr\
    \ F composition(F f, F g) {\n        auto [fa, fb] = f;\n        auto [ga, gb]\
    \ = g;\n        return {fa + ga, fb + gb};\n    }\n    static constexpr F id()\
    \ { return {T(0), T(0)}; }\n};\n\ntemplate <class T> struct MonoidProductSumAdd2\
    \ {\n    using MS = MonoidS<T>;\n    using MF = MonoidF<T>;\n    using S = typename\
    \ MS::S;\n    using F = typename MF::F;\n    static constexpr S mapping(F f, S\
    \ x) {\n        auto [fa, fb] = f;\n        auto [xab, xa, xb, xs] = x;\n    \
    \    return {xab + (fa * xb) + (fb * xa) + (fa * fb * xs), xa + (fa * xs), xb\
    \ + (fb * xs), xs};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_product_sum_add2.hpp
  requiredBy: []
  timestamp: '2024-06-09 21:34:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s_f/monoid_product_sum_add2.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_product_sum_add2.hpp
- /library/algebra/monoid_s_f/monoid_product_sum_add2.hpp.html
title: algebra/monoid_s_f/monoid_product_sum_add2.hpp
---
