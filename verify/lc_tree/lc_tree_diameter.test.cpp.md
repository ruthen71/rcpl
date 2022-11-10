---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/template.hpp
    title: src/graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/tree_diameter.hpp
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
    \n#line 2 \"src/graph/tree_diameter.hpp\"\n\n#line 2 \"src/graph/template.hpp\"\
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
    \ }\n\n    void read_parent(int offset = 1) {\n        es.reserve(N - 1);\n  \
    \      for (int i = 1; i < N; i++) {\n            int p;\n            std::cin\
    \ >> p;\n            p -= offset;\n            add_edge(i, p);\n        }\n  \
    \  }\n\n    void add_edge(const int &a, const int &b, T cost = 1) {\n        assert(0\
    \ <= a and a < N and 0 <= b and b < N);\n        if (!directed) G[b].push_back(edge_type(b,\
    \ a, cost, M));\n        G[a].push_back(edge_type(a, b, cost, M));\n        es.push_back(edge_type(a,\
    \ b, cost, M++));\n    }\n\n    inline std::vector<edge_type> &operator[](const\
    \ int &k) { return G[k]; }\n\n    inline const std::vector<edge_type> &operator[](const\
    \ int &k) const { return G[k]; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const graph<T, directed> &G) {\n        os << \"V: \" << G.N << \"\\nE:\
    \ \" << G.M << '\\n';\n        for (int v = 0; v < G.N; v++) {\n            os\
    \ << \"G[\" << v << \"] = [\";\n            for (auto &e : G[v]) os << e << \"\
    \ \";\n            os << \"]\\n\";\n        }\n        return os;\n    }\n};\n\
    #line 4 \"src/graph/tree_diameter.hpp\"\n\ntemplate <class Graph>\nstd::pair<typename\
    \ Graph::cost_type, std::vector<typename Graph::edge_type>>  //\ntree_diameter(Graph\
    \ &G) {\n    using T = typename Graph::cost_type;\n    std::vector<int> to(G.size(),\
    \ -1);\n\n    auto dfs = [&](auto f, int cur, int par) -> std::pair<T, int> {\n\
    \        std::pair<T, int> ret = {0, cur};\n        for (auto &e : G[cur]) {\n\
    \            if (e.to == par) continue;\n            auto cost = f(f, e.to, cur);\n\
    \            cost.first += e.cost;\n            if (ret.first < cost.first) {\n\
    \                ret = cost;\n                to[cur] = e.to;\n            }\n\
    \        }\n        return ret;\n    };\n\n    auto s = dfs(dfs, 0, -1);\n   \
    \ auto t = dfs(dfs, s.second, -1);\n\n    int cur = s.second;\n    std::vector<typename\
    \ Graph::edge_type> path;\n    while (cur != t.second) {\n        for (auto &e\
    \ : G[cur]) {\n            if (to[cur] == e.to) {\n                path.emplace_back(e);\n\
    \            }\n        }\n        cur = to[cur];\n    }\n    return {t.first,\
    \ path};\n}\n\n/**\n * @brief Tree Diameter (\u6728\u306E\u76F4\u5F84)\n * @docs\
    \ docs/graph/tree_diameter.md\n */\n#line 6 \"verify/lc_tree/lc_tree_diameter.test.cpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    graph<long long> G(N);\n\
    \    G.read_tree(true, 0);\n    auto [d, path] = tree_diameter(G);\n    std::cout\
    \ << d << ' ' << path.size() + 1 << '\\n';\n    std::cout << path.front().from;\n\
    \    for (auto &e : path) {\n        std::cout << ' ' << e.to;\n    }\n    std::cout\
    \ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"src/graph/tree_diameter.hpp\"\n\nint main() {\n\
    \    int N;\n    std::cin >> N;\n    graph<long long> G(N);\n    G.read_tree(true,\
    \ 0);\n    auto [d, path] = tree_diameter(G);\n    std::cout << d << ' ' << path.size()\
    \ + 1 << '\\n';\n    std::cout << path.front().from;\n    for (auto &e : path)\
    \ {\n        std::cout << ' ' << e.to;\n    }\n    std::cout << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - src/graph/tree_diameter.hpp
  - src/graph/template.hpp
  isVerificationFile: true
  path: verify/lc_tree/lc_tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2022-09-30 19:25:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_tree/lc_tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_tree/lc_tree_diameter.test.cpp
- /verify/verify/lc_tree/lc_tree_diameter.test.cpp.html
title: verify/lc_tree/lc_tree_diameter.test.cpp
---