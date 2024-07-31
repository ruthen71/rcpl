---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/auxiliary_tree.hpp
    title: "Auxiliary Tree (\u865A\u6811)"
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':question:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc359/tasks/abc359_g
    links:
    - https://atcoder.jp/contests/abc359/tasks/abc359_g
  bundledCode: "#line 1 \"verify/graph/auxiliary_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc359/tasks/abc359_g\"\n\n#include <iostream>\n\
    \n#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\n\n\
    #include <vector>\n#include <cassert>\n\ntemplate <class T> struct Edge {\n  \
    \  int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const\
    \ int from, const int to, const T cost = T(1), const int id = -1) : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend bool operator<(const Edge<T>& a,\
    \ const Edge<T>& b) { return a.cost < b.cost; }\n\n    friend std::ostream& operator<<(std::ostream&\
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
    \ c);\n    }\n    g.build();\n    return g;\n}\n#line 2 \"graph/auxiliary_tree.hpp\"\
    \n\n#line 2 \"graph/lowest_common_ancestor.hpp\"\n\n#line 4 \"graph/lowest_common_ancestor.hpp\"\
    \n\n#line 6 \"graph/lowest_common_ancestor.hpp\"\n\ntemplate <class T> struct\
    \ LowestCommonAncestor {\n    int n, lg;\n    std::vector<int> depth;\n    std::vector<std::vector<int>>\
    \ parent;\n\n    LowestCommonAncestor(Graph<T>& g, const int root = 0) : n((int)(g.size())),\
    \ lg(32 - __builtin_clz(n)), depth(n, 0), parent(lg, std::vector<int>(n)) {\n\
    \        auto dfs = [&](auto f, int cur, int par) -> void {\n            parent[0][cur]\
    \ = par;\n            for (auto&& e : g[cur]) {\n                if (e.to == par)\
    \ continue;\n                depth[e.to] = depth[cur] + 1;\n                f(f,\
    \ e.to, cur);\n            }\n        };\n        dfs(dfs, root, -1);\n      \
    \  for (int k = 0; k + 1 < lg; k++) {\n            for (int v = 0; v < n; v++)\
    \ {\n                parent[k + 1][v] = parent[k][v] < 0 ? -1 : parent[k][parent[k][v]];\n\
    \            }\n        }\n    }\n\n    int lca(int u, int v) {\n        assert((int)(depth.size())\
    \ == n);\n        if (depth[u] > depth[v]) std::swap(u, v);\n        // depth[u]\
    \ <= depth[v]\n        for (int k = 0; k < lg; k++) {\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) v = parent[k][v];\n        }\n        if (u == v) return\
    \ u;\n        for (int k = lg - 1; k >= 0; k--) {\n            if (parent[k][u]\
    \ != parent[k][v]) {\n                u = parent[k][u];\n                v = parent[k][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    int level_ancestor(int\
    \ u, const int d) {\n        assert((int)(depth.size()) == n);\n        if (depth[u]\
    \ < d) return -1;\n        for (int k = 0; k < lg; k++) {\n            if (d >>\
    \ k & 1) u = parent[k][u];\n        }\n        return u;\n    }\n\n    int distance(const\
    \ int u, const int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)];\
    \ }\n};\n#line 5 \"graph/auxiliary_tree.hpp\"\n\n#include <algorithm>\n\ntemplate\
    \ <class T> struct AuxiliaryTree {\n    int n, root;\n    std::vector<int> preorder,\
    \ rank;\n    std::vector<T> depth;\n    LowestCommonAncestor<T> lca;\n\n    AuxiliaryTree(Graph<T>&\
    \ g, const int root = 0) : n((int)(g.size())), root(root), depth(n, T(0)), rank(n),\
    \ lca(g, root) {\n        // DFS \u3057\u3066\u884C\u304D\u304C\u3051\u9806\u306B\
    \u9802\u70B9\u3092\u4E26\u3079\u308B\n        auto dfs = [&](auto f, int cur,\
    \ int par) -> void {\n            preorder.push_back(cur);\n            for (auto&&\
    \ e : g[cur]) {\n                if (e.to == par) continue;\n                depth[e.to]\
    \ = depth[cur] + e.cost;\n                f(f, e.to, cur);\n            }\n  \
    \      };\n        dfs(dfs, root, -1);\n        for (int i = 0; i < n; i++) rank[preorder[i]]\
    \ = i;\n    }\n\n    // (\u5727\u7E2E\u5F8C\u306E\u30B0\u30E9\u30D5, \u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9\u756A\u53F7 -> \u5143\u306E\u30B0\u30E9\u30D5\u306E\u9802\
    \u70B9\u756A\u53F7 \u306E\u5BFE\u5FDC\u8868)\n    std::pair<Graph<T>, std::vector<int>>\
    \ get(std::vector<int> vs) {\n        if (vs.empty()) return {};\n\n        auto\
    \ comp = [&](int i, int j) -> bool { return rank[i] < rank[j]; };\n        std::sort(vs.begin(),\
    \ vs.end(), comp);\n        for (int i = 0, vslen = (int)(vs.size()); i + 1 <\
    \ vslen; i++) {\n            vs.emplace_back(lca.lca(vs[i], vs[i + 1]));\n   \
    \     }\n        std::sort(vs.begin(), vs.end(), comp);\n        vs.erase(unique(vs.begin(),\
    \ vs.end()), vs.end());\n\n        // Auxiliary Tree\n        Graph<T> aux(vs.size(),\
    \ false);\n        std::vector<int> rs;\n        rs.push_back(0);\n\n        //\
    \ i \u306F\u65B0\u3057\u3044\u9802\u70B9\u756A\u53F7, vs[i] \u306F\u3082\u3068\
    \u306E\u9802\u70B9\u756A\u53F7\n        // vs \u306F Auxiliary Tree \u306E\u884C\
    \u304D\u304C\u3051\u9806\u306B\u306A\u3063\u3066\u3044\u308B\u306E\u3067\u30EB\
    \u30FC\u30D7\u304C DFS \u306B\u306A\u3063\u3066\u3044\u308B\n        for (int\
    \ i = 1; i < (int)(vs.size()); i++) {\n            // LCA \u307E\u3067\u9061\u3063\
    \u3066\u304B\u3089\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n            int l = lca.lca(vs[rs.back()],\
    \ vs[i]);\n            while (vs[rs.back()] != l) rs.pop_back();\n           \
    \ aux.add_edge(rs.back(), i, depth[vs[i]] - depth[vs[rs.back()]]);\n         \
    \   rs.push_back(i);\n        }\n        aux.build();\n        return {aux, vs};\n\
    \    }\n};\n#line 7 \"verify/graph/auxiliary_tree.test.cpp\"\n\nint main() {\n\
    \    int N;\n    std::cin >> N;\n    auto g = read_graph<int>(N, N - 1);\n   \
    \ std::vector<int> A(N);\n    std::vector<std::vector<int>> vs(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        std::cin >> A[i];\n        A[i]--;\n        vs[A[i]].push_back(i);\n\
    \    }\n    AuxiliaryTree<int> aux(g);\n    long long ans = 0;\n    for (int col\
    \ = 0; col < N; col++) {\n        auto vec = vs[col];\n        if ((int)(vec.size())\
    \ == 0) continue;\n        auto [caux, label] = aux.get(vec);\n        const int\
    \ M = (int)(vec.size());\n        std::vector<int> dp((int)(label.size()));\n\
    \        auto rec = [&](auto f, int cur, int par) -> void {\n            dp[cur]\
    \ = (A[label[cur]] == col);\n            for (auto&& e : caux[cur]) {\n      \
    \          if (e.to == par) continue;\n                f(f, e.to, cur);\n    \
    \            dp[cur] += dp[e.to];\n                ans += (long long)e.cost *\
    \ dp[e.to] * (M - dp[e.to]);\n            }\n        };\n        rec(rec, 0, -1);\n\
    \    }\n    std::cout << ans << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc359/tasks/abc359_g\"\n\n\
    #include <iostream>\n\n#include \"graph/read_graph.hpp\"\n#include \"graph/auxiliary_tree.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    auto g = read_graph<int>(N,\
    \ N - 1);\n    std::vector<int> A(N);\n    std::vector<std::vector<int>> vs(N);\n\
    \    for (int i = 0; i < N; i++) {\n        std::cin >> A[i];\n        A[i]--;\n\
    \        vs[A[i]].push_back(i);\n    }\n    AuxiliaryTree<int> aux(g);\n    long\
    \ long ans = 0;\n    for (int col = 0; col < N; col++) {\n        auto vec = vs[col];\n\
    \        if ((int)(vec.size()) == 0) continue;\n        auto [caux, label] = aux.get(vec);\n\
    \        const int M = (int)(vec.size());\n        std::vector<int> dp((int)(label.size()));\n\
    \        auto rec = [&](auto f, int cur, int par) -> void {\n            dp[cur]\
    \ = (A[label[cur]] == col);\n            for (auto&& e : caux[cur]) {\n      \
    \          if (e.to == par) continue;\n                f(f, e.to, cur);\n    \
    \            dp[cur] += dp[e.to];\n                ans += (long long)e.cost *\
    \ dp[e.to] * (M - dp[e.to]);\n            }\n        };\n        rec(rec, 0, -1);\n\
    \    }\n    std::cout << ans << '\\n';\n    return 0;\n}"
  dependsOn:
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/auxiliary_tree.hpp
  - graph/lowest_common_ancestor.hpp
  isVerificationFile: true
  path: verify/graph/auxiliary_tree.test.cpp
  requiredBy: []
  timestamp: '2024-07-31 21:19:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/graph/auxiliary_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/auxiliary_tree.test.cpp
- /verify/verify/graph/auxiliary_tree.test.cpp.html
title: verify/graph/auxiliary_tree.test.cpp
---
