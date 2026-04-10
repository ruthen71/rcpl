---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: graph/topological_sort.hpp
    title: "Topological Sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      )"
  - icon: ':heavy_check_mark:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  - icon: ':heavy_check_mark:'
    path: misc/topbit.hpp
    title: Topbit
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc223/tasks/abc223_d
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/graph/topological_sort_lexicographical_order.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <algorithm>\n\
    #include <iostream>\n\n#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\ntemplate <class T> struct Edge {\n\
    \    int from, to;\n    T cost;\n    int id;\n\n    Edge() = default;\n    Edge(const\
    \ int from, const int to, const T cost = T(1), const int id = -1)\n        : from(from),\
    \ to(to), cost(cost), id(id) {}\n\n    friend bool operator<(const Edge<T>& a,\
    \ const Edge<T>& b) {\n        return a.cost < b.cost;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Edge<T>& e) {\n        // output format:\
    \ {id: cost(from, to) = cost}\n        return os << \"{\" << e.id << \": cost(\"\
    \ << e.from << \", \" << e.to\n                  << \") = \" << e.cost << \"}\"\
    ;\n    }\n};\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\ntemplate\
    \ <class T> struct Graph {\n    struct EdgeIterators {\n      public:\n      \
    \  using Iterator = typename std::vector<Edge<T>>::iterator;\n        EdgeIterators()\
    \ = default;\n        EdgeIterators(const Iterator& begit, const Iterator& endit)\n\
    \            : begit(begit), endit(endit) {}\n        Iterator begin() const {\
    \ return begit; }\n        Iterator end() const { return endit; }\n        size_t\
    \ size() const { return std::distance(begit, endit); }\n        Edge<T>& operator[](int\
    \ i) const { return begit[i]; }\n\n      private:\n        Iterator begit, endit;\n\
    \    };\n\n    int n, m;\n    bool is_build, is_directed;\n    std::vector<Edge<T>>\
    \ edges;\n\n    // CSR (Compressed Row Storage) \u5F62\u5F0F\u7528\n    std::vector<int>\
    \ start;\n    std::vector<Edge<T>> csr_edges;\n\n    Graph() = default;\n    Graph(const\
    \ int n, const bool directed = false)\n        : n(n), m(0), is_build(false),\
    \ is_directed(directed), start(n + 1, 0) {}\n\n    // \u8FBA\u3092\u8FFD\u52A0\
    \u3057, \u305D\u306E\u8FBA\u304C\u4F55\u756A\u76EE\u306B\u8FFD\u52A0\u3055\u308C\
    \u305F\u304B\u3092\u8FD4\u3059\n    int add_edge(const int from,\n           \
    \      const int to,\n                 const T cost = T(1),\n                \
    \ int id = -1) {\n        assert(!is_build);\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        if (id == -1) id = m;\n\
    \        edges.emplace_back(from, to, cost, id);\n        return m++;\n    }\n\
    \n    // CSR \u5F62\u5F0F\u3067\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\n    void\
    \ build() {\n        assert(!is_build);\n        for (auto&& e : edges) {\n  \
    \          start[e.from + 1]++;\n            if (!is_directed) start[e.to + 1]++;\n\
    \        }\n        for (int v = 0; v < n; v++) start[v + 1] += start[v];\n  \
    \      auto counter = start;\n        csr_edges.resize(start.back() + 1);\n  \
    \      for (auto&& e : edges) {\n            csr_edges[counter[e.from]++] = e;\n\
    \            if (!is_directed)\n                csr_edges[counter[e.to]++] = Edge(e.to,\
    \ e.from, e.cost, e.id);\n        }\n        is_build = true;\n    }\n\n    EdgeIterators\
    \ operator[](int i) {\n        if (!is_build) build();\n        return EdgeIterators(csr_edges.begin()\
    \ + start[i],\n                             csr_edges.begin() + start[i + 1]);\n\
    \    }\n\n    size_t size() const { return (size_t)(n); }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, Graph<T>& g) {\n        os << \"[\";\n        for\
    \ (int i = 0; i < (int)(g.size()); i++) {\n            os << \"[\";\n        \
    \    for (int j = 0; j < (int)(g[i].size()); j++) {\n                os << g[i][j];\n\
    \                if (j + 1 != (int)(g[i].size())) os << \", \";\n            }\n\
    \            os << \"]\";\n            if (i + 1 != (int)(g.size())) os << \"\
    , \";\n        }\n        return os << \"]\";\n    }\n};\n#line 4 \"graph/read_graph.hpp\"\
    \n\ntemplate <class T>\nGraph<T> read_graph(const int n,\n                   \
    \ const int m,\n                    const bool weight = false,\n             \
    \       const bool directed = false,\n                    const int offset = 1)\
    \ {\n    Graph<T> g(n, directed);\n    for (int i = 0; i < m; i++) {\n       \
    \ int a, b;\n        std::cin >> a >> b;\n        a -= offset, b -= offset;\n\
    \        T c = 1;\n        if (weight) std::cin >> c;\n        g.add_edge(a, b,\
    \ c);\n    }\n    g.build();\n    return g;\n}\n\ntemplate <class T>\nGraph<T>\
    \ read_parent(const int n,\n                     const bool weight = false,\n\
    \                     const bool directed = false,\n                     const\
    \ int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int i = 1; i < n;\
    \ i++) {\n        int p;\n        std::cin >> p;\n        p -= offset;\n     \
    \   T c = 1;\n        if (weight) std::cin >> c;\n        g.add_edge(p, i, c);\n\
    \    }\n    g.build();\n    return g;\n}\n#line 2 \"graph/topological_sort.hpp\"\
    \n\n#line 4 \"graph/topological_sort.hpp\"\n\n#line 6 \"graph/topological_sort.hpp\"\
    \n#include <queue>\n\n// topological sort \u304C\u5B58\u5728\u3059\u308B\u306A\
    \u3089, \u8F9E\u66F8\u9806\u6700\u5C0F\u306E\u3082\u306E\u3092\u8FD4\u3059\n//\
    \ O((n + m) log n)\n// topological sort \u304C\u4E00\u610F\u306B\u5B9A\u307E\u308B\
    \ <=> \u6700\u9577\u30D1\u30B9\u306E\u9577\u3055\u304C n - 1\ntemplate <class\
    \ T> std::vector<int> topological_sort(Graph<T>& g) {\n    const int n = (int)(g.size());\n\
    \    assert(n > 0);\n    std::vector<int> indeg(n, 0);\n    for (int i = 0; i\
    \ < n; i++) {\n        for (auto&& e : g[i]) indeg[e.to]++;\n    }\n    // O(n\
    \ + m) \u306B\u3057\u305F\u3044\u5834\u5408\u306F std::queue \u306B\u3059\u308B\
    \n    std::priority_queue<int, std::vector<int>, std::greater<>> que;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (indeg[i] == 0) {\n            que.push(i);\n\
    \        }\n    }\n    std::vector<int> res;\n    while (!que.empty()) {\n   \
    \     auto v = que.top();\n        que.pop();\n        res.push_back(v);\n   \
    \     for (auto&& e : g[v]) {\n            indeg[e.to]--;\n            if (indeg[e.to]\
    \ == 0) que.push(e.to);\n        }\n    }\n    // topological sort \u3067\u304D\
    \u306A\u3044\n    if ((int)(res.size()) != n) {\n        return std::vector<int>();\n\
    \    }\n    return res;\n}\n#line 2 \"random/base.hpp\"\n\n#line 4 \"random/base.hpp\"\
    \n#include <chrono>\n#include <cstdint>\n\n#line 2 \"misc/topbit.hpp\"\n\n#line\
    \ 2 \"misc/countl_zero.hpp\"\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\
    \n// countl_zero\n// (000, 001, 010, 011, 100) -> (32, 31, 30, 30, 29)\n#if __cplusplus\
    \ >= 202002L\nusing std::countl_zero;\n#else\nint countl_zero(unsigned int x)\
    \ {\n    return x == 0 ? 32 : __builtin_clz(x);\n}\nint countl_zero(unsigned long\
    \ long int x) {\n    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#endif\nint\
    \ countl_zero(int x) { return countl_zero((unsigned int)(x)); }\nint countl_zero(long\
    \ long int x) {\n    return countl_zero((unsigned long long int)(x));\n}\n#line\
    \ 4 \"misc/topbit.hpp\"\n\n// topbit\n// (000, 001, 010, 011, 100) -> (-1, 0,\
    \ 1, 1, 2)\nint topbit(int x) { return 31 - countl_zero(x); }\nint topbit(unsigned\
    \ int x) { return 31 - countl_zero(x); }\nint topbit(long long int x) { return\
    \ 63 - countl_zero(x); }\nint topbit(unsigned long long int x) { return 63 - countl_zero(x);\
    \ }\n#line 8 \"random/base.hpp\"\n\ntemplate <bool auto_seed> struct Random {\n\
    \    uint64_t x_seed;\n\n    Random(uint64_t seed = 0) {\n        if (auto_seed)\
    \ {\n            // set random seed\n            assert(seed == 0);\n        \
    \    x_seed =\n                std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        } else {\n            // set seed\n            x_seed = seed;\n     \
    \   }\n    }\n\n    // http://xorshift.di.unimi.it/splitmix64.c\n    // [0, 2^64\
    \ - 1]\n    uint64_t rand_int() {\n        uint64_t z = (x_seed += 0x9e3779b97f4a7c15);\n\
    \        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;\n        z = (z ^ (z >> 27))\
    \ * 0x94d049bb133111eb;\n        return z ^ (z >> 31);\n    }\n\n    // [0, mod\
    \ - 1]\n    // rand_int() % mod \u3060\u3068 mod \u304C 2 \u3079\u304D\u3067\u306A\
    \u3044\u3068\u304D\u306B\u504F\u308B\n    uint64_t rand_int(uint64_t mod) {\n\
    \        assert(mod > 0);\n        if ((mod & (mod - 1)) == 0) {\n           \
    \ // mod = 2^p\n            // (mod - 1) = 0...01...1\n            return rand_int()\
    \ & (mod - 1);\n        }\n        // mod >= 3 (1 = 2^0, 2 = 2^1)\n        int\
    \ lg = topbit((unsigned long long)mod);\n        uint64_t mask = (lg == 63) ?\
    \ ~0ULL : (1ULL << (lg + 1)) - 1;\n        while (true) {\n            uint64_t\
    \ r = rand_int() & mask;\n            if (r < mod) return r;\n        }\n    }\n\
    \n    // [l, r]\n    template <class T> T rand_int(T l, T r) {\n        assert(l\
    \ <= r);\n        return T(l + rand_int(uint64_t(r - l + 1)));\n    }\n\n    //\
    \ [0.0, 1.0]\n    double rand_double() {\n        uint64_t v = rand_int(1ULL <<\
    \ 63);\n        return double(v) / ((1ULL << 63) - 1);\n    }\n\n    // [l, r]\n\
    \    double rand_double(double l, double r) {\n        assert(l <= r);\n     \
    \   return l + rand_double() * (r - l);\n    }\n};\n\nusing RandomFixed = Random<false>;\n\
    using RandomAuto = Random<true>;\n\nRandomAuto rng_auto;\n#line 9 \"verify/graph/topological_sort_lexicographical_order.test.cpp\"\
    \n\nvoid test1_lexicographical_order() {\n    // \u65E7: https://atcoder.jp/contests/abc223/tasks/abc223_d\n\
    \    const int n = 200;\n    // 0 -> 1 -> n - 1\n    // 0 -> 2 -> n - 1\n    //\
    \ \u3092\u30E9\u30F3\u30C0\u30E0\u306A\u9806\u5E8F\u3067\u5F35\u3063\u3066\u3044\
    \u304D, \u30C8\u30DD\u30BD\u3059\u308B\n    std::vector<std::pair<int, int>> p;\n\
    \    for (int i = 1; i < n - 1; i++) {\n        p.push_back({rng_auto.rand_int(),\
    \ i});\n    }\n    std::sort(p.begin(), p.end());\n    Graph<int> g(n, true);\n\
    \    for (int i = 0; i < n - 2; i++) {\n        g.add_edge(0, p[i].second);\n\
    \        g.add_edge(p[i].second, n - 1);\n    }\n    auto vec = topological_sort(g);\n\
    \    for (int i = 0; i < n; i++) {\n        assert(vec[i] == i);\n    }\n}\n\n\
    int main() {\n    test1_lexicographical_order();\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    std::cout << a + b << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <algorithm>\n\
    #include <iostream>\n\n#include \"../../graph/read_graph.hpp\"\n#include \"../../graph/topological_sort.hpp\"\
    \n#include \"../../random/base.hpp\"\n\nvoid test1_lexicographical_order() {\n\
    \    // \u65E7: https://atcoder.jp/contests/abc223/tasks/abc223_d\n    const int\
    \ n = 200;\n    // 0 -> 1 -> n - 1\n    // 0 -> 2 -> n - 1\n    // \u3092\u30E9\
    \u30F3\u30C0\u30E0\u306A\u9806\u5E8F\u3067\u5F35\u3063\u3066\u3044\u304D, \u30C8\
    \u30DD\u30BD\u3059\u308B\n    std::vector<std::pair<int, int>> p;\n    for (int\
    \ i = 1; i < n - 1; i++) {\n        p.push_back({rng_auto.rand_int(), i});\n \
    \   }\n    std::sort(p.begin(), p.end());\n    Graph<int> g(n, true);\n    for\
    \ (int i = 0; i < n - 2; i++) {\n        g.add_edge(0, p[i].second);\n       \
    \ g.add_edge(p[i].second, n - 1);\n    }\n    auto vec = topological_sort(g);\n\
    \    for (int i = 0; i < n; i++) {\n        assert(vec[i] == i);\n    }\n}\n\n\
    int main() {\n    test1_lexicographical_order();\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    std::cout << a + b << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/topological_sort.hpp
  - random/base.hpp
  - misc/topbit.hpp
  - misc/countl_zero.hpp
  isVerificationFile: true
  path: verify/graph/topological_sort_lexicographical_order.test.cpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/topological_sort_lexicographical_order.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/topological_sort_lexicographical_order.test.cpp
- /verify/verify/graph/topological_sort_lexicographical_order.test.cpp.html
title: verify/graph/topological_sort_lexicographical_order.test.cpp
---
