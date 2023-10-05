---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc322/tasks/abc322_f
  bundledCode: "#line 2 \"algebra/lazy_max01_flip.hpp\"\n\n// https://atcoder.jp/contests/abc322/tasks/abc322_f\n\
    template <class T> struct LazyMax01Flip {\n    using S = std::array<T, 7>;  //\
    \ {max0, left0, right0, max1, left1, right1, length}\n    using F = int;\n   \
    \ using value_type_S = S;\n    using value_type_F = F;\n    static constexpr S\
    \ op(S a, S b) {\n        S res;\n        for (int i = 0; i < 6; i += 3) {\n \
    \           res[i + 0] = std::max({a[i + 0], b[i + 0], a[i + 2] + b[i + 1]});\n\
    \            res[i + 1] = a[6] == a[i + 1] ? a[i + 1] + b[i + 1] : a[i + 1];\n\
    \            res[i + 2] = b[6] == b[i + 2] ? a[i + 2] + b[i + 2] : b[i + 2];\n\
    \        }\n        res[6] = a[6] + b[6];\n        return res;\n    }\n    static\
    \ constexpr S e() { return {0, 0, 0, 0, 0, 0, 0}; }\n    static constexpr S e0()\
    \ { return {1, 1, 1, 0, 0, 0, 1}; }\n    static constexpr S e1() { return {0,\
    \ 0, 0, 1, 1, 1, 1}; }\n    static constexpr S mapping(F f, S x) {\n        if\
    \ (f) {\n            for (int i = 0; i < 3; i++) std::swap(x[i], x[i + 3]);\n\
    \        }\n        return x;\n    }\n    static constexpr F composition(F f,\
    \ F g) { return f ^ g; }\n    static constexpr F id() { return 0; }\n};\n"
  code: "#pragma once\n\n// https://atcoder.jp/contests/abc322/tasks/abc322_f\ntemplate\
    \ <class T> struct LazyMax01Flip {\n    using S = std::array<T, 7>;  // {max0,\
    \ left0, right0, max1, left1, right1, length}\n    using F = int;\n    using value_type_S\
    \ = S;\n    using value_type_F = F;\n    static constexpr S op(S a, S b) {\n \
    \       S res;\n        for (int i = 0; i < 6; i += 3) {\n            res[i +\
    \ 0] = std::max({a[i + 0], b[i + 0], a[i + 2] + b[i + 1]});\n            res[i\
    \ + 1] = a[6] == a[i + 1] ? a[i + 1] + b[i + 1] : a[i + 1];\n            res[i\
    \ + 2] = b[6] == b[i + 2] ? a[i + 2] + b[i + 2] : b[i + 2];\n        }\n     \
    \   res[6] = a[6] + b[6];\n        return res;\n    }\n    static constexpr S\
    \ e() { return {0, 0, 0, 0, 0, 0, 0}; }\n    static constexpr S e0() { return\
    \ {1, 1, 1, 0, 0, 0, 1}; }\n    static constexpr S e1() { return {0, 0, 0, 1,\
    \ 1, 1, 1}; }\n    static constexpr S mapping(F f, S x) {\n        if (f) {\n\
    \            for (int i = 0; i < 3; i++) std::swap(x[i], x[i + 3]);\n        }\n\
    \        return x;\n    }\n    static constexpr F composition(F f, F g) { return\
    \ f ^ g; }\n    static constexpr F id() { return 0; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/lazy_max01_flip.hpp
  requiredBy: []
  timestamp: '2023-10-05 17:47:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/lazy_max01_flip.hpp
layout: document
redirect_from:
- /library/algebra/lazy_max01_flip.hpp
- /library/algebra/lazy_max01_flip.hpp.html
title: algebra/lazy_max01_flip.hpp
---
