---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/algebra/monoid_min_index.md
    links: []
  bundledCode: "#line 2 \"src/algebra/monoid_min_index.hpp\"\n\ntemplate <class T,\
    \ bool left = true> struct monoid_min_index {\n    using S = std::pair<T, int>;\n\
    \    using value_type = S;\n    static constexpr S op(S a, S b) {\n        if\
    \ (a.first < b.first) return a;\n        if (a.first > b.first) return b;\n  \
    \      if (a.second > b.second) swap(a, b);\n        return (left ? a : b);\n\
    \    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(), -1};\
    \ }\n};\n\n/**\n * @docs docs/algebra/monoid_min_index.md\n */\n"
  code: "#pragma once\n\ntemplate <class T, bool left = true> struct monoid_min_index\
    \ {\n    using S = std::pair<T, int>;\n    using value_type = S;\n    static constexpr\
    \ S op(S a, S b) {\n        if (a.first < b.first) return a;\n        if (a.first\
    \ > b.first) return b;\n        if (a.second > b.second) swap(a, b);\n       \
    \ return (left ? a : b);\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ -1}; }\n};\n\n/**\n * @docs docs/algebra/monoid_min_index.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/monoid_min_index.hpp
  requiredBy: []
  timestamp: '2022-09-23 05:31:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/monoid_min_index.hpp
layout: document
redirect_from:
- /library/src/algebra/monoid_min_index.hpp
- /library/src/algebra/monoid_min_index.hpp.html
title: src/algebra/monoid_min_index.hpp
---
# monoid_min_index

## 使用例

- [ABC267 E](https://atcoder.jp/contests/abc267/tasks/abc267_e)

