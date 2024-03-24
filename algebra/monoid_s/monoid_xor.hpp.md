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
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_xor.hpp\"\n// MS\ntemplate <class\
    \ T> struct MonoidXor {\n    using S = T;\n    static constexpr S op(S a, S b)\
    \ { return a ^ b; }\n    static constexpr S e() { return T(0); }\n};\n"
  code: "#pragma once\n// MS\ntemplate <class T> struct MonoidXor {\n    using S =\
    \ T;\n    static constexpr S op(S a, S b) { return a ^ b; }\n    static constexpr\
    \ S e() { return T(0); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_s/monoid_xor.hpp
  requiredBy: []
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s/monoid_xor.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s/monoid_xor.hpp
- /library/algebra/monoid_s/monoid_xor.hpp.html
title: algebra/monoid_s/monoid_xor.hpp
---
