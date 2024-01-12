---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: "Low Link (\u95A2\u7BC0\u70B9\u30FB\u6A4B)"
  - icon: ':heavy_check_mark:'
    path: graph/read_graph.hpp
    title: graph/read_graph.hpp
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
  bundledCode: "#line 1 \"verify/aoj_grl/aoj_grl_3_a.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Edge<T> &e) {\n        // output format:\
    \ \"{ id : from -> to, cost }\"\n        return os << \"{ \" << e.id << \" : \"\
    \ << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\n\
    template <class T> using Edges = std::vector<Edge<T>>;\ntemplate <class T> using\
    \ Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"graph/read_graph.hpp\"\
    \n\ntemplate <class T> Graph<T> read_graph(int N, int M, const bool weight = false,\
    \ const bool directed = false, const int offset = 1) {\n    Graph<T> G(N);\n \
    \   for (int i = 0; i < M; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        a -= offset, b -= offset;\n        if (weight) {\n            T\
    \ c;\n            std::cin >> c;\n            if (!directed) G[b].push_back(Edge(b,\
    \ a, c, i));\n            G[a].push_back(Edge(a, b, c, i));\n        } else {\n\
    \            // c = 1\n            if (!directed) G[b].push_back(Edge(b, a, T(1),\
    \ i));\n            G[a].push_back(Edge(a, b, T(1), i));\n        }\n    }\n \
    \   return G;\n}\n#line 2 \"graph/low_link.hpp\"\n\n#line 4 \"graph/low_link.hpp\"\
    \n\ntemplate <class T> struct LowLink {\n    int n;\n    std::vector<int> ord,\
    \ low, articulation;\n    std::vector<std::pair<int, int>> bridge;  // edges {u,\
    \ v} (u < v)\n\n    LowLink(const Graph<T> &g) : n(int(g.size())), ord(n, -1),\
    \ low(n, -1) {\n        int k = 0;\n        auto dfs = [&](auto f, int cur, int\
    \ par) -> void {\n            low[cur] = ord[cur] = k;\n            k++;\n   \
    \         int cnt = 0;\n            bool is_articulation = false;\n          \
    \  for (auto &e : g[cur]) {\n                if (ord[e.to] == -1) {\n        \
    \            cnt++;\n                    f(f, e.to, cur);\n                  \
    \  low[cur] = std::min(low[cur], low[e.to]);\n                    is_articulation\
    \ |= (par != -1) && (ord[cur] <= low[e.to]);\n                    if (ord[cur]\
    \ < low[e.to]) {\n                        bridge.emplace_back(std::minmax(cur,\
    \ e.to));\n                    }\n                } else if (e.to != par) {\n\
    \                    low[cur] = std::min(low[cur], ord[e.to]);\n             \
    \   }\n            }\n            is_articulation |= par == -1 && cnt > 1;\n \
    \           if (is_articulation) articulation.push_back(cur);\n            return;\n\
    \        };\n        for (int i = 0; i < n; i++) {\n            if (ord[i] ==\
    \ -1) {\n                dfs(dfs, i, -1);\n            }\n        }\n    }\n};\n\
    #line 7 \"verify/aoj_grl/aoj_grl_3_a.test.cpp\"\n\nint main() {\n    int N, M;\n\
    \    std::cin >> N >> M;\n    auto G = read_graph<int>(N, M, 0, 0, 0);\n    LowLink\
    \ llink(G);\n    auto ans = llink.articulation;\n    std::sort(ans.begin(), ans.end());\n\
    \    for (auto& v : ans) std::cout << v << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"graph/read_graph.hpp\"\n#include \"\
    graph/low_link.hpp\"\n\nint main() {\n    int N, M;\n    std::cin >> N >> M;\n\
    \    auto G = read_graph<int>(N, M, 0, 0, 0);\n    LowLink llink(G);\n    auto\
    \ ans = llink.articulation;\n    std::sort(ans.begin(), ans.end());\n    for (auto&\
    \ v : ans) std::cout << v << '\\n';\n    return 0;\n}"
  dependsOn:
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/low_link.hpp
  isVerificationFile: true
  path: verify/aoj_grl/aoj_grl_3_a.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 19:15:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_grl/aoj_grl_3_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_grl/aoj_grl_3_a.test.cpp
- /verify/verify/aoj_grl/aoj_grl_3_a.test.cpp.html
title: verify/aoj_grl/aoj_grl_3_a.test.cpp
---
