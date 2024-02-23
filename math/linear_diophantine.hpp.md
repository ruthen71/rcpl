---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extended_gcd.hpp
    title: math/extended_gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - "https://ja.wikipedia.org/wiki/\u30D9\u30BA\u30FC\u306E\u7B49\u5F0F"
  bundledCode: "#line 2 \"math/linear_diophantine.hpp\"\n\n#include <tuple>\n#line\
    \ 2 \"math/extended_gcd.hpp\"\n\n#line 4 \"math/extended_gcd.hpp\"\n// find (x,\
    \ y) s.t. ax + by = gcd(a, b)\n// a, b >= 0\n// return {x, y, gcd(a, b)}\ntemplate\
    \ <class T> std::tuple<T, T, T> extended_gcd(T a, T b) {\n    if (b == 0) return\
    \ {1, 0, a};\n    auto [y, x, g] = extended_gcd(b, a % b);\n    return {x, y -\
    \ (a / b) * x, g};\n}\n#line 5 \"math/linear_diophantine.hpp\"\n\n// Reference:\
    \ https://ja.wikipedia.org/wiki/\u30D9\u30BA\u30FC\u306E\u7B49\u5F0F\n// ax +\
    \ by = c \u3092\u89E3\u304F (a, b >= 0)\n// return {x, y, gcd(a, b), has_solution}\n\
    // \u89E3\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\n// (1) a = 0, b = 0, c =\
    \ 0 \u306E\u3068\u304D\n//   x, y \u306F\u4EFB\u610F\n//   {0, 0, gcd(a, b) =\
    \ 0, 1} \u3092\u8FD4\u3059\n// (2) a = 0, c \u304C b \u306E\u500D\u6570\u306E\u3068\
    \u304D\n//   x \u306F\u4EFB\u610F, y = c / b\n//   {0, c / b, gcd(a, b) = b, 1}\
    \ \u3092\u8FD4\u3059\n// (3) b = 0, c \u304C a \u306E\u500D\u6570\u306E\u3068\u304D\
    \n//   y \u306F\u4EFB\u610F, x = c / b\n//   {c / a, 0, gcd(a, b) = a, 1} \u3092\
    \u8FD4\u3059\n// (4) a > 0, b > 0, c % gcd(a, b) = 0 \u306E\u3068\u304D\n//  \
    \ x = x' + k * (b / gcd(a, b)), y = y' - k * (a / gcd(a, b))\n//   {x', y', gcd(a,\
    \ b), 1} \u3092\u8FD4\u3059\n// \u89E3\u304C\u5B58\u5728\u3057\u306A\u3044\u3068\
    \u304D\n// {-1, -1, -1, 0} \u3092\u8FD4\u3059\ntemplate <class T> std::tuple<T,\
    \ T, T, int> linear_diophantine(T a, T b, T c) {\n    assert(a >= 0 and b >= 0);\n\
    \    if (a == 0 and b == 0) {\n        if (c == 0) return {0, 0, 0, 1};\n    \
    \    return {-1, -1, -1, 0};\n    }\n    if (a == 0) {\n        // by = c\n  \
    \      if (c % b == 0) return {0, c / b, b, 1};\n        return {-1, -1, -1, 0};\n\
    \    }\n    if (b == 0) {\n        // ax = c\n        if (c % a == 0) return {c\
    \ / a, 0, a, 1};\n        return {-1, -1, -1, 0};\n    }\n    // as + bt = gcd(a,\
    \ b) \u304B\u3089 ax + by = c \u3092\u6C42\u3081\u308B\n    // x = s * (c / gcd(a,\
    \ b)), y = t * (c / gcd(a, b)) \u3088\u308A\u3082 x, y \u304C\u5C0F\u3055\u304F\
    \u306A\u308B?\n    // c = c' + a * dx + b * dy \u3068\u306A\u308B\u3088\u3046\u306B\
    \ c' \u3092\u6C42\u3081\u308B\n    // (a, b \u306F gcd(a, b) \u306E\u500D\u6570\
    \u306A\u306E\u3067 c' \u306F gcd(a, b) \u306E\u500D\u6570)\n    // x = dx + s\
    \ * (c' / gcd(a, b)), y = dy + t * (c' / gcd(a, b)) \u304C\u89E3\u3068\u306A\u308B\
    \n    // ax + by = a * dx + b * dy + (as + bt) * (c' / gcd(a, b)) = a * dx + b\
    \ * dy + c' = c\n    auto [s, t, g] = extended_gcd(a, b);\n    if (c % g != 0)\
    \ return {-1, -1, -1, 0};\n    T dx = c / a;\n    c -= dx * a;\n    T dy = c /\
    \ b;\n    c -= dy * b;\n    T x = dx + s * (c / g);\n    T y = dy + t * (c / g);\n\
    \    return {x, y, g, 1};\n}\n\n// \u7DDA\u5F62\u5408\u540C\u5F0F ax = b (mod\
    \ m) \u3092\u89E3\u304F (m > 0)\n// \u89E3\u304C\u5B58\u5728\u3059\u308B\u5834\
    \u5408 x = x' (mod h) \u3068\u306A\u308B\u3068\u304D\u306E\u6700\u5C0F\u306E x'\
    \ \u3068 h \u3092\u8FD4\u3059\n// \u89E3\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408 {-1, -1} \u3092\u8FD4\u3059\ntemplate <class T> std::pair<T, T> linear_congruence(T\
    \ a, T b, T m) {\n    assert(m > 0);\n    a = (a % m + m) % m;\n    b = (b % m\
    \ + m) % m;\n    // ax = b (mod m) <=> ax + my = b \u3068\u306A\u308B (x, y) \u304C\
    \u5B58\u5728\n    auto [x, y, g, is_ok] = linear_diophantine(a, m, b);\n    if\
    \ (!is_ok) return {-1, -1};\n    T h = m / g;\n    x = (x % h + h) % h;\n    return\
    \ {x, h};\n}\n"
  code: "#pragma once\n\n#include <tuple>\n#include \"math/extended_gcd.hpp\"\n\n\
    // Reference: https://ja.wikipedia.org/wiki/\u30D9\u30BA\u30FC\u306E\u7B49\u5F0F\
    \n// ax + by = c \u3092\u89E3\u304F (a, b >= 0)\n// return {x, y, gcd(a, b), has_solution}\n\
    // \u89E3\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\n// (1) a = 0, b = 0, c =\
    \ 0 \u306E\u3068\u304D\n//   x, y \u306F\u4EFB\u610F\n//   {0, 0, gcd(a, b) =\
    \ 0, 1} \u3092\u8FD4\u3059\n// (2) a = 0, c \u304C b \u306E\u500D\u6570\u306E\u3068\
    \u304D\n//   x \u306F\u4EFB\u610F, y = c / b\n//   {0, c / b, gcd(a, b) = b, 1}\
    \ \u3092\u8FD4\u3059\n// (3) b = 0, c \u304C a \u306E\u500D\u6570\u306E\u3068\u304D\
    \n//   y \u306F\u4EFB\u610F, x = c / b\n//   {c / a, 0, gcd(a, b) = a, 1} \u3092\
    \u8FD4\u3059\n// (4) a > 0, b > 0, c % gcd(a, b) = 0 \u306E\u3068\u304D\n//  \
    \ x = x' + k * (b / gcd(a, b)), y = y' - k * (a / gcd(a, b))\n//   {x', y', gcd(a,\
    \ b), 1} \u3092\u8FD4\u3059\n// \u89E3\u304C\u5B58\u5728\u3057\u306A\u3044\u3068\
    \u304D\n// {-1, -1, -1, 0} \u3092\u8FD4\u3059\ntemplate <class T> std::tuple<T,\
    \ T, T, int> linear_diophantine(T a, T b, T c) {\n    assert(a >= 0 and b >= 0);\n\
    \    if (a == 0 and b == 0) {\n        if (c == 0) return {0, 0, 0, 1};\n    \
    \    return {-1, -1, -1, 0};\n    }\n    if (a == 0) {\n        // by = c\n  \
    \      if (c % b == 0) return {0, c / b, b, 1};\n        return {-1, -1, -1, 0};\n\
    \    }\n    if (b == 0) {\n        // ax = c\n        if (c % a == 0) return {c\
    \ / a, 0, a, 1};\n        return {-1, -1, -1, 0};\n    }\n    // as + bt = gcd(a,\
    \ b) \u304B\u3089 ax + by = c \u3092\u6C42\u3081\u308B\n    // x = s * (c / gcd(a,\
    \ b)), y = t * (c / gcd(a, b)) \u3088\u308A\u3082 x, y \u304C\u5C0F\u3055\u304F\
    \u306A\u308B?\n    // c = c' + a * dx + b * dy \u3068\u306A\u308B\u3088\u3046\u306B\
    \ c' \u3092\u6C42\u3081\u308B\n    // (a, b \u306F gcd(a, b) \u306E\u500D\u6570\
    \u306A\u306E\u3067 c' \u306F gcd(a, b) \u306E\u500D\u6570)\n    // x = dx + s\
    \ * (c' / gcd(a, b)), y = dy + t * (c' / gcd(a, b)) \u304C\u89E3\u3068\u306A\u308B\
    \n    // ax + by = a * dx + b * dy + (as + bt) * (c' / gcd(a, b)) = a * dx + b\
    \ * dy + c' = c\n    auto [s, t, g] = extended_gcd(a, b);\n    if (c % g != 0)\
    \ return {-1, -1, -1, 0};\n    T dx = c / a;\n    c -= dx * a;\n    T dy = c /\
    \ b;\n    c -= dy * b;\n    T x = dx + s * (c / g);\n    T y = dy + t * (c / g);\n\
    \    return {x, y, g, 1};\n}\n\n// \u7DDA\u5F62\u5408\u540C\u5F0F ax = b (mod\
    \ m) \u3092\u89E3\u304F (m > 0)\n// \u89E3\u304C\u5B58\u5728\u3059\u308B\u5834\
    \u5408 x = x' (mod h) \u3068\u306A\u308B\u3068\u304D\u306E\u6700\u5C0F\u306E x'\
    \ \u3068 h \u3092\u8FD4\u3059\n// \u89E3\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408 {-1, -1} \u3092\u8FD4\u3059\ntemplate <class T> std::pair<T, T> linear_congruence(T\
    \ a, T b, T m) {\n    assert(m > 0);\n    a = (a % m + m) % m;\n    b = (b % m\
    \ + m) % m;\n    // ax = b (mod m) <=> ax + my = b \u3068\u306A\u308B (x, y) \u304C\
    \u5B58\u5728\n    auto [x, y, g, is_ok] = linear_diophantine(a, m, b);\n    if\
    \ (!is_ok) return {-1, -1};\n    T h = m / g;\n    x = (x % h + h) % h;\n    return\
    \ {x, h};\n}"
  dependsOn:
  - math/extended_gcd.hpp
  isVerificationFile: false
  path: math/linear_diophantine.hpp
  requiredBy: []
  timestamp: '2024-02-23 10:34:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear_diophantine.hpp
layout: document
title: "\u7DDA\u5F62\u30C7\u30A3\u30AA\u30D5\u30A1\u30F3\u30C8\u30B9\u65B9\u7A0B\u5F0F\
  \ ($ ax + by = c $) / \u7DDA\u5F62\u5408\u540C\u5F0F ( $ ax \\equiv b \\pmod m $\
  \ )"
---

線形合同式は $ \bmod m $ で $ a^{-1} $ を求めることでは解が求められない場合がある

例えば、$ 9x \equiv 3 \pmod {15} $ は $ 9^{-1} $ となる値を持たないが、$ x \equiv 2 \pmod 5 $ が解である

このような場合、拡張ユークリッドの互除法を用いることで解が求められる
