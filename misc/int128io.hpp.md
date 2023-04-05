---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/int128io.hpp\"\n\nstd::istream &operator>>(std::istream\
    \ &is, __int128_t &x) {\n    std::string s;\n    is >> s;\n    x = 0;\n    int\
    \ i = s[0] == '-' ? 1 : 0;\n    while (i < (int)s.size()) {\n        x = 10 *\
    \ x + s[i] - '0';\n        i++;\n    }\n    if (s[0] == '-') x = -x;\n    return\
    \ is;\n}\nstd::ostream &operator<<(std::ostream &os, const __int128_t &x) {\n\
    \    if (x == 0) {\n        return os << 0;\n    }\n    __int128_t y = std::abs(x);\n\
    \    std::string res = \"\";\n    while (y) {\n        res += y % 10 + '0';\n\
    \        y /= 10;\n    }\n    if (x < 0) res += '-';\n    std::reverse(res.begin(),\
    \ res.end());\n    return os << res;\n}\n"
  code: "#pragma once\n\nstd::istream &operator>>(std::istream &is, __int128_t &x)\
    \ {\n    std::string s;\n    is >> s;\n    x = 0;\n    int i = s[0] == '-' ? 1\
    \ : 0;\n    while (i < (int)s.size()) {\n        x = 10 * x + s[i] - '0';\n  \
    \      i++;\n    }\n    if (s[0] == '-') x = -x;\n    return is;\n}\nstd::ostream\
    \ &operator<<(std::ostream &os, const __int128_t &x) {\n    if (x == 0) {\n  \
    \      return os << 0;\n    }\n    __int128_t y = std::abs(x);\n    std::string\
    \ res = \"\";\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n\
    \    }\n    if (x < 0) res += '-';\n    std::reverse(res.begin(), res.end());\n\
    \    return os << res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/int128io.hpp
  requiredBy: []
  timestamp: '2023-04-05 19:46:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/int128io.hpp
layout: document
redirect_from:
- /library/misc/int128io.hpp
- /library/misc/int128io.hpp.html
title: misc/int128io.hpp
---
