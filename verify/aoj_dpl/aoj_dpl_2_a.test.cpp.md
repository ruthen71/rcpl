---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/traveling_salesman_problem.hpp
    title: "Traveling Salesman Problem (\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
      \u30F3\u554F\u984C)"
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':question:'
    path: graph/read_graph.hpp
    title: graph/read_graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
  bundledCode: "#line 1 \"verify/aoj_dpl/aoj_dpl_2_a.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"dp/traveling_salesman_problem.hpp\"\n\n#line 2\
    \ \"graph/graph_template.hpp\"\n\ntemplate <class T> struct Edge {\n    int from,\
    \ to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int\
    \ to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n\
    \    friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n \
    \       // output format: \"{ id : from -> to, cost }\"\n        return os <<\
    \ \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    dp/traveling_salesman_problem.hpp\"\n\ntemplate <class T>\nstd::vector<std::vector<T>>\
    \  //\ntraveling_salesman_problem(Graph<T> &G, const T INF) {\n    int N = (int)G.size();\n\
    \    int N2 = 1 << N;\n\n    std::vector<std::vector<T>> dist(N, std::vector<T>(N,\
    \ INF));\n    for (int i = 0; i < N; i++) dist[i][i] = T(0);\n    for (int i =\
    \ 0; i < N; i++) {\n        for (auto &&e : G[i]) {\n            dist[e.from][e.to]\
    \ = std::min(dist[e.from][e.to], e.cost);\n        }\n    }\n\n    std::vector<std::vector<T>>\
    \ dp(N2, std::vector<T>(N, INF));\n    dp[0][0] = 0;\n    for (int s = 0; s <\
    \ (1 << N); s++) {\n        for (int v = 0; v < N; v++) {\n            if (s >>\
    \ v & 1) continue;\n            for (int u = 0; u < N; u++) {\n              \
    \  if (u == v) continue;\n                dp[s | (1 << v)][v] = std::min(dp[s\
    \ | (1 << v)][v], dp[s][u] + dist[u][v]);\n            }\n        }\n    }\n \
    \   return dp;\n}\n#line 2 \"graph/read_graph.hpp\"\n\n#line 4 \"graph/read_graph.hpp\"\
    \n\ntemplate <class T> Graph<T> read_graph(int n, int m, const bool weight = false,\
    \ const bool directed = false, const int offset = 1) {\n    Graph<T> g(n);\n \
    \   for (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        a -= offset, b -= offset;\n        if (weight) {\n            T\
    \ c;\n            std::cin >> c;\n            if (!directed) g[b].push_back(Edge(b,\
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
    \ }\n    return {g, id, loc};\n}\n#line 7 \"verify/aoj_dpl/aoj_dpl_2_a.test.cpp\"\
    \n\nint main() {\n    int N, M;\n    std::cin >> N >> M;\n    auto G = read_graph<long\
    \ long>(N, M, true, true, 0);\n    const long long INF = 1LL << 60;\n    auto\
    \ res = traveling_salesman_problem<long long>(G, INF);\n    long long ans = res.back()[0];\n\
    \    if (ans == INF) ans = -1;\n    std::cout << ans << '\\n';\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"dp/traveling_salesman_problem.hpp\"\
    \n#include \"graph/read_graph.hpp\"\n\nint main() {\n    int N, M;\n    std::cin\
    \ >> N >> M;\n    auto G = read_graph<long long>(N, M, true, true, 0);\n    const\
    \ long long INF = 1LL << 60;\n    auto res = traveling_salesman_problem<long long>(G,\
    \ INF);\n    long long ans = res.back()[0];\n    if (ans == INF) ans = -1;\n \
    \   std::cout << ans << '\\n';\n    return 0;\n}"
  dependsOn:
  - dp/traveling_salesman_problem.hpp
  - graph/graph_template.hpp
  - graph/read_graph.hpp
  isVerificationFile: true
  path: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
  requiredBy: []
  timestamp: '2024-01-15 16:50:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dpl/aoj_dpl_2_a.test.cpp
- /verify/verify/aoj_dpl/aoj_dpl_2_a.test.cpp.html
title: verify/aoj_dpl/aoj_dpl_2_a.test.cpp
---
