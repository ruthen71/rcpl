---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/unionfind.hpp
    title: UnionFind
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/graph/minimum_steiner_tree.test.cpp
    title: verify/graph/minimum_steiner_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc364/editorial/10547
    - https://kopricky.github.io/code/Academic/steiner_tree.html
    - https://www.slideshare.net/wata_orz/ss-12131479#50
    - https://yukicoder.me/problems/no/114/editorial
  bundledCode: "#line 2 \"graph/minimum_steiner_tree.hpp\"\n\n#include <vector>\n\
    #include <queue>\n#include <algorithm>\n#include <cassert>\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#line 4 \"graph/graph_template.hpp\"\ntemplate <class T> struct Edge {\n \
    \   int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(int\
    \ from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id)\
    \ {}\n\n    friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e)\
    \ {\n        // output format: \"{ id : from -> to, cost }\"\n        return os\
    \ << \"{ \" << e.id << \" : \" << e.from << \" -> \" << e.to << \", \" << e.cost\
    \ << \" }\";\n    }\n};\n\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    template <class T> using Graph = std::vector<std::vector<Edge<T>>>;\n#line 2 \"\
    data_structure/unionfind.hpp\"\n\nstruct UnionFind {\n    int n;\n    std::vector<int>\
    \ parents;\n\n    UnionFind() {}\n    UnionFind(int n) : n(n), parents(n, -1)\
    \ {}\n\n    int leader(int x) { return parents[x] < 0 ? x : parents[x] = leader(parents[x]);\
    \ }\n\n    bool merge(int x, int y) {\n        x = leader(x), y = leader(y);\n\
    \        if (x == y) return false;\n        if (parents[x] > parents[y]) std::swap(x,\
    \ y);\n        parents[x] += parents[y];\n        parents[y] = x;\n        return\
    \ true;\n    }\n\n    bool same(int x, int y) { return leader(x) == leader(y);\
    \ }\n\n    int size(int x) { return -parents[leader(x)]; }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(n), group_size(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n    \
    \        group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
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
    }\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n#include <algorithm>\n\
    #include <cassert>\n\n#include \"graph/graph_template.hpp\"\n#include \"data_structure/unionfind.hpp\"\
    \n\n// minimum steiner tree\n// O(3 ^ k n + 2 ^ k m \\log m) (n = |V|, m = |E|,\
    \ k = |terminals|)\n// https://www.slideshare.net/wata_orz/ss-12131479#50\n//\
    \ https://kopricky.github.io/code/Academic/steiner_tree.html\n// https://atcoder.jp/contests/abc364/editorial/10547\n\
    template <class T> std::vector<std::vector<T>> minimum_steiner_tree(Graph<T>&\
    \ g, std::vector<int>& terminals, const T inf) {\n    const int n = (int)(g.size());\n\
    \    const int k = (int)(terminals.size());\n    const int k2 = 1 << k;\n\n  \
    \  // dp[bit][v] = \u30BF\u30FC\u30DF\u30CA\u30EB\u306E\u90E8\u5206\u96C6\u5408\
    \u304C bit (0 ~ k - 1 \u306B\u5727\u7E2E), \u52A0\u3048\u3066\u9802\u70B9 v \u3082\
    \u542B\u307E\u308C\u308B\u6700\u5C0F\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\u6728\
    \n    std::vector dp(k2, std::vector<T>(n, inf));\n    for (int i = 0; i < k;\
    \ i++) dp[1 << i][terminals[i]] = T(0);\n\n    for (int bit = 0; bit < (1 << k);\
    \ bit++) {\n        // dp[bit][v] = min(dp[bit][v], dp[sub][v] + dp[bit ^ sub][v])\n\
    \        // \u901A\u5E38\u306E\u5B9F\u88C5\n        // for (int sub = bit; sub\
    \ > 0; sub = (sub - 1) & bit) {\n        // \u5B9A\u6570\u500D\u9AD8\u901F\u5316\
    \n        // bit \u306E\u4E2D\u3067 1 \u8981\u7D20\u3060\u3051 sub \u3068 bit\
    \ ^ sub \u306E\u3069\u3061\u3089\u306B\u5C5E\u3059\u308B\u304B\u6C7A\u3081\u308B\
    \n        int bit2 = bit ^ (bit & -bit);\n        for (int sub = bit2; sub > 0;\
    \ sub = (sub - 1) & bit2) {\n            for (int v = 0; v < n; v++) {\n     \
    \           dp[bit][v] = std::min(dp[bit][v], dp[sub][v] + dp[bit ^ sub][v]);\n\
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
    }"
  dependsOn:
  - graph/graph_template.hpp
  - data_structure/unionfind.hpp
  isVerificationFile: false
  path: graph/minimum_steiner_tree.hpp
  requiredBy: []
  timestamp: '2024-07-28 03:17:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/graph/minimum_steiner_tree.test.cpp
documentation_of: graph/minimum_steiner_tree.hpp
layout: document
title: "Minimum Steiner Tree (\u6700\u5C0F\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\u6728\
  )"
---

- `minimum_steiner_tree(g, terminals, inf)`
    - $ O(3 ^ k n + 2 ^ k m \log m) $
    - 戻り値は dp の配列
- `minimum_steiner_tree_mst(g, terminals, inf)`
    - ほとんどの頂点がターミナル点であるときに残りの点のうち使うものを全探索することで解く方法
    - $ O(2 ^ {n - k} (n + m)) $
    - 戻り値は最小シュタイナー木の辺の重みの総和

