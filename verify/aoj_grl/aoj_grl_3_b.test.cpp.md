---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':x:'
    path: graph/low_link.hpp
    title: "Low Link (\u95A2\u7BC0\u70B9\u30FB\u6A4B)"
  - icon: ':question:'
    path: graph/read_graph.hpp
    title: graph/read_graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"verify/aoj_grl/aoj_grl_3_b.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id\
    \ = -1) : from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Edge<T> &e) {\n        // output format:\
    \ \"{ id : from -> to, cost }\"\n        return os << \"{ \" << e.id << \" : \"\
    \ << e.from << \" -> \" << e.to << \", \" << e.cost << \" }\";\n    }\n};\n\n\
    template <class T> using Edges = std::vector<Edge<T>>;\ntemplate <class T> using\
    \ Graph = std::vector<std::vector<Edge<T>>>;\n#line 4 \"graph/read_graph.hpp\"\
    \n\ntemplate <class T> Graph<T> read_graph(int n, int m, const bool weight = false,\
    \ const bool directed = false, const int offset = 1) {\n    Graph<T> g(n);\n \
    \   for (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        a -= offset, b -= offset;\n        if (weight) {\n            T\
    \ c;\n            std::cin >> c;\n            if (!directed) g[b].push_back(Edge(b,\
    \ a, c, i));\n            g[a].push_back(Edge(a, b, c, i));\n        } else {\n\
    \            // c = 1\n            if (!directed) g[b].push_back(Edge(b, a, T(1),\
    \ i));\n            g[a].push_back(Edge(a, b, T(1), i));\n        }\n    }\n \
    \   return g;\n}\n\nstd::tuple<Graph<int>, std::vector<std::vector<int>>, std::vector<std::pair<int,\
    \ int>>> read_grid(const int h, const int w, std::string rel = \".#\") {\n   \
    \ std::vector<std::string> s(h);\n    std::vector id(h, std::vector<int>(w, -1));\n\
    \    std::vector<std::pair<int, int>> loc;\n    int n = 0;\n    for (int i = 0;\
    \ i < h; i++) {\n        std::cin >> s[i];\n        for (int j = 0; j < w; j++)\
    \ {\n            if (s[i][j] == rel[1]) {\n                id[i][j] = n++;\n \
    \               loc.emplace_back(i, j);\n            }\n        }\n    }\n   \
    \ int m = 0;\n    Graph<int> g(n);\n    for (int i = 0; i < h; i++) {\n      \
    \  for (int j = 0; j < w; j++) {\n            if (s[i][j] == rel[1]) {\n     \
    \           if (i + 1 < h and s[i + 1][j] == rel[1]) {\n                    g[id[i][j]].push_back(Edge(id[i][j],\
    \ id[i + 1][j], 1, m));\n                    g[id[i + 1][j]].push_back(Edge(id[i\
    \ + 1][j], id[i][j], 1, m++));\n                }\n                if (j + 1 <\
    \ w and s[i][j + 1] == rel[1]) {\n                    g[id[i][j]].push_back(Edge(id[i][j],\
    \ id[i][j + 1], 1, m));\n                    g[id[i][j + 1]].push_back(Edge(id[i][j\
    \ + 1], id[i][j], 1, m++));\n                }\n            }\n        }\n   \
    \ }\n    return {g, id, loc};\n}\n#line 2 \"graph/low_link.hpp\"\n\n#line 4 \"\
    graph/low_link.hpp\"\n\ntemplate <class T> struct LowLink {\n    int n;\n    std::vector<int>\
    \ ord, low;\n    std::vector<int> articulations;\n    std::vector<int> roots;\n\
    \    std::vector<std::pair<int, int>> bridges;  // edges {u, v} (u < v)\n    std::vector<std::vector<int>>\
    \ dfs_tree;\n\n    LowLink(const Graph<T>& g) : n(int(g.size())) {\n        ord.assign(n,\
    \ -1);\n        low.assign(n, -1);\n        dfs_tree.resize(n);\n        int ord_id\
    \ = 0;\n        auto dfs = [&](auto f, int cur, int par) -> void {\n         \
    \   low[cur] = ord[cur] = ord_id++;\n            bool is_articulation = false;\n\
    \            for (auto& e : g[cur]) {\n                if (ord[e.to] == -1) {\n\
    \                    // DFS \u6728\u4E0A\u306E\u8FBA\u306B\u5BFE\u3059\u308B\u51E6\
    \u7406\n                    f(f, e.to, cur);\n                    dfs_tree[cur].push_back(e.to);\n\
    \                    // e \u304C DFS \u6728\u306B\u542B\u307E\u308C\u3066\u3044\
    \u308B\u306E\u3067\u5F8C\u9000\u8FBA\u3092\u3059\u3067\u306B\u901A\u3063\u305F\
    \ low[e.to] \u3092\u4F7F\u3063\u3066\u66F4\u65B0\u3057\u3066\u826F\u3044\n   \
    \                 low[cur] = std::min(low[cur], low[e.to]);\n                \
    \    is_articulation |= (par != -1) and (ord[cur] <= low[e.to]);\n           \
    \         if (ord[cur] < low[e.to]) {\n                        bridges.emplace_back(std::minmax(cur,\
    \ e.to));\n                    }\n                } else if (e.to != par) {\n\
    \                    // \u5F8C\u9000\u8FBA\u306B\u5BFE\u3059\u308B\u51E6\u7406\
    \n                    // Todo: multiple edges\n                    low[cur] =\
    \ std::min(low[cur], ord[e.to]);\n                }\n            }\n         \
    \   is_articulation |= par == -1 and int(dfs_tree[cur].size()) > 1;\n        \
    \    if (is_articulation) articulations.push_back(cur);\n            return;\n\
    \        };\n        for (int i = 0; i < n; i++) {\n            if (ord[i] ==\
    \ -1) {\n                roots.push_back(i);\n                dfs(dfs, i, -1);\n\
    \            }\n        }\n    }\n    // \u9023\u7D50\u6210\u5206\u6570\n    int\
    \ count_components() { return int(roots.size()); }\n    // \u9802\u70B9 x \u3092\
    \u53D6\u308A\u9664\u304F\u3068\u3082\u3068\u3082\u3068 1 \u3064\u3060\u3063\u305F\
    \u9023\u7D50\u6210\u5206\u304C\u3044\u304F\u3064\u306B\u306A\u308B\u304B\n   \
    \ int count_components_remove(int x) {\n        if (std::binary_search(roots.begin(),\
    \ roots.end(), x)) {\n            int c = int(dfs_tree[x].size());\n         \
    \   return c;\n        } else {\n            int c = 0;\n            for (auto&\
    \ e : dfs_tree[x]) {\n                if (ord[x] <= low[e]) c++;\n           \
    \ }\n            // \u89AA\u306E\u5206\u3067 +1\n            return c + 1;\n \
    \       }\n    }\n};\n#line 7 \"verify/aoj_grl/aoj_grl_3_b.test.cpp\"\n\nint main()\
    \ {\n    int N, M;\n    std::cin >> N >> M;\n    auto G = read_graph<int>(N, M,\
    \ 0, 0, 0);\n    LowLink llink(G);\n    auto ans = llink.bridge;\n    std::sort(ans.begin(),\
    \ ans.end());\n    for (auto& [s, t] : ans) std::cout << s << ' ' << t << '\\\
    n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"graph/read_graph.hpp\"\n#include \"\
    graph/low_link.hpp\"\n\nint main() {\n    int N, M;\n    std::cin >> N >> M;\n\
    \    auto G = read_graph<int>(N, M, 0, 0, 0);\n    LowLink llink(G);\n    auto\
    \ ans = llink.bridge;\n    std::sort(ans.begin(), ans.end());\n    for (auto&\
    \ [s, t] : ans) std::cout << s << ' ' << t << '\\n';\n    return 0;\n}"
  dependsOn:
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/low_link.hpp
  isVerificationFile: true
  path: verify/aoj_grl/aoj_grl_3_b.test.cpp
  requiredBy: []
  timestamp: '2024-01-15 16:50:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj_grl/aoj_grl_3_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_grl/aoj_grl_3_b.test.cpp
- /verify/verify/aoj_grl/aoj_grl_3_b.test.cpp.html
title: verify/aoj_grl/aoj_grl_3_b.test.cpp
---
