---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_xor.hpp
    title: algebra/monoid/monoid_xor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
    title: segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc322/tasks/abc322_f
  bundledCode: "#line 2 \"algebra/acted_monoid/acted_monoid_max01_flip.hpp\"\n\n#include\
    \ <algorithm>\n\n#line 2 \"algebra/monoid/monoid_xor.hpp\"\n\ntemplate <class\
    \ T> struct MonoidXor {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        return a ^ b;\n    }\n    static constexpr\
    \ T identity() noexcept { return T(0); }\n    static constexpr T inverse(const\
    \ T& a) noexcept { return a; }\n    static constexpr bool commutative = true;\n\
    };\n#line 6 \"algebra/acted_monoid/acted_monoid_max01_flip.hpp\"\n\n// https://atcoder.jp/contests/abc322/tasks/abc322_f\n\
    template <class T> struct Max01 {\n    // m: \u6700\u5927\u9577, l: \u5DE6\u7AEF\
    \u304B\u3089\u306E\u9023\u7D9A\u500B\u6570, r: \u53F3\u7AEF\u304B\u3089\u306E\u9023\
    \u7D9A\u500B\u6570\n    T m0, l0, r0, m1, l1, r1, size;\n};\n\ntemplate <class\
    \ T> struct MonoidMax01 {\n    using value_type = Max01<T>;\n    static constexpr\
    \ value_type operation(const value_type& a,\n                                \
    \          const value_type& b) {\n        return {std::max({a.m0, b.m0, a.r0\
    \ + b.l0}),\n                (a.size == a.l0 ? a.size + b.l0 : a.l0),\n      \
    \          (b.size == b.r0 ? a.r0 + b.size : b.r0),\n                std::max({a.m1,\
    \ b.m1, a.r1 + b.l1}),\n                (a.size == a.l1 ? a.size + b.l1 : a.l1),\n\
    \                (b.size == b.r1 ? a.r1 + b.size : b.r1),\n                a.size\
    \ + b.size};\n    }\n    static constexpr value_type identity() { return {0, 0,\
    \ 0, 0, 0, 0, 0}; }\n};\n\ntemplate <class T> struct ActedMonoidMax01Flip {\n\
    \    using MS = MonoidMax01<T>;\n    using MF = MonoidXor<int>;\n    using S =\
    \ typename MS::value_type;\n    using F = typename MF::value_type;\n    static\
    \ constexpr S mapping(const F f, S x, const int size) {\n        if (f == MF::identity())\
    \ {\n            return x;\n        }\n        return {x.m1, x.l1, x.r1, x.m0,\
    \ x.l0, x.r0, x.size};\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n\n#include \"../monoid/monoid_xor.hpp\"\
    \n\n// https://atcoder.jp/contests/abc322/tasks/abc322_f\ntemplate <class T> struct\
    \ Max01 {\n    // m: \u6700\u5927\u9577, l: \u5DE6\u7AEF\u304B\u3089\u306E\u9023\
    \u7D9A\u500B\u6570, r: \u53F3\u7AEF\u304B\u3089\u306E\u9023\u7D9A\u500B\u6570\n\
    \    T m0, l0, r0, m1, l1, r1, size;\n};\n\ntemplate <class T> struct MonoidMax01\
    \ {\n    using value_type = Max01<T>;\n    static constexpr value_type operation(const\
    \ value_type& a,\n                                          const value_type&\
    \ b) {\n        return {std::max({a.m0, b.m0, a.r0 + b.l0}),\n               \
    \ (a.size == a.l0 ? a.size + b.l0 : a.l0),\n                (b.size == b.r0 ?\
    \ a.r0 + b.size : b.r0),\n                std::max({a.m1, b.m1, a.r1 + b.l1}),\n\
    \                (a.size == a.l1 ? a.size + b.l1 : a.l1),\n                (b.size\
    \ == b.r1 ? a.r1 + b.size : b.r1),\n                a.size + b.size};\n    }\n\
    \    static constexpr value_type identity() { return {0, 0, 0, 0, 0, 0, 0}; }\n\
    };\n\ntemplate <class T> struct ActedMonoidMax01Flip {\n    using MS = MonoidMax01<T>;\n\
    \    using MF = MonoidXor<int>;\n    using S = typename MS::value_type;\n    using\
    \ F = typename MF::value_type;\n    static constexpr S mapping(const F f, S x,\
    \ const int size) {\n        if (f == MF::identity()) {\n            return x;\n\
    \        }\n        return {x.m1, x.l1, x.r1, x.m0, x.l0, x.r0, x.size};\n   \
    \ }\n};\n"
  dependsOn:
  - algebra/monoid/monoid_xor.hpp
  isVerificationFile: false
  path: algebra/acted_monoid/acted_monoid_max01_flip.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_max01_flip.test.cpp
documentation_of: algebra/acted_monoid/acted_monoid_max01_flip.hpp
layout: document
redirect_from:
- /library/algebra/acted_monoid/acted_monoid_max01_flip.hpp
- /library/algebra/acted_monoid/acted_monoid_max01_flip.hpp.html
title: algebra/acted_monoid/acted_monoid_max01_flip.hpp
---
