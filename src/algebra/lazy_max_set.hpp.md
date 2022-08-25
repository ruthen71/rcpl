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
  bundledCode: "#line 2 \"src/algebra/lazy_max_set.hpp\"\n\ntemplate <class S> struct\
    \ lazy_max_set {\n    using F = S;\n    using value_type_S = S;\n    using value_type_F\
    \ = F;\n    static constexpr S op(S a, S b) { return std::max(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::min(); }\n    static constexpr\
    \ S init() { return std::numeric_limits<S>::min(); }\n    static constexpr S mapping(F\
    \ f, S x) { return f == id() ? x : f; }\n    static constexpr F composition(F\
    \ f, F g) { return f == id() ? g : f; }\n    static constexpr F id() { return\
    \ std::numeric_limits<F>::min(); }\n};\n"
  code: "#pragma once\n\ntemplate <class S> struct lazy_max_set {\n    using F = S;\n\
    \    using value_type_S = S;\n    using value_type_F = F;\n    static constexpr\
    \ S op(S a, S b) { return std::max(a, b); }\n    static constexpr S e() { return\
    \ std::numeric_limits<S>::min(); }\n    static constexpr S init() { return std::numeric_limits<S>::min();\
    \ }\n    static constexpr S mapping(F f, S x) { return f == id() ? x : f; }\n\
    \    static constexpr F composition(F f, F g) { return f == id() ? g : f; }\n\
    \    static constexpr F id() { return std::numeric_limits<F>::min(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/lazy_max_set.hpp
  requiredBy: []
  timestamp: '2022-08-25 20:09:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/lazy_max_set.hpp
layout: document
redirect_from:
- /library/src/algebra/lazy_max_set.hpp
- /library/src/algebra/lazy_max_set.hpp.html
title: src/algebra/lazy_max_set.hpp
---
