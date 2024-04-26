---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/extended_gcd.hpp
    title: math/extended_gcd.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/baby_step_giant_step.hpp
    title: math/baby_step_giant_step.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/inv_mod.hpp\"\n\n#include <cassert>\n#line 2 \"math/extended_gcd.hpp\"\
    \n\n#include <tuple>\n// find (x, y) s.t. ax + by = gcd(a, b)\n// a, b >= 0\n\
    // return {x, y, gcd(a, b)}\ntemplate <class T> std::tuple<T, T, T> extended_gcd(T\
    \ a, T b) {\n    if (b == 0) return {1, 0, a};\n    auto [y, x, g] = extended_gcd(b,\
    \ a % b);\n    return {x, y - (a / b) * x, g};\n}\n#line 5 \"math/inv_mod.hpp\"\
    \n\n// mod >= 2\nlong long inv_mod(long long a, long long mod) {\n    a %= mod;\n\
    \    if (a < 0) a += mod;\n    assert(a != 0);\n    auto [x, y, g] = extended_gcd(a,\
    \ mod);\n    x %= mod;\n    if (x < 0) x += mod;\n    return x;\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include \"math/extended_gcd.hpp\"\n\n\
    // mod >= 2\nlong long inv_mod(long long a, long long mod) {\n    a %= mod;\n\
    \    if (a < 0) a += mod;\n    assert(a != 0);\n    auto [x, y, g] = extended_gcd(a,\
    \ mod);\n    x %= mod;\n    if (x < 0) x += mod;\n    return x;\n}"
  dependsOn:
  - math/extended_gcd.hpp
  isVerificationFile: false
  path: math/inv_mod.hpp
  requiredBy:
  - math/baby_step_giant_step.hpp
  timestamp: '2024-02-23 10:38:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/inv_mod.hpp
layout: document
redirect_from:
- /library/math/inv_mod.hpp
- /library/math/inv_mod.hpp.html
title: math/inv_mod.hpp
---
