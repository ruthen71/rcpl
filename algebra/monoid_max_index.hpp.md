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
  bundledCode: "#line 2 \"algebra/monoid_max_index.hpp\"\n\ntemplate <class T, bool\
    \ left = true> struct MonoidMaxIndex {\n    using S = std::pair<T, int>;\n   \
    \ using value_type = S;\n    static constexpr S op(S a, S b) {\n        if (a.first\
    \ > b.first) return a;\n        if (a.first < b.first) return b;\n        if (a.second\
    \ > b.second) std::swap(a, b);\n        return (left ? a : b);\n    }\n    static\
    \ constexpr S e() { return {std::numeric_limits<T>::lowest(), -1}; }\n};\n"
  code: "#pragma once\n\ntemplate <class T, bool left = true> struct MonoidMaxIndex\
    \ {\n    using S = std::pair<T, int>;\n    using value_type = S;\n    static constexpr\
    \ S op(S a, S b) {\n        if (a.first > b.first) return a;\n        if (a.first\
    \ < b.first) return b;\n        if (a.second > b.second) std::swap(a, b);\n  \
    \      return (left ? a : b);\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ -1}; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_max_index.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_max_index.hpp
layout: document
title: "\u6700\u5927\u5024(\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9)\u53D6\u5F97"
---
