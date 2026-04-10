---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_xor.hpp
    title: algebra/monoid/monoid_xor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
    title: segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/tasks/practice2_l
  bundledCode: "#line 2 \"algebra/acted_monoid/acted_monoid_inversion01_flip.hpp\"\
    \n\n#line 2 \"algebra/monoid/monoid_xor.hpp\"\n\ntemplate <class T> struct MonoidXor\
    \ {\n    using value_type = T;\n    static constexpr T operation(const T& a, const\
    \ T& b) noexcept {\n        return a ^ b;\n    }\n    static constexpr T identity()\
    \ noexcept { return T(0); }\n    static constexpr T inverse(const T& a) noexcept\
    \ { return a; }\n    static constexpr bool commutative = true;\n};\n#line 4 \"\
    algebra/acted_monoid/acted_monoid_inversion01_flip.hpp\"\n\n// https://atcoder.jp/contests/practice2/tasks/practice2_l\n\
    template <class T> struct Inversion01 {\n    // c0: 0 \u306E\u500B\u6570, c1:\
    \ 1 \u306E\u500B\u6570, c10: \u8EE2\u5012\u6570\n    T c0, c1, c10;\n};\n\ntemplate\
    \ <class T> struct MonoidInversion01 {\n    using value_type = Inversion01<T>;\n\
    \    static constexpr value_type operation(const value_type& a,\n            \
    \                              const value_type& b) {\n        return {a.c0 +\
    \ b.c0, a.c1 + b.c1, a.c10 + b.c10 + a.c1 * b.c0};\n    }\n    static constexpr\
    \ value_type identity() { return {T(0), T(0), T(0)}; }\n};\n\ntemplate <class\
    \ T> struct ActedMonoidInversion01Flip {\n    using MS = MonoidInversion01<T>;\n\
    \    using MF = MonoidXor<int>;\n    using S = typename MS::value_type;\n    using\
    \ F = typename MF::value_type;\n    static constexpr S mapping(const F f, S x,\
    \ const int size) {\n        if (f == MF::identity()) {\n            return x;\n\
    \        }\n        return {x.c1, x.c0, x.c0 * x.c1 - x.c10};\n    }\n};\n"
  code: "#pragma once\n\n#include \"../monoid/monoid_xor.hpp\"\n\n// https://atcoder.jp/contests/practice2/tasks/practice2_l\n\
    template <class T> struct Inversion01 {\n    // c0: 0 \u306E\u500B\u6570, c1:\
    \ 1 \u306E\u500B\u6570, c10: \u8EE2\u5012\u6570\n    T c0, c1, c10;\n};\n\ntemplate\
    \ <class T> struct MonoidInversion01 {\n    using value_type = Inversion01<T>;\n\
    \    static constexpr value_type operation(const value_type& a,\n            \
    \                              const value_type& b) {\n        return {a.c0 +\
    \ b.c0, a.c1 + b.c1, a.c10 + b.c10 + a.c1 * b.c0};\n    }\n    static constexpr\
    \ value_type identity() { return {T(0), T(0), T(0)}; }\n};\n\ntemplate <class\
    \ T> struct ActedMonoidInversion01Flip {\n    using MS = MonoidInversion01<T>;\n\
    \    using MF = MonoidXor<int>;\n    using S = typename MS::value_type;\n    using\
    \ F = typename MF::value_type;\n    static constexpr S mapping(const F f, S x,\
    \ const int size) {\n        if (f == MF::identity()) {\n            return x;\n\
    \        }\n        return {x.c1, x.c0, x.c0 * x.c1 - x.c10};\n    }\n};\n"
  dependsOn:
  - algebra/monoid/monoid_xor.hpp
  isVerificationFile: false
  path: algebra/acted_monoid/acted_monoid_inversion01_flip.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_inversion01_flip.test.cpp
documentation_of: algebra/acted_monoid/acted_monoid_inversion01_flip.hpp
layout: document
redirect_from:
- /library/algebra/acted_monoid/acted_monoid_inversion01_flip.hpp
- /library/algebra/acted_monoid/acted_monoid_inversion01_flip.hpp.html
title: algebra/acted_monoid/acted_monoid_inversion01_flip.hpp
---
