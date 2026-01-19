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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../algebra/monoid_f/monoid_add.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../algebra/monoid_f/monoid_add.hpp\"\n#include \"\
    ../algebra/monoid_s/monoid_max.hpp\"\n// MSF\ntemplate <class T> struct MonoidMaxAdd\
    \ {\n    using MS = MonoidMax<T>;\n    using MF = MonoidAdd<T>;\n    using S =\
    \ typename MS::S;\n    using F = typename MF::F;\n    static constexpr S mapping(F\
    \ f, S x) { return f + x; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_s_f/monoid_max_add.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s_f/monoid_max_add.hpp
layout: document
redirect_from:
- /library/algebra/monoid_s_f/monoid_max_add.hpp
- /library/algebra/monoid_s_f/monoid_max_add.hpp.html
title: algebra/monoid_s_f/monoid_max_add.hpp
---
