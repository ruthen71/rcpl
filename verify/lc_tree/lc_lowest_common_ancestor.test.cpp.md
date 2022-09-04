---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: src/graph/template.hpp
    title: src/graph/template.hpp
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
    \n#line 2 \"src/graph/lowest_common_ancestor.hpp\"\n\n#line 2 \"src/graph/template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to),\
    \ cost(cost), id(id) {}\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const edge<T> &e) {\n        // { id : from -> to, cost }\n        return os\
    \ << \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T, bool directed = false> struct graph\
    \ {\n    int N, M;\n    using cost_type = T;\n    using edge_type = edge<T>;\n\
    \    std::vector<std::vector<edge_type>> G;\n\n    graph() : N(0), M(0) {}\n \
    \   graph(int N) : N(N), M(0), G(N) {}\n\n    constexpr bool is_directed() { return\
    \ directed; }\n\n    size_t size() const { return G.size(); }\n\n    void read_tree(bool\
    \ weight = false, int offset = 1) { read_graph(N - 1, weight, offset); }\n\n \
    \   void read_graph(int _M, bool weight = false, int offset = 1) {\n        for\
    \ (int i = 0; i < _M; i++) {\n            int a, b;\n            std::cin >> a\
    \ >> b;\n            a -= offset, b -= offset;\n            if (weight) {\n  \
    \              T c;\n                std::cin >> c;\n                add_edge(a,\
    \ b, c);\n            } else {\n                add_edge(a, b);\n            }\n\
    \        }\n    }\n\n    void read_parent(int offset = 1) {\n        for (int\
    \ i = 1; i < N; i++) {\n            int p;\n            std::cin >> p;\n     \
    \       p -= offset;\n            add_edge(i, p);\n        }\n    }\n\n    void\
    \ add_edge(const int &a, const int &b, T cost = 1) {\n        assert(0 <= a and\
    \ a < N and 0 <= b and b < N);\n        if (!directed) G[b].push_back(edge_type(b,\
    \ a, cost, M));\n        G[a].push_back(edge_type(a, b, cost, M++));\n    }\n\n\
    \    inline std::vector<edge_type> &operator[](const int &k) { return G[k]; }\n\
    \n    inline const std::vector<edge_type> &operator[](const int &k) const { return\
    \ G[k]; }\n\n    friend std::ostream &operator<<(std::ostream &os, const graph<T>\
    \ &G) {\n        os << \"V: \" << G.N << '\\n';\n        os << \"E: \" << G.M\
    \ << '\\n';\n        for (int v = 0; v < G.N; v++) {\n            os << \"G[\"\
    \ << v << \"] = \";\n            os << \"[ \";\n            for (auto &e : G[v])\
    \ os << e << \" \";\n            os << \"]\\n\";\n        }\n        return os;\n\
    \    }\n};\n#line 4 \"src/graph/lowest_common_ancestor.hpp\"\n\ntemplate <class\
    \ Graph> struct lowest_common_ancestor {\n    std::vector<int> depth;\n    std::vector<std::vector<int>>\
    \ parent;\n    int n, LOG;\n\n    lowest_common_ancestor(Graph &G, int root =\
    \ 0) : n(G.size()), LOG(32 - __builtin_clz(G.size())) {\n        depth.assign(n,\
    \ 0);\n        parent.assign(LOG, std::vector<int>(n));\n        auto dfs = [&](auto\
    \ f, int cur, int par) -> void {\n            parent[0][cur] = par;\n        \
    \    for (auto &e : G[cur]) {\n                if (e.to == par) continue;\n  \
    \              depth[e.to] = depth[cur] + 1;\n                f(f, e.to, cur);\n\
    \            }\n        };\n        dfs(dfs, root, -1);\n        for (int k =\
    \ 0; k + 1 < LOG; k++) {\n            for (int v = 0; v < n; v++) {\n        \
    \        parent[k + 1][v] = (parent[k][v] < 0 ? -1 : parent[k][parent[k][v]]);\n\
    \            }\n        }\n    }\n\n    int lca(int u, int v) {\n        assert((int)depth.size()\
    \ == n);\n        if (depth[u] > depth[v]) std::swap(u, v);\n        // depth[u]\
    \ <= depth[v]\n        for (int k = 0; k < LOG; k++)\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) v = parent[k][v];\n\n        if (u == v) return u;\n \
    \       for (int k = LOG - 1; k >= 0; k--) {\n            if (parent[k][u] !=\
    \ parent[k][v]) {\n                u = parent[k][u];\n                v = parent[k][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    int level_ancestor(int\
    \ u, int d) {\n        assert((int)depth.size() == n);\n        if (depth[u] <\
    \ d) return -1;\n        for (int k = 0; k < LOG; k++)\n            if (d >> k\
    \ & 1) u = parent[k][u];\n        return u;\n    }\n};\n\n/**\n * @brief Lowest\
    \ Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)\n * @docs docs/graph/lowest_common_ancestor.md\n\
    \ */\n#line 6 \"verify/lc_tree/lc_lowest_common_ancestor.test.cpp\"\n\nint main()\
    \ {\n    int N, Q;\n    std::cin >> N >> Q;\n    graph<long long> G(N);\n    G.read_parent(0);\n\
    \    lowest_common_ancestor<decltype(G)> tq(G, 0);\n    while (Q--) {\n      \
    \  int u, v;\n        std::cin >> u >> v;\n        std::cout << tq.lca(u, v) <<\
    \ '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    \n#include \"src/graph/lowest_common_ancestor.hpp\"\n\nint main() {\n    int N,\
    \ Q;\n    std::cin >> N >> Q;\n    graph<long long> G(N);\n    G.read_parent(0);\n\
    \    lowest_common_ancestor<decltype(G)> tq(G, 0);\n    while (Q--) {\n      \
    \  int u, v;\n        std::cin >> u >> v;\n        std::cout << tq.lca(u, v) <<\
    \ '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - src/graph/lowest_common_ancestor.hpp
  - src/graph/template.hpp
  isVerificationFile: true
  path: verify/lc_tree/lc_lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 19:39:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_tree/lc_lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_tree/lc_lowest_common_ancestor.test.cpp
- /verify/verify/lc_tree/lc_lowest_common_ancestor.test.cpp.html
title: verify/lc_tree/lc_lowest_common_ancestor.test.cpp
---
