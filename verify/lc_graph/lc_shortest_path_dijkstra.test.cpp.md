---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: "Dijkstra's algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/lc_graph/lc_shortest_path_dijkstra.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include <bits/stdc++.h>\n\
    \n#line 2 \"src/graph/dijkstra.hpp\"\n\n#line 2 \"src/graph/template.hpp\"\n\n\
    template <class T> struct edge {\n    int from, to;\n    T cost;\n    int id;\n\
    \n    edge(int from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost),\
    \ id(id) {}\n\n    friend std::ostream &operator<<(std::ostream &os, const edge<T>\
    \ &e) {\n        // { id : from -> to, cost }\n        return os << \"{ \" <<\
    \ e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\"\
    ;\n    }\n};\n\ntemplate <class T, bool directed = false> struct graph {\n   \
    \ int N, M;\n    using cost_type = T;\n    using edge_type = edge<T>;\n    std::vector<std::vector<edge_type>>\
    \ G;\n\n    graph() : N(0), M(0) {}\n    graph(int N) : N(N), M(0), G(N) {}\n\n\
    \    constexpr bool is_directed() { return directed; }\n\n    size_t size() const\
    \ { return G.size(); }\n\n    void read_tree(bool weight = false, int offset =\
    \ 1) { read_graph(N - 1, weight, offset); }\n\n    void read_graph(int _M, bool\
    \ weight = false, int offset = 1) {\n        for (int i = 0; i < _M; i++) {\n\
    \            int a, b;\n            std::cin >> a >> b;\n            a -= offset,\
    \ b -= offset;\n            if (weight) {\n                T c;\n            \
    \    std::cin >> c;\n                add_edge(a, b, c);\n            } else {\n\
    \                add_edge(a, b);\n            }\n        }\n    }\n\n    void\
    \ read_parent(int offset = 1) {\n        for (int i = 1; i < N; i++) {\n     \
    \       int p;\n            std::cin >> p;\n            p -= offset;\n       \
    \     add_edge(i, p);\n        }\n    }\n\n    void add_edge(const int &a, const\
    \ int &b, T cost = 1) {\n        assert(0 <= a and a < N and 0 <= b and b < N);\n\
    \        if (!directed) G[b].push_back(edge_type(b, a, cost, M));\n        G[a].push_back(edge_type(a,\
    \ b, cost, M++));\n    }\n\n    inline std::vector<edge_type> &operator[](const\
    \ int &k) { return G[k]; }\n\n    inline const std::vector<edge_type> &operator[](const\
    \ int &k) const { return G[k]; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const graph<T, directed> &G) {\n        os << \"V: \" << G.N << \"\\nE:\
    \ \" << G.M << '\\n';\n        for (int v = 0; v < G.N; v++) {\n            os\
    \ << \"G[\" << v << \"] = [\";\n            for (auto &e : G[v]) os << e << \"\
    \ \";\n            os << \"]\\n\";\n        }\n        return os;\n    }\n};\n\
    #line 4 \"src/graph/dijkstra.hpp\"\n\ntemplate <class Graph>\nstd::tuple<std::vector<typename\
    \ Graph::cost_type>, std::vector<int>, std::vector<int>>  //\ndijkstra(Graph &G,\
    \ std::vector<int> &s, const typename Graph::cost_type INF = std::numeric_limits<typename\
    \ Graph::cost_type>::max() / 4) {\n    using T = typename Graph::cost_type;\n\n\
    \    int N = (int)G.size();\n    std::vector<T> dist(N, INF);\n    std::vector<int>\
    \ par(N, -1), root(N, -1);\n\n    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T,\
    \ int>>, std::greater<std::pair<T, int>>> que;\n\n    for (auto &v : s) {\n  \
    \      dist[v] = 0;\n        root[v] = v;\n        que.emplace(T(0), v);\n   \
    \ }\n\n    while (!que.empty()) {\n        auto [d, v] = que.top();\n        que.pop();\n\
    \        if (dist[v] != d) continue;  // dist[v] < d\n        for (auto &e : G[v])\
    \ {\n            if (dist[e.to] > d + e.cost) {\n                dist[e.to] =\
    \ d + e.cost;\n                root[e.to] = root[v];\n                par[e.to]\
    \ = v;\n                que.emplace(dist[e.to], e.to);\n            }\n      \
    \  }\n    }\n    return {dist, par, root};\n}\n\n/**\n * @brief Dijkstra's algorithm\
    \ (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n * @docs docs/graph/dijkstra.md\n\
    \ */\n#line 6 \"verify/lc_graph/lc_shortest_path_dijkstra.test.cpp\"\n\nint main()\
    \ {\n    int N, M, s, t;\n    std::cin >> N >> M >> s >> t;\n    graph<long long,\
    \ true> G(N);\n    G.read_graph(M, true, 0);\n    std::vector<int> ss = {s};\n\
    \    const long long INF = 1LL << 60;\n    auto [d, p, r] = dijkstra(G, ss, INF);\n\
    \    if (d[t] == INF) {\n        std::cout << -1 << '\\n';\n        return 0;\n\
    \    }\n    std::vector<int> ans;\n    int c = t;\n    while (t != -1) {\n   \
    \     ans.push_back(t);\n        t = p[t];\n    }\n    std::reverse(ans.begin(),\
    \ ans.end());\n    std::cout << d[c] << ' ' << ans.size() - 1 << '\\n';\n    for\
    \ (int i = 0; i < ans.size() - 1; i++) std::cout << ans[i] << ' ' << ans[i + 1]\
    \ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"src/graph/dijkstra.hpp\"\n\nint main() {\n   \
    \ int N, M, s, t;\n    std::cin >> N >> M >> s >> t;\n    graph<long long, true>\
    \ G(N);\n    G.read_graph(M, true, 0);\n    std::vector<int> ss = {s};\n    const\
    \ long long INF = 1LL << 60;\n    auto [d, p, r] = dijkstra(G, ss, INF);\n   \
    \ if (d[t] == INF) {\n        std::cout << -1 << '\\n';\n        return 0;\n \
    \   }\n    std::vector<int> ans;\n    int c = t;\n    while (t != -1) {\n    \
    \    ans.push_back(t);\n        t = p[t];\n    }\n    std::reverse(ans.begin(),\
    \ ans.end());\n    std::cout << d[c] << ' ' << ans.size() - 1 << '\\n';\n    for\
    \ (int i = 0; i < ans.size() - 1; i++) std::cout << ans[i] << ' ' << ans[i + 1]\
    \ << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/graph/dijkstra.hpp
  - src/graph/template.hpp
  isVerificationFile: true
  path: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
  requiredBy: []
  timestamp: '2022-09-09 18:41:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
- /verify/verify/lc_graph/lc_shortest_path_dijkstra.test.cpp.html
title: verify/lc_graph/lc_shortest_path_dijkstra.test.cpp
---
