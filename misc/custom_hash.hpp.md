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
    - http://xorshift.di.unimi.it/splitmix64.c
    - https://codeforces.com/blog/entry/62393
  bundledCode: "#line 2 \"misc/custom_hash.hpp\"\n\n// https://codeforces.com/blog/entry/62393\n\
    struct CustomHash {\n    static uint64_t splitmix64(uint64_t x) {\n        //\
    \ http://xorshift.di.unimi.it/splitmix64.c\n        x += 0x9e3779b97f4a7c15;\n\
    \        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27))\
    \ * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n    }\n\n    uint64_t\
    \ operator()(uint64_t x) const {\n        static const uint64_t FIXED_RANDOM =\
    \ std::chrono::steady_clock::now().time_since_epoch().count();\n        return\
    \ splitmix64(x + FIXED_RANDOM);\n    }\n} ch;\n// unordered_map<int, int, CustomHash>\
    \ mp;\n"
  code: "#pragma once\n\n// https://codeforces.com/blog/entry/62393\nstruct CustomHash\
    \ {\n    static uint64_t splitmix64(uint64_t x) {\n        // http://xorshift.di.unimi.it/splitmix64.c\n\
    \        x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    uint64_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n} ch;\n// unordered_map<int,\
    \ int, CustomHash> mp;\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/custom_hash.hpp
  requiredBy: []
  timestamp: '2024-05-27 02:35:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/custom_hash.hpp
layout: document
redirect_from:
- /library/misc/custom_hash.hpp
- /library/misc/custom_hash.hpp.html
title: misc/custom_hash.hpp
---
