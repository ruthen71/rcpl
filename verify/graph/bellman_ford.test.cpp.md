---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: "Bellman-Ford algorithm (\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\
      \u6CD5)"
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
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
  bundledCode: "#line 1 \"verify/graph/bellman_ford.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\n\n#include\
    \ <iostream>\n#include <algorithm>\n\n#line 2 \"graph/bellman_ford.hpp\"\n\n#line\
    \ 2 \"graph/graph_template.hpp\"\n\n#include <cassert>\n#include <vector>\n\n\
    template <class T> struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\
    \n    Edge() = default;\n    Edge(const int from, const int to, const T cost =\
    \ T(1), const int id = -1)\n        : from(from), to(to), cost(cost), id(id) {}\n\
    \n    friend bool operator<(const Edge<T>& a, const Edge<T>& b) {\n        return\
    \ a.cost < b.cost;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Edge<T>& e) {\n        // output format: {id: cost(from, to) = cost}\n\
    \        return os << \"{\" << e.id << \": cost(\" << e.from << \", \" << e.to\n\
    \                  << \") = \" << e.cost << \"}\";\n    }\n};\ntemplate <class\
    \ T> using Edges = std::vector<Edge<T>>;\n\ntemplate <class T> struct Graph {\n\
    \    struct EdgeIterators {\n      public:\n        using Iterator = typename\
    \ std::vector<Edge<T>>::iterator;\n        EdgeIterators() = default;\n      \
    \  EdgeIterators(const Iterator& begit, const Iterator& endit)\n            :\
    \ begit(begit), endit(endit) {}\n        Iterator begin() const { return begit;\
    \ }\n        Iterator end() const { return endit; }\n        size_t size() const\
    \ { return std::distance(begit, endit); }\n        Edge<T>& operator[](int i)\
    \ const { return begit[i]; }\n\n      private:\n        Iterator begit, endit;\n\
    \    };\n\n    int n, m;\n    bool is_build, is_directed;\n    std::vector<Edge<T>>\
    \ edges;\n\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\u7528\n    std::vector<int>\
    \ start;\n    std::vector<Edge<T>> csr_edges;\n\n    Graph() = default;\n    Graph(const\
    \ int n, const bool directed = false)\n        : n(n), m(0), is_build(false),\
    \ is_directed(directed), start(n + 1, 0) {}\n\n    // \u8FBA\u3092\u8FFD\u52A0\
    \u3057, \u305D\u306E\u8FBA\u304C\u4F55\u756A\u76EE\u306B\u8FFD\u52A0\u3055\u308C\
    \u305F\u304B\u3092\u8FD4\u3059\n    int add_edge(const int from,\n           \
    \      const int to,\n                 const T cost = T(1),\n                \
    \ int id = -1) {\n        assert(!is_build);\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        if (id == -1) id = m;\n\
    \        edges.emplace_back(from, to, cost, id);\n        return m++;\n    }\n\
    \n    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\n    void\
    \ build() {\n        assert(!is_build);\n        for (auto&& e : edges) {\n  \
    \          start[e.from + 1]++;\n            if (!is_directed) start[e.to + 1]++;\n\
    \        }\n        for (int v = 0; v < n; v++) start[v + 1] += start[v];\n  \
    \      auto counter = start;\n        csr_edges.resize(start.back() + 1);\n  \
    \      for (auto&& e : edges) {\n            csr_edges[counter[e.from]++] = e;\n\
    \            if (!is_directed)\n                csr_edges[counter[e.to]++] = Edge(e.to,\
    \ e.from, e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
    \ operator[](int i) {\n        if (!is_build) build();\n        return EdgeIterators(csr_edges.begin()\
    \ + start[i],\n                             csr_edges.begin() + start[i + 1]);\n\
    \    }\n\n    size_t size() const { return (size_t)(n); }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, Graph<T>& g) {\n        os << \"[\";\n        for\
    \ (int i = 0; i < (int)(g.size()); i++) {\n            os << \"[\";\n        \
    \    for (int j = 0; j < (int)(g[i].size()); j++) {\n                os << g[i][j];\n\
    \                if (j + 1 != (int)(g[i].size())) os << \", \";\n            }\n\
    \            os << \"]\";\n            if (i + 1 != (int)(g.size())) os << \"\
    , \";\n        }\n        return os << \"]\";\n    }\n};\n#line 4 \"graph/bellman_ford.hpp\"\
    \n\n#include <tuple>\n\n// {dist, par, root}\ntemplate <class T> std::tuple<std::vector<T>,\
    \ std::vector<int>, std::vector<int>> bellman_ford(Graph<T>& g, std::vector<int>&\
    \ s, const T inf) {\n    const int n = (int)(g.size());\n    std::vector<T> dist(n,\
    \ inf);\n    std::vector<int> par(n, -1), root(n, -1);\n\n    for (auto&& v :\
    \ s) {\n        dist[v] = 0;\n        root[v] = v;\n    }\n    int loop_count\
    \ = 0;\n\n    while (true) {\n        loop_count++;\n        bool update = false;\n\
    \        for (int cur = 0; cur < n; cur++) {\n            if (dist[cur] == inf)\
    \ continue;\n            for (auto&& e : g[cur]) {\n                T nd = std::max(-inf,\
    \ dist[cur] + e.cost);\n                if (dist[e.to] > nd) {\n             \
    \       par[e.to] = cur;\n                    root[e.to] = root[cur];\n      \
    \              update = true;\n                    if (loop_count >= n) nd = -inf;\n\
    \                    dist[e.to] = nd;\n                }\n            }\n    \
    \    }\n        if (!update) break;\n    }\n    return {dist, par, root};\n}\n\
    #line 2 \"graph/read_graph.hpp\"\n\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate\
    \ <class T>\nGraph<T> read_graph(const int n,\n                    const int m,\n\
    \                    const bool weight = false,\n                    const bool\
    \ directed = false,\n                    const int offset = 1) {\n    Graph<T>\
    \ g(n, directed);\n    for (int i = 0; i < m; i++) {\n        int a, b;\n    \
    \    std::cin >> a >> b;\n        a -= offset, b -= offset;\n        T c = 1;\n\
    \        if (weight) std::cin >> c;\n        g.add_edge(a, b, c);\n    }\n   \
    \ g.build();\n    return g;\n}\n\ntemplate <class T>\nGraph<T> read_parent(const\
    \ int n,\n                     const bool weight = false,\n                  \
    \   const bool directed = false,\n                     const int offset = 1) {\n\
    \    Graph<T> g(n, directed);\n    for (int i = 1; i < n; i++) {\n        int\
    \ p;\n        std::cin >> p;\n        p -= offset;\n        T c = 1;\n       \
    \ if (weight) std::cin >> c;\n        g.add_edge(p, i, c);\n    }\n    g.build();\n\
    \    return g;\n}\n#line 8 \"verify/graph/bellman_ford.test.cpp\"\n\nint main()\
    \ {\n    int N, M, r;\n    std::cin >> N >> M >> r;\n    auto g = read_graph<int>(N,\
    \ M, true, true, 0);\n    std::vector<int> s = {r};\n    const int INF = 1 <<\
    \ 30;\n    auto [dist, par, root] = bellman_ford(g, s, INF);\n    int ans = *std::min_element(dist.begin(),\
    \ dist.end());\n    if (ans == -INF) {\n        std::cout << \"NEGATIVE CYCLE\"\
    \ << '\\n';\n    } else {\n        for (int i = 0; i < N; i++) {\n           \
    \ if (dist[i] == INF) {\n                std::cout << \"INF\" << '\\n';\n    \
    \        } else {\n                std::cout << dist[i] << '\\n';\n          \
    \  }\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <iostream>\n#include <algorithm>\n\n#include \"graph/bellman_ford.hpp\"\
    \n#include \"graph/read_graph.hpp\"\n\nint main() {\n    int N, M, r;\n    std::cin\
    \ >> N >> M >> r;\n    auto g = read_graph<int>(N, M, true, true, 0);\n    std::vector<int>\
    \ s = {r};\n    const int INF = 1 << 30;\n    auto [dist, par, root] = bellman_ford(g,\
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
  path: verify/graph/bellman_ford.test.cpp
  requiredBy: []
  timestamp: '2026-01-20 04:06:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/bellman_ford.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/bellman_ford.test.cpp
- /verify/verify/graph/bellman_ford.test.cpp.html
title: verify/graph/bellman_ford.test.cpp
---
