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
    \ MonoidS {\n    using S = ;  // todo\n    static constexpr S op(S a, S b) {\n\
    \        // todo\n    }\n    static constexpr S e() {\n        // todo\n    }\n\
    };\n\ntemplate <class T> struct MonoidF {\n    using F = ;  // todo\n    static\
    \ constexpr F composition(F f, F g) {\n        // todo\n    }\n    static constexpr\
    \ F id() {\n        // todo\n    }\n};\n\ntemplate <class T> struct MonoidSF {\n\
    \    using MS = MonoidS<T>;\n    using MF = MonoidF<T>;\n    using S = typename\
    \ MS::S;\n    using F = typename MF::F;\n    static constexpr S mapping(F f, S\
    \ x) {\n        // todo\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct MonoidS {\n    using S = ;  //\
    \ todo\n    static constexpr S op(S a, S b) {\n        // todo\n    }\n    static\
    \ constexpr S e() {\n        // todo\n    }\n};\n\ntemplate <class T> struct MonoidF\
    \ {\n    using F = ;  // todo\n    static constexpr F composition(F f, F g) {\n\
    \        // todo\n    }\n    static constexpr F id() {\n        // todo\n    }\n\
    };\n\ntemplate <class T> struct MonoidSF {\n    using MS = MonoidS<T>;\n    using\
    \ MF = MonoidF<T>;\n    using S = typename MS::S;\n    using F = typename MF::F;\n\
    \    static constexpr S mapping(F f, S x) {\n        // todo\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_template.hpp
  requiredBy: []
  timestamp: '2024-06-09 21:34:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_template.hpp
layout: document
redirect_from:
- /library/algebra/monoid_template.hpp
- /library/algebra/monoid_template.hpp.html
title: algebra/monoid_template.hpp
---
