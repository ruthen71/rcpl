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
  bundledCode: "#line 2 \"src/algebra/monoid_min.hpp\"\n\ntemplate <class S> struct\
    \ monoid_min {\n    using value_type = S;\n    static constexpr S op(S a, S b)\
    \ { return std::min(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::max();\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct monoid_min {\n    using value_type\
    \ = S;\n    static constexpr S op(S a, S b) { return std::min(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::max(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/monoid_min.hpp
  requiredBy: []
  timestamp: '2022-08-23 17:30:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/monoid_min.hpp
layout: document
redirect_from:
- /library/src/algebra/monoid_min.hpp
- /library/src/algebra/monoid_min.hpp.html
title: src/algebra/monoid_min.hpp
---