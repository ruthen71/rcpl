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
  bundledCode: "#line 2 \"misc/timer.hpp\"\n\n#include <chrono>\n\nstruct Timer {\n\
    \    std::chrono::high_resolution_clock::time_point st;\n\n    Timer() { reset();\
    \ }\n    void reset() { st = std::chrono::high_resolution_clock::now(); }\n\n\
    \    // t [ms]\n    long long elapsed() {\n        auto ed = std::chrono::high_resolution_clock::now();\n\
    \        return std::chrono::duration_cast<std::chrono::milliseconds>(ed - st).count();\n\
    \    }\n    long long operator()() { return elapsed(); }\n} timer;\n"
  code: "#pragma once\n\n#include <chrono>\n\nstruct Timer {\n    std::chrono::high_resolution_clock::time_point\
    \ st;\n\n    Timer() { reset(); }\n    void reset() { st = std::chrono::high_resolution_clock::now();\
    \ }\n\n    // t [ms]\n    long long elapsed() {\n        auto ed = std::chrono::high_resolution_clock::now();\n\
    \        return std::chrono::duration_cast<std::chrono::milliseconds>(ed - st).count();\n\
    \    }\n    long long operator()() { return elapsed(); }\n} timer;"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.hpp
  requiredBy: []
  timestamp: '2024-01-20 17:42:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/timer.hpp
layout: document
redirect_from:
- /library/misc/timer.hpp
- /library/misc/timer.hpp.html
title: misc/timer.hpp
---
