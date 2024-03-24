---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_f/monoid_set.hpp
    title: algebra/monoid_f/monoid_set.hpp
  - icon: ':warning:'
    path: algebra/monoid_s/monoid_max.hpp
    title: algebra/monoid_s/monoid_max.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_max.hpp\"\n// MS\ntemplate <class\
    \ T> struct MonoidMax {\n    using S = T;\n    static constexpr S op(S a, S b)\
    \ { return std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<T>::lowest();\
    \ }\n};\n#line 2 \"algebra/monoid_f/monoid_set.hpp\"\n// MF\ntemplate <class T>\
    \ struct MonoidSet {\n    using F = T;\n    static constexpr F composition(F f,\
    \ F g) { return f == id() ? g : f; }\n    static constexpr F id() { return std::numeric_limits<F>::max();\
    \ }\n};\n#line 4 \"algebra/monoid_s_f/monoid_max_set.hpp\"\n// MSF\ntemplate <class\
    \ T> struct MonoidMaxSet {\n    using MS = MonoidMax<T>;\n    using MF = MonoidSet<T>;\n\
    \    using S = typename MS::S;\n    using F = typename MF::F;\n    static constexpr\
    \ S mapping(F f, S x) { return f == MF::id() ? x : f; }\n};\n"
  code: "#pragma once\n#include \"algebra/monoid_s/monoid_max.hpp\"\n#include \"algebra/monoid_f/monoid_set.hpp\"\
    \n// MSF\ntemplate <class T> struct MonoidMaxSet {\n    using MS = MonoidMax<T>;\n\
    \    using MF = MonoidSet<T>;\n    using S = typename MS::S;\n    using F = typename\
    \ MF::F;\n    static constexpr S mapping(F f, S x) { return f == MF::id() ? x\
    \ : f; }\n};"
  dependsOn:
  - algebra/monoid_s/monoid_max.hpp
  - algebra/monoid_f/monoid_set.hpp
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_max_set.hpp
  requiredBy: []
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s_f/monoid_max_set.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_max_set.hpp
- /library/algebra/monoid_s_f/monoid_max_set.hpp.html
title: algebra/monoid_s_f/monoid_max_set.hpp
---
