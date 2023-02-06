---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/read_graph.hpp
    title: graph/read_graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"verify/lc_tree/lc_tree_diameter.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include <bits/stdc++.h>\n\
    \n#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\n\n\
    template <class T> struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\
    \n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id = -1) :\
    \ from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Edge<T> &e) {\n        // { id : from -> to, cost }\n        return\
    \ os << \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    graph/read_graph.hpp\"\n\ntemplate <class T> Graph<T> read_graph(int N, int M,\
    \ const bool weight = false, const bool directed = false, const int offset = 1)\
    \ {\n    Graph<T> G(N);\n    for (int i = 0; i < M; i++) {\n        int a, b;\n\
    \        std::cin >> a >> b;\n        a -= offset, b -= offset;\n        if (weight)\
    \ {\n            T c;\n            std::cin >> c;\n            if (!directed)\
    \ G[b].push_back(Edge(b, a, c, i));\n            G[a].push_back(Edge(a, b, c,\
    \ i));\n        } else {\n            // c = 1\n            if (!directed) G[b].push_back(Edge(b,\
    \ a, T(1), i));\n            G[a].push_back(Edge(a, b, T(1), i));\n        }\n\
    \    }\n    return G;\n}\n#line 2 \"graph/tree_diameter.hpp\"\n\n#line 4 \"graph/tree_diameter.hpp\"\
    \n\ntemplate <class T> std::pair<T, std::vector<Edge<T>>> tree_diameter(Graph<T>\
    \ &G) {\n    std::vector<int> to(G.size(), -1);\n\n    auto dfs = [&](auto f,\
    \ int cur, int par) -> std::pair<T, int> {\n        std::pair<T, int> ret = {0,\
    \ cur};\n        for (auto &e : G[cur]) {\n            if (e.to == par) continue;\n\
    \            auto cost = f(f, e.to, cur);\n            cost.first += e.cost;\n\
    \            if (ret.first < cost.first) {\n                ret = cost;\n    \
    \            to[cur] = e.to;\n            }\n        }\n        return ret;\n\
    \    };\n\n    auto s = dfs(dfs, 0, -1);\n    auto t = dfs(dfs, s.second, -1);\n\
    \n    int cur = s.second;\n    std::vector<Edge<T>> path;\n    while (cur != t.second)\
    \ {\n        for (auto &e : G[cur]) {\n            if (to[cur] == e.to) {\n  \
    \              path.emplace_back(e);\n            }\n        }\n        cur =\
    \ to[cur];\n    }\n    return {t.first, path};\n}\n#line 7 \"verify/lc_tree/lc_tree_diameter.test.cpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    auto G = read_graph<long\
    \ long>(N, N - 1, true, false, 0);\n    auto [d, path] = tree_diameter(G);\n \
    \   std::cout << d << ' ' << path.size() + 1 << '\\n';\n    std::cout << path.front().from;\n\
    \    for (auto &e : path) {\n        std::cout << ' ' << e.to;\n    }\n    std::cout\
    \ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"graph/read_graph.hpp\"\n#include \"graph/tree_diameter.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    auto G = read_graph<long\
    \ long>(N, N - 1, true, false, 0);\n    auto [d, path] = tree_diameter(G);\n \
    \   std::cout << d << ' ' << path.size() + 1 << '\\n';\n    std::cout << path.front().from;\n\
    \    for (auto &e : path) {\n        std::cout << ' ' << e.to;\n    }\n    std::cout\
    \ << '\\n';\n    return 0;\n}"
  dependsOn:
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/tree_diameter.hpp
  isVerificationFile: true
  path: verify/lc_tree/lc_tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 23:29:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_tree/lc_tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_tree/lc_tree_diameter.test.cpp
- /verify/verify/lc_tree/lc_tree_diameter.test.cpp.html
title: verify/lc_tree/lc_tree_diameter.test.cpp
---
