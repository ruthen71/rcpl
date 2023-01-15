---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/algebra/monoid_rolling_hash.md
    links: []
  bundledCode: "#line 2 \"src/algebra/monoid_rolling_hash.hpp\"\n\ntemplate <class\
    \ Mint> struct monoid_rolling_hash {\n    using S = std::pair<Mint, int>;\n  \
    \  using value_type = S;\n    static constexpr S op(S a, S b) { return {rh.combine(a.first,\
    \ b.first, b.second), a.second + b.second}; }\n    static constexpr S e() { return\
    \ {0, 0}; }\n};\n\n/**\n * @docs docs/algebra/monoid_rolling_hash.md\n */\n"
  code: "#pragma once\n\ntemplate <class Mint> struct monoid_rolling_hash {\n    using\
    \ S = std::pair<Mint, int>;\n    using value_type = S;\n    static constexpr S\
    \ op(S a, S b) { return {rh.combine(a.first, b.first, b.second), a.second + b.second};\
    \ }\n    static constexpr S e() { return {0, 0}; }\n};\n\n/**\n * @docs docs/algebra/monoid_rolling_hash.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/monoid_rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-01-16 00:56:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/monoid_rolling_hash.hpp
layout: document
redirect_from:
- /library/src/algebra/monoid_rolling_hash.hpp
- /library/src/algebra/monoid_rolling_hash.hpp.html
title: src/algebra/monoid_rolling_hash.hpp
---
## 使用例

- [ABC285 F](https://atcoder.jp/contests/abc285/tasks/abc285_f)
- 以下の順で定義しなければならない(上手くやる方法がわからなかった)
    - `#include "src/string/rolling_hash.hpp"`
    - `rolling_hash<mint> rh;`
    - `#include "src/algebra/monoid_rolling_hash.hpp"`
- 2つ以上のmodを組み合わせるなら、include ではなくべた書きするしかない
- 正直あまり綺麗な書き方ではないので一刻も早く何とかしたい

