---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/extended_gcd.hpp
    title: math/extended_gcd.hpp
  - icon: ':x:'
    path: math/linear_diophantine.hpp
    title: "\u7DDA\u5F62\u30C7\u30A3\u30AA\u30D5\u30A1\u30F3\u30C8\u30B9\u65B9\u7A0B\
      \u5F0F ($ ax + by = c $) / \u7DDA\u5F62\u5408\u540C\u5F0F ( $ ax \\equiv b \\\
      pmod m $ )"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yuki/yuki_186_chinese_remainder_theorem.test.cpp
    title: verify/yuki/yuki_186_chinese_remainder_theorem.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/chinese_remainder_theorem.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n#line 2 \"math/linear_diophantine.hpp\"\n\n#include <tuple>\n\
    #line 2 \"math/extended_gcd.hpp\"\n\n#line 4 \"math/extended_gcd.hpp\"\n// find\
    \ (x, y) s.t. ax + by = gcd(a, b)\n// a, b >= 0\n// return {x, y, gcd(a, b)}\n\
    template <class T> std::tuple<T, T, T> extended_gcd(T a, T b) {\n    if (b ==\
    \ 0) return {1, 0, a};\n    auto [y, x, g] = extended_gcd(b, a % b);\n    return\
    \ {x, y - (a / b) * x, g};\n}\n#line 5 \"math/linear_diophantine.hpp\"\n\n// Reference:\
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
    \ {x, h};\n}\n#line 6 \"math/chinese_remainder_theorem.hpp\"\n\n// (rem, mod)\n\
    std::pair<long long, long long> chinese_remainder_theorem(const std::vector<long\
    \ long>& r, const std::vector<long long>& m) {\n    assert(r.size() == m.size());\n\
    \    const int n = (int)(r.size());\n    long long r0 = 0, m0 = 1;\n    for (int\
    \ i = 0; i < n; i++) {\n        assert(m[i] >= 1);\n        long long r1 = r[i]\
    \ % m[i], m1 = m[i];\n        if (r1 < 0) r1 += m[i];\n        if (m0 < m1) {\n\
    \            std::swap(r0, r1);\n            std::swap(m0, m1);\n        }\n \
    \       // m0 > m1\n        if (m0 % m1 == 0) {\n            if (r0 % m1 != r1)\
    \ return {0, 0};\n            continue;\n        }\n        // (r0, m0), (r1,\
    \ m1) -> (r2, m2 = lcm(m0, m1))\n        // r2 % m0 = r0\n        // -> r2 = r0\
    \ + x * m0\n        // r2 % m1 = r1\n        // -> (r0 + x * m0) % m1 = r1\n \
    \       // -> x * m0 = r1 - r0 (mod m1)\n        auto [x, h] = linear_congruence(m0,\
    \ r1 - r0, m1);\n        if (x == -1 and h == -1) return {0, 0};\n        r0 +=\
    \ x * m0;\n        m0 *= h;\n        r0 %= m0;\n        if (r0 < 0) r0 += m0;\n\
    \    }\n    return {r0, m0};\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n#include \"math/linear_diophantine.hpp\"\
    \n\n// (rem, mod)\nstd::pair<long long, long long> chinese_remainder_theorem(const\
    \ std::vector<long long>& r, const std::vector<long long>& m) {\n    assert(r.size()\
    \ == m.size());\n    const int n = (int)(r.size());\n    long long r0 = 0, m0\
    \ = 1;\n    for (int i = 0; i < n; i++) {\n        assert(m[i] >= 1);\n      \
    \  long long r1 = r[i] % m[i], m1 = m[i];\n        if (r1 < 0) r1 += m[i];\n \
    \       if (m0 < m1) {\n            std::swap(r0, r1);\n            std::swap(m0,\
    \ m1);\n        }\n        // m0 > m1\n        if (m0 % m1 == 0) {\n         \
    \   if (r0 % m1 != r1) return {0, 0};\n            continue;\n        }\n    \
    \    // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1))\n        // r2 % m0 = r0\n\
    \        // -> r2 = r0 + x * m0\n        // r2 % m1 = r1\n        // -> (r0 +\
    \ x * m0) % m1 = r1\n        // -> x * m0 = r1 - r0 (mod m1)\n        auto [x,\
    \ h] = linear_congruence(m0, r1 - r0, m1);\n        if (x == -1 and h == -1) return\
    \ {0, 0};\n        r0 += x * m0;\n        m0 *= h;\n        r0 %= m0;\n      \
    \  if (r0 < 0) r0 += m0;\n    }\n    return {r0, m0};\n}"
  dependsOn:
  - math/linear_diophantine.hpp
  - math/extended_gcd.hpp
  isVerificationFile: false
  path: math/chinese_remainder_theorem.hpp
  requiredBy: []
  timestamp: '2024-04-27 04:52:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yuki/yuki_186_chinese_remainder_theorem.test.cpp
documentation_of: math/chinese_remainder_theorem.hpp
layout: document
title: "Chinese Remainder Theorem (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
---

答えがない場合は $ (0, 0) $ を返す