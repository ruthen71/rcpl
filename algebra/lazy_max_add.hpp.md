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
  bundledCode: "#line 2 \"algebra/lazy_max_add.hpp\"\n\ntemplate <class S> struct\
    \ LazyMaxAdd {\n    using F = S;\n    using value_type_S = S;\n    using value_type_F\
    \ = F;\n    static constexpr S op(S a, S b) { return std::max(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::lowest(); }\n    static constexpr\
    \ S mapping(F f, S x) { return f + x; }\n    static constexpr F composition(F\
    \ f, F g) { return f + g; }\n    static constexpr F id() { return 0; }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct LazyMaxAdd {\n    using F = S;\n\
    \    using value_type_S = S;\n    using value_type_F = F;\n    static constexpr\
    \ S op(S a, S b) { return std::max(a, b); }\n    static constexpr S e() { return\
    \ std::numeric_limits<S>::lowest(); }\n    static constexpr S mapping(F f, S x)\
    \ { return f + x; }\n    static constexpr F composition(F f, F g) { return f +\
    \ g; }\n    static constexpr F id() { return 0; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/lazy_max_add.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/lazy_max_add.hpp
layout: document
redirect_from:
- /library/algebra/lazy_max_add.hpp
- /library/algebra/lazy_max_add.hpp.html
title: algebra/lazy_max_add.hpp
---
