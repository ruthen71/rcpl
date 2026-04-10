---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/value_index.hpp
    title: algebra/value_index.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_max_index_plus.hpp
    title: algebra/acted_monoid/acted_monoid_max_index_plus.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_max_index.hpp\"\n\n#line 2 \"algebra/value_index.hpp\"\
    \n\ntemplate <class T> struct ValueIndex {\n    T v;\n    int i;\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const ValueIndex& x) {\n        return os << x.v;\n\
    \    }\n};\n#line 4 \"algebra/monoid/monoid_max_index.hpp\"\n\ntemplate <class\
    \ T, T inf, bool smaller_index> struct MonoidMaxIndex {\n    using value_type\
    \ = ValueIndex<T>;\n    static constexpr value_type operation(const value_type&\
    \ a,\n                                          const value_type& b) {\n     \
    \   if (a.v > b.v) return a;\n        if (a.v < b.v) return b;\n        bool is_small\
    \ = smaller_index ? (a.i < b.i) : (a.i >= b.i);\n        return is_small ? a :\
    \ b;\n    }\n    static constexpr value_type identity() noexcept { return {-inf,\
    \ -1}; }\n    static constexpr bool commutative = true;\n};\n"
  code: "#pragma once\n\n#include \"../../algebra/value_index.hpp\"\n\ntemplate <class\
    \ T, T inf, bool smaller_index> struct MonoidMaxIndex {\n    using value_type\
    \ = ValueIndex<T>;\n    static constexpr value_type operation(const value_type&\
    \ a,\n                                          const value_type& b) {\n     \
    \   if (a.v > b.v) return a;\n        if (a.v < b.v) return b;\n        bool is_small\
    \ = smaller_index ? (a.i < b.i) : (a.i >= b.i);\n        return is_small ? a :\
    \ b;\n    }\n    static constexpr value_type identity() noexcept { return {-inf,\
    \ -1}; }\n    static constexpr bool commutative = true;\n};\n"
  dependsOn:
  - algebra/value_index.hpp
  isVerificationFile: false
  path: algebra/monoid/monoid_max_index.hpp
  requiredBy:
  - algebra/acted_monoid/acted_monoid_max_index_plus.hpp
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
documentation_of: algebra/monoid/monoid_max_index.hpp
layout: document
redirect_from:
- /library/algebra/monoid/monoid_max_index.hpp
- /library/algebra/monoid/monoid_max_index.hpp.html
title: algebra/monoid/monoid_max_index.hpp
---
