---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/monoid_f/monoid_set.hpp
    title: algebra/monoid_f/monoid_set.hpp
  - icon: ':question:'
    path: algebra/monoid_s/monoid_min.hpp
    title: algebra/monoid_s/monoid_min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
    title: verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_f/monoid_set.hpp\"\n// MF\ntemplate <class\
    \ T> struct MonoidSet {\n    using F = T;\n    static constexpr F composition(F\
    \ f, F g) { return f == id() ? g : f; }\n    static constexpr F id() { return\
    \ std::numeric_limits<F>::max(); }\n};\n#line 2 \"algebra/monoid_s/monoid_min.hpp\"\
    \n// MS\ntemplate <class T> struct MonoidMin {\n    using S = T;\n    static constexpr\
    \ S op(S a, S b) { return std::min(a, b); }\n    static constexpr S e() { return\
    \ std::numeric_limits<T>::max(); }\n};\n#line 4 \"algebra/monoid_s_f/monoid_min_set.hpp\"\
    \n// MSF\ntemplate <class T> struct MonoidMinSet {\n    using MS = MonoidMin<T>;\n\
    \    using MF = MonoidSet<T>;\n    using S = typename MS::S;\n    using F = typename\
    \ MF::F;\n    static constexpr S mapping(F f, S x) { return f == MF::id() ? x\
    \ : f; }\n};\n"
  code: "#pragma once\n#include \"../../algebra/monoid_f/monoid_set.hpp\"\n#include\
    \ \"../../algebra/monoid_s/monoid_min.hpp\"\n// MSF\ntemplate <class T> struct\
    \ MonoidMinSet {\n    using MS = MonoidMin<T>;\n    using MF = MonoidSet<T>;\n\
    \    using S = typename MS::S;\n    using F = typename MF::F;\n    static constexpr\
    \ S mapping(F f, S x) { return f == MF::id() ? x : f; }\n};\n"
  dependsOn:
  - algebra/monoid_f/monoid_set.hpp
  - algebra/monoid_s/monoid_min.hpp
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_min_set.hpp
  requiredBy: []
  timestamp: '2026-01-20 14:43:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_2_f_lazy_segment_tree.test.cpp
documentation_of: algebra/monoid_s_f/monoid_min_set.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_min_set.hpp
- /library/algebra/monoid_s_f/monoid_min_set.hpp.html
title: algebra/monoid_s_f/monoid_min_set.hpp
---
