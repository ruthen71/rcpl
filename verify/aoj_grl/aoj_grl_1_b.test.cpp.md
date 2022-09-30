---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/bellman_ford.hpp
    title: "Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\
      \u6CD5)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"verify/aoj_grl/aoj_grl_1_b.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"src/graph/bellman_ford.hpp\"\n\n#line 2 \"src/graph/template.hpp\"\
    \n\ntemplate <class T> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to),\
    \ cost(cost), id(id) {}\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const edge<T> &e) {\n        // { id : from -> to, cost }\n        return os\
    \ << \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T, bool directed = false> struct graph\
    \ {\n    int N, M;\n    using cost_type = T;\n    using edge_type = edge<T>;\n\
    \    std::vector<std::vector<edge_type>> G;\n    std::vector<edge_type> es;\n\n\
    \    graph() : N(0), M(0) {}\n    graph(int N) : N(N), M(0), G(N) {}\n\n    constexpr\
    \ bool is_directed() { return directed; }\n\n    size_t size() const { return\
    \ G.size(); }\n\n    void read_tree(bool weight = false, int offset = 1) { read_graph(N\
    \ - 1, weight, offset); }\n\n    void read_graph(int _M, bool weight = false,\
    \ int offset = 1) {\n        es.reserve(_M);\n        for (int i = 0; i < _M;\
    \ i++) {\n            int a, b;\n            std::cin >> a >> b;\n           \
    \ a -= offset, b -= offset;\n            if (weight) {\n                T c;\n\
    \                std::cin >> c;\n                add_edge(a, b, c);\n        \
    \    } else {\n                add_edge(a, b);\n            }\n        }\n   \
    \ }\n\n    void read_parent(int offset = 1) {\n        for (int i = 1; i < N;\
    \ i++) {\n            int p;\n            std::cin >> p;\n            p -= offset;\n\
    \            add_edge(i, p);\n        }\n    }\n\n    void add_edge(const int\
    \ &a, const int &b, T cost = 1) {\n        assert(0 <= a and a < N and 0 <= b\
    \ and b < N);\n        if (!directed) G[b].push_back(edge_type(b, a, cost, M));\n\
    \        G[a].push_back(edge_type(a, b, cost, M));\n        es.push_back(edge_type(a,\
    \ b, cost, M++));\n    }\n\n    inline std::vector<edge_type> &operator[](const\
    \ int &k) { return G[k]; }\n\n    inline const std::vector<edge_type> &operator[](const\
    \ int &k) const { return G[k]; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const graph<T, directed> &G) {\n        os << \"V: \" << G.N << \"\\nE:\
    \ \" << G.M << '\\n';\n        for (int v = 0; v < G.N; v++) {\n            os\
    \ << \"G[\" << v << \"] = [\";\n            for (auto &e : G[v]) os << e << \"\
    \ \";\n            os << \"]\\n\";\n        }\n        return os;\n    }\n};\n\
    #line 4 \"src/graph/bellman_ford.hpp\"\n\ntemplate <class Graph>\nstd::tuple<std::vector<typename\
    \ Graph::cost_type>, std::vector<int>, std::vector<int>>  //\nbellman_ford(Graph\
    \ &G, std::vector<int> &s, const typename Graph::cost_type INF = std::numeric_limits<typename\
    \ Graph::cost_type>::max() / 4) {\n    using T = typename Graph::cost_type;\n\n\
    \    int N = (int)G.size();\n    std::vector<T> dist(N, INF);\n    std::vector<int>\
    \ par(N, -1), root(N, -1);\n\n    for (auto &v : s) {\n        dist[v] = 0;\n\
    \        root[v] = v;\n    }\n    int loop_count = 0;\n\n    while (true) {\n\
    \        loop_count++;\n        bool update = false;\n        for (int cur = 0;\
    \ cur < N; cur++) {\n            if (dist[cur] == INF) continue;\n           \
    \ for (auto &e : G[cur]) {\n                T nd = std::max(-INF, dist[cur] +\
    \ e.cost);\n                if (dist[e.to] > nd) {\n                    par[e.to]\
    \ = cur;\n                    root[e.to] = root[cur];\n                    update\
    \ = true;\n                    if (loop_count >= N) nd = -INF;\n             \
    \       dist[e.to] = nd;\n                }\n            }\n        }\n      \
    \  if (!update) break;\n    }\n    return {dist, par, root};\n}\n\n/**\n * @brief\
    \ Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\
    )\n * @docs docs/graph/bellman_ford.md\n */\n#line 6 \"verify/aoj_grl/aoj_grl_1_b.test.cpp\"\
    \n\nint main() {\n    int N, M, r;\n    std::cin >> N >> M >> r;\n    graph<int,\
    \ true> G(N);\n    G.read_graph(M, true, 0);\n    std::vector<int> s = {r};\n\
    \    const int INF = 1 << 30;\n    auto [dist, par, root] = bellman_ford(G, s,\
    \ INF);\n    int ans = *std::min_element(dist.begin(), dist.end());\n    if (ans\
    \ == -INF) {\n        std::cout << \"NEGATIVE CYCLE\" << '\\n';\n    } else {\n\
    \        for (int i = 0; i < N; i++) {\n            if (dist[i] == INF) {\n  \
    \              std::cout << \"INF\" << '\\n';\n            } else {\n        \
    \        std::cout << dist[i] << '\\n';\n            }\n        }\n    }\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"src/graph/bellman_ford.hpp\"\n\nint\
    \ main() {\n    int N, M, r;\n    std::cin >> N >> M >> r;\n    graph<int, true>\
    \ G(N);\n    G.read_graph(M, true, 0);\n    std::vector<int> s = {r};\n    const\
    \ int INF = 1 << 30;\n    auto [dist, par, root] = bellman_ford(G, s, INF);\n\
    \    int ans = *std::min_element(dist.begin(), dist.end());\n    if (ans == -INF)\
    \ {\n        std::cout << \"NEGATIVE CYCLE\" << '\\n';\n    } else {\n       \
    \ for (int i = 0; i < N; i++) {\n            if (dist[i] == INF) {\n         \
    \       std::cout << \"INF\" << '\\n';\n            } else {\n               \
    \ std::cout << dist[i] << '\\n';\n            }\n        }\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - src/graph/bellman_ford.hpp
  - src/graph/template.hpp
  isVerificationFile: true
  path: verify/aoj_grl/aoj_grl_1_b.test.cpp
  requiredBy: []
  timestamp: '2022-09-30 19:15:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_grl/aoj_grl_1_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_grl/aoj_grl_1_b.test.cpp
- /verify/verify/aoj_grl/aoj_grl_1_b.test.cpp.html
title: verify/aoj_grl/aoj_grl_1_b.test.cpp
---
