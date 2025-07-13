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
  bundledCode: "#line 2 \"math/quotient_enumeration.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\n// \u5546\u5217\u6319 (quotient enumeration)\n\
    // {l, r, d}: floor(n / x) = d \u3068\u306A\u308B x \u304C l <= x <= r (\u9589\
    \u533A\u9593)\ntemplate <class T> std::vector<std::tuple<T, T, T>> quotient_enumeration(T\
    \ n) {\n    assert(n > 0);\n    std::vector<std::tuple<T, T, T>> res;\n    T l\
    \ = T(1);\n    while (l < n) {\n        T d = n / l;\n        T r = n / d;\n \
    \       res.emplace_back(l, r, d);\n        l = r + 1;\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \n// \u5546\u5217\u6319 (quotient enumeration)\n// {l, r, d}: floor(n / x) = d\
    \ \u3068\u306A\u308B x \u304C l <= x <= r (\u9589\u533A\u9593)\ntemplate <class\
    \ T> std::vector<std::tuple<T, T, T>> quotient_enumeration(T n) {\n    assert(n\
    \ > 0);\n    std::vector<std::tuple<T, T, T>> res;\n    T l = T(1);\n    while\
    \ (l < n) {\n        T d = n / l;\n        T r = n / d;\n        res.emplace_back(l,\
    \ r, d);\n        l = r + 1;\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/quotient_enumeration.hpp
  requiredBy: []
  timestamp: '2025-07-13 20:19:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/quotient_enumeration.hpp
layout: document
redirect_from:
- /library/math/quotient_enumeration.hpp
- /library/math/quotient_enumeration.hpp.html
title: math/quotient_enumeration.hpp
---
