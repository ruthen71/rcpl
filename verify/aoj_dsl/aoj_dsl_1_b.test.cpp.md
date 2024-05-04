---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/weighted_unionfind.hpp
    title: "Weighted UnionFind (\u91CD\u307F\u3064\u304D UnionFind)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"verify/aoj_dsl/aoj_dsl_1_b.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"data_structure/weighted_unionfind.hpp\"\n\ntemplate\
    \ <class T> struct WeightedUnionFind {\n    int n;\n    std::vector<int> parents;\n\
    \    std::vector<T> diff_weight;\n\n    WeightedUnionFind() {}\n    WeightedUnionFind(int\
    \ n) : n(n), parents(n, -1), diff_weight(n, T(0)) {}\n\n    int leader(int x)\
    \ {\n        if (parents[x] < 0) {\n            return x;\n        } else {\n\
    \            int r = leader(parents[x]);\n            diff_weight[x] += diff_weight[parents[x]];\n\
    \            return parents[x] = r;\n        }\n    }\n\n    T weight(int x) {\n\
    \        leader(x);\n        return diff_weight[x];\n    }\n\n    // weight(y)\
    \ = weight(x) + w\n    bool merge(int x, int y, T w) {\n        w += weight(x);\n\
    \        w -= weight(y);\n        x = leader(x), y = leader(y);\n        if (x\
    \ == y) return false;\n        if (parents[x] > parents[y]) std::swap(x, y), w\
    \ = -w;\n        parents[x] += parents[y];\n        parents[y] = x;\n        diff_weight[y]\
    \ = w;\n        return true;\n    }\n\n    // return weight(y) - weight(x)\n \
    \   T diff(int x, int y) { return weight(y) - weight(x); }\n\n    bool same(int\
    \ x, int y) { return leader(x) == leader(y); }\n\n    int size(int x) { return\
    \ -parents[leader(x)]; }\n\n    // \u9023\u7D50\u6210\u5206\u3054\u3068\u306B\
    \ (\u9802\u70B9\u756A\u53F7 v, diff(leader(v), v)) \u306E\u914D\u5217\u3092\u8FD4\
    \u3059\n    std::vector<std::vector<std::pair<int, T>>> groups() {\n        std::vector<int>\
    \ leader_buf(n), group_size(n);\n        for (int i = 0; i < n; i++) {\n     \
    \       leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<std::pair<int, T>>> result(n);\n \
    \       for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].emplace_back(i,\
    \ weight(i));\n        }\n        result.erase(std::remove_if(result.begin(),\
    \ result.end(), [&](const std::vector<std::pair<int, T>>& v) { return v.empty();\
    \ }), result.end());\n        return result;\n    }\n\n    void init(int n) {\
    \ parents.assign(n, -1), diff_weight.assign(n, T(0)); }  // reset\n};\n#line 6\
    \ \"verify/aoj_dsl/aoj_dsl_1_b.test.cpp\"\n\nint main() {\n    int N, Q;\n   \
    \ std::cin >> N >> Q;\n    WeightedUnionFind<long long> uf(N);\n    while (Q--)\
    \ {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n         \
    \   int x, y;\n            std::cin >> x >> y;\n            long long z;\n   \
    \         std::cin >> z;\n            uf.merge(x, y, z);\n        } else {\n \
    \           int x, y;\n            std::cin >> x >> y;\n            if (uf.same(x,\
    \ y)) {\n                std::cout << uf.diff(x, y) << '\\n';\n            } else\
    \ {\n                std::cout << '?' << '\\n';\n            }\n        }\n  \
    \  }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"data_structure/weighted_unionfind.hpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    WeightedUnionFind<long\
    \ long> uf(N);\n    while (Q--) {\n        int t;\n        std::cin >> t;\n  \
    \      if (t == 0) {\n            int x, y;\n            std::cin >> x >> y;\n\
    \            long long z;\n            std::cin >> z;\n            uf.merge(x,\
    \ y, z);\n        } else {\n            int x, y;\n            std::cin >> x >>\
    \ y;\n            if (uf.same(x, y)) {\n                std::cout << uf.diff(x,\
    \ y) << '\\n';\n            } else {\n                std::cout << '?' << '\\\
    n';\n            }\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - data_structure/weighted_unionfind.hpp
  isVerificationFile: true
  path: verify/aoj_dsl/aoj_dsl_1_b.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 23:26:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_dsl/aoj_dsl_1_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dsl/aoj_dsl_1_b.test.cpp
- /verify/verify/aoj_dsl/aoj_dsl_1_b.test.cpp.html
title: verify/aoj_dsl/aoj_dsl_1_b.test.cpp
---
