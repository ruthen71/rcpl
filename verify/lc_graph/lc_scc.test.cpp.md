---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/read_graph.hpp
    title: graph/read_graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
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
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"graph/graph_template.hpp\"\n\ntemplate\
    \ <class T> struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\n   \
    \ Edge() = default;\n    Edge(int from, int to, T cost = 1, int id = -1) : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Edge<T> &e) {\n        // output format: \"{ id : from -> to, cost\
    \ }\"\n        return os << \"{ \" << e.id << \" : \" << e.from << \" -> \" <<\
    \ e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using Edges\
    \ = std::vector<Edge<T>>;\ntemplate <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n\
    #line 2 \"graph/read_graph.hpp\"\n\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate\
    \ <class T> Graph<T> read_graph(int N, int M, const bool weight = false, const\
    \ bool directed = false, const int offset = 1) {\n    Graph<T> G(N);\n    for\
    \ (int i = 0; i < M; i++) {\n        int a, b;\n        std::cin >> a >> b;\n\
    \        a -= offset, b -= offset;\n        if (weight) {\n            T c;\n\
    \            std::cin >> c;\n            if (!directed) G[b].push_back(Edge(b,\
    \ a, c, i));\n            G[a].push_back(Edge(a, b, c, i));\n        } else {\n\
    \            // c = 1\n            if (!directed) G[b].push_back(Edge(b, a, T(1),\
    \ i));\n            G[a].push_back(Edge(a, b, T(1), i));\n        }\n    }\n \
    \   return G;\n}\n#line 2 \"graph/strongly_connected_component.hpp\"\n\n#line\
    \ 4 \"graph/strongly_connected_component.hpp\"\n\ntemplate <class T> std::vector<std::vector<int>>\
    \ strongly_connected_component(Graph<T>& g) {\n    int n = int(g.size());\n  \
    \  int now_ord = 0, group_num = 0;\n    std::vector<int> visited, low(n), ord(n,\
    \ -1), ids(n);\n    visited.reserve(n);\n    auto dfs = [&](auto f, int cur) ->\
    \ void {\n        low[cur] = ord[cur] = now_ord++;\n        visited.push_back(cur);\n\
    \        for (auto& e : g[cur]) {\n            if (ord[e.to] == -1) {\n      \
    \          f(f, e.to);\n                low[cur] = std::min(low[cur], low[e.to]);\n\
    \            } else {\n                low[cur] = std::min(low[cur], ord[e.to]);\n\
    \            }\n        }\n        if (low[cur] == ord[cur]) {\n            while\
    \ (true) {\n                int u = visited.back();\n                visited.pop_back();\n\
    \                ord[u] = n;\n                ids[u] = group_num;\n          \
    \      if (u == cur) break;\n            }\n            group_num++;\n       \
    \ }\n    };\n    for (int i = 0; i < n; i++) {\n        if (ord[i] == -1) dfs(dfs,\
    \ i);\n    }\n    for (auto& x : ids) {\n        x = group_num - 1 - x;\n    }\n\
    \    std::vector<int> counts(group_num);\n    for (auto& x : ids) counts[x]++;\n\
    \    std::vector<std::vector<int>> groups(group_num);\n    for (int i = 0; i <\
    \ group_num; i++) {\n        groups[i].reserve(counts[i]);\n    }\n    for (int\
    \ i = 0; i < n; i++) {\n        groups[ids[i]].push_back(i);\n    }\n    return\
    \ groups;\n}\n#line 8 \"verify/lc_graph/lc_scc.test.cpp\"\n\nint main() {\n  \
    \  int N, M;\n    std::cin >> N >> M;\n    auto G = read_graph<int>(N, M, false,\
    \ true, 0);\n    auto scc = strongly_connected_component(G);\n    std::cout <<\
    \ scc.size() << '\\n';\n    for (auto& vec : scc) {\n        std::cout << vec.size();\n\
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
  timestamp: '2023-05-30 23:26:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lc_graph/lc_scc.test.cpp
layout: document
redirect_from:
- /verify/verify/lc_graph/lc_scc.test.cpp
- /verify/verify/lc_graph/lc_scc.test.cpp.html
title: verify/lc_graph/lc_scc.test.cpp
---
