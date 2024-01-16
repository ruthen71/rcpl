---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: "Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\
      \u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/read_graph.hpp
    title: graph/read_graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"verify/aoj_grl/aoj_grl_1_b.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"graph/bellman_ford.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Edge<T> &e) {\n        // output format:\
    \ \"{ id : from -> to, cost }\"\n        return os << \"{ \" << e.id << \" : \"\
    \ << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\n\
    template <class T> using Edges = std::vector<Edge<T>>;\ntemplate <class T> using\
    \ Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"graph/bellman_ford.hpp\"\
    \n\ntemplate <class T>\nstd::tuple<std::vector<T>, std::vector<int>, std::vector<int>>\
    \  //\nbellman_ford(Graph<T> &G, std::vector<int> &s, const T INF) {\n    int\
    \ N = (int)G.size();\n    std::vector<T> dist(N, INF);\n    std::vector<int> par(N,\
    \ -1), root(N, -1);\n\n    for (auto &v : s) {\n        dist[v] = 0;\n       \
    \ root[v] = v;\n    }\n    int loop_count = 0;\n\n    while (true) {\n       \
    \ loop_count++;\n        bool update = false;\n        for (int cur = 0; cur <\
    \ N; cur++) {\n            if (dist[cur] == INF) continue;\n            for (auto\
    \ &e : G[cur]) {\n                T nd = std::max(-INF, dist[cur] + e.cost);\n\
    \                if (dist[e.to] > nd) {\n                    par[e.to] = cur;\n\
    \                    root[e.to] = root[cur];\n                    update = true;\n\
    \                    if (loop_count >= N) nd = -INF;\n                    dist[e.to]\
    \ = nd;\n                }\n            }\n        }\n        if (!update) break;\n\
    \    }\n    return {dist, par, root};\n}\n#line 2 \"graph/read_graph.hpp\"\n\n\
    #line 4 \"graph/read_graph.hpp\"\n\ntemplate <class T> Graph<T> read_graph(int\
    \ n, int m, const bool weight = false, const bool directed = false, const int\
    \ offset = 1) {\n    Graph<T> g(n);\n    for (int i = 0; i < m; i++) {\n     \
    \   int a, b;\n        std::cin >> a >> b;\n        a -= offset, b -= offset;\n\
    \        if (weight) {\n            T c;\n            std::cin >> c;\n       \
    \     if (!directed) g[b].push_back(Edge(b, a, c, i));\n            g[a].push_back(Edge(a,\
    \ b, c, i));\n        } else {\n            // c = 1\n            if (!directed)\
    \ g[b].push_back(Edge(b, a, T(1), i));\n            g[a].push_back(Edge(a, b,\
    \ T(1), i));\n        }\n    }\n    return g;\n}\n\nstd::tuple<Graph<int>, std::vector<std::vector<int>>,\
    \ std::vector<std::pair<int, int>>> read_grid(const int h, const int w, std::string\
    \ rel = \".#\") {\n    std::vector<std::string> s(h);\n    std::vector id(h, std::vector<int>(w,\
    \ -1));\n    std::vector<std::pair<int, int>> loc;\n    int n = 0;\n    for (int\
    \ i = 0; i < h; i++) {\n        std::cin >> s[i];\n        for (int j = 0; j <\
    \ w; j++) {\n            if (s[i][j] == rel[1]) {\n                id[i][j] =\
    \ n++;\n                loc.emplace_back(i, j);\n            }\n        }\n  \
    \  }\n    int m = 0;\n    Graph<int> g(n);\n    for (int i = 0; i < h; i++) {\n\
    \        for (int j = 0; j < w; j++) {\n            if (s[i][j] == rel[1]) {\n\
    \                if (i + 1 < h and s[i + 1][j] == rel[1]) {\n                \
    \    g[id[i][j]].push_back(Edge(id[i][j], id[i + 1][j], 1, m));\n            \
    \        g[id[i + 1][j]].push_back(Edge(id[i + 1][j], id[i][j], 1, m++));\n  \
    \              }\n                if (j + 1 < w and s[i][j + 1] == rel[1]) {\n\
    \                    g[id[i][j]].push_back(Edge(id[i][j], id[i][j + 1], 1, m));\n\
    \                    g[id[i][j + 1]].push_back(Edge(id[i][j + 1], id[i][j], 1,\
    \ m++));\n                }\n            }\n        }\n    }\n    return {g, id,\
    \ loc};\n}\n#line 7 \"verify/aoj_grl/aoj_grl_1_b.test.cpp\"\n\nint main() {\n\
    \    int N, M, r;\n    std::cin >> N >> M >> r;\n    auto G = read_graph<int>(N,\
    \ M, true, true, 0);\n    std::vector<int> s = {r};\n    const int INF = 1 <<\
    \ 30;\n    auto [dist, par, root] = bellman_ford(G, s, INF);\n    int ans = *std::min_element(dist.begin(),\
    \ dist.end());\n    if (ans == -INF) {\n        std::cout << \"NEGATIVE CYCLE\"\
    \ << '\\n';\n    } else {\n        for (int i = 0; i < N; i++) {\n           \
    \ if (dist[i] == INF) {\n                std::cout << \"INF\" << '\\n';\n    \
    \        } else {\n                std::cout << dist[i] << '\\n';\n          \
    \  }\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"graph/bellman_ford.hpp\"\n#include\
    \ \"graph/read_graph.hpp\"\n\nint main() {\n    int N, M, r;\n    std::cin >>\
    \ N >> M >> r;\n    auto G = read_graph<int>(N, M, true, true, 0);\n    std::vector<int>\
    \ s = {r};\n    const int INF = 1 << 30;\n    auto [dist, par, root] = bellman_ford(G,\
    \ s, INF);\n    int ans = *std::min_element(dist.begin(), dist.end());\n    if\
    \ (ans == -INF) {\n        std::cout << \"NEGATIVE CYCLE\" << '\\n';\n    } else\
    \ {\n        for (int i = 0; i < N; i++) {\n            if (dist[i] == INF) {\n\
    \                std::cout << \"INF\" << '\\n';\n            } else {\n      \
    \          std::cout << dist[i] << '\\n';\n            }\n        }\n    }\n \
    \   return 0;\n}"
  dependsOn:
  - graph/bellman_ford.hpp
  - graph/graph_template.hpp
  - graph/read_graph.hpp
  isVerificationFile: true
  path: verify/aoj_grl/aoj_grl_1_b.test.cpp
  requiredBy: []
  timestamp: '2024-01-15 16:50:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_grl/aoj_grl_1_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_grl/aoj_grl_1_b.test.cpp
- /verify/verify/aoj_grl/aoj_grl_1_b.test.cpp.html
title: verify/aoj_grl/aoj_grl_1_b.test.cpp
---
