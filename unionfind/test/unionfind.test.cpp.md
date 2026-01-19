---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: unionfind/unionfind.hpp
    title: Unionfind
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
  bundledCode: "#line 1 \"unionfind/test/unionfind.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/unionfind\"\n\n#include <iostream>\n\n#line 2\
    \ \"unionfind/unionfind.hpp\"\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <vector>\n\n// Unionfind\nstruct Unionfind {\n    int n;\n    std::vector<int>\
    \ parent;\n\n    Unionfind() = default;\n\n    explicit Unionfind(int n) : n(n),\
    \ parent(n, -1) {}\n\n    int leader(int x) {\n        assert(0 <= x and x < n);\n\
    \        if (parent[x] < 0) {\n            return x;\n        } else {\n     \
    \       return parent[x] = leader(parent[x]);\n        }\n    }\n\n    int merge(int\
    \ x, int y) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and y\
    \ < n);\n        x = leader(x);\n        y = leader(y);\n        if (x == y) {\n\
    \            return x;\n        }\n        if (-parent[x] < -parent[y]) {\n  \
    \          std::swap(x, y);\n        }\n        parent[x] += parent[y];\n    \
    \    parent[y] = x;\n        return x;\n    }\n\n    bool same(int x, int y) {\n\
    \        assert(0 <= x and x < n);\n        assert(0 <= y and y < n);\n      \
    \  return leader(x) == leader(y);\n    }\n\n    int size(int x) {\n        assert(0\
    \ <= x and x < n);\n        return -parent[leader(x)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(n), group_size(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n    \
    \        group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(\n                         result.begin(),\
    \ result.end(),\n                         [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n                     result.end());\n        return result;\n\
    \    }\n};\n#line 6 \"unionfind/test/unionfind.test.cpp\"\n\nint main() {\n  \
    \  int n, q;\n    std::cin >> n >> q;\n    Unionfind uf(n);\n    for (int i =\
    \ 0; i < q; i++) {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n \
    \       if (t == 0) {\n            uf.merge(u, v);\n        } else {\n       \
    \     std::cout << uf.same(u, v) << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n\n#include \"../../unionfind/unionfind.hpp\"\n\nint main() {\n \
    \   int n, q;\n    std::cin >> n >> q;\n    Unionfind uf(n);\n    for (int i =\
    \ 0; i < q; i++) {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n \
    \       if (t == 0) {\n            uf.merge(u, v);\n        } else {\n       \
    \     std::cout << uf.same(u, v) << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  dependsOn:
  - unionfind/unionfind.hpp
  isVerificationFile: true
  path: unionfind/test/unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-12-10 04:21:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unionfind/test/unionfind.test.cpp
layout: document
redirect_from:
- /verify/unionfind/test/unionfind.test.cpp
- /verify/unionfind/test/unionfind.test.cpp.html
title: unionfind/test/unionfind.test.cpp
---
