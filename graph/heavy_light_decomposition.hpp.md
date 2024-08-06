---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/heavy_light_decomposition.test.cpp
    title: verify/graph/heavy_light_decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/heavy_light_decomposition.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n\ntemplate <class T> struct Edge {\n\
    \    int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const\
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
    \    }\n};\n#line 4 \"graph/heavy_light_decomposition.hpp\"\n\n// Heavy-Light\
    \ Decomposition\n// \u30D1\u30B9\u30AF\u30A8\u30EA\u306B\u5BFE\u5FDC\n// \u8FBA\
    \u306E\u4E26\u3079\u66FF\u3048\u3092\u5185\u90E8\u3067\u884C\u3046\u306E\u3067\
    \u6CE8\u610F\ntemplate <class T> struct HeavyLightDecomposition {\n    int n;\n\
    \    std::vector<int> subsize;   // subsize[v] = v \u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\n    std::vector<int> vertices;  //\
    \ Heavy-Edge \u304B\u3089\u512A\u5148\u7684\u306B DFS \u3057\u305F\u3068\u304D\
    \u306E\u9802\u70B9\u3092\u8A2A\u554F\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\
    \n    std::vector<int> parent;    // \u89AA\u306E\u9802\u70B9\n    std::vector<int>\
    \ pathtop;   // \u5404\u9802\u70B9\u3092\u542B\u3080\u30D1\u30B9\u4E0A\u306E\u6700\
    \u3082\u7956\u5148\u306E\u9802\u70B9\n    std::vector<int> indexes;   // \u5404\
    \u9802\u70B9\u304C vertives \u3067\u4F55\u756A\u76EE\u306B\u767B\u5834\u3059\u308B\
    \u304B\n\n    HeavyLightDecomposition(Graph<T>& g, const int root = 0) : n((int)(g.size())),\
    \ subsize(n, 1), parent(n, -1), pathtop(n, -1), indexes(n, -1) {\n        // \u90E8\
    \u5206\u6728\u306E\u30B5\u30A4\u30BA\u3092\u8A08\u7B97\n        auto dfs_size\
    \ = [&](auto f, int cur, int par) -> void {\n            // \u89AA\u65B9\u5411\
    \u3078\u306E\u8FBA\u3092\u672B\u5C3E\u306B\u79FB\u52D5\n            for (int i\
    \ = 0; i < (int)(g[cur].size()); i++) {\n                if (g[cur][i].to == par)\
    \ {\n                    std::swap(g[cur][i], g[cur][(int)(g[cur].size()) - 1]);\n\
    \                    break;\n                }\n            }\n            //\
    \ \u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u304C\u6700\u5927\u306E\u3082\u306E\
    \u3092\u5148\u982D\u306B\u79FB\u52D5\n            for (auto&& e : g[cur]) {\n\
    \                if (e.to == par) continue;\n                f(f, e.to, cur);\n\
    \                subsize[cur] += subsize[e.to];\n                if (subsize[e.to]\
    \ > subsize[g[cur][0].to]) {\n                    std::swap(e, g[cur][0]);\n \
    \               }\n            }\n        };\n        dfs_size(dfs_size, root,\
    \ -1);\n\n        // \u9802\u70B9\u3092\u4E26\u3079\u308B\n        auto dfs_hld\
    \ = [&](auto f, int cur, int par, int top) -> void {\n            parent[cur]\
    \ = par;\n            pathtop[cur] = top;\n            indexes[cur] = (int)(vertices.size());\n\
    \            vertices.emplace_back(cur);\n\n            for (int i = 0; i < (int)(g[cur].size());\
    \ i++) {\n                if (g[cur][i].to == par) continue;\n               \
    \ // top \u306F heavy-edge \u306B\u5BFE\u3057\u3066\u306E\u307F\u5F15\u304D\u7D99\
    \u304C\u308C\u308B\n                f(f, g[cur][i].to, cur, (i == 0 ? top : g[cur][i].to));\n\
    \            }\n        };\n        dfs_hld(dfs_hld, root, -1, root);\n    }\n\
    \n    int lca(int u, int v) {\n        // \u540C\u3058\u30D1\u30B9\u307E\u3067\
    \u4E0A\u304C\u308B\n        while (pathtop[u] != pathtop[v]) {\n            if\
    \ (indexes[u] > indexes[v]) {\n                u = parent[pathtop[u]];\n     \
    \       } else {\n                v = parent[pathtop[v]];\n            }\n   \
    \     }\n        if (indexes[u] > indexes[v]) std::swap(u, v);\n        return\
    \ u;\n    }\n\n    // u - v \u30D1\u30B9\u306B\u64CD\u4F5C\u3092\u884C\u3046\u3068\
    \u304D\u306B\u4F7F\u3046\u533A\u9593\u3092\u5217\u6319\u3059\u308B\n    std::vector<std::pair<int,\
    \ int>> query(int u, int v) {\n        std::vector<std::pair<int, int>> res;\n\
    \        while (pathtop[u] != pathtop[v]) {\n            // \u8FBA\u306B\u5BFE\
    \u3059\u308B\u64CD\u4F5C\u306A\u306E\u3067 pathtop[u] \u304B\u3089 parent[pathtop[u]]\
    \ \u306B\u884C\u304F\u8FBA\u3082\u533A\u9593\u306B\u52A0\u3048\u308B\n       \
    \     if (indexes[u] > indexes[v]) {\n                res.emplace_back(indexes[pathtop[u]]\
    \ - 1, indexes[u]);\n                u = parent[pathtop[u]];\n            } else\
    \ {\n                res.emplace_back(indexes[pathtop[v]] - 1, indexes[v]);\n\
    \                v = parent[pathtop[v]];\n            }\n        }\n        if\
    \ (indexes[u] > indexes[v]) std::swap(u, v);\n        res.emplace_back(indexes[u],\
    \ indexes[v]);\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph/graph_template.hpp\"\n\n// Heavy-Light Decomposition\n\
    // \u30D1\u30B9\u30AF\u30A8\u30EA\u306B\u5BFE\u5FDC\n// \u8FBA\u306E\u4E26\u3079\
    \u66FF\u3048\u3092\u5185\u90E8\u3067\u884C\u3046\u306E\u3067\u6CE8\u610F\ntemplate\
    \ <class T> struct HeavyLightDecomposition {\n    int n;\n    std::vector<int>\
    \ subsize;   // subsize[v] = v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\
    \u306E\u30B5\u30A4\u30BA\n    std::vector<int> vertices;  // Heavy-Edge \u304B\
    \u3089\u512A\u5148\u7684\u306B DFS \u3057\u305F\u3068\u304D\u306E\u9802\u70B9\u3092\
    \u8A2A\u554F\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\n    std::vector<int> parent;\
    \    // \u89AA\u306E\u9802\u70B9\n    std::vector<int> pathtop;   // \u5404\u9802\
    \u70B9\u3092\u542B\u3080\u30D1\u30B9\u4E0A\u306E\u6700\u3082\u7956\u5148\u306E\
    \u9802\u70B9\n    std::vector<int> indexes;   // \u5404\u9802\u70B9\u304C vertives\
    \ \u3067\u4F55\u756A\u76EE\u306B\u767B\u5834\u3059\u308B\u304B\n\n    HeavyLightDecomposition(Graph<T>&\
    \ g, const int root = 0) : n((int)(g.size())), subsize(n, 1), parent(n, -1), pathtop(n,\
    \ -1), indexes(n, -1) {\n        // \u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\
    \u3092\u8A08\u7B97\n        auto dfs_size = [&](auto f, int cur, int par) -> void\
    \ {\n            // \u89AA\u65B9\u5411\u3078\u306E\u8FBA\u3092\u672B\u5C3E\u306B\
    \u79FB\u52D5\n            for (int i = 0; i < (int)(g[cur].size()); i++) {\n \
    \               if (g[cur][i].to == par) {\n                    std::swap(g[cur][i],\
    \ g[cur][(int)(g[cur].size()) - 1]);\n                    break;\n           \
    \     }\n            }\n            // \u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\
    \u304C\u6700\u5927\u306E\u3082\u306E\u3092\u5148\u982D\u306B\u79FB\u52D5\n   \
    \         for (auto&& e : g[cur]) {\n                if (e.to == par) continue;\n\
    \                f(f, e.to, cur);\n                subsize[cur] += subsize[e.to];\n\
    \                if (subsize[e.to] > subsize[g[cur][0].to]) {\n              \
    \      std::swap(e, g[cur][0]);\n                }\n            }\n        };\n\
    \        dfs_size(dfs_size, root, -1);\n\n        // \u9802\u70B9\u3092\u4E26\u3079\
    \u308B\n        auto dfs_hld = [&](auto f, int cur, int par, int top) -> void\
    \ {\n            parent[cur] = par;\n            pathtop[cur] = top;\n       \
    \     indexes[cur] = (int)(vertices.size());\n            vertices.emplace_back(cur);\n\
    \n            for (int i = 0; i < (int)(g[cur].size()); i++) {\n             \
    \   if (g[cur][i].to == par) continue;\n                // top \u306F heavy-edge\
    \ \u306B\u5BFE\u3057\u3066\u306E\u307F\u5F15\u304D\u7D99\u304C\u308C\u308B\n \
    \               f(f, g[cur][i].to, cur, (i == 0 ? top : g[cur][i].to));\n    \
    \        }\n        };\n        dfs_hld(dfs_hld, root, -1, root);\n    }\n\n \
    \   int lca(int u, int v) {\n        // \u540C\u3058\u30D1\u30B9\u307E\u3067\u4E0A\
    \u304C\u308B\n        while (pathtop[u] != pathtop[v]) {\n            if (indexes[u]\
    \ > indexes[v]) {\n                u = parent[pathtop[u]];\n            } else\
    \ {\n                v = parent[pathtop[v]];\n            }\n        }\n     \
    \   if (indexes[u] > indexes[v]) std::swap(u, v);\n        return u;\n    }\n\n\
    \    // u - v \u30D1\u30B9\u306B\u64CD\u4F5C\u3092\u884C\u3046\u3068\u304D\u306B\
    \u4F7F\u3046\u533A\u9593\u3092\u5217\u6319\u3059\u308B\n    std::vector<std::pair<int,\
    \ int>> query(int u, int v) {\n        std::vector<std::pair<int, int>> res;\n\
    \        while (pathtop[u] != pathtop[v]) {\n            // \u8FBA\u306B\u5BFE\
    \u3059\u308B\u64CD\u4F5C\u306A\u306E\u3067 pathtop[u] \u304B\u3089 parent[pathtop[u]]\
    \ \u306B\u884C\u304F\u8FBA\u3082\u533A\u9593\u306B\u52A0\u3048\u308B\n       \
    \     if (indexes[u] > indexes[v]) {\n                res.emplace_back(indexes[pathtop[u]]\
    \ - 1, indexes[u]);\n                u = parent[pathtop[u]];\n            } else\
    \ {\n                res.emplace_back(indexes[pathtop[v]] - 1, indexes[v]);\n\
    \                v = parent[pathtop[v]];\n            }\n        }\n        if\
    \ (indexes[u] > indexes[v]) std::swap(u, v);\n        res.emplace_back(indexes[u],\
    \ indexes[v]);\n        return res;\n    }\n};\n"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2024-08-06 17:45:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/heavy_light_decomposition.test.cpp
documentation_of: graph/heavy_light_decomposition.hpp
layout: document
title: "Heavy-Light Decomposition (\u91CD\u8EFD\u5206\u89E3)"
---

HL分解とも呼ばれる

## 使い方

```cpp
Graph<int> g;
int root;
HeavyLightDecomposition hld(g, root);
auto intervals = hld.query(u, v);   // u - v パスに対応する区間を列挙 (長さ 0 の場合もあり)
```

## 参考文献
- [【図解】木のパスに関するクエリは HL 分解！ その仕組みと実装を図で理解する｜Heavy-Light Decomposition](https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3)
- [My algorithm, HL Decomposition](https://kopricky.github.io/code/DataStructure_OnGraph/hl_decomposition.html)
- [math314のブログ, Heavy-Light Decomposition](https://math314.hateblo.jp/entry/2014/06/24/220107)