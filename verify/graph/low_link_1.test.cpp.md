---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: "Low Link (\u95A2\u7BC0\u70B9\u30FB\u6A4B)"
  - icon: ':heavy_check_mark:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"verify/graph/low_link_1.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <iostream>\n#include <algorithm>\n\n#line 2 \"graph/read_graph.hpp\"\
    \n\n#line 2 \"graph/graph_template.hpp\"\n\n#include <vector>\n#include <cassert>\n\
    \ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\
    \n    Edge() = default;\n    Edge(const int from, const int to, const T cost =\
    \ T(1), const int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n   \
    \ friend bool operator<(const Edge<T>& a, const Edge<T>& b) { return a.cost <\
    \ b.cost; }\n\n    friend std::ostream& operator<<(std::ostream& os, const Edge<T>&\
    \ e) {\n        // output format: {id: cost(from, to) = cost}\n        return\
    \ os << \"{\" << e.id << \": cost(\" << e.from << \", \" << e.to << \") = \" <<\
    \ e.cost << \"}\";\n    }\n};\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    \ntemplate <class T> struct Graph {\n    struct EdgeIterators {\n       public:\n\
    \        using Iterator = typename std::vector<Edge<T>>::iterator;\n        EdgeIterators()\
    \ = default;\n        EdgeIterators(const Iterator& begit, const Iterator& endit)\
    \ : begit(begit), endit(endit) {}\n        Iterator begin() const { return begit;\
    \ }\n        Iterator end() const { return endit; }\n        size_t size() const\
    \ { return std::distance(begit, endit); }\n        Edge<T>& operator[](int i)\
    \ const { return begit[i]; }\n\n       private:\n        Iterator begit, endit;\n\
    \    };\n\n    int n, m;\n    bool is_build, is_directed;\n    std::vector<Edge<T>>\
    \ edges;\n\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\u7528\n    std::vector<int>\
    \ start;\n    std::vector<Edge<T>> csr_edges;\n\n    Graph() = default;\n    Graph(const\
    \ int n, const bool directed = false) : n(n), m(0), is_build(false), is_directed(directed),\
    \ start(n + 1, 0) {}\n\n    // \u8FBA\u3092\u8FFD\u52A0\u3057, \u305D\u306E\u8FBA\
    \u304C\u4F55\u756A\u76EE\u306B\u8FFD\u52A0\u3055\u308C\u305F\u304B\u3092\u8FD4\
    \u3059\n    int add_edge(const int from, const int to, const T cost = T(1), int\
    \ id = -1) {\n        assert(!is_build);\n        assert(0 <= from and from <\
    \ n);\n        assert(0 <= to and to < n);\n        if (id == -1) id = m;\n  \
    \      edges.emplace_back(from, to, cost, id);\n        return m++;\n    }\n\n\
    \    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\n    void build()\
    \ {\n        assert(!is_build);\n        for (auto&& e : edges) {\n          \
    \  start[e.from + 1]++;\n            if (!is_directed) start[e.to + 1]++;\n  \
    \      }\n        for (int v = 0; v < n; v++) start[v + 1] += start[v];\n    \
    \    auto counter = start;\n        csr_edges.resize(start.back() + 1);\n    \
    \    for (auto&& e : edges) {\n            csr_edges[counter[e.from]++] = e;\n\
    \            if (!is_directed) csr_edges[counter[e.to]++] = Edge(e.to, e.from,\
    \ e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
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
    \ c);\n    }\n    g.build();\n    return g;\n}\n#line 2 \"graph/low_link.hpp\"\
    \n\n#line 4 \"graph/low_link.hpp\"\n\ntemplate <class T> struct LowLink {\n  \
    \  int n;\n    std::vector<int> ord, low;\n    std::vector<std::vector<int>> dfs_tree;\n\
    \    std::vector<int> articulations;\n    std::vector<std::pair<int, int>> bridges;\
    \  // edges {u, v} (u < v)\n    std::vector<int> roots;\n\n    LowLink(Graph<T>&\
    \ g) : n((int)(g.size())), ord(n, -1), low(n, -1), dfs_tree(n) {\n        int\
    \ ord_id = 0;\n        auto dfs = [&](auto f, int cur, int par) -> void {\n  \
    \          low[cur] = ord[cur] = ord_id++;\n            bool is_articulation =\
    \ false;\n            for (auto&& e : g[cur]) {\n                if (ord[e.to]\
    \ == -1) {\n                    // DFS \u6728\u4E0A\u306E\u8FBA\u306B\u5BFE\u3059\
    \u308B\u51E6\u7406\n                    f(f, e.to, cur);\n                   \
    \ dfs_tree[cur].push_back(e.to);\n                    // e \u304C DFS \u6728\u306B\
    \u542B\u307E\u308C\u3066\u3044\u308B\u306E\u3067\u5F8C\u9000\u8FBA\u3092\u3059\
    \u3067\u306B\u901A\u3063\u305F low[e.to] \u3092\u4F7F\u3063\u3066\u66F4\u65B0\u3057\
    \u3066\u826F\u3044\n                    low[cur] = std::min(low[cur], low[e.to]);\n\
    \                    is_articulation |= (par != -1) and (ord[cur] <= low[e.to]);\n\
    \                    if (ord[cur] < low[e.to]) {\n                        bridges.emplace_back(std::minmax(cur,\
    \ e.to));\n                    }\n                } else if (e.to != par) {\n\
    \                    // \u5F8C\u9000\u8FBA\u306B\u5BFE\u3059\u308B\u51E6\u7406\
    \n                    // Todo: multiple edges\n                    low[cur] =\
    \ std::min(low[cur], ord[e.to]);\n                }\n            }\n         \
    \   is_articulation |= par == -1 and (int)(dfs_tree[cur].size()) > 1;\n      \
    \      if (is_articulation) articulations.push_back(cur);\n            return;\n\
    \        };\n        for (int i = 0; i < n; i++) {\n            if (ord[i] ==\
    \ -1) {\n                roots.push_back(i);\n                dfs(dfs, i, -1);\n\
    \            }\n        }\n    }\n\n    // \u9023\u7D50\u6210\u5206\u6570\n  \
    \  int count_components() { return (int)(roots.size()); }\n\n    // \u9802\u70B9\
    \ x \u3092\u53D6\u308A\u9664\u304F\u3068\u3082\u3068\u3082\u3068 1 \u3064\u3060\
    \u3063\u305F\u9023\u7D50\u6210\u5206\u304C\u3044\u304F\u3064\u306B\u306A\u308B\
    \u304B\n    int count_components_remove(int x) {\n        if (std::binary_search(roots.begin(),\
    \ roots.end(), x)) {\n            return (int)(dfs_tree[x].size());\n        }\
    \ else {\n            int c = 0;\n            for (auto&& e : dfs_tree[x]) {\n\
    \                if (ord[x] <= low[e]) c++;\n            }\n            // \u89AA\
    \u306E\u5206\u3067 +1\n            return c + 1;\n        }\n    }\n};\n#line\
    \ 8 \"verify/graph/low_link_1.test.cpp\"\n\nint main() {\n    int N, M;\n    std::cin\
    \ >> N >> M;\n    auto g = read_graph<int>(N, M, false, false, 0);\n    LowLink\
    \ llink(g);\n    auto ans = llink.articulations;\n    std::sort(ans.begin(), ans.end());\n\
    \    for (auto&& v : ans) std::cout << v << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <iostream>\n#include <algorithm>\n\n#include \"graph/read_graph.hpp\"\
    \n#include \"graph/low_link.hpp\"\n\nint main() {\n    int N, M;\n    std::cin\
    \ >> N >> M;\n    auto g = read_graph<int>(N, M, false, false, 0);\n    LowLink\
    \ llink(g);\n    auto ans = llink.articulations;\n    std::sort(ans.begin(), ans.end());\n\
    \    for (auto&& v : ans) std::cout << v << '\\n';\n    return 0;\n}"
  dependsOn:
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/low_link.hpp
  isVerificationFile: true
  path: verify/graph/low_link_1.test.cpp
  requiredBy: []
  timestamp: '2024-07-31 21:19:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/low_link_1.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/low_link_1.test.cpp
- /verify/verify/graph/low_link_1.test.cpp.html
title: verify/graph/low_link_1.test.cpp
---