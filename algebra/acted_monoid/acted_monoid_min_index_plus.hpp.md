---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_min_index.hpp
    title: algebra/monoid/monoid_min_index.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/value_index.hpp
    title: algebra/value_index.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/acted_monoid/acted_monoid_min_index_plus.hpp\"\n\
    \n#line 2 \"algebra/monoid/monoid_min_index.hpp\"\n\n#line 2 \"algebra/value_index.hpp\"\
    \n\ntemplate <class T> struct ValueIndex {\n    T v;\n    int i;\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const ValueIndex& x) {\n        return os << x.v;\n\
    \    }\n};\n#line 4 \"algebra/monoid/monoid_min_index.hpp\"\n\ntemplate <class\
    \ T, T inf, bool smaller_index> struct MonoidMinIndex {\n    using value_type\
    \ = ValueIndex<T>;\n    static constexpr value_type operation(const value_type&\
    \ a,\n                                          const value_type& b) {\n     \
    \   if (a.v < b.v) return a;\n        if (a.v > b.v) return b;\n        bool is_small\
    \ = smaller_index ? (a.i < b.i) : (a.i >= b.i);\n        return is_small ? a :\
    \ b;\n    }\n    static constexpr value_type identity() noexcept { return {inf,\
    \ -1}; }\n    static constexpr bool commutative = true;\n};\n#line 2 \"algebra/monoid/monoid_plus.hpp\"\
    \n\ntemplate <class T> struct MonoidPlus {\n    using value_type = T;\n    static\
    \ constexpr T operation(const T& a, const T& b) noexcept {\n        return a +\
    \ b;\n    }\n    static constexpr T identity() noexcept { return T(0); }\n   \
    \ static constexpr T inverse(const T& a) noexcept { return -a; }\n    static constexpr\
    \ bool commutative = true;\n};\n#line 5 \"algebra/acted_monoid/acted_monoid_min_index_plus.hpp\"\
    \n\ntemplate <class T, T inf, bool smaller_index> struct ActedMonoidMinIndexPlus\
    \ {\n    using MS = MonoidMinIndex<T, inf, smaller_index>;\n    using MF = MonoidPlus<T>;\n\
    \    using S = typename MS::value_type;\n    using F = typename MF::value_type;\n\
    \    static constexpr S mapping(const F f, const S x, const int size) {\n    \
    \    if (f == MF::identity()) {\n            return {x.v, x.i};\n        }\n \
    \       return {x.v + f, x.i};\n    }\n};\n"
  code: "#pragma once\n\n#include \"../monoid/monoid_min_index.hpp\"\n#include \"\
    ../monoid/monoid_plus.hpp\"\n\ntemplate <class T, T inf, bool smaller_index> struct\
    \ ActedMonoidMinIndexPlus {\n    using MS = MonoidMinIndex<T, inf, smaller_index>;\n\
    \    using MF = MonoidPlus<T>;\n    using S = typename MS::value_type;\n    using\
    \ F = typename MF::value_type;\n    static constexpr S mapping(const F f, const\
    \ S x, const int size) {\n        if (f == MF::identity()) {\n            return\
    \ {x.v, x.i};\n        }\n        return {x.v + f, x.i};\n    }\n};\n"
  dependsOn:
  - algebra/monoid/monoid_min_index.hpp
  - algebra/value_index.hpp
  - algebra/monoid/monoid_plus.hpp
  isVerificationFile: false
  path: algebra/acted_monoid/acted_monoid_min_index_plus.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
documentation_of: algebra/acted_monoid/acted_monoid_min_index_plus.hpp
layout: document
redirect_from:
- /library/algebra/acted_monoid/acted_monoid_min_index_plus.hpp
- /library/algebra/acted_monoid/acted_monoid_min_index_plus.hpp.html
title: algebra/acted_monoid/acted_monoid_min_index_plus.hpp
---
