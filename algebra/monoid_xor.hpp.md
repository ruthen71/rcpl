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
  bundledCode: "#line 2 \"algebra/monoid_xor.hpp\"\n\ntemplate <class S> struct MonoidXor\
    \ {\n    using value_type = S;\n    static constexpr S op(S a, S b) { return a\
    \ ^ b; }\n    static constexpr S e() { return 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct MonoidXor {\n    using value_type\
    \ = S;\n    static constexpr S op(S a, S b) { return a ^ b; }\n    static constexpr\
    \ S e() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_xor.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_xor.hpp
layout: document
redirect_from:
- /library/algebra/monoid_xor.hpp
- /library/algebra/monoid_xor.hpp.html
title: algebra/monoid_xor.hpp
---
