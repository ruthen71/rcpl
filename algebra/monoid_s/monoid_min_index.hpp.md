---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_min_index_add.hpp
    title: algebra/monoid_s_f/monoid_min_index_add.hpp
  - icon: ':warning:'
    path: algebra/monoid_s_f/monoid_min_index_set.hpp
    title: algebra/monoid_s_f/monoid_min_index_set.hpp
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
    \ constexpr S e() { return {std::numeric_limits<T>::max(), -1}; }\n};\n"
  code: "#pragma once\n// MS\ntemplate <class T, bool left = true> struct MonoidMinIndex\
    \ {\n    using S = std::pair<T, int>;\n    static constexpr S op(S a, S b) {\n\
    \        if (a.first < b.first) return a;\n        if (a.first > b.first) return\
    \ b;\n        if (a.second > b.second) std::swap(a, b);\n        return (left\
    \ ? a : b);\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ -1}; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_s/monoid_min_index.hpp
  requiredBy:
  - algebra/monoid_s_f/monoid_min_index_set.hpp
  - algebra/monoid_s_f/monoid_min_index_add.hpp
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s/monoid_min_index.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s/monoid_min_index.hpp
- /library/algebra/monoid_s/monoid_min_index.hpp.html
title: algebra/monoid_s/monoid_min_index.hpp
---
