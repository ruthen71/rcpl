---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/baby_step_giant_step.hpp
    title: math/baby_step_giant_step.hpp
  - icon: ':warning:'
    path: math/inv_mod.hpp
    title: math/inv_mod.hpp
  - icon: ':warning:'
    path: math/linear_diophantine.hpp
    title: "\u7DDA\u5F62\u30C7\u30A3\u30AA\u30D5\u30A1\u30F3\u30C8\u30B9\u65B9\u7A0B\
      \u5F0F ($ ax + by = c $) / \u7DDA\u5F62\u5408\u540C\u5F0F ( $ ax \\equiv b \\\
      pmod m $ )"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
    title: verify/aoj_ntl/aoj_ntl_1_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/extended_gcd.hpp\"\n\n#include <tuple>\n// find (x,\
    \ y) s.t. ax + by = gcd(a, b)\n// a, b >= 0\n// return {x, y, gcd(a, b)}\ntemplate\
    \ <class T> std::tuple<T, T, T> extended_gcd(T a, T b) {\n    if (b == 0) return\
    \ {1, 0, a};\n    auto [y, x, g] = extended_gcd(b, a % b);\n    return {x, y -\
    \ (a / b) * x, g};\n}\n"
  code: "#pragma once\n\n#include <tuple>\n// find (x, y) s.t. ax + by = gcd(a, b)\n\
    // a, b >= 0\n// return {x, y, gcd(a, b)}\ntemplate <class T> std::tuple<T, T,\
    \ T> extended_gcd(T a, T b) {\n    if (b == 0) return {1, 0, a};\n    auto [y,\
    \ x, g] = extended_gcd(b, a % b);\n    return {x, y - (a / b) * x, g};\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/extended_gcd.hpp
  requiredBy:
  - math/baby_step_giant_step.hpp
  - math/linear_diophantine.hpp
  - math/inv_mod.hpp
  timestamp: '2024-02-23 10:34:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_ntl/aoj_ntl_1_e.test.cpp
documentation_of: math/extended_gcd.hpp
layout: document
redirect_from:
- /library/math/extended_gcd.hpp
- /library/math/extended_gcd.hpp.html
title: math/extended_gcd.hpp
---
