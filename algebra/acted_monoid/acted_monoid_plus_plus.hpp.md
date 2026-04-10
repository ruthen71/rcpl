---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
    title: verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/acted_monoid/acted_monoid_plus_plus.hpp\"\n\n#line\
    \ 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate <class T> struct MonoidPlus\
    \ {\n    using value_type = T;\n    static constexpr T operation(const T& a, const\
    \ T& b) noexcept {\n        return a + b;\n    }\n    static constexpr T identity()\
    \ noexcept { return T(0); }\n    static constexpr T inverse(const T& a) noexcept\
    \ { return -a; }\n    static constexpr bool commutative = true;\n};\n#line 4 \"\
    algebra/acted_monoid/acted_monoid_plus_plus.hpp\"\n\ntemplate <class T> struct\
    \ ActedMonoidPlusPlus {\n    using MS = MonoidPlus<T>;\n    using MF = MonoidPlus<T>;\n\
    \    using S = typename MS::value_type;\n    using F = typename MF::value_type;\n\
    \    static constexpr S mapping(const F f, const S x, const int size) {\n    \
    \    return x + f * T(size);\n    }\n};\n"
  code: "#pragma once\n\n#include \"../monoid/monoid_plus.hpp\"\n\ntemplate <class\
    \ T> struct ActedMonoidPlusPlus {\n    using MS = MonoidPlus<T>;\n    using MF\
    \ = MonoidPlus<T>;\n    using S = typename MS::value_type;\n    using F = typename\
    \ MF::value_type;\n    static constexpr S mapping(const F f, const S x, const\
    \ int size) {\n        return x + f * T(size);\n    }\n};\n"
  dependsOn:
  - algebra/monoid/monoid_plus.hpp
  isVerificationFile: false
  path: algebra/acted_monoid/acted_monoid_plus_plus.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/heavy_light_decomposition_path_add_path_sum.test.cpp
  - segment_tree/test/lazy_segment_tree_plus_plus.test.cpp
documentation_of: algebra/acted_monoid/acted_monoid_plus_plus.hpp
layout: document
redirect_from:
- /library/algebra/acted_monoid/acted_monoid_plus_plus.hpp
- /library/algebra/acted_monoid/acted_monoid_plus_plus.hpp.html
title: algebra/acted_monoid/acted_monoid_plus_plus.hpp
---
