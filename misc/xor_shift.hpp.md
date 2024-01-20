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
  bundledCode: "#line 2 \"misc/xor_shift.hpp\"\n#include <cassert>\n\nstruct XorShift\
    \ {\n    unsigned long long x = 88172645463325252ULL;\n    // [0, 2 ^ 64 - 1]\n\
    \    unsigned long long rand_int() {\n        x = x ^ (x << 7);\n        x = x\
    \ ^ (x >> 9);\n        return x;\n    }\n    // [0, mod - 1]\n    long long rand_int(long\
    \ long mod) {\n        assert(mod > 0);\n        return rand_int() % mod;\n  \
    \  }\n    // [l, r]\n    long long rand_int(long long l, long long r) {\n    \
    \    assert(l <= r);\n        return l + rand_int(r - l + 1);\n    }\n    // [0,\
    \ 1.0]\n    double rand_double() { return rand_int() * 5.42101086242752217004e-20;\
    \ }\n    // [l, r]\n    double rand_double(double l, double r) {\n        assert(l\
    \ <= r);\n        return l + rand_double() * (r - l);\n    }\n} rnd;\n"
  code: "#pragma once\n#include <cassert>\n\nstruct XorShift {\n    unsigned long\
    \ long x = 88172645463325252ULL;\n    // [0, 2 ^ 64 - 1]\n    unsigned long long\
    \ rand_int() {\n        x = x ^ (x << 7);\n        x = x ^ (x >> 9);\n       \
    \ return x;\n    }\n    // [0, mod - 1]\n    long long rand_int(long long mod)\
    \ {\n        assert(mod > 0);\n        return rand_int() % mod;\n    }\n    //\
    \ [l, r]\n    long long rand_int(long long l, long long r) {\n        assert(l\
    \ <= r);\n        return l + rand_int(r - l + 1);\n    }\n    // [0, 1.0]\n  \
    \  double rand_double() { return rand_int() * 5.42101086242752217004e-20; }\n\
    \    // [l, r]\n    double rand_double(double l, double r) {\n        assert(l\
    \ <= r);\n        return l + rand_double() * (r - l);\n    }\n} rnd;"
  dependsOn: []
  isVerificationFile: false
  path: misc/xor_shift.hpp
  requiredBy: []
  timestamp: '2024-01-20 17:42:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/xor_shift.hpp
layout: document
redirect_from:
- /library/misc/xor_shift.hpp
- /library/misc/xor_shift.hpp.html
title: misc/xor_shift.hpp
---
