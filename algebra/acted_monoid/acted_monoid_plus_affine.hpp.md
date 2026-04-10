---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_affine.hpp
    title: algebra/monoid/monoid_affine.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
    title: segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/acted_monoid/acted_monoid_plus_affine.hpp\"\n\n\
    #line 2 \"algebra/monoid/monoid_affine.hpp\"\n\ntemplate <class T> struct Affine\
    \ {\n    T a;\n    T b;\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const Affine& f) {\n        return os << f.a << \", \" << f.b;\n    }\n};\n\n\
    template <class T> struct MonoidAffine {\n    using value_type = Affine<T>;\n\
    \    static constexpr value_type operation(const value_type& f,\n            \
    \                              const value_type& g) noexcept {\n        // f(x)\
    \ := ax + b, g(x) := cx + d\n        // g(f(x)) = c(ax + b) + d = cax + cb + d\n\
    \        return {g.a * f.a, g.a * f.b + g.b};\n    }\n    static constexpr value_type\
    \ identity() noexcept { return {T(1), T(0)}; }\n};\n#line 2 \"algebra/monoid/monoid_plus.hpp\"\
    \n\ntemplate <class T> struct MonoidPlus {\n    using value_type = T;\n    static\
    \ constexpr T operation(const T& a, const T& b) noexcept {\n        return a +\
    \ b;\n    }\n    static constexpr T identity() noexcept { return T(0); }\n   \
    \ static constexpr T inverse(const T& a) noexcept { return -a; }\n    static constexpr\
    \ bool commutative = true;\n};\n#line 5 \"algebra/acted_monoid/acted_monoid_plus_affine.hpp\"\
    \n\ntemplate <class T> struct ActedMonoidPlusAffine {\n    using MS = MonoidPlus<T>;\n\
    \    using MF = MonoidAffine<T>;\n    using S = typename MS::value_type;\n   \
    \ using F = typename MF::value_type;\n    static constexpr S mapping(const F f,\
    \ const S x, const int size) {\n        return f.a * x + f.b * T(size);\n    }\n\
    };\n"
  code: "#pragma once\n\n#include \"../monoid/monoid_affine.hpp\"\n#include \"../monoid/monoid_plus.hpp\"\
    \n\ntemplate <class T> struct ActedMonoidPlusAffine {\n    using MS = MonoidPlus<T>;\n\
    \    using MF = MonoidAffine<T>;\n    using S = typename MS::value_type;\n   \
    \ using F = typename MF::value_type;\n    static constexpr S mapping(const F f,\
    \ const S x, const int size) {\n        return f.a * x + f.b * T(size);\n    }\n\
    };\n"
  dependsOn:
  - algebra/monoid/monoid_affine.hpp
  - algebra/monoid/monoid_plus.hpp
  isVerificationFile: false
  path: algebra/acted_monoid/acted_monoid_plus_affine.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_sum_affine.test.cpp
documentation_of: algebra/acted_monoid/acted_monoid_plus_affine.hpp
layout: document
redirect_from:
- /library/algebra/acted_monoid/acted_monoid_plus_affine.hpp
- /library/algebra/acted_monoid/acted_monoid_plus_affine.hpp.html
title: algebra/acted_monoid/acted_monoid_plus_affine.hpp
---
