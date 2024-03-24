---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"my_template_int128.hpp\"\n\n#include <my_template.hpp>\n\
    // type definition\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n// infinity\n\
    template <> constexpr i128 INF<i128> = i128(INF<i64>) * INF<i64>;  // 4e36\ntemplate\
    \ <> constexpr u128 INF<u128> = INF<i128>;                  // 4e36\n// input\n\
    std::istream& operator>>(std::istream& is, i128& x) {\n    std::string s;\n  \
    \  is >> s;\n    x = 0;\n    int i = s[0] == '-' ? 1 : 0;\n    while (i < (int)(s.size()))\
    \ x = 10 * x + s[i++] - '0';\n    if (s[0] == '-') x = -x;\n    return is;\n}\n\
    std::istream& operator>>(std::istream& is, u128& x) {\n    std::string s;\n  \
    \  is >> s;\n    assert(s[0] != '-');\n    x = 0;\n    int i = 0;\n    while (i\
    \ < (int)(s.size())) x = 10 * x + s[i++] - '0';\n    return is;\n}\n// output\n\
    std::ostream& operator<<(std::ostream& os, const i128& x) {\n    if (x == 0) {\n\
    \        return os << 0;\n    }\n    i128 y = (x > 0 ? x : -x);\n    std::string\
    \ res;\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n\
    \    if (x < 0) res += '-';\n    std::reverse(res.begin(), res.end());\n    return\
    \ os << res;\n}\nstd::ostream& operator<<(std::ostream& os, const u128& x) {\n\
    \    if (x == 0) {\n        return os << 0;\n    }\n    u128 y = x;\n    std::string\
    \ res;\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n\
    \    std::reverse(res.begin(), res.end());\n    return os << res;\n}\n// definition\
    \ & input\n#define I128(...)     \\\n    i128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define U128(...)     \\\n    u128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n"
  code: "#pragma once\n\n#include <my_template.hpp>\n// type definition\nusing i128\
    \ = __int128_t;\nusing u128 = __uint128_t;\n// infinity\ntemplate <> constexpr\
    \ i128 INF<i128> = i128(INF<i64>) * INF<i64>;  // 4e36\ntemplate <> constexpr\
    \ u128 INF<u128> = INF<i128>;                  // 4e36\n// input\nstd::istream&\
    \ operator>>(std::istream& is, i128& x) {\n    std::string s;\n    is >> s;\n\
    \    x = 0;\n    int i = s[0] == '-' ? 1 : 0;\n    while (i < (int)(s.size()))\
    \ x = 10 * x + s[i++] - '0';\n    if (s[0] == '-') x = -x;\n    return is;\n}\n\
    std::istream& operator>>(std::istream& is, u128& x) {\n    std::string s;\n  \
    \  is >> s;\n    assert(s[0] != '-');\n    x = 0;\n    int i = 0;\n    while (i\
    \ < (int)(s.size())) x = 10 * x + s[i++] - '0';\n    return is;\n}\n// output\n\
    std::ostream& operator<<(std::ostream& os, const i128& x) {\n    if (x == 0) {\n\
    \        return os << 0;\n    }\n    i128 y = (x > 0 ? x : -x);\n    std::string\
    \ res;\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n\
    \    if (x < 0) res += '-';\n    std::reverse(res.begin(), res.end());\n    return\
    \ os << res;\n}\nstd::ostream& operator<<(std::ostream& os, const u128& x) {\n\
    \    if (x == 0) {\n        return os << 0;\n    }\n    u128 y = x;\n    std::string\
    \ res;\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n\
    \    std::reverse(res.begin(), res.end());\n    return os << res;\n}\n// definition\
    \ & input\n#define I128(...)     \\\n    i128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define U128(...)     \\\n    u128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)"
  dependsOn:
  - my_template.hpp
  isVerificationFile: false
  path: my_template_int128.hpp
  requiredBy: []
  timestamp: '2024-03-24 14:28:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: my_template_int128.hpp
layout: document
redirect_from:
- /library/my_template_int128.hpp
- /library/my_template_int128.hpp.html
title: my_template_int128.hpp
---
