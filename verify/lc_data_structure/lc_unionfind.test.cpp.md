---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/unionfind.hpp
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
    \n#line 2 \"data_structure/unionfind.hpp\"\n\n#line 5 \"data_structure/unionfind.hpp\"\
    \n\nstruct UnionFind {\n    int n;\n    std::vector<int> parents;\n\n    UnionFind()\
    \ {}\n    UnionFind(int n) : n(n), parents(n, -1) {}\n\n    int leader(int x)\
    \ { return parents[x] < 0 ? x : parents[x] = leader(parents[x]); }\n\n    bool\
    \ merge(int x, int y) {\n        x = leader(x), y = leader(y);\n        if (x\
    \ == y) return false;\n        if (parents[x] > parents[y]) std::swap(x, y);\n\
    \        parents[x] += parents[y];\n        parents[y] = x;\n        return true;\n\
    \    }\n\n    bool same(int x, int y) { return leader(x) == leader(y); }\n\n \
    \   int size(int x) { return -parents[leader(x)]; }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(n), group_size(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n    \
    \        group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(result.begin(), result.end(),\
    \ [&](const std::vector<int>& v) { return v.empty(); }), result.end());\n    \
    \    return result;\n    }\n\n    void init(int n) { parents.assign(n, -1); }\
    \  // reset\n};\n#line 6 \"verify/lc_data_structure/lc_unionfind.test.cpp\"\n\n\
    int main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    UnionFind uf(N);\n \
    \   while (Q--) {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n  \
    \      if (t == 0) {\n            uf.merge(u, v);\n        } else {\n        \
    \    std::cout << uf.same(u, v) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"data_structure/unionfind.hpp\"\n\nint main() {\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    UnionFind uf(N);\n    while (Q--)\
    \ {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n        if (t ==\
    \ 0) {\n            uf.merge(u, v);\n        } else {\n            std::cout <<\
    \ uf.same(u, v) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/unionfind.hpp
  isVerificationFile: true
  path: verify/lc_data_structure/lc_unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-07-31 17:25:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_data_structure/lc_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_data_structure/lc_unionfind.test.cpp
- /verify/verify/lc_data_structure/lc_unionfind.test.cpp.html
title: verify/lc_data_structure/lc_unionfind.test.cpp
---
