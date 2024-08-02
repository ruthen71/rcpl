---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_f/monoid_add.hpp
    title: algebra/monoid_f/monoid_add.hpp
  - icon: ':warning:'
    path: algebra/monoid_s/monoid_max_index.hpp
    title: algebra/monoid_s/monoid_max_index.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_max_index.hpp\"\n// MS\ntemplate\
    \ <class T, bool left = true> struct MonoidMaxIndex {\n    using S = std::pair<T,\
    \ int>;\n    static constexpr S op(S a, S b) {\n        if (a.first > b.first)\
    \ return a;\n        if (a.first < b.first) return b;\n        if (a.second >\
    \ b.second) std::swap(a, b);\n        return (left ? a : b);\n    }\n    static\
    \ constexpr S e() { return {std::numeric_limits<T>::lowest(), -1}; }\n};\n#line\
    \ 2 \"algebra/monoid_f/monoid_add.hpp\"\n// MF\ntemplate <class T> struct MonoidAdd\
    \ {\n    using F = T;\n    static constexpr F composition(F f, F g) { return f\
    \ + g; }\n    static constexpr F id() { return T(0); }\n};\n#line 4 \"algebra/monoid_s_f/monoid_max_index_add.hpp\"\
    \n// MSF\ntemplate <class T, bool left = true> struct MonoidMaxIndexAdd {\n  \
    \  using MS = MonoidMaxIndex<T, left>;\n    using MF = MonoidAdd<T>;\n    using\
    \ S = typename MS::S;\n    using F = typename MF::F;\n    static constexpr S mapping(F\
    \ f, S x) { return {f + x.first, x.second}; }\n};\n"
  code: "#pragma once\n#include \"algebra/monoid_s/monoid_max_index.hpp\"\n#include\
    \ \"algebra/monoid_f/monoid_add.hpp\"\n// MSF\ntemplate <class T, bool left =\
    \ true> struct MonoidMaxIndexAdd {\n    using MS = MonoidMaxIndex<T, left>;\n\
    \    using MF = MonoidAdd<T>;\n    using S = typename MS::S;\n    using F = typename\
    \ MF::F;\n    static constexpr S mapping(F f, S x) { return {f + x.first, x.second};\
    \ }\n};"
  dependsOn:
  - algebra/monoid_s/monoid_max_index.hpp
  - algebra/monoid_f/monoid_add.hpp
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_max_index_add.hpp
  requiredBy: []
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s_f/monoid_max_index_add.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_max_index_add.hpp
- /library/algebra/monoid_s_f/monoid_max_index_add.hpp.html
title: algebra/monoid_s_f/monoid_max_index_add.hpp
---