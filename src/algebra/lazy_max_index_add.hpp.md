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
  bundledCode: "#line 2 \"src/algebra/lazy_max_index_add.hpp\"\n\ntemplate <class\
    \ T, bool left = true> struct lazy_max_index_add {\n    using S = std::pair<T,\
    \ int>;\n    using F = T;\n    using value_type_S = S;\n    using value_type_F\
    \ = F;\n    static constexpr S op(S a, S b) {\n        if (a.first > b.first)\
    \ return a;\n        if (a.first < b.first) return b;\n        if (a.second >\
    \ b.second) swap(a, b);\n        return (left ? a : b);\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), -1}; }\n    static constexpr\
    \ S mapping(F f, S x) { return {f + x.first, x.second}; }\n    static constexpr\
    \ F composition(F f, F g) { return f + g; }\n    static constexpr F id() { return\
    \ 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class T, bool left = true> struct lazy_max_index_add\
    \ {\n    using S = std::pair<T, int>;\n    using F = T;\n    using value_type_S\
    \ = S;\n    using value_type_F = F;\n    static constexpr S op(S a, S b) {\n \
    \       if (a.first > b.first) return a;\n        if (a.first < b.first) return\
    \ b;\n        if (a.second > b.second) swap(a, b);\n        return (left ? a :\
    \ b);\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ -1}; }\n    static constexpr S mapping(F f, S x) { return {f + x.first, x.second};\
    \ }\n    static constexpr F composition(F f, F g) { return f + g; }\n    static\
    \ constexpr F id() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/lazy_max_index_add.hpp
  requiredBy: []
  timestamp: '2022-09-23 16:03:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/lazy_max_index_add.hpp
layout: document
redirect_from:
- /library/src/algebra/lazy_max_index_add.hpp
- /library/src/algebra/lazy_max_index_add.hpp.html
title: src/algebra/lazy_max_index_add.hpp
---
