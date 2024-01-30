---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':question:'
    path: graph/read_graph.hpp
    title: graph/read_graph.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/lc_graph/lc_scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"graph/graph_template.hpp\"\n\n#line\
    \ 4 \"graph/graph_template.hpp\"\ntemplate <class T> struct Edge {\n    int from,\
    \ to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int from, int\
    \ to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}\n\n\
    \    friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {\n \
    \       // output format: \"{ id : from -> to, cost }\"\n        return os <<\
    \ \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 2 \"\
    graph/read_graph.hpp\"\n\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate <class\
    \ T> Graph<T> read_graph(const int n, const int m, const bool weight = false,\
    \ const bool directed = false, const int offset = 1) {\n    Graph<T> g(n);\n \
    \   for (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        a -= offset, b -= offset;\n        if (weight) {\n            T\
    \ c;\n            std::cin >> c;\n            if (!directed) g[b].push_back(Edge(b,\
    \ a, c, i));\n            g[a].push_back(Edge(a, b, c, i));\n        } else {\n\
    \            // c = 1\n            if (!directed) g[b].push_back(Edge(b, a, T(1),\
    \ i));\n            g[a].push_back(Edge(a, b, T(1), i));\n        }\n    }\n \
    \   return g;\n}\n\ntemplate <class T> Graph<T> read_parent(const int n, const\
    \ bool weight = false, const bool directed = false, const int offset = 1) {\n\
    \    Graph<T> g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n     \
    \   std::cin >> p;\n        p -= offset;\n        if (weight) {\n            T\
    \ c;\n            std::cin >> c;\n            if (!directed) g[i].push_back(Edge(i,\
    \ p, c, i - 1));\n            g[p].push_back(Edge(p, i, c, i - 1));\n        }\
    \ else {\n            // c = 1\n            if (!directed) g[i].push_back(Edge(i,\
    \ p, T(1), i - 1));\n            g[p].push_back(Edge(p, i, T(1), i - 1));\n  \
    \      }\n    }\n    return g;\n}\n\nstd::tuple<Graph<int>, std::vector<std::vector<int>>,\
    \ std::vector<std::pair<int, int>>> read_grid(const int h, const int w, std::string\
    \ rel = \".#\") {\n    std::vector<std::string> s(h);\n    std::vector id(h, std::vector<int>(w,\
    \ -1));\n    std::vector<std::pair<int, int>> loc;\n    int n = 0;\n    for (int\
    \ i = 0; i < h; i++) {\n        std::cin >> s[i];\n        for (int j = 0; j <\
    \ w; j++) {\n            if (s[i][j] == rel[1]) {\n                id[i][j] =\
    \ n++;\n                loc.emplace_back(i, j);\n            }\n        }\n  \
    \  }\n    int m = 0;\n    Graph<int> g(n);\n    for (int i = 0; i < h; i++) {\n\
    \        for (int j = 0; j < w; j++) {\n            if (s[i][j] == rel[1]) {\n\
    \                if (i + 1 < h and s[i + 1][j] == rel[1]) {\n                \
    \    g[id[i][j]].push_back(Edge(id[i][j], id[i + 1][j], 1, m));\n            \
    \        g[id[i + 1][j]].push_back(Edge(id[i + 1][j], id[i][j], 1, m++));\n  \
    \              }\n                if (j + 1 < w and s[i][j + 1] == rel[1]) {\n\
    \                    g[id[i][j]].push_back(Edge(id[i][j], id[i][j + 1], 1, m));\n\
    \                    g[id[i][j + 1]].push_back(Edge(id[i][j + 1], id[i][j], 1,\
    \ m++));\n                }\n            }\n        }\n    }\n    return {g, id,\
    \ loc};\n}\n#line 2 \"graph/strongly_connected_component.hpp\"\n\n#line 4 \"graph/strongly_connected_component.hpp\"\
    \n\ntemplate <class T> std::vector<std::vector<int>> strongly_connected_component(Graph<T>&\
    \ g) {\n    int n = int(g.size());\n    int now_ord = 0, group_num = 0;\n    std::vector<int>\
    \ visited, low(n), ord(n, -1), ids(n);\n    visited.reserve(n);\n    auto dfs\
    \ = [&](auto f, int cur) -> void {\n        low[cur] = ord[cur] = now_ord++;\n\
    \        visited.push_back(cur);\n        for (auto& e : g[cur]) {\n         \
    \   if (ord[e.to] == -1) {\n                f(f, e.to);\n                low[cur]\
    \ = std::min(low[cur], low[e.to]);\n            } else {\n                low[cur]\
    \ = std::min(low[cur], ord[e.to]);\n            }\n        }\n        if (low[cur]\
    \ == ord[cur]) {\n            while (true) {\n                int u = visited.back();\n\
    \                visited.pop_back();\n                ord[u] = n;\n          \
    \      ids[u] = group_num;\n                if (u == cur) break;\n           \
    \ }\n            group_num++;\n        }\n    };\n    for (int i = 0; i < n; i++)\
    \ {\n        if (ord[i] == -1) dfs(dfs, i);\n    }\n    for (auto& x : ids) {\n\
    \        x = group_num - 1 - x;\n    }\n    std::vector<int> counts(group_num);\n\
    \    for (auto& x : ids) counts[x]++;\n    std::vector<std::vector<int>> groups(group_num);\n\
    \    for (int i = 0; i < group_num; i++) {\n        groups[i].reserve(counts[i]);\n\
    \    }\n    for (int i = 0; i < n; i++) {\n        groups[ids[i]].push_back(i);\n\
    \    }\n    return groups;\n}\n#line 8 \"verify/lc_graph/lc_scc.test.cpp\"\n\n\
    int main() {\n    int N, M;\n    std::cin >> N >> M;\n    auto G = read_graph<int>(N,\
    \ M, false, true, 0);\n    auto scc = strongly_connected_component(G);\n    std::cout\
    \ << scc.size() << '\\n';\n    for (auto& vec : scc) {\n        std::cout << vec.size();\n\
    \        for (auto& vi : vec) std::cout << ' ' << vi;\n        std::cout << '\\\
    n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n\
    \n#include \"graph/graph_template.hpp\"\n#include \"graph/read_graph.hpp\"\n#include\
    \ \"graph/strongly_connected_component.hpp\"\n\nint main() {\n    int N, M;\n\
    \    std::cin >> N >> M;\n    auto G = read_graph<int>(N, M, false, true, 0);\n\
    \    auto scc = strongly_connected_component(G);\n    std::cout << scc.size()\
    \ << '\\n';\n    for (auto& vec : scc) {\n        std::cout << vec.size();\n \
    \       for (auto& vi : vec) std::cout << ' ' << vi;\n        std::cout << '\\\
    n';\n    }\n    return 0;\n}"
  dependsOn:
  - graph/graph_template.hpp
  - graph/read_graph.hpp
  - graph/strongly_connected_component.hpp
  isVerificationFile: true
  path: verify/lc_graph/lc_scc.test.cpp
  requiredBy: []
  timestamp: '2024-01-25 10:46:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_graph/lc_scc.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_graph/lc_scc.test.cpp
- /verify/verify/lc_graph/lc_scc.test.cpp.html
title: verify/lc_graph/lc_scc.test.cpp
---
