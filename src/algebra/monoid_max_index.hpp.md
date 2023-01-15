---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/algebra/monoid_max_index.md
    links: []
  bundledCode: "#line 2 \"src/algebra/monoid_max_index.hpp\"\n\ntemplate <class T,\
    \ bool left = true> struct monoid_max_index {\n    using S = std::pair<T, int>;\n\
    \    using value_type = S;\n    static constexpr S op(S a, S b) {\n        if\
    \ (a.first > b.first) return a;\n        if (a.first < b.first) return b;\n  \
    \      if (a.second > b.second) std::swap(a, b);\n        return (left ? a : b);\n\
    \    }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ -1}; }\n};\n\n/**\n * @docs docs/algebra/monoid_max_index.md\n */\n"
  code: "#pragma once\n\ntemplate <class T, bool left = true> struct monoid_max_index\
    \ {\n    using S = std::pair<T, int>;\n    using value_type = S;\n    static constexpr\
    \ S op(S a, S b) {\n        if (a.first > b.first) return a;\n        if (a.first\
    \ < b.first) return b;\n        if (a.second > b.second) std::swap(a, b);\n  \
    \      return (left ? a : b);\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ -1}; }\n};\n\n/**\n * @docs docs/algebra/monoid_max_index.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/monoid_max_index.hpp
  requiredBy: []
  timestamp: '2022-09-26 06:11:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/monoid_max_index.hpp
layout: document
redirect_from:
- /library/src/algebra/monoid_max_index.hpp
- /library/src/algebra/monoid_max_index.hpp.html
title: src/algebra/monoid_max_index.hpp
---
## 使用例

