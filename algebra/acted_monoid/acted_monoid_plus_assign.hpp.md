---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_assign.hpp
    title: algebra/monoid/monoid_assign.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
    title: segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/acted_monoid/acted_monoid_plus_assign.hpp\"\n\n\
    #line 2 \"algebra/monoid/monoid_assign.hpp\"\n\ntemplate <class T, T none> struct\
    \ MonoidAssign {\n    using value_type = T;\n    static constexpr T operation(const\
    \ T& a, const T& b) noexcept {\n        if (b == identity()) {\n            return\
    \ a;\n        }\n        return b;\n    }\n    static constexpr T identity() noexcept\
    \ { return none; }\n    static constexpr bool commutative = false;\n};\n#line\
    \ 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate <class T> struct MonoidPlus\
    \ {\n    using value_type = T;\n    static constexpr T operation(const T& a, const\
    \ T& b) noexcept {\n        return a + b;\n    }\n    static constexpr T identity()\
    \ noexcept { return T(0); }\n    static constexpr T inverse(const T& a) noexcept\
    \ { return -a; }\n    static constexpr bool commutative = true;\n};\n#line 5 \"\
    algebra/acted_monoid/acted_monoid_plus_assign.hpp\"\n\ntemplate <class T, T none>\
    \ struct ActedMonoidPlusAssign {\n    using MS = MonoidPlus<T>;\n    using MF\
    \ = MonoidAssign<T, none>;\n    using S = typename MS::value_type;\n    using\
    \ F = typename MF::value_type;\n    static constexpr S mapping(const F f, const\
    \ S x, const int size) {\n        if (f == MF::identity()) {\n            return\
    \ x;\n        }\n        return f * T(size);\n    }\n};\n"
  code: "#pragma once\n\n#include \"../monoid/monoid_assign.hpp\"\n#include \"../monoid/monoid_plus.hpp\"\
    \n\ntemplate <class T, T none> struct ActedMonoidPlusAssign {\n    using MS =\
    \ MonoidPlus<T>;\n    using MF = MonoidAssign<T, none>;\n    using S = typename\
    \ MS::value_type;\n    using F = typename MF::value_type;\n    static constexpr\
    \ S mapping(const F f, const S x, const int size) {\n        if (f == MF::identity())\
    \ {\n            return x;\n        }\n        return f * T(size);\n    }\n};\n"
  dependsOn:
  - algebra/monoid/monoid_assign.hpp
  - algebra/monoid/monoid_plus.hpp
  isVerificationFile: false
  path: algebra/acted_monoid/acted_monoid_plus_assign.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_plus_assign.test.cpp
documentation_of: algebra/acted_monoid/acted_monoid_plus_assign.hpp
layout: document
redirect_from:
- /library/algebra/acted_monoid/acted_monoid_plus_assign.hpp
- /library/algebra/acted_monoid/acted_monoid_plus_assign.hpp.html
title: algebra/acted_monoid/acted_monoid_plus_assign.hpp
---
