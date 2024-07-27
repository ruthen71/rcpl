---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/unionfind.hpp
    title: UnionFind
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':x:'
    path: graph/minimum_steiner_tree.hpp
    title: "Minimum Steiner Tree (\u6700\u5C0F\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\
      \u6728)"
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
    PROBLEM: https://yukicoder.me/problems/no/114
    links:
    - https://yukicoder.me/problems/no/114
  bundledCode: "#line 1 \"verify/graph/minimum_steiner_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/114\"\n\n#include <iostream>\n\n#line 2 \"\
    graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\n\n#include <vector>\n\
    template <class T> struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\
    \n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int id = -1) :\
    \ from(from), to(to), cost(cost), id(id) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Edge<T> &e) {\n        // output format: \"{ id : from -> to, cost\
    \ }\"\n        return os << \"{ \" << e.id << \" : \" << e.from << \" -> \" <<\
    \ e.to << \", \" << e.cost << \" }\";\n    }\n};\n\ntemplate <class T> using Edges\
    \ = std::vector<Edge<T>>;\ntemplate <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n\
    #line 4 \"graph/read_graph.hpp\"\n\ntemplate <class T> Graph<T> read_graph(const\
    \ int n, const int m, const bool weight = false, const bool directed = false,\
    \ const int offset = 1) {\n    Graph<T> g(n);\n    for (int i = 0; i < m; i++)\
    \ {\n        int a, b;\n        std::cin >> a >> b;\n        a -= offset, b -=\
    \ offset;\n        if (weight) {\n            T c;\n            std::cin >> c;\n\
    \            if (!directed) g[b].push_back(Edge(b, a, c, i));\n            g[a].push_back(Edge(a,\
    \ b, c, i));\n        } else {\n            // c = 1\n            if (!directed)\
    \ g[b].push_back(Edge(b, a, T(1), i));\n            g[a].push_back(Edge(a, b,\
    \ T(1), i));\n        }\n    }\n    return g;\n}\n\ntemplate <class T> Graph<T>\
    \ read_parent(const int n, const bool weight = false, const bool directed = false,\
    \ const int offset = 1) {\n    Graph<T> g(n);\n    for (int i = 1; i < n; i++)\
    \ {\n        int p;\n        std::cin >> p;\n        p -= offset;\n        if\
    \ (weight) {\n            T c;\n            std::cin >> c;\n            if (!directed)\
    \ g[i].push_back(Edge(i, p, c, i - 1));\n            g[p].push_back(Edge(p, i,\
    \ c, i - 1));\n        } else {\n            // c = 1\n            if (!directed)\
    \ g[i].push_back(Edge(i, p, T(1), i - 1));\n            g[p].push_back(Edge(p,\
    \ i, T(1), i - 1));\n        }\n    }\n    return g;\n}\n\nstd::tuple<Graph<int>,\
    \ std::vector<std::vector<int>>, std::vector<std::pair<int, int>>> read_grid(const\
    \ int h, const int w, std::string rel = \".#\") {\n    std::vector<std::string>\
    \ s(h);\n    std::vector id(h, std::vector<int>(w, -1));\n    std::vector<std::pair<int,\
    \ int>> loc;\n    int n = 0;\n    for (int i = 0; i < h; i++) {\n        std::cin\
    \ >> s[i];\n        for (int j = 0; j < w; j++) {\n            if (s[i][j] ==\
    \ rel[1]) {\n                id[i][j] = n++;\n                loc.emplace_back(i,\
    \ j);\n            }\n        }\n    }\n    int m = 0;\n    Graph<int> g(n);\n\
    \    for (int i = 0; i < h; i++) {\n        for (int j = 0; j < w; j++) {\n  \
    \          if (s[i][j] == rel[1]) {\n                if (i + 1 < h and s[i + 1][j]\
    \ == rel[1]) {\n                    g[id[i][j]].push_back(Edge(id[i][j], id[i\
    \ + 1][j], 1, m));\n                    g[id[i + 1][j]].push_back(Edge(id[i +\
    \ 1][j], id[i][j], 1, m++));\n                }\n                if (j + 1 < w\
    \ and s[i][j + 1] == rel[1]) {\n                    g[id[i][j]].push_back(Edge(id[i][j],\
    \ id[i][j + 1], 1, m));\n                    g[id[i][j + 1]].push_back(Edge(id[i][j\
    \ + 1], id[i][j], 1, m++));\n                }\n            }\n        }\n   \
    \ }\n    return {g, id, loc};\n}\n#line 2 \"graph/minimum_steiner_tree.hpp\"\n\
    \n#line 4 \"graph/minimum_steiner_tree.hpp\"\n#include <queue>\n#include <algorithm>\n\
    #include <cassert>\n\n#line 2 \"data_structure/unionfind.hpp\"\n\nstruct UnionFind\
    \ {\n    int n;\n    std::vector<int> parents;\n\n    UnionFind() {}\n    UnionFind(int\
    \ n) : n(n), parents(n, -1) {}\n\n    int leader(int x) { return parents[x] <\
    \ 0 ? x : parents[x] = leader(parents[x]); }\n\n    bool merge(int x, int y) {\n\
    \        x = leader(x), y = leader(y);\n        if (x == y) return false;\n  \
    \      if (parents[x] > parents[y]) std::swap(x, y);\n        parents[x] += parents[y];\n\
    \        parents[y] = x;\n        return true;\n    }\n\n    bool same(int x,\
    \ int y) { return leader(x) == leader(y); }\n\n    int size(int x) { return -parents[leader(x)];\
    \ }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(n), group_size(n);\n        for (int i = 0; i < n; i++) {\n     \
    \       leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n      \
    \  }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(result.begin(), result.end(),\
    \ [&](const std::vector<int>& v) { return v.empty(); }), result.end());\n    \
    \    return result;\n    }\n\n    void init(int n) { parents.assign(n, -1); }\
    \  // reset\n};\n#line 10 \"graph/minimum_steiner_tree.hpp\"\n\n// minimum steiner\
    \ tree\n// O(3 ^ k n + 2 ^ k m \\log m) (n = |V|, m = |E|, k = |terminals|)\n\
    // https://www.slideshare.net/wata_orz/ss-12131479#50\n// https://kopricky.github.io/code/Academic/steiner_tree.html\n\
    // https://atcoder.jp/contests/abc364/editorial/10547\ntemplate <class T> std::vector<std::vector<T>>\
    \ minimum_steiner_tree(Graph<T>& g, std::vector<int>& terminals, const T inf)\
    \ {\n    const int n = (int)(g.size());\n    const int k = (int)(terminals.size());\n\
    \    const int k2 = 1 << k;\n\n    // dp[bit][v] = \u30BF\u30FC\u30DF\u30CA\u30EB\
    \u306E\u90E8\u5206\u96C6\u5408\u304C bit (0 ~ k - 1 \u306B\u5727\u7E2E), \u52A0\
    \u3048\u3066\u9802\u70B9 v \u3082\u542B\u307E\u308C\u308B\u6700\u5C0F\u30B7\u30E5\
    \u30BF\u30A4\u30CA\u30FC\u6728\n    std::vector dp(k2, std::vector<T>(n, inf));\n\
    \    for (int i = 0; i < k; i++) dp[1 << i][terminals[i]] = T(0);\n\n    for (int\
    \ bit = 0; bit < (1 << k); bit++) {\n        // dp[bit][v] = min(dp[bit][v], dp[sub][v]\
    \ + dp[bit ^ sub][v])\n        // \u901A\u5E38\u306E\u5B9F\u88C5\n        // for\
    \ (int sub = bit; sub > 0; sub = (sub - 1) & bit) {\n        // \u5B9A\u6570\u500D\
    \u9AD8\u901F\u5316\n        // bit \u306E\u4E2D\u3067 1 \u8981\u7D20\u3060\u3051\
    \ sub \u3068 bit ^ sub \u306E\u3069\u3061\u3089\u306B\u5C5E\u3059\u308B\u304B\u6C7A\
    \u3081\u308B\n        int bit2 = bit ^ (bit & -bit);\n        for (int sub = bit2;\
    \ sub > 0; sub = (sub - 1) & bit2) {\n            for (int v = 0; v < n; v++)\
    \ {\n                dp[bit][v] = std::min(dp[bit][v], dp[sub][v] + dp[bit ^ sub][v]);\n\
    \            }\n        }\n        // dp[bit][v] = min(dp[bit][v], dp[bit][u]\
    \ + cost(u, v))\n        using tp = std::pair<T, int>;\n        std::priority_queue<tp,\
    \ std::vector<tp>, std::greater<tp>> que;\n        for (int u = 0; u < n; u++)\
    \ que.emplace(dp[bit][u], u);\n        while (!que.empty()) {\n            auto\
    \ [d, u] = que.top();\n            que.pop();\n            if (dp[bit][u] != d)\
    \ continue;\n            for (auto&& e : g[u]) {\n                if (dp[bit][e.to]\
    \ > d + e.cost) {\n                    dp[bit][e.to] = d + e.cost;\n         \
    \           que.emplace(dp[bit][e.to], e.to);\n                }\n           \
    \ }\n        }\n    }\n    // dp[k2 - 1][i] = \u30BF\u30FC\u30DF\u30CA\u30EB\u3068\
    \u9802\u70B9 i \u3092\u542B\u3080\u6700\u5C0F\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\
    \u6728\n    // dp[k2 - 1][terminals[0]] \u304C\u57FA\u672C\u7684\u306A\u7B54\u3048\
    \u306B\u306A\u308B\n    return dp;\n}\n\n// O(2 ^ {n - k} (n + m)) (n = |V|, m\
    \ = |E|, k = |terminals|)\n// https://yukicoder.me/problems/no/114/editorial\n\
    // n - k <= 20, n <= 64\ntemplate <class T> T minimum_steiner_tree_mst(Graph<T>&\
    \ g, std::vector<int>& terminals, const T inf) {\n    const int n = (int)(g.size());\n\
    \    const int k = (int)(terminals.size());\n    assert(n <= 64);\n\n    // \u30BF\
    \u30FC\u30DF\u30CA\u30EB\u306B\u542B\u307E\u308C\u306A\u3044\u70B9\u96C6\u5408\
    \ (others) \u3092\u53D6\u5F97\n    unsigned long long st = 0;\n    for (int i\
    \ = 0; i < k; i++) st |= 1LL << terminals[i];\n    std::vector<int> others;\n\
    \    for (int i = 0; i < n; i++)\n        if ((st >> i & 1) == 0) others.emplace_back(i);\n\
    \n    // \u8FBA\u306E\u30EA\u30B9\u30C8\n    std::vector<Edge<T>> edges;\n   \
    \ for (int v = 0; v < n; v++) {\n        for (auto&& e : g[v]) {\n           \
    \ edges.push_back(e);\n        }\n    }\n    std::sort(edges.begin(), edges.end(),\
    \ [&](Edge<T>& a, Edge<T>& b) -> bool { return a.cost < b.cost; });\n\n    //\
    \ \u30BF\u30FC\u30DF\u30CA\u30EB + others \u306E\u7D44\u5408\u305B\u3092\u5168\
    \u5217\u6319 -> Minimum Spanning Tree \u3092\u6C42\u3081\u308B\n    T ans = inf;\n\
    \    for (int bit = 0; bit < (1 << (n - k)); bit++) {\n        // \u4F7F\u3046\
    \u9802\u70B9\u96C6\u5408\n        unsigned long long subv = st;\n        for (int\
    \ i = 0; i < n - k; i++) {\n            if (bit >> i & 1) {\n                subv\
    \ |= 1LL << others[i];\n            }\n        }\n\n        // Minimum Spanning\
    \ Tree \u3092\u8A08\u7B97\n        UnionFind uf(n);\n        T cur = 0;\n    \
    \    int connected = 0;\n        for (auto&& e : edges) {\n            // subv\
    \ \u306B\u5BFE\u3059\u308B g \u306E\u8A98\u5C0E\u90E8\u5206\u30B0\u30E9\u30D5\u306B\
    \u542B\u307E\u308C\u308B\u8FBA\u306E\u307F\u8A66\u3059\n            if (!(subv\
    \ >> e.from & 1) or !(subv >> e.to & 1)) continue;\n            if (!uf.same(e.from,\
    \ e.to)) {\n                uf.merge(e.from, e.to);\n                cur += e.cost;\n\
    \                connected++;\n            }\n        }\n        // \u5168\u57DF\
    \u6728\u304C\u4F5C\u308C\u305F\u304B\u5224\u5B9A\n        if (connected + 1 ==\
    \ k + __builtin_popcount(bit)) ans = std::min(ans, cur);\n    }\n    return ans;\n\
    }\n#line 7 \"verify/graph/minimum_steiner_tree.test.cpp\"\n\nint main() {\n  \
    \  int N, M, T;\n    std::cin >> N >> M >> T;\n    auto g = read_graph<long long>(N,\
    \ M, true);\n    std::vector<int> terminals(T);\n    for (int i = 0; i < T; i++)\
    \ {\n        std::cin >> terminals[i];\n        terminals[i]--;\n    }\n    if\
    \ (T <= 15) {\n        auto dp = minimum_steiner_tree(g, terminals, 1'000'000'000'000'000'000LL);\n\
    \        std::cout << dp.back()[terminals[0]] << '\\n';\n    } else {\n      \
    \  std::cout << minimum_steiner_tree_mst(g, terminals, 1'000'000'000'000'000'000LL)\
    \ << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/114\"\n\n#include <iostream>\n\
    \n#include \"graph/read_graph.hpp\"\n#include \"graph/minimum_steiner_tree.hpp\"\
    \n\nint main() {\n    int N, M, T;\n    std::cin >> N >> M >> T;\n    auto g =\
    \ read_graph<long long>(N, M, true);\n    std::vector<int> terminals(T);\n   \
    \ for (int i = 0; i < T; i++) {\n        std::cin >> terminals[i];\n        terminals[i]--;\n\
    \    }\n    if (T <= 15) {\n        auto dp = minimum_steiner_tree(g, terminals,\
    \ 1'000'000'000'000'000'000LL);\n        std::cout << dp.back()[terminals[0]]\
    \ << '\\n';\n    } else {\n        std::cout << minimum_steiner_tree_mst(g, terminals,\
    \ 1'000'000'000'000'000'000LL) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/minimum_steiner_tree.hpp
  - data_structure/unionfind.hpp
  isVerificationFile: true
  path: verify/graph/minimum_steiner_tree.test.cpp
  requiredBy: []
  timestamp: '2024-07-28 03:20:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/graph/minimum_steiner_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/minimum_steiner_tree.test.cpp
- /verify/verify/graph/minimum_steiner_tree.test.cpp.html
title: verify/graph/minimum_steiner_tree.test.cpp
---
