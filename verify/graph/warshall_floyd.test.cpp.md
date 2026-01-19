---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':x:'
    path: graph/warshall_floyd.hpp
    title: "Warshall-Floyd algorithm (\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\
      \u30C9\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"verify/graph/warshall_floyd.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\n\n#include\
    \ <iostream>\n\n#line 2 \"graph/warshall_floyd.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\ntemplate <class T> struct Edge {\n\
    \    int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const\
    \ int from, const int to, const T cost = T(1), const int id = -1)\n        : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend bool operator<(const Edge<T>& a,\
    \ const Edge<T>& b) {\n        return a.cost < b.cost;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Edge<T>& e) {\n        // output format:\
    \ {id: cost(from, to) = cost}\n        return os << \"{\" << e.id << \": cost(\"\
    \ << e.from << \", \" << e.to\n                  << \") = \" << e.cost << \"}\"\
    ;\n    }\n};\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\ntemplate\
    \ <class T> struct Graph {\n    struct EdgeIterators {\n      public:\n      \
    \  using Iterator = typename std::vector<Edge<T>>::iterator;\n        EdgeIterators()\
    \ = default;\n        EdgeIterators(const Iterator& begit, const Iterator& endit)\n\
    \            : begit(begit), endit(endit) {}\n        Iterator begin() const {\
    \ return begit; }\n        Iterator end() const { return endit; }\n        size_t\
    \ size() const { return std::distance(begit, endit); }\n        Edge<T>& operator[](int\
    \ i) const { return begit[i]; }\n\n      private:\n        Iterator begit, endit;\n\
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
    , \";\n        }\n        return os << \"]\";\n    }\n};\n#line 4 \"graph/warshall_floyd.hpp\"\
    \n\ntemplate <class T> std::vector<std::vector<T>> warshall_floyd(Graph<T>& g,\
    \ const T inf) {\n    const int n = (int)(g.size());\n\n    std::vector dist(n,\
    \ std::vector<T>(n, inf));\n    for (int i = 0; i < n; i++) {\n        dist[i][i]\
    \ = 0;\n        for (auto&& e : g[i]) {\n            dist[e.from][e.to] = std::min(dist[e.from][e.to],\
    \ e.cost);\n        }\n    }\n\n    for (int k = 0; k < n; k++) {\n        for\
    \ (int i = 0; i < n; i++) {\n            if (dist[i][k] == inf) continue;\n  \
    \          for (int j = 0; j < n; j++) {\n                if (dist[k][j] == inf)\
    \ continue;\n                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \            }\n        }\n    }\n\n    // \u8CA0\u9589\u8DEF\u691C\u51FA\n  \
    \  for (int i = 0; i < n; i++) {\n        if (dist[i][i] < 0) dist[i][i] = -inf;\n\
    \    }\n\n    // \u8CA0\u9589\u8DEF\u3092\u3082\u3068\u306B\u5C0F\u3055\u304F\u3067\
    \u304D\u308B\u30D1\u30B9\u306B\u3064\u3044\u3066\u8ABF\u3079\u308B\n    for (int\
    \ k = 0; k < n; k++) {\n        for (int i = 0; i < n; i++) {\n            if\
    \ (dist[i][k] == inf) continue;\n            for (int j = 0; j < n; j++) {\n \
    \               if (dist[k][j] == inf) continue;\n                T nd = dist[i][k]\
    \ + dist[k][j];\n                if (dist[i][k] == -inf or dist[k][j] == -inf)\
    \ nd = -inf;\n                dist[i][j] = std::min(dist[i][j], nd);\n       \
    \     }\n        }\n    }\n    return dist;\n}\n#line 2 \"graph/read_graph.hpp\"\
    \n\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate <class T>\nGraph<T> read_graph(const\
    \ int n,\n                    const int m,\n                    const bool weight\
    \ = false,\n                    const bool directed = false,\n               \
    \     const int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int i =\
    \ 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >> b;\n        a\
    \ -= offset, b -= offset;\n        T c = 1;\n        if (weight) std::cin >> c;\n\
    \        g.add_edge(a, b, c);\n    }\n    g.build();\n    return g;\n}\n\ntemplate\
    \ <class T>\nGraph<T> read_parent(const int n,\n                     const bool\
    \ weight = false,\n                     const bool directed = false,\n       \
    \              const int offset = 1) {\n    Graph<T> g(n, directed);\n    for\
    \ (int i = 1; i < n; i++) {\n        int p;\n        std::cin >> p;\n        p\
    \ -= offset;\n        T c = 1;\n        if (weight) std::cin >> c;\n        g.add_edge(p,\
    \ i, c);\n    }\n    g.build();\n    return g;\n}\n#line 7 \"verify/graph/warshall_floyd.test.cpp\"\
    \n\nint main() {\n    {\n        const int n1 = 5, n2 = 5;\n        Graph<int>\
    \ g(n1 + n2, true);\n        for (int i = 0; i < n1; i++) {\n            g.add_edge(i,\
    \ (i + 1) % n1, -1, i);\n        }\n        for (int i = 0; i < n2; i++) {\n \
    \           g.add_edge(i + n1, (i + 1) % n2 + n1, -1, i + n1);\n        }\n  \
    \      const int INF = 1 << 30;\n        auto dist = warshall_floyd(g, INF);\n\
    \        for (int i = 0; i < n1 + n2; i++) {\n            for (int j = 0; j <\
    \ n1 + n2; j++) {\n                int same = (i < n1) == (j < n1);\n        \
    \        if (same) {\n                    assert(dist[i][j] == -INF);\n      \
    \          } else {\n                    assert(dist[i][j] == INF);\n        \
    \        }\n            }\n        }\n    }\n    {\n        const int n1 = 5,\
    \ n2 = 5;\n        Graph<int> g(n1 + n2, true);\n        for (int i = 0; i < n1;\
    \ i++) {\n            g.add_edge(i, (i + 1) % n1, -1, i);\n        }\n       \
    \ for (int i = 0; i < n2; i++) {\n            if (i % 2 == 0) {\n            \
    \    g.add_edge(i + n1, i, 1, i + n1);\n            } else {\n               \
    \ g.add_edge(i, i + n1, 1, i + n1);\n            }\n        }\n        const int\
    \ INF = 1 << 30;\n        auto dist = warshall_floyd(g, INF);\n        for (int\
    \ i = 0; i < n1 + n2; i++) {\n            for (int j = 0; j < n1 + n2; j++) {\n\
    \                if (i < n1 and j < n1) {\n                    assert(dist[i][j]\
    \ == -INF);\n                } else if (i < n1) {\n                    assert(j\
    \ >= n1);\n                    if ((j - n1) % 2 == 0) {\n                    \
    \    assert(dist[i][j] == INF);\n                    } else {\n              \
    \          assert(dist[i][j] == -INF);\n                    }\n              \
    \  } else if (j < n1) {\n                    assert(i >= n1);\n              \
    \      if ((i - n1) % 2 == 0) {\n                        assert(dist[i][j] ==\
    \ -INF);\n                    } else {\n                        assert(dist[i][j]\
    \ == INF);\n                    }\n                } else {\n                \
    \    assert(i >= n1 and j >= n1);\n                    if (i == j) {\n       \
    \                 assert(dist[i][j] == 0);\n                    } else if ((i\
    \ - n1) % 2 == (j - n1) % 2) {\n                        assert(dist[i][j] == INF);\n\
    \                    } else {\n                        if ((i - n1) % 2 == 0)\
    \ {\n                            assert(dist[i][j] == -INF);\n               \
    \         } else {\n                            assert(dist[i][j] == INF);\n \
    \                       }\n                    }\n                }\n        \
    \    }\n        }\n    }\n    int V, E;\n    std::cin >> V >> E;\n    auto g =\
    \ read_graph<long long>(V, E, true, true, 0);\n    const long long INF = 1LL <<\
    \ 60;\n    auto dist = warshall_floyd(g, INF);\n    for (int i = 0; i < V; i++)\n\
    \        for (int j = 0; j < V; j++) {\n            if (dist[i][j] == -INF) {\n\
    \                std::cout << \"NEGATIVE CYCLE\\n\";\n                return 0;\n\
    \            }\n        }\n    for (int i = 0; i < V; i++) {\n        for (int\
    \ j = 0; j < V; j++) {\n            if (dist[i][j] == INF) {\n               \
    \ std::cout << \"INF\";\n            } else {\n                std::cout << dist[i][j];\n\
    \            }\n            std::cout << \" \\n\"[j + 1 == V];\n        }\n  \
    \  }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n\n#include \"graph/warshall_floyd.hpp\"\n#include \"\
    graph/read_graph.hpp\"\n\nint main() {\n    {\n        const int n1 = 5, n2 =\
    \ 5;\n        Graph<int> g(n1 + n2, true);\n        for (int i = 0; i < n1; i++)\
    \ {\n            g.add_edge(i, (i + 1) % n1, -1, i);\n        }\n        for (int\
    \ i = 0; i < n2; i++) {\n            g.add_edge(i + n1, (i + 1) % n2 + n1, -1,\
    \ i + n1);\n        }\n        const int INF = 1 << 30;\n        auto dist = warshall_floyd(g,\
    \ INF);\n        for (int i = 0; i < n1 + n2; i++) {\n            for (int j =\
    \ 0; j < n1 + n2; j++) {\n                int same = (i < n1) == (j < n1);\n \
    \               if (same) {\n                    assert(dist[i][j] == -INF);\n\
    \                } else {\n                    assert(dist[i][j] == INF);\n  \
    \              }\n            }\n        }\n    }\n    {\n        const int n1\
    \ = 5, n2 = 5;\n        Graph<int> g(n1 + n2, true);\n        for (int i = 0;\
    \ i < n1; i++) {\n            g.add_edge(i, (i + 1) % n1, -1, i);\n        }\n\
    \        for (int i = 0; i < n2; i++) {\n            if (i % 2 == 0) {\n     \
    \           g.add_edge(i + n1, i, 1, i + n1);\n            } else {\n        \
    \        g.add_edge(i, i + n1, 1, i + n1);\n            }\n        }\n       \
    \ const int INF = 1 << 30;\n        auto dist = warshall_floyd(g, INF);\n    \
    \    for (int i = 0; i < n1 + n2; i++) {\n            for (int j = 0; j < n1 +\
    \ n2; j++) {\n                if (i < n1 and j < n1) {\n                    assert(dist[i][j]\
    \ == -INF);\n                } else if (i < n1) {\n                    assert(j\
    \ >= n1);\n                    if ((j - n1) % 2 == 0) {\n                    \
    \    assert(dist[i][j] == INF);\n                    } else {\n              \
    \          assert(dist[i][j] == -INF);\n                    }\n              \
    \  } else if (j < n1) {\n                    assert(i >= n1);\n              \
    \      if ((i - n1) % 2 == 0) {\n                        assert(dist[i][j] ==\
    \ -INF);\n                    } else {\n                        assert(dist[i][j]\
    \ == INF);\n                    }\n                } else {\n                \
    \    assert(i >= n1 and j >= n1);\n                    if (i == j) {\n       \
    \                 assert(dist[i][j] == 0);\n                    } else if ((i\
    \ - n1) % 2 == (j - n1) % 2) {\n                        assert(dist[i][j] == INF);\n\
    \                    } else {\n                        if ((i - n1) % 2 == 0)\
    \ {\n                            assert(dist[i][j] == -INF);\n               \
    \         } else {\n                            assert(dist[i][j] == INF);\n \
    \                       }\n                    }\n                }\n        \
    \    }\n        }\n    }\n    int V, E;\n    std::cin >> V >> E;\n    auto g =\
    \ read_graph<long long>(V, E, true, true, 0);\n    const long long INF = 1LL <<\
    \ 60;\n    auto dist = warshall_floyd(g, INF);\n    for (int i = 0; i < V; i++)\n\
    \        for (int j = 0; j < V; j++) {\n            if (dist[i][j] == -INF) {\n\
    \                std::cout << \"NEGATIVE CYCLE\\n\";\n                return 0;\n\
    \            }\n        }\n    for (int i = 0; i < V; i++) {\n        for (int\
    \ j = 0; j < V; j++) {\n            if (dist[i][j] == INF) {\n               \
    \ std::cout << \"INF\";\n            } else {\n                std::cout << dist[i][j];\n\
    \            }\n            std::cout << \" \\n\"[j + 1 == V];\n        }\n  \
    \  }\n    return 0;\n}"
  dependsOn:
  - graph/warshall_floyd.hpp
  - graph/graph_template.hpp
  - graph/read_graph.hpp
  isVerificationFile: true
  path: verify/graph/warshall_floyd.test.cpp
  requiredBy: []
  timestamp: '2026-01-20 04:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/graph/warshall_floyd.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/warshall_floyd.test.cpp
- /verify/verify/graph/warshall_floyd.test.cpp.html
title: verify/graph/warshall_floyd.test.cpp
---
