---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../algebra/monoid_f/monoid_set.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"algebra/monoid_s_f/monoid_sum_size_set.hpp\"\
    \n#include \"data_structure/lazy_segment_tree.hpp\"\n\nint main() {\n    int N,\
    \ Q;\n    std::cin >> N >> Q;\n    LazySegmentTree<MonoidSumSizeSet<long long>>\
    \ seg(std::vector<std::pair<long long, int>>(N, {0, 1}));\n    while (Q--) {\n\
    \        int t;\n        std::cin >> t;\n        if (t == 0) {\n            int\
    \ l, r, x;\n            std::cin >> l >> r >> x;\n            seg.apply(l, r +\
    \ 1, x);\n        } else {\n            int l, r;\n            std::cin >> l >>\
    \ r;\n            std::cout << seg.prod(l, r + 1).first << '\\n';\n        }\n\
    \    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
- /verify/verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp.html
title: verify/aoj_dsl/aoj_dsl_2_i_lazy_segment_tree.test.cpp
---
