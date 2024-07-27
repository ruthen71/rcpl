---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':question:'
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
    #line 4 \"graph/graph_template.hpp\"\ntemplate <class T> struct Edge {\n    int\
    \ from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from,\
    \ int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\
    \n    friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n\
    \        // output format: \"{ id : from -> to, cost }\"\n        return os <<\
    \ \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    graph/read_graph.hpp\"\n\ntemplate <class T> Graph<T> read_graph(const int n,\
    \ const int m, const bool weight = false, const bool directed = false, const int\
    \ offset = 1) {\n    Graph<T> g(n);\n    for (int i = 0; i < m; i++) {\n     \
    \   int a, b;\n        std::cin >> a >> b;\n        a -= offset, b -= offset;\n\
    \        if (weight) {\n            T c;\n            std::cin >> c;\n       \
    \     if (!directed) g[b].push_back(Edge(b, a, c, i));\n            g[a].push_back(Edge(a,\
    \ b, c, i));\n        } else {\n            // c = 1\n            if (!directed)\
    \ g[b].push_back(Edge(b, a, T(1), i));\n            g[a].push_back(Edge(a, b,\
    \ T(1), i));\n        }\n    }\n    return g;\n}\n\ntemplate <class T> Graph<T>\
    \ read_parent(const int n, const bool weight = false, const bool directed = false,\
    \ const int offset = 1) {\n    Graph<T> g(n);\n    for (int i = 1; i < n; i++)\
    \ {\n        int p;\n        std::cin >> p;\n        p -= offset;\n        if\
    \ (weight) {\n            T c;\n            std::cin >> c;\n            if (!directed)\
    \ g[i].push_back(Edge(i, p, c, i - 1));\n            g[p].push_back(Edge(p, i,\
    \ c, i - 1));\n        } else {\n            // c = 1\n            if (!directed)\
    \ g[i].push_back(Edge(i, p, T(1), i - 1));\n            g[p].push_back(Edge(p,\
    \ i, T(1), i - 1));\n        }\n    }\n    return g;\n}\n\nstd::tuple<Graph<int>,\
    \ std::vector<std::vector<int>>, std::vector<std::pair<int, int>>> read_grid(const\
    \ int h, const int w, std::string rel = \".#\") {\n    std::vector<std::string>\
    \ s(h);\n    std::vector id(h, std::vector<int>(w, -1));\n    std::vector<std::pair<int,\
    \ int>> loc;\n    int n = 0;\n    for (int i = 0; i < h; i++) {\n        std::cin\
    \ >> s[i];\n        for (int j = 0; j < w; j++) {\n            if (s[i][j] ==\
    \ rel[1]) {\n                id[i][j] = n++;\n                loc.emplace_back(i,\
    \ j);\n            }\n        }\n    }\n    int m = 0;\n    Graph<int> g(n);\n\
    \    for (int i = 0; i < h; i++) {\n        for (int j = 0; j < w; j++) {\n  \
    \          if (s[i][j] == rel[1]) {\n                if (i + 1 < h and s[i + 1][j]\
    \ == rel[1]) {\n                    g[id[i][j]].push_back(Edge(id[i][j], id[i\
    \ + 1][j], 1, m));\n                    g[id[i + 1][j]].push_back(Edge(id[i +\
    \ 1][j], id[i][j], 1, m++));\n                }\n                if (j + 1 < w\
    \ and s[i][j + 1] == rel[1]) {\n                    g[id[i][j]].push_back(Edge(id[i][j],\
    \ id[i][j + 1], 1, m));\n                    g[id[i][j + 1]].push_back(Edge(id[i][j\
    \ + 1], id[i][j], 1, m++));\n                }\n            }\n        }\n   \
    \ }\n    return {g, id, loc};\n}\n#line 2 \"graph/tree_diameter.hpp\"\n\n#line\
    \ 4 \"graph/tree_diameter.hpp\"\n// {\u76F4\u5F84\u306E\u8FBA\u306E\u91CD\u307F\
    \u306E\u7DCF\u548C, \u901A\u308B\u9802\u70B9\u96C6\u5408}\ntemplate <class T>\
    \ std::pair<T, std::vector<Edge<T>>> tree_diameter(Graph<T> &G) {\n    std::vector<int>\
    \ to(G.size(), -1);\n\n    auto dfs = [&](auto f, int cur, int par) -> std::pair<T,\
    \ int> {\n        std::pair<T, int> ret = {0, cur};\n        for (auto &e : G[cur])\
    \ {\n            if (e.to == par) continue;\n            auto cost = f(f, e.to,\
    \ cur);\n            cost.first += e.cost;\n            if (ret.first < cost.first)\
    \ {\n                ret = cost;\n                to[cur] = e.to;\n          \
    \  }\n        }\n        return ret;\n    };\n\n    auto s = dfs(dfs, 0, -1);\n\
    \    auto t = dfs(dfs, s.second, -1);\n\n    int cur = s.second;\n    std::vector<Edge<T>>\
    \ path;\n    while (cur != t.second) {\n        for (auto &e : G[cur]) {\n   \
    \         if (to[cur] == e.to) {\n                path.emplace_back(e);\n    \
    \        }\n        }\n        cur = to[cur];\n    }\n    return {t.first, path};\n\
    }\n#line 7 \"verify/lc_tree/lc_tree_diameter.test.cpp\"\n\nint main() {\n    int\
    \ N;\n    std::cin >> N;\n    auto G = read_graph<long long>(N, N - 1, true, false,\
    \ 0);\n    auto [d, path] = tree_diameter(G);\n    std::cout << d << ' ' << path.size()\
    \ + 1 << '\\n';\n    std::cout << path.front().from;\n    for (auto &e : path)\
    \ {\n        std::cout << ' ' << e.to;\n    }\n    std::cout << '\\n';\n    return\
    \ 0;\n}\n"
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
  timestamp: '2024-07-07 00:10:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_tree/lc_tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_tree/lc_tree_diameter.test.cpp
- /verify/verify/lc_tree/lc_tree_diameter.test.cpp.html
title: verify/lc_tree/lc_tree_diameter.test.cpp
---
