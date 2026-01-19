---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal's algorithm (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  - icon: ':question:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':question:'
    path: unionfind/unionfind.hpp
    title: Unionfind
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
  bundledCode: "#line 1 \"verify/graph/kruskal.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <iostream>\n\n#line 2 \"graph/kruskal.hpp\"\n\n#line 2 \"unionfind/unionfind.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n// Unionfind\n\
    struct Unionfind {\n    int n;\n    std::vector<int> parent;\n\n    Unionfind()\
    \ = default;\n\n    explicit Unionfind(int n) : n(n), parent(n, -1) {}\n\n   \
    \ int leader(int x) {\n        assert(0 <= x and x < n);\n        if (parent[x]\
    \ < 0) {\n            return x;\n        } else {\n            return parent[x]\
    \ = leader(parent[x]);\n        }\n    }\n\n    int merge(int x, int y) {\n  \
    \      assert(0 <= x and x < n);\n        assert(0 <= y and y < n);\n        x\
    \ = leader(x);\n        y = leader(y);\n        if (x == y) {\n            return\
    \ x;\n        }\n        if (-parent[x] < -parent[y]) {\n            std::swap(x,\
    \ y);\n        }\n        parent[x] += parent[y];\n        parent[y] = x;\n  \
    \      return x;\n    }\n\n    bool same(int x, int y) {\n        assert(0 <=\
    \ x and x < n);\n        assert(0 <= y and y < n);\n        return leader(x) ==\
    \ leader(y);\n    }\n\n    int size(int x) {\n        assert(0 <= x and x < n);\n\
    \        return -parent[leader(x)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(n), group_size(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n    \
    \        group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(\n                         result.begin(),\
    \ result.end(),\n                         [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n                     result.end());\n        return result;\n\
    \    }\n};\n#line 2 \"graph/graph_template.hpp\"\n\n#line 5 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(const int from, const int to, const T\
    \ cost = T(1), const int id = -1)\n        : from(from), to(to), cost(cost), id(id)\
    \ {}\n\n    friend bool operator<(const Edge<T>& a, const Edge<T>& b) {\n    \
    \    return a.cost < b.cost;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
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
    , \";\n        }\n        return os << \"]\";\n    }\n};\n#line 5 \"graph/kruskal.hpp\"\
    \n\n#line 7 \"graph/kruskal.hpp\"\n\ntemplate <class T> std::pair<T, std::vector<Edge<T>>>\
    \ kruskal(Graph<T>& g) {\n    auto es = g.edges;\n    std::sort(es.begin(), es.end());\n\
    \    const int n = (int)(g.size());\n    Unionfind uf(n);\n    T ret = 0;\n  \
    \  std::vector<Edge<T>> es_ret;\n    es_ret.reserve(n - 1);\n    for (auto&& e\
    \ : es) {\n        if (!uf.same(e.from, e.to)) {\n            ret += e.cost;\n\
    \            uf.merge(e.from, e.to);\n            es_ret.push_back(e);\n     \
    \   }\n    }\n    return {ret, es_ret};\n}\n#line 2 \"graph/read_graph.hpp\"\n\
    \n#line 4 \"graph/read_graph.hpp\"\n\ntemplate <class T>\nGraph<T> read_graph(const\
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
    \ i, c);\n    }\n    g.build();\n    return g;\n}\n#line 7 \"verify/graph/kruskal.test.cpp\"\
    \n\nint main() {\n    int N, M;\n    std::cin >> N >> M;\n    auto g = read_graph<long\
    \ long>(N, M, true, false, 0);\n    auto [cost, es_set] = kruskal<long long>(g);\n\
    \    std::cout << cost << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <iostream>\n\n#include \"graph/kruskal.hpp\"\n#include \"graph/read_graph.hpp\"\
    \n\nint main() {\n    int N, M;\n    std::cin >> N >> M;\n    auto g = read_graph<long\
    \ long>(N, M, true, false, 0);\n    auto [cost, es_set] = kruskal<long long>(g);\n\
    \    std::cout << cost << '\\n';\n    return 0;\n}"
  dependsOn:
  - graph/kruskal.hpp
  - unionfind/unionfind.hpp
  - graph/graph_template.hpp
  - graph/read_graph.hpp
  isVerificationFile: true
  path: verify/graph/kruskal.test.cpp
  requiredBy: []
  timestamp: '2026-01-20 04:06:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/kruskal.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/kruskal.test.cpp
- /verify/verify/graph/kruskal.test.cpp.html
title: verify/graph/kruskal.test.cpp
---
