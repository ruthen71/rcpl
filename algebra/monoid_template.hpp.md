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
  bundledCode: "#line 2 \"algebra/monoid_template.hpp\"\n\ntemplate <class T> struct\
    \ MonoidS {\n    using value_type = ;  // todo\n    static constexpr value_type\
    \ operation(const value_type& a,\n                                          const\
    \ value_type& b) {\n        // todo\n    }\n    static constexpr value_type identity()\
    \ {\n        // todo\n    }\n};\n\ntemplate <class T> struct MonoidF {\n    using\
    \ value_type = ;  // todo\n    static constexpr value_type operation(const value_type&\
    \ f,\n                                          const value_type& g) {\n     \
    \   // todo\n    }\n    static constexpr value_type identity() {\n        // todo\n\
    \    }\n};\n\ntemplate <class T> struct ActedMonoid {\n    using MS = MonoidS<T>;\n\
    \    using MF = MonoidF<T>;\n    using S = typename MS::value_type;\n    using\
    \ F = typename MF::value_type;\n    static constexpr S mapping(const F f, const\
    \ S x, const int size) {\n        // todo\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct MonoidS {\n    using value_type\
    \ = ;  // todo\n    static constexpr value_type operation(const value_type& a,\n\
    \                                          const value_type& b) {\n        //\
    \ todo\n    }\n    static constexpr value_type identity() {\n        // todo\n\
    \    }\n};\n\ntemplate <class T> struct MonoidF {\n    using value_type = ;  //\
    \ todo\n    static constexpr value_type operation(const value_type& f,\n     \
    \                                     const value_type& g) {\n        // todo\n\
    \    }\n    static constexpr value_type identity() {\n        // todo\n    }\n\
    };\n\ntemplate <class T> struct ActedMonoid {\n    using MS = MonoidS<T>;\n  \
    \  using MF = MonoidF<T>;\n    using S = typename MS::value_type;\n    using F\
    \ = typename MF::value_type;\n    static constexpr S mapping(const F f, const\
    \ S x, const int size) {\n        // todo\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_template.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_template.hpp
layout: document
redirect_from:
- /library/algebra/monoid_template.hpp
- /library/algebra/monoid_template.hpp.html
title: algebra/monoid_template.hpp
---
