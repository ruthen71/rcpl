---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/lc_tree/lc_lowest_common_ancestor.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    \n#line 2 \"graph/lowest_common_ancestor.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Edge<T> &e) {\n        // output format:\
    \ \"{ id : from -> to, cost }\"\n        return os << \"{ \" << e.id << \" : \"\
    \ << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\n\
    template <class T> using Edges = std::vector<Edge<T>>;\ntemplate <class T> using\
    \ Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"graph/lowest_common_ancestor.hpp\"\
    \n\ntemplate <class T> struct LowestCommonAncestor {\n    std::vector<int> depth;\n\
    \    std::vector<std::vector<int>> parent;\n    int n, LOG;\n\n    LowestCommonAncestor(Graph<T>\
    \ &G, int root = 0) : n(G.size()), LOG(32 - __builtin_clz(G.size())) {\n     \
    \   depth.assign(n, 0);\n        parent.assign(LOG, std::vector<int>(n));\n  \
    \      auto dfs = [&](auto f, int cur, int par) -> void {\n            parent[0][cur]\
    \ = par;\n            for (auto &e : G[cur]) {\n                if (e.to == par)\
    \ continue;\n                depth[e.to] = depth[cur] + 1;\n                f(f,\
    \ e.to, cur);\n            }\n        };\n        dfs(dfs, root, -1);\n      \
    \  for (int k = 0; k + 1 < LOG; k++) {\n            for (int v = 0; v < n; v++)\
    \ {\n                parent[k + 1][v] = (parent[k][v] < 0 ? -1 : parent[k][parent[k][v]]);\n\
    \            }\n        }\n    }\n\n    int lca(int u, int v) {\n        assert((int)depth.size()\
    \ == n);\n        if (depth[u] > depth[v]) std::swap(u, v);\n        // depth[u]\
    \ <= depth[v]\n        for (int k = 0; k < LOG; k++)\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) v = parent[k][v];\n\n        if (u == v) return u;\n \
    \       for (int k = LOG - 1; k >= 0; k--) {\n            if (parent[k][u] !=\
    \ parent[k][v]) {\n                u = parent[k][u];\n                v = parent[k][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    int level_ancestor(int\
    \ u, int d) {\n        assert((int)depth.size() == n);\n        if (depth[u] <\
    \ d) return -1;\n        for (int k = 0; k < LOG; k++)\n            if (d >> k\
    \ & 1) u = parent[k][u];\n        return u;\n    }\n};\n#line 6 \"verify/lc_tree/lc_lowest_common_ancestor.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    Graph<int> G(N);\n\
    \    for (int i = 1; i < N; i++) {\n        int p;\n        std::cin >> p;\n \
    \       G[i].push_back(Edge(i, p, 1, i - 1));\n        G[p].push_back(Edge(p,\
    \ i, 1, i - 1));\n    }\n    LowestCommonAncestor tq(G, 0);\n    while (Q--) {\n\
    \        int u, v;\n        std::cin >> u >> v;\n        std::cout << tq.lca(u,\
    \ v) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    \n#include \"graph/lowest_common_ancestor.hpp\"\n\nint main() {\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    Graph<int> G(N);\n    for (int i = 1; i < N; i++)\
    \ {\n        int p;\n        std::cin >> p;\n        G[i].push_back(Edge(i, p,\
    \ 1, i - 1));\n        G[p].push_back(Edge(p, i, 1, i - 1));\n    }\n    LowestCommonAncestor\
    \ tq(G, 0);\n    while (Q--) {\n        int u, v;\n        std::cin >> u >> v;\n\
    \        std::cout << tq.lca(u, v) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - graph/lowest_common_ancestor.hpp
  - graph/graph_template.hpp
  isVerificationFile: true
  path: verify/lc_tree/lc_lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2023-02-10 01:10:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_tree/lc_lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_tree/lc_lowest_common_ancestor.test.cpp
- /verify/verify/lc_tree/lc_lowest_common_ancestor.test.cpp.html
title: verify/lc_tree/lc_lowest_common_ancestor.test.cpp
---
