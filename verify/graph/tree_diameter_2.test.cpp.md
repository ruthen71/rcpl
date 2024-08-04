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
    path: graph/restore_path.hpp
    title: Restore path
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
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
  bundledCode: "#line 1 \"verify/graph/tree_diameter_2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include <iostream>\n\n\
    #line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\n\n#include\
    \ <vector>\n#include <cassert>\n\ntemplate <class T> struct Edge {\n    int from,\
    \ to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const int from,\
    \ const int to, const T cost = T(1), const int id = -1) : from(from), to(to),\
    \ cost(cost), id(id) {}\n\n    friend bool operator<(const Edge<T>& a, const Edge<T>&\
    \ b) { return a.cost < b.cost; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Edge<T>& e) {\n        // output format: {id: cost(from, to) = cost}\n\
    \        return os << \"{\" << e.id << \": cost(\" << e.from << \", \" << e.to\
    \ << \") = \" << e.cost << \"}\";\n    }\n};\ntemplate <class T> using Edges =\
    \ std::vector<Edge<T>>;\n\ntemplate <class T> struct Graph {\n    struct EdgeIterators\
    \ {\n       public:\n        using Iterator = typename std::vector<Edge<T>>::iterator;\n\
    \        EdgeIterators() = default;\n        EdgeIterators(const Iterator& begit,\
    \ const Iterator& endit) : begit(begit), endit(endit) {}\n        Iterator begin()\
    \ const { return begit; }\n        Iterator end() const { return endit; }\n  \
    \      size_t size() const { return std::distance(begit, endit); }\n        Edge<T>&\
    \ operator[](int i) const { return begit[i]; }\n\n       private:\n        Iterator\
    \ begit, endit;\n    };\n\n    int n, m;\n    bool is_build, is_directed;\n  \
    \  std::vector<Edge<T>> edges;\n\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\
    \u7528\n    std::vector<int> start;\n    std::vector<Edge<T>> csr_edges;\n\n \
    \   Graph() = default;\n    Graph(const int n, const bool directed = false) :\
    \ n(n), m(0), is_build(false), is_directed(directed), start(n + 1, 0) {}\n\n \
    \   // \u8FBA\u3092\u8FFD\u52A0\u3057, \u305D\u306E\u8FBA\u304C\u4F55\u756A\u76EE\
    \u306B\u8FFD\u52A0\u3055\u308C\u305F\u304B\u3092\u8FD4\u3059\n    int add_edge(const\
    \ int from, const int to, const T cost = T(1), int id = -1) {\n        assert(!is_build);\n\
    \        assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n\
    \        if (id == -1) id = m;\n        edges.emplace_back(from, to, cost, id);\n\
    \        return m++;\n    }\n\n    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\
    \u3092\u69CB\u7BC9\n    void build() {\n        assert(!is_build);\n        for\
    \ (auto&& e : edges) {\n            start[e.from + 1]++;\n            if (!is_directed)\
    \ start[e.to + 1]++;\n        }\n        for (int v = 0; v < n; v++) start[v +\
    \ 1] += start[v];\n        auto counter = start;\n        csr_edges.resize(start.back()\
    \ + 1);\n        for (auto&& e : edges) {\n            csr_edges[counter[e.from]++]\
    \ = e;\n            if (!is_directed) csr_edges[counter[e.to]++] = Edge(e.to,\
    \ e.from, e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
    \ operator[](int i) {\n        if (!is_build) build();\n        return EdgeIterators(csr_edges.begin()\
    \ + start[i], csr_edges.begin() + start[i + 1]);\n    }\n\n    size_t size() const\
    \ { return (size_t)(n); }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, Graph<T>& g) {\n        os << \"[\";\n        for (int i = 0; i < (int)(g.size());\
    \ i++) {\n            os << \"[\";\n            for (int j = 0; j < (int)(g[i].size());\
    \ j++) {\n                os << g[i][j];\n                if (j + 1 != (int)(g[i].size()))\
    \ os << \", \";\n            }\n            os << \"]\";\n            if (i +\
    \ 1 != (int)(g.size())) os << \", \";\n        }\n        return os << \"]\";\n\
    \    }\n};\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate <class T> Graph<T> read_graph(const\
    \ int n, const int m, const bool weight = false, const bool directed = false,\
    \ const int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int i = 0; i\
    \ < m; i++) {\n        int a, b;\n        std::cin >> a >> b;\n        a -= offset,\
    \ b -= offset;\n        T c = 1;\n        if (weight) std::cin >> c;\n       \
    \ g.add_edge(a, b, c);\n    }\n    g.build();\n    return g;\n}\n\ntemplate <class\
    \ T> Graph<T> read_parent(const int n, const bool weight = false, const bool directed\
    \ = false, const int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int\
    \ i = 1; i < n; i++) {\n        int p;\n        std::cin >> p;\n        p -= offset;\n\
    \        T c = 1;\n        if (weight) std::cin >> c;\n        g.add_edge(p, i,\
    \ c);\n    }\n    g.build();\n    return g;\n}\n#line 2 \"graph/tree_diameter.hpp\"\
    \n\n#line 2 \"graph/restore_path.hpp\"\n\n#line 4 \"graph/restore_path.hpp\"\n\
    #include <algorithm>\n\n// restore path from root[t] to t\nstd::vector<int> restore_path(std::vector<int>&\
    \ par, int t) {\n    std::vector<int> path = {t};\n    while (par[path.back()]\
    \ != -1) path.emplace_back(par[path.back()]);\n    std::reverse(path.begin(),\
    \ path.end());\n    return path;\n}\n#line 5 \"graph/tree_diameter.hpp\"\n\n#include\
    \ <utility>\n#line 8 \"graph/tree_diameter.hpp\"\n\n// {\u76F4\u5F84\u306E\u8FBA\
    \u306E\u91CD\u307F\u306E\u7DCF\u548C, \u901A\u308B\u9802\u70B9\u96C6\u5408}\n\
    template <class T> std::pair<T, std::vector<int>> tree_diameter(Graph<T>& g) {\n\
    \    const int n = (int)(g.size());\n    std::vector<int> parent(n, -1);\n   \
    \ std::vector<T> dist(n);\n\n    auto dfs = [&](auto f, int cur, int par) -> void\
    \ {\n        for (auto&& e : g[cur]) {\n            if (e.to == par) continue;\n\
    \            dist[e.to] = dist[cur] + e.cost;\n            parent[e.to] = cur;\n\
    \            f(f, e.to, cur);\n        }\n        return;\n    };\n\n    dfs(dfs,\
    \ 0, -1);\n    int s = std::max_element(dist.begin(), dist.end()) - dist.begin();\n\
    \    dist.assign(n, 0);\n    parent.assign(n, -1);\n    dfs(dfs, s, -1);\n   \
    \ int t = std::max_element(dist.begin(), dist.end()) - dist.begin();\n    auto\
    \ path = restore_path(parent, t);\n    return {dist[t], path};\n}\n#line 7 \"\
    verify/graph/tree_diameter_2.test.cpp\"\n\nint main() {\n    int N;\n    std::cin\
    \ >> N;\n    auto g = read_graph<long long>(N, N - 1, true, false, 0);\n    auto\
    \ [d, path] = tree_diameter(g);\n    std::cout << d << ' ' << path.size() << '\\\
    n';\n    for (int i = 0; i < (int)(path.size()); i++) {\n        std::cout <<\
    \ path[i] << \" \\n\"[i + 1 == (int)(path.size())];\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ <iostream>\n\n#include \"graph/read_graph.hpp\"\n#include \"graph/tree_diameter.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    auto g = read_graph<long\
    \ long>(N, N - 1, true, false, 0);\n    auto [d, path] = tree_diameter(g);\n \
    \   std::cout << d << ' ' << path.size() << '\\n';\n    for (int i = 0; i < (int)(path.size());\
    \ i++) {\n        std::cout << path[i] << \" \\n\"[i + 1 == (int)(path.size())];\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/tree_diameter.hpp
  - graph/restore_path.hpp
  isVerificationFile: true
  path: verify/graph/tree_diameter_2.test.cpp
  requiredBy: []
  timestamp: '2024-08-05 02:23:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/tree_diameter_2.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/tree_diameter_2.test.cpp
- /verify/verify/graph/tree_diameter_2.test.cpp.html
title: verify/graph/tree_diameter_2.test.cpp
---
