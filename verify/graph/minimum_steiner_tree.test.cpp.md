---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/minimum_steriner_tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/114\"\n\n#include <iostream>\n\
    \n#include \"graph/read_graph.hpp\"\n#include \"graph/minimum_steriner_tree.hpp\"\
    \n\nint main() {\n    int N, M, T;\n    std::cin >> N >> M >> T;\n    auto g =\
    \ read_graph<long long>(N, M, true);\n    std::vector<int> terminals(T);\n   \
    \ for (int i = 0; i < T; i++) {\n        std::cin >> terminals[i];\n        terminals[i]--;\n\
    \    }\n    if (T <= 15) {\n        auto dp = minimum_steiner_tree(g, terminals,\
    \ 1'000'000'000'000'000'000LL);\n        std::cout << dp.back()[terminals[0]]\
    \ << '\\n';\n    } else {\n        std::cout << minimum_steiner_tree_mst(g, terminals,\
    \ 1'000'000'000'000'000'000LL) << '\\n';\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/graph/minimum_steiner_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/graph/minimum_steiner_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/minimum_steiner_tree.test.cpp
- /verify/verify/graph/minimum_steiner_tree.test.cpp.html
title: verify/graph/minimum_steiner_tree.test.cpp
---
