---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_component.hpp
    title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"verify/graph/strongly_connected_component_1.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#include <iostream>\n\n#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
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
    , \";\n        }\n        return os << \"]\";\n    }\n};\n#line 4 \"graph/read_graph.hpp\"\
    \n\ntemplate <class T>\nGraph<T> read_graph(const int n,\n                   \
    \ const int m,\n                    const bool weight = false,\n             \
    \       const bool directed = false,\n                    const int offset = 1)\
    \ {\n    Graph<T> g(n, directed);\n    for (int i = 0; i < m; i++) {\n       \
    \ int a, b;\n        std::cin >> a >> b;\n        a -= offset, b -= offset;\n\
    \        T c = 1;\n        if (weight) std::cin >> c;\n        g.add_edge(a, b,\
    \ c);\n    }\n    g.build();\n    return g;\n}\n\ntemplate <class T>\nGraph<T>\
    \ read_parent(const int n,\n                     const bool weight = false,\n\
    \                     const bool directed = false,\n                     const\
    \ int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int i = 1; i < n;\
    \ i++) {\n        int p;\n        std::cin >> p;\n        p -= offset;\n     \
    \   T c = 1;\n        if (weight) std::cin >> c;\n        g.add_edge(p, i, c);\n\
    \    }\n    g.build();\n    return g;\n}\n#line 2 \"graph/strongly_connected_component.hpp\"\
    \n\n#line 4 \"graph/strongly_connected_component.hpp\"\n\ntemplate <class T> std::vector<std::vector<int>>\
    \ strongly_connected_component(Graph<T>& g) {\n    const int n = (int)(g.size());\n\
    \    int now_ord = 0, group_num = 0;\n    std::vector<int> visited, low(n), ord(n,\
    \ -1), ids(n);\n    visited.reserve(n);\n    auto dfs = [&](auto f, int cur) ->\
    \ void {\n        low[cur] = ord[cur] = now_ord++;\n        visited.push_back(cur);\n\
    \        for (auto&& e : g[cur]) {\n            if (ord[e.to] == -1) {\n     \
    \           f(f, e.to);\n                low[cur] = std::min(low[cur], low[e.to]);\n\
    \            } else {\n                low[cur] = std::min(low[cur], ord[e.to]);\n\
    \            }\n        }\n        if (low[cur] == ord[cur]) {\n            while\
    \ (true) {\n                int u = visited.back();\n                visited.pop_back();\n\
    \                ord[u] = n;\n                ids[u] = group_num;\n          \
    \      if (u == cur) break;\n            }\n            group_num++;\n       \
    \ }\n    };\n    for (int i = 0; i < n; i++) {\n        if (ord[i] == -1) dfs(dfs,\
    \ i);\n    }\n    for (auto&& x : ids) {\n        x = group_num - 1 - x;\n   \
    \ }\n    std::vector<int> counts(group_num);\n    for (auto&& x : ids) counts[x]++;\n\
    \    std::vector<std::vector<int>> groups(group_num);\n    for (int i = 0; i <\
    \ group_num; i++) groups[i].reserve(counts[i]);\n    for (int i = 0; i < n; i++)\
    \ groups[ids[i]].push_back(i);\n    return groups;\n}\n#line 7 \"verify/graph/strongly_connected_component_1.test.cpp\"\
    \n\nint main() {\n    int V, E;\n    std::cin >> V >> E;\n    auto g = read_graph<int>(V,\
    \ E, false, true, 0);\n    auto res = strongly_connected_component(g);\n    std::vector<int>\
    \ id(V);\n    for (int i = 0; i < (int)(res.size()); i++) {\n        for (auto&&\
    \ e : res[i]) id[e] = i;\n    }\n    int Q;\n    std::cin >> Q;\n    for (int\
    \ i = 0; i < Q; i++) {\n        int u, v;\n        std::cin >> u >> v;\n     \
    \   std::cout << (id[u] == id[v]) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#include <iostream>\n\n#include \"graph/read_graph.hpp\"\n#include \"graph/strongly_connected_component.hpp\"\
    \n\nint main() {\n    int V, E;\n    std::cin >> V >> E;\n    auto g = read_graph<int>(V,\
    \ E, false, true, 0);\n    auto res = strongly_connected_component(g);\n    std::vector<int>\
    \ id(V);\n    for (int i = 0; i < (int)(res.size()); i++) {\n        for (auto&&\
    \ e : res[i]) id[e] = i;\n    }\n    int Q;\n    std::cin >> Q;\n    for (int\
    \ i = 0; i < Q; i++) {\n        int u, v;\n        std::cin >> u >> v;\n     \
    \   std::cout << (id[u] == id[v]) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/strongly_connected_component.hpp
  isVerificationFile: true
  path: verify/graph/strongly_connected_component_1.test.cpp
  requiredBy: []
  timestamp: '2026-01-20 04:06:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/strongly_connected_component_1.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/strongly_connected_component_1.test.cpp
- /verify/verify/graph/strongly_connected_component_1.test.cpp.html
title: verify/graph/strongly_connected_component_1.test.cpp
---
