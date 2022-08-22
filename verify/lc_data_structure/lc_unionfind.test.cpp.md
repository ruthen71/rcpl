---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/unionfind.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/lc_data_structure/lc_unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"src/data_structure/unionfind.hpp\"\n\nstruct\
    \ unionfind {\n    std::vector<int> parents;\n\n    unionfind() {}\n    unionfind(int\
    \ n) : parents(n, -1) {}\n\n    int leader(int x) { return parents[x] < 0 ? x\
    \ : parents[x] = leader(parents[x]); }\n\n    bool merge(int x, int y) {\n   \
    \     x = leader(x), y = leader(y);\n        if (x == y) return false;\n     \
    \   if (parents[x] > parents[y]) std::swap(x, y);\n        parents[x] += parents[y];\n\
    \        parents[y] = x;\n        return true;\n    }\n\n    bool same(int x,\
    \ int y) { return leader(x) == leader(y); }\n\n    int size(int x) { return -parents[leader(x)];\
    \ }\n\n    void init(int n) { parents.assign(n, -1); }  // reset\n};\n\n/**\n\
    \ * @brief UnionFind\n * @docs docs/data-structure/unionfind.md\n */\n#line 7\
    \ \"verify/lc_data_structure/lc_unionfind.test.cpp\"\n\nint main() {\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    unionfind uf(N);\n    while (Q--) {\n       \
    \ int t, u, v;\n        cin >> t >> u >> v;\n        if (t == 0) {\n         \
    \   uf.merge(u, v);\n        } else {\n            cout << uf.same(u, v) << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../src/data_structure/unionfind.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    unionfind uf(N);\n  \
    \  while (Q--) {\n        int t, u, v;\n        cin >> t >> u >> v;\n        if\
    \ (t == 0) {\n            uf.merge(u, v);\n        } else {\n            cout\
    \ << uf.same(u, v) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - src/data_structure/unionfind.hpp
  isVerificationFile: true
  path: verify/lc_data_structure/lc_unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-08-22 13:53:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_data_structure/lc_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_data_structure/lc_unionfind.test.cpp
- /verify/verify/lc_data_structure/lc_unionfind.test.cpp.html
title: verify/lc_data_structure/lc_unionfind.test.cpp
---
