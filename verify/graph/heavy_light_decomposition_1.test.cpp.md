---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_s/monoid_sum.hpp
    title: algebra/monoid_s/monoid_sum.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/heavy_light_decomposition.hpp
    title: "Heavy-Light Decomposition (\u91CD\u8EFD\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: graph/read_graph.hpp
    title: "\u30B0\u30E9\u30D5\u5165\u529B\u30E9\u30A4\u30D6\u30E9\u30EA"
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
  bundledCode: "#line 1 \"verify/graph/heavy_light_decomposition_1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n\n#include <iostream>\n\n#line 2 \"graph/read_graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
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
    \    }\n};\n#line 4 \"graph/read_graph.hpp\"\n\ntemplate <class T> Graph<T> read_graph(const\
    \ int n, const int m, const bool weight = false, const bool directed = false,\
    \ const int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int i = 0; i\
    \ < m; i++) {\n        int a, b;\n        std::cin >> a >> b;\n        a -= offset,\
    \ b -= offset;\n        T c = 1;\n        if (weight) std::cin >> c;\n       \
    \ g.add_edge(a, b, c);\n    }\n    g.build();\n    return g;\n}\n\ntemplate <class\
    \ T> Graph<T> read_parent(const int n, const bool weight = false, const bool directed\
    \ = false, const int offset = 1) {\n    Graph<T> g(n, directed);\n    for (int\
    \ i = 1; i < n; i++) {\n        int p;\n        std::cin >> p;\n        p -= offset;\n\
    \        T c = 1;\n        if (weight) std::cin >> c;\n        g.add_edge(p, i,\
    \ c);\n    }\n    g.build();\n    return g;\n}\n#line 2 \"graph/heavy_light_decomposition.hpp\"\
    \n\n#line 4 \"graph/heavy_light_decomposition.hpp\"\n\n// Heavy-Light Decomposition\
    \ (\u30D1\u30B9\u30AF\u30A8\u30EA)\ntemplate <class T> struct HeavyLightDecomposition\
    \ {\n    int n;\n    // dfs_size\n    std::vector<int> subsize;  // subsize[v]\
    \ = v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\
    \n    std::vector<int> depth;    // depth[v] = v \u306E\u6DF1\u3055\n    std::vector<int>\
    \ parent;   // parent[v] = v \u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7\n\n  \
    \  // dfs_hld\n    std::vector<int> vertices;  // Heavy-Edge \u304B\u3089\u512A\
    \u5148\u7684\u306B DFS \u3057\u305F\u3068\u304D\u306E\u9802\u70B9\u306E\u756A\u53F7\
    \u3092\u4E26\u3079\u305F\u3082\u306E, n \u8981\u7D20\n    std::vector<int> edges;\
    \     // Heavy-Edge \u304B\u3089\u512A\u5148\u7684\u306B DFS \u3057\u305F\u3068\
    \u304D\u306E\u8FBA\u306E\u756A\u53F7\u3092\u4E26\u3079\u305F\u3082\u306E, n -\
    \ 1 \u8981\u7D20\n    std::vector<int> pathtop;   // pathtop[v] = v \u3092\u542B\
    \u3080\u30D1\u30B9\u4E0A\u306E\u7956\u5148\n    std::vector<int> subbegin;  //\
    \ subbegin[v] = v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\
    \u70B9\u5217\u306E\u958B\u59CB\u4F4D\u7F6E, vertices \u306B\u304A\u3051\u308B\
    \ v \u306E\u767B\u5834\u4F4D\u7F6E\n    std::vector<int> subend;    // subend[v]\
    \ = v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u5217\
    \u306E\u7D42\u308F\u308A\n    std::vector<int> eindex;    // eindex[e] = edges\
    \ \u306B\u304A\u3051\u308B e \u306E\u767B\u5834\u4F4D\u7F6E\n\n    // Graph<T>\
    \ \u306E\u8FBA\u306E\u4E26\u3079\u66FF\u3048\u3092\u884C\u3046\u3053\u3068\u306B\
    \u6CE8\u610F\n    HeavyLightDecomposition(Graph<T>& g, const int root = 0) : n((int)(g.size())),\
    \ subsize(n, 1), depth(n, 0), parent(n, -1), pathtop(n, -1), subbegin(n, -1),\
    \ subend(n, -1), eindex(n - 1, -1) {\n        // \u90E8\u5206\u6728\u306E\u30B5\
    \u30A4\u30BA\u3092\u8A08\u7B97\n        auto dfs_size = [&](auto f, int cur, int\
    \ par) -> void {\n            parent[cur] = par;\n            // \u89AA\u65B9\u5411\
    \u3078\u306E\u8FBA\u3092\u672B\u5C3E\u306B\u79FB\u52D5\n            for (int i\
    \ = 0; i < (int)(g[cur].size()); i++) {\n                if (g[cur][i].to == par)\
    \ {\n                    std::swap(g[cur][i], g[cur][(int)(g[cur].size()) - 1]);\n\
    \                    break;\n                }\n            }\n            //\
    \ \u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u304C\u6700\u5927\u306E\u3082\u306E\
    \u3092\u5148\u982D\u306B\u79FB\u52D5\n            for (auto&& e : g[cur]) {\n\
    \                if (e.to == par) continue;\n                depth[e.to] = depth[cur]\
    \ + 1;\n                f(f, e.to, cur);\n                subsize[cur] += subsize[e.to];\n\
    \                if (subsize[e.to] > subsize[g[cur][0].to]) {\n              \
    \      std::swap(e, g[cur][0]);\n                }\n            }\n        };\n\
    \        dfs_size(dfs_size, root, -1);\n\n        // \u9802\u70B9\u3092\u4E26\u3079\
    \u308B\n        vertices.reserve(n);\n        edges.reserve(n - 1);\n        auto\
    \ dfs_hld = [&](auto f, int cur, int par, int top) -> void {\n            pathtop[cur]\
    \ = top;\n            subbegin[cur] = (int)(vertices.size());\n            vertices.push_back(cur);\n\
    \n            for (auto&& e : g[cur]) {\n                if (e.to == par) continue;\n\
    \                eindex[e.id] = (int)(edges.size());\n                edges.push_back(e.id);\n\
    \                // top \u306F heavy-edge \u306B\u5BFE\u3057\u3066\u306E\u307F\
    \u5F15\u304D\u7D99\u304C\u308C\u308B\n                f(f, e.to, cur, (e.to ==\
    \ g[cur][0].to ? top : e.to));\n            }\n            subend[cur] = (int)(vertices.size());\n\
    \        };\n        dfs_hld(dfs_hld, root, -1, root);\n    }\n\n    int lca(int\
    \ u, int v) {\n        // \u540C\u3058\u30D1\u30B9\u307E\u3067\u4E0A\u304C\u308B\
    \n        while (pathtop[u] != pathtop[v]) {\n            if (subbegin[u] > subbegin[v])\
    \ {\n                u = parent[pathtop[u]];\n            } else {\n         \
    \       v = parent[pathtop[v]];\n            }\n        }\n        if (subbegin[u]\
    \ > subbegin[v]) std::swap(u, v);\n        return u;\n    }\n\n    // u - v \u30D1\
    \u30B9\u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593\n    // is_edges = true \u306A\
    \u3089 edges \u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593, false \u306A\u3089 vertices\
    \ \u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593\n    std::vector<std::pair<int, int>>\
    \ path_query(int u, int v, const bool is_edges) {\n        std::vector<std::pair<int,\
    \ int>> res;\n        while (pathtop[u] != pathtop[v]) {\n            if (subbegin[u]\
    \ > subbegin[v]) std::swap(u, v);\n            // subbegin[u] <= subbegin[v]\n\
    \            if (is_edges) {\n                // edges \u306B\u5BFE\u5FDC\u3059\
    \u308B\u533A\u9593\u306A\u306E\u3067 pathtop[u] \u304B\u3089 parent[pathtop[u]]\
    \ \u306B\u884C\u304F\u8FBA\u3082\u533A\u9593\u306B\u52A0\u3048\u308B\n       \
    \         res.emplace_back(subbegin[pathtop[v]] - 1, subbegin[v]);\n         \
    \   } else {\n                res.emplace_back(subbegin[pathtop[v]], subbegin[v]\
    \ + 1);\n            }\n            v = parent[pathtop[v]];\n        }\n     \
    \   if (subbegin[u] > subbegin[v]) std::swap(u, v);\n        if (is_edges) {\n\
    \            res.emplace_back(subbegin[u], subbegin[v]);\n        } else {\n \
    \           res.emplace_back(subbegin[u], subbegin[v] + 1);\n        }\n     \
    \   return res;\n    }\n};\n#line 4 \"data_structure/segment_tree.hpp\"\ntemplate\
    \ <class MS> struct SegmentTree {\n   public:\n    using S = typename MS::S;\n\
    \    SegmentTree() : SegmentTree(0) {}\n    SegmentTree(int n) : SegmentTree(std::vector<S>(n,\
    \ MS::e())) {}\n    SegmentTree(const std::vector<S>& v) : n((int)(v.size()))\
    \ {\n        log = 0;\n        while ((1U << log) < (unsigned int)(n)) log++;\n\
    \        size = 1 << log;\n        d = std::vector<S>(size << 1, MS::e());\n \
    \       for (int i = 0; i < n; i++) d[i + size] = v[i];\n        for (int i =\
    \ size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void\
    \ set(int p, const S& x) {\n        assert(0 <= p and p < n);\n        p += size;\n\
    \        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n\n    void chset(int p, const S& x) {\n        assert(0 <= p and p < n);\n\
    \        p += size;\n        d[p] = MS::op(d[p], x);\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S operator[](int p) const {\n \
    \       assert(0 <= p and p < n);\n        return d[p + size];\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < n);\n        return d[p + size];\n\
    \    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l and l <= r and\
    \ r <= n);\n        S sml = MS::e(), smr = MS::e();\n        l += size;\n    \
    \    r += size;\n\n        while (l < r) {\n            if (l & 1) sml = MS::op(sml,\
    \ d[l++]);\n            if (r & 1) smr = MS::op(d[--r], smr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return MS::op(sml, smr);\n    }\n\
    \n    S all_prod() const { return d[1]; }\n\n    template <class G> int max_right(int\
    \ l, G& g) const {\n        assert(0 <= l and l <= n);\n        assert(g(MS::e()));\n\
    \        if (l == n) return n;\n        l += size;\n        S sm = MS::e();\n\
    \        do {\n            while ((l & 1) == 0) l >>= 1;\n            if (!g(MS::op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l <<= 1;\n\
    \                    if (g(MS::op(sm, d[l]))) {\n                        sm =\
    \ MS::op(sm, d[l]);\n                        l++;\n                    }\n   \
    \             }\n                return l - size;\n            }\n           \
    \ sm = MS::op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n\
    \        return n;\n    }\n\n    template <class G> int min_left(int r, G& g)\
    \ const {\n        assert(0 <= r and r <= n);\n        assert(g(MS::e()));\n \
    \       if (r == 0) return 0;\n        r += size;\n        S sm = MS::e();\n \
    \       do {\n            r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n\
    \            if (!g(MS::op(d[r], sm))) {\n                while (r < size) {\n\
    \                    r = (r << 1) | 1;\n                    if (g(MS::op(d[r],\
    \ sm))) {\n                        sm = MS::op(d[r], sm);\n                  \
    \      r--;\n                    }\n                }\n                return\
    \ r + 1 - size;\n            }\n            sm = MS::op(d[r], sm);\n        }\
    \ while ((r & -r) != r);\n        return 0;\n    }\n\n    std::vector<S> make_vector()\
    \ {\n        std::vector<S> vec(n);\n        for (int i = 0; i < n; i++) vec[i]\
    \ = get(i);\n        return vec;\n    }\n\n   private:\n    int n, log, size;\n\
    \    std::vector<S> d;\n    inline void update(int k) { d[k] = MS::op(d[k << 1],\
    \ d[(k << 1) | 1]); }\n};\n#line 2 \"algebra/monoid_s/monoid_sum.hpp\"\n// MS\n\
    template <class T> struct MonoidSum {\n    using S = T;\n    static constexpr\
    \ S op(S a, S b) { return a + b; }\n    static constexpr S e() { return T(0);\
    \ }\n};\n#line 9 \"verify/graph/heavy_light_decomposition_1.test.cpp\"\n\nint\
    \ main() {\n    int N;\n    std::cin >> N;\n    Graph<int> g(N, false);\n\n  \
    \  std::vector<int> id(N, -1);\n    for (int i = 0; i < N; i++) {\n        int\
    \ K;\n        std::cin >> K;\n        for (int j = 0; j < K; j++) {\n        \
    \    int c;\n            std::cin >> c;\n            id[c] = g.add_edge(i, c,\
    \ 1);\n        }\n    }\n    const int root = N / 2;  // verify \u306E\u305F\u3081\
    \u306B\u9069\u5F53\u306B\u6C7A\u3081\u308B\n    HeavyLightDecomposition hld(g,\
    \ root);\n    SegmentTree<MonoidSum<long long>> seg(N - 1);\n\n    int Q;\n  \
    \  std::cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        int type;\n    \
    \    std::cin >> type;\n        if (type == 0) {\n            int v, w;\n    \
    \        std::cin >> v >> w;\n            int eid = id[v];\n            seg.chset(hld.eindex[eid],\
    \ w);\n        } else {\n            int v;\n            std::cin >> v;\n    \
    \        auto intervals = hld.path_query(0, v, true);\n            auto res =\
    \ MonoidSum<long long>::e();\n            for (auto&& [l, r] : intervals) {\n\
    \                res = MonoidSum<long long>::op(res, seg.prod(l, r));\n      \
    \      }\n            std::cout << res << '\\n';\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n\n#include <iostream>\n\n#include \"graph/read_graph.hpp\"\n#include \"graph/heavy_light_decomposition.hpp\"\
    \n#include \"data_structure/segment_tree.hpp\"\n#include \"algebra/monoid_s/monoid_sum.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    Graph<int> g(N, false);\n\
    \n    std::vector<int> id(N, -1);\n    for (int i = 0; i < N; i++) {\n       \
    \ int K;\n        std::cin >> K;\n        for (int j = 0; j < K; j++) {\n    \
    \        int c;\n            std::cin >> c;\n            id[c] = g.add_edge(i,\
    \ c, 1);\n        }\n    }\n    const int root = N / 2;  // verify \u306E\u305F\
    \u3081\u306B\u9069\u5F53\u306B\u6C7A\u3081\u308B\n    HeavyLightDecomposition\
    \ hld(g, root);\n    SegmentTree<MonoidSum<long long>> seg(N - 1);\n\n    int\
    \ Q;\n    std::cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        int type;\n\
    \        std::cin >> type;\n        if (type == 0) {\n            int v, w;\n\
    \            std::cin >> v >> w;\n            int eid = id[v];\n            seg.chset(hld.eindex[eid],\
    \ w);\n        } else {\n            int v;\n            std::cin >> v;\n    \
    \        auto intervals = hld.path_query(0, v, true);\n            auto res =\
    \ MonoidSum<long long>::e();\n            for (auto&& [l, r] : intervals) {\n\
    \                res = MonoidSum<long long>::op(res, seg.prod(l, r));\n      \
    \      }\n            std::cout << res << '\\n';\n        }\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - graph/read_graph.hpp
  - graph/graph_template.hpp
  - graph/heavy_light_decomposition.hpp
  - data_structure/segment_tree.hpp
  - algebra/monoid_s/monoid_sum.hpp
  isVerificationFile: true
  path: verify/graph/heavy_light_decomposition_1.test.cpp
  requiredBy: []
  timestamp: '2024-08-06 23:44:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/heavy_light_decomposition_1.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/heavy_light_decomposition_1.test.cpp
- /verify/verify/graph/heavy_light_decomposition_1.test.cpp.html
title: verify/graph/heavy_light_decomposition_1.test.cpp
---
