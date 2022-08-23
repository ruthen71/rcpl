---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../src/data_structure/segment_tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../src/algebra/monoid_min.hpp\"\n#include \"\
    ../../src/data_structure/segment_tree.hpp\"\n\nint main() {\n    int N, Q;\n \
    \   std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for (int i = 0; i < N;\
    \ i++) std::cin >> A[i];\n    segment_tree<monoid_min<int>> seg(A);\n    while\
    \ (Q--) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout <<\
    \ seg.prod(l, r) << '\\n';\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
- /verify/verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp.html
title: verify/lc_data_structure/lc_static_rmq_segment_tree.test.cpp
---
