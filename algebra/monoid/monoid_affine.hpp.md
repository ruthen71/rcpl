---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_plus_affine.hpp
    title: algebra/acted_monoid/acted_monoid_plus_affine.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
    title: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_affine.hpp\"\n\ntemplate <class T>\
    \ struct Affine {\n    T a;\n    T b;\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Affine& f) {\n        return os << f.a << \", \" << f.b;\n    }\n\
    };\n\ntemplate <class T> struct MonoidAffine {\n    using value_type = Affine<T>;\n\
    \    static constexpr value_type operation(const value_type& f,\n            \
    \                              const value_type& g) noexcept {\n        // f(x)\
    \ := ax + b, g(x) := cx + d\n        // g(f(x)) = c(ax + b) + d = cax + cb + d\n\
    \        return {g.a * f.a, g.a * f.b + g.b};\n    }\n    static constexpr value_type\
    \ identity() noexcept { return {T(1), T(0)}; }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct Affine {\n    T a;\n    T b;\n\
    \    friend std::ostream& operator<<(std::ostream& os, const Affine& f) {\n  \
    \      return os << f.a << \", \" << f.b;\n    }\n};\n\ntemplate <class T> struct\
    \ MonoidAffine {\n    using value_type = Affine<T>;\n    static constexpr value_type\
    \ operation(const value_type& f,\n                                          const\
    \ value_type& g) noexcept {\n        // f(x) := ax + b, g(x) := cx + d\n     \
    \   // g(f(x)) = c(ax + b) + d = cax + cb + d\n        return {g.a * f.a, g.a\
    \ * f.b + g.b};\n    }\n    static constexpr value_type identity() noexcept {\
    \ return {T(1), T(0)}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/monoid_affine.hpp
  requiredBy:
  - algebra/acted_monoid/acted_monoid_plus_affine.hpp
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
documentation_of: algebra/monoid/monoid_affine.hpp
layout: document
redirect_from:
- /library/algebra/monoid/monoid_affine.hpp
- /library/algebra/monoid/monoid_affine.hpp.html
title: algebra/monoid/monoid_affine.hpp
---
