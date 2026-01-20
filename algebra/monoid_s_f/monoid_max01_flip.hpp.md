---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algebra/monoid_f/monoid_flip.hpp
    title: algebra/monoid_f/monoid_flip.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc322/tasks/abc322_f
  bundledCode: "#line 2 \"algebra/monoid_s_f/monoid_max01_flip.hpp\"\n\n// https://atcoder.jp/contests/abc322/tasks/abc322_f\n\
    // MS\ntemplate <class T> struct MonoidMax01 {\n    using S =\n        std::array<T,\
    \ 7>;  // {max0, left0, right0, max1, left1, right1, length}\n    static constexpr\
    \ S op(S a, S b) {\n        S res;\n        for (int i = 0; i < 6; i += 3) {\n\
    \            res[i + 0] = std::max({a[i + 0], b[i + 0], a[i + 2] + b[i + 1]});\n\
    \            res[i + 1] = a[6] == a[i + 1] ? a[i + 1] + b[i + 1] : a[i + 1];\n\
    \            res[i + 2] = b[6] == b[i + 2] ? a[i + 2] + b[i + 2] : b[i + 2];\n\
    \        }\n        res[6] = a[6] + b[6];\n        return res;\n    }\n    static\
    \ constexpr S e() { return {0, 0, 0, 0, 0, 0, 0}; }\n    static constexpr S e0()\
    \ { return {1, 1, 1, 0, 0, 0, 1}; }\n    static constexpr S e1() { return {0,\
    \ 0, 0, 1, 1, 1, 1}; }\n};\n#line 2 \"algebra/monoid_f/monoid_flip.hpp\"\n\n//\
    \ MF\nstruct MonoidFlip {\n    using F = int;\n    static constexpr F composition(F\
    \ f, F g) { return f ^ g; }\n    static constexpr F id() { return 0; }\n};\n#line\
    \ 23 \"algebra/monoid_s_f/monoid_max01_flip.hpp\"\n// MSF\ntemplate <class T>\
    \ struct MonoidMax01Flip {\n    using MS = MonoidMax01<T>;\n    using MF = MonoidFlip;\n\
    \    using S = typename MS::S;\n    using F = typename MF::F;\n    static constexpr\
    \ S mapping(F f, S x) {\n        if (!f) return x;\n        for (int i = 0; i\
    \ < 3; i++) std::swap(x[i], x[i + 3]);\n        return x;\n    }\n};\n"
  code: "#pragma once\n\n// https://atcoder.jp/contests/abc322/tasks/abc322_f\n//\
    \ MS\ntemplate <class T> struct MonoidMax01 {\n    using S =\n        std::array<T,\
    \ 7>;  // {max0, left0, right0, max1, left1, right1, length}\n    static constexpr\
    \ S op(S a, S b) {\n        S res;\n        for (int i = 0; i < 6; i += 3) {\n\
    \            res[i + 0] = std::max({a[i + 0], b[i + 0], a[i + 2] + b[i + 1]});\n\
    \            res[i + 1] = a[6] == a[i + 1] ? a[i + 1] + b[i + 1] : a[i + 1];\n\
    \            res[i + 2] = b[6] == b[i + 2] ? a[i + 2] + b[i + 2] : b[i + 2];\n\
    \        }\n        res[6] = a[6] + b[6];\n        return res;\n    }\n    static\
    \ constexpr S e() { return {0, 0, 0, 0, 0, 0, 0}; }\n    static constexpr S e0()\
    \ { return {1, 1, 1, 0, 0, 0, 1}; }\n    static constexpr S e1() { return {0,\
    \ 0, 0, 1, 1, 1, 1}; }\n};\n#include \"../../algebra/monoid_f/monoid_flip.hpp\"\
    \n// MSF\ntemplate <class T> struct MonoidMax01Flip {\n    using MS = MonoidMax01<T>;\n\
    \    using MF = MonoidFlip;\n    using S = typename MS::S;\n    using F = typename\
    \ MF::F;\n    static constexpr S mapping(F f, S x) {\n        if (!f) return x;\n\
    \        for (int i = 0; i < 3; i++) std::swap(x[i], x[i + 3]);\n        return\
    \ x;\n    }\n};\n"
  dependsOn:
  - algebra/monoid_f/monoid_flip.hpp
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_max01_flip.hpp
  requiredBy: []
  timestamp: '2026-01-20 14:43:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s_f/monoid_max01_flip.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_max01_flip.hpp
- /library/algebra/monoid_s_f/monoid_max01_flip.hpp.html
title: algebra/monoid_s_f/monoid_max01_flip.hpp
---
