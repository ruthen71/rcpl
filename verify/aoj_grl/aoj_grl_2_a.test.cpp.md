---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/unionfind.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: graph/get_edges.hpp
    title: graph/get_edges.hpp
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal's algorithm (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"verify/aoj_grl/aoj_grl_2_a.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"graph/kruskal.hpp\"\n\n#line 2 \"data_structure/unionfind.hpp\"\
    \n\nstruct UnionFind {\n    int n;\n    std::vector<int> parents;\n\n    UnionFind()\
    \ {}\n    UnionFind(int n) : n(n), parents(n, -1) {}\n\n    int leader(int x)\
    \ { return parents[x] < 0 ? x : parents[x] = leader(parents[x]); }\n\n    bool\
    \ merge(int x, int y) {\n        x = leader(x), y = leader(y);\n        if (x\
    \ == y) return false;\n        if (parents[x] > parents[y]) std::swap(x, y);\n\
    \        parents[x] += parents[y];\n        parents[y] = x;\n        return true;\n\
    \    }\n\n    bool same(int x, int y) { return leader(x) == leader(y); }\n\n \
    \   int size(int x) { return -parents[leader(x)]; }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(n), group_size(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n    \
    \        group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(result.begin(), result.end(),\
    \ [&](const std::vector<int>& v) { return v.empty(); }), result.end());\n    \
    \    return result;\n    }\n\n    void init(int n) { parents.assign(n, -1); }\
    \  // reset\n};\n#line 2 \"graph/get_edges.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#line 4 \"graph/graph_template.hpp\"\ntemplate <class T> struct Edge {\n \
    \   int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int\
    \ from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id)\
    \ {}\n\n    friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e)\
    \ {\n        // output format: \"{ id : from -> to, cost }\"\n        return os\
    \ << \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"\
    graph/get_edges.hpp\"\n\ntemplate <class T> Edges<T> get_edges(Graph<T> &G) {\n\
    \    int N = (int)G.size(), M = 0;\n    for (int i = 0; i < N; i++) {\n      \
    \  for (auto &&e : G[i]) {\n            M = std::max(M, e.id + 1);\n        }\n\
    \    }\n    Edges<T> es(M);\n    for (int i = N - 1; i >= 0; i--) {\n        for\
    \ (auto &&e : G[i]) {\n            es[e.id] = e;\n        }\n    }\n    return\
    \ es;\n}\n#line 6 \"graph/kruskal.hpp\"\n\ntemplate <class T> std::pair<T, Edges<T>>\
    \ kruskal(Graph<T> &G) {\n    auto es = get_edges<T>(G);\n    std::sort(es.begin(),\
    \ es.end(), [](Edge<T> a, Edge<T> b) { return a.cost < b.cost; });\n    int N\
    \ = (int)G.size();\n    UnionFind uf(N);\n    T ret = 0;\n    Edges<T> es_ret;\n\
    \    es_ret.reserve(N - 1);\n    for (auto &&e : es) {\n        if (!uf.same(e.from,\
    \ e.to)) {\n            ret += e.cost;\n            uf.merge(e.from, e.to);\n\
    \            es_ret.push_back(e);\n        }\n    }\n    return {ret, es_ret};\n\
    }\n#line 2 \"graph/read_graph.hpp\"\n\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate\
    \ <class T> Graph<T> read_graph(const int n, const int m, const bool weight =\
    \ false, const bool directed = false, const int offset = 1) {\n    Graph<T> g(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        a -= offset, b -= offset;\n        if (weight) {\n            T\
    \ c;\n            std::cin >> c;\n            if (!directed) g[b].push_back(Edge(b,\
    \ a, c, i));\n            g[a].push_back(Edge(a, b, c, i));\n        } else {\n\
    \            // c = 1\n            if (!directed) g[b].push_back(Edge(b, a, T(1),\
    \ i));\n            g[a].push_back(Edge(a, b, T(1), i));\n        }\n    }\n \
    \   return g;\n}\n\ntemplate <class T> Graph<T> read_parent(const int n, const\
    \ bool weight = false, const bool directed = false, const int offset = 1) {\n\
    \    Graph<T> g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n     \
    \   std::cin >> p;\n        p -= offset;\n        if (weight) {\n            T\
    \ c;\n            std::cin >> c;\n            if (!directed) g[i].push_back(Edge(i,\
    \ p, c, i - 1));\n            g[p].push_back(Edge(p, i, c, i - 1));\n        }\
    \ else {\n            // c = 1\n            if (!directed) g[i].push_back(Edge(i,\
    \ p, T(1), i - 1));\n            g[p].push_back(Edge(p, i, T(1), i - 1));\n  \
    \      }\n    }\n    return g;\n}\n\nstd::tuple<Graph<int>, std::vector<std::vector<int>>,\
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
    \ loc};\n}\n#line 7 \"verify/aoj_grl/aoj_grl_2_a.test.cpp\"\n\nint main() {\n\
    \    int N, M;\n    std::cin >> N >> M;\n    auto G = read_graph<long long>(N,\
    \ M, true, false, 0);\n    auto [cost, es_set] = kruskal<long long>(G);\n    std::cout\
    \ << cost << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"graph/kruskal.hpp\"\n#include \"graph/read_graph.hpp\"\
    \n\nint main() {\n    int N, M;\n    std::cin >> N >> M;\n    auto G = read_graph<long\
    \ long>(N, M, true, false, 0);\n    auto [cost, es_set] = kruskal<long long>(G);\n\
    \    std::cout << cost << '\\n';\n    return 0;\n}"
  dependsOn:
  - graph/kruskal.hpp
  - data_structure/unionfind.hpp
  - graph/get_edges.hpp
  - graph/graph_template.hpp
  - graph/read_graph.hpp
  isVerificationFile: true
  path: verify/aoj_grl/aoj_grl_2_a.test.cpp
  requiredBy: []
  timestamp: '2024-01-25 10:46:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_grl/aoj_grl_2_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_grl/aoj_grl_2_a.test.cpp
- /verify/verify/aoj_grl/aoj_grl_2_a.test.cpp.html
title: verify/aoj_grl/aoj_grl_2_a.test.cpp
---
