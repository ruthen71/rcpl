---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/auxiliary_tree.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n\ntemplate <class T> struct Edge {\n\
    \    int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const\
    \ int from, const int to, const T cost = T(1), const int id = -1) : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend std::ostream& operator<<(std::ostream&\
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
    \  std::vector<Edge<T>> edges;\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\
    \u7528\n    std::vector<int> start;\n    std::vector<Edge<T>> csr_edges;\n\n \
    \   Graph() : Graph(0) {}\n    Graph(const int n, const bool directed = false)\
    \ : n(n), m(0), is_build(false), start(n + 1, 0), is_directed(directed) {}\n\n\
    \    // \u8FBA\u3092\u8FFD\u52A0\u3057, \u305D\u306E\u8FBA\u304C\u4F55\u756A\u76EE\
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
    \ os, Graph<T>& g) {\n        // output format: {id: cost(from, to) = cost}\n\
    \        os << \"[\";\n        for (int i = 0; i < g.size(); i++) {\n        \
    \    os << \"[\";\n            for (int j = 0; j < g[i].size(); j++) {\n     \
    \           os << g[i][j];\n                if (j + 1 != g[i].size()) os << \"\
    , \";\n            }\n            os << \"]\";\n            if (i + 1 != g.size())\
    \ os << \", \";\n        }\n        return os << \"]\";\n    }\n};\n#line 2 \"\
    graph/lowest_common_ancestor.hpp\"\n\n#line 4 \"graph/lowest_common_ancestor.hpp\"\
    \n\ntemplate <class T> struct LowestCommonAncestor {\n    std::vector<int> depth;\n\
    \    std::vector<std::vector<int>> parent;\n    int n, LOG;\n\n    LowestCommonAncestor(Graph<T>&\
    \ g, int root = 0) : n((int)(g.size())), LOG(32 - __builtin_clz(n)) {\n      \
    \  depth.assign(n, 0);\n        parent.assign(LOG, std::vector<int>(n));\n   \
    \     auto dfs = [&](auto f, int cur, int par) -> void {\n            parent[0][cur]\
    \ = par;\n            for (auto& e : g[cur]) {\n                if (e.to == par)\
    \ continue;\n                depth[e.to] = depth[cur] + 1;\n                f(f,\
    \ e.to, cur);\n            }\n        };\n        dfs(dfs, root, -1);\n      \
    \  for (int k = 0; k + 1 < LOG; k++) {\n            for (int v = 0; v < n; v++)\
    \ {\n                parent[k + 1][v] = (parent[k][v] < 0 ? -1 : parent[k][parent[k][v]]);\n\
    \            }\n        }\n    }\n\n    int lca(int u, int v) {\n        assert((int)(depth.size())\
    \ == n);\n        if (depth[u] > depth[v]) std::swap(u, v);\n        // depth[u]\
    \ <= depth[v]\n        for (int k = 0; k < LOG; k++)\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) v = parent[k][v];\n\n        if (u == v) return u;\n \
    \       for (int k = LOG - 1; k >= 0; k--) {\n            if (parent[k][u] !=\
    \ parent[k][v]) {\n                u = parent[k][u];\n                v = parent[k][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    int level_ancestor(int\
    \ u, int d) {\n        assert((int)(depth.size()) == n);\n        if (depth[u]\
    \ < d) return -1;\n        for (int k = 0; k < LOG; k++)\n            if (d >>\
    \ k & 1) u = parent[k][u];\n        return u;\n    }\n\n    int distance(int u,\
    \ int v) {\n        int par = lca(u, v);\n        return depth[u] + depth[v] -\
    \ 2 * depth[par];\n    }\n};\n#line 5 \"graph/auxiliary_tree.hpp\"\n\ntemplate\
    \ <class T> struct AuxiliaryTree {\n    Graph<T> g;\n    int n, root;\n    std::vector<int>\
    \ preorder, rank;\n    std::vector<T> depth;\n    LowestCommonAncestor<T> lca;\n\
    \n    AuxiliaryTree(const Graph<T>& g, int root = 0) : n((int)(g.size())), root(root),\
    \ g(g), lca(g, root) {\n        // DFS\u3057\u3066\u884C\u304D\u304C\u3051\u9806\
    \u306B\u9802\u70B9\u3092\u4E26\u3079\u308B\n        depth.assign(n, T(0));\n \
    \       rank.resize(n);\n        auto dfs = [&](auto f, int cur, int par) -> void\
    \ {\n            preorder.push_back(cur);\n            for (auto& e : g[cur])\
    \ {\n                if (e.to == par) continue;\n                depth[e.to] =\
    \ depth[cur] + e.cost;\n                f(f, e.to, cur);\n            }\n    \
    \    };\n        dfs(dfs, root, -1);\n        for (int i = 0; i < n; i++) rank[preorder[i]]\
    \ = i;\n    }\n\n    // (\u5727\u7E2E\u5F8C\u306E\u30B0\u30E9\u30D5, \u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9\u756A\u53F7 -> \u5143\u306E\u30B0\u30E9\u30D5\u306E\u9802\
    \u70B9\u756A\u53F7 \u306E\u5BFE\u5FDC\u8868)\n    std::pair<Graph<T>, std::vector<int>>\
    \ get(std::vector<int> vs) {\n        if (vs.empty()) return {};\n        auto\
    \ comp = [&](int i, int j) -> bool { return rank[i] < rank[j]; };\n        std::sort(begin(vs),\
    \ end(vs), comp);\n        for (int i = 0, vslen = (int)(vs.size()); i + 1 < vslen;\
    \ i++) {\n            vs.emplace_back(lca.lca(vs[i], vs[i + 1]));\n        }\n\
    \        std::sort(begin(vs), end(vs), comp);\n        vs.erase(unique(begin(vs),\
    \ end(vs)), end(vs));\n        Graph<T> aux(vs.size());\n        std::vector<int>\
    \ rs;\n        rs.push_back(0);\n        for (int i = 1; i < (int)(vs.size());\
    \ i++) {\n            int l = lca.lca(vs[rs.back()], vs[i]);\n            while\
    \ (vs[rs.back()] != l) rs.pop_back();\n            aux[rs.back()].push_back(Edge(rs.back(),\
    \ i, depth[vs[i]] - depth[vs[rs.back()]], i - 1));\n            aux[i].push_back(Edge(i,\
    \ rs.back(), depth[vs[i]] - depth[vs[rs.back()]], i - 1));\n            rs.push_back(i);\n\
    \        }\n        return {aux, vs};\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n#include \"graph/lowest_common_ancestor.hpp\"\
    \n\ntemplate <class T> struct AuxiliaryTree {\n    Graph<T> g;\n    int n, root;\n\
    \    std::vector<int> preorder, rank;\n    std::vector<T> depth;\n    LowestCommonAncestor<T>\
    \ lca;\n\n    AuxiliaryTree(const Graph<T>& g, int root = 0) : n((int)(g.size())),\
    \ root(root), g(g), lca(g, root) {\n        // DFS\u3057\u3066\u884C\u304D\u304C\
    \u3051\u9806\u306B\u9802\u70B9\u3092\u4E26\u3079\u308B\n        depth.assign(n,\
    \ T(0));\n        rank.resize(n);\n        auto dfs = [&](auto f, int cur, int\
    \ par) -> void {\n            preorder.push_back(cur);\n            for (auto&\
    \ e : g[cur]) {\n                if (e.to == par) continue;\n                depth[e.to]\
    \ = depth[cur] + e.cost;\n                f(f, e.to, cur);\n            }\n  \
    \      };\n        dfs(dfs, root, -1);\n        for (int i = 0; i < n; i++) rank[preorder[i]]\
    \ = i;\n    }\n\n    // (\u5727\u7E2E\u5F8C\u306E\u30B0\u30E9\u30D5, \u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9\u756A\u53F7 -> \u5143\u306E\u30B0\u30E9\u30D5\u306E\u9802\
    \u70B9\u756A\u53F7 \u306E\u5BFE\u5FDC\u8868)\n    std::pair<Graph<T>, std::vector<int>>\
    \ get(std::vector<int> vs) {\n        if (vs.empty()) return {};\n        auto\
    \ comp = [&](int i, int j) -> bool { return rank[i] < rank[j]; };\n        std::sort(begin(vs),\
    \ end(vs), comp);\n        for (int i = 0, vslen = (int)(vs.size()); i + 1 < vslen;\
    \ i++) {\n            vs.emplace_back(lca.lca(vs[i], vs[i + 1]));\n        }\n\
    \        std::sort(begin(vs), end(vs), comp);\n        vs.erase(unique(begin(vs),\
    \ end(vs)), end(vs));\n        Graph<T> aux(vs.size());\n        std::vector<int>\
    \ rs;\n        rs.push_back(0);\n        for (int i = 1; i < (int)(vs.size());\
    \ i++) {\n            int l = lca.lca(vs[rs.back()], vs[i]);\n            while\
    \ (vs[rs.back()] != l) rs.pop_back();\n            aux[rs.back()].push_back(Edge(rs.back(),\
    \ i, depth[vs[i]] - depth[vs[rs.back()]], i - 1));\n            aux[i].push_back(Edge(i,\
    \ rs.back(), depth[vs[i]] - depth[vs[rs.back()]], i - 1));\n            rs.push_back(i);\n\
    \        }\n        return {aux, vs};\n    }\n};"
  dependsOn:
  - graph/graph_template.hpp
  - graph/lowest_common_ancestor.hpp
  isVerificationFile: false
  path: graph/auxiliary_tree.hpp
  requiredBy: []
  timestamp: '2024-07-28 20:11:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/auxiliary_tree.hpp
layout: document
title: "Auxiliary Tree (\u865A\u6811)"
---

Virtual Tree とも呼ばれる

## 使い方

```cpp
Graph<T> g; // 木
AuxiliaryTree<T> aux(g, root);
std::vector<int> vs; // 頂点集合
auto [caux, label] = aux.get(vs);
```

圧縮後の木は頂点番号が `0` から `圧縮後の木の頂点数 - 1` になっている

圧縮後の木の頂点 `v` に対応するもとの木における頂点番号を知りたいときには `label[v]` を呼べば良い

圧縮後の木の辺 `u - v` の重みは、もとの木における `u - v` パスの辺の重みの総和と等しい

## 使用例

- [ABC359 G](https://atcoder.jp/contests/abc359/submissions/54857051)

## 参考文献

- [LCAをベースに構築するAuxiliary Treeのメモ](https://smijake3.hatenablog.com/entry/2019/09/15/200200)
- [AtCoder Beginner Contest 340 G - Leaf Color 解説](https://atcoder.jp/contests/abc340/editorial/9249)
