---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: graph/euler_tour.hpp
    title: "Euler Tour (\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
  - icon: ':heavy_check_mark:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree.hpp
    title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
  bundledCode: "#line 1 \"verify/graph/euler_tour.test.cpp\"\n#define PROBLEM \\\n\
    \    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\n\n\
    #include <iostream>\n\n#line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate\
    \ <class T> struct MonoidPlus {\n    using value_type = T;\n    static constexpr\
    \ T operation(const T& a, const T& b) noexcept {\n        return a + b;\n    }\n\
    \    static constexpr T identity() noexcept { return T(0); }\n    static constexpr\
    \ T inverse(const T& a) noexcept { return -a; }\n    static constexpr bool commutative\
    \ = true;\n};\n#line 2 \"segment_tree/segment_tree.hpp\"\n\n#line 2 \"misc/bit_ceil.hpp\"\
    \n\n#include <cassert>\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\
    \n// bit_ceil\n// (0, 1, 2, 3, 4) -> (1, 1, 2, 4, 4)\n#if __cplusplus >= 202002L\n\
    using std::bit_ceil;\n#else\nunsigned int bit_ceil(unsigned int x) {\n    unsigned\
    \ int p = 1;\n    while (p < x) p *= 2;\n    return p;\n}\nunsigned long long\
    \ int bit_ceil(unsigned long long int x) {\n    unsigned long long int p = 1;\n\
    \    while (p < x) p *= 2;\n    return p;\n}\n#endif\nint bit_ceil(int x) {\n\
    \    assert(x >= 0);\n    return bit_ceil((unsigned int)(x));\n}\nlong long int\
    \ bit_ceil(long long int x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned\
    \ long long int)(x));\n}\n#line 2 \"misc/countr_zero.hpp\"\n\n#if __cplusplus\
    \ >= 202002L\n#include <bit>\n#endif\n\n// countr_zero\n// (000, 001, 010, 011,\
    \ 100) -> (32, 0, 1, 0, 2)\n#if __cplusplus >= 202002L\nusing std::countr_zero;\n\
    #else\nint countr_zero(unsigned int x) {\n    return x == 0 ? 32 : __builtin_ctz(x);\n\
    }\nint countr_zero(unsigned long long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n#endif\nint countr_zero(int x) { return countr_zero((unsigned int)(x)); }\n\
    int countr_zero(long long int x) {\n    return countr_zero((unsigned long long\
    \ int)(x));\n}\n#line 5 \"segment_tree/segment_tree.hpp\"\n\n#line 7 \"segment_tree/segment_tree.hpp\"\
    \n#include <vector>\n\n// Segment Tree\ntemplate <class MS> struct SegmentTree\
    \ {\n  public:\n    using S = typename MS::value_type;\n\n    SegmentTree() =\
    \ default;\n\n    explicit SegmentTree(int n)\n        : SegmentTree(std::vector<S>(n,\
    \ MS::identity())) {}\n\n    explicit SegmentTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        size = bit_ceil(n);\n        log = countr_zero(size);\n        d\
    \ = std::vector<S>(size << 1, MS::identity());\n        for (int i = 0; i < n;\
    \ i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n  \
    \          update(i);\n        }\n    }\n\n    void set(int p, const S& x) {\n\
    \        assert(0 <= p and p < n);\n        p += size;\n        d[p] = x;\n  \
    \      for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    void add(int\
    \ p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n  \
    \      d[p] = MS::operation(d[p], x);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S operator[](int p) const {\n        assert(0\
    \ <= p and p < n);\n        return d[p + size];\n    }\n\n    S get(int p) const\
    \ {\n        assert(0 <= p && p < n);\n        return d[p + size];\n    }\n\n\
    \    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        S sml = MS::identity(), smr = MS::identity();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = MS::operation(sml,\
    \ d[l++]);\n            if (r & 1) smr = MS::operation(d[--r], smr);\n       \
    \     l >>= 1;\n            r >>= 1;\n        }\n        return MS::operation(sml,\
    \ smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template <class\
    \ G> int max_right(int l, G& g) const {\n        assert(0 <= l and l <= n);\n\
    \        assert(g(MS::identity()));\n        if (l == n) return n;\n        l\
    \ += size;\n        S sm = MS::identity();\n        do {\n            while ((l\
    \ & 1) == 0) l >>= 1;\n            if (!g(MS::operation(sm, d[l]))) {\n      \
    \          while (l < size) {\n                    l <<= 1;\n                \
    \    if (g(MS::operation(sm, d[l]))) {\n                        sm = MS::operation(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = MS::operation(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);\n        return n;\n\
    \    }\n\n    template <class G> int min_left(int r, G& g) const {\n        assert(0\
    \ <= r and r <= n);\n        assert(g(MS::identity()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        S sm = MS::identity();\n        do {\n     \
    \       r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n            if (!g(MS::operation(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (r << 1)\
    \ | 1;\n                    if (g(MS::operation(d[r], sm))) {\n              \
    \          sm = MS::operation(d[r], sm);\n                        r--;\n     \
    \               }\n                }\n                return r + 1 - size;\n \
    \           }\n            sm = MS::operation(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n    std::vector<S> make_vector() const\
    \ {\n        std::vector<S> vec(n);\n        for (int i = 0; i < n; i++) vec[i]\
    \ = get(i);\n        return vec;\n    }\n\n  private:\n    int n, log, size;\n\
    \    std::vector<S> d;\n\n    inline void update(int k) {\n        d[k] = MS::operation(d[k\
    \ << 1], d[(k << 1) | 1]);\n    }\n};\n#line 2 \"graph/euler_tour.hpp\"\n\n#line\
    \ 2 \"graph/graph_template.hpp\"\n\n#line 5 \"graph/graph_template.hpp\"\n\ntemplate\
    \ <class T> struct Edge {\n    int from, to;\n    T cost;\n    int id;\n\n   \
    \ Edge() = default;\n    Edge(const int from, const int to, const T cost = T(1),\
    \ const int id = -1)\n        : from(from), to(to), cost(cost), id(id) {}\n\n\
    \    friend bool operator<(const Edge<T>& a, const Edge<T>& b) {\n        return\
    \ a.cost < b.cost;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Edge<T>& e) {\n        // output format: {id: cost(from, to) = cost}\n\
    \        return os << \"{\" << e.id << \": cost(\" << e.from << \", \" << e.to\n\
    \                  << \") = \" << e.cost << \"}\";\n    }\n};\ntemplate <class\
    \ T> using Edges = std::vector<Edge<T>>;\n\ntemplate <class T> struct Graph {\n\
    \    struct EdgeIterators {\n      public:\n        using Iterator = typename\
    \ std::vector<Edge<T>>::iterator;\n        EdgeIterators() = default;\n      \
    \  EdgeIterators(const Iterator& begit, const Iterator& endit)\n            :\
    \ begit(begit), endit(endit) {}\n        Iterator begin() const { return begit;\
    \ }\n        Iterator end() const { return endit; }\n        size_t size() const\
    \ { return std::distance(begit, endit); }\n        Edge<T>& operator[](int i)\
    \ const { return begit[i]; }\n\n      private:\n        Iterator begit, endit;\n\
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
    , \";\n        }\n        return os << \"]\";\n    }\n};\n#line 4 \"graph/euler_tour.hpp\"\
    \n\n#include <tuple>\n\n// Euler Tour\n// O(n + m)\n// \u8FBA\u3068\u9802\u70B9\
    \u306E\u3046\u3061, \u5909\u5316\u3055\u305B\u308B\u3082\u306E\u3092\u8981\u7D20\
    \u3068\u898B\u3066, \u305D\u3046\u3067\u306A\u3044\u3082\u306E\u3067\u8981\u7D20\
    \u3092\u533A\u5207\u308B\u3068\u8003\u3048\u308B\u3068\u826F\u3044\ntemplate <class\
    \ T> struct EulerTour {\n    int n;\n    std::vector<int> vertices;  // DFS \u3067\
    \u8A2A\u554F\u3059\u308B\u9802\u70B9\u306E\u756A\u53F7\u3092\u4E26\u3079\u305F\
    \u3082\u306E, 2 * n - 1 \u8981\u7D20\n    std::vector<int> edges;     // DFS \u3067\
    \u901A\u308B\u8FBA\u306E\u756A\u53F7\u3092\u4E26\u3079\u305F\u3082\u306E, 2 *\
    \ n - 2 \u8981\u7D20\n    std::vector<int> dir;       // DFS \u3067\u901A\u308B\
    \u8FBA\u306E\u5411\u304D\u304C 0 = \u5B50\u4F9B\u65B9\u5411, 1 = \u89AA\u65B9\u5411\
    \n    std::vector<int> vsl;       // vsl[v]: vertices[i] = v \u3068\u306A\u308B\
    \ i \u306E\u6700\u5C0F\u5024\n    std::vector<int> vsr;       // vsr[v]: vertices[i]\
    \ = v \u3068\u306A\u308B i \u306E\u6700\u5927\u5024\n    std::vector<int> esl;\
    \       // esl[e]: edges[i] = e \u304B\u3064 dir[i] = 0 \u3068\u306A\u308B i\n\
    \    std::vector<int> esr;       // esr[e]: edges[i] = e \u304B\u3064 dir[i] =\
    \ 1 \u3068\u306A\u308B i\n\n    EulerTour(Graph<T>& g, const int root = 0) : n((int)(g.size())),\
    \ vsl(n, 2 * n - 1), vsr(n, -1), esl(n - 1, -1), esr(n - 1, -1) {\n        vertices.reserve(2\
    \ * n - 1);\n        edges.reserve(2 * n - 2);\n        dir.reserve(2 * n - 2);\n\
    \n        auto dfs = [&](auto f, int cur, int par) -> void {\n            for\
    \ (auto&& e : g[cur]) {\n                if (e.to == par) continue;\n        \
    \        // \u9802\u70B9\u3092\u8FFD\u52A0\n                vertices.emplace_back(cur);\n\
    \                // \u5B50\u4F9B\u65B9\u5411\u306E\u8FBA\u3092\u8FFD\u52A0\n \
    \               edges.emplace_back(e.id);\n                dir.emplace_back(0);\n\
    \                // DFS\n                f(f, e.to, cur);\n                //\
    \ \u89AA\u65B9\u5411\u306E\u8FBA\u3092\u8FFD\u52A0\n                edges.emplace_back(e.id);\n\
    \                dir.emplace_back(1);\n            }\n            // \u9802\u70B9\
    \u3092\u8FFD\u52A0\n            vertices.emplace_back(cur);\n        };\n    \
    \    dfs(dfs, root, -1);\n        for (int i = 2 * n - 2; i >= 0; i--) vsl[vertices[i]]\
    \ = i;\n        for (int i = 0; i < 2 * n - 1; i++) vsr[vertices[i]] = i;\n  \
    \      for (int i = 0; i < 2 * n - 2; i++) (dir[i] == 0 ? esl[edges[i]] : esr[edges[i]])\
    \ = i;\n    }\n};\n#line 2 \"graph/read_graph.hpp\"\n\n#line 4 \"graph/read_graph.hpp\"\
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
    \    }\n    g.build();\n    return g;\n}\n#line 10 \"verify/graph/euler_tour.test.cpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    Graph<int> g(N);\n\n   \
    \ std::vector<int> id(N, -1);\n    for (int i = 0; i < N; i++) {\n        int\
    \ K;\n        std::cin >> K;\n        for (int j = 0; j < K; j++) {\n        \
    \    int c;\n            std::cin >> c;\n            id[c] = g.add_edge(i, c,\
    \ 0);\n        }\n    }\n\n    EulerTour et(g);\n    SegmentTree<MonoidPlus<long\
    \ long>> seg(2 * N - 2);\n    int Q;\n    std::cin >> Q;\n    for (int q = 0;\
    \ q < Q; q++) {\n        int type;\n        std::cin >> type;\n        if (type\
    \ == 0) {\n            int v, w;\n            std::cin >> v >> w;\n          \
    \  int eid = id[v];\n            seg.add(et.esl[eid], w);\n            seg.add(et.esr[eid],\
    \ -w);\n        } else {\n            int u;\n            std::cin >> u;\n   \
    \         std::cout << seg.prod(0, et.vsl[u]) << '\\n';\n        }\n    }\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n\n#include <iostream>\n\n#include \"algebra/monoid/monoid_plus.hpp\"\n#include\
    \ \"segment_tree/segment_tree.hpp\"\n#include \"graph/euler_tour.hpp\"\n#include\
    \ \"graph/read_graph.hpp\"\n\nint main() {\n    int N;\n    std::cin >> N;\n \
    \   Graph<int> g(N);\n\n    std::vector<int> id(N, -1);\n    for (int i = 0; i\
    \ < N; i++) {\n        int K;\n        std::cin >> K;\n        for (int j = 0;\
    \ j < K; j++) {\n            int c;\n            std::cin >> c;\n            id[c]\
    \ = g.add_edge(i, c, 0);\n        }\n    }\n\n    EulerTour et(g);\n    SegmentTree<MonoidPlus<long\
    \ long>> seg(2 * N - 2);\n    int Q;\n    std::cin >> Q;\n    for (int q = 0;\
    \ q < Q; q++) {\n        int type;\n        std::cin >> type;\n        if (type\
    \ == 0) {\n            int v, w;\n            std::cin >> v >> w;\n          \
    \  int eid = id[v];\n            seg.add(et.esl[eid], w);\n            seg.add(et.esr[eid],\
    \ -w);\n        } else {\n            int u;\n            std::cin >> u;\n   \
    \         std::cout << seg.prod(0, et.vsl[u]) << '\\n';\n        }\n    }\n  \
    \  return 0;\n}\n"
  dependsOn:
  - algebra/monoid/monoid_plus.hpp
  - segment_tree/segment_tree.hpp
  - misc/bit_ceil.hpp
  - misc/countr_zero.hpp
  - graph/euler_tour.hpp
  - graph/graph_template.hpp
  - graph/read_graph.hpp
  isVerificationFile: true
  path: verify/graph/euler_tour.test.cpp
  requiredBy: []
  timestamp: '2026-04-12 20:46:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/euler_tour.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/euler_tour.test.cpp
- /verify/verify/graph/euler_tour.test.cpp.html
title: verify/graph/euler_tour.test.cpp
---
