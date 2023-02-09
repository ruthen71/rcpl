---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/unionfind.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: graph/get_edges.hpp
    title: graph/get_edges.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal's algorithm (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"verify/aoj_grl/aoj_grl_2_a.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"graph/kruskal.hpp\"\n\n#line 2 \"data_structure/unionfind.hpp\"\
    \n\nstruct UnionFind {\n    std::vector<int> parents;\n\n    UnionFind() {}\n\
    \    UnionFind(int n) : parents(n, -1) {}\n\n    int leader(int x) { return parents[x]\
    \ < 0 ? x : parents[x] = leader(parents[x]); }\n\n    bool merge(int x, int y)\
    \ {\n        x = leader(x), y = leader(y);\n        if (x == y) return false;\n\
    \        if (parents[x] > parents[y]) std::swap(x, y);\n        parents[x] +=\
    \ parents[y];\n        parents[y] = x;\n        return true;\n    }\n\n    bool\
    \ same(int x, int y) { return leader(x) == leader(y); }\n\n    int size(int x)\
    \ { return -parents[leader(x)]; }\n\n    void init(int n) { parents.assign(n,\
    \ -1); }  // reset\n};\n#line 2 \"graph/get_edges.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Edge<T> &e) {\n        // output format:\
    \ \"{ id : from -> to, cost }\"\n        return os << \"{ \" << e.id << \" : \"\
    \ << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\n\
    template <class T> using Edges = std::vector<Edge<T>>;\ntemplate <class T> using\
    \ Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"graph/get_edges.hpp\"\n\
    \ntemplate <class T> Edges<T> get_edges(Graph<T> &G) {\n    int N = (int)G.size(),\
    \ M = 0;\n    for (int i = 0; i < N; i++) {\n        for (auto &&e : G[i]) {\n\
    \            M = std::max(M, e.id + 1);\n        }\n    }\n    Edges<T> es(M);\n\
    \    for (int i = N - 1; i >= 0; i--) {\n        for (auto &&e : G[i]) {\n   \
    \         es[e.id] = e;\n        }\n    }\n    return es;\n}\n#line 6 \"graph/kruskal.hpp\"\
    \n\ntemplate <class T> std::pair<T, Edges<T>> kruskal(Graph<T> &G) {\n    auto\
    \ es = get_edges<T>(G);\n    std::sort(es.begin(), es.end(), [](Edge<T> a, Edge<T>\
    \ b) { return a.cost < b.cost; });\n    int N = (int)G.size();\n    UnionFind\
    \ uf(N);\n    T ret = 0;\n    Edges<T> es_ret;\n    es_ret.reserve(N - 1);\n \
    \   for (auto &&e : es) {\n        if (!uf.same(e.from, e.to)) {\n           \
    \ ret += e.cost;\n            uf.merge(e.from, e.to);\n            es_ret.push_back(e);\n\
    \        }\n    }\n    return {ret, es_ret};\n}\n#line 2 \"graph/read_graph.hpp\"\
    \n\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate <class T> Graph<T> read_graph(int\
    \ N, int M, const bool weight = false, const bool directed = false, const int\
    \ offset = 1) {\n    Graph<T> G(N);\n    for (int i = 0; i < M; i++) {\n     \
    \   int a, b;\n        std::cin >> a >> b;\n        a -= offset, b -= offset;\n\
    \        if (weight) {\n            T c;\n            std::cin >> c;\n       \
    \     if (!directed) G[b].push_back(Edge(b, a, c, i));\n            G[a].push_back(Edge(a,\
    \ b, c, i));\n        } else {\n            // c = 1\n            if (!directed)\
    \ G[b].push_back(Edge(b, a, T(1), i));\n            G[a].push_back(Edge(a, b,\
    \ T(1), i));\n        }\n    }\n    return G;\n}\n#line 7 \"verify/aoj_grl/aoj_grl_2_a.test.cpp\"\
    \n\nint main() {\n    int N, M;\n    std::cin >> N >> M;\n    auto G = read_graph<long\
    \ long>(N, M, true, false, 0);\n    auto [cost, es_set] = kruskal<long long>(G);\n\
    \    std::cout << cost << '\\n';\n    return 0;\n}\n"
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
  timestamp: '2023-02-10 01:10:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_grl/aoj_grl_2_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_grl/aoj_grl_2_a.test.cpp
- /verify/verify/aoj_grl/aoj_grl_2_a.test.cpp.html
title: verify/aoj_grl/aoj_grl_2_a.test.cpp
---
