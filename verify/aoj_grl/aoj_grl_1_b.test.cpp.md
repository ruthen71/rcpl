---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/bellman_ford.hpp
    title: "Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\
      \u6CD5)"
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: src/graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/read_graph.hpp
    title: src/graph/read_graph.hpp
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
    \ <bits/stdc++.h>\n\n#line 2 \"src/graph/bellman_ford.hpp\"\n\n#line 2 \"src/graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge() = default;\n    edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const edge<T> &e) {\n        // { id : from ->\
    \ to, cost }\n        return os << \"{ \" << e.id << \" : \" << e.from << \" ->\
    \ \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using\
    \ edges = std::vector<edge<T>>;\ntemplate <class T> using graph = std::vector<std::vector<edge<T>>>;\n\
    #line 4 \"src/graph/bellman_ford.hpp\"\n\ntemplate <class T, class Graph>\nstd::tuple<std::vector<T>,\
    \ std::vector<int>, std::vector<int>>  //\nbellman_ford(Graph &G, std::vector<int>\
    \ &s, const T INF) {\n    int N = (int)G.size();\n    std::vector<T> dist(N, INF);\n\
    \    std::vector<int> par(N, -1), root(N, -1);\n\n    for (auto &v : s) {\n  \
    \      dist[v] = 0;\n        root[v] = v;\n    }\n    int loop_count = 0;\n\n\
    \    while (true) {\n        loop_count++;\n        bool update = false;\n   \
    \     for (int cur = 0; cur < N; cur++) {\n            if (dist[cur] == INF) continue;\n\
    \            for (auto &e : G[cur]) {\n                T nd = std::max(-INF, dist[cur]\
    \ + e.cost);\n                if (dist[e.to] > nd) {\n                    par[e.to]\
    \ = cur;\n                    root[e.to] = root[cur];\n                    update\
    \ = true;\n                    if (loop_count >= N) nd = -INF;\n             \
    \       dist[e.to] = nd;\n                }\n            }\n        }\n      \
    \  if (!update) break;\n    }\n    return {dist, par, root};\n}\n\n/**\n * @brief\
    \ Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\
    )\n * @docs docs/graph/bellman_ford.md\n */\n#line 2 \"src/graph/read_graph.hpp\"\
    \n\n#line 4 \"src/graph/read_graph.hpp\"\n\ntemplate <class T> graph<T> read_graph(int\
    \ N, int M, const bool weight = false, const bool directed = false, const int\
    \ offset = 1) {\n    graph<T> G(N);\n    for (int i = 0; i < M; i++) {\n     \
    \   int a, b;\n        std::cin >> a >> b;\n        a -= offset, b -= offset;\n\
    \        if (weight) {\n            T c;\n            std::cin >> c;\n       \
    \     if (!directed) G[b].push_back(edge(b, a, c, i));\n            G[a].push_back(edge(a,\
    \ b, c, i));\n        } else {\n            // c = 1\n            if (!directed)\
    \ G[b].push_back(edge(b, a, T(1), i));\n            G[a].push_back(edge(a, b,\
    \ T(1), i));\n        }\n    }\n    return G;\n}\n#line 7 \"verify/aoj_grl/aoj_grl_1_b.test.cpp\"\
    \n\nint main() {\n    int N, M, r;\n    std::cin >> N >> M >> r;\n    graph<int>\
    \ G = read_graph<int>(N, M, true, true, 0);\n    std::vector<int> s = {r};\n \
    \   const int INF = 1 << 30;\n    auto [dist, par, root] = bellman_ford(G, s,\
    \ INF);\n    int ans = *std::min_element(dist.begin(), dist.end());\n    if (ans\
    \ == -INF) {\n        std::cout << \"NEGATIVE CYCLE\" << '\\n';\n    } else {\n\
    \        for (int i = 0; i < N; i++) {\n            if (dist[i] == INF) {\n  \
    \              std::cout << \"INF\" << '\\n';\n            } else {\n        \
    \        std::cout << dist[i] << '\\n';\n            }\n        }\n    }\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"src/graph/bellman_ford.hpp\"\n#include\
    \ \"src/graph/read_graph.hpp\"\n\nint main() {\n    int N, M, r;\n    std::cin\
    \ >> N >> M >> r;\n    graph<int> G = read_graph<int>(N, M, true, true, 0);\n\
    \    std::vector<int> s = {r};\n    const int INF = 1 << 30;\n    auto [dist,\
    \ par, root] = bellman_ford(G, s, INF);\n    int ans = *std::min_element(dist.begin(),\
    \ dist.end());\n    if (ans == -INF) {\n        std::cout << \"NEGATIVE CYCLE\"\
    \ << '\\n';\n    } else {\n        for (int i = 0; i < N; i++) {\n           \
    \ if (dist[i] == INF) {\n                std::cout << \"INF\" << '\\n';\n    \
    \        } else {\n                std::cout << dist[i] << '\\n';\n          \
    \  }\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - src/graph/bellman_ford.hpp
  - src/graph/graph_template.hpp
  - src/graph/read_graph.hpp
  isVerificationFile: true
  path: verify/aoj_grl/aoj_grl_1_b.test.cpp
  requiredBy: []
  timestamp: '2022-11-16 19:50:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_grl/aoj_grl_1_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_grl/aoj_grl_1_b.test.cpp
- /verify/verify/aoj_grl/aoj_grl_1_b.test.cpp.html
title: verify/aoj_grl/aoj_grl_1_b.test.cpp
---