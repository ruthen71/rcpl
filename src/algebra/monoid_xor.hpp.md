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
  bundledCode: "#line 2 \"src/algebra/monoid_xor.hpp\"\n\ntemplate <class S> struct\
    \ monoid_xor {\n    using value_type = S;\n    static constexpr S op(S a, S b)\
    \ { return a ^ b; }\n    static constexpr S e() { return 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct monoid_xor {\n    using value_type\
    \ = S;\n    static constexpr S op(S a, S b) { return a ^ b; }\n    static constexpr\
    \ S e() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/monoid_xor.hpp
  requiredBy: []
  timestamp: '2022-09-26 00:29:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/monoid_xor.hpp
layout: document
redirect_from:
- /library/src/algebra/monoid_xor.hpp
- /library/src/algebra/monoid_xor.hpp.html
title: src/algebra/monoid_xor.hpp
---
