---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/lazy_min_index_add.hpp\"\n\ntemplate <class T, bool\
    \ left = true> struct lazy_min_index_add {\n    using S = std::pair<T, int>;\n\
    \    using F = T;\n    using value_type_S = S;\n    using value_type_F = F;\n\
    \    static constexpr S op(S a, S b) {\n        if (a.first < b.first) return\
    \ a;\n        if (a.first > b.first) return b;\n        if (a.second > b.second)\
    \ std::swap(a, b);\n        return (left ? a : b);\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::max(), -1}; }\n    static constexpr\
    \ S mapping(F f, S x) { return {f + x.first, x.second}; }\n    static constexpr\
    \ F composition(F f, F g) { return f + g; }\n    static constexpr F id() { return\
    \ 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class T, bool left = true> struct lazy_min_index_add\
    \ {\n    using S = std::pair<T, int>;\n    using F = T;\n    using value_type_S\
    \ = S;\n    using value_type_F = F;\n    static constexpr S op(S a, S b) {\n \
    \       if (a.first < b.first) return a;\n        if (a.first > b.first) return\
    \ b;\n        if (a.second > b.second) std::swap(a, b);\n        return (left\
    \ ? a : b);\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ -1}; }\n    static constexpr S mapping(F f, S x) { return {f + x.first, x.second};\
    \ }\n    static constexpr F composition(F f, F g) { return f + g; }\n    static\
    \ constexpr F id() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/lazy_min_index_add.hpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/lazy_min_index_add.hpp
layout: document
redirect_from:
- /library/algebra/lazy_min_index_add.hpp
- /library/algebra/lazy_min_index_add.hpp.html
title: algebra/lazy_min_index_add.hpp
---
