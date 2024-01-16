---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "Dijkstra's algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/lc_graph/lc_shortest_path_dijkstra.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include <bits/stdc++.h>\n\
    \n#line 2 \"graph/dijkstra.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\n\ntemplate\
    \ <class T> struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\n   \
    \ Edge() = default;\n    Edge(int from, int to, T cost = 1, int id = -1) : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Edge<T> &e) {\n        // output format: \"{ id : from -> to, cost\
    \ }\"\n        return os << \"{ \" << e.id << \" : \" << e.from << \" -> \" <<\
    \ e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using Edges\
    \ = std::vector<Edge<T>>;\ntemplate <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n\
    #line 4 \"graph/dijkstra.hpp\"\n\ntemplate <class T>\nstd::tuple<std::vector<T>,\
    \ std::vector<int>, std::vector<int>>  //\ndijkstra(Graph<T> &G, std::vector<int>\
    \ &s, const T INF) {\n    int N = (int)G.size();\n    std::vector<T> dist(N, INF);\n\
    \    std::vector<int> par(N, -1), root(N, -1);\n\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;\n\
    \n    for (auto &v : s) {\n        dist[v] = 0;\n        root[v] = v;\n      \
    \  que.emplace(T(0), v);\n    }\n\n    while (!que.empty()) {\n        auto [d,\
    \ v] = que.top();\n        que.pop();\n        if (dist[v] != d) continue;  //\
    \ dist[v] < d\n        for (auto &e : G[v]) {\n            if (dist[e.to] > d\
    \ + e.cost) {\n                dist[e.to] = d + e.cost;\n                root[e.to]\
    \ = root[v];\n                par[e.to] = v;\n                que.emplace(dist[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return {dist, par, root};\n}\n\
    #line 2 \"graph/read_graph.hpp\"\n\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate\
    \ <class T> Graph<T> read_graph(int n, int m, const bool weight = false, const\
    \ bool directed = false, const int offset = 1) {\n    Graph<T> g(n);\n    for\
    \ (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >> b;\n\
    \        a -= offset, b -= offset;\n        if (weight) {\n            T c;\n\
    \            std::cin >> c;\n            if (!directed) g[b].push_back(Edge(b,\
    \ a, c, i));\n            g[a].push_back(Edge(a, b, c, i));\n        } else {\n\
    \            // c = 1\n            if (!directed) g[b].push_back(Edge(b, a, T(1),\
    \ i));\n            g[a].push_back(Edge(a, b, T(1), i));\n        }\n    }\n \
    \   return g;\n}\n\nstd::tuple<Graph<int>, std::vector<std::vector<int>>, std::vector<std::pair<int,\
    \ int>>> read_grid(const int h, const int w, std::string rel = \".#\") {\n   \
    \ std::vector<std::string> s(h);\n    std::vector id(h, std::vector<int>(w, -1));\n\
    \    std::vector<std::pair<int, int>> loc;\n    int n = 0;\n    for (int i = 0;\
    \ i < h; i++) {\n        std::cin >> s[i];\n        for (int j = 0; j < w; j++)\
    \ {\n            if (s[i][j] == rel[1]) {\n                id[i][j] = n++;\n \
    \               loc.emplace_back(i, j);\n            }\n        }\n    }\n   \
    \ int m = 0;\n    Graph<int> g(n);\n    for (int i = 0; i < h; i++) {\n      \
    \  for (int j = 0; j < w; j++) {\n            if (s[i][j] == rel[1]) {\n     \
    \           if (i + 1 < h and s[i + 1][j] == rel[1]) {\n                    g[id[i][j]].push_back(Edge(id[i][j],\
    \ id[i + 1][j], 1, m));\n                    g[id[i + 1][j]].push_back(Edge(id[i\
    \ + 1][j], id[i][j], 1, m++));\n                }\n                if (j + 1 <\
    \ w and s[i][j + 1] == rel[1]) {\n                    g[id[i][j]].push_back(Edge(id[i][j],\
    \ id[i][j + 1], 1, m));\n                    g[id[i][j + 1]].push_back(Edge(id[i][j\
    \ + 1], id[i][j], 1, m++));\n                }\n            }\n        }\n   \
    \ }\n    return {g, id, loc};\n}\n#line 7 \"verify/lc_graph/lc_shortest_path_dijkstra.test.cpp\"\
    \n\nint main() {\n    int N, M, s, t;\n    std::cin >> N >> M >> s >> t;\n   \
    \ auto G = read_graph<long long>(N, M, true, true, 0);\n    std::vector<int> ss\
    \ = {s};\n    const long long INF = 1LL << 60;\n    auto [d, p, r] = dijkstra(G,\
    \ ss, INF);\n    if (d[t] == INF) {\n        std::cout << -1 << '\\n';\n     \
    \   return 0;\n    }\n    std::vector<int> ans;\n    int c = t;\n    while (t\
    \ != -1) {\n        ans.push_back(t);\n        t = p[t];\n    }\n    std::reverse(ans.begin(),\
    \ ans.end());\n    std::cout << d[c] << ' ' << ans.size() - 1 << '\\n';\n    for\
    \ (int i = 0; i < ans.size() - 1; i++) std::cout << ans[i] << ' ' << ans[i + 1]\
    \ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"graph/dijkstra.hpp\"\n#include \"graph/read_graph.hpp\"\
    \n\nint main() {\n    int N, M, s, t;\n    std::cin >> N >> M >> s >> t;\n   \
    \ auto G = read_graph<long long>(N, M, true, true, 0);\n    std::vector<int> ss\
    \ = {s};\n    const long long INF = 1LL << 60;\n    auto [d, p, r] = dijkstra(G,\
    \ ss, INF);\n    if (d[t] == INF) {\n        std::cout << -1 << '\\n';\n     \
    \   return 0;\n    }\n    std::vector<int> ans;\n    int c = t;\n    while (t\
    \ != -1) {\n        ans.push_back(t);\n        t = p[t];\n    }\n    std::reverse(ans.begin(),\
    \ ans.end());\n    std::cout << d[c] << ' ' << ans.size() - 1 << '\\n';\n    for\
    \ (int i = 0; i < ans.size() - 1; i++) std::cout << ans[i] << ' ' << ans[i + 1]\
    \ << '\\n';\n    return 0;\n}"
  dependsOn:
  - graph/dijkstra.hpp
  - graph/graph_template.hpp
  - graph/read_graph.hpp
  isVerificationFile: true
  path: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  requiredBy: []
  timestamp: '2024-01-15 16:50:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
- /verify/verify/lc_graph/lc_shortest_path_dijkstra.test.cpp.html
title: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
---
