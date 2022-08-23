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
  bundledCode: "#line 2 \"src/algebra/monoid_max.hpp\"\n\ntemplate <class S> struct\
    \ monoid_max {\n    using value_type = S;\n    static constexpr S op(S a, S b)\
    \ { return std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::lowest();\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct monoid_max {\n    using value_type\
    \ = S;\n    static constexpr S op(S a, S b) { return std::max(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::lowest(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/monoid_max.hpp
  requiredBy: []
  timestamp: '2022-08-23 21:14:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/monoid_max.hpp
layout: document
redirect_from:
- /library/src/algebra/monoid_max.hpp
- /library/src/algebra/monoid_max.hpp.html
title: src/algebra/monoid_max.hpp
---
