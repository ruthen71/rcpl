---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_f/monoid_set.hpp
    title: algebra/monoid_f/monoid_set.hpp
  - icon: ':warning:'
    path: algebra/monoid_s/monoid_min_index.hpp
    title: algebra/monoid_s/monoid_min_index.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_min_index.hpp\"\n// MS\ntemplate\
    \ <class T, bool left = true> struct MonoidMinIndex {\n    using S = std::pair<T,\
    \ int>;\n    static constexpr S op(S a, S b) {\n        if (a.first < b.first)\
    \ return a;\n        if (a.first > b.first) return b;\n        if (a.second >\
    \ b.second) std::swap(a, b);\n        return (left ? a : b);\n    }\n    static\
    \ constexpr S e() { return {std::numeric_limits<T>::max(), -1}; }\n};\n#line 2\
    \ \"algebra/monoid_f/monoid_set.hpp\"\n// MF\ntemplate <class T> struct MonoidSet\
    \ {\n    using F = T;\n    static constexpr F composition(F f, F g) { return f\
    \ == id() ? g : f; }\n    static constexpr F id() { return std::numeric_limits<F>::max();\
    \ }\n};\n#line 4 \"algebra/monoid_s_f/monoid_min_index_set.hpp\"\n// MSF\ntemplate\
    \ <class T, bool left = true> struct MonoidMinIndexSet {\n    using MS = MonoidMinIndex<T,\
    \ left>;\n    using MF = MonoidSet<T>;\n    using S = typename MS::S;\n    using\
    \ F = typename MF::F;\n    static constexpr S mapping(F f, S x) { return f ==\
    \ MF::id() ? x : ({f, x.second}); }\n};\n"
  code: "#pragma once\n#include \"algebra/monoid_s/monoid_min_index.hpp\"\n#include\
    \ \"algebra/monoid_f/monoid_set.hpp\"\n// MSF\ntemplate <class T, bool left =\
    \ true> struct MonoidMinIndexSet {\n    using MS = MonoidMinIndex<T, left>;\n\
    \    using MF = MonoidSet<T>;\n    using S = typename MS::S;\n    using F = typename\
    \ MF::F;\n    static constexpr S mapping(F f, S x) { return f == MF::id() ? x\
    \ : ({f, x.second}); }\n};"
  dependsOn:
  - algebra/monoid_s/monoid_min_index.hpp
  - algebra/monoid_f/monoid_set.hpp
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_min_index_set.hpp
  requiredBy: []
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s_f/monoid_min_index_set.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_min_index_set.hpp
- /library/algebra/monoid_s_f/monoid_min_index_set.hpp.html
title: algebra/monoid_s_f/monoid_min_index_set.hpp
---
