---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/tree_diameter.hpp
    title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_tree/lc_tree_diameter.test.cpp
    title: verify/lc_tree/lc_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/template.hpp\"\n\ntemplate <class T> struct edge\
    \ {\n    int from, to;\n    T cost;\n    int id;\n\n    edge(int from, int to,\
    \ T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const edge<T> &e) {\n    \
    \    // { id : from -> to, cost }\n        return os << \"{ \" << e.id << \" :\
    \ \" << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\
    \ntemplate <class T, bool directed = false> struct graph {\n    int N, M;\n  \
    \  using cost_type = T;\n    using edge_type = edge<T>;\n    std::vector<std::vector<edge_type>>\
    \ G;\n\n    graph() : N(0), M(0) {}\n    graph(int N) : N(N), M(0), G(N) {}\n\n\
    \    constexpr bool is_directed() { return directed; }\n\n    size_t size() const\
    \ { return G.size(); }\n\n    void read_tree(bool weight = false, int offset =\
    \ 1) { read_graph(N - 1, weight, offset); }\n\n    void read_graph(int _M, bool\
    \ weight = false, int offset = 1) {\n        for (int i = 0; i < _M; i++) {\n\
    \            int a, b;\n            std::cin >> a >> b;\n            a -= offset,\
    \ b -= offset;\n            if (weight) {\n                T c;\n            \
    \    std::cin >> c;\n                add_edge(a, b, c);\n            } else {\n\
    \                add_edge(a, b);\n            }\n        }\n    }\n\n    void\
    \ add_edge(const int &a, const int &b, T cost = 1) {\n        assert(0 <= a and\
    \ a < N and 0 <= b and b < N);\n        if (!directed) G[b].push_back(edge_type(b,\
    \ a, cost, M));\n        G[a].push_back(edge_type(a, b, cost, M++));\n    }\n\n\
    \    inline std::vector<edge_type> &operator[](const int &k) { return G[k]; }\n\
    \n    inline const std::vector<edge_type> &operator[](const int &k) const { return\
    \ G[k]; }\n\n    friend std::ostream &operator<<(std::ostream &os, const graph<T>\
    \ &G) {\n        os << \"V: \" << G.N << '\\n';\n        os << \"E: \" << G.M\
    \ << '\\n';\n        for (int v = 0; v < G.N; v++) {\n            os << \"G[\"\
    \ << v << \"] = \";\n            os << \"[ \";\n            for (auto &e : G[v])\
    \ os << e << \" \";\n            os << \"]\\n\";\n        }\n        return os;\n\
    \    }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct edge {\n    int from, to;\n   \
    \ T cost;\n    int id;\n\n    edge(int from, int to, T cost = 1, int id = -1)\
    \ : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const edge<T> &e) {\n        // { id : from -> to, cost }\n        return\
    \ os << \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T, bool directed = false> struct graph\
    \ {\n    int N, M;\n    using cost_type = T;\n    using edge_type = edge<T>;\n\
    \    std::vector<std::vector<edge_type>> G;\n\n    graph() : N(0), M(0) {}\n \
    \   graph(int N) : N(N), M(0), G(N) {}\n\n    constexpr bool is_directed() { return\
    \ directed; }\n\n    size_t size() const { return G.size(); }\n\n    void read_tree(bool\
    \ weight = false, int offset = 1) { read_graph(N - 1, weight, offset); }\n\n \
    \   void read_graph(int _M, bool weight = false, int offset = 1) {\n        for\
    \ (int i = 0; i < _M; i++) {\n            int a, b;\n            std::cin >> a\
    \ >> b;\n            a -= offset, b -= offset;\n            if (weight) {\n  \
    \              T c;\n                std::cin >> c;\n                add_edge(a,\
    \ b, c);\n            } else {\n                add_edge(a, b);\n            }\n\
    \        }\n    }\n\n    void add_edge(const int &a, const int &b, T cost = 1)\
    \ {\n        assert(0 <= a and a < N and 0 <= b and b < N);\n        if (!directed)\
    \ G[b].push_back(edge_type(b, a, cost, M));\n        G[a].push_back(edge_type(a,\
    \ b, cost, M++));\n    }\n\n    inline std::vector<edge_type> &operator[](const\
    \ int &k) { return G[k]; }\n\n    inline const std::vector<edge_type> &operator[](const\
    \ int &k) const { return G[k]; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const graph<T> &G) {\n        os << \"V: \" << G.N << '\\n';\n        os\
    \ << \"E: \" << G.M << '\\n';\n        for (int v = 0; v < G.N; v++) {\n     \
    \       os << \"G[\" << v << \"] = \";\n            os << \"[ \";\n          \
    \  for (auto &e : G[v]) os << e << \" \";\n            os << \"]\\n\";\n     \
    \   }\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/template.hpp
  requiredBy:
  - src/graph/tree_diameter.hpp
  timestamp: '2022-09-04 19:21:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_tree/lc_tree_diameter.test.cpp
documentation_of: src/graph/template.hpp
layout: document
redirect_from:
- /library/src/graph/template.hpp
- /library/src/graph/template.hpp.html
title: src/graph/template.hpp
---
